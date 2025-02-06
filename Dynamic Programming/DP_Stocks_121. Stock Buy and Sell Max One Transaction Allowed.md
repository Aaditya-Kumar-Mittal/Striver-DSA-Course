# Stock Buy and Sell – Max One Transaction Allowed

## Table of Contents

- [Stock Buy and Sell – Max One Transaction Allowed](#stock-buy-and-sell--max-one-transaction-allowed)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Optimal Approach (Greedy + Single Pass)](#optimal-approach-greedy--single-pass)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Summary](#summary)

---

## Introduction

The problem requires us to determine the maximum profit possible by buying and selling a stock on different days, given an array of prices where each element represents the price of the stock on a particular day.

A single transaction is allowed, meaning one buy and one sell operation only. If no profit can be made, we return `0`.

---

## Problem Description

Given an array `prices[]` of size `n`, find the maximum profit possible by performing at most one transaction (i.e., buy one day and sell on another day).

If no profit can be made, return `0`.

---

### Examples

#### Example 1

Input:

```cpp
prices[] = [7, 10, 1, 3, 6, 9, 2]
```

Output:

```cpp
8
```

Explanation:

- The best day to buy is Day 2 (`prices[2] = 1`).
- The best day to sell is Day 5 (`prices[5] = 9`).
- Maximum profit = `9 - 1 = 8`.

---

#### Example 2

Input:

```cpp
prices[] = [7, 6, 4, 3, 1]
```

Output:

```cpp
0
```

Explanation:

- The prices are strictly decreasing, so no profit can be made.
- Return `0`.

---

#### Example 3

Input:

```cpp
prices[] = [1, 3, 6, 9, 11]
```

Output:

```cpp
10
```

Explanation:

- The best day to buy is Day 1 (`prices[0] = 1`).
- The best day to sell is Day 5 (`prices[4] = 11`).
- Maximum profit = `11 - 1 = 10`.

---

### Constraints

- `1 ≤ prices.size() ≤ 10⁵`
- `0 ≤ prices[i] ≤ 10⁴`

---

## Approach

The problem can be solved using a single pass (O(n)) approach.

### Optimal Approach (Greedy + Single Pass)

1. Initialize variables:
   - `mini` to store the minimum price encountered so far.
   - `profit` to store the maximum profit found so far.
2. Iterate through the prices array:
   - At each step, calculate `cost = prices[i] - mini` (potential profit).
   - Update `profit = max(profit, cost)`.
   - Update `mini = min(mini, prices[i])` to track the minimum price.

This approach ensures that we always buy at the lowest price seen so far and sell at the highest possible price after that.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProfit(vector<int> &prices) {
        int n = prices.size();
        int mini = prices[0]; // Minimum price so far
        int profit = 0; // Maximum profit

        for (int price = 1; price < n; price++) {
            int cost = prices[price] - mini; // Potential profit if sold today
            profit = max(profit, cost); // Update max profit
            mini = min(mini, prices[price]); // Update minimum price so far
        }

        return profit; // Return maximum profit found
    }
};

// Driver Code
int main() {
    vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
    Solution obj;
    cout << obj.maximumProfit(prices) << endl; // Output: 8
    return 0;
}
```

---

## Complexity Analysis

- Time Complexity:
  - O(n) (We iterate through the `prices` array only once)
- Space Complexity:
  - O(1) (Only a few extra variables are used)

---

## How to Run the Code

### For C++

1. Compile the code:

   ```bash
   g++ filename.cpp -o output
   ```

2. Run the executable:

   ```bash
   ./output
   ```

3. Expected Output (for input `{7, 10, 1, 3, 6, 9, 2}`):

   ```bash
   8
   ```

---

## Summary

- The problem is solved using a single pass (O(n)) greedy approach.
- We keep track of the minimum price and update profit whenever a better selling price is found.
- This solution efficiently finds the maximum possible profit with only one transaction allowed.

This approach ensures optimal performance while solving the problem in linear time! 🚀
