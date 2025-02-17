# Burst Balloons

## Table of Contents

- [Burst Balloons](#burst-balloons)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
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

## Introduction

The **Burst Balloons** problem requires finding the maximum number of coins that can be collected by strategically bursting balloons. Each burst balloon contributes to the score based on the product of its adjacent balloons.

## Problem Description

Given an array `nums` of `n` balloons, where `nums[i]` represents the value of the `i-th` balloon, the goal is to maximize the score by bursting balloons in an optimal order. The score for bursting a balloon at index `i` is computed as:

```cpp
nums[i - 1] * nums[i] * nums[i + 1]
```

If `i - 1` or `i + 1` goes out of bounds, assume the balloon at that position is `1`.

### Examples

#### Example 1

**Input:**

```cpp
nums = [3,1,5,8]
```

**Output:**

```cpp
167
```

**Explanation:**

```cpp
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
```

#### Example 2

**Input:**

```cpp
nums = [1,5]
```

**Output:**

```cpp
10
```

### Constraints

- `n == nums.length`
- `1 <= n <= 300`
- `0 <= nums[i] <= 100`

## Approach

We solve this problem using **Dynamic Programming (DP)**. The key steps are:

1. **Recursive Approach**: Solve the problem by recursively trying all burst sequences and selecting the maximum score.
2. **Memoization**: Store results of overlapping subproblems to avoid recomputation.
3. **Tabulation (Bottom-Up DP)**: Build a DP table iteratively to optimize space and time.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int recursive_solution(int i, int j, vector<int>& nums) {
        if (i > j) return 0;

        int maxi = -1e9;
        for (int ind = i; ind <= j; ind++) {
            int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) +
                       recursive_solution(i, ind - 1, nums) +
                       recursive_solution(ind + 1, j, nums);
            maxi = max(maxi, cost);
        }
        return maxi;
    }

    int memoization(int i, int j, vector<int>& nums, vector<vector<int>>& dp) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        int maxi = -1e9;
        for (int ind = i; ind <= j; ind++) {
            int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) +
                       memoization(i, ind - 1, nums, dp) +
                       memoization(ind + 1, j, nums, dp);
            maxi = max(maxi, cost);
        }
        return dp[i][j] = maxi;
    }

    int tabulation(int n, vector<int>& nums) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= n; j++) {
                if (i > j) continue;

                int maxi = -1e9;
                for (int ind = i; ind <= j; ind++) {
                    int cost = (nums[i - 1] * nums[ind] * nums[j + 1]) +
                               dp[i][ind - 1] + dp[ind + 1][j];
                    maxi = max(maxi, cost);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n];
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        vector<int> temp = nums;
        temp.insert(temp.begin(), 1);
        temp.push_back(1);

        return tabulation(n, temp);
    }
};
```

## Complexity Analysis

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Recursion   | `O(3^N)`        | `O(N)`           |
| Memoization | `O(N^2)`        | `O(N^2)`         |
| Tabulation  | `O(N^3)`        | `O(N^2)`         |

- The **Recursive** approach explores all possible ways of bursting balloons, leading to exponential time complexity (`O(3^N)`).
- **Memoization** optimizes this by storing results, reducing the complexity to `O(N^2)`.
- **Tabulation** further optimizes by iterating in a bottom-up manner, achieving `O(N^3)`.

## How to Run the Code

### For C++

1. Copy the provided C++ code into a file, e.g., `burst_balloons.cpp`.
2. Compile using:

   ```sh
   g++ burst_balloons.cpp -o burst_balloons
   ```

3. Run the executable:

   ```sh
   ./burst_balloons
   ```

This will execute the code and print the maximum coins that can be obtained by bursting the balloons optimally.

---

This documentation provides an in-depth explanation of the problem, approach, implementation, and execution details. 🚀 Let me know if you need further refinements!
