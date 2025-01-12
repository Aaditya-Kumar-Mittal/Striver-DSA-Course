# Prerequisite Tasks

## Table of Contents

- [Prerequisite Tasks](#prerequisite-tasks)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

Given a total of `N` tasks (labeled from 0 to `N-1`) and a list of `P` prerequisite pairs, the task is to determine whether it is possible to complete all tasks. This problem can be solved using concepts of graph theory, specifically **cycle detection** in a Directed Acyclic Graph (DAG).

---

## Problem Description

You are given:

- `N`: Total number of tasks.
- `P`: Number of prerequisite pairs.
- `prerequisites`: A list of pairs where `[a, b]` indicates that task `a` depends on task `b`.

The goal is to determine if all tasks can be completed, considering the prerequisites.

### Examples

#### Example 1

**Input**:

```bash

N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]

```

**Output**:

```bash

Yes

```

**Explanation**:

- Task 1 depends on task 0.
- Task 2 depends on task 1.
- Task 3 depends on task 2.
- Therefore, all tasks can be completed in the order [0, 1, 2, 3].

#### Example 2

**Input**:

```bash

N = 2, P = 2, prerequisites = [[1,0],[0,1]]

```

**Output**:

```bash

No

```

**Explanation**:

- Task 1 depends on task 0.
- Task 0 depends on task 1.
- This creates a cycle, so it is not possible to complete all tasks.

### Constraints

- \( 1 \leq N \leq 10^4 \)
- \( 1 \leq P \leq 10^5 \)

---

## Approach

1. **Graph Representation**:
   - Represent the tasks as a directed graph using an adjacency list.
   - Each task is a vertex, and the prerequisites form directed edges.

2. **Cycle Detection**:
   - Use **Kahn’s Algorithm** (BFS-based topological sort).
   - If the graph contains a cycle, it will be impossible to perform all tasks.

3. **Algorithm**:
   - Calculate the in-degree of each vertex.
   - Add all vertices with in-degree 0 to a queue.
   - Perform BFS, reducing in-degree for adjacent vertices.
   - If all vertices are processed, the tasks can be completed; otherwise, there is a cycle.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to check if it is possible to complete all tasks.
    bool isPossible(int N, int P, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> adj(N);
        
        // Build adjacency list
        for (auto it : prerequisites) {
            adj[it.first].push_back(it.second);
        }

        // Calculate in-degree
        vector<int> indegree(N, 0);
        for (int i = 0; i < N; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        // Initialize queue with nodes having in-degree 0
        queue<int> q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform Kahn's Algorithm
        int count = 0;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            count++;

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        return count == N;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int N, P;
        vector<pair<int, int>> prerequisites;
        cin >> N >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }

        Solution obj;
        if (obj.isPossible(N, P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public boolean isPossible(int N, int P, int[][] prerequisites) {
        // Build adjacency list
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < N; i++) adj.add(new ArrayList<>());
        for (int[] pair : prerequisites) {
            adj.get(pair[0]).add(pair[1]);
        }

        // Calculate in-degree
        int[] indegree = new int[N];
        for (int i = 0; i < N; i++) {
            for (int neighbor : adj.get(i)) {
                indegree[neighbor]++;
            }
        }

        // Initialize queue with nodes having in-degree 0
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        // Perform Kahn's Algorithm
        int count = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            count++;

            for (int neighbor : adj.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }

        return count == N;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int N = sc.nextInt();
            int P = sc.nextInt();
            int[][] prerequisites = new int[P][2];
            for (int i = 0; i < P; i++) {
                prerequisites[i][0] = sc.nextInt();
                prerequisites[i][1] = sc.nextInt();
            }

            Solution obj = new Solution();
            System.out.println(obj.isPossible(N, P, prerequisites) ? "Yes" : "No");
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

1. **Time Complexity**:
   - Building adjacency list: \( O(P) \)
   - Calculating in-degree: \( O(P) \)
   - Kahn’s Algorithm: \( O(N + P) \)
   - **Total**: \( O(N + P) \)

2. **Space Complexity**:
   - Adjacency list storage: \( O(N + P) \)
   - In-degree array and queue: \( O(N) \)
   - **Total**: \( O(N + P) \)

---

## How to Run the Code

### For C++

1. Save the code to a file, e.g., `prerequisite_tasks.cpp`.
2. Compile using: `g++ prerequisite_tasks.cpp -o prerequisite_tasks`.
3. Run using: `./prerequisite_tasks`.

### For Java

1. Save the code to a file, e.g., `Solution.java`.
2. Compile using: `javac Solution.java`.
3. Run using: `java Solution`.

---
