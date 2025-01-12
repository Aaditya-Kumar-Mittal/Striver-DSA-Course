# Is Graph Bipartite?

## Table of Contents

- [Is Graph Bipartite?](#is-graph-bipartite)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
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

A graph is **bipartite** if it is possible to partition its nodes into two disjoint sets \(A\) and \(B\) such that every edge connects a node in set \(A\) to a node in set \(B\).

In this problem, given an undirected graph represented as an adjacency list, the task is to determine if the graph is bipartite.

---

## Problem Description

- **Input:** A 2D list `graph` where `graph[u]` contains all nodes adjacent to node `u`.
- **Output:** Return `true` if the graph is bipartite, otherwise `false`.

---

## Examples

### Example 1

**Input:**  

```text
graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
```

**Output:**  

```text
false
```

**Explanation:**  
It is impossible to partition the nodes into two sets such that every edge connects a node from one set to the other.

---

### Example 2

**Input:**  

```text
graph = [[1,3],[0,2],[1,3],[0,2]]
```

**Output:**  

```text
true
```

**Explanation:**  
The graph can be partitioned into two sets: \(\{0, 2\}\) and \(\{1, 3\}\).

---

## Constraints

- \(1 \leq n \leq 100\)
- \(0 \leq \text{graph[u].length} < n\)
- The graph has no self-loops or duplicate edges.
- If \(v \in \text{graph[u]}\), then \(u \in \text{graph[v]}\).

---

## Approach

### Steps

1. **Coloring:**  
   Assign two colors (0 and 1) to the nodes to differentiate between the two sets. Use a `color` array initialized to `-1` to track the color of each node.
2. **Breadth-First Search (BFS):**  
   Traverse each connected component of the graph using BFS:
   - Color the starting node with color 0.
   - For each adjacent node:
     - If uncolored, assign it the opposite color of the current node.
     - If already colored and the color matches the current node, the graph is not bipartite.
3. **Iterate Through All Nodes:**  
   Since the graph may be disconnected, check each node for bipartiteness.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool check(int start, vector<vector<int>>& graph, vector<int>& color) {
        queue<int> q;
        q.push(start);
        color[start] = 0; // Start with color 0

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = !color[node]; // Assign opposite color
                    q.push(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Same color found, not bipartite
                }
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize all nodes as uncolored

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // Check unvisited components
                if (!check(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private boolean check(int start, int[][] graph, int[] color) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(start);
        color[start] = 0; // Start with color 0

        while (!q.isEmpty()) {
            int node = q.poll();

            for (int neighbor : graph[node]) {
                if (color[neighbor] == -1) {
                    color[neighbor] = 1 - color[node]; // Assign opposite color
                    q.offer(neighbor);
                } else if (color[neighbor] == color[node]) {
                    return false; // Same color found, not bipartite
                }
            }
        }
        return true;
    }

    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int[] color = new int[n];
        Arrays.fill(color, -1); // Initialize all nodes as uncolored

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) { // Check unvisited components
                if (!check(i, graph, color)) {
                    return false;
                }
            }
        }
        return true;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **BFS Traversal:** Each node and edge is processed once.
  \(O(V + E)\), where \(V\) is the number of nodes and \(E\) is the number of edges.

### Space Complexity

- **Color Array:** \(O(V)\)
- **Queue:** \(O(V)\) in the worst case.

**Overall:** \(O(V + E)\)

---

## How to Run the Code

### For C++

1. Compile the program:

   ```bash
   g++ -o solution solution.cpp
   ```

2. Run the program:

   ```bash
   ./solution
   ```

### For Java

1. Compile the program:

   ```bash
   javac Solution.java
   ```

2. Run the program:

   ```bash
   java Solution
   ```
