# Topological Sort

## Table of Contents

- [Topological Sort](#topological-sort)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Approach 1: Depth First Search (DFS)](#approach-1-depth-first-search-dfs)
    - [Approach 2: Kahn's Algorithm (BFS)](#approach-2-kahns-algorithm-bfs)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

Topological sorting for a **Directed Acyclic Graph (DAG)** is a linear ordering of its vertices such that for every directed edge \( u \rightarrow v \), vertex \( u \) appears before \( v \) in the ordering.

---

## Problem Description

You are given:

- An adjacency list representation of a **DAG**, where `adj[u]` contains a list of all vertices \( v \) such that there exists a directed edge \( u \rightarrow v \).

### Task

Return a valid **topological sort** of the graph.  
If the returned order is valid, the output will be `1`; otherwise, it will be `0`.

---

### Examples

**Example 1:**  
Input:  

```bash
adj = [[], [0], [0], [0]]
```

Output:  

```bash
1
```

Explanation:  
A few valid topological orders are:  

- `[3, 2, 1, 0]`
- `[1, 2, 3, 0]`
- `[2, 3, 1, 0]`

---

**Example 2:**  
Input:  

```bash
adj = [[], [3], [3], [], [0,1], [0,2]]
```

Output:  

```bash
1
```

Explanation:  
A few valid topological orders are:  

- `[4, 5, 0, 1, 2, 3]`
- `[5, 2, 4, 0, 1, 3]`

---

### Constraints

- \( 2 \leq V \leq 1000 \)
- \( 1 \leq E \leq \frac{V \times (V - 1)}{2} \)

---

## Approach

### Approach 1: Depth First Search (DFS)

1. Perform DFS for all unvisited nodes.
2. After visiting a node, push it onto a stack to maintain reverse order of processing.
3. At the end, pop all elements from the stack to obtain the topological order.

---

### Approach 2: Kahn's Algorithm (BFS)

1. Compute the **in-degree** of each vertex.
2. Add all vertices with in-degree 0 to a queue.
3. Process vertices from the queue:
   - Append the vertex to the topological order.
   - Decrease the in-degree of its neighbors.
   - Add neighbors with in-degree 0 to the queue.
4. If all vertices are processed, return the order; otherwise, detect a cycle.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &stk) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, stk);
            }
        }
        stk.push(node);
    }

public:
    vector<int> topologicalSort(vector<vector<int>> &adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> stk;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, stk);
            }
        }

        vector<int> topoSort;
        while (!stk.empty()) {
            topoSort.push_back(stk.top());
            stk.pop();
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

        for (int node : res) {
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int node, List<List<Integer>> adj, boolean[] visited, Stack<Integer> stk) {
        visited[node] = true;

        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, stk);
            }
        }

        stk.push(node);
    }

    public int[] topologicalSort(int V, List<List<Integer>> adj) {
        boolean[] visited = new boolean[V];
        Stack<Integer> stk = new Stack<>();

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, stk);
            }
        }

        int[] topoSort = new int[V];
        int index = 0;
        while (!stk.isEmpty()) {
            topoSort[index++] = stk.pop();
        }

        return topoSort;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj.get(u).add(v);
            }

            Solution obj = new Solution();
            int[] result = obj.topologicalSort(V, adj);

            for (int node : result) {
                System.out.print(node + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

| Algorithm        | Time Complexity | Space Complexity |
|-------------------|-----------------|------------------|
| DFS (Stack)       | \( O(V + E) \)  | \( O(V) \)       |
| BFS (Kahn's Algo) | \( O(V + E) \)  | \( O(V) \)       |

---

## How to Run the Code

### For C++

1. Save the code in a file `topological_sort.cpp`.
2. Compile using:  

   ```bash
   g++ -o topological_sort topological_sort.cpp
   ```

3. Run using:  

   ```bash
   ./topological_sort
   ```

### For Java

1. Save the code in a file `Solution.java`.
2. Compile using:  

   ```bash
   javac Solution.java
   ```

3. Run using:  

   ```bash
   java Solution
   ```

---
