# 802. Find Eventual Safe States

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [802. Find Eventual Safe States](#802-find-eventual-safe-states)
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

A **safe node** is a node where every possible path starting from it eventually leads to a terminal node (a node with no outgoing edges) or other safe nodes. The task is to identify and return all such nodes in sorted order.

---

## Problem Description

- **Input:**  
  A directed graph represented as a 2D list, where `graph[i]` is the list of nodes directly reachable from node `i`.

- **Output:**  
  Return an array of all safe nodes in ascending order.

---

## Examples

### Example 1

**Input:**  

```text
graph = [[1,2],[2,3],[5],[0],[5],[],[]]
```

**Output:**  

```text
[2,4,5,6]
```

**Explanation:**  
Nodes 5 and 6 are terminal nodes. Nodes 2 and 4 are safe because all paths starting from them eventually lead to terminal nodes.

---

### Example 2

**Input:**  

```text
graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
```

**Output:**  

```text
[4]
```

**Explanation:**  
Only node 4 is a terminal node, and all paths starting at node 4 lead to it.

---

## Constraints

- \( n = \text{graph.length} \)
- \( 1 \leq n \leq 10^4 \)
- \( 0 \leq \text{graph[i].length} \leq n \)
- \( 0 \leq \text{graph[i][j]} \leq n - 1 \)
- `graph[i]` is sorted in strictly increasing order.
- The graph may contain self-loops.
- The number of edges in the graph will be in the range \([1, 4 \times 10^4]\).

---

## Approach

### Steps

1. **DFS-Based Cycle Detection:**
   - Use **DFS** to identify cycles. Any node that is part of a cycle is not a safe node.
   - Maintain three arrays:
     - `visited`: To check if a node is visited.
     - `pathVisited`: To track nodes in the current recursion stack.
     - `check`: To mark nodes as safe or unsafe.

2. **Node Classification:**
   - If a node is part of a cycle or leads to a cycle, it is marked as unsafe (`check[node] = 0`).
   - Otherwise, it is marked as safe (`check[node] = 1`).

3. **Safe Node Collection:**
   - Traverse the `check` array and collect all nodes marked as safe.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& graph, vector<int>& visited, vector<int>& pathVisited, vector<int>& check) {
        visited[node] = 1; // Mark the node as visited
        pathVisited[node] = 1; // Mark the node as part of the current recursion stack

        for (auto neighbor : graph[node]) {
            // If the neighbor is not visited, do a DFS on it
            if (!visited[neighbor]) {
                if (dfsCheck(neighbor, graph, visited, pathVisited, check)) {
                    check[node] = 0;
                    return true; // Cycle detected
                }
            }
            // If the neighbor is already in the current recursion stack, a cycle is detected
            else if (pathVisited[neighbor]) {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1; // Mark the node as safe
        pathVisited[node] = 0; // Remove the node from the recursion stack
        return false; // No cycle detected for this path
    }

public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> visited(V, 0), pathVisited(V, 0), check(V, 0);
        vector<int> safeNodes;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfsCheck(i, graph, visited, pathVisited, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};

// Driver Code
int main() {
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
    Solution obj;
    vector<int> result = obj.eventualSafeNodes(graph);
    for (int node : result) {
        cout << node << " ";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private boolean dfsCheck(int node, List<List<Integer>> graph, int[] visited, int[] pathVisited, int[] check) {
        visited[node] = 1; // Mark the node as visited
        pathVisited[node] = 1; // Mark the node as part of the current recursion stack

        for (int neighbor : graph.get(node)) {
            // If the neighbor is not visited, do a DFS on it
            if (visited[neighbor] == 0) {
                if (dfsCheck(neighbor, graph, visited, pathVisited, check)) {
                    check[node] = 0;
                    return true; // Cycle detected
                }
            }
            // If the neighbor is already in the current recursion stack, a cycle is detected
            else if (pathVisited[neighbor] == 1) {
                check[node] = 0;
                return true;
            }
        }

        check[node] = 1; // Mark the node as safe
        pathVisited[node] = 0; // Remove the node from the recursion stack
        return false; // No cycle detected for this path
    }

    public List<Integer> eventualSafeNodes(int[][] graph) {
        int V = graph.length;
        int[] visited = new int[V], pathVisited = new int[V], check = new int[V];
        List<Integer> safeNodes = new ArrayList<>();

        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
            for (int node : graph[i]) {
                adj.get(i).add(node);
            }
        }

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {
                dfsCheck(i, adj, visited, pathVisited, check);
            }
        }

        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safeNodes.add(i);
            }
        }

        return safeNodes;
    }

    public static void main(String[] args) {
        int[][] graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
        Solution obj = new Solution();
        System.out.println(obj.eventualSafeNodes(graph));
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS Traversal:** \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

### Space Complexity

- **Auxiliary Space:** \(O(V)\) for arrays `visited`, `pathVisited`, and `check`.
- **Recursion Stack:** \(O(V)\) for the worst-case recursion depth.

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
