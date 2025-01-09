# Detect Cycle in an Undirected Graph Using DFS

## Table of Contents

- [Detect Cycle in an Undirected Graph Using DFS](#detect-cycle-in-an-undirected-graph-using-dfs)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Statement](#problem-statement)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Algorithm](#algorithm)
    - [Depth-First Search (DFS) Approach](#depth-first-search-dfs-approach)
  - [Code](#code)
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

This implementation detects a cycle in an undirected graph using **Depth-First Search (DFS)**. The graph is represented as an adjacency list, and the algorithm explores all vertices recursively while keeping track of visited nodes and their parents.

---

## Problem Statement

Given an undirected graph with \( n \) vertices and \( m \) edges, check whether the graph contains a cycle. If a cycle exists, return "Yes"; otherwise, return "No".

---

## Examples

### Example 1

**Input:**  
Edges:  
`edges = [[1, 2], [2, 3], [3, 4], [4, 1]]`  
Number of vertices: `n = 4`  
Number of edges: `m = 4`

**Output:**  
`Yes`

**Explanation:**  
The graph contains a cycle: \(1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 1\).

---

### Example 2

**Input:**  
Edges:  
`edges = [[1, 2], [2, 3]]`  
Number of vertices: `n = 3`  
Number of edges: `m = 2`

**Output:**  
`No`

**Explanation:**  
The graph does not contain any cycle.

---

## Constraints

- \( 1 \leq n, m \leq 10^5 \)
- The graph is represented using an adjacency list.

---

## Algorithm

### Depth-First Search (DFS) Approach

1. Use an adjacency list to represent the graph.
2. Use a `visited` array to track visited nodes.
3. For each unvisited node, perform DFS:
   - If the adjacent node is already visited and is not the parent of the current node, a cycle is detected.
4. If any cycle is found, return "Yes"; otherwise, return "No".

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Depth First Search (DFS) for cycle detection
bool dfs(int node, int parent, vector<int> adj[], vector<int> &vis) {
    vis[node] = 1;
    for (auto adjacentNode : adj[node]) {
        if (parent == adjacentNode) {
            continue;
        }
        if (!vis[adjacentNode]) {
            if (dfs(adjacentNode, node, adj, vis)) {
                return true;
            }
        } else if (adjacentNode != parent) {
            return true;
        }
    }
    return false;
}

// Cycle Detection Function
string cycleDetection(vector<vector<int>> &edges, int n, int m) {
    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; i++) { // Use 1-based indexing
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                return "Yes";
            }
        }
    }
    return "No";
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    cout << cycleDetection(edges, n, m) << endl;
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

public class Solution {

    // Depth First Search (DFS) for cycle detection
    private static boolean dfs(int node, int parent, List<List<Integer>> adj, boolean[] vis) {
        vis[node] = true;

        for (int adjacentNode : adj.get(node)) {
            if (adjacentNode == parent) {
                continue;
            }
            if (!vis[adjacentNode]) {
                if (dfs(adjacentNode, node, adj, vis)) {
                    return true;
                }
            } else if (adjacentNode != parent) {
                return true;
            }
        }
        return false;
    }

    // Cycle Detection Function
    public static String cycleDetection(List<List<Integer>> edges, int n) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (List<Integer> edge : edges) {
            int u = edge.get(0);
            int v = edge.get(1);
            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        boolean[] visited = new boolean[n + 1];

        for (int i = 1; i <= n; i++) { // Use 1-based indexing
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited)) {
                    return "Yes";
                }
            }
        }
        return "No";
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<List<Integer>> edges = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            edges.add(Arrays.asList(u, v));
        }
        System.out.println(cycleDetection(edges, n));
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS Traversal:** \( O(V + E) \), where \( V \) is the number of vertices and \( E \) is the number of edges.

### Space Complexity

- **Visited Array:** \( O(V) \).
- **Recursive Stack:** \( O(V) \) in the worst case for DFS.

---

## How to Run the Code

### For C++

1. Copy the C++ implementation into a `.cpp` file.
2. Compile using a C++ compiler:

   ```bash
   g++ -o detectCycle detectCycle.cpp
   ```

3. Run the executable:

   ```bash
   ./detectCycle
   ```

### For Java

1. Copy the Java implementation into a file named `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
