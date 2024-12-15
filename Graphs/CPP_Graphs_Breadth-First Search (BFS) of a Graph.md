# Breadth-First Search (BFS) of a Graph

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Breadth-First Search (BFS) of a Graph](#breadth-first-search-bfs-of-a-graph)
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

Breadth-First Search (BFS) is a fundamental graph traversal technique that explores all vertices at the same depth level before moving deeper into the graph. BFS uses a queue to systematically explore the graph layer by layer, making it suitable for solving shortest path problems in unweighted graphs.

---

## Problem Statement

Given a connected undirected graph represented as an adjacency list `adj`, perform a **Breadth-First Traversal (BFS)** starting from vertex `0`. Traverse the vertices in the order they appear in the adjacency list and return a list of vertices in the BFS traversal order.

---

## Examples

### Example 1

**Input:**  
`adj = [[2,3,1], [0], [0,4], [0], [2]]`  

**Output:**  
`[0, 2, 3, 1, 4]`

**Explanation:**  

1. Start at vertex 0 → Output: `[0]`.  
2. Visit neighbors of 0: `[2, 3, 1]` in the adjacency list order → Output: `[0, 2, 3, 1]`.  
3. Visit neighbor of 2: `[4]` → Final Output: `[0, 2, 3, 1, 4]`.

---

### Example 2

**Input:**  
`adj = [[1, 2], [0, 2], [0, 1, 3, 4], [2], [2]]`  

**Output:**  
`[0, 1, 2, 3, 4]`

**Explanation:**  
The traversal order is as follows:  
0 → 1 → 2 → 3 → 4.

---

## Constraints

- \( 1 \leq \text{adj.size()} \leq 10^4 \)
- \( 1 \leq \text{adj[i][j]} \leq 10^4 \)

---

## Algorithm

### Steps

1. Initialize a `visited` array to keep track of visited nodes.
2. Create a queue to store vertices for BFS traversal.
3. Start BFS from vertex `0`:
   - Mark vertex `0` as visited and enqueue it.
4. While the queue is not empty:
   - Dequeue a vertex and append it to the BFS result.
   - For each unvisited neighbor, mark it as visited and enqueue it.
5. Return the BFS traversal order.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of the given graph.
    vector<int> bfsOfGraph(vector<vector<int>>& adj) {
        int V = adj.size();  // Number of vertices
        vector<int> visited(V, 0);
        vector<int> bfs;
        queue<int> q;

        // Start BFS from vertex 0
        visited[0] = 1;
        q.push(0);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            // Visit neighbors of the current node
            for (auto neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        return bfs;
    }
};

// Driver code
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        Solution obj;
        vector<int> ans = obj.bfsOfGraph(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
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
    // Function to return Breadth First Traversal of the given graph.
    public ArrayList<Integer> bfsOfGraph(int V, ArrayList<ArrayList<Integer>> adj) {
        boolean[] visited = new boolean[V];
        ArrayList<Integer> bfs = new ArrayList<>();
        Queue<Integer> queue = new LinkedList<>();

        // Start BFS from vertex 0
        visited[0] = true;
        queue.add(0);

        while (!queue.isEmpty()) {
            int node = queue.poll();
            bfs.add(node);

            // Visit neighbors of the current node
            for (int neighbor : adj.get(node)) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
        return bfs;
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
                adj.get(v).add(u);  // Since the graph is undirected
            }

            Solution obj = new Solution();
            ArrayList<Integer> result = obj.bfsOfGraph(V, adj);

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
- **BFS Traversal:** \( O(V + E) \), as each vertex and edge is visited once.

### Space Complexity

- **Adjacency List:** \( O(V + E) \)
- **Visited Array:** \( O(V) \)
- **Queue for BFS:** \( O(V) \)

---

## How to Run the Code

### For C++

1. Copy the C++ implementation into your development environment.
2. Compile using `g++`:

   ```bash
   g++ -o bfs bfs.cpp
   ```

3. Run the program:

   ```bash
   ./bfs
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
