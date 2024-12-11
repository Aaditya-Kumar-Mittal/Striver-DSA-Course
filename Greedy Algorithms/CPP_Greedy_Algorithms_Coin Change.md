# Coin Change

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Coin Change](#coin-change)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Dynamic Programming Approach](#dynamic-programming-approach)
    - [Greedy Approach (For Some Cases)](#greedy-approach-for-some-cases)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Dynamic Programming Approach](#dynamic-programming-approach-1)
      - [Greedy Approach (For Some Cases)](#greedy-approach-for-some-cases-1)
    - [Java Implementation](#java-implementation)
      - [Dynamic Programming Approach](#dynamic-programming-approach-2)
      - [Greedy Approach (For Some Cases)](#greedy-approach-for-some-cases-2)
  - [Complexity Analysis](#complexity-analysis)
    - [Dynamic Programming](#dynamic-programming)
    - [Greedy Approach](#greedy-approach)

---

## Introduction

The **Coin Change** problem involves finding the minimum number of coins required to make up a given `amount` using coins of specified denominations. If it is not possible to form the `amount`, the output should be `-1`.

This problem can be solved using both **Dynamic Programming** and **Greedy Algorithm**, depending on the specific requirements and constraints.

---

## Problem Description

### Input

1. An integer array `coins` representing the denominations of coins.
2. An integer `amount` representing the target amount.

### Output

- The minimum number of coins needed to form the `amount`.
- If it is not possible to form the amount, return `-1`.

---

## Examples

### Example 1

**Input:**  
`coins = [1, 2, 5]`, `amount = 11`  
**Output:**  
`3`  
**Explanation:**  
11 = 5 + 5 + 1

### Example 2

**Input:**  
`coins = [2]`, `amount = 3`  
**Output:**  
`-1`  
**Explanation:**  
It is not possible to make the amount 3 using denomination 2.

### Example 3

**Input:**  
`coins = [1]`, `amount = 0`  
**Output:**  
`0`  
**Explanation:**  
No coins are required to form amount 0.

---

## Constraints

- \( 1 \leq \text{coins.length} \leq 12 \)
- \( 1 \leq \text{coins}[i] \leq 2^{31} - 1 \)
- \( 0 \leq \text{amount} \leq 10^4 \)

---

## Approach

### Dynamic Programming Approach

1. Use an array `dp` where `dp[i]` represents the minimum coins required to form amount `i`.
2. Initialize `dp[0] = 0` (0 coins are needed to form amount 0) and all other values in `dp` to `INT_MAX`.
3. For each amount `i` from `1` to `amount`, iterate through all the coins and update `dp[i]` as the minimum of its current value and `dp[i - coin] + 1` (if `i >= coin`).
4. The result is stored in `dp[amount]`. If it remains `INT_MAX`, return `-1`.

### Greedy Approach (For Some Cases)

1. Sort the coins in descending order.
2. Start with the largest denomination and subtract its value from the `amount` as many times as possible.
3. If the amount becomes zero, return the count of coins used; otherwise, return `-1`.

---

## Detailed Explanation of Code

### C++ Implementation

#### Dynamic Programming Approach

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
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
};

// Driver Code
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;

    return 0;
}
```

#### Greedy Approach (For Some Cases)

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.rbegin(), coins.rend());
        int count = 0;

        for (int coin : coins) {
            while (amount >= coin) {
                amount -= coin;
                count++;
            }
        }
        return amount == 0 ? count : -1;
    }
};

// Driver Code
int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    Solution obj;
    cout << obj.coinChange(coins, amount) << endl;

    return 0;
}
```

---

### Java Implementation

#### Dynamic Programming Approach

```java
import java.util.*;

class Solution {
    public int coinChange(int[] coins, int amount) {
        int[] dp = new int[amount + 1];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (i >= coin && dp[i - coin] != Integer.MAX_VALUE) {
                    dp[i] = Math.min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        return dp[amount] == Integer.MAX_VALUE ? -1 : dp[amount];
    }

    // Driver Code
    public static void main(String[] args) {
        int[] coins = {1, 2, 5};
        int amount = 11;

        Solution obj = new Solution();
        System.out.println(obj.coinChange(coins, amount));
    }
}
```

#### Greedy Approach (For Some Cases)

```java
import java.util.*;

class Solution {
    public int coinChange(int[] coins, int amount) {
        Arrays.sort(coins);
        int count = 0;

        for (int i = coins.length - 1; i >= 0; i--) {
            while (amount >= coins[i]) {
                amount -= coins[i];
                count++;
            }
        }
        return amount == 0 ? count : -1;
    }

    // Driver Code
    public static void main(String[] args) {
        int[] coins = {1, 2, 5};
        int amount = 11;

        Solution obj = new Solution();
        System.out.println(obj.coinChange(coins, amount));
    }
}
```

---

## Complexity Analysis

### Dynamic Programming

- **Time Complexity:** \( O(n \times \text{amount}) \), where \( n \) is the number of coins.
- **Space Complexity:** \( O(\text{amount}) \).

### Greedy Approach

- **Time Complexity:** \( O(n \log n + \text{amount}) \), where \( n \) is the number of coins (for sorting).
- **Space Complexity:** \( O(1) \).

Note: The **Greedy Approach** is not always optimal but works for certain coin denominations where the largest denomination always contributes optimally.
