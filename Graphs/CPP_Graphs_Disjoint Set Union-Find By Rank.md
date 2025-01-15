# Union-Find

## Table of Contents

- [Union-Find](#union-find)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Techniques](#key-techniques)
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

The Union-Find data structure, also known as Disjoint Set Union (DSU), is an efficient algorithm used to manage dynamic connectivity problems. It supports two fundamental operations:

1. **Union**: Merges two subsets into a single subset.
2. **Find**: Determines which subset a particular element belongs to, with optimizations for efficiency like **path compression** and **union by rank**.

---

## Problem Description

Given `N` nodes and `Q` queries, implement two operations:

1. `Union(a, b)`: Merge the sets containing elements `a` and `b`.
2. `isConnected(a, b)`: Check if elements `a` and `b` are in the same subset.

### Examples

#### Example 1

**Input:**

```text
N = 5, Q = 4
Queries: 
Union(1,3) 
isConnected(1,2) 
Union(1,5) 
isConnected(3,5)
```

**Output:**

```text
0
1
```

**Explanation:**

- Initially, all nodes are isolated.
- After `Union(1, 3)`, nodes 1 and 3 are connected.
- `isConnected(1, 2)` returns 0 since 1 and 2 are not connected.
- After `Union(1, 5)`, nodes 1 and 5 are connected.
- `isConnected(3, 5)` returns 1 since node 1 connects both 3 and 5.

#### Example 2

**Input:**

```text
N = 5, Q = 4
Queries: 
Union(1,4) 
Union(1,5) 
isConnected(2,3) 
Union(3,4)
```

**Output:**

```text
0
```

---

### Constraints

- \(1 \leq N \leq 10^5\)
- \(1 \leq Q \leq 10^5\)
- \(1 \leq \text{node1}, \text{node2} \leq N\)

---

## Approach

### Key Techniques

1. **Path Compression**: Optimizes the `find` operation by pointing nodes directly to their ultimate parent, reducing tree height.
2. **Union by Rank**: Ensures smaller trees are attached under larger ones, maintaining balance and efficiency.

### Steps

1. Initialize `parent` and `rank` arrays:
   - `parent[i] = i` (each node is its own parent initially).
   - `rank[i] = 1` (rank starts at 1).
2. Process queries:
   - Use `find` with path compression to identify subsets.
   - Use `union` with rank optimization to merge subsets.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union-Find Class
class DisjointSet {
public:
    vector<int> rank, parent;

    // Constructor to initialize rank and parent arrays
    DisjointSet(int n) {
        rank.resize(n + 1, 0);  // Rank array initialized to 0
        parent.resize(n + 1);   // Parent array to track components

        for (int i = 0; i <= n; i++) {
            parent[i] = i;      // Initially, each node is its own parent
        }
    }

    // Find function with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        // Path compression: point the node directly to its ultimate parent
        return parent[node] = findParent(parent[node]);
    }

    // Union function by rank
    void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        // If they are already in the same set, do nothing
        if (rootU == rootV) return;

        // Union by rank
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
};

int main() {
    int t; // Number of test cases
    cin >> t;
    while (t--) {
        int n; // Number of nodes
        cin >> n;

        DisjointSet ds(n);

        int q; // Number of queries
        cin >> q;

        while (q--) {
            char type; // 'U' for union, 'Q' for query
            int a, b;
            cin >> type >> a >> b;

            if (type == 'U') {
                ds.unionByRank(a, b);
            } else {
                cout << (ds.findParent(a) == ds.findParent(b)) << endl;
            }
        }
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class DisjointSet {
    int[] parent, rank;

    // Constructor to initialize parent and rank arrays
    public DisjointSet(int n) {
        parent = new int[n + 1];
        rank = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Find function with path compression
    public int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union function by rank
    public void unionByRank(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV) return;

        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootV] < rank[rootU]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }

    // Check if two nodes are connected
    public boolean isConnected(int x, int y) {
        return findParent(x) == findParent(y);
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt(); // Number of test cases
        while (t-- > 0) {
            int n = sc.nextInt(); // Number of nodes
            DisjointSet ds = new DisjointSet(n);

            int q = sc.nextInt(); // Number of queries
            while (q-- > 0) {
                char type = sc.next().charAt(0);
                int a = sc.nextInt();
                int b = sc.nextInt();

                if (type == 'U') {
                    ds.unionByRank(a, b);
                } else {
                    System.out.println(ds.isConnected(a, b) ? 1 : 0);
                }
            }
        }

        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - Each `find` and `union` operation runs in \(O(\alpha(N))\), where \(\alpha\) is the inverse Ackermann function.
  - Total complexity: \(O(N + Q \cdot \alpha(N))\), approximately \(O(N + Q)\).

- **Space Complexity**:
  - \(O(N)\) for `rank` and `parent` arrays.

---

## How to Run the Code

### For C++

1. Compile using:

   ```bash
   g++ -std=c++17 union_find.cpp -o union_find
   ```

2. Run using:

   ```bash
   ./union_find
   ```

### For Java

1. Compile using:

   ```bash
   javac Solution.java
   ```

2. Run using:

   ```bash
   java Solution
   ```
