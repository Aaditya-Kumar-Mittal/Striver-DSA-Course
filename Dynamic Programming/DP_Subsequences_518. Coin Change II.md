# Coin Change II

## Table of Contents

- [Coin Change II](#coin-change-ii)
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
    - [Main Function](#main-function)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Summary](#summary)
  - [Other Solution](#other-solution)
    - [My Leetcode Submission](#my-leetcode-submission)
  - [Solution - 2](#solution---2)
  - [Solution - 3](#solution---3)
  - [Solution - 4](#solution---4)

---

## Introduction

The **Coin Change II** problem requires us to find the number of ways we can form a given amount using an infinite supply of coins with given denominations. The order of coins does not matter.

---

## Problem Description

Given an integer array `coins` representing different coin denominations and an integer `amount` representing the total sum, return the number of unique combinations that sum up to `amount`. If it's impossible to make up the amount, return `0`.

The answer is guaranteed to fit within a **signed 32-bit integer**.

### Examples

#### Example 1

**Input:**

```cpp
amount = 5
coins = [1,2,5]
```

**Output:**

```cpp
4
```

**Explanation:** The four possible ways to make up the amount:

```bash
5 = 5
5 = 2 + 2 + 1
5 = 2 + 1 + 1 + 1
5 = 1 + 1 + 1 + 1 + 1
```

#### Example 2

**Input:**

```cpp
amount = 3
coins = [2]
```

**Output:**

```cpp
0
```

**Explanation:** The amount 3 cannot be formed using only coin 2.

#### Example 3

**Input:**

```cpp
amount = 10
coins = [10]
```

**Output:**

```cpp
1
```

**Explanation:** There is only one way to form 10 using a single 10-value coin.

### Constraints

- `1 <= coins.length <= 300`
- `1 <= coins[i] <= 5000`
- All `coins` values are **unique**.
- `0 <= amount <= 5000`

---

## Approach

We can solve this problem using **three main approaches:**

1. **Recursion:** Directly explore all possible ways.
2. **Memoization (Top-down Dynamic Programming):** Store already computed results to avoid recomputation.
3. **Tabulation (Bottom-up Dynamic Programming):** Use a 2D or 1D table to iteratively compute the results.

---

## Detailed Explanation of Code

### Recursive Approach

```cpp
int recursive_solution(int index, int amount, vector<int>& coins) {
    if (index == 0) {
        return amount % coins[0] == 0; // If the amount is exactly divisible by the smallest coin
    }
    int notCount = recursive_solution(index - 1, amount, coins);
    int count = (coins[index] <= amount) ? recursive_solution(index, amount - coins[index], coins) : 0;
    return notCount + count;
}
```

**Explanation:**

- Base case: If only one type of coin is left (`index == 0`), check if `amount` is divisible.
- Try both possibilities:
  - **Exclude the current coin** (`notCount`).
  - **Include the current coin** (`count`).
- Return the sum of both possibilities.
- **Time Complexity:** Exponential `O(2^N)`, as it explores all possible subsets.

---

### Memoization Approach

```cpp
int memoization(int index, int amount, vector<int>& coins, vector<vector<int>>& dp) {
    if (index == 0) {
        return amount % coins[0] == 0;
    }
    if (dp[index][amount] != -1) return dp[index][amount];
    int notCount = memoization(index - 1, amount, coins, dp);
    int count = (coins[index] <= amount) ? memoization(index, amount - coins[index], coins, dp) : 0;
    return dp[index][amount] = notCount + count;
}
```

**Explanation:**

- Uses a 2D `dp` table (`dp[index][amount]`) to store precomputed results and avoid recomputation.
- Reduces time complexity by avoiding redundant calculations.
- **Time Complexity:** `O(N * amount)`, where `N` is the number of coins.
- **Space Complexity:** `O(N * amount)`, due to the memoization table.

---

### Main Function

```cpp
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return memoization(n - 1, amount, coins, dp);
}
```

**Explanation:**

- Initializes a `dp` table with `-1`.
- Calls memoization to compute results efficiently.
- **Time Complexity:** `O(N * amount)`, optimized over the recursive approach.
- **Space Complexity:** `O(N * amount)`, due to the `dp` table.

---

## Complexity Analysis

| Approach    | Time Complexity | Space Complexity         |
| ----------- | --------------- | ------------------------ |
| Recursion   | `O(2^N)`        | `O(N)` (recursive stack) |
| Memoization | `O(N * amount)` | `O(N * amount)`          |
| Tabulation  | `O(N * amount)` | `O(amount)` (optimized)  |

---

## How to Run the Code

### For C++

1. Compile the C++ code using:

   ```sh
   g++ -o coin_change coin_change.cpp
   ```

2. Run the compiled executable:

   ```sh
   ./coin_change
   ```

### For Java

1. Compile the Java program:

   ```sh
   javac CoinChange.java
   ```

2. Run the compiled class:

   ```sh
   java CoinChange
   ```

---

## Summary

- **Recursive solution** works but is inefficient.
- **Memoization** improves efficiency by caching results.
- **Tabulation (bottom-up DP)** is the most optimized approach.
- **Space optimization** can be further achieved by reducing the 2D `dp` array to a 1D array.

## Other Solution

### My Leetcode Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int amount, vector<int>& coins) {
        if (index == 0)
            return amount % coins[0] == 0;

        int notCount = recursive_solution(index - 1, amount, coins);
        int count =
            (coins[index] <= amount)
                ? recursive_solution(index, amount - coins[index], coins)
                : 0;

        return (notCount + count) % MOD;
    }

    int memoization(int index, int amount, vector<int>& coins,
                    vector<vector<int>>& dp) {
        if (index == 0)
            return amount % coins[0] == 0;

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int notCount = memoization(index - 1, amount, coins, dp);
        int count = (coins[index] <= amount)
                        ? memoization(index, amount - coins[index], coins, dp)
                        : 0;

        return dp[index][amount] = (notCount + count) % MOD;
    }

    long tabulation_optimized(int n, int amount, vector<int>& coins) {
        if (amount == 0)
            return 1;

        if (n == 0)
            return 0;

        vector<long> prev(amount + 1, 0), curr(amount + 1, 0);

        // Base case: Fill the first row for the smallest coin
        for (int T = 0; T <= amount; T++) {
            prev[T] = (T % coins[0] == 0);
        }

        // Iterate over each coin type
        for (int index = 1; index < n; index++) {
            for (int T = 0; T <= amount; T++) {
                long notCount = prev[T]; // Not taking the current coin
                long count = (coins[index] <= T) ? curr[T - coins[index]] : 0;
                curr[T] =
                    (notCount + count); // Take modulo to prevent overflow
            }
            prev = curr; // Update previous row for next iteration
        }

        return prev[amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return tabulation_optimized(n, amount, coins);
    }
};
```

## Solution - 2

```java
    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length+1][amount+1];
        dp[0][0] = 1;

        for (int i = 1; i <= coins.length; i++) {
            dp[i][0] = 1;
            for (int j = 1; j <= amount; j++) {
                dp[i][j] = dp[i-1][j] + (j >= coins[i-1] ? dp[i][j-coins[i-1]] : 0);
            }
        }
        return dp[coins.length][amount];
    }
```

```java
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                dp[i] += dp[i-coin];
            }
        }
        return dp[amount];
    }
```

```java
    private Integer[][] dp;
    public int change(int amount, int[] coins) {
        if (amount == 0)
            return 1;
        if (coins.length == 0)
            return 0;
        dp = new Integer[coins.length][amount + 1];
        return changeFrom(amount, coins, 0);
    }

    private int changeFrom(int amount, int[] coins, int currentIndex) {
        if (amount == 0)
          return 1;

        if (amount < 0 || currentIndex == coins.length)
          return 0;

        if (dp[currentIndex][amount] != null)
            return dp[currentIndex][amount];

        // Recursive call after selecting the coin at the currentIndex
        int sum1 = changeFrom(amount - coins[currentIndex], coins, currentIndex);

        // Recursive call after excluding the coin at the currentIndex
        int sum2 = changeFrom(amount, coins, currentIndex + 1);

        dp[currentIndex][amount] = sum1 + sum2;
        return dp[currentIndex][amount];
    }
```

```java
    public int change(int amount, int[] coins) {
        int[][] dp = new int[coins.length + 1][amount + 1];
        dp[0][0] = 1;
        for (int j = 1; j <= coins.length; j++) {
            dp[j][0] = 1;
            for (int i = 1; i <= amount; i++) {
                dp[j][i] = dp[j - 1][i];
                if (i - coins[j - 1] >= 0) {
                    dp[j][i] += dp[j][i - coins[j - 1]];
                }
            }
        }
        return dp[coins.length][amount];
    }
```

```java
    public int change(int amount, int[] coins) {
        int[] dp = new int[amount + 1];
        dp[0] = 1;
        for (int j = 0; j < coins.length; j++) {
            for (int i = 1; i <= amount; i++) {
                if (i - coins[j] >= 0) {
                    dp[i] += dp[i - coins[j]];
                }
            }
        }
        return dp[amount];
    }
```

## Solution - 3

1. Recursion

   ```cpp
   class Solution {
   public:

    int coinChange(vector<int>& coins, int n, int amount)
    {
        if(n==0)
            return 0;
        if(amount == 0)
        {
            return 1;
        }
        if(coins[n-1] > amount)
        {
            return coinChange(coins, n-1, amount);
        }
        return coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
            return 0;
        return coinChange(coins, n, amount);

    }
   };
   ```

2. Memoization

   ```cpp
   class Solution {
   public:
    vector<vector<int>> dp;
    int coinChange(vector<int>& coins, int n, int amount)
    {
        if(n==0)
            return 0;
        if(amount == 0)
        {
            return 1;
        }
        if(dp[n][amount] != -1)
        {
            return dp[n][amount];
        }
        if(coins[n-1] > amount)
        {
            dp[n][amount] = coinChange(coins, n-1, amount);
            return dp[n][amount];
        }
        dp[n][amount] = coinChange(coins, n, amount-coins[n-1]) + coinChange(coins, n-1, amount);
        return dp[n][amount];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;

        dp.resize(n+2,vector<int>(amount+2,-1));

        dp[n][amount] = coinChange(coins, n, amount);
        return dp[n][amount];

    }
   };
   ```

3. Tabulation

   ```cpp
   class Solution {
   public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if(amount == 0) {
            return 1;
        }
        if(n==0)
          return 0;
        vector<vector<int>> dp;
        dp.resize(n+2,vector<int>(amount+2,-1));

        for(int i=0;i<n+1;i++)
        {
            dp[i][0] = 1;
        }

        for(int i=0;i<amount+1;i++)
        {
            dp[0][i] = 0;
        }

        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<amount+1;j++)
            {
                if(coins[i-1] > j) {
                    dp[i][j] = dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j]+dp[i][j-coins[i-1]];
                }
            }
        }
        return dp[n][amount];

    }
   };
   ```

## Solution - 4

```cpp
int change(int t, vector<int>& cs) {
  int dp[5001] = { 1 };
  for (auto c : cs)
    for (auto j = c; j <= t; ++j) dp[j] += dp[j - c];
  return dp[t];
}
```
