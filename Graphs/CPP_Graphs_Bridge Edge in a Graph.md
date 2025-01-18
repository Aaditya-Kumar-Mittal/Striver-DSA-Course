# Bridge Edge in a Graph

## Table of Contents

- [Bridge Edge in a Graph](#bridge-edge-in-a-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Tarjan’s Algorithm for Bridges](#tarjans-algorithm-for-bridges)
    - [Steps](#steps)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [Input Format](#input-format)
    - [Example Input](#example-input)
    - [Example Output](#example-output)

---

## Introduction

In this problem, we are tasked with determining whether a given edge in an undirected graph is a **bridge**. A **bridge** is an edge that, if removed, disconnects the graph into multiple components.

We solve this problem using **Tarjan’s Algorithm**, which efficiently identifies bridges using Depth-First Search (DFS).

---

## Problem Description

**Input:**

1. \(V\): Number of vertices in the graph.
2. \(E\): Number of edges in the graph.
3. \(adj\): Adjacency list representation of the graph.
4. \((c, d)\): The edge to check if it is a bridge.

**Output:**

- Return \(1\) if the edge \((c, d)\) is a bridge.
- Return \(0\) otherwise.

---

## Examples

### Example 1

**Input:**

```bash
V = 4, E = 4
Edges = [(0, 1), (1, 2), (2, 0), (1, 3)]
Edge to check: (1, 3)
```

**Output:**

```bash
1
```

**Explanation:**
Removing the edge \((1, 3)\) disconnects the graph, so it is a bridge.

---

### Example 2

**Input:**

```bash
V = 4, E = 4
Edges = [(0, 1), (1, 2), (2, 0), (1, 3)]
Edge to check: (0, 2)
```

**Output:**

```bash
0
```

**Explanation:**
Removing the edge \((0, 2)\) does not disconnect the graph, so it is not a bridge.

---

## Constraints

- \(1 \leq V, E \leq 10^5\)
- \(0 \leq c, d \leq V-1\)

---

## Approach

### Tarjan’s Algorithm for Bridges

Tarjan's Algorithm is based on Depth-First Search (DFS) and uses:

1. **Discovery Time (\(tin\))**: Time when a vertex is first visited during DFS.
2. **Lowest Time (\(low\))**: The earliest discovery time reachable from the current node or its descendants.

### Steps

1. **Graph Representation**:
   - Use an adjacency list to represent the graph.

2. **DFS Traversal**:
   - Start DFS from an unvisited node.
   - For each vertex, update its \(tin\) and \(low\) values.
   - Check if the given edge \((c, d)\) satisfies the condition for being a bridge:  
     \[
     \text{low[neighbor]} > \text{tin[node]}
     \]

3. **Result**:
   - If the edge satisfies the condition, mark it as a bridge.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& visited, vector<int> adj[], 
             int tin[], int low[], int& is_bridge, int c, int d) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto neighbor : adj[node]) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node, visited, adj, tin, low, is_bridge, c, d);
                low[node] = min(low[node], low[neighbor]);

                // Check if the edge (node, neighbor) is a bridge
                if (low[neighbor] > tin[node]) {
                    if ((node == c && neighbor == d) || (node == d && neighbor == c)) {
                        is_bridge = 1;
                    }
                }
            } else {
                // Back edge
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

public:
    int isBridge(int V, vector<int> adj[], int c, int d) {
        vector<int> visited(V, 0);
        int tin[V], low[V];
        int is_bridge = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj, tin, low, is_bridge, c, d);
            }
        }

        return is_bridge;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private int timer = 1;

    private void dfs(int node, int parent, boolean[] visited, List<List<Integer>> adj, 
                     int[] tin, int[] low, int[] isBridge, int c, int d) {
        visited[node] = true;
        tin[node] = low[node] = timer++;

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node, visited, adj, tin, low, isBridge, c, d);
                low[node] = Math.min(low[node], low[neighbor]);

                // Check if the edge (node, neighbor) is a bridge
                if (low[neighbor] > tin[node]) {
                    if ((node == c && neighbor == d) || (node == d && neighbor == c)) {
                        isBridge[0] = 1;
                    }
                }
            } else {
                // Back edge
                low[node] = Math.min(low[node], tin[neighbor]);
            }
        }
    }

    public int isBridge(int V, List<List<Integer>> adj, int c, int d) {
        boolean[] visited = new boolean[V];
        int[] tin = new int[V];
        int[] low = new int[V];
        int[] isBridge = {0};

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj, tin, low, isBridge, c, d);
            }
        }

        return isBridge[0];
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
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
                adj.get(v).add(u);
            }

            int c = sc.nextInt();
            int d = sc.nextInt();

            Solution sol = new Solution();
            System.out.println(sol.isBridge(V, adj, c, d));
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS Traversal**: \(O(V + E)\)

### Space Complexity

- **Adjacency List**: \(O(V + E)\)
- **Auxiliary Space (Visited, Tin, Low)**: \(O(V)\)

**Total Space Complexity**: \(O(V + E)\).

---

## How to Run the Code

### Input Format

1. Number of test cases.
2. For each test case:
   - Number of vertices (\(V\)) and edges (\(E\)).
   - List of edges.
   - The edge to check.

### Example Input

```bash
1
4 4
0 1
1 2
2 0
1 3
1 3
```

### Example Output

```bash
1
```
