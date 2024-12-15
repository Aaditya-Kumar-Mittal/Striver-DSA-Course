# Depth First Search (DFS) of a Graph

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Depth First Search (DFS) of a Graph](#depth-first-search-dfs-of-a-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Statement](#problem-statement)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Algorithm](#algorithm)
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

Depth-First Search (DFS) is a graph traversal technique where we start at a vertex and explore as far along each branch as possible before backtracking. DFS can be implemented recursively or iteratively (using a stack). It is particularly useful for tasks such as connectivity checking, cycle detection, and pathfinding.

---

## Problem Statement

Given a connected undirected graph represented by an adjacency list `adj`, perform a **Depth First Traversal (DFS)** starting from vertex `0`. Traverse vertices in the order they appear in the adjacency list and return a list of vertices in DFS traversal order.

---

## Examples

### Example 1

**Input:**  
`adj = [[2,3,1], [0], [0,4], [0], [2]]`  

**Output:**  
`[0, 2, 4, 3, 1]`

**Explanation:**  

1. Start at vertex 0 → Output: `[0]`.  
2. Visit 2 (first neighbor of 0) → Output: `[0, 2]`.  
3. Visit 4 (first neighbor of 2) → Output: `[0, 2, 4]`.  
4. Backtrack to 2, then to 0, and visit 3 → Output: `[0, 2, 4, 3]`.  
5. Backtrack to 0 and visit 1 → Final Output: `[0, 2, 4, 3, 1]`.

---

### Example 2

**Input:**  
`adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`  

**Output:**  
`[0, 1, 2, 3, 4]`

**Explanation:**  
The traversal proceeds as follows:  
0 → 1 → 2 → 3 → 4.

---

## Constraints

- \( 1 \leq \text{adj.size()} \leq 10^4 \)
- \( 1 \leq \text{adj[i][j]} \leq 10^4 \)

---

## Algorithm

### Steps

1. Define a helper function `dfs(node, adj, vis, traversal)` that:
   - Marks the current node as visited.
   - Appends the current node to the traversal result.
   - Recursively visits all unvisited neighbors in the adjacency list.
2. Start DFS from vertex `0` and initialize:
   - A `visited` array to track visited vertices.
   - A `traversal` list to store the DFS traversal order.
3. Call the recursive helper function `dfs(0, adj, vis, traversal)` to begin the traversal.
4. Return the `traversal` list as the result.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& traversal) {
        // Mark the node as visited
        visited[node] = 1;
        traversal.push_back(node);

        // Visit all unvisited neighbors
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, traversal);
            }
        }
    }

public:
    // Function to return DFS traversal of the graph
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size(); // Number of vertices
        vector<int> visited(V, 0); // Visited array
        vector<int> traversal;    // Result array

        // Start DFS from vertex 0
        dfs(0, adj, visited, traversal);

        return traversal;
    }
};

// Driver Code
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V); // Adjacency list
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }

        Solution obj;
        vector<int> result = obj.dfsOfGraph(adj);
        for (int val : result) {
            cout << val << " ";
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
    private void dfs(int node, ArrayList<ArrayList<Integer>> adj, boolean[] visited, ArrayList<Integer> traversal) {
        // Mark the node as visited
        visited[node] = true;
        traversal.add(node);

        // Visit all unvisited neighbors
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited, traversal);
            }
        }
    }

    // Function to return DFS traversal of the graph
    public ArrayList<Integer> dfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V];
        ArrayList<Integer> traversal = new ArrayList<>();

        // Start DFS from vertex 0
        dfs(0, adj, visited, traversal);

        return traversal;
    }
}

// Driver Code
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
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
                adj.get(v).add(u); // Since the graph is undirected
            }

            Solution obj = new Solution();
            ArrayList<Integer> result = obj.dfsOfGraph(V, adj);
            for (int val : result) {
                System.out.print(val + " ");
            }
            System.out.println();
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Construction:** \( O(V + E) \), where \( V \) is the number of vertices and \( E \) is the number of edges.
- **DFS Traversal:** \( O(V + E) \), as each vertex and edge is visited once.

### Space Complexity

- **Adjacency List:** \( O(V + E) \)
- **Visited Array:** \( O(V) \)
- **Recursive Stack Space:** \( O(V) \) in the worst case (for a completely connected graph).

---

## How to Run the Code

### For C++

1. Copy the C++ implementation into a file, e.g., `dfs.cpp`.
2. Compile using `g++`:

   ```bash
   g++ -o dfs dfs.cpp
   ```

3. Run the program:

   ```bash
   ./dfs
   ```

### For Java

1. Copy the Java implementation into a file named `Main.java`.
2. Compile using:

   ```bash
   javac Main.java
   ```

3. Run the program:

   ```bash
   java Main
   ```
