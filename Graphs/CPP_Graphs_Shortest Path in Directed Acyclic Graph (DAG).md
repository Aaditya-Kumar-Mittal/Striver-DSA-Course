# Shortest Path in Directed Acyclic Graph (DAG)

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Shortest Path in Directed Acyclic Graph (DAG)](#shortest-path-in-directed-acyclic-graph-dag)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Expected Output](#expected-output)
    - [Definitions](#definitions)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
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

The **Shortest Path in Directed Acyclic Graph (DAG)** problem involves finding the shortest path from the source vertex (0) to all other vertices in a directed acyclic graph. A DAG is a directed graph that contains no cycles. The graph is given as a list of edges with weights, and the task is to compute the shortest path from the source vertex (0) to every other vertex, returning `-1` for vertices that are unreachable.

---

## Problem Description

You are given:

- `V`: Number of vertices (0 to n-1).
- `E`: Number of edges.
- `edges`: A 2D array where each entry represents a directed edge from vertex `edges[i][0]` to vertex `edges[i][1]` with a weight `edges[i][2]`.

### Expected Output

- A list of shortest distances from the source vertex (0) to all vertices. If a vertex is unreachable, the distance for that vertex should be `-1`.

### Definitions

- **Shortest Path:** The path that has the least total weight.
- **DAG (Directed Acyclic Graph):** A graph with directed edges and no cycles.

---

### Examples

#### Example 1

**Input:**

```text
V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
```

**Output:**

```text
[0, 2, 1, -1]
```

**Explanation:**

- The shortest path from 0 to 1 is `0 -> 1` with weight `2`.
- The shortest path from 0 to 2 is `0 -> 2` with weight `1`.
- There is no path from 0 to vertex 3, so the output is `-1`.

---

#### Example 2

**Input:**

```text
V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
```

**Output:**

```text
[0, 2, 3, 6, 1, 5]
```

**Explanation:**

- The shortest path from 0 to 1 is `0 -> 1` with weight `2`.
- The shortest path from 0 to 2 is `0 -> 4 -> 2` with weight `1 + 2 = 3`.
- The shortest path from 0 to 3 is `0 -> 4 -> 5 -> 3` with weight `1 + 4 + 1 = 6`.
- The shortest path from 0 to 4 is `0 -> 4` with weight `1`.
- The shortest path from 0 to 5 is `0 -> 4 -> 5` with weight `1 + 4 = 5`.

---

### Constraints

- \( 1 \leq V \leq 1000 \)
- \( 1 \leq E \leq \min((N \times (N - 1)) / 2, 4000) \)
- \( 0 \leq \text{edges}[i][0], \text{edges}[i][1] < n \)
- \( 0 \leq \text{edge}[i][2] \leq 10^5 \)

---

## Approach

To solve this problem, we can use **Topological Sorting** followed by **Relaxation** of edges:

1. **Topological Sort**: Perform a topological sort of the graph to ensure we process each vertex in the correct order.
   - Use **DFS** or **Kahn's Algorithm** to achieve topological sorting.
2. **Relaxation**: After sorting, relax the edges one by one. Start from the source vertex (0), and update the shortest distances for all reachable vertices.
   - If a vertex has an edge to another vertex and the distance to the destination can be improved by going through the current vertex, update the distance.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<int>& visited, stack<int>& stk) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            int v = it.first;
            if (!visited[v]) {
                dfs(v, adj, visited, stk);
            }
        }
        stk.push(node);
    }

public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // Adjacency list representation of the graph
        vector<vector<pair<int, int>>> adj(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Topological sorting using DFS
        vector<int> visited(V, 0);
        stack<int> stk;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, stk);
            }
        }

        // Distance array initialization
        vector<int> distances(V, INT_MAX);
        distances[0] = 0;

        // Relax edges based on topological order
        while (!stk.empty()) {
            int node = stk.top();
            stk.pop();
            if (distances[node] != INT_MAX) {
                for (auto it : adj[node]) {
                    int v = it.first;
                    int wt = it.second;
                    if (distances[node] + wt < distances[v]) {
                        distances[v] = distances[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable nodes' distance with -1
        for (int i = 0; i < V; i++) {
            if (distances[i] == INT_MAX) {
                distances[i] = -1;
            }
        }

        return distances;
    }
};
```

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int node, List<List<int[]>> adj, int[] visited, Stack<Integer> stk) {
        visited[node] = 1;
        for (int[] edge : adj.get(node)) {
            int v = edge[0];
            if (visited[v] == 0) {
                dfs(v, adj, visited, stk);
            }
        }
        stk.push(node);
    }

    public int[] shortestPath(int V, int E, int[][] edges) {
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }

        // Create the graph
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj.get(u).add(new int[]{v, w});
        }

        // Topological sort
        int[] visited = new int[V];
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, stk);
            }
        }

        // Distance array initialization
        int[] distances = new int[V];
        Arrays.fill(distances, Integer.MAX_VALUE);
        distances[0] = 0;

        // Relax edges based on topological order
        while (!stk.isEmpty()) {
            int node = stk.pop();
            if (distances[node] != Integer.MAX_VALUE) {
                for (int[] edge : adj.get(node)) {
                    int v = edge[0];
                    int wt = edge[1];
                    if (distances[node] + wt < distances[v]) {
                        distances[v] = distances[node] + wt;
                    }
                }
            }
        }

        // Replace unreachable nodes' distance with -1
        for (int i = 0; i < V; i++) {
            if (distances[i] == Integer.MAX_VALUE) {
                distances[i] = -1;
            }
        }

        return distances;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Construction:** \( O(E) \), where \( E \) is the number of edges.
- **Topological Sort (DFS):** \( O(V + E) \), where \( V \) is the number of vertices and \( E \) is the number of edges.
- **Relaxation of Edges:** \( O(E) \), as each edge is relaxed at most once.

Overall: \( O(V + E) \)

### Space Complexity

- **Graph Representation:** \( O(V + E) \)
- **Auxiliary Structures (Visited, Stack, Distances):** \( O(V) \)

Overall: \( O(V + E) \)

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile using a command like:

   ```bash
   g++ -std=c++17 -o output filename.cpp
   ```

3. Run the executable:

   ```bash
   ./output
   ```

### For Java

1. Save the code in a `.java` file.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
