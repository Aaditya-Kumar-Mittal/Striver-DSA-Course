# Rat in a Maze Problem

## Table of Contents

- [Rat in a Maze Problem](#rat-in-a-maze-problem)
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
    - [Backtracking Algorithm](#backtracking-algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)

---

## Introduction

The goal is to determine all possible paths a rat can take to move from the top-left corner `(0, 0)` to the bottom-right corner `(n-1, n-1)` of an `n x n` maze, moving in four directions: 'U' (up), 'D' (down), 'L' (left), 'R' (right). The rat cannot revisit cells or pass through blocked cells (represented by 0).

---

## Problem Description

### Input

- `n x n` matrix `mat` containing:
  - `1`: Free cell.
  - `0`: Blocked cell.

### Output

- A list of all possible paths (as strings of moves) in lexicographically sorted order.

---

### Examples

#### Example 1

**Input:**

```plaintext
mat = [[1, 0, 0, 0],
       [1, 1, 0, 1],
       [1, 1, 0, 0],
       [0, 1, 1, 1]]
```

**Output:**

```plaintext
["DDRDRR", "DRDDRR"]
```

---

#### Example 2

**Input:**

```plaintext
mat = [[1, 0],
       [1, 0]]
```

**Output:**

```plaintext
[]
```

---

### Constraints

- `2 ≤ n ≤ 50`
- `0 ≤ mat[i][j] ≤ 1`

---

## Approach

### Backtracking Algorithm

1. **Recursive Exploration**:

   - Start at `(0, 0)`, mark the cell as visited.
   - Explore all possible moves: down, left, right, and up.
   - If the destination is reached, add the path to the result.
   - Backtrack to explore other possibilities.

2. **Base Cases**:

   - Stop if out of bounds, encountering a blocked cell (`0`), or revisiting a cell.

3. **Result Sorting**:
   - Return all valid paths in lexicographical order.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void moveInMaze(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        // Mark the current cell as visited
        visited[i][j] = 1;

        // Downward move
        if (i + 1 < n && !visited[i + 1][j] && maze[i + 1][j] == 1) {
            moveInMaze(i + 1, j, maze, n, ans, move + 'D', visited);
        }

        // Leftward move
        if (j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] == 1) {
            moveInMaze(i, j - 1, maze, n, ans, move + 'L', visited);
        }

        // Rightward move
        if (j + 1 < n && !visited[i][j + 1] && maze[i][j + 1] == 1) {
            moveInMaze(i, j + 1, maze, n, ans, move + 'R', visited);
        }

        // Upward move
        if (i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] == 1) {
            moveInMaze(i - 1, j, maze, n, ans, move + 'U', visited);
        }

        // Backtrack
        visited[i][j] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>> &maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));

        if (maze[0][0] == 1) {
            moveInMaze(0, 0, maze, n, ans, "", visited);
        }

        return ans;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void moveInMaze(int i, int j, int[][] maze, int n, List<String> ans, String move, int[][] visited) {
        if (i == n - 1 && j == n - 1) {
            ans.add(move);
            return;
        }

        // Mark the current cell as visited
        visited[i][j] = 1;

        // Downward move
        if (i + 1 < n && visited[i + 1][j] == 0 && maze[i + 1][j] == 1) {
            moveInMaze(i + 1, j, maze, n, ans, move + 'D', visited);
        }

        // Leftward move
        if (j - 1 >= 0 && visited[i][j - 1] == 0 && maze[i][j - 1] == 1) {
            moveInMaze(i, j - 1, maze, n, ans, move + 'L', visited);
        }

        // Rightward move
        if (j + 1 < n && visited[i][j + 1] == 0 && maze[i][j + 1] == 1) {
            moveInMaze(i, j + 1, maze, n, ans, move + 'R', visited);
        }

        // Upward move
        if (i - 1 >= 0 && visited[i - 1][j] == 0 && maze[i - 1][j] == 1) {
            moveInMaze(i - 1, j, maze, n, ans, move + 'U', visited);
        }

        // Backtrack
        visited[i][j] = 0;
    }

    public List<String> findPath(int[][] maze) {
        int n = maze.length;
        List<String> ans = new ArrayList<>();
        int[][] visited = new int[n][n];

        if (maze[0][0] == 1) {
            moveInMaze(0, 0, maze, n, ans, "", visited);
        }

        return ans;
    }
}
```

---

## Complexity Analysis

1. **Time Complexity**:

   - Each cell is visited at most once in each recursion.
   - Total complexity: `O(4^(n*n))`.

2. **Space Complexity**:
   - Space used for recursion stack and visited matrix: `O(n*n)`.
