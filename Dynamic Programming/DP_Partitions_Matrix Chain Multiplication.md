# Matrix Chain Multiplication

## Table of Contents

- [Matrix Chain Multiplication](#matrix-chain-multiplication)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Steps to Run](#steps-to-run)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

## Introduction

Matrix Chain Multiplication is a classical problem in dynamic programming. Given a sequence of matrices, the goal is to determine the optimal order of multiplication to minimize the number of scalar multiplications required.

## Problem Description

Given an array `arr[]` where the `i-th` matrix has dimensions `(arr[i-1] x arr[i])`, find the most efficient way to multiply the matrices together. The efficiency is measured in terms of the least number of scalar multiplications required.

### Examples

#### Example 1

**Input:** `arr[] = [2, 1, 3, 4]`

**Output:** `20`

**Explanation:**

There are 3 matrices with dimensions:

- `M1`: 2 × 1
- `M2`: 1 × 3
- `M3`: 3 × 4

Possible multiplication orders:

1. `((M1 × M2) × M3)` → `(2×1×3) + (2×3×4) = 30`
2. `(M1 × (M2 × M3))` → `(1×3×4) + (2×1×4) = 20`

Minimum multiplications = `20`

#### Example 2

**Input:** `arr[] = [1, 2, 3, 4, 3]`

**Output:** `30`

#### Example 3

**Input:** `arr[] = [3, 4]`

**Output:** `0`

**Explanation:** Since there's only one matrix, no multiplication is required.

### Constraints

- `2 ≤ arr.size() ≤ 100`
- `1 ≤ arr[i] ≤ 500`

## Approach

The problem can be solved using dynamic programming with three different approaches:

1. **Recursive Approach** (Naïve solution)
2. **Memoization Approach** (Top-down DP)
3. **Tabulation Approach** (Bottom-up DP)

## Detailed Explanation of Code

### Recursive Approach

```cpp
int recursive_solution(int i, int j, vector<int> &arr) {
    if (i == j) return 0;

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int steps = (arr[i-1] * arr[k] * arr[j]) + recursive_solution(i, k, arr) + recursive_solution(k+1, j, arr);
        mini = min(mini, steps);
    }

    return mini;
}
```

**Explanation:**

- If `i == j`, there's only one matrix, so multiplication cost is `0`.
- Try all possible ways to parenthesize the matrices and recursively compute the minimum cost.
- The time complexity is **exponential** (`O(2^N)`).

### Memoization Approach

```cpp
int memoization(int i, int j, vector<int> &arr, vector<vector<int>> &dp) {
    if (i == j) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for (int k = i; k < j; k++) {
        int steps = (arr[i-1] * arr[k] * arr[j]) + memoization(i, k, arr, dp) + memoization(k+1, j, arr, dp);
        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}
```

**Explanation:**

- Uses a `dp[][]` table to store already computed results and avoid redundant calculations.
- Time Complexity: `O(N^2)`

### Tabulation Approach

```cpp
int tabulation(int n, vector<int> &arr) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = 1; i < n; i++) dp[i][i] = 0;

    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j < n; j++) {
            int mini = INT_MAX;

            for (int k = i; k < j; k++) {
                int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];
                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][n-1];
}
```

**Explanation:**

- Uses a `dp[][]` table to iteratively compute the minimum multiplications.
- Time Complexity: `O(N^3)`
- Space Complexity: `O(N^2)`

## Complexity Analysis

| Approach    | Time Complexity | Space Complexity     |
| ----------- | --------------- | -------------------- |
| Recursive   | `O(2^N)`        | `O(N)` (stack depth) |
| Memoization | `O(N^2)`        | `O(N^2)`             |
| Tabulation  | `O(N^3)`        | `O(N^2)`             |

## How to Run the Code

### For C++

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        return tabulation(n, arr);
    }
};

int main() {
    vector<int> arr = {2, 1, 3, 4};
    Solution obj;
    cout << "Minimum multiplications: " << obj.matrixMultiplication(arr) << endl;
    return 0;
}
```

### Steps to Run

1. Copy the code into a C++ compiler.
2. Compile using `g++ filename.cpp -o output`
3. Run using `./output`

---

## Other Solutions

### My Submission

```cpp
// User function Template for C++

class Solution {

    int recursive_solution(int i, int j, vector<int> &arr)
    {
        if(i == j) return 0;

        int mini = 1e9;

        for(int k = i; k < j; k++)
        {
            int steps = (arr[i-1] * arr[k] * arr[j]) + recursive_solution(i, k, arr) + recursive_solution(k+1, j, arr);

            if(steps < mini) mini = steps;
        }

        return mini;
    }

    int memoization(int i, int j, vector<int> &arr, vector<vector<int>> &dp)
    {
        if(i == j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = 1e9;

        for(int k = i; k < j; k++)
        {
            int steps = (arr[i-1] * arr[k] * arr[j]) + memoization(i, k, arr, dp) + memoization(k+1, j, arr, dp);

            if(steps < mini) mini = steps;
        }

        return dp[i][j] = mini;
    }

    int tabulation(int n, vector<int> &arr)
    {
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i = 1; i< n; i++) dp[i][i] = 0;

        for(int i = n-1; i >= 1; i--)
        {
            for(int j = i+1; j < n; j++)
            {
                int mini = 1e9;

                for(int k = i; k < j; k++)
                {
                    int steps = (arr[i-1] * arr[k] * arr[j]) + dp[i][k] + dp[k+1][j];

                    if(steps < mini) mini = steps;
                }

                dp[i][j] = mini;
            }
        }

        return dp[1][n-1];
    }

  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here

        int n = arr.size();

        // vector<vector<int>> dp(n, vector<int>(n, -1));

        return tabulation(n, arr);

    }
};
```

This concludes the documentation for **Matrix Chain Multiplication**. 🚀
