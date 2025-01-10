# Cycle in a Directed Graph

## Table of Contents

- [Cycle in a Directed Graph](#cycle-in-a-directed-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [1. Depth-First Search (DFS)](#1-depth-first-search-dfs)
    - [2. Kahn's Algorithm (BFS-based)](#2-kahns-algorithm-bfs-based)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

## Introduction

A directed graph is said to contain a cycle if there exists a path such that starting from a vertex, you can return to the same vertex through a sequence of directed edges. This document explains how to determine whether a directed graph contains a cycle using two approaches: Depth-First Search (DFS) and Kahn's Algorithm (BFS-based).

---

## Problem Description

Given a Directed Graph with `V` vertices (numbered from `0` to `V-1`) and `E` edges, check whether it contains any cycle. The graph is represented as an adjacency list, where `adj[i]` contains a list of vertices that are directly reachable from vertex `i`.

### Examples

#### Example 1

Input:  

```bash
V = 4, E = 4
Edges: [[0, 1], [1, 2], [2, 3], [3, 3]]
```

Output:  

```bash
1
```

Explanation: The edge 3 -> 3 forms a cycle.

#### Example 2

Input:  

```bash
V = 4, E = 4
Edges: [[0, 1], [1, 2], [2, 3]]
```

Output:  

```bash
0
```

Explanation: There are no cycles in the graph.

### Constraints

- `1 ≤ V, E ≤ 10^5`

---

## Approach

### 1. Depth-First Search (DFS)

- Use a recursive DFS traversal to detect back edges, which indicate cycles.
- Maintain a `visited` array and a `recursion stack` to track nodes currently in the recursion stack.

### 2. Kahn's Algorithm (BFS-based)

- Compute the in-degree for each vertex.
- Use a queue to process nodes with in-degree 0.
- If all nodes are processed without detecting a cycle, the graph is acyclic. Otherwise, it contains a cycle.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> &adj) {
        vector<int> indegree(V, 0);
        
        // Calculate in-degrees of all vertices
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        // Push all vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        int count = 0; // Count of processed vertices
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

        // If count != V, graph contains a cycle
        return count != V;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    // Function to detect cycle in a directed graph.
    public boolean isCyclic(int V, ArrayList<ArrayList<Integer>> adj) {
        int[] indegree = new int[V];

        // Calculate in-degrees of all vertices
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj.get(i)) {
                indegree[neighbor]++;
            }
        }

        Queue<Integer> queue = new LinkedList<>();

        // Push all vertices with in-degree 0
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
            }
        }

        int count = 0; // Count of processed vertices
        while (!queue.isEmpty()) {
            int node = queue.poll();
            count++;

            for (int neighbor : adj.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }

        // If count != V, graph contains a cycle
        return count != V;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();

            ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }

            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj.get(u).add(v);
            }

            Solution obj = new Solution();
            System.out.println(obj.isCyclic(V, adj) ? 1 : 0);
        }

        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **C++ and Java:** `O(V + E)` where `V` is the number of vertices and `E` is the number of edges. This is due to the BFS traversal and adjacency list processing.

### Space Complexity

- **C++ and Java:** `O(V + E)` for the adjacency list and additional storage for the in-degree array and queue.

---

This implementation handles large graphs efficiently and adheres to the problem's constraints, ensuring scalability and correctness.
