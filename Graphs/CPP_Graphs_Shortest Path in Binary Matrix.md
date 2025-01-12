# Shortest Path in Binary Matrix

## Table of Contents

- [Shortest Path in Binary Matrix](#shortest-path-in-binary-matrix)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution -2](#solution--2)
      - [Edge Case Handling](#edge-case-handling)
      - [Optimized BFS Explanation](#optimized-bfs-explanation)
      - [Optimized Double-Ended BFS](#optimized-double-ended-bfs)
      - [Code for Double-Ended BFS](#code-for-double-ended-bfs)
      - [Notes and Observations](#notes-and-observations)

---

## Introduction

The problem is to find the shortest path from the **top-left** cell to the **bottom-right** cell in an `n x n` binary matrix. The path must consist only of cells containing `0` and must traverse cells connected 8-directionally (including diagonals). If no such path exists, return `-1`. The length of the path is the number of cells visited.

---

## Problem Description

### Input

- **`grid`**: An `n x n` binary matrix:
  - `grid[i][j] = 0`: The cell is traversable.
  - `grid[i][j] = 1`: The cell is blocked.

### Output

- The shortest path length from `(0, 0)` to `(n-1, n-1)`, or `-1` if no path exists.

### Examples

#### Example 1

**Input:**

```plaintext
grid = [[0, 1],
        [1, 0]]
```

**Output:**

```plaintext
2
```

**Explanation:**  
The shortest path is `[(0,0) -> (1,1)]`.

#### Example 2

**Input:**

```plaintext
grid = [[0, 0, 0],
        [1, 1, 0],
        [1, 1, 0]]
```

**Output:**

```plaintext
4
```

**Explanation:**  
The shortest path is `[(0,0) -> (0,1) -> (0,2) -> (1,2) -> (2,2)]`.

#### Example 3

**Input:**

```plaintext
grid = [[1, 0, 0],
        [1, 1, 0],
        [1, 1, 0]]
```

**Output:**

```plaintext
-1
```

**Explanation:**  
There is no clear path from `(0,0)` to `(2,2)`.

---

## Constraints

- \(1 \leq n \leq 100\)
- `grid[i][j]` is either `0` or `1`.

---

## Approach

### Breadth-First Search (BFS)

1. **Initialization**:
   - If the source `(0, 0)` or destination `(n-1, n-1)` is blocked, return `-1`.
   - Use a queue to perform BFS starting from `(0, 0)`.
   - Maintain a `distance` matrix to store the minimum distance to each cell.
   - Define the possible 8 directions for movement.

2. **Processing**:
   - For each cell, visit its neighbors (in 8 directions).
   - If a neighbor is within bounds, has a value of `0`, and hasn't been visited with a shorter distance, update its distance and enqueue it.

3. **Termination**:
   - If the destination `(n-1, n-1)` is reached during BFS, return the distance.
   - If the queue is empty and the destination is not reached, return `-1`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Edge case: If source or destination is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> distance(n, vector<int>(n, INT_MAX)); // Distance matrix
        queue<pair<int, pair<int, int>>> q;

        // Directions for moving in 8 directions
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        distance[0][0] = 1; // Distance to the source is 1
        q.push({1, {0, 0}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dist = it.first, row = it.second.first, col = it.second.second;

            for (int i = 0; i < 8; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && dist + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = dist + 1;
                    q.push({dist + 1, {newRow, newCol}});
                    if (newRow == n-1 && newCol == n-1)
                        return dist + 1;
                }
            }
        }

        return -1; // If destination is unreachable
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int shortestPathBinaryMatrix(int[][] grid) {
        int n = grid.length;

        // Edge case: If source or destination is blocked
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        int[][] distance = new int[n][n];
        for (int[] row : distance) Arrays.fill(row, Integer.MAX_VALUE);

        Queue<int[]> queue = new LinkedList<>();
        int[] dr = {-1, -1, -1, 0, 1, 1, 1, 0};
        int[] dc = {-1, 0, 1, 1, 1, 0, -1, -1};

        distance[0][0] = 1; // Distance to the source is 1
        queue.add(new int[]{0, 0, 1});

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int row = current[0], col = current[1], dist = current[2];

            for (int i = 0; i < 8; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == 0 && dist + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = dist + 1;
                    queue.add(new int[]{newRow, newCol, dist + 1});
                    if (newRow == n-1 && newCol == n-1)
                        return dist + 1;
                }
            }
        }

        return -1; // If destination is unreachable
    }
}
```

---

## Complexity Analysis

- **Time Complexity:** \(O(n^2)\)
  - Each cell is visited at most once.
- **Space Complexity:** \(O(n^2)\)
  - For the `distance` matrix and BFS queue.

---

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file.
2. Compile with `g++ filename.cpp`.
3. Run the executable and provide inputs as required.

### For Java

1. Copy the code into a `.java` file.
2. Compile with `javac filename.java`.
3. Run the program with `java filename`.

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Edge case: If source or destination is blocked

        int n = grid.size(), m = grid[0].size();
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n - 1, m - 1};

        if (source.first == destination.first &&
            source.second == destination.second &&
            grid[source.first][source.second] == 0)
            return 1;

        if (grid[source.first][source.second] == 1 ||
            grid[destination.first][destination.second] == 1)
            return -1;

        vector<vector<int>> distance(
            n, vector<int>(m, INT_MAX)); // Distance matrix
        queue<pair<int, pair<int, int>>> q;

        // Directions for moving Up, Down, Left, and Right
        int dr[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dc[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        distance[source.first][source.second] = 1;
        q.push({1, {source.first, source.second}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dist = it.first, row = it.second.first, col = it.second.second;

            for (int i = 0; i < 8; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 0 &&
                    dist + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = dist + 1;
                    q.push({dist + 1, {newRow, newCol}});
                    if (newRow == destination.first &&
                        newCol == destination.second)
                        return dist + 1;
                }
            }
        }

        return -1; // If destination is unreachable
    }
};
```

### Solution -2

**Optimized BFS vs. DFS, Fastest Solution to Date, 100% Time (35ms), ~99% Space (18.3MB)**  
Author: Giacomo Sorbi  

The problem at hand is a classic maze exploration problem where BFS (Breadth-First Search) generally outperforms DFS (Depth-First Search). Let's explore an optimized solution that uses BFS, along with an explanation of its components.

---

#### Edge Case Handling  

Before diving into the main logic, the solution addresses critical edge cases:  

1. If either the starting cell or the target cell is inaccessible (value is `1`), return `-1`.
2. For a single-cell matrix, return `1` if the cell is empty (`0`) or `-1` otherwise.

---

#### Optimized BFS Explanation  

The BFS solution works as follows:  

1. **Initialization**  
   - Define support variables:
     - `res` (result): Initialized to `2`, representing the minimum number of steps.
     - `len`: Tracks the current queue length.
     - `maxX`, `maxY`: Grid bounds.
   - Initialize a queue `q` to manage the BFS traversal, starting with the initial cell (0, 0).
   - Mark the start cell as visited by setting `grid[0][0] = -1`.

2. **Main BFS Loop**  
   - Traverse while the queue is non-empty:
     - For every cell in the current queue, check all its valid neighbors.
     - Mark valid neighbors as visited and add them to the queue for the next level of traversal.
     - Increment `res` to track the number of steps.
   - If the target cell `(maxX, maxY)` is reached, return `res`.
   - If the queue is exhausted without finding a path, return `-1`.

3. **Code for Optimized BFS**

```cpp
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // Edge case: start or end not accessible
        if (grid[0][0] || grid.back().back()) return -1;
        
        int res = 2, len = 1, maxX = grid[0].size() - 1, maxY = grid.size() - 1;
        queue<pair<int, int>> q;

        // Edge case: single cell matrix
        if (!maxX && !maxY) return 1 - (grid[0][0] << 1);

        // Adding the starting point
        q.push({0, 0});
        grid[0][0] = -1; // Marking start as visited

        while (len) {
            while (len--) {
                auto [cx, cy] = q.front();
                q.pop();

                for (int x = max(0, cx - 1), lmtX = min(cx + 1, maxX); x <= lmtX; x++) {
                    for (int y = max(0, cy - 1), lmtY = min(cy + 1, maxY); y <= lmtY; y++) {
                        // If target reached
                        if (x == maxX && y == maxY) return res;

                        // If cell is unexplored
                        if (!grid[y][x]) {
                            grid[y][x] = -1;
                            q.push({x, y});
                        }
                    }
                }
            }
            res++;
            len = q.size();
        }
        return -1;
    }
};
```

![Optimized](https://assets.leetcode.com/users/images/f0252a59-1383-4aa0-b90a-791f18aac0cc_1613219437.2042842.png)

---

#### Optimized Double-Ended BFS  

This approach improves both performance and memory usage:

1. Use two queues (`q1` and `q2`), starting BFS from both ends (start and target).
2. During BFS:
   - Alternate between queues and markers to ensure paths meet in the middle.
   - Mark cells visited by one side and check if the other side has already visited it.
3. Avoid redundant checks by prioritizing adjacent nodes and early exits.

---

#### Code for Double-Ended BFS  

```cpp
class Solution {
private:
    // support variables
    int maxX, maxY, res = 1;
    int dfs(vector<vector<int>>& grid, int cx = 0, int cy = 0) {
        // check if we reached the target
        if (cx == maxX && cy == maxY) return res;
        // support variable
        int partRes = INT_MAX;
        // marking the cell as visited and increasing res
        grid[cy][cx] = -1;
        res++;
        for (int x = max(0, cx - 1), lmtX = min(cx + 1, maxX); x <= lmtX; x++) {
            for (int y = max(0, cy - 1), lmtY = min(cy + 1, maxY); y <= lmtY; y++) {
                if (!grid[y][x]) {
                    partRes = min(partRes, dfs(grid, x, y));
                }
            }
        }
        // backtracking the cell as non-visited and decreasing res
        grid[cy][cx] = 0;
        res--;
        return partRes;
    }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // edge case: start or end not accessible
        if (grid[0][0] || grid.back().back()) return -1;
        maxX = grid[0].size() - 1, maxY = grid.size() - 1;
        // searching from the starting point
        res = dfs(grid);
        return res == INT_MAX ? -1 : res;
    }
};
```

```cpp
using pathType = pair<int, int>;

class Solution {
    int startMark = -1, endMark = -2;
    queue<pathType> q1{{{0, 0}}}, q2;

    void markAndAdd(vector<vector<int>>& grid, int x, int y) {
        grid[y][x] = startMark;
        q1.push({x, y});
    }

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int t = grid.size() - 1, res = bool(t), qLen = 1, cx, cy, x, y, currVal;
        if (grid[0][0] || grid[t][t]) return -1;

        q2.push({t, t});
        grid[0][0] = startMark;
        grid[t][t] = endMark;

        while (qLen) {
            res++;
            while (qLen--) {
                auto& front = q1.front();
                cx = front.first;
                cy = front.second;
                if (grid[cy][cx] == endMark) return res;
                q1.pop();

                // Adding diagonals and adjacent nodes
                for (int dx : {-1, 0, 1}) {
                    for (int dy : {-1, 0, 1}) {
                        if (dx == 0 && dy == 0) continue;
                        x = cx + dx;
                        y = cy + dy;
                        if (x >= 0 && x <= t && y >= 0 && y <= t) {
                            currVal = grid[y][x];
                            if (currVal == endMark) return res;
                            if (!currVal) markAndAdd(grid, x, y);
                        }
                    }
                }
            }
            swap(q1, q2);
            swap(startMark, endMark);
            qLen = q1.size();
        }
        return -1;
    }
};
```

---

#### Notes and Observations

- The BFS solutions are tailored to handle sparse and dense grids efficiently.
- Double-ended BFS minimizes traversal depth, improving runtime and memory usage.
- Both solutions are highly optimized for competitive programming scenarios.
