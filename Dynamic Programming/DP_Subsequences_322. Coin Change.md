# Coin Change Problem

## Table of Contents

- [Coin Change Problem](#coin-change-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Return](#return)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Solution](#recursive-solution)
    - [Memoization](#memoization)
    - [Tabulation](#tabulation)
    - [Tabulation Optimized (Using 1D Array)](#tabulation-optimized-using-1d-array)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My LeetCode Submission](#my-leetcode-submission)

## Introduction

The **Coin Change Problem** is a well-known problem in dynamic programming where we need to determine the minimum number of coins required to make up a given amount using given denominations. If the amount cannot be made up, return `-1`.

## Problem Description

### Given

- An integer array `coins` representing coins of different denominations.
- An integer `amount` representing a total sum.

### Return

- The fewest number of coins needed to make up `amount`.
- If it is not possible, return `-1`.

### Examples

#### Example 1

**Input:**

```cpp
coins = [1,2,5], amount = 11
```

**Output:**

```cpp
3
```

**Explanation:** 11 = 5 + 5 + 1

#### Example 2

**Input:**

```cpp
coins = [2], amount = 3
```

**Output:**

```cpp
-1
```

#### Example 3

**Input:**

```cpp
coins = [1], amount = 0
```

**Output:**

```cpp
0
```

### Constraints

- `1 <= coins.length <= 12`
- `1 <= coins[i] <= 2^31 - 1`
- `0 <= amount <= 10^4`

## Approach

The problem can be solved using **Dynamic Programming (DP)**. The different approaches include:

1. **Recursive Approach** (Brute Force)
2. **Memoization** (Top-Down DP)
3. **Tabulation** (Bottom-Up DP)
4. **Optimized Tabulation** (Using Less Space)
5. **Most Optimized DP Approach** (Single Array DP)

## Detailed Explanation of Code

### Recursive Solution

- A simple recursive approach explores all possibilities by either including or excluding a coin.
- It results in **exponential time complexity** due to overlapping subproblems.

```cpp
int recursive_solution(int index, int amount, vector<int>& coins) {
    if (index == 0) {
        return (amount % coins[0] == 0) ? amount / coins[0] : 1e9;
    }
    int notCount = recursive_solution(index - 1, amount, coins);
    int count = (coins[index] <= amount) ? 1 + recursive_solution(index, amount - coins[index], coins) : 1e9;
    return min(notCount, count);
}
```

### Memoization

- Stores previously computed values in a 2D table `dp[index][amount]` to avoid redundant calculations.

```cpp
int memoization(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (index == 0) return (amount % coins[0] == 0) ? amount / coins[0] : 1e9;
    if (dp[index][amount] != -1) return dp[index][amount];
    int notCount = memoization(index - 1, amount, coins, dp);
    int count = (coins[index] <= amount) ? 1 + memoization(index, amount - coins[index], coins, dp) : 1e9;
    return dp[index][amount] = min(notCount, count);
}
```

### Tabulation

- Uses a **2D DP table** to iteratively compute solutions.
- Bottom-up approach avoids recursion.

```cpp
int tabulation(int n, int amount, vector<int>& coins) {
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    for (int T = 0; T <= amount; T++) {
        dp[0][T] = (T % coins[0] == 0) ? T / coins[0] : 1e9;
    }
    for (int index = 1; index < n; index++) {
        for (int T = 0; T <= amount; T++) {
            int notCount = dp[index - 1][T];
            int count = (coins[index] <= T) ? 1 + dp[index][T - coins[index]] : 1e9;
            dp[index][T] = min(notCount, count);
        }
    }
    return dp[n - 1][amount];
}
```

### Tabulation Optimized (Using 1D Array)

- Uses a **single 1D array** (`dp`) instead of a full DP table.
- Significantly reduces space complexity.

```cpp
int most_optimized(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin && dp[i - coin] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

## Complexity Analysis

| Approach             | Time Complexity | Space Complexity   |
| -------------------- | --------------- | ------------------ |
| Recursive Solution   | O(2^N)          | O(N) (Stack Space) |
| Memoization          | O(N \* amount)  | O(N \* amount)     |
| Tabulation           | O(N \* amount)  | O(N \* amount)     |
| Tabulation Optimized | O(N \* amount)  | O(amount)          |
| Most Optimized DP    | O(N \* amount)  | O(amount)          |

## How to Run the Code

### For C++

1. Compile the program using:

   ```sh
   g++ coin_change.cpp -o coin_change
   ```

2. Run the executable:

   ```sh
   ./coin_change
   ```

Alternatively, you can use an **online C++ compiler** like [OnlineGDB](https://www.onlinegdb.com/).

---

## Other Solutions

### My LeetCode Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int amount, vector<int>& coins) {

        if (index == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        int notCount = recursive_solution(index - 1, amount, coins);
        int count =
            (coins[index] <= amount)
                ? 1 + recursive_solution(index, amount - coins[index], coins)
                : 1e9;

        return min(notCount, count);
    }

    int tabulation(int n, int amount, vector<int>& coins) {
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0)
                dp[0][T] = T / coins[0];
            else
                dp[0][T] = 1e9;
        }

        for (int index = 1; index < n; index++) {
            for (int T = 0; T <= amount; T++) {

                int notCount = dp[index - 1][T];
                int count =
                    (coins[index] <= T) ? 1 + dp[index][T - coins[index]] : 1e9;
                dp[index][T] = min(notCount, count);
            }
        }

        return dp[n - 1][amount];
    }

    int memoization(int index, int amount, vector<int>& coins,
                    vector<vector<int>>& dp) {

        if (index == 0) {
            if (amount % coins[0] == 0)
                return amount / coins[0];
            return 1e9;
        }

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int notCount = memoization(index - 1, amount, coins, dp);
        int count =
            (coins[index] <= amount)
                ? 1 + memoization(index, amount - coins[index], coins, dp)
                : 1e9;

        return dp[index][amount] = min(notCount, count);
    }

    int tabulation_optimized(int n, int amount, vector<int>& coins) {
        vector<int> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case: Fill the first row for the smallest coin
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0)
                prev[T] =
                    T /
                    coins[0]; // If divisible, store the number of coins needed
            else
                prev[T] = 1e9; // Otherwise, mark as impossible
        }

        // Iterate over each coin type
        for (int index = 1; index < n; index++) {
            for (int T = 0; T <= amount; T++) {
                int notCount = prev[T]; // Not taking the current coin
                int count =
                    (coins[index] <= T) ? 1 + curr[T - coins[index]] : 1e9;
                curr[T] = min(notCount, count); // Store the minimum count
            }
            prev = curr; // Update previous row for next iteration
        }

        return (prev[amount] >= 1e9)
                   ? -1
                   : prev[amount]; // Return -1 if not possible
    }

    int tabulation_optimized_better(int n, int amount, vector<int>& coins) {
        vector<int> prev(amount + 1, 0);

        // Base case: Fill the first row for the smallest coin
        for (int T = 0; T <= amount; T++) {
            if (T % coins[0] == 0)
                prev[T] =
                    T /
                    coins[0]; // If divisible, store the number of coins needed
            else
                prev[T] = 1e9; // Otherwise, mark as impossible
        }

        // Iterate over each coin type
        for (int index = 1; index < n; index++) {
            for (int T = 0; T <= amount; T++) {
                int notCount = prev[T]; // Not taking the current coin
                int count =
                    (coins[index] <= T) ? 1 + prev[T - coins[index]] : 1e9;
                prev[T] = min(notCount, count); // Store the minimum count
            }
        }

        return (prev[amount] >= 1e9)
                   ? -1
                   : prev[amount]; // Return -1 if not possible
    }

    int most_optimized(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0; // Base case: 0 coins are needed to make a sum of 0

        // Build the DP array
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        // Return the result for the given amount
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = tabulation_optimized_better(n, amount, coins);

        if (ans >= 1e9)
            return -1;
        else
            return ans;
    }
};
```
