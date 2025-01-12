# 1765. Map of Highest Peak

## Table of Contents

- [1765. Map of Highest Peak](#1765-map-of-highest-peak)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
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

The problem involves assigning heights to cells in a \( m \times n \) grid such that:

- Water cells have a height of `0`.
- The height difference between adjacent cells is at most `1`.
- The maximum height in the grid is maximized.

A BFS approach is ideal as it can propagate heights outward from water cells, ensuring the height difference rule is adhered to.

---

## Problem Description

You are given an integer matrix `isWater` of size \( m \times n \), where:

- `isWater[i][j] = 1` indicates a water cell.
- `isWater[i][j] = 0` indicates a land cell.

Return a height matrix where:

- Water cells have height `0`.
- The height of adjacent cells differs by at most `1`.
- The maximum height is maximized.

---

## Examples

### Example 1

**Input:**  
`isWater = [[0,1],[0,0]]`

**Output:**  
`[[1,0],[2,1]]`

---

### Example 2

**Input:**  
`isWater = [[0,0,1],[1,0,0],[0,0,0]]`

**Output:**  
`[[1,1,0],[0,1,1],[1,2,2]]`

---

## Constraints

- \( 1 \leq m, n \leq 1000 \)
- `isWater[i][j]` is either `0` or `1`.
- There is at least one water cell.

---

## Approach

### Breadth-First Search (BFS)

1. **Initialization:**
   - Use a `queue` to store all water cells `(i, j)` with height `0`.
   - Mark water cells as visited.
2. **Propagation:**
   - For each cell, update its height as the current height incremented by `1`.
   - Push all unvisited neighbors into the queue and mark them as visited.
3. **Return:**  
   - After BFS completes, return the `height` matrix.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size();
        int m = isWater[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<vector<int>> height(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        // Initialize the queue with all water cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // BFS to assign heights
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();

            height[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && !visited[nRow][nCol]) {
                    visited[nRow][nCol] = 1;
                    q.push({{nRow, nCol}, steps + 1});
                }
            }
        }

        return height;
    }
};

int main() {
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    Solution sol;
    vector<vector<int>> result = sol.highestPeak(isWater);
    for (auto row : result) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[][] highestPeak(int[][] isWater) {
        int n = isWater.length;
        int m = isWater[0].length;

        int[][] visited = new int[n][m];
        int[][] height = new int[n][m];
        Queue<int[]> queue = new LinkedList<>();

        // Initialize the queue with all water cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (isWater[i][j] == 1) {
                    queue.add(new int[] {i, j, 0});
                    visited[i][j] = 1;
                }
            }
        }

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        // BFS to assign heights
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int row = cell[0];
            int col = cell[1];
            int steps = cell[2];

            height[row][col] = steps;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && visited[nRow][nCol] == 0) {
                    visited[nRow][nCol] = 1;
                    queue.add(new int[] {nRow, nCol, steps + 1});
                }
            }
        }

        return height;
    }

    public static void main(String[] args) {
        int[][] isWater = {{0, 1}, {0, 0}};
        Solution sol = new Solution();
        int[][] result = sol.highestPeak(isWater);
        for (int[] row : result) {
            System.out.println(Arrays.toString(row));
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- BFS visits each cell once: \( O(m \times n) \).
- For each cell, neighbors are checked in constant time.

**Overall:** \( O(m \times n) \).

### Space Complexity

- **Queue:** Stores all cells during BFS. Maximum size is \( O(m \times n) \).
- **Visited and Height Matrices:** \( O(m \times n) \).

**Overall:** \( O(m \times n) \).

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile:

   ```bash
   g++ -o highestPeak highestPeak.cpp
   ```

3. Run:

   ```bash
   ./highestPeak
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
