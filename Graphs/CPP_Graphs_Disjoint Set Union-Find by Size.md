# Disjoint Set Union-Find by Size

## Table of Contents

- [Disjoint Set Union-Find by Size](#disjoint-set-union-find-by-size)
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

The **Disjoint Set Union-Find by Size** is a data structure for managing disjoint sets, supporting two primary operations:

1. **Union by Size**: Merges two sets by attaching the smaller set to the larger one.
2. **Find with Path Compression**: Optimizes future queries by compressing the path from any node to the root.

---

## Problem Description

Given `N` elements and `Q` queries, implement:

1. `Union(a, b)` to merge the sets containing `a` and `b`.
2. `isConnected(a, b)` to check if `a` and `b` are in the same set.

---

### Examples

#### Example 1

**Input:**

```text
N = 5, Q = 4
Queries:
Union(1, 3)
isConnected(1, 2)
Union(2, 4)
isConnected(3, 4)
```

**Output:**

```text
0
1
```

**Explanation:**

- Initially, all elements are in separate sets.
- `Union(1, 3)` connects 1 and 3.
- `isConnected(1, 2)` returns `0` since 1 and 2 are not connected.
- `Union(2, 4)` connects 2 and 4.
- `isConnected(3, 4)` returns `1` since 3 and 4 are indirectly connected.

---

## Constraints

- \(1 \leq N \leq 10^5\)
- \(1 \leq Q \leq 10^5\)
- \(1 \leq \text{node1}, \text{node2} \leq N\)

---

## Approach

1. **Union by Size**: Track the size of each subset. Always attach the smaller subset to the larger subset to minimize tree height.
2. **Path Compression**: During the `find` operation, compress the path from the current node to its root for efficiency.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union-Find Class
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

// Driver Code
int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Number of elements
        cin >> n;

        DisjointSet ds(n);
        int q; // Number of queries
        cin >> q;

        while (q--) {
            char type;
            int a, b;
            cin >> type >> a >> b;

            if (type == 'U') {
                ds.unionBySize(a, b);
            } else {
                cout << (ds.findParent(a) == ds.findParent(b)) << endl;
            }
        }
        cout << "~" << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class DisjointSet {
    private int[] parent;
    private int[] sizeArr;

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
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt(); // Number of test cases

        while (t-- > 0) {
            int n = sc.nextInt(); // Number of elements
            DisjointSet ds = new DisjointSet(n);

            int q = sc.nextInt(); // Number of queries

            while (q-- > 0) {
                char type = sc.next().charAt(0);
                int a = sc.nextInt();
                int b = sc.nextInt();

                if (type == 'U') {
                    ds.unionBySize(a, b);
                } else {
                    System.out.println(ds.findParent(a) == ds.findParent(b) ? 1 : 0);
                }
            }
            System.out.println("~");
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - Each `find` and `union` operation runs in \(O(\alpha(N))\), where \(\alpha\) is the inverse Ackermann function (nearly constant).
  - Total complexity: \(O(N + Q \cdot \alpha(N))\).

- **Space Complexity**:
  - \(O(N)\) for `parent` and `sizeArr`.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `union_find_by_size.cpp`.
2. Compile:

   ```bash
   g++ -std=c++17 union_find_by_size.cpp -o union_find_by_size
   ```

3. Run:

   ```bash
   ./union_find_by_size
   ```

### For Java

1. Save the code in a file, e.g., `Main.java`.
2. Compile:

   ```bash
   javac Main.java
   ```

3. Run:

   ```bash
   java Main
   ```
