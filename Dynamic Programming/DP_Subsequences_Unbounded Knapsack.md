# Unbounded Knapsack

## Table of Contents

- [Unbounded Knapsack](#unbounded-knapsack)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
    - [Memoization](#memoization)
    - [Tabulation](#tabulation)
    - [Space Optimized Tabulation](#space-optimized-tabulation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

## Introduction

The **Unbounded Knapsack** problem is a variation of the classical **0/1 Knapsack problem**, where each item can be taken **any number of times**. The goal is to maximize the total value while keeping the total weight within a given capacity.

## Problem Description

Given:

- An array `val[]` where `val[i]` represents the value of the `i-th` item.
- An array `wt[]` where `wt[i]` represents the weight of the `i-th` item.
- An integer `capacity` representing the maximum weight the knapsack can carry.

**Objective:**
Find the **maximum value** that can be obtained by filling the knapsack optimally with the given items.

### Examples

#### Example 1

**Input:**

```cpp
val = [1, 1], wt = [2, 1], capacity = 3
```

**Output:**

```cpp
3
```

**Explanation:** The optimal choice is to pick the 2nd element 3 times.

#### Example 2

**Input:**

```cpp
val = [6, 1, 7, 7], wt = [1, 3, 4, 5], capacity = 8
```

**Output:**

```cpp
48
```

**Explanation:** The optimal choice is to pick the 1st element 8 times.

#### Example 3

**Input:**

```cpp
val = [6, 8, 7, 100], wt = [2, 3, 4, 5], capacity = 1
```

**Output:**

```cpp
0
```

**Explanation:** We can't pick any element. Hence, total profit is 0.

### Constraints

- `1 <= val.size() = wt.size() <= 1000`
- `1 <= capacity <= 1000`
- `1 <= val[i], wt[i] <= 100`

## Approach

### Recursive Solution

This approach explores all possible selections for each item using recursion.

```cpp
int recursive_solution(int index, int capacity, vector<int>& val, vector<int>& wt) {
    if (index == 0) {
        return (capacity / wt[0]) * val[0]; // Maximum items that fit from first type
    }
    int not_pick = recursive_solution(index - 1, capacity, val, wt);
    int pick = (wt[index] <= capacity) ? val[index] + recursive_solution(index, capacity - wt[index], val, wt) : 0;
    return max(not_pick, pick);
}
```

### Memoization

This approach improves recursion by storing previously computed values.

```cpp
int memoization(int index, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
    if (index == 0) {
        return (capacity / wt[0]) * val[0];
    }
    if (dp[index][capacity] != -1) return dp[index][capacity];
    int not_pick = memoization(index - 1, capacity, val, wt, dp);
    int pick = (wt[index] <= capacity) ? val[index] + memoization(index, capacity - wt[index], val, wt, dp) : 0;
    return dp[index][capacity] = max(not_pick, pick);
}
```

### Tabulation

This approach eliminates recursion by using bottom-up dynamic programming.

```cpp
int tabulation(int n, int capacity, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
    for (int W = 0; W <= capacity; W++) {
        dp[0][W] = (W / wt[0]) * val[0];
    }
    for (int index = 1; index < n; index++) {
        for (int W = 0; W <= capacity; W++) {
            int not_pick = dp[index - 1][W];
            int pick = (wt[index] <= W) ? val[index] + dp[index][W - wt[index]] : 0;
            dp[index][W] = max(not_pick, pick);
        }
    }
    return dp[n - 1][capacity];
}
```

### Space Optimized Tabulation

Reduces space complexity by storing only the last computed row.

```cpp
int tabulation_optimized_best(int n, int capacity, vector<int>& val, vector<int>& wt) {
    vector<int> dp(capacity + 1, 0);
    for (int W = 0; W <= capacity; W++) {
        dp[W] = (W / wt[0]) * val[0];
    }
    for (int index = 1; index < n; index++) {
        for (int W = 0; W <= capacity; W++) {
            int not_pick = dp[W];
            int pick = (wt[index] <= W) ? val[index] + dp[W - wt[index]] : 0;
            dp[W] = max(not_pick, pick);
        }
    }
    return dp[capacity];
}
```

## Complexity Analysis

| Approach                   | Time Complexity   | Space Complexity         |
| -------------------------- | ----------------- | ------------------------ |
| Recursive                  | `O(2^n)`          | `O(n)` (recursive stack) |
| Memoization                | `O(n * capacity)` | `O(n * capacity)`        |
| Tabulation                 | `O(n * capacity)` | `O(n * capacity)`        |
| Space Optimized Tabulation | `O(n * capacity)` | `O(capacity)`            |

## How to Run the Code

1. Compile the C++ code using:

   ```sh
   g++ -std=c++17 knapsack.cpp -o knapsack
   ```

2. Run the executable:

   ```sh
   ./knapsack
   ```

3. Provide input in the required format, and the output will be displayed.

## Other Solutions

### My Submission

```cpp
// User function Template for C++

class Solution {
  public:

    // Recursive function for Unbounded Knapsack
    int recursive_solution(int index, int capacity, vector<int>& val, vector<int>& wt) {
        if (index == 0) {
            return (capacity / wt[0]) * val[0]; // Maximum items that fit from first type
        }

        int not_pick = recursive_solution(index - 1, capacity, val, wt);
        int pick = (wt[index] <= capacity)
                    ? val[index] + recursive_solution(index, capacity - wt[index], val, wt)
                    : 0;

        return max(not_pick, pick);
    }

    int memoization(int index, int capacity, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp) {
        if (index == 0) {
            return (capacity / wt[0]) * val[0]; // Maximum items that fit from first type
        }

        if(dp[index][capacity] != -1) return dp[index][capacity];

        int not_pick = memoization(index - 1, capacity, val, wt, dp);
        int pick = (wt[index] <= capacity)
                    ? val[index] + memoization(index, capacity - wt[index], val, wt, dp)
                    : 0;

        return dp[index][capacity] = max(not_pick, pick);
    }

    int tabulation(int n, int capacity, vector<int> &val, vector<int> &wt)
      {
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        for (int W = 0; W <= capacity; W++)
        {
          dp[0][W] = (W / wt[0]) * val[0];
        }

        for (int index = 1; index < n; index++)
        {
          for (int W = 0; W <= capacity; W++)
          {
            int not_pick = dp[index - 1][W];
            int pick = (wt[index] <= W) ? val[index] + dp[index][W - wt[index]] : 0;
            dp[index][W] = max(not_pick, pick);
          }
        }

        return dp[n - 1][capacity];
      }

      int tabulation_optimized(int n, int capacity, vector<int> &val, vector<int> &wt)
      {
       vector<int> dp(capacity + 1, 0), current(capacity + 1, 0);

        for (int W = 0; W <= capacity; W++)
        {
          dp[W] = (W / wt[0]) * val[0];
        }

        for (int index = 1; index < n; index++)
        {
          for (int W = 0; W <= capacity; W++)
          {
            int not_pick = dp[W];
            int pick = (wt[index] <= W) ? val[index] + current[W - wt[index]] : 0;
            current[W] = max(not_pick, pick);
          }
          dp = current;
        }

        return dp[capacity];
      }

    int tabulation_optimized_best(int n, int capacity, vector<int> &val, vector<int> &wt)
    {
        vector<int> dp(capacity + 1, 0);

        for (int W = 0; W <= capacity; W++) dp[W] = (W / wt[0]) * val[0];

        for (int index = 1; index < n; index++)
        {

            for (int W = 0; W <= capacity; W++)
            {
                int not_pick = dp[W];
                int pick = (wt[index] <= W) ? val[index] + dp[W - wt[index]] : 0;
                dp[W] = max(not_pick, pick);
            }
        }

        return dp[capacity];
    }

    // Function to solve Knapsack problem
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();

        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

        return tabulation_optimized_best(n, capacity, val, wt);
    }
};
```
