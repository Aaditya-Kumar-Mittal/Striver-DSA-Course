# Rat in a Maze Problem with Optimized Direction Traversal

## Table of Contents

- [Rat in a Maze Problem with Optimized Direction Traversal](#rat-in-a-maze-problem-with-optimized-direction-traversal)
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
    - [Directional Optimization](#directional-optimization)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [Other Solutions](#other-solutions)
    - [CPP Solution](#cpp-solution)

---

## Introduction

This variation of the **Rat in a Maze Problem** optimizes movement using directional arrays to simplify traversal and ensure clarity. It determines all paths from `(0, 0)` to `(n-1, n-1)` in lexicographically sorted order.

---

## Problem Description

### Input

- `n x n` binary matrix `mat`:
  - `1`: Free cell.
  - `0`: Blocked cell.

### Output

- Sorted list of valid paths (`D`, `L`, `R`, `U` moves).

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

### Directional Optimization

1. **Directional Arrays**:

   - Use arrays for movement:  
     `di[] = {+1, 0, 0, -1}` for rows (down, left, right, up).  
     `dj[] = {0, -1, +1, 0}` for columns.

2. **Recursive Backtracking**:

   - Start at `(0, 0)` and recursively move in valid directions.
   - On reaching `(n-1, n-1)`, add the path to the result.
   - Use a `visited` matrix to avoid revisiting cells.

3. **Sorting**:
   - Return sorted paths lexicographically.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void moveInMaze(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited, int di[], int dj[]) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }

        visited[i][j] = 1;

        string dlru = "DLRU"; // Order for lexicographical sorting
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visited[nexti][nextj] && maze[nexti][nextj] == 1) {
                moveInMaze(nexti, nextj, maze, n, ans, move + dlru[ind], visited, di, dj);
            }
        }

        visited[i][j] = 0; // Backtrack
    }

public:
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        int di[] = {+1, 0, 0, -1}; // Down, Left, Right, Up
        int dj[] = {0, -1, +1, 0};

        if (mat[0][0] == 1) {
            moveInMaze(0, 0, mat, n, ans, "", visited, di, dj);
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
    private void moveInMaze(int i, int j, int[][] maze, int n, List<String> ans, String move, int[][] visited, int[] di, int[] dj) {
        if (i == n - 1 && j == n - 1) {
            ans.add(move);
            return;
        }

        visited[i][j] = 1;

        String dlru = "DLRU"; // Order for lexicographical sorting
        for (int ind = 0; ind < 4; ind++) {
            int nexti = i + di[ind];
            int nextj = j + dj[ind];

            if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && visited[nexti][nextj] == 0 && maze[nexti][nextj] == 1) {
                moveInMaze(nexti, nextj, maze, n, ans, move + dlru.charAt(ind), visited, di, dj);
            }
        }

        visited[i][j] = 0; // Backtrack
    }

    public List<String> findPath(int[][] maze) {
        int n = maze.length;
        List<String> ans = new ArrayList<>();
        int[][] visited = new int[n][n];
        int[] di = {+1, 0, 0, -1}; // Down, Left, Right, Up
        int[] dj = {0, -1, +1, 0};

        if (maze[0][0] == 1) {
            moveInMaze(0, 0, maze, n, ans, "", visited, di, dj);
        }
        return ans;
    }
}
```

---

## Complexity Analysis

1. **Time Complexity**:

   - Each cell is visited once during recursion.
   - Total complexity: `O(4^(n*n))` due to recursive branching.

2. **Space Complexity**:
   - `O(n*n)` for the `visited` matrix and recursion stack.

## Other Solutions

### CPP Solution

```cpp

class Solution
{
private:
  void moveInMaze(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited, int di[], int dj[])
  {

    if (i == n - 1 && j == n - 1)
    {
      ans.push_back(move);
      return;
    }

    string dlru = "DLRU";

    for (int ind = 0; ind < 4; ind++)
    {
      int nexti = i + di[ind];

      int nextj = j + dj[ind];

      if (nexti >= 0 && nextj >= 0 && nexti < n && nextj < n && !visited[nexti][nextj] && maze[nexti][nextj] == 1)
      {
        visited[i][j] = 1;

        moveInMaze(nexti, nextj, maze, n, ans, move + dlru[ind], visited, di, dj);

        visited[i][j] = 0;
      }
    }
  }

public:
  vector<string> findPath(vector<vector<int>> &mat)
  {

    int n = mat.size();

    vector<string> ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));

    int di[] = {+1, 0, 0, -1};

    int dj[] = {0, -1, +1, 0};

    if (mat[0][0] == 1)
      moveInMaze(0, 0, mat, n, ans, "", visited, di, dj);

    return ans;
  }
};
```
