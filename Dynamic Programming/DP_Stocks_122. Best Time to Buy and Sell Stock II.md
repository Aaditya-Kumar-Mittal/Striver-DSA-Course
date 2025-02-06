# Best Time to Buy and Sell Stock II

## Table of Contents

- [Best Time to Buy and Sell Stock II](#best-time-to-buy-and-sell-stock-ii)
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
    - [Recursive Solution](#recursive-solution)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
    - [Space Optimized Tabulation](#space-optimized-tabulation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)

## Introduction

The problem requires us to find the maximum profit that can be obtained by buying and selling a stock multiple times. You are given an array where each element represents the stock price on a given day, and you can buy and sell multiple times. However, you can only hold at most one share at a time.

## Problem Description

You are given an integer array `prices` where `prices[i]` is the price of a given stock on the `i-th` day. On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

### Examples

#### Example 1

**Input:**

```cpp
prices = [7,1,5,3,6,4]
```

**Output:**

```cpp
7
```

**Explanation:**

- Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = `5 - 1 = 4`.
- Buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = `6 - 3 = 3`.
- Total profit is `4 + 3 = 7`.

#### Example 2

**Input:**

```cpp
prices = [1,2,3,4,5]
```

**Output:**

```cpp
4
```

**Explanation:**

- Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = `5 - 1 = 4`.
- Total profit is `4`.

#### Example 3

**Input:**

```cpp
prices = [7,6,4,3,1]
```

**Output:**

```cpp
0
```

**Explanation:**

- There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of `0`.

### Constraints

- `1 <= prices.length <= 3 * 10^4`
- `0 <= prices[i] <= 10^4`

## Approach

To solve this problem efficiently, we explore four approaches:

1. **Recursive Approach** (Brute Force): Trying all possible cases.
2. **Memoization (Top-Down Dynamic Programming):** Storing the computed results for reuse.
3. **Tabulation (Bottom-Up DP):** Filling a DP table iteratively.
4. **Space Optimized Tabulation:** Optimizing space complexity by using only two arrays.

## Detailed Explanation of Code

### Recursive Solution

The recursive approach explores all possible buy and sell actions at each step.

```cpp
int recursive_solution(int index, int buy, int n, vector<int>& prices) {
    if (index == n) return 0;
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

### Memoization Approach

Using memoization, we store previously computed results to avoid redundant calculations.

```cpp
int memoization(int index, int buy, int n, vector<int>& prices, vector<vector<int>>& dp) {
    if (index == n) return 0;
    if (dp[index][buy] != -1) return dp[index][buy];
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

### Tabulation Approach

We use a bottom-up approach to fill the DP table iteratively.

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

### Space Optimized Tabulation

Instead of using a 2D DP table, we reduce space by maintaining only the last two states.

```cpp
int tabulation_optimized(int n, vector<int>& prices) {
    vector<int> dp(2, 0), current(2, 0);
    for (int ind = n - 1; ind >= 0; ind--) {
        for (int buy = 0; buy < 2; buy++) {
            if (buy) {
                current[buy] = max(-prices[ind] + dp[0], dp[1]);
            } else {
                current[buy] = max(prices[ind] + dp[1], dp[0]);
            }
            dp = current;
        }
    }
    return current[1];
}
```

## Complexity Analysis

| Approach                   | Time Complexity | Space Complexity       |
| -------------------------- | --------------- | ---------------------- |
| Recursive                  | O(2^N)          | O(N) (Recursive Stack) |
| Memoization                | O(N \* 2)       | O(N \* 2)              |
| Tabulation                 | O(N \* 2)       | O(N \* 2)              |
| Space Optimized Tabulation | O(N \* 2)       | O(2)                   |

## How to Run the Code

1. Compile the C++ file:

   ```sh
   g++ -o stock_profit stock_profit.cpp
   ```

2. Run the executable:

   ```sh
   ./stock_profit
   ```

## Other Solutions

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

    int tabulation_optimized(int n, vector<int>& prices) {
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
                    current[buy] = max(prices[ind] + dp[1], dp[0]);
                }
                dp = current;
            }
        }

        // Return the maximum profit when starting from the first day with the
        // ability to buy
        return current[1];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2, -1));
        return tabulation_optimized(n, prices);
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) {
            return 0;
        }
        int profit = 0;
        int buyPrice = prices[0];
        for (int i = 0; i < prices.size() - 1; i++) {
            if (prices[i] > prices[i + 1]) {
                profit += prices[i] - buyPrice;
                buyPrice = prices[i + 1];
            }
        }
        if (prices[prices.size() - 1] > buyPrice) {
            profit += prices[prices.size() - 1] - buyPrice;
        }
        return profit;
    }
};
```

### Solution - 3

```cpp
public int maxProfit(int[] prices) {
        int i = 0, buy, sell, profit = 0, N = prices.length - 1;
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) i++;
            buy = prices[i];

            while (i < N && prices[i + 1] > prices[i]) i++;
            sell = prices[i];

            profit += sell - buy;
        }
        return profit;
}
```

```java
public Pair<List<Pair<Integer, Integer>>, Integer> buysAndSells(int[] prices) {
        int i = 0, iBuy, iSell, profit = 0, N = prices.length - 1;
        List<Pair<Integer, Integer>> buysAndSells = new ArrayList<Pair<Integer, Integer>>();
        while (i < N) {
            while (i < N && prices[i + 1] <= prices[i]) i++;
            iBuy = i;

            while (i < N && prices[i + 1] > prices[i]) i++;
            iSell = i;

            profit += prices[iSell] - prices[iBuy];
            Pair<Integer, Integer> bs = new Pair<Integer, Integer>(iBuy, iSell);
            buysAndSells.add(bs);
        }
        return new Pair<List<Pair<Integer, Integer>>, Integer>(buysAndSells, profit);
}

public class Pair<T1, T2> {
    public T1 fst;
    public T2 snd;
    public Pair(T1 f, T2 s) {
        fst = f;
        snd = s;
    }
}
```

### Solution - 4

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {

        // It is impossible to sell stock on first day, set -infinity as initial value for curHold
        int curHold = INT_MIN, curNotHold = 0;

        for( const int stockPrice : prices ){

            int prevHold = curHold, prevNotHold = curNotHold;

            // either keep hold, or buy in stock today at stock price
            curHold = max( prevHold, prevNotHold - stockPrice );

            // either keep not-hold, or sell out stock today at stock price
            curNotHold = max( prevNotHold, prevHold + stockPrice );
        }

        // Max profit must come from notHold state finally.
        return curNotHold;
    }
};
```

```java
class Solution {
    public int maxProfit(int[] prices) {

        // It is impossible to sell stock on first day, set -infinity as initial value for cur_hold
        int hold = -Integer.MAX_VALUE, notHold = 0;

        for( int stockPrice : prices ){

            int prevHold = hold, prevNotHold = notHold;

            // either keep hold, or buy in stock today at stock price
            hold = Math.max(prevHold, prevNotHold - stockPrice);

            // either keep not-hold, or sell out stock today at stock price
            notHold = Math.max(prevNotHold, prevHold + stockPrice);

        }

        // maximum profit must be in not-hold state
        return notHold;

    }
}
```
