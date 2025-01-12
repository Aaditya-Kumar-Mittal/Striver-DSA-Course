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

A **cycle** in a directed graph occurs when there exists a path of vertices such that a vertex is revisited before completing the traversal. This task aims to determine if a given directed graph has any cycle.

---

## Problem Description

- **Input:**  
  A directed graph with \(V\) vertices and \(E\) edges represented as an adjacency list.  
  - `adj[i]` contains the list of vertices directly reachable from vertex `i`.

- **Output:**  
  Return `1` if the graph contains a cycle; otherwise, return `0`.

---

## Examples

### Example 1

**Input:**  

```text
V = 4, adj = [[1], [2], [3], [0]]
```

**Output:**  

```text
1
```

**Explanation:**  
The cycle exists as \(3 \to 0 \to 1 \to 2 \to 3\).

---

### Example 2

**Input:**  

```text
V = 4, adj = [[1], [2], [3], []]
```

**Output:**  

```text
0
```

**Explanation:**  
No cycle exists in the graph.

---

## Constraints

- \(1 \leq V \leq 10^4\)
- \(0 \leq E \leq 10^4\)

---

## Approach

### Steps

1. **DFS-Based Cycle Detection:**
   - Use **DFS** traversal to detect cycles.
   - Maintain two arrays:
     - `visited`: To check if a node is visited.
     - `pathVisited`: To track nodes in the current recursion stack.
   - If a node is already in the recursion stack (`pathVisited`) during traversal, a cycle exists.

2. **Iterate Through All Nodes:**
   - Start DFS from every unvisited node to handle disconnected components.

3. **Recursive Backtracking:**
   - Remove the node from `pathVisited` after returning from recursion to avoid false positives.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfsCheck(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& pathVisited) {
        visited[node] = 1;          // Mark the node as visited
        pathVisited[node] = 1;      // Mark the node as part of the current recursion stack

        for (auto neighbor : adj[node]) {
            // If the neighbor is not visited, do a DFS on it
            if (!visited[neighbor]) {
                if (dfsCheck(neighbor, adj, visited, pathVisited)) {
                    return true;
                }
            }
            // If the neighbor is already in the current recursion stack, a cycle is detected
            else if (pathVisited[neighbor]) {
                return true;
            }
        }

        pathVisited[node] = 0;      // Remove the node from the recursion stack
        return false;               // No cycle detected for this path
    }

public:
    bool isCyclic(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0), pathVisited(V, 0);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {      // Start DFS from every unvisited node
                if (dfsCheck(i, adj, visited, pathVisited)) {
                    return true;
                }
            }
        }
        return false;               // No cycle found
    }
};

// Driver Code
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

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private boolean dfsCheck(int node, List<List<Integer>> adj, int[] visited, int[] pathVisited) {
        visited[node] = 1;          // Mark the node as visited
        pathVisited[node] = 1;      // Mark the node as part of the current recursion stack

        for (int neighbor : adj.get(node)) {
            // If the neighbor is not visited, do a DFS on it
            if (visited[neighbor] == 0) {
                if (dfsCheck(neighbor, adj, visited, pathVisited)) {
                    return true;
                }
            }
            // If the neighbor is already in the current recursion stack, a cycle is detected
            else if (pathVisited[neighbor] == 1) {
                return true;
            }
        }

        pathVisited[node] = 0;      // Remove the node from the recursion stack
        return false;               // No cycle detected for this path
    }

    public boolean isCyclic(int V, List<List<Integer>> adj) {
        int[] visited = new int[V];
        int[] pathVisited = new int[V];

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) {  // Start DFS from every unvisited node
                if (dfsCheck(i, adj, visited, pathVisited)) {
                    return true;
                }
            }
        }
        return false;               // No cycle found
    }

    // Driver Code
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
            }

            Solution obj = new Solution();
            System.out.println(obj.isCyclic(V, adj) ? "1" : "0");
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS Traversal:** \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

### Space Complexity

- **Auxiliary Space:** \(O(V)\) for the `visited` and `pathVisited` arrays.
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
