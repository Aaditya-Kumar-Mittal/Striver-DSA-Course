# Shortest Distance in a Binary Maze

## Table of Contents

- [Shortest Distance in a Binary Maze](#shortest-distance-in-a-binary-maze)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
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

Given a binary matrix (`grid`) representing a maze, you are required to find the shortest path from a `source` cell to a `destination` cell. The path is valid only if it passes through cells containing `1`. If the path is not possible, return `-1`. Movement is allowed in four directions: Up, Down, Left, and Right.

---

## Problem Description

### Input

- **`grid`**: A 2D binary matrix of size `n x m`, where:
  - `grid[i][j] = 1`: The cell is traversable.
  - `grid[i][j] = 0`: The cell is blocked.
- **`source`**: A pair of integers `(x1, y1)` indicating the starting cell.
- **`destination`**: A pair of integers `(x2, y2)` indicating the target cell.

### Output

- The shortest distance between `source` and `destination`, or `-1` if no path exists.

### Examples

#### Example 1

**Input:**

```plaintext
grid = [[1, 1, 1, 1],
        [1, 1, 0, 1],
        [1, 1, 1, 1],
        [1, 1, 0, 0],
        [1, 0, 0, 1]]
source = (0, 1)
destination = (2, 2)
```

**Output:**

```plaintext
3
```

**Explanation:**  
The shortest path from `(0, 1)` to `(2, 2)` is of length `3`.

#### Example 2

**Input:**

```plaintext
grid = [[1, 1, 1, 1, 1],
        [1, 1, 1, 1, 1],
        [1, 1, 1, 1, 0],
        [1, 0, 1, 0, 1]]
source = (0, 0)
destination = (3, 4)
```

**Output:**

```plaintext
-1
```

**Explanation:**  
The destination `(3, 4)` is unreachable from the source `(0, 0)`.

---

## Constraints

- \(1 \leq n, m \leq 500\)
- `grid[i][j]` is either `0` or `1`.
- The `source` and `destination` cells are always within bounds.

---

## Approach

1. **Breadth-First Search (BFS):**
   - BFS is suitable for finding the shortest path in an unweighted graph-like structure.
   - Start from the `source` cell, mark it as visited, and explore its four neighbors.
   - If the `destination` cell is reached during the traversal, return the current path length.
2. **Optimizations:**
   - Use a `queue` to store cells along with their distances from the source.
   - Use a `distance` matrix to track the minimum distance to each cell from the source.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
        // Edge case: If source or destination is blocked
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> distance(n, vector<int>(m, INT_MAX)); // Distance matrix
        queue<pair<int, pair<int, int>>> q;

        // Directions for moving Up, Down, Left, and Right
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        distance[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int dist = it.first, row = it.second.first, col = it.second.second;

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 && dist + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = dist + 1;
                    q.push({dist + 1, {newRow, newCol}});
                    if (newRow == destination.first && newCol == destination.second)
                        return dist + 1;
                }
            }
        }

        return -1; // If destination is unreachable
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;

        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public int shortestPath(int[][] grid, int[] source, int[] destination) {
        int n = grid.length, m = grid[0].length;

        if (grid[source[0]][source[1]] == 0 || grid[destination[0]][destination[1]] == 0)
            return -1;

        int[][] distance = new int[n][m];
        for (int[] row : distance) Arrays.fill(row, Integer.MAX_VALUE);

        Queue<int[]> queue = new LinkedList<>();
        int[] dr = {-1, 0, 1, 0};
        int[] dc = {0, 1, 0, -1};

        distance[source[0]][source[1]] = 0;
        queue.add(new int[]{source[0], source[1], 0});

        while (!queue.isEmpty()) {
            int[] current = queue.poll();
            int row = current[0], col = current[1], dist = current[2];

            for (int i = 0; i < 4; i++) {
                int newRow = row + dr[i], newCol = col + dc[i];

                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 && dist + 1 < distance[newRow][newCol]) {
                    distance[newRow][newCol] = dist + 1;
                    queue.add(new int[]{newRow, newCol, dist + 1});
                    if (newRow == destination[0] && newCol == destination[1])
                        return dist + 1;
                }
            }
        }

        return -1;
    }
}
```

---

## Complexity Analysis

- **Time Complexity:** \(O(n \times m)\)
  - Each cell is visited at most once.
- **Space Complexity:** \(O(n \times m)\)
  - For the `distance` matrix and queue.

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

Let me know if you need further clarifications or enhancements!
