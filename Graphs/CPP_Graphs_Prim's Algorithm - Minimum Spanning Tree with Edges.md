# Prim's Algorithm - Minimum Spanning Tree with Edges

## Table of Contents

- [Prim's Algorithm - Minimum Spanning Tree with Edges](#prims-algorithm---minimum-spanning-tree-with-edges)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
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

This version of Prim's algorithm computes the **total weight** of the Minimum Spanning Tree (MST) and provides the **edges included in the MST** along with their weights. It supports both C++ and Java implementations.

---

## Problem Description

You are given:

1. An integer `V` representing the number of vertices.
2. An integer `E` representing the number of edges.
3. An adjacency list `adj` where `adj[i]` contains a list of pairs `[vertex, weight]` denoting a connection from vertex `i` to another vertex with the specified weight.

The task is to:

1. Compute the total weight of the MST.
2. Return a list of edges included in the MST along with their weights.

---

### Examples

#### Example 1

**Input:**

```bash
V = 4, E = 4
Edges: [[0, 1, 10], [0, 2, 6], [0, 3, 5], [1, 3, 15], [2, 3, 4]]
```

**Output:**

```bash
MST Total Weight: 19
MST Edges:
0 - 3 : 5
3 - 2 : 4
0 - 1 : 10
```

**Explanation:**  
The MST includes edges `(0, 3)`, `(3, 2)`, and `(0, 1)` with weights `5`, `4`, and `10`, respectively. The total weight is `19`.

---

### Constraints

- \( 2 \leq V \leq 1000 \)
- \( V - 1 \leq E \leq \frac{V \cdot (V - 1)}{2} \)
- \( 1 \leq \text{weight of edges} \leq 1000 \)

The graph is connected and does not contain self-loops or multiple edges.

---

## Approach

Prim's algorithm is a **greedy algorithm** that starts with a single node and expands the MST by selecting the minimum-weight edge that connects a new vertex. This implementation uses:

1. A **priority queue** to fetch the minimum-weight edge efficiently.
2. A **visited array** to ensure no vertex is processed more than once.

Steps:

1. Start from any node (node `0` in this case).
2. Use a priority queue to store edges, prioritized by their weights.
3. Expand the MST by selecting the smallest edge that connects a new node.
4. Keep track of the total weight and the edges included in the MST.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the sum of weights of edges in the Minimum Spanning Tree.
    vector<pair<int, pair<int, int>>> spanningTree(int V, vector<vector<int>> adj[]) {
        // Priority queue to pick the edge with the minimum weight
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        // Visited array to track visited nodes
        vector<int> visited(V, 0);

        // Storing the MST edges and their total weight
        vector<pair<int, pair<int, int>>> mstEdges;
        int minSum = 0;

        // Push the starting node into the priority queue
        pq.push({0, {0, -1}}); // {weight, {node, parent}}

        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int node = it.second.first;
            int wt = it.first;
            int parent = it.second.second;

            // If the node is already visited, skip it
            if (visited[node]) continue;

            // Mark the node as visited
            visited[node] = 1;

            // If the parent exists, add the edge to the MST
            if (parent != -1) {
                mstEdges.push_back({wt, {parent, node}});
            }

            // Add the edge weight to the MST total weight
            minSum += wt;

            // Traverse the adjacent nodes
            for (auto itr : adj[node]) {
                int adjNode = itr[0];
                int edgeWt = itr[1];

                // If the adjacent node is not visited, add it to the priority queue
                if (!visited[adjNode]) {
                    pq.push({edgeWt, {adjNode, node}});
                }
            }
        }

        // Add the total weight as the first entry
        mstEdges.insert(mstEdges.begin(), {minSum, {-1, -1}});
        return mstEdges;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        vector<pair<int, pair<int, int>>> result = obj.spanningTree(V, adj);

        // Print the total weight of the MST
        cout << "MST Total Weight: " << result[0].first << "\n";

        // Print the edges in the MST
        cout << "MST Edges:\n";
        for (int i = 1; i < result.size(); i++) {
            cout << result[i].second.first << " - " << result[i].second.second
                 << " : " << result[i].first << "\n";
        }
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    static class Pair implements Comparable<Pair> {
        int node, weight, parent;

        Pair(int node, int weight, int parent) {
            this.node = node;
            this.weight = weight;
            this.parent = parent;
        }

        public int compareTo(Pair other) {
            return this.weight - other.weight;
        }
    }

    public List<int[]> spanningTree(int V, List<List<int[]>> adj) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        boolean[] visited = new boolean[V];
        List<int[]> mstEdges = new ArrayList<>();
        int minSum = 0;

        // Start with node 0
        pq.add(new Pair(0, 0, -1));

        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int node = current.node;
            int weight = current.weight;
            int parent = current.parent;

            // Skip if node is already visited
            if (visited[node]) continue;

            visited[node] = true;

            // Add to MST edges if not the starting node
            if (parent != -1) {
                mstEdges.add(new int[]{parent, node, weight});
            }

            minSum += weight;

            // Traverse adjacent nodes
            for (int[] neighbor : adj.get(node)) {
                int adjNode = neighbor[0];
                int edgeWeight = neighbor[1];
                if (!visited[adjNode]) {
                    pq.add(new Pair(adjNode, edgeWeight, node));
                }
            }
        }

        // Add the total weight as the first element
        mstEdges.add(0, new int[]{-1, -1, minSum});
        return mstEdges;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            List<List<int[]>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();
                adj.get(u).add(new int[]{v, w});
                adj.get(v).add(new int[]{u, w});
            }
            Solution sol = new Solution();
            List<int[]> result = sol.spanningTree(V, adj);

            System.out.println("MST Total Weight: " + result.get(0)[2]);
            System.out.println("MST Edges:");
            for (int i = 1; i < result.size(); i++) {
                System.out.println(result.get(i)[0] + " - " + result.get(i)[1] + " : " + result.get(i)[2]);
            }
        }
    }
}
```

---

## Complexity Analysis

- **Time Complexity:** \( O((V + E) \cdot \log V) \), where \( V \) is the number of vertices and \( E \) is the number of edges.
- **Space Complexity:** \( O(V + E) \), for storing the adjacency list and the priority queue.

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile using `g++ -std=c++17 filename.cpp`.
3. Run the compiled program using `./a.out`.

### For Java

1. Save the code in a `.java` file.
2. Compile using `javac filename.java`.
3. Run using `java filename`.

---
