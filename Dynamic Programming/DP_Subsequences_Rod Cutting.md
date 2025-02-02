# Rod Cutting

## Table of Contents

- [Rod Cutting](#rod-cutting)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
    - [Optimized Tabulation Approach](#optimized-tabulation-approach)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

## Introduction

The **Rod Cutting** problem is a variation of the **Unbounded Knapsack** problem. Given a rod of length `n` inches and an array `price[]` where `price[i]` denotes the value of a piece of length `(i+1)`, the task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

## Problem Description

Given:

- An integer `n` representing the length of the rod.
- An array `price[]` of size `n`, where `price[i]` is the value of a piece of length `i+1`.

### Examples

#### Example 1

**Input:**

```cpp
price[] = [1, 5, 8, 9, 10, 17, 17, 20]
```

**Output:**

```cpp
22
```

**Explanation:**
The maximum obtainable value is `22` by cutting the rod into two pieces of lengths `2` and `6`, i.e., `5+17=22`.

#### Example 2

**Input:**

```cpp
price[] = [3, 5, 8, 9, 10, 17, 17, 20]
```

**Output:**

```cpp
24
```

**Explanation:**
The maximum obtainable value is `24` by cutting the rod into `8` pieces of length `1`, i.e., `8 * price[1] = 8 * 3 = 24`.

### Constraints

- `1 ≤ price.size() ≤ 10^3`
- `1 ≤ price[i] ≤ 10^6`

## Approach

The problem can be solved using the following approaches:

1. **Recursive Approach:** Solve the problem by considering two cases for each piece: taking it or not taking it.
2. **Memoization Approach:** Use a 2D `dp` table to store computed results and avoid redundant calculations.
3. **Tabulation Approach:** Use a bottom-up approach to fill a `dp` table iteratively.
4. **Optimized Tabulation:** Reduce space complexity by maintaining only the previous row.

## Detailed Explanation of Code

### Recursive Approach

```cpp
int recursive_solution(int index, int target, vector<int> &price) {
    if(index == 0) return target * price[0];

    int not_take = recursive_solution(index-1, target, price);
    int take = (index+1 <= target) ? price[index] + recursive_solution(index, target-(index+1), price) : 0;

    return max(not_take, take);
}
```

### Memoization Approach

```cpp
int memoization(int index, int target, vector<int> &price, vector<vector<int>>& dp) {
    if(index == 0) return target * price[0];
    if(dp[index][target] != -1) return dp[index][target];

    int not_take = memoization(index-1, target, price, dp);
    int take = (index+1 <= target) ? price[index] + memoization(index, target-(index+1), price, dp) : 0;

    return dp[index][target] = max(not_take, take);
}
```

### Tabulation Approach

```cpp
int tabulation(int n, vector<int> &price) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    for(int len = 0; len <= n; len++) {
        dp[0][len] = len * price[0];
    }

    for(int index = 1; index < n; index++) {
        for(int len = 0; len <= n; len++) {
            int not_take = dp[index-1][len];
            int take = (index+1 <= len) ? price[index] + dp[index][len - (index+1)] : 0;
            dp[index][len] = max(not_take, take);
        }
    }

    return dp[n-1][n];
}
```

### Optimized Tabulation Approach

```cpp
int tabulation_optimized_best(int n, vector<int> &price) {
    vector<int> dp(n+1, -1);

    for(int len = 0; len <= n; len++) {
        dp[len] = len * price[0];
    }

    for(int index = 1; index < n; index++) {
        for(int len = 0; len <= n; len++) {
            int not_take = dp[len];
            int take = (index+1 <= len) ? price[index] + dp[len - (index+1)] : 0;
            dp[len] = max(not_take, take);
        }
    }

    return dp[n];
}
```

## Complexity Analysis

| Approach             | Time Complexity        | Space Complexity |
| -------------------- | ---------------------- | ---------------- |
| Recursive            | `O(2^n)` `Exponential` | `O(n)`           |
| Memoization          | `O(n^2)`               | `O(n^2)`         |
| Tabulation           | `O(n^2)`               | `O(n^2)`         |
| Optimized Tabulation | `O(n^2)`               | `O(n)`           |

## How to Run the Code

1. Compile the program using a C++ compiler:

   ```sh
   g++ -o rod_cutting rod_cutting.cpp
   ```

2. Run the program:

   ```sh
   ./rod_cutting
   ```

3. Provide input as specified in examples to test the functionality.

## Other Solutions

### My Submission

```cpp
// User function Template for C++

class Solution {
  public:

    int recursive_solution(int index, int target, vector<int> &price)
    {
        if(index == 0) return target * price[0];

        int not_take = recursive_solution(index-1, target, price);
        int take = (index+1 <= target) ? price[index]+recursive_solution(index, target-(index+1), price) : 0;

        return max(not_take, take);
    }

    int memoization(int index, int target, vector<int> &price, vector<vector<int>>& dp)
    {
        if(index == 0) return target * price[0];
        if(dp[index][target] != -1) return dp[index][target];

        int not_take = memoization(index-1, target, price, dp);
        int take = (index+1 <= target) ? price[index]+memoization(index, target-(index+1), price, dp) : 0;

        return dp[index][target] = max(not_take, take);
    }

    int tabulation(int n, vector<int> &price)
    {
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        // When index is zero, len is 1
        for(int len = 0; len <= n; len++)
        {
            dp[0][len] = len * price[0];
        }

        for(int index = 1; index < n; index++)
        {
            for(int len = 0; len <= n; len++)
            {
                int not_take = dp[index-1][len];
                int take = (index+1 <= len) ? price[index] + dp[index][len - (index+1)] : 0;
                dp[index][len] = max(not_take, take);
            }
        }

        return dp[n-1][n];
    }

    int tabulation_optimized(int n, vector<int> &price)
    {
        vector<int> dp(n+1, -1), current(n+1, -1);

        // When index is zero, len is 1
        for(int len = 0; len <= n; len++)
        {
            dp[len] = len * price[0];
        }

        for(int index = 1; index < n; index++)
        {
            for(int len = 0; len <= n; len++)
            {
                int not_take = dp[len];
                int take = (index+1 <= len) ? price[index] + current[len - (index+1)] : 0;
                current[len] = max(not_take, take);
            }
            dp = current;
        }

        return dp[n];
    }

    int tabulation_optimized_best(int n, vector<int> &price)
    {
        vector<int> dp(n+1, -1);

        // When index is zero, len is 1
        for(int len = 0; len <= n; len++)
        {
            dp[len] = len * price[0];
        }

        for(int index = 1; index < n; index++)
        {
            for(int len = 0; len <= n; len++)
            {
                int not_take = dp[len];
                int take = (index+1 <= len) ? price[index] + dp[len - (index+1)] : 0;
                dp[len] = max(not_take, take);
            }
        }

        return dp[n];
    }

    int cutRod(vector<int> &price) {

        int n = price.size();

        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return tabulation_optimized_best(n, price);
    }
};
```
