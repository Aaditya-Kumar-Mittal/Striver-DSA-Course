# Topological Sort (Kahn's Algorithm)

## Table of Contents

- [Topological Sort (Kahn's Algorithm)](#topological-sort-kahns-algorithm)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [DFS-Based Approach](#dfs-based-approach)
    - [BFS-Based Approach (Kahn's Algorithm)](#bfs-based-approach-kahns-algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

Topological sorting is a linear ordering of vertices in a Directed Acyclic Graph (DAG) such that for every directed edge `u -> v`, vertex `u` comes before `v` in the ordering. This sorting is primarily used in scheduling problems and as a prerequisite for many algorithms like finding strongly connected components.

---

## Problem Description

Given an adjacency list for a DAG where `adj[u]` contains a list of all vertices `v` such that there exists a directed edge `u -> v`, return a valid topological sort of the graph.

- **Input:** Adjacency list of a graph
- **Output:** A topological ordering of vertices
- **Note:** If multiple valid topological orders exist, any one can be returned.

### Examples

**Example 1:**

- **Input:** `adj = [[], [0], [0], [0]]`
- **Output:** `1`
  
Explanation: Valid topological orders include:

- `[3, 2, 1, 0]`
- `[1, 2, 3, 0]`
- `[2, 3, 1, 0]`

**Example 2:**

- **Input:** `adj = [[], [3], [3], [], [0, 1], [0, 2]]`
- **Output:** `1`

Explanation: Valid topological orders include:

- `[4, 5, 0, 1, 2, 3]`
- `[5, 2, 4, 0, 1, 3]`

### Constraints

- \(2 \leq V \leq 10^3\)
- \(1 \leq E \leq \frac{V \times (V - 1)}{2}\)

---

## Approach

### DFS-Based Approach

1. Perform a Depth First Search (DFS) traversal for each vertex.
2. Mark nodes as visited during traversal.
3. Push nodes to a stack after all their neighbors are processed.
4. Pop nodes from the stack to get the topological order.

### BFS-Based Approach (Kahn's Algorithm)

1. Compute the in-degree of all vertices.
2. Push all vertices with in-degree 0 into a queue.
3. Process vertices from the queue:
   - Add them to the topological order.
   - Decrease the in-degree of their neighbors.
   - Add neighbors with in-degree 0 to the queue.
4. Continue until the queue is empty.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, stack<int>& stk) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, stk);
            }
        }
        stk.push(node);
    }

public:
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        int V = adj.size();

        // Using Kahn's Algorithm (BFS-Based Approach)
        vector<int> indegree(V, 0);
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoSort;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topoSort.push_back(node);

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) q.push(it);
            }
        }

        return topoSort;
    }
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> N >> E;

        vector<vector<int>> adj(N);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        for (auto x : res) cout << x << " ";
        cout << endl;
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[] topologicalSort(int V, List<List<Integer>> adj) {
        // Using Kahn's Algorithm (BFS-Based Approach)
        int[] indegree = new int[V];
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj.get(i)) {
                indegree[neighbor]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.offer(i);
            }
        }

        int[] topoSort = new int[V];
        int index = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            topoSort[index++] = node;

            for (int neighbor : adj.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.offer(neighbor);
                }
            }
        }

        return topoSort;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int N = sc.nextInt();
            int E = sc.nextInt();

            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < N; i++) {
                adj.add(new ArrayList<>());
            }

            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj.get(u).add(v);
            }

            Solution obj = new Solution();
            int[] res = obj.topologicalSort(N, adj);

            for (int x : res) System.out.print(x + " ");
            System.out.println();
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS-Based:**
  - \(O(V + E)\) for visiting all vertices and edges.
- **BFS-Based (Kahn's Algorithm):**
  - \(O(V + E)\) for calculating in-degrees and processing all vertices and edges.

### Space Complexity

- \(O(V + E)\) for the adjacency list representation.
- \(O(V)\) for the stack (DFS) or queue (BFS).

---

## How to Run the Code

### For C++

1. Save the code in a file named `topological_sort.cpp`.
2. Compile using `g++ topological_sort.cpp -o topological_sort`.
3. Run using `./topological_sort`.

### For Java

1. Save the code in a file named `Main.java`.
2. Compile using `javac Main.java`.
3. Run using `java Main`.

---
