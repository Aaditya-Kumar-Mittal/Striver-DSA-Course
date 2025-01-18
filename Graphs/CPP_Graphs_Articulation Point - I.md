# Articulation Point - I

## Table of Contents

- [Articulation Point - I](#articulation-point---i)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Concepts](#key-concepts)
    - [Steps](#steps)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)

---

## Introduction

An **articulation point** (or cut vertex) in an undirected graph is a vertex that, if removed (along with its edges), causes the graph to become disconnected. The goal is to identify all such vertices in the given graph.

This problem is efficiently solved using **Tarjan’s Algorithm**, which employs Depth-First Search (DFS) to determine the articulation points.

---

## Problem Description

**Input:**

1. \( V \): Number of vertices in the graph.
2. \( adj \): Adjacency list representation of the graph.

**Output:**

- A sorted list of articulation points in the graph. If there are no articulation points, return \([-1]\).

---

## Examples

### Example 1

**Input:**

```bash
V = 5, E = 5
Edges = [(0, 1), (0, 2), (1, 3), (3, 4), (1, 4)]
```

**Output:**

```bash
[1, 3]
```

**Explanation:**

- Removing vertex \(1\) disconnects the graph into two components.
- Removing vertex \(3\) also disconnects the graph.

---

## Constraints

- \(1 \leq V \leq 10^5\)
- Graph is undirected and connected.

---

## Approach

### Key Concepts

- **Discovery Time (\(tin\))**: The time at which a vertex is first visited during DFS.
- **Lowest Time (\(low\))**: The earliest discovery time reachable from the current vertex or its descendants.
- **Children Count**: Tracks the number of children for a vertex during DFS.

### Steps

1. **Graph Representation**:
   - Use an adjacency list to represent the graph.

2. **DFS Traversal**:
   - Perform DFS from an unvisited node.
   - For each vertex:
     - Update \(tin\) and \(low\) values.
     - Count its children.
     - Check if removing the vertex disconnects the graph using:
       \[
       \text{low[neighbor]} \geq \text{tin[node]}
       \]

3. **Special Case for Root Node**:
   - The root node is an articulation point if it has more than one child in the DFS tree.

4. **Result**:
   - Collect all articulation points and return them in sorted order.

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
             int tin[], int low[], vector<int>& marked) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;
        int children = 0;

        for (auto neighbor : adj[node]) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                children++;
                dfs(neighbor, node, visited, adj, tin, low, marked);
                low[node] = min(low[node], low[neighbor]);

                // Check if the current node is an articulation point
                if (low[neighbor] >= tin[node] && parent != -1) {
                    marked[node] = 1;
                }
            } else {
                // Back edge
                low[node] = min(low[node], tin[neighbor]);
            }
        }

        // Special case for root node
        if (parent == -1 && children > 1) {
            marked[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        vector<int> visited(V, 0), marked(V, 0);
        int tin[V], low[V];

        // Perform DFS for all components
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj, tin, low, marked);
            }
        }

        // Collect articulation points
        vector<int> ans;
        for (int i = 0; i < V; ++i) {
            if (marked[i]) {
                ans.push_back(i);
            }
        }

        // If no articulation points are found
        if (ans.empty()) return {-1};
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (int x : ans) {
            cout << x << " ";
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
    private int timer = 1;

    private void dfs(int node, int parent, boolean[] visited, List<List<Integer>> adj,
                     int[] tin, int[] low, int[] marked) {
        visited[node] = true;
        tin[node] = low[node] = timer++;
        int children = 0;

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                children++;
                dfs(neighbor, node, visited, adj, tin, low, marked);
                low[node] = Math.min(low[node], low[neighbor]);

                // Check if the current node is an articulation point
                if (low[neighbor] >= tin[node] && parent != -1) {
                    marked[node] = 1;
                }
            } else {
                // Back edge
                low[node] = Math.min(low[node], tin[neighbor]);
            }
        }

        // Special case for root node
        if (parent == -1 && children > 1) {
            marked[node] = 1;
        }
    }

    public List<Integer> articulationPoints(int V, List<List<Integer>> adj) {
        boolean[] visited = new boolean[V];
        int[] tin = new int[V], low = new int[V], marked = new int[V];

        // Perform DFS for all components
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, -1, visited, adj, tin, low, marked);
            }
        }

        // Collect articulation points
        List<Integer> result = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            if (marked[i] == 1) {
                result.add(i);
            }
        }

        // If no articulation points are found
        if (result.isEmpty()) return Arrays.asList(-1);
        return result;
    }
}

public class Main {
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

            Solution sol = new Solution();
            List<Integer> ans = sol.articulationPoints(V, adj);
            for (int x : ans) {
                System.out.print(x + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.
- **Space Complexity**: \(O(V + E)\) for adjacency list, and \(O(V)\) for auxiliary arrays.

---

## How to Run the Code

1. Input format:
   - Number of test cases.
   - For each test case:
     - Number of vertices (\(V\)) and edges (\(E\)).
     - List of edges.

2. Example Input:

   ```bash
   1
   5 5
   0 1
   0 2
   1 3
   3 4
   1 4
   ```

3. Example Output:

   ```bash
   1 3
   ```
