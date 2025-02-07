# Best Time to Buy and Sell Stock with Transaction Fee

## Table of Contents

- [Best Time to Buy and Sell Stock with Transaction Fee](#best-time-to-buy-and-sell-stock-with-transaction-fee)
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
    - [Memoization](#memoization)
    - [Tabulation](#tabulation)
    - [Optimized Tabulation](#optimized-tabulation)
    - [Final Function](#final-function)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solution](#other-solution)
    - [My Submission](#my-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)

## Introduction

This document provides a comprehensive explanation of the solution for the problem "Best Time to Buy and Sell Stock with Transaction Fee" (LeetCode 714). The goal is to maximize profit while buying and selling stocks, given that each transaction incurs a fee.

## Problem Description

Given an array `prices[]` where `prices[i]` represents the price of a stock on the `i`th day, and an integer `fee` representing the transaction fee for each transaction, determine the maximum profit that can be achieved.

### Examples

#### Example 1

**Input:**

```cpp
prices = [1,3,2,8,4,9]
fee = 2
```

**Output:**

```cpp
8
```

**Explanation:**
Transactions:

- Buy at `1`, Sell at `8` (Profit: 7, after fee: 5)
- Buy at `4`, Sell at `9` (Profit: 5, after fee: 3)
  Total Profit: `5 + 3 = 8`

#### Example 2

**Input:**

```cpp
prices = [1,3,7,5,10,3]
fee = 3
```

**Output:**

```cpp
6
```

### Constraints

- `1 <= prices.length <= 5 * 10^4`
- `1 <= prices[i] < 5 * 10^4`
- `0 <= fee < 5 * 10^4`

## Approach

The solution is approached in four ways:

1. **Recursive Approach** - A brute force approach to check all possibilities.
2. **Memoization** - Optimizing recursion with caching.
3. **Tabulation** - Using bottom-up dynamic programming.
4. **Optimized Tabulation** - Reducing space complexity further.

## Detailed Explanation of Code

### Recursive Solution

```cpp
int recursive_solution(int index, int buy, int n, vector<int>& prices) {
    if (index == n)
        return 0;
    int profit = 0;
    if (buy) {
        profit = max(-prices[index] + recursive_solution(index + 1, 0, n, prices),
                     recursive_solution(index + 1, 1, n, prices));
    } else {
        profit = max(prices[index] + recursive_solution(index + 1, 1, n, prices),
                     recursive_solution(index + 1, 0, n, prices));
    }
    return profit;
}
```

### Memoization

```cpp
int memoization(int index, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
    if (index == n)
        return 0;
    if (dp[index][buy] != -1)
        return dp[index][buy];
    int profit = 0;
    if (buy) {
        profit = max(-prices[index] + memoization(index + 1, 0, n, prices, dp),
                     memoization(index + 1, 1, n, prices, dp));
    } else {
        profit = max(prices[index] + memoization(index + 1, 1, n, prices, dp),
                     memoization(index + 1, 0, n, prices, dp));
    }
    return dp[index][buy] = profit;
}
```

### Tabulation

```cpp
int tabulation(int n, vector<int>& prices) {
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            if (buy) {
                dp[ind][buy] = max(-prices[ind] + dp[ind + 1][0], dp[ind + 1][1]);
            } else {
                dp[ind][buy] = max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
            }
        }
    }
    return dp[0][1];
}
```

### Optimized Tabulation

```cpp
int tabulation_optimized(int n, int fee, vector<int>& prices) {
    vector<int> dp(2, 0), current(2, 0);
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            if (buy) {
                current[buy] = max(-prices[ind] + dp[0], dp[1]);
            } else {
                current[buy] = max(prices[ind] + dp[1] - fee, dp[0]);
            }
        }
        dp = current;
    }
    return current[1];
}
```

### Final Function

```cpp
int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    return tabulation_optimized(n, fee, prices);
}
```

## Complexity Analysis

| Approach             | Time Complexity | Space Complexity      |
| -------------------- | --------------- | --------------------- |
| Recursive Solution   | O(2^n)          | O(n) (call stack)     |
| Memoization          | O(n\*2)         | O(n\*2) (DP table)    |
| Tabulation           | O(n\*2)         | O(n\*2) (DP table)    |
| Optimized Tabulation | O(n)            | O(1) (Constant space) |

## How to Run the Code

1. **Compile and run the C++ program:**

   ```sh
   g++ solution.cpp -o solution
   ./solution
   ```

2. **Pass test cases within the `main()` function**
3. **Example input in `main()`**:

   ```cpp
   vector<int> prices = {1, 3, 2, 8, 4, 9};
   int fee = 2;
   cout << maxProfit(prices, fee) << endl;
   ```

This concludes the documentation for "Best Time to Buy and Sell Stock with Transaction Fee" with multiple approaches and optimizations.

## Other Solution

### My Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int buy, int n, vector<int>& prices) {
        // Base case: If we reach the end of the prices array, return 0
        if (index == n)
            return 0;

        int profit = 0;

        if (buy) {
            // If we are buying, we have two choices:
            // 1. Buy the stock at the current price and move to the next day
            // (cannot buy again until we sell)
            // 2. Skip buying and move to the next day
            profit = max(-prices[index] +
                             recursive_solution(index + 1, 0, n, prices),
                         recursive_solution(index + 1, 1, n, prices));
        } else {
            // If we are selling, we have two choices:
            // 1. Sell the stock at the current price and move to the next day
            // (can buy again)
            // 2. Skip selling and move to the next day
            profit =
                max(prices[index] + recursive_solution(index + 1, 1, n, prices),
                    recursive_solution(index + 1, 0, n, prices));
        }

        return profit;
    }

    int memoization(int index, int buy, int n, vector<int>& prices,
                    vector<vector<int>>& dp) {
        // Base case: If we reach the end of the prices array, return 0
        if (index == n)
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        int profit = 0;

        if (buy) {
            // If we are buying, we have two choices:
            // 1. Buy the stock at the current price and move to the next day
            // (cannot buy again until we sell)
            // 2. Skip buying and move to the next day
            profit =
                max(-prices[index] + memoization(index + 1, 0, n, prices, dp),
                    memoization(index + 1, 1, n, prices, dp));
        } else {
            // If we are selling, we have two choices:
            // 1. Sell the stock at the current price and move to the next day
            // (can buy again)
            // 2. Skip selling and move to the next day
            profit =
                max(prices[index] + memoization(index + 1, 1, n, prices, dp),
                    memoization(index + 1, 0, n, prices, dp));
        }

        return dp[index][buy] = profit;
    }

    int tabulation(int n, vector<int>& prices) {
        // DP table to store maximum profit at each state
        // dp[ind][buy]: max profit at index `ind` with `buy` state (0 or 1)
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        // Base case: No profit can be made after the last day
        dp[n][0] = dp[n][1] = 0;

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
                        max(prices[ind] + dp[ind + 1][1], dp[ind + 1][0]);
                }
            }
        }

        // Return the maximum profit when starting from the first day with the
        // ability to buy
        return dp[0][1];
    }

    int tabulation_optimized(int n, int fee, vector<int>& prices) {
        // DP table to store maximum profit at each state
        // dp[ind][buy]: max profit at index `ind` with `buy` state (0 or 1)
        // Base case: No profit can be made after the last day
        vector<int> dp(2, 0), current(2, 0);

        // Fill the DP table from the end to the beginning
        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy < 2; buy++) {
                if (buy) {
                    // If we can buy, choose between buying or skipping
                    current[buy] = max(-prices[ind] + dp[0], dp[1]);
                } else {
                    // If we can sell, choose between selling or skipping
                    current[buy] = max(prices[ind] + dp[1] - fee, dp[0]);
                }
                dp = current;
            }
        }

        // Return the maximum profit when starting from the first day with the
        // ability to buy
        return current[1];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        return tabulation_optimized(n, fee, prices);
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n <= 1) return 0;
        int buy = -prices[0];
        int sell = 0;
        for (int i = 1; i < n; i++) {
            int prevBuy = buy;
            buy = max(buy, sell - prices[i]);
            sell = max(sell, prevBuy + prices[i] - fee);
        }
        return sell;
    }
};
```

### Solution - 3

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int buy = INT_MIN;  // max profit if you end the day with a stock bought
        int sell = 0;       // max profit if you end the day with a stock sold
        for (int price: prices) {
            buy = max(buy, sell - price);   // either keep the current stock, or buy a new stock if not own
            sell = max(sell, buy + price - fee);    // either do nothing, or sell the current stock owned
        }
        return sell;
    }
};
```

### Solution - 4

```cpp
class Solution {
public:

    int lastDay  ;
    int dp[50001][2] ;
    int Fees ;

    int maxProfits( int day, int transaction, vector<int>& prices ){

        if(  day >= lastDay ){
            return 0 ;
        }

        if( dp[day][transaction] != -1){
            return dp[day][transaction] ;
        }

        int profit = 0 ;
        if( transaction == 0 ){                                                         // 0 means buy
            profit = maxProfits( day+1, 1, prices ) - prices[day] ;
            profit = max( profit, maxProfits( day+1, transaction, prices) ) ;
        }
        else{                                                                       // 1 means sell
            profit = maxProfits( day+1, 0, prices ) + prices[day] - Fees ;
            profit = max( profit, maxProfits( day+1, transaction, prices) ) ;
        }

        return dp[day][transaction] = profit ;
    }

    int maxProfit(vector<int>& prices, int fee) {
        Fees = fee ;
        lastDay = prices.size() ;
        memset(dp, -1, sizeof(dp)) ;
        return maxProfits(0, 0, prices) ;
    }
};
```
