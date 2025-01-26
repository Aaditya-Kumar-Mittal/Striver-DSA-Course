# Maximum Path Sum in a Matrix

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Maximum Path Sum in a Matrix](#maximum-path-sum-in-a-matrix)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
      - [Pseudocode](#pseudocode)
    - [Recursive with Memoization](#recursive-with-memoization)
      - [Steps](#steps)
    - [Tabulation](#tabulation)
    - [Space Optimized Tabulation](#space-optimized-tabulation)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
    - [Time and Space Complexity Comparison](#time-and-space-complexity-comparison)
    - [Explanation of Complexities](#explanation-of-complexities)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

## Introduction

You are given an N x M matrix filled with integer numbers. The task is to find the maximum sum of a path starting from any cell in the first row and ending at any cell in the last row. From a cell (i, j) in the matrix, you can move in one of three directions:

1. Directly below: (i+1, j)
2. Diagonally below left: (i+1, j-1)
3. Diagonally below right: (i+1, j+1)

The goal is to compute the maximum possible sum for any such path.

## Problem Description

### Input

- The first line contains an integer T, the number of test cases.
- For each test case:
  - The first line contains two integers N and M representing the number of rows and columns of the matrix.
  - The next N lines contain M integers each, representing the matrix.

### Output

For each test case, print the maximum path sum.

### Examples

**Example 1:**

Input:

```bash
2
4 4
1 2 10 4
100 3 2 1
1 1 20 2
2 2 3 3
10 2 3 3
7 2 8 1
5
```

Output:

```bash
105
25
```

Explanation:

- For the first test case, the path with the maximum sum is `2 -> 100 -> 1 -> 2`, and the sum is 105.
- For the second test case, the path with the maximum sum is `10 -> 7 -> 8`, and the sum is 25.

**Example 2:**

Input:

```bash
2
3 3
1 2 3
9 8 7
4 5 6
4 6 10
10 2 -13
20 4 1
-9 -81
30 2 5
0 10 4
-79 2 -10
1 -5
2 20 -11
4
```

Output:

```bash
17
74
```

### Constraints

- \(1 \leq T \leq 50\)
- \(1 \leq N \leq 100\)
- \(1 \leq M \leq 100\)
- \(-10^4 \leq matrix[i][j] \leq 10^4\)

## Approach

### Recursive Solution

We calculate the maximum path sum starting from the last row and move upwards. For each cell (i, j), the result is:

```bash
matrix[i][j] + max(up, up_left, up_right)
```

#### Pseudocode

1. **Base Case:**

   - If `i == 0`, return `matrix[0][j]`.
   - If `j < 0` or `j >= M`, return a very small value (e.g., `INT_MIN`).

2. **Recursive Calls:**
   - Calculate the path sum for moving up, up-left, and up-right.
3. Return the maximum of the three paths.

### Recursive with Memoization

To optimize the recursive solution, we use a memoization technique by storing already computed results in a dynamic programming table `dp`.

#### Steps

1. Use a dp array where `dp[i][j]` stores the maximum path sum starting from `(i, j)`.
2. If a value is already computed, return it.

### Tabulation

We build a DP table iteratively. The value in `dp[i][j]` depends on the values from the row above:

```bash
up = dp[i-1][j]
up_left = dp[i-1][j-1] (if j > 0)
up_right = dp[i-1][j+1] (if j < M-1)
```

### Space Optimized Tabulation

Instead of maintaining a 2D DP table, we use a single row (`dp`) to store the results of the previous row and another row (`temp`) to compute the current row. After processing each row, we update the `dp` array with the results of the `temp` array.

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
int recursive_solution(int i, int j, int n, int m, vector<vector<int>> &a) {
    if (j < 0 || j >= m) return INT_MIN;
    if (i == 0) return a[0][j];

    int up = a[i][j] + recursive_solution(i - 1, j, n, m, a);
    int up_left = a[i][j] + recursive_solution(i - 1, j - 1, n, m, a);
    int up_right = a[i][j] + recursive_solution(i - 1, j + 1, n, m, a);

    return max(up, max(up_left, up_right));
}

// Recursive Memoization
int recursive_memoization(int i, int j, int n, int m, vector<vector<int>> &a, vector<vector<int>> &dp) {
    if (j < 0 || j >= m) return INT_MIN;
    if (i == 0) return a[0][j];

    if (dp[i][j] != -1) return dp[i][j];

    int up = a[i][j] + recursive_memoization(i - 1, j, n, m, a, dp);
    int up_left = a[i][j] + recursive_memoization(i - 1, j - 1, n, m, a, dp);
    int up_right = a[i][j] + recursive_memoization(i - 1, j + 1, n, m, a, dp);

    return dp[i][j] = max(up, max(up_left, up_right));
}

// Tabulation Solution
int tabulation_solution(int n, int m, vector<vector<int>> &a) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for (int j = 0; j < m; j++) {
        dp[0][j] = a[0][j];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = a[i][j] + dp[i - 1][j];
            int up_left = (j > 0) ? a[i][j] + dp[i - 1][j - 1] : INT_MIN;
            int up_right = (j < m - 1) ? a[i][j] + dp[i - 1][j + 1] : INT_MIN;

            dp[i][j] = max(up, max(up_left, up_right));
        }
    }

    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}

// Space Optimized Tabulation
int tabulation_solution_optimized(int n, int m, vector<vector<int>> &a) {
    vector<int> dp(m, 0);

    for (int j = 0; j < m; j++) {
        dp[j] = a[0][j];
    }

    for (int i = 1; i < n; i++) {
        vector<int> temp(m, 0);

        for (int j = 0; j < m; j++) {
            int up = a[i][j] + dp[j];
            int up_left = (j > 0) ? a[i][j] + dp[j - 1] : INT_MIN;
            int up_right = (j < m - 1) ? a[i][j] + dp[j + 1] : INT_MIN;

            temp[j] = max(up, max(up_left, up_right));
        }

        dp = temp;
    }

    return *max_element(dp.begin(), dp.end());
}

// Main Function to Get Maximum Path Sum
int getMaxPathSum(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    // Uncomment the desired approach:

    // Recursive Solution (Uncomment if needed)
    // int ans = INT_MIN;
    // for (int j = 0; j < m; j++) {
    //     ans = max(ans, recursive_solution(n - 1, j, n, m, matrix));
    // }
    // return ans;

    // Recursive Memoization
    // vector<vector<int>> dp(n, vector<int>(m, -1));
    // int ans = INT_MIN;
    // for (int j = 0; j < m; j++) {
    //     ans = max(ans, recursive_memoization(n - 1, j, n, m, matrix, dp));
    // }
    // return ans;

    // Tabulation Solution
    // return tabulation_solution(n, m, matrix);

    return tabulation_solution_optimized(n, m, matrix);
}
```

## Complexity Analysis

### Time Complexity

- **Recursive Solution:** \(O(3^{n})\) due to the branching at each level.
- **Memoization Solution:** \(O(n \times m)\), as we memoize the results of each sub-problem.
- **Tabulation Solution:** \(O(n \times m)\), as we fill a table of size \(n \times m\).
- **Space Optimized Tabulation:** \(O(m)\), where \(m\) is the number of columns (storing only the current and previous rows).

### Space Complexity

- **Recursive Solution:** \(O(n \times m)\) for the recursion stack.
- **Memoization Solution:** \(O(n \times m)\) for the memoization table.
- **Tabulation Solution:** \(O(n \times m)\) for the DP table.
- **Space Optimized Tabulation:** \(O(m)\) for the current and previous rows.

Here is a markdown table summarizing the **Time Complexity** and **Space Complexity** for each solution approach, along with brief explanations:

### Time and Space Complexity Comparison

| **Approach**                   | **Time Complexity** | **Explanation**                                                                                                                    | **Space Complexity** | **Explanation**                                                                             |
| ------------------------------ | ------------------- | ---------------------------------------------------------------------------------------------------------------------------------- | -------------------- | ------------------------------------------------------------------------------------------- |
| **Recursive Solution**         | \(O(3^{n})\)        | The recursion branches into three calls (up, up-left, up-right) at each level, leading to an exponential growth in function calls. | \(O(n \times m)\)    | Due to recursion depth, the space is proportional to the maximum number of recursive calls. |
| **Memoization Solution**       | \(O(n \times m)\)   | The problem is solved by breaking it down into subproblems and storing the results to avoid recomputation.                         | \(O(n \times m)\)    | A memoization table of size \(n \times m\) stores the maximum path sum for each cell.       |
| **Tabulation Solution**        | \(O(n \times m)\)   | The results are built iteratively by filling up a DP table, using previously computed values.                                      | \(O(n \times m)\)    | A DP table of size \(n \times m\) is used to store the results of all subproblems.          |
| **Space Optimized Tabulation** | \(O(n \times m)\)   | The approach is similar to tabulation but optimizes space by using only two rows instead of a full \(n \times m\) table.           | \(O(m)\)             | Only two rows are required to store the current and previous rows of the DP table.          |

### Explanation of Complexities

- **Time Complexity**: This is the time it takes to compute the result.

  - **Recursive Solution**: Since each cell's maximum sum is computed by recursively checking up to three directions, this leads to exponential time complexity.
  - **Memoization Solution**: The time complexity is reduced by storing the result of each subproblem and reusing it, making it linear in terms of the number of cells in the matrix.
  - **Tabulation Solution**: It iterates through the entire matrix, filling up the DP table once, which results in \(O(n \times m)\) time complexity.
  - **Space Optimized Tabulation**: Like the tabulation solution, but instead of storing the entire DP table, only two rows are kept, so the complexity remains \(O(n \times m)\) in filling the table but optimized in terms of space.

- **Space Complexity**: This is the amount of memory required to store intermediate results.
  - **Recursive Solution**: The recursion stack grows with each function call, so the space complexity is proportional to the maximum depth of recursion, which could be \(n \times m\).
  - **Memoization Solution**: A table of size \(n \times m\) is used to store the maximum path sum for each subproblem.
  - **Tabulation Solution**: Similar to memoization, but instead of recursive calls, an iterative process fills the table, so the space complexity is also \(n \times m\).
  - **Space Optimized Tabulation**: Only two rows are used, one for the current and another for the previous row, resulting in an optimized space complexity of \(O(m)\).

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file (e.g., `MaxPathSum.cpp`).
2. Compile the file using a C++ compiler, e.g., `g++ MaxPathSum.cpp -o MaxPathSum`.
3. Run the compiled file: `./MaxPathSum`.

## Other Solutions

### My Submission

```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive Solution
int recursive_solution(int i, int j, int n, int m, vector<vector<int>> &a) {
  // Boundary condition: invalid column index
  if (j < 0 || j >= m)
    return INT_MIN;

  // Base case: first row
  if (i == 0)
    return a[0][j];

  // Recursively calculate maximum path sum
  int up = a[i][j] + recursive_solution(i - 1, j, n, m, a);
  int up_left = a[i][j] + recursive_solution(i - 1, j - 1, n, m, a);
  int up_right = a[i][j] + recursive_solution(i - 1, j + 1, n, m, a);

  // Return the maximum of all paths
  return max(up, max(up_left, up_right));
}

// Recursive Memoization
int recursive_memoization(int i, int j, int n, int m, vector<vector<int>> &a,
                          vector<vector<int>> &dp) {
  // Boundary condition: invalid column index
  if (j < 0 || j >= m)
    return INT_MIN;

  // Base case: first row
  if (i == 0)
    return a[0][j];

  // Check if the value is already computed
  if (dp[i][j] != -1)
    return dp[i][j];

  // Recursively calculate maximum path sum
  int up = a[i][j] + recursive_memoization(i - 1, j, n, m, a, dp);
  int up_left = a[i][j] + recursive_memoization(i - 1, j - 1, n, m, a, dp);
  int up_right = a[i][j] + recursive_memoization(i - 1, j + 1, n, m, a, dp);

  // Return the maximum of all paths and store in dp array
  return dp[i][j] = max(up, max(up_left, up_right));
}

// Tabulation Solution
int tabulation_solution(int n, int m, vector<vector<int>> &a) {
  vector<vector<int>> dp(n, vector<int>(m, 0));

  // Base case: Initialize the first row
  for (int j = 0; j < m; j++) {
    dp[0][j] = a[0][j];
  }

  // Fill the dp table row by row
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int up = a[i][j] + dp[i - 1][j];
      int up_left = (j > 0) ? a[i][j] + dp[i - 1][j - 1] : INT_MIN;
      int up_right = (j < m - 1) ? a[i][j] + dp[i - 1][j + 1] : INT_MIN;

      dp[i][j] = max(up, max(up_left, up_right));
    }
  }

  // Find the maximum path sum in the last row
  int ans = INT_MIN;
  for (int j = 0; j < m; j++) {
    ans = max(ans, dp[n - 1][j]);
  }

  return ans;
}

int tabulation_solution_optimized(int n, int m, vector<vector<int>> &a) {
  vector<int> dp(m, 0); // To store the current row's results

  // Base case: Initialize the first row
  for (int j = 0; j < m; j++) {
    dp[j] = a[0][j];
  }

  // Fill the dp table row by row
  for (int i = 1; i < n; i++) {
    vector<int> temp(m, 0); // Temp array to store the current row's results

    for (int j = 0; j < m; j++) {
      // Calculate possible paths (up, up-left, up-right)
      int up = a[i][j] + dp[j];
      int up_left = (j > 0) ? a[i][j] + dp[j - 1] : INT_MIN;
      int up_right = (j < m - 1) ? a[i][j] + dp[j + 1] : INT_MIN;

      // Store the maximum of the three possible paths
      temp[j] = max(up, max(up_left, up_right));
    }

    dp = temp; // Update dp to be the current row's results
  }

  // Find the maximum path sum in the last row
  int ans = INT_MIN;
  for (int j = 0; j < m; j++) {
    ans = max(ans, dp[j]);
  }

  return ans;
}

// Main Function to Get Maximum Path Sum
int getMaxPathSum(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  // Uncomment the desired approach:

  // Recursive Solution (Uncomment if needed)
  // int ans = INT_MIN;
  // for (int j = 0; j < m; j++) {
  //     ans = max(ans, recursive_solution(n - 1, j, n, m, matrix));
  // }
  // return ans;

  // Recursive Memoization
  // vector<vector<int>> dp(n, vector<int>(m, -1));
  // int ans = INT_MIN;
  // for (int j = 0; j < m; j++) {
  //     ans = max(ans, recursive_memoization(n - 1, j, n, m, matrix, dp));
  // }
  // return ans;

  // Tabulation Solution
  // return tabulation_solution(n, m, matrix);
  return tabulation_solution_optimized(n, m, matrix);
}
```
