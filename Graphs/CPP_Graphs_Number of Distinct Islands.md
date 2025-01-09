# Number of Distinct Islands

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Number of Distinct Islands](#number-of-distinct-islands)
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

This problem requires finding the number of **distinct islands** in a 2D binary matrix, where an island is defined as a group of connected `1`s. Two islands are considered distinct if their shapes are different, meaning they cannot be obtained by rotating or reflecting one another.

---

## Problem Description

Given a boolean 2D matrix `grid` of size \(n \times m\), where:

- `0` represents water.
- `1` represents land.

The task is to count the number of **distinct islands** in the matrix.

---

## Examples

### Example 1

**Input:**  

```text
grid = [[1, 1, 0, 0, 0],
        [1, 1, 0, 0, 0],
        [0, 0, 0, 1, 1],
        [0, 0, 0, 1, 1]]
```

**Output:**  
`1`

**Explanation:**  
There are two islands in the grid, but they have the same shape.

---

### Example 2

**Input:**  

```text
grid = [[1, 1, 0, 1, 1],
        [1, 0, 0, 0, 0],
        [0, 0, 0, 0, 1],
        [1, 1, 0, 1, 1]]
```

**Output:**  
`3`

**Explanation:**  
There are four islands in the grid, but two of them have the same shape.

---

## Constraints

- \(1 \leq n, m \leq 500\)
- \(grid[i][j] \in \{0, 1\}\)

---

## Approach

### Steps

1. Use a Depth First Search (DFS) approach to traverse the grid and identify all connected components of `1`s.
2. Record the **relative shape** of each island by storing the coordinates of all cells relative to the starting point of the DFS.
3. Use a `set` to store unique shapes of islands. This ensures that duplicate islands are counted only once.
4. Return the size of the `set` as the number of distinct islands.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,
             vector<pair<int, int>>& vec, int rowBase, int colBase) {
        vis[row][col] = 1;
        vec.push_back({row - rowBase, col - colBase}); // Relative position

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if (nRow >= 0 && nRow < grid.size() && nCol >= 0 && nCol < grid[0].size() &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, grid, vis, vec, rowBase, colBase);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, vis, vec, i, j);
                    st.insert(vec);
                }
            }
        }

        return st.size();
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int row, int col, int[][] grid, boolean[][] vis,
                     List<int[]> shape, int rowBase, int colBase) {
        vis[row][col] = true;
        shape.add(new int[] {row - rowBase, col - colBase});

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < grid.length && nCol >= 0 && nCol < grid[0].length &&
                !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, grid, vis, shape, rowBase, colBase);
            }
        }
    }

    public int countDistinctIslands(int[][] grid) {
        int n = grid.length, m = grid[0].length;
        boolean[][] vis = new boolean[n][m];
        Set<List<int[]>> distinctShapes = new HashSet<>();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    List<int[]> shape = new ArrayList<>();
                    dfs(i, j, grid, vis, shape, i, j);
                    distinctShapes.add(shape);
                }
            }
        }

        return distinctShapes.size();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS Traversal:** Each cell is visited at most once.  
  \(O(n \times m)\)
- **Set Operations:** Inserting the relative shapes of islands into the set depends on the size of the islands but is generally \(O(n \times m)\) in the worst case.

**Overall:** \(O(n \times m)\)

### Space Complexity

- **Visited Matrix:** \(O(n \times m)\)
- **Storage for Island Shapes:** \(O(n \times m)\)

**Overall:** \(O(n \times m)\)

---

## How to Run the Code

### For C++

1. Compile the program using a C++ compiler:

   ```bash
   g++ -o solution solution.cpp
   ```

2. Run the executable:

   ```bash
   ./solution
   ```

### For Java

1. Compile the program using a Java compiler:

   ```bash
   javac Solution.java
   ```

2. Run the program:

   ```bash
   java Solution
   ```
