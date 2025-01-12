# Replace O's with X's

## Table of Contents

- [Replace O's with X's](#replace-os-with-xs)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
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

The goal is to replace all 'O's in a matrix that are fully surrounded by 'X's. A 'O' is considered surrounded if all its directly adjacent cells (up, down, left, right) are 'X'. This is a classic DFS/BFS problem involving boundary traversal.

---

## Problem Description

Given a matrix `mat` of dimensions \( n \times m \), replace all 'O's that are surrounded by 'X's with 'X'. If an 'O' is connected to the boundary of the matrix, it cannot be surrounded and should remain unchanged.

---

## Examples

### Example 1

**Input:**  
`mat = [['X', 'X', 'X'], ['X', 'O', 'X'], ['X', 'X', 'X']]`

**Output:**  
`[['X', 'X', 'X'], ['X', 'X', 'X'], ['X', 'X', 'X']]`

**Explanation:**  
The 'O' is surrounded by 'X' on all sides.

---

### Example 2

**Input:**  
`mat = [['X', 'O', 'X'], ['X', 'O', 'X'], ['X', 'X', 'X']]`

**Output:**  
`[['X', 'O', 'X'], ['X', 'O', 'X'], ['X', 'X', 'X']]`

**Explanation:**  
The 'O's are connected to the boundary and are not surrounded.

---

### Example 3

**Input:**  
`mat = [['X', 'X', 'X', 'X'], ['X', 'O', 'X', 'X'], ['X', 'O', 'O', 'X'], ['X', 'O', 'X', 'X'], ['X', 'X', 'O', 'O']]`

**Output:**  
`[['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'X', 'X'], ['X', 'X', 'O', 'O']]`

**Explanation:**  
The 'O's in the middle are surrounded by 'X's and are replaced. Boundary 'O's remain unchanged.

---

## Constraints

- \( 1 \leq n, m \leq 1000 \)
- The matrix contains only characters `'X'` and `'O'`.

---

## Approach

### Steps

1. **Mark Boundary-Connected 'O's:**
   - Use DFS/BFS starting from all boundary cells.
   - Mark all reachable 'O's as visited or as a special character (e.g., `'*'`) to indicate they shouldn't be replaced.
2. **Replace Remaining 'O's:**
   - Traverse the matrix. Replace any unvisited 'O' with 'X'.
3. **Restore Boundary-Connected 'O's:**
   - Convert all marked cells (`'*'`) back to 'O'.

This ensures that only surrounded 'O's are replaced.

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

    void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& vis, int n, int m) {
        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 'O') {
                dfs(nRow, nCol, mat, vis, n, m);
            }
        }
    }

public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Mark all boundary-connected 'O's
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') dfs(0, j, mat, vis, n, m);
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') dfs(n - 1, j, mat, vis, n, m);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, mat, vis, n, m);
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') dfs(i, m - 1, mat, vis, n, m);
        }

        // Replace surrounded 'O's with 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '.'));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];

        Solution ob;
        vector<vector<char>> ans = ob.fill(mat);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~\n";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private int[] delRow = {-1, 0, 1, 0};
    private int[] delCol = {0, 1, 0, -1};

    private void dfs(int row, int col, char[][] mat, boolean[][] vis, int n, int m) {
        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !vis[nRow][nCol] && mat[nRow][nCol] == 'O') {
                dfs(nRow, nCol, mat, vis, n, m);
            }
        }
    }

    public char[][] fill(char[][] mat) {
        int n = mat.length;
        int m = mat[0].length;

        boolean[][] vis = new boolean[n][m];

        // Mark all boundary-connected 'O's
        for (int j = 0; j < m; j++) {
            if (!vis[0][j] && mat[0][j] == 'O') dfs(0, j, mat, vis, n, m);
            if (!vis[n - 1][j] && mat[n - 1][j] == 'O') dfs(n - 1, j, mat, vis, n, m);
        }

        for (int i = 0; i < n; i++) {
            if (!vis[i][0] && mat[i][0] == 'O') dfs(i, 0, mat, vis, n, m);
            if (!vis[i][m - 1] && mat[i][m - 1] == 'O') dfs(i, m - 1, mat, vis, n, m);
        }

        // Replace surrounded 'O's with 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                }
            }
        }

        return mat;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Boundary Traversal:** \( O(n + m) \).
- **DFS Traversal:** \( O(n \times m) \).

**Overall:** \( O(n \

times m) \).

### Space Complexity

- **Visited Array:** \( O(n \times m) \).
- **DFS Stack:** \( O(n \times m) \) (worst case).

**Overall:** \( O(n \times m) \).

---

## How to Run the Code

### For C++

1. Copy the code into a file named `main.cpp`.
2. Compile using `g++ main.cpp -o main`.
3. Run with `./main`.

### For Java

1. Copy the code into a file named `Solution.java`.
2. Compile using `javac Solution.java`.
3. Run with `java Solution`.

---
