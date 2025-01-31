# 0/1 Knapsack Problem

## Table of Contents

- [0/1 Knapsack Problem](#01-knapsack-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
    - [Optimized Tabulation Approaches](#optimized-tabulation-approaches)
  - [Complexity Analysis](#complexity-analysis)
  - [Implementation](#implementation)
    - [C++ Code](#c-code)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

---

## Introduction

The **0/1 Knapsack Problem** is a classic problem in combinatorial optimization. Given a set of items, each with a weight and a value, we want to determine the maximum total value that can be placed in a knapsack of fixed capacity. Each item can either be included entirely or not at all.

---

## Problem Description

You are given two integer arrays:

- `val[]`: Represents the values of `n` items.
- `wt[]`: Represents the weights of `n` items.
- An integer `capacity`: The maximum weight the knapsack can hold.

Your goal is to find the maximum value that can be obtained by selecting a subset of items such that their total weight does not exceed `capacity`.

### Examples

#### Example 1

**Input:**

```plaintext
capacity = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
```

**Output:**

```plaintext
3
```

**Explanation:**
We choose the last item (weight = 1, value = 3), giving a total value of **3**.

#### Example 2

**Input:**

```plaintext
capacity = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6]
```

**Output:**

```plaintext
0
```

**Explanation:**
Every item has a weight greater than the knapsack's capacity, so the maximum value is **0**.

#### Example 3

**Input:**

```plaintext
capacity = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 6, 3]
```

**Output:**

```plaintext
50
```

**Explanation:**
We choose the last item (value = 50, weight = 3), resulting in a total value of **50**.

### Constraints

- `2 ≤ val.size() = wt.size() ≤ 1000`
- `1 ≤ capacity ≤ 1000`
- `1 ≤ val[i] ≤ 1000`
- `1 ≤ wt[i] ≤ 1000`

---

## Approach

### Recursive Approach

A recursive solution considers two cases for each item:

- **Include the item** if its weight does not exceed the remaining capacity.
- **Exclude the item** and move to the next.

Time Complexity: **O(2^n)** (Exponential)

### Memoization Approach

We use a 2D DP table to store computed results to avoid redundant calculations.

Time Complexity: **O(n × capacity)**
Space Complexity: **O(n × capacity) (for DP table)**

### Tabulation Approach

A bottom-up dynamic programming approach that fills a DP table iteratively.

Time Complexity: **O(n × capacity)**
Space Complexity: **O(n × capacity)**

### Optimized Tabulation Approaches

To improve space efficiency:

1. **`tabulation_optimized()`**: Uses two 1D arrays instead of a 2D DP table.
2. **`tabulation_optimized_better()`**: Uses a single 1D array and iterates backward to avoid overwriting values prematurely.
3. **`tabulation_optimized_single()`**: The most optimized version using only a single DP array.

Time Complexity: **O(n × capacity)**
Space Complexity: **O(capacity)**

---

## Complexity Analysis

| Approach                     | Time Complexity | Space Complexity       |
| ---------------------------- | --------------- | ---------------------- |
| Recursive                    | O(2^n)          | O(n) (Recursion Stack) |
| Memoization (Top-Down)       | O(n × capacity) | O(n × capacity)        |
| Tabulation (Bottom-Up)       | O(n × capacity) | O(n × capacity)        |
| Optimized Tabulation (1D DP) | O(n × capacity) | O(capacity)            |

---

## Implementation

### C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursive_solution(int index, int W, vector<int> &wt, vector<int> &val) {
        if (index == 0) return (wt[0] <= W) ? val[0] : 0;
        int not_take = recursive_solution(index - 1, W, wt, val);
        int take = (wt[index] <= W) ? val[index] + recursive_solution(index - 1, W - wt[index], wt, val) : INT_MIN;
        return max(not_take, take);
    }

    int tabulation_optimized_single(int n, int capacity, vector<int> &wt, vector<int> &val) {
        vector<int> dp(capacity + 1, 0);
        for (int W = wt[0]; W <= capacity; W++) dp[W] = val[0];
        for (int index = 1; index < n; index++) {
            for (int W = capacity; W >= 0; W--) {
                int not_take = dp[W];
                int take = (wt[index] <= W) ? val[index] + dp[W - wt[index]] : 0;
                dp[W] = max(not_take, take);
            }
        }
        return dp[capacity];
    }

    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
        return tabulation_optimized_single(n, capacity, wt, val);
    }
};

int main() {
    int testCases;
    cin >> testCases;
    while (testCases--) {
        int capacity, numberOfItems;
        cin >> capacity >> numberOfItems;
        vector<int> values(numberOfItems), weights(numberOfItems);
        for (int i = 0; i < numberOfItems; i++) cin >> values[i];
        for (int i = 0; i < numberOfItems; i++) cin >> weights[i];
        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
    }
    return 0;
}
```

---

## How to Run the Code

1. Compile using:

   ```bash
   g++ knapsack.cpp -o knapsack
   ```

2. Run the program:

   ```bash
   ./knapsack
   ```

3. Input test cases as specified in the examples.

## Other Solutions

### My Submission

```cpp
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int recursive_solution(int index, int W, vector<int> &wt, vector<int> &val)
    {
        if(index == 0)
        {
            if(wt[0] <= W) return val[0];
            return 0;
        }

        int not_take = recursive_solution(index -1, W, wt, val);
        int take = (wt[index] <= W) ? val[index] + recursive_solution(index -1, W - wt[index], wt, val) : INT_MIN;

        return max(not_take, take);
    }

    int memoization(int index, int W, vector<int> &wt, vector<int> &val, vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(wt[0] <= W) return val[0];
            return 0;
        }

        if(dp[index][W] != -1) return dp[index][W];

        int not_take = memoization(index-1, W, wt, val, dp);
        int take = (wt[index] <= W) ? val[index] + memoization(index -1, W - wt[index], wt, val, dp) : INT_MIN;

        return dp[index][W] = max(not_take, take);
    }

    // Tabulation Approach (Bottom-Up DP)
    int tabulation(int n, int capacity, vector<int> &wt, vector<int> &val) {
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base Case: Filling first row
        for (int W = wt[0]; W <= capacity; W++) {
            dp[0][W] = val[0];
        }

        // Filling DP Table
        for (int index = 1; index < n; index++) {
            for (int W = 0; W <= capacity; W++) {
                int not_take = dp[index - 1][W];
                int take = (wt[index] <= W) ? val[index] + dp[index - 1][W - wt[index]] : 0;
                dp[index][W] = max(not_take, take);
            }
        }

        return dp[n - 1][capacity];
    }

    // Tabulation Approach Optimized (Bottom-Up DP)
    int tabulation_optimized(int n, int capacity, vector<int> &wt, vector<int> &val) {
        vector<int> dp(capacity + 1, 0), current(capacity + 1, 0);

        // Base Case: Filling first row
        for (int W = wt[0]; W <= capacity; W++) {
            dp[W] = val[0];
        }

        // Filling DP Table
        for (int index = 1; index < n; index++) {
            for (int W = 0; W <= capacity; W++) {
                int not_take = dp[W];
                int take = (wt[index] <= W) ? val[index] + dp[W - wt[index]] : 0;
                current[W] = max(not_take, take);
            }
            dp = current;
        }

        return dp[capacity];
    }

    // Tabulation Approach Optimized (Bottom-Up DP)
    int tabulation_optimized_better(int n, int capacity, vector<int> &wt, vector<int> &val) {
        vector<int> dp(capacity + 1, 0), current(capacity + 1, 0);

        // Base Case: Filling first row
        for (int W = wt[0]; W <= capacity; W++) {
            dp[W] = val[0];
        }

        // Filling DP Table
        for (int index = 1; index < n; index++) {
            for (int W = capacity; W >= 0; W--) {
                int not_take = dp[W];
                int take = (wt[index] <= W) ? val[index] + dp[W - wt[index]] : 0;
                current[W] = max(not_take, take);
            }
            dp = current;
        }

        return dp[capacity];
    }

    // Tabulation Approach Optimized (Bottom-Up DP)
    int tabulation_optimized_single(int n, int capacity, vector<int> &wt, vector<int> &val) {
        vector<int> dp(capacity + 1, 0);

        // Base Case: Filling first row
        for (int W = wt[0]; W <= capacity; W++) {
            dp[W] = val[0];
        }

        // Filling DP Table
        for (int index = 1; index < n; index++) {
            for (int W = capacity; W >= 0; W--) {
                int not_take = dp[W];
                int take = (wt[index] <= W) ? val[index] + dp[W - wt[index]] : 0;
                dp[W] = max(not_take, take);
            }
        }

        return dp[capacity];
    }

    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {

        int n = wt.size();

        // vector<vector<int>> dp(n, vector<int>(capacity+1, -1));

        // return memoization(n-1, capacity, wt, val, dp);

        return tabulation_optimized_single(n, capacity, wt, val);
    }
};
```
