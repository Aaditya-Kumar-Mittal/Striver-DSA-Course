# Best Time to Buy and Sell Stock III

## Table of Contents

- [Best Time to Buy and Sell Stock III](#best-time-to-buy-and-sell-stock-iii)
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
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Output](#output)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)
    - [Solution - 6](#solution---6)
      - [Recursive Approach](#recursive-approach)
      - [Memoization Approach](#memoization-approach)
      - [Tabulation Approach](#tabulation-approach)
      - [Space Optimized Tabulation](#space-optimized-tabulation)

## Introduction

This problem is an extension of the classic "Best Time to Buy and Sell Stock" series. The goal is to maximize profit by making at most two transactions. You cannot hold multiple stocks at the same time, meaning you must sell before buying again.

## Problem Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day.
Find the maximum profit you can achieve. You may complete at most two transactions.

### Examples

#### Example 1

**Input:**

```cpp
prices = [3,3,5,0,0,3,1,4]
```

**Output:**

```cpp
6
```

**Explanation:**

- Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = `3 - 0 = 3`.
- Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = `4 - 1 = 3`.
- Total profit = `3 + 3 = 6`.

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
- Total profit = `4`.

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

- No transaction is done, so max profit is `0`.

### Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^5`

## Approach

We solve this problem using **Dynamic Programming (DP)** with the following approaches:

1. **Recursive Approach:**

   - Consider all buy and sell scenarios.
   - Recursively compute the profit with at most 2 transactions.
   - Time Complexity: **Exponential** (TLE for large inputs).

2. **Memoization (Top-Down DP):**

   - Store already computed states to avoid redundant calculations.
   - Time Complexity: **O(N _ 2 _ 3) = O(N)**.

3. **Tabulation (Bottom-Up DP):**

   - Iterate from the last index to the first.
   - Use a `dp[index][buy][cap]` table to store results.
   - Time Complexity: **O(N _ 2 _ 3) = O(N)**.

4. **Space-Optimized DP:**
   - Reduce space usage by maintaining only two DP tables for `current` and `next` states.
   - Time Complexity: **O(N)**.
   - Space Complexity: **O(2 \* 3) = O(1)**.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int tabulation_optimized(int n, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        vector<vector<int>> current(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap < 3; cap++) {
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

        return current[1][2];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return tabulation_optimized(n, prices);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
```

## Complexity Analysis

| Approach               | Time Complexity | Space Complexity       |
| ---------------------- | --------------- | ---------------------- |
| Recursive Solution     | O(2^N)          | O(N) (Recursion Stack) |
| Memoization (Top-Down) | O(N)            | O(N _2_ 3)             |
| Tabulation (Bottom-Up) | O(N)            | O(N _2_ 3)             |
| Space Optimized DP     | O(N)            | O(2 \* 3) = O(1)       |

## How to Run the Code

### For C++

1. Copy the above C++ code into a file, e.g., `stock_trading.cpp`.
2. Compile using:

   ```sh
   g++ stock_trading.cpp -o stock_trading
   ```

3. Run the executable:

   ```sh
   ./stock_trading
   ```

### Output

```sh
Max Profit: 6
```

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int buy, int cap, int n,
                           vector<int>& prices) {
        // Base case: If we reach the end of the prices array, return 0
        if (index == n)
            return 0;

        if (cap == 0)
            return 0;

        int profit = 0;

        if (buy) {
            // If we are buying, we have two choices:
            // 1. Buy the stock at the current price and move to the next day
            // (cannot buy again until we sell)
            // 2. Skip buying and move to the next day
            profit = max(-prices[index] +
                             recursive_solution(index + 1, 0, cap, n, prices),
                         recursive_solution(index + 1, 1, cap, n, prices));
        } else {
            // If we are selling, we have two choices:
            // 1. Sell the stock at the current price and move to the next day
            // (can buy again)
            // 2. Skip selling and move to the next day
            profit = max(prices[index] + recursive_solution(index + 1, 1,
                                                            cap - 1, n, prices),
                         recursive_solution(index + 1, 0, cap, n, prices));
        }

        return profit;
    }

    int memoization(int index, int buy, int cap, int n, vector<int>& prices,
                    vector<vector<vector<int>>>& dp) {
        // Base case: If we reach the end of the prices array or no transactions
        // left, return 0
        if (index == n || cap == 0)
            return 0;

        // If the result is already computed, return it
        if (dp[index][buy][cap] != -1)
            return dp[index][buy][cap];

        int profit = 0;

        if (buy) {
            // If we are buying, we have two choices:
            // 1. Buy the stock at the current price and move to the next day
            // 2. Skip buying and move to the next day
            profit = max(-prices[index] +
                             memoization(index + 1, 0, cap, n, prices, dp),
                         memoization(index + 1, 1, cap, n, prices, dp));
        } else {
            // If we are selling, we have two choices:
            // 1. Sell the stock at the current price and move to the next day
            // 2. Skip selling and move to the next day
            profit = max(prices[index] +
                             memoization(index + 1, 1, cap - 1, n, prices, dp),
                         memoization(index + 1, 0, cap, n, prices, dp));
        }

        // Store the result in the DP table and return
        return dp[index][buy][cap] = profit;
    }

    int tabulation(int n, vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap < 3; cap++) {
                    int profit = 0;
                    if (buy) {
                        profit = max(-prices[index] + dp[index + 1][0][cap],
                                     dp[index + 1][1][cap]);
                    } else {
                        profit = max(prices[index] + dp[index + 1][1][cap - 1],
                                     dp[index + 1][0][cap]);
                    }
                    dp[index][buy][cap] = profit;
                }
            }
        }

        return dp[0][1][2];
    }

    int tabulation_optimized(int n, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(3, 0));
        vector<vector<int>> current(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap < 3; cap++) {
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

        return current[1][2];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        // DP table with dimensions [index][buy][cap]
        // Initialize with -1
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2,
        // vector<int>(3, -1)));

        // Start with index = 0, buy = 1 (can buy), and cap = 2 (2 transactions
        // left)
        return tabulation_optimized(n, prices);
    }
};
```

### Solution - 2

```cpp
class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int sellTwo = 0;
    int holdTwo = INT_MIN;
    int sellOne = 0;
    int holdOne = INT_MIN;

    for (const int price : prices) {
      sellTwo = max(sellTwo, holdTwo + price);
      holdTwo = max(holdTwo, sellOne - price);
      sellOne = max(sellOne, holdOne + price);
      holdOne = max(holdOne, -price);
    }

    return sellTwo;
  }
};
```

### Solution - 3

```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<int> left(n, 0), right(n, 0);

        int minPrice = prices[0];
        for (int i = 1; i < n; i++) {
            minPrice = min(minPrice, prices[i]);
            left[i] = max(left[i - 1], prices[i] - minPrice);
        }

        int maxPrice = prices[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            maxPrice = max(maxPrice, prices[i]);
            right[i] = max(right[i + 1], maxPrice - prices[i]);
        }

        int maxProfit = right[0];
        for (int i = 0; i < n - 1; i++) {
            maxProfit = max(maxProfit, left[i] + right[i + 1]);
        }

        return maxProfit;
    }
};
```

### Solution - 4

```cpp
int maxProfit(vector<int> &prices)
{
  if (prices.empty())
    return 0;
  int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;

  for (int i = 1; i < prices.size(); ++i)
  {
    s1 = max(s1, -prices[i]);
    s2 = max(s2, s1 + prices[i]);
    s3 = max(s3, s2 - prices[i]);
    s4 = max(s4, s3 + prices[i]);
  }
  return max(0, s4);
}
```

### Solution - 6

#### Recursive Approach

```cpp
class Solution {
public:

    int solve(vector<int>&prices, int day, int transactionsLeft){

        if(day == prices.size()){
            return 0;
        }

        if(transactionsLeft == 0){
            return 0;
        }

        // choice 1
        // no transaction today
        int ans1 = solve(prices, day + 1, transactionsLeft);


        // choice 2
        // doing the possible transaction today
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);

        if(buy == true){ // buy
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1);
        }else{ // sell
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1);
        }

        return max(ans1, ans2);


    }


    int maxProfit(vector<int>& prices) {

        int ans = solve(prices, 0, 4); // starting with day 0 and max 4 transactions can be done
        return ans;

    }
};
```

#### Memoization Approach

```cpp
class Solution {
public:

    int solve(vector<int>&prices, int day, int transactionsLeft, vector<vector<int>> &Memo){

        if(day == prices.size()){
            return 0;
        }

        if(transactionsLeft == 0){
            return 0;
        }

        int &ans = Memo[day][transactionsLeft];

        if(ans != -1){ // if problem has already been solved
            return ans;
        }

        // choice 1
        // no transaction today
        int ans1 = solve(prices, day + 1, transactionsLeft, Memo);


        // choice 2
        // doing the possible transaction today
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);

        if(buy == true){ // buy
            ans2 = -prices[day] + solve(prices, day + 1, transactionsLeft - 1, Memo);
        }else{ // sell
            ans2 = prices[day] + solve(prices, day + 1, transactionsLeft - 1, Memo);
        }

        return ans = max(ans1, ans2); // store ans in memo before returning


    }


    int maxProfit(vector<int>& prices) {

        vector<vector<int>> Memo(prices.size(), vector<int>(5, -1));
        int ans = solve(prices, 0, 4, Memo);
        return ans;

    }
};
```

#### Tabulation Approach

```cpp
class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int dp[prices.size() + 1][5];


        for(int day = (int) prices.size();day >= 0;day--){

            for(int transactionsLeft = 0;transactionsLeft <= 4;transactionsLeft++){

                int &ans = dp[day][transactionsLeft];

                if(day == prices.size()){
                    ans = 0;
                }else if(transactionsLeft == 0){
                    ans = 0;
                }else{

                    // choice 1
                    // no transaction today
                    int ans1 = dp[day + 1][transactionsLeft];

                    // choice 2
                    // doing the possible transaction today
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);

                    if(buy == true){ // buy
                        ans2 = -prices[day] + dp[day + 1][transactionsLeft - 1];
                    }else{ // sell
                        ans2 = prices[day] + dp[day + 1][transactionsLeft - 1];
                    }

                    ans = max(ans1, ans2);

                }

            }
        }
        return dp[0][4];

    }
};
```

#### Space Optimized Tabulation

```cpp
class Solution {
public:

    int maxProfit(vector<int>& prices) {

        int dp[2][5];


        for(int day = (int) prices.size();day >= 0;day--){

            for(int transactionsLeft = 0;transactionsLeft <= 4;transactionsLeft++){


                int &ans = dp[day % 2][transactionsLeft];

                if(day == prices.size()){
                    ans = 0;
                }else if(transactionsLeft == 0){
                    ans = 0;
                }else{

                    // choice 1
                    // no transaction today
                    int ans1 = dp[(day + 1) % 2][transactionsLeft];

                    // choice 2
                    // doing the possible transaction today
                    int ans2 = 0;
                    bool buy = (transactionsLeft % 2 == 0);

                    if(buy == true){ // buy
                        ans2 = -prices[day] + dp[(day + 1) % 2][transactionsLeft - 1];
                    }else{ // sell
                        ans2 = prices[day] + dp[(day + 1) % 2][transactionsLeft - 1];
                    }

                    ans = max(ans1, ans2);

                }

            }
        }
        return dp[0][4];

    }
};
```
