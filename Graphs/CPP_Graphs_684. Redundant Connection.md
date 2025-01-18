# Redundant Connection

## Table of Contents

- [Redundant Connection](#redundant-connection)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The "Redundant Connection" problem involves identifying and removing a single redundant edge from a graph such that the resulting structure becomes a tree. A tree is defined as an undirected graph that is connected and contains no cycles.

## Problem Description

Given a graph represented as an array `edges` where `edges[i] = [ai, bi]` indicates an edge between nodes `ai` and `bi`, the task is to return the redundant edge that can be removed to make the graph a tree.

### Examples

#### Example 1

**Input:**

```bash
edges = [[1, 2], [1, 3], [2, 3]]
```

**Output:**

```bash
[2, 3]
```

**Explanation:** Removing edge `[2, 3]` ensures the graph remains a tree.

#### Example 2

**Input:**

```bash
edges = [[1, 2], [2, 3], [3, 4], [1, 4], [1, 5]]
```

**Output:**

```bash
[1, 4]
```

**Explanation:** Removing edge `[1, 4]` ensures the graph remains a tree.

### Constraints

- \( n = \text{edges.length} \)
- \( 3 \leq n \leq 1000 \)
- \( \text{edges}[i].length = 2 \)
- \( 1 \leq a_i < b_i \leq n \)
- The given graph is connected and contains exactly one cycle.

## Approach

1. **Disjoint Set Union (DSU):**
   - Use the DSU data structure to track connected components in the graph efficiently.
   - Implement path compression to optimize the `find` operation.
   - Use union by size to balance the tree structure when merging sets.

2. **Detect Cycles:**
   - For each edge in the input, check if both nodes belong to the same component using the `findParent` function.
   - If they do, the edge forms a cycle and is redundant.
   - Otherwise, merge the components using the `unionBySize` function.

3. **Return the Redundant Edge:**
   - Return the first edge that causes a cycle.

## Code

### C++ Implementation

```cpp
#include <vector>
using namespace std;

// Disjoint Set Class
class DisjointSet {
public:
    vector<int> parent, sizeArr;

    // Constructor to initialize parent and size arrays
    DisjointSet(int n) {
        parent.resize(n + 1);
        sizeArr.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union function by size
    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV)
            return;

        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
};

// Solution class
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If u and v are already connected, return the edge
            if (ds.findParent(u) == ds.findParent(v)) {
                return {u, v};
            } else {
                ds.unionBySize(u, v);
            }
        }

        // If no redundant connection is found (shouldn't happen for the problem definition)
        return {};
    }
};
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        DisjointSet ds = new DisjointSet(n);

        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            // If u and v are already connected, return the edge
            if (ds.findParent(u) == ds.findParent(v)) {
                return new int[]{u, v};
            } else {
                ds.unionBySize(u, v);
            }
        }

        // If no redundant connection is found (shouldn't happen for the problem definition)
        return new int[]{};
    }
}

class DisjointSet {
    private int[] parent, sizeArr;

    // Constructor to initialize parent and size arrays
    public DisjointSet(int n) {
        parent = new int[n + 1];
        sizeArr = new int[n + 1];
        Arrays.fill(sizeArr, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    public int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    // Union function by size
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
```

## Complexity Analysis

- **Time Complexity:**  
  - Each `findParent` and `unionBySize` operation is nearly \( O(1) \) due to path compression and union by size.  
  - For \( E \) edges, the total time complexity is \( O(E \cdot \alpha(V)) \), where \( \alpha(V) \) is the inverse Ackermann function (very small for practical inputs).

- **Space Complexity:**  
  - \( O(V) \) for storing the `parent` and `sizeArr` arrays.

## How to Run the Code

### For C++

1. **Compile the Code:**  
   Use a C++ compiler like g++:

   ```bash
   g++ -std=c++17 -o solution solution.cpp
   ```

2. **Run the Executable:**

   ```bash
   ./solution
   ```

3. **Input Format:**  
   - Provide the edges of the graph as a 2D vector.  
   - Call the `findRedundantConnection` method with the input vector.

4. **Output:**  
   - The output will be the redundant edge that can be removed to make the graph a tree.

### For Java

1. **Compile the Code:**  
   Use the `javac` compiler:

   ```bash
   javac Solution.java
   ```

2. **Run the Program:**

   ```bash
   java Solution
   ```

3. **Input Format:**  
   - Provide the edges of the graph as a 2D array.  
   - Call the `findRedundantConnection` method with the input array.

4. **Output:**  
   - The output will be the redundant edge that can be removed to make the graph a tree.
