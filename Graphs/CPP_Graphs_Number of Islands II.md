# Number of Islands II

## Table of Contents

- [Number of Islands II](#number-of-islands-ii)
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
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)

---

## Introduction

The **Number of Islands** problem involves determining the number of distinct islands in a grid after a series of operations. Each operation toggles a cell in the grid from water (`0`) to land (`1`). Islands are defined as groups of adjacent lands connected vertically or horizontally. The goal is to return the number of islands after each operation.

---

## Problem Description

Given:

1. A grid of size `n x m`, initially filled with water (`0`).
2. A list of `k` operations, where each operation toggles a cell `(row, col)` to land (`1`).

Return an array of size `k`, where each element represents the number of islands after the corresponding operation.

---

### Examples

#### Example 1

**Input:**

```bash
n = 4, m = 5, k = 4
A = {{1, 1}, {0, 1}, {3, 3}, {3, 4}}
```

**Output:**

```bash
1 1 2 2
```

**Explanation:**

1. Operation 1: Toggle (1,1). Grid becomes:

    ```bash
    00000
    01000
    00000
    00000
    ```

    Islands = 1.

2. Operation 2: Toggle (0,1). Grid becomes:

    ```bash
    01000
    01000
    00000
    00000
    ```

    Islands = 1.

3. Operation 3: Toggle (3,3). Grid becomes:

    ```bash
    01000
    01000
    00000
    00010
    ```

    Islands = 2.

4. Operation 4: Toggle (3,4). Grid becomes:

    ```bash
    01000
    01000
    00000
    00011
    ```

    Islands = 2.

---

#### Example 2

**Input:**

```bash
n = 4, m = 5, k = 4
A = {{0, 0}, {1, 1}, {2, 2}, {3, 3}}
```

**Output:**

```bash
1 2 3 4
```

**Explanation:**

1. Operation 1: Toggle (0,0). Islands = 1.
2. Operation 2: Toggle (1,1). Islands = 2.
3. Operation 3: Toggle (2,2). Islands = 3.
4. Operation 4: Toggle (3,3). Islands = 4.

---

### Constraints

- \( 1 \leq n, m \leq 1000 \)
- \( 1 \leq k \leq 1000 \)

---

## Approach

1. **Grid Initialization:**
   - Start with an `n x m` grid filled with `0` (water).
   - Each operation toggles a specific cell `(row, col)` to `1` (land).

2. **Union-Find Data Structure (Disjoint Set Union - DSU):**
   - Use DSU to track connected components (islands).
   - Implement path compression for efficient `find` operations.
   - Use union-by-size to balance the structure during `union` operations.

3. **Island Formation:**
   - For each operation:
     - If the cell is already land, skip the operation.
     - Otherwise:
       - Mark the cell as land.
       - Check its four neighbors (up, down, left, right).
       - If a neighbor is also land, connect them using DSU.
     - Update the island count.

4. **Result Storage:**
   - After processing each operation, store the current island count in the result array.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, sizeArr;

    DisjointSet(int n) {
        parent.resize(n + 1);
        sizeArr.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

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

class Solution {
public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> ans;
        int count = 0;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (auto &it : operators) {
            int row = it[0], col = it[1];

            if (visited[row][col]) {
                ans.push_back(count);
                continue;
            }

            visited[row][col] = 1;
            count++;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol]) {
                    int nodeNum = row * m + col;
                    int adjNum = nRow * m + nCol;

                    if (ds.findParent(nodeNum) != ds.findParent(adjNum)) {
                        count--;
                        ds.unionBySize(nodeNum, adjNum);
                    }
                }
            }

            ans.push_back(count);
        }

        return ans;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class DisjointSet {
    private int[] parent, sizeArr;

    public DisjointSet(int n) {
        parent = new int[n + 1];
        sizeArr = new int[n + 1];
        Arrays.fill(sizeArr, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    public int findParent(int node) {
        if (node == parent[node]) {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

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
    public List<Integer> numOfIslands(int n, int m, List<int[]> operators) {
        DisjointSet ds = new DisjointSet(n * m);
        int[][] visited = new int[n][m];
        List<Integer> ans = new ArrayList<>();
        int count = 0;

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        for (int[] op : operators) {
            int row = op[0], col = op[1];

            if (visited[row][col] == 1) {
                ans.add(count);
                continue;
            }

            visited[row][col] = 1;
            count++;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] == 1) {
                    int nodeNum = row * m + col;
                    int adjNum = nRow * m + nCol;

                    if (ds.findParent(nodeNum) != ds.findParent(adjNum)) {
                        count--;
                        ds.unionBySize

(nodeNum, adjNum);
                    }
                }
            }

            ans.add(count);
        }

        return ans;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DSU Operations:** \(O(\alpha(n \cdot m))\), where \(\alpha\) is the inverse Ackermann function.
- **Total:** \(O(k \cdot 4 \cdot \alpha(n \cdot m)) \approx O(k)\).

### Space Complexity

- \(O(n \cdot m)\) for DSU and visited array.

---

## How to Run the Code

1. **C++:**
   - Compile using `g++ -std=c++17 filename.cpp`.
   - Run the executable with appropriate input.

2. **Java:**
   - Compile using `javac Solution.java`.
   - Run the program with appropriate input.

---
