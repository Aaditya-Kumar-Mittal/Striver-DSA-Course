# Number of Enclaves

## Table of Contents

- [Number of Enclaves](#number-of-enclaves)
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
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [CPP DFS](#cpp-dfs)

---

## Introduction

This problem requires us to determine the number of land cells (`1`s) in a grid that cannot reach the boundary. A cell can "reach the boundary" if it is either directly on the boundary or is connected to a boundary cell through adjacent `1`s. The task involves traversing the grid and identifying such enclosed cells.

---

## Problem Description

Given an \( m \times n \) binary matrix `grid`, where:

- `0` represents a sea cell,
- `1` represents a land cell,

return the count of land cells (`1`s) that are completely enclosed by sea cells (`0`s) and cannot reach the boundary.

---

## Examples

### Example 1

**Input:**  
`grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]`

**Output:**  
`3`

**Explanation:**  
There are three `1`s that are enclosed by `0`s. The `1` on the boundary is not enclosed.

---

### Example 2

**Input:**  
`grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]`

**Output:**  
`0`

**Explanation:**  
All `1`s are either on the boundary or connected to the boundary.

---

## Constraints

- \( 1 \leq m, n \leq 500 \)
- `grid[i][j]` is either `0` or `1`.

---

## Approach

1. **Identify Boundary-Connected Cells:**
   - Start from all boundary cells. If a boundary cell is `1`, mark it as visited and traverse its connected neighbors using BFS/DFS.
2. **Count Enclosed Cells:**
   - After marking all reachable `1`s starting from the boundary, count the remaining `1`s in the grid that are not marked as visited.

### Steps

1. Initialize a `visited` matrix to keep track of visited cells.
2. Iterate over all boundary cells:
   - If a boundary cell is `1` and unvisited, perform BFS/DFS to mark all connected land cells.
3. Traverse the entire grid:
   - Count the number of `1`s that are not visited.
4. Return the count.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Add all boundary cells with value 1 to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        vis[i][j] = 1;
                    }
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS to mark all reachable land cells from the boundary
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && 
                    !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                    q.push({nRow, nCol});
                    vis[nRow][nCol] = 1;
                }
            }
        }

        // Count land cells that are not visited
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] == 0)
                    count++;
            }
        }

        return count;
    }
};

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    Solution solution;
    cout << solution.numEnclaves(grid) << endl;

    return 0;
}
```

---

## Complexity Analysis

### Time Complexity

- **Boundary Traversal:** \( O(n \times m) \) (each cell is visited at most once).
- **BFS Traversal:** \( O(n \times m) \) (worst case where all cells are `1`).

**Overall:** \( O(n \times m) \).

- Runtime: O(n * m), where n and m are the dimensions of the grid.
- Memory: O(n * m). DFS can enumerate all elements in the worst case, and we need to store each element on the stack for the recursion.

### Space Complexity

- **Visited Array:** \( O(n \times m) \).
- **Queue (for BFS):** \( O(n \times m) \) (in the worst case).

**Overall:** \( O(n \times m) \).

---

## How to Run the Code

1. Copy the code into a file named `main.cpp`.
2. Compile using `g++ main.cpp -o main`.
3. Run with `./main`.

---

## Other Solutions

### CPP DFS

```cpp
class Solution {
    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    // DFS to explore all land connected to the borders
    void dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& visited, int m, int n) {
        // Mark as visited
        visited[r][c] = 1;
        
        // Explore all 4 directions
        for (auto dir : direction) {
            int newr = r + dir[0];
            int newc = c + dir[1];

            // Ensure we're within bounds and visiting unvisited land (1)
            if (newr >= 0 && newr < m && newc >= 0 && newc < n && !visited[newr][newc] && grid[newr][newc] == 1) {
                dfs(newr, newc, grid, visited, m, n);
            }
        }
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Create a visited grid initialized to false
        vector<vector<int>> visited(m, vector<int>(n, 0));

        // Start DFS from the borders (first and last rows, first and last columns)
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 1 && !visited[i][0]) dfs(i, 0, grid, visited, m, n); // Left border
            if (grid[i][n-1] == 1 && !visited[i][n-1]) dfs(i, n-1, grid, visited, m, n); // Right border
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 1 && !visited[0][j]) dfs(0, j, grid, visited, m, n); // Top border
            if (grid[m-1][j] == 1 && !visited[m-1][j]) dfs(m-1, j, grid, visited, m, n); // Bottom border
        }

        // Now count the remaining land cells (1s) that are not connected to the border
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    count++;
                }
            }
        }
        return count;
    }
};
```
