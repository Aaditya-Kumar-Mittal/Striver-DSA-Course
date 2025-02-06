# Best Time to Buy and Sell Stock IV

## Table of Contents

- [Best Time to Buy and Sell Stock IV](#best-time-to-buy-and-sell-stock-iv)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Optimized Tabulation Approach](#optimized-tabulation-approach)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

---

## Introduction

The problem requires us to maximize profit from stock trading, given an array `prices[]` representing stock prices on different days. We are allowed to make at most `k` transactions (each transaction consists of a buy followed by a sell). The challenge is to determine the maximum profit possible while ensuring that we do not hold multiple stocks simultaneously.

---

## Problem Description

We are given:

- An integer `k` representing the maximum number of transactions allowed.
- An integer array `prices[]` where `prices[i]` represents the stock price on the `i`th day.

### Examples

#### Example 1

**Input:**

```cpp
k = 2, prices = [2,4,1]
```

**Output:**

```cpp
2
```

**Explanation:**

- Buy on day 1 (price = 2), sell on day 2 (price = 4), profit = 4 - 2 = 2.

#### Example 2

**Input:**

```cpp
k = 2, prices = [3,2,6,5,0,3]
```

**Output:**

```cpp
7
```

**Explanation:**

- Buy on day 2 (price = 2), sell on day 3 (price = 6), profit = 6 - 2 = 4.
- Buy on day 5 (price = 0), sell on day 6 (price = 3), profit = 3 - 0 = 3.

### Constraints

- `1 <= k <= 100`
- `1 <= prices.length <= 1000`
- `0 <= prices[i] <= 1000`

---

## Approach

The problem is solved using **Dynamic Programming (DP)**. Several approaches are implemented:

1. **Recursive Approach**
2. **Memoization Approach** (Top-Down DP)
3. **Tabulation Approach** (Bottom-Up DP)
4. **Optimized Tabulation Approach** (Space-Efficient DP)

---

## Detailed Explanation of Code

### Optimized Tabulation Approach

```cpp
int tabulation_optimized(int n, int k, vector<int>& prices) {
    vector<vector<int>> dp(2, vector<int>(k + 1, 0));
    vector<vector<int>> current(2, vector<int>(k + 1, 0));

    for (int index = n - 1; index >= 0; index--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                int profit = 0;
                if (buy) {
                    profit = max(-prices[index] + dp[0][cap], dp[1][cap]);
                } else {
                    profit = max(prices[index] + dp[1][cap - 1], dp[0][cap]);
                }
                current[buy][cap] = profit;
            }
        }
        dp = current;
    }
    return current[1][k];
}
```

### Recursive Approach

```cpp
int optimized(int index, int transaction, int k, int n, vector<int>& prices) {
    if (index == n || transaction == 2 * k) return 0;
    if (transaction % 2 == 0) {
        return max(-prices[index] + optimized(index + 1, transaction + 1, k, n, prices), optimized(index + 1, transaction, k, n, prices));
    } else {
        return max(prices[index] + optimized(index + 1, transaction + 1, k, n, prices), optimized(index + 1, transaction, k, n, prices));
    }
}
```

### Memoization Approach

```cpp
int optimized_memoized(int index, int transaction, int k, int n, vector<int>& prices, vector<vector<int>>& dp) {
    if (index == n || transaction == 2 * k) return 0;
    if (dp[index][transaction] != -1) return dp[index][transaction];
    if (transaction % 2 == 0) {
        return dp[index][transaction] = max(-prices[index] + optimized_memoized(index + 1, transaction + 1, k, n, prices, dp), optimized_memoized(index + 1, transaction, k, n, prices, dp));
    } else {
        return dp[index][transaction] = max(prices[index] + optimized_memoized(index + 1, transaction + 1, k, n, prices, dp), optimized_memoized(index + 1, transaction, k, n, prices, dp));
    }
}
```

### Tabulation Approach

```cpp
int tabulation(int k, int n, vector<int>& prices) {
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int index = n - 1; index >= 0; index--) {
        for (int transaction = 2 * k - 1; transaction >= 0; transaction--) {
            if (transaction % 2 == 0) {
                dp[index][transaction] = max(-prices[index] + dp[index + 1][transaction + 1], dp[index + 1][transaction]);
            } else {
                dp[index][transaction] = max(prices[index] + dp[index + 1][transaction + 1], dp[index + 1][transaction]);
            }
        }
    }
    return dp[0][0];
}
```

---

## Complexity Analysis

| Approach                  | Time Complexity | Space Complexity |
| ------------------------- | --------------- | ---------------- |
| Recursive                 | O(2^(N\*K))     | O(N\*K)          |
| Memoization (Top-Down DP) | O(N\*K)         | O(N\*K)          |
| Tabulation (Bottom-Up DP) | O(N\*K)         | O(N\*K)          |
| Optimized Tabulation      | O(N\*K)         | O(K)             |

---

## How to Run the Code

1. Copy the code into a C++ compiler.
2. Define the input values for `k` and `prices`.
3. Call the function `maxProfit(k, prices);`.
4. Print the output result.

Example:

```cpp
vector<int> prices = {3,2,6,5,0,3};
int k = 2;
Solution obj;
cout << obj.maxProfit(k, prices);
```

This will output `7` as the maximum profit.

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    int tabulation_optimized(int n, int k, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));
        vector<vector<int>> current(2, vector<int>(k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[index] + dp[0][cap], dp[1][cap]);
                    } else {
                        profit =
                            max(prices[index] + dp[1][cap - 1], dp[0][cap]);
                    }
                    current[buy][cap] = profit;
                }
            }
            dp = current;
        }

        return current[1][k];
    }

    int optimized(int index, int transaction, int k, int n,
                  vector<int>& prices) {

        if (index == n || transaction == 2 * k)
            return 0;

        if (transaction % 2 == 0) {
            return max(-prices[index] +
                           optimized(index + 1, transaction + 1, k, n, prices),
                       optimized(index + 1, transaction, k, n, prices));
        } else {
            return max(prices[index] +
                           optimized(index + 1, transaction + 1, k, n, prices),
                       optimized(index + 1, transaction, k, n, prices));
        }
    }

    int optimized_memoized(int index, int transaction, int k, int n,
                           vector<int>& prices, vector<vector<int>>& dp) {

        if (index == n || transaction == 2 * k)
            return 0;

        if (dp[index][transaction] != -1)
            return dp[index][transaction];

        if (transaction % 2 == 0) {
            return dp[index][transaction] =
                       max(-prices[index] +
                               optimized_memoized(index + 1, transaction + 1, k,
                                                  n, prices, dp),
                           optimized_memoized(index + 1, transaction, k, n,
                                              prices, dp));
        } else {
            return dp[index][transaction] =
                       max(prices[index] + optimized_memoized(index + 1,
                                                              transaction + 1,
                                                              k, n, prices, dp),
                           optimized_memoized(index + 1, transaction, k, n,
                                              prices, dp));
        }
    }

    int tabulation(int k, int n, vector<int>& prices) {
        vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--) {
                if (transaction % 2 == 0) {
                    dp[index][transaction] =
                        max(-prices[index] + dp[index + 1][transaction + 1],
                            dp[index + 1][transaction]);
                } else {
                    dp[index][transaction] =
                        max(prices[index] + dp[index + 1][transaction + 1],
                            dp[index + 1][transaction]);
                }
            }
        }

        return dp[0][0];
    }

    int tabulation_better(int k, int n, vector<int>& prices) {
        vector<int> dp(2 * k + 1, 0);
        vector<int> current(2 * k + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int transaction = 2 * k - 1; transaction >= 0; transaction--) {
                if (transaction % 2 == 0) {
                    current[transaction] = max(
                        -prices[index] + dp[transaction + 1], dp[transaction]);
                } else {
                    current[transaction] = max(
                        prices[index] + dp[transaction + 1], dp[transaction]);
                }
            }
            dp = current;
        }

        return current[0];
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        // vector<vector<int>> dp(n, vector<int>(2 * k, -1));

        return tabulation_better(k, n, prices);
    }
};
```
