# Prim's Algorithm - Minimum Spanning Tree

## Table of Contents

- [Prim's Algorithm - Minimum Spanning Tree](#prims-algorithm---minimum-spanning-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

Prim's algorithm is a **greedy algorithm** used to find the **Minimum Spanning Tree (MST)** of a weighted, undirected, and connected graph. The MST is a subset of the edges of the graph that:

1. Connects all the vertices.
2. Has the minimum possible total edge weight.
3. Contains no cycles.

This problem involves implementing Prim's algorithm to find the sum of the edge weights in the MST.

---

## Problem Description

You are given:

1. An integer `V` representing the number of vertices.
2. An integer `E` representing the number of edges.
3. An adjacency list `adj` where `adj[i]` contains a list of pairs `[vertex, weight]` denoting a connection from vertex `i` to another vertex with the specified weight.

The task is to calculate the **sum of the weights** of the edges in the MST.

---

### Examples

#### Example 1

**Input:**

```bash
V = 3, E = 3
Edges: [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
```

**Output:**

```bash
4
```

**Explanation:**  
The MST includes edges `(0, 2)` and `(1, 2)`, with weights `1` and `3` respectively.

---

#### Example 2

**Input:**

```bash
V = 2, E = 1
Edges: [[1, 5]]
```

**Output:**

```bash
5
```

**Explanation:**  
Only one spanning tree is possible with the single edge, having weight `5`.

---

### Constraints

- \( 2 \leq V \leq 1000 \)
- \( V - 1 \leq E \leq \frac{V \cdot (V - 1)}{2} \)
- \( 1 \leq w \leq 1000 \)
- The graph is connected and does not contain self-loops or multiple edges.

---

## Approach

1. **Initialization:**
   - Use a **priority queue** to store the edges based on their weights (minimum first).
   - Keep a **visited array** to track nodes already included in the MST.

2. **Algorithm Steps:**
   - Start with any vertex, initialize its weight as 0, and push it into the priority queue.
   - While the priority queue is not empty:
     - Extract the minimum weight edge.
     - If the vertex connected by this edge is not visited:
       - Add its weight to the MST total.
       - Mark the vertex as visited.
       - Push all its adjacent edges into the priority queue.
   - Continue until all vertices are included in the MST.

3. **Output:**  
   Return the sum of the weights of the edges in the MST.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the sum of weights of edges in the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to store {weight, vertex}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Visited array to track included vertices
        vector<int> visited(V, 0);

        // Start with node 0
        pq.push({0, 0});
        int minSum = 0;

        // Process edges
        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (visited[node]) continue; // Skip already visited nodes

            visited[node] = 1; // Mark as visited
            minSum += wt;      // Add weight to MST sum

            // Push all adjacent edges
            for (auto &neighbor : adj[node]) {
                int adjNode = neighbor[0];
                int edgeWt = neighbor[1];
                if (!visited[adjNode]) {
                    pq.push({edgeWt, adjNode});
                }
            }
        }

        return minSum;
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    // Function to find the sum of weights of edges in the Minimum Spanning Tree.
    public int spanningTree(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj) {
        // Priority queue to store {weight, vertex}
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Visited array to track included vertices
        boolean[] visited = new boolean[V];

        // Start with node 0
        pq.add(new int[] { 0, 0 }); // {weight, node}
        int minSum = 0;

        // Process edges
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int wt = current[0];
            int node = current[1];

            if (visited[node]) continue; // Skip already visited nodes

            visited[node] = true; // Mark as visited
            minSum += wt;         // Add weight to MST sum

            // Push all adjacent edges
            for (ArrayList<Integer> neighbor : adj.get(node)) {
                int adjNode = neighbor.get(0);
                int edgeWt = neighbor.get(1);
                if (!visited[adjNode]) {
                    pq.add(new int[] { edgeWt, adjNode });
                }
            }
        }

        return minSum;
    }

    // Driver Code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) adj.add(new ArrayList<>());
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();
                adj.get(u).add(new ArrayList<>(Arrays.asList(v, w)));
                adj.get(v).add(new ArrayList<>(Arrays.asList(u, w)));
            }
            Solution obj = new Solution();
            System.out.println(obj.spanningTree(V, adj));
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**
  - \( O(E \log V) \), where \( E \) is the number of edges and \( V \) is the number of vertices.
  - This is because each edge is processed once, and the priority queue operations (insert and extract) take \( O(\log V) \).

- **Space Complexity:**
  - \( O(V + E) \), for the adjacency list and priority queue.

---

## How to Run the Code

### For C++

1. Save the code in a file (e.g., `prim_mst.cpp`).
2. Compile using:

   ```bash
   g++ -std=c++17 prim_mst.cpp -o prim_mst
   ```

3. Run using:

   ```bash
   ./prim_mst
   ```

### For Java

1. Save the code in a file (e.g., `PrimMST.java`).
2. Compile using:

   ```bash
   javac PrimMST.java
   ```

3. Run using:

   ```bash
   java PrimMST
   ```

---
