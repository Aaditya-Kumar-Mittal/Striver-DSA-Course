# Best Time to Buy and Sell Stock with Cooldown

## Table of Contents

- [Best Time to Buy and Sell Stock with Cooldown](#best-time-to-buy-and-sell-stock-with-cooldown)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Solution](#recursive-solution)
    - [Memoization (Top-Down DP)](#memoization-top-down-dp)
    - [Tabulation (Bottom-Up DP)](#tabulation-bottom-up-dp)
    - [Tabulation Optimized](#tabulation-optimized)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)

---

## Introduction

The problem requires finding the maximum profit that can be achieved by buying and selling stocks while adhering to a cooldown period of one day after selling.

---

## Problem Description

You are given an array `prices` where `prices[i]` represents the price of a stock on the `i-th` day. You can complete as many transactions as you like, but after selling a stock, you must wait for one day (cooldown) before buying again.

### Examples

#### Example 1

**Input:**

```cpp
prices = [1,2,3,0,2]
```

**Output:**

```cpp
3
```

**Explanation:**
Transactions: `[buy, sell, cooldown, buy, sell]`.

#### Example 2

**Input:**

```cpp
prices = [1]
```

**Output:**

```cpp
0
```

### Constraints

- `1 <= prices.length <= 5000`
- `0 <= prices[i] <= 1000`

---

## Approach

We use Dynamic Programming (DP) to solve the problem efficiently. The different approaches include:

1. **Recursive Solution** (Brute Force)
2. **Memoization (Top-Down DP)**
3. **Tabulation (Bottom-Up DP)**
4. **Tabulation Optimized** (Space-Optimized DP)

---

## Detailed Explanation of Code

### Recursive Solution

```cpp
class Solution {
public:
    int recursive_solution(int index, int buy, int n, vector<int>& prices) {
        if (index >= n)
            return 0;

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + recursive_solution(index + 1, 0, n, prices),
                         recursive_solution(index + 1, 1, n, prices));
        } else {
            profit = max(prices[index] + recursive_solution(index + 2, 1, n, prices),
                         recursive_solution(index + 1, 0, n, prices));
        }
        return profit;
    }
};
```

### Memoization (Top-Down DP)

```cpp
class Solution {
public:
    int memoization(int index, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
        if (index >= n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;
        if (buy) {
            profit = max(-prices[index] + memoization(index + 1, 0, n, prices, dp),
                         memoization(index + 1, 1, n, prices, dp));
        } else {
            profit = max(prices[index] + memoization(index + 2, 1, n, prices, dp),
                         memoization(index + 1, 0, n, prices, dp));
        }
        return dp[index][buy] = profit;
    }
};
```

### Tabulation (Bottom-Up DP)

```cpp
class Solution {
public:
    int tabulation(int n, vector<int>& prices) {
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                } else {
                    dp[ind][buy] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
                }
            }
        }
        return dp[0][1];
    }
};
```

### Tabulation Optimized

```cpp
class Solution {
public:
    int tabulation_optimized(int n, vector<int>& prices) {
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int ind = n - 1; ind >= 0; ind--) {
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
        }
        return dp[0][1];
    }
};
```

---

## Complexity Analysis

| Approach               | Time Complexity | Space Complexity       |
| ---------------------- | --------------- | ---------------------- |
| Recursive Solution     | O(2^N)          | O(N) (recursion depth) |
| Memoization (Top-Down) | O(N)            | O(N) (DP table)        |
| Tabulation (Bottom-Up) | O(N)            | O(N) (DP table)        |
| Tabulation Optimized   | O(N)            | O(1) (Optimized DP)    |

The best approach is **Tabulation Optimized**, which runs in **O(N) time** and uses **O(1) space**.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `solution.cpp`.
2. Compile the code using:

   ```sh
   g++ -o solution solution.cpp
   ```

3. Run the executable:

   ```sh
   ./solution
   ```

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int buy, int n, vector<int>& prices) {
        // Base case: If we reach or exceed the end of the prices array, return
        // 0
        if (index >= n)
            return 0;

        int profit = 0;

        if (buy) {
            // If we are buying, we have two choices:
            // 1. Buy the stock at the current price and move to the next day
            // 2. Skip buying and move to the next day
            profit = max(-prices[index] +
                             recursive_solution(index + 1, 0, n, prices),
                         recursive_solution(index + 1, 1, n, prices));
        } else {
            // If we are selling, we have two choices:
            // 1. Sell the stock at the current price and move to index + 2
            // (cooldown)
            // 2. Skip selling and move to the next day
            profit =
                max(prices[index] + recursive_solution(index + 2, 1, n, prices),
                    recursive_solution(index + 1, 0, n, prices));
        }

        return profit;
    }

    int memoization(int index, int buy, int n, vector<int>& prices,
                    vector<vector<int>>& dp) {
        // Base case: If we reach or exceed the end of the prices array, return
        // 0
        if (index >= n)
            return 0;

        // If the result is already computed, return it
        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if (buy) {
            // If we are buying, we have two choices:
            // 1. Buy the stock at the current price and move to the next day
            // 2. Skip buying and move to the next day
            profit =
                max(-prices[index] + memoization(index + 1, 0, n, prices, dp),
                    memoization(index + 1, 1, n, prices, dp));
        } else {
            // If we are selling, we have two choices:
            // 1. Sell the stock at the current price and move to index + 2
            // (cooldown)
            // 2. Skip selling and move to the next day
            profit =
                max(prices[index] + memoization(index + 2, 1, n, prices, dp),
                    memoization(index + 1, 0, n, prices, dp));
        }

        // Store the result in the DP table and return
        return dp[index][buy] = profit;
    }

    int tabulation(int n, vector<int>& prices) {
        // DP table to store maximum profit at each state
        // dp[ind][buy]: max profit at index `ind` with `buy` state (0 or 1)
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Fill the DP table from the end to the beginning
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    // If we can buy, choose between buying or skipping
                    dp[ind][buy] =
                        max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
                } else {
                    // If we can sell, choose between selling or skipping
                    dp[ind][buy] =
                        max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
                }
            }
        }

        // Return the maximum profit when starting from the first day with the
        // ability to buy
        return dp[0][1];
    }

    int tabulation_optimized(int n, vector<int>& prices) {
        // DP table to store maximum profit at each state
        // dp[ind][buy]: max profit at index `ind` with `buy` state (0 or 1)
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        // Fill the DP table from the end to the beginning
        for (int ind = n - 1; ind >= 0; ind--) {

            // If we can buy, choose between buying or skipping
            dp[ind][1] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);

            // If we can sell, choose between selling or skipping
            dp[ind][0] = max(prices[ind] + dp[ind + 2][1], dp[ind + 1][0]);
        }

        // Return the maximum profit when starting from the first day with the
        // ability to buy
        return dp[0][1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // return recursive_solution(0, 1, n, prices);

        /*
                // DP table with dimensions [index][buy]
                        // Initialize with -1
                                vector<vector<int>> dp(n, vector<int>(2, -1));

                                        // Start with index = 0, buy = 1 (can
           buy) return memoization(0, 1, n, prices, dp);
                                                        */

        return tabulation_optimized(n, prices);
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
 int maxProfit(vector<int>& prices){
  if (prices.size() <= 1) return 0;
  vector<int> s0(prices.size(), 0);
  vector<int> s1(prices.size(), 0);
  vector<int> s2(prices.size(), 0);
  s1[0] = -prices[0];
  s0[0] = 0;
  s2[0] = INT_MIN;
  for (int i = 1; i < prices.size(); i++) {
   s0[i] = max(s0[i - 1], s2[i - 1]);
   s1[i] = max(s1[i - 1], s0[i - 1] - prices[i]);
   s2[i] = s1[i - 1] + prices[i];
  }
  return max(s0[prices.size() - 1], s2[prices.size() - 1]);
 }
};
```

### Solution - 3

```cpp
int maxProfit(vector<int> &prices) {
    int buy(INT_MIN), sell(0), prev_sell(0), prev_buy;
    for (int price : prices) {
        prev_buy = buy;
        buy = max(prev_sell - price, buy);
        prev_sell = sell;
        sell = max(prev_buy + price, sell);
    }
    return sell;
}
```
