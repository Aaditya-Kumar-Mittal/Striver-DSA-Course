# 200. Number of Islands

## Table of Contents

- [200. Number of Islands](#200-number-of-islands)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
    - [Python Implementation](#python-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
    - [For Python](#for-python)
  - [Other Solutions](#other-solutions)
    - [C++ DFS Solution](#c-dfs-solution)

---

## Introduction

This problem deals with finding the number of islands in a 2D binary grid. An island is formed by connecting adjacent cells with value `'1'` (land) either horizontally or vertically. The grid boundaries are considered surrounded by water.

---

## Problem Description

### Task

Given a grid of dimensions \( m \times n \), count the number of islands. An island is a connected group of `'1'` cells surrounded by `'0'` (water). Only horizontal and vertical connections are allowed.

### Examples

#### Example 1

**Input:**  
`grid = [["1","1","1","1","0"], ["1","1","0","1","0"], ["1","1","0","0","0"], ["0","0","0","0","0"]]`  
**Output:**  
`1`

**Explanation:**  
All land cells are connected, forming one single island.

#### Example 2

**Input:**  
`grid = [["1","1","0","0","0"], ["1","1","0","0","0"], ["0","0","1","0","0"], ["0","0","0","1","1"]]`  
**Output:**  
`3`

**Explanation:**  
Three separate islands exist.

---

## Constraints

- \( 1 \leq m, n \leq 300 \)
- `grid[i][j]` is either `'0'` or `'1'`.

---

## Approach

1. **Traversal Method**: Use **BFS (Breadth-First Search)** to explore the grid, marking all cells belonging to an island as visited.
2. **Visited Array**: Maintain a `visited` array to ensure cells are processed only once.
3. **Island Counting**: Each BFS initiated from an unvisited `'1'` cell increments the island count.

### Steps

- Traverse the grid row by row and column by column.
- For each unvisited land cell (`'1'`), perform BFS to mark the entire connected component as visited.
- Increment the island count for each BFS call.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& visited, vector<vector<char>>& grid, int n, int m) {
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        // Directions for 4-connected neighbors
        int dRow[] = {-1, 0, 1, 0};
        int dCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int neighRow = row + dRow[k];
                int neighCol = col + dCol[k];

                if (neighRow >= 0 && neighRow < n && neighCol >= 0 &&
                    neighCol < m && grid[neighRow][neighCol] == '1' &&
                    !visited[neighRow][neighCol]) {
                    visited[neighRow][neighCol] = 1;
                    q.push({neighRow, neighCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid, n, m);
                }
            }
        }
        return count;
    }
};

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    Solution obj;
    cout << obj.numIslands(grid) << endl;
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void bfs(int i, int j, boolean[][] visited, char[][] grid, int n, int m) {
        visited[i][j] = true;
        Queue<int[]> queue = new LinkedList<>();
        queue.add(new int[]{i, j});

        int[] dRow = {-1, 0, 1, 0};
        int[] dCol = {0, 1, 0, -1};

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int row = cell[0];
            int col = cell[1];

            for (int k = 0; k < 4; k++) {
                int neighRow = row + dRow[k];
                int neighCol = col + dCol[k];

                if (neighRow >= 0 && neighRow < n && neighCol >= 0 &&
                    neighCol < m && grid[neighRow][neighCol] == '1' &&
                    !visited[neighRow][neighCol]) {
                    visited[neighRow][neighCol] = true;
                    queue.add(new int[]{neighRow, neighCol});
                }
            }
        }
    }

    public int numIslands(char[][] grid) {
        int n = grid.length;
        if (n == 0) return 0;
        int m = grid[0].length;

        boolean[][] visited = new boolean[n][m];
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid, n, m);
                }
            }
        }
        return count;
    }
}
```

---

### Python Implementation

```python
from collections import deque

class Solution:
    def numIslands(self, grid):
        def bfs(i, j):
            queue = deque([(i, j)])
            visited[i][j] = True

            while queue:
                row, col = queue.popleft()
                for dr, dc in directions:
                    neigh_row, neigh_col = row + dr, col + dc
                    if 0 <= neigh_row < n and 0 <= neigh_col < m and \
                            grid[neigh_row][neigh_col] == '1' and not visited[neigh_row][neigh_col]:
                        visited[neigh_row][neigh_col] = True
                        queue.append((neigh_row, neigh_col))

        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        count = 0

        for row in range(n):
            for col in range(m):
                if not visited[row][col] and grid[row][col] == '1':
                    count += 1
                    bfs(row, col)

        return count
```

---

## Complexity Analysis

- **Time Complexity**: \( O(n \times m) \)  
  Every cell is processed once.
- **Space Complexity**: \( O(n \times m) \)  
  For the `visited` array and BFS queue.

---

## How to Run the Code

### For C++

1. Save the code to `num_islands.cpp`.
2. Compile with `g++ num_islands.cpp -o num_islands`.
3. Run with `./num_islands`.

### For Java

1. Save the code to `Solution.java`.
2. Compile with `javac Solution.java`.
3. Run with `java Solution`.

### For Python

1. Save the code to `num_islands.py`.
2. Run with `python num_islands.py`.

## Other Solutions

### C++ DFS Solution

```cpp
/*
    https://leetcode.com/problems/number-of-islands/
    TC: O(V^2)
*/
class Solution {
public:
    void DFS(vector<vector<char>>& grid, int i, int j) {
        // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // return if current position is of water or is already visited
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '2';
        
        // do DFS in all 4 directions
        DFS(grid, i+1, j);
        DFS(grid, i, j-1);
        DFS(grid, i-1, j);
        DFS(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // We can treat the matrix grid as a grid. Each Island is a
        // connected component. The task is to find no. of disconnectedd components
        // in the graph.
        
        int islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == '1') {
                    DFS(grid, i, j);
                    ++islands;
                } 
            }
        }
        return islands;
    }
};
```
