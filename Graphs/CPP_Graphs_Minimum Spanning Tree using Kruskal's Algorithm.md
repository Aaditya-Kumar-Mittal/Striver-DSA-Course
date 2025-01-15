# Minimum Spanning Tree using Kruskal's Algorithm

## Table of Contents

- [Minimum Spanning Tree using Kruskal's Algorithm](#minimum-spanning-tree-using-kruskals-algorithm)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The Minimum Spanning Tree (MST) of a graph is a subset of edges that connects all the vertices together, without cycles, and with the minimum possible total edge weight. **Kruskal's Algorithm** is a greedy algorithm to find the MST by sorting edges and progressively adding them to the tree, ensuring no cycles are formed.

---

## Problem Description

Given:

- A weighted, undirected, and connected graph with \(V\) vertices and \(E\) edges.

Task:

- Find the **sum of the weights** of the edges in the Minimum Spanning Tree.

Input format:

- \(V\): Number of vertices.
- \(E\): Number of edges.
- Each edge is defined as \(u, v, w\), where \(u\) and \(v\) are vertices connected by the edge and \(w\) is the weight.

Output:

- The sum of the weights of the edges in the MST.

---

### Examples

#### Example 1

**Input:**

```text
V = 3, E = 3
Edges:
0 1 5
1 2 3
0 2 1
```

**Output:**

```text
4
```

**Explanation:**

- The edges included in the MST are:
  - (0, 2) with weight 1
  - (1, 2) with weight 3
- Total weight: \(1 + 3 = 4\).

#### Example 2

**Input:**

```text
V = 2, E = 1
Edges:
0 1 5
```

**Output:**

```text
5
```

**Explanation:**

- Only one edge is available, forming the MST with weight 5.

---

### Constraints

- \(2 \leq V \leq 1000\)
- \(V-1 \leq E \leq \frac{V \times (V-1)}{2}\)
- \(1 \leq w \leq 1000\)

---

## Approach

### Steps

1. **Extract and Sort Edges**:
   - Gather all edges with their weights.
   - Sort them in ascending order of weight.

2. **Disjoint Set Union (DSU)**:
   - Use DSU to check whether two vertices belong to the same component. If not, union them.

3. **Greedy Edge Selection**:
   - Traverse the sorted edge list. Add edges to the MST if they connect disjoint components.

4. **Return Total Weight**:
   - Sum the weights of all selected edges in the MST.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union class
class DisjointSet {
public:
    vector<int> parent, sizeArr;

    // Constructor
    DisjointSet(int n) {
        parent.resize(n + 1);
        sizeArr.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union by size
    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return;

        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
};

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<pair<int, pair<int, int>>> edges;

        // Collect all edges
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                int node = i;
                int adjNode = it[0];
                int wt = it[1];
                edges.push_back({wt, {node, adjNode}});
            }
        }

        // Sort edges by weight
        sort(edges.begin(), edges.end());

        // Initialize DSU and MST weight
        DisjointSet ds(V);
        int MST_WEIGHT = 0;

        // Process edges
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findParent(u) != ds.findParent(v)) {
                MST_WEIGHT += wt;
                ds.unionBySize(u, v);
            }
        }

        return MST_WEIGHT;
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

class DisjointSet {
    private int[] parent, sizeArr;

    // Constructor
    public DisjointSet(int n) {
        parent = new int[n + 1];
        sizeArr = new int[n + 1];
        Arrays.fill(sizeArr, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find with path compression
    public int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union by size
    public void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV) return;

        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
}

class Solution {
    public int spanningTree(int V, ArrayList<int[]>[] adj) {
        ArrayList<int[]> edges = new ArrayList<>();

        // Collect edges
        for (int i = 0; i < V; i++) {
            for (int[] edge : adj[i]) {
                edges.add(new int[] { edge[1], i, edge[0] });
            }
        }

        // Sort edges by weight
        edges.sort(Comparator.comparingInt(a -> a[0]));

        // Initialize DSU and MST weight
        DisjointSet ds = new DisjointSet(V);
        int MST_WEIGHT = 0;

        // Process edges
        for (int[] edge : edges) {
            int wt = edge[0], u = edge[1], v = edge[2];

            if (ds.findParent(u) != ds.findParent(v)) {
                MST_WEIGHT += wt;
                ds.unionBySize(u, v);
            }
        }

        return MST_WEIGHT;
    }
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - Edge sorting: \(O(E \log E)\)
  - DSU operations: \(O(E \cdot \alpha(V))\), where \(\alpha\) is the inverse Ackermann function.
  - Total: \(O(E \log E + E \cdot \alpha(V))\).

- **Space Complexity**:
  - \(O(V + E)\) for edges and DSU.

---

## How to Run the Code

### For C++

1. Save the code in `kruskals_mst.cpp`.
2. Compile:

   ```bash
   g++ -std=c++17 kruskals_mst.cpp -o kruskals_mst
   ```

3. Run:

   ```bash
   ./kruskals_mst
   ```

### For Java

1. Save the code in `Solution.java`.
2. Compile:

   ```bash
   javac Solution.java
   ```

3. Run:

   ```bash
   java Solution
   ```
