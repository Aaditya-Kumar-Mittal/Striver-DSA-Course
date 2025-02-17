# Count Square Submatrices with All Ones

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Count Square Submatrices with All Ones](#count-square-submatrices-with-all-ones)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Overview](#overview)
      - [Conditions for Square Submatrices](#conditions-for-square-submatrices)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [Approach 1: Bottom-up Approach](#approach-1-bottom-up-approach)
      - [Intuition](#intuition)
      - [Algorithm](#algorithm)
      - [C++ Implementation](#c-implementation-1)
      - [Java Implementation](#java-implementation)
      - [Python Implementation](#python-implementation)
    - [Approach 2: Top-Down Dynamic Programming](#approach-2-top-down-dynamic-programming)
      - [Intuition](#intuition-1)
      - [Algorithm](#algorithm-1)
      - [C++ Implementation](#c-implementation-2)
      - [Java Implementation](#java-implementation-1)
      - [Python Implementation](#python-implementation-1)
    - [Approach 3: Optimized Dynamic Programming](#approach-3-optimized-dynamic-programming)
      - [Intuition](#intuition-2)
      - [Algorithm](#algorithm-2)
      - [C++ Implementation](#c-implementation-3)
      - [Java Implementation](#java-implementation-2)
      - [Python Implementation](#python-implementation-2)

## Introduction

The problem requires counting all square submatrices with all ones in a given binary matrix (composed of 0s and 1s). A submatrix is square if its number of rows and columns are equal.

### Overview

We need to find the number of square submatrices containing only ones in a binary matrix. A square submatrix has equal rows and columns, such as 1x1, 2x2, 3x3, and so on.

- **1x1 submatrices**: Each cell with only a 1 contributes directly to the count.
- **Larger submatrices**: For submatrices larger than 1x1, the size of the largest square submatrix with its bottom right corner at (i, j) determines the count of possible square submatrices.

#### Conditions for Square Submatrices

![enter image description here](https://leetcode.com/problems/count-square-submatrices-with-all-ones/Figures/1277re/Slide1re.png)

![enter image description here](https://leetcode.com/problems/count-square-submatrices-with-all-ones/Figures/1277re/Slide2re.png)

![enter image description here](https://leetcode.com/problems/count-square-submatrices-with-all-ones/Figures/1277re/Slide3re.png)

- For a 2x2 square ending at (i, j):
  - The cell at (i, j) must be 1.
  - The cells above (i-1, j), to the left (i, j-1), and diagonally (i-1, j-1) must also be 1.
- For a 3x3 square:
  - The 2x2 square formed by the neighbors (i-1, j-1), (i-1, j), and (i, j-1) must be valid.

Thus, constructing larger submatrices relies on the existence of smaller valid ones.

## Problem Description

Given an `m x n` matrix consisting of ones and zeros, the task is to find the number of square submatrices that contain only ones.

### Examples

#### Example 1

**Input:**

```cpp
matrix = [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
]
```

**Output:**

```bash
15
```

**Explanation:**

- There are 10 squares of size 1x1.
- There are 4 squares of size 2x2.
- There is 1 square of size 3x3.
- Total squares = 10 + 4 + 1 = 15.

#### Example 2

**Input:**

```cpp
matrix = [
    [1,0,1],
    [1,1,0],
    [1,1,0]
]
```

**Output:**

```bash
7
```

**Explanation:**

- There are 6 squares of size 1x1.
- There is 1 square of size 2x2.
- Total squares = 6 + 1 = 7.

### Constraints

- `1 <= matrix.length <= 300`
- `1 <= matrix[0].length <= 300`
- `0 <= matrix[i][j] <= 1`

## Approach

This problem is efficiently solved using Dynamic Programming (DP). The main idea is:

1. Define a DP table `dp[i][j]`, where each cell stores the size of the largest square submatrix ending at `(i, j)`.
2. Base case: First row and first column directly inherit values from `matrix[i][j]`.
3. Transition:
   - If `matrix[i][j] == 1`, `dp[i][j] = 1 + min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])`.
   - If `matrix[i][j] == 0`, then `dp[i][j] = 0`.
4. The sum of all values in `dp` gives the final result.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++)
            dp[0][j] = matrix[0][j];

        for (int i = 0; i < row; i++)
            dp[i][0] = matrix[i][0];

        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }

        int sum = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum += dp[i][j];
            }
        }

        return sum;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(m * n)`, since we iterate through the matrix once.
- **Space Complexity:** `O(m * n)`, as we use an auxiliary DP table of the same size.

## How to Run the Code

### For C++

1. Copy and paste the code into a `.cpp` file.
2. Compile using:

   ```sh
   g++ -o solution solution.cpp
   ```

3. Run the executable:

   ```sh
   ./solution
   ```

---

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int row = matrix.size();
        int col = matrix[0].size();

        vector<vector<int>> dp(row, vector<int>(col, 0));

        for (int j = 0; j < col; j++)
            dp[0][j] = matrix[0][j];
        for (int i = 0; i < row; i++)
            dp[i][0] = matrix[i][0];
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (matrix[i][j] == 0)
                    dp[i][j] = 0;
                else {
                    dp[i][j] = 1 + min(dp[i - 1][j],
                                       min(dp[i - 1][j - 1], dp[i][j - 1]));
                }
            }
        }

        int sum = 0;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                sum += dp[i][j];
            }
        }

        return sum;
    }
};
```

---

### Approach 1: Bottom-up Approach

#### Intuition

- Initialize a DP matrix (`dp`) with the same dimensions as the original matrix, initialized with all 0’s.
- `dp(i, j)` represents the side length of the maximum square whose bottom right corner is the cell with index (i, j) in the original matrix.
- For every 1 found in the original matrix, update the value of the current element as:

  ```cpp
  dp(i+1, j+1) = min(dp(i, j+1), dp(i+1, j), dp(i, j)) + 1
  ```

- Store the sizes of the largest squares in the `dp` array. The required result is the sum of the sizes of these squares.

#### Algorithm

1. Create a 2D DP table `dp` of size `(row+1) x (col+1)` to store the size of the largest square submatrices ending at each cell (i, j).
2. Initialize a variable `ans` to keep track of the total number of square submatrices with all 1s.
3. Traverse the input matrix using a nested loop:

   - Outer loop iterates over the rows (i from 0 to row-1).
   - Inner loop iterates over the columns (j from 0 to col-1):

     - For each cell `matrix[i][j]`, if the value is 1:

       - Calculate the size of the square submatrix ending at that cell using:

         ```cpp
         dp[i+1][j+1] = min(dp[i][j+1], dp[i+1][j], dp[i][j]) + 1
         ```

       - Add this value to the total count `ans`.

4. Return the value of `ans`.

#### C++ Implementation

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] =
                        min({dp[i][j + 1], dp[i + 1][j], dp[i][j]}) + 1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
};
```

#### Java Implementation

```java
class Solution {

    public int countSquares(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length;
        int[][] dp = new int[row + 1][col + 1];
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (matrix[i][j] == 1) {
                    dp[i + 1][j + 1] =
                        Math.min(
                            Math.min(dp[i][j + 1], dp[i + 1][j]),
                            dp[i][j]
                        ) +
                        1;
                    ans += dp[i + 1][j + 1];
                }
            }
        }
        return ans;
    }
}
```

#### Python Implementation

```python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row, col = len(matrix), len(matrix[0])
        dp = [[0] * (col + 1) for _ in range(row + 1)]
        ans = 0
        for i in range(row):
            for j in range(col):
                if matrix[i][j]:
                    dp[i + 1][j + 1] = (
                        min(dp[i][j + 1], dp[i + 1][j], dp[i][j]) + 1
                    )
                    ans += dp[i + 1][j + 1]
        return ans
```

---

### Approach 2: Top-Down Dynamic Programming

#### Intuition

- Use recursion to break the problem into smaller subproblems.
- At each cell (i, j), the size of the largest square submatrix depends on the sizes of the submatrices at its neighboring cells: (i-1, j), (i, j-1), and (i-1, j-1).
- Convert the recursive approach into a dynamic programming (DP) solution using memoization to store results of subproblems.

#### Algorithm

1. Define a recursive function `solve(i, j, grid, dp)`:
   - If the current cell `grid[i][j]` is outside the bounds of the grid or is 0, return 0.
   - If `dp[i][j] != -1`, return the memoized value.
   - Recursively calculate the size of the square submatrices:
     - `right`: Check the cell to the right (i, j+1).
     - `diagonal`: Check the cell to the diagonal below (i+1, j+1).
     - `below`: Check the cell below (i+1, j).
   - Store the result as `1 + min(right, diagonal, below)` in the `dp` table.
2. Initialize a DP table:
   - Create a `dp` table (2D vector) of the same size as the input grid, initialized with -1.
3. Use a nested loop to iterate through each cell in the grid:
   - For each cell (i, j), call the recursive function `solve(i, j)` to compute the size of the largest square submatrices ending at that cell and add it to the total count.
4. Return the total number of square submatrices with all 1s.

#### C++ Implementation

```cpp
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {
        // If the cell lies outside the grid, return 0.
        if (i >= grid.size() || j >= grid[0].size()) return 0;
        if (grid[i][j] == 0) return 0;

        // If we have already visited this cell, return the memoized value.
        if (dp[i][j] != -1) return dp[i][j];

        // Find the answer for the cell to the right of the current cell.
        int right = solve(i, j + 1, grid, dp);
        // Find the answer for the cell to the diagonal of the current cell.
        int diagonal = solve(i + 1, j + 1, grid, dp);
        // Find the answer for the cell below the current cell.
        int below = solve(i + 1, j, grid, dp);

        return dp[i][j] = 1 + min(right, min(diagonal, below));
    }

    int countSquares(vector<vector<int>>& grid) {
        int ans = 0;
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                ans += solve(i, j, grid, dp);
            }
        }
        return ans;
    }
};
```

#### Java Implementation

```java
class Solution {

    public int solve(int i, int j, int[][] grid, int[][] dp) {
        // If the cell lies outside the grid, return 0.
        if (i >= grid.length || j >= grid[0].length) {
            return 0;
        }
        if (grid[i][j] == 0) {
            return 0;
        }

        // If we have already visited this cell, return the memoized value.
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Find the answer for the cell to the right of the current cell.
        int right = solve(i, j + 1, grid, dp);
        // Find the answer for the cell to the diagonal of the current cell.
        int diagonal = solve(i + 1, j + 1, grid, dp);
        // Find the answer for the cell below the current cell.
        int below = solve(i + 1, j, grid, dp);

        return dp[i][j] = 1 + Math.min(right, Math.min(diagonal, below));
    }

    public int countSquares(int[][] grid) {
        int ans = 0;
        int[][] dp = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                Arrays.fill(dp[i], -1);
            }
        }
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                ans += solve(i, j, grid, dp);
            }
        }

        return ans;
    }
}
```

#### Python Implementation

```python
class Solution:
    def solve(self, i, j, grid, dp):
        # If the cell lies outside the grid, return 0.
        if i >= len(grid) or j >= len(grid[0]):
            return 0
        if grid[i][j] == 0:
            return 0
        # If we have already visited this cell, return the memoized value.
        if dp[i][j] != -1:
            return dp[i][j]
        # Find the answer for the cell to the right of the current cell.
        right = self.solve(i, j + 1, grid, dp)
        # Find the answer for the cell to the diagonal of the current cell.
        diagonal = self.solve(i + 1, j + 1, grid, dp)
        # Find the answer for the cell below the current cell.
        below = self.solve(i + 1, j, grid, dp)
        dp[i][j] = 1 + min(right, min(diagonal, below))
        return dp[i][j]

    def countSquares(self, matrix: List[List[int]]) -> int:
        ans = 0
        dp = [[-1 for _ in range(len(matrix[0]))] for _ in range(len(matrix))]
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                ans += self.solve(i, j, matrix, dp)
        return ans

```

---

### Approach 3: Optimized Dynamic Programming

#### Intuition

- The size of the largest square submatrix ending at a given cell (i, j) depends on three values:
  - The size of the largest square ending at (i, j-1) (left).
  - The size of the largest square ending at (i-1, j) (top).
  - The size of the largest square ending at (i-1, j-1) (top-left).
- Use a 1D DP array to optimize space complexity.

#### Algorithm

1. Create a 1D DP table `dp` of size `(col+1)` to store the size of the largest square submatrices ending at each cell (i, j).
2. Initialize a variable `result` to keep track of the total count of square submatrices and a variable `prev` to store the value of the top-left diagonal element for the DP computation.
3. Traverse the input matrix using a nested loop:

   - Outer loop iterates over the rows (i from 0 to row-1).
   - Inner loop iterates over the columns (j from 0 to col-1):

     - For each cell `matrix[i][j]`, if the value is 1:

       - Temporarily store the current value of `dp[j]` in a variable `temp`.
       - Update `dp[j]` using:

         ```cpp
         dp[j] = 1 + min(prev, min(dp[j-1], dp[j]))
         ```

       - Update `prev` to the value stored in `temp`.
       - Add `dp[j]` to `result`.

     - Otherwise, set `dp[j]` to 0.

4. Return the value of `result`.

#### C++ Implementation

```cpp
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size(), result = 0, prev = 0;
        vector<int> dp(col + 1, 0);

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    int temp = dp[j];
                    dp[j] = 1 + min(prev, min(dp[j - 1], dp[j]));
                    prev = temp;
                    result += dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return result;
    }
};
```

#### Java Implementation

```java
class Solution {

    public int countSquares(int[][] matrix) {
        int row = matrix.length, col = matrix[0].length, result = 0, prev = 0;
        int[] dp = new int[col + 1];

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++) {
                if (matrix[i - 1][j - 1] == 1) {
                    int temp = dp[j];
                    dp[j] = 1 + Math.min(prev, Math.min(dp[j - 1], dp[j]));
                    prev = temp;
                    result += dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return result;
    }
}
```

#### Python Implementation

````python
class Solution:
    def countSquares(self, matrix: List[List[int]]) -> int:
        row, col, result, prev = len(matrix), len(matrix[0]), 0, 0
        dp = [0 for _ in range(col + 1)]

        for i in range(1, row + 1):
            for j in range(1, col + 1):
                if matrix[i - 1][j - 1] == 1:
                    temp = dp[j]
                    dp[j] = 1 + min(prev, min(dp[j - 1], dp[j]))
                    prev = temp
                    result += dp[j]
                else:
                    dp[j] = 0

        return result
        ```
---

### Complexity Analysis

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Bottom-up Approach | O(row \* col)   | O(row \* col)    |
| Top-Down DP        | O(row \* col)   | O(row \* col)    |
| Optimized DP       | O(row \* col)   | O(col)           |

---

### Summary

- **Bottom-up Approach**: Uses a 2D DP table to store results and iterates through the matrix to compute the largest square submatrices.
- **Top-Down DP**: Uses recursion with memoization to solve subproblems and store results in a 2D DP table.
- **Optimized DP**: Reduces space complexity by using a 1D DP array and a variable to store the top-left diagonal value.

This solution efficiently counts all square submatrices with ones using dynamic programming!
````
