# Rotting Oranges

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Rotting Oranges](#rotting-oranges)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Statement](#problem-statement)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Algorithm](#algorithm)
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
  - [Other Solutions](#other-solutions)
    - [Python Solution](#python-solution)

---

## Introduction

The **Rotting Oranges** problem is a grid-based simulation problem where fresh oranges turn rotten if they are 4-directionally adjacent to a rotten orange. The goal is to determine the minimum time required for all fresh oranges to rot or identify if it is impossible.

---

## Problem Statement

You are given an \( m \times n \) grid where each cell can have one of three values:

- `0`: An empty cell.
- `1`: A fresh orange.
- `2`: A rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten. Return the minimum number of minutes that must elapse until no cell has a fresh orange. If it is impossible for all fresh oranges to rot, return `-1`.

---

## Examples

### Example 1

**Input:**  
`grid = [[2,1,1],[1,1,0],[0,1,1]]`  

**Output:**  
`4`  

**Explanation:**  

- At minute 1: Oranges at positions `(0,1)` and `(1,0)` rot.
- At minute 2: Oranges at positions `(0,2)` and `(1,1)` rot.
- At minute 3: Orange at position `(2,1)` rots.
- At minute 4: Orange at position `(2,2)` rots.

---

### Example 2

**Input:**  
`grid = [[2,1,1],[0,1,1],[1,0,1]]`  

**Output:**  
`-1`  

**Explanation:**  
The orange at position `(2,0)` is unreachable and will never rot.

---

### Example 3

**Input:**  
`grid = [[0,2]]`  

**Output:**  
`0`  

**Explanation:**  
There are no fresh oranges to begin with, so the output is `0`.

---

## Constraints

- \( 1 \leq m, n \leq 10 \)
- \( \text{grid}[i][j] \) is `0`, `1`, or `2`.

---

## Algorithm

### Steps

1. Initialize a queue to perform Breadth-First Search (BFS) for the rotten oranges.
2. Traverse the grid:
   - Add all rotten oranges (`2`) to the queue with their initial positions and time `0`.
   - Count the number of fresh oranges (`1`).
3. Perform BFS:
   - For each rotten orange, spread the rot to adjacent fresh oranges if possible, updating the time and marking them as visited.
4. Check if any fresh oranges remain:
   - If no fresh oranges are left, return the time taken for all to rot.
   - If some fresh oranges remain unreachable, return `-1`.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q; // {{row, col}, time}
        int freshCount = 0;

        // Initialize queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int time = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                    q.push({{nrow, ncol}, t + 1});
                    vis[nrow][ncol] = 1;
                    freshCount--;
                }
            }
        }

        return freshCount == 0 ? time : -1;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int orangesRotting(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> queue = new LinkedList<>();
        int freshCount = 0;

        // Initialize queue with all rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    queue.add(new int[] {i, j, 0});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int time = 0;
        int[] drow = {-1, 0, 1, 0};
        int[] dcol = {0, 1, 0, -1};

        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int r = cell[0];
            int c = cell[1];
            int t = cell[2];
            time = Math.max(time, t);

            for (int i = 0; i < 4; i++) {
                int nrow = r + drow[i];
                int ncol = c + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                    grid[nrow][ncol] == 1) {
                    queue.add(new int[] {nrow, ncol, t + 1});
                    grid[nrow][ncol] = 2;
                    freshCount--;
                }
            }
        }

        return freshCount == 0 ? time : -1;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **BFS Traversal:** \( O(m \times n) \), as we process each cell at most once.
- **Overall:** \( O(m \times n) \).

### Space Complexity

- **Queue and Visited Array:** \( O(m \times n) \).
- **Overall:** \( O(m \times n) \).

---

## How to Run the Code

### For C++

1. Copy the C++ implementation into your IDE or a `.cpp` file.
2. Compile the file using a C++ compiler:

   ```bash
   g++ -o rottingOranges rottingOranges.cpp
   ```

3. Run the program:

   ```bash
   ./rottingOranges
   ```

### For Java

1. Copy the Java implementation into a file named `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```

## Other Solutions

### Python Solution

```python
from collections import deque

# Time complexity: O(rows * cols) -> each cell is visited at least once
# Space complexity: O(rows * cols) -> in the worst case if all the oranges are rotten they will be added to the queue

class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        
        # number of rows
        rows = len(grid)
        if rows == 0:  # check if grid is empty
            return -1
        
        # number of columns
        cols = len(grid[0])
        
        # keep track of fresh oranges
        fresh_cnt = 0
        
        # queue with rotten oranges (for BFS)
        rotten = deque()
        
        # visit each cell in the grid
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 2:
                    # add the rotten orange coordinates to the queue
                    rotten.append((r, c))
                elif grid[r][c] == 1:
                    # update fresh oranges count
                    fresh_cnt += 1
        
        # keep track of minutes passed.
        minutes_passed = 0
        
        # If there are rotten oranges in the queue and there are still fresh oranges in the grid keep looping
        while rotten and fresh_cnt > 0:

            # update the number of minutes passed
            # it is safe to update the minutes by 1, since we visit oranges level by level in BFS traversal.
            minutes_passed += 1
            
            # process rotten oranges on the current level
            for _ in range(len(rotten)):
                x, y = rotten.popleft()
                
                # visit all the adjacent cells
                for dx, dy in [(1,0), (-1,0), (0,1), (0,-1)]:
                    # calculate the coordinates of the adjacent cell
                    xx, yy = x + dx, y + dy
                    # ignore the cell if it is out of the grid boundary
                    if xx < 0 or xx == rows or yy < 0 or yy == cols:
                        continue
                    # ignore the cell if it is empty '0' or visited before '2'
                    if grid[xx][yy] == 0 or grid[xx][yy] == 2:
                        continue
                        
                    # update the fresh oranges count
                    fresh_cnt -= 1
                    
                    # mark the current fresh orange as rotten
                    grid[xx][yy] = 2
                    
                    # add the current rotten to the queue
                    rotten.append((xx, yy))

        
        # return the number of minutes taken to make all the fresh oranges to be rotten
        # return -1 if there are fresh oranges left in the grid (there were no adjacent rotten oranges to make them rotten)
        return minutes_passed if fresh_cnt == 0 else -1
```
