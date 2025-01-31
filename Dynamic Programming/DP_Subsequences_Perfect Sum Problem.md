# Perfect Sum Problem

## Table of Contents

- [Perfect Sum Problem](#perfect-sum-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
      - [Example 4](#example-4)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive with Memoization](#recursive-with-memoization)
    - [Tabulation Approach](#tabulation-approach)
    - [Space Optimized Tabulation](#space-optimized-tabulation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Example Usage](#example-usage)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)

## Introduction

The **Perfect Sum Problem** requires counting all subsets of a given array whose sum is equal to a given target.

## Problem Description

Given an array `arr` of non-negative integers and an integer `target`, the task is to count all subsets whose sum is equal to the given `target`.

### Examples

#### Example 1

**Input:**

```cpp
arr[] = {5, 2, 3, 10, 6, 8}, target = 10
```

**Output:**

```cpp
3
```

**Explanation:**  
Subsets summing to `10` are `{5, 2, 3}, {2, 8}, {10}`.

#### Example 2

**Input:**

```cpp
arr[] = {2, 5, 1, 4, 3}, target = 10
```

**Output:**

```cpp
3
```

**Explanation:**  
Subsets summing to `10` are `{2, 1, 4, 3}, {5, 1, 4}, {2, 5, 3}`.

#### Example 3

**Input:**

```cpp
arr[] = {5, 7, 8}, target = 3
```

**Output:**

```cpp
0
```

**Explanation:**  
No subset sums to `3`.

#### Example 4

**Input:**

```cpp
arr[] = {35, 2, 8, 22}, target = 0
```

**Output:**

```cpp
1
```

**Explanation:**  
The empty subset is the only subset with a sum of `0`.

### Constraints

- `1 ≤ arr.size() ≤ 10^3`
- `0 ≤ arr[i] ≤ 10^3`
- `0 ≤ target ≤ 10^3`

## Approach

We use **Dynamic Programming** (DP) to solve this problem efficiently. Three approaches are discussed:

1. **Recursive with Memoization** (Top-down approach)
2. **Tabulation** (Bottom-up approach)
3. **Space Optimized Tabulation**

## Detailed Explanation of Code

### Recursive with Memoization

```cpp
int helper(int i, int k, vector<int> &arr, vector<vector<int>> &dp) {
    if (i == 0) {
        if (k == 0 && arr[0] == 0) return 2;
        if (k == arr[0] || k == 0) return 1;
        return 0;
    }
    if (dp[i][k] != -1) return dp[i][k];
    int notpick = helper(i - 1, k, arr, dp);
    int pick = (arr[i] <= k) ? helper(i - 1, k - arr[i], arr, dp) : 0;
    return dp[i][k] = (notpick + pick) % mod;
}
```

### Tabulation Approach

```cpp
int tabulation_solution(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    if (arr[0] == 0) dp[0][0] = 2;
    if (arr[0] != 0 && arr[0] <= target) dp[0][arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= target; sum++) {
            int notpick = dp[i - 1][sum];
            int pick = (arr[i] <= sum) ? dp[i - 1][sum - arr[i]] : 0;
            dp[i][sum] = (notpick + pick) % mod;
        }
    }
    return dp[n - 1][target];
}
```

### Space Optimized Tabulation

```cpp
int tabulation_optimized(vector<int> &arr, int target) {
    int n = arr.size();
    vector<int> dp(target + 1, 0), current(target + 1, 0);
    dp[0] = 1;
    if (arr[0] == 0) dp[0] = 2;
    if (arr[0] != 0 && arr[0] <= target) dp[arr[0]] = 1;

    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= target; sum++) {
            int notpick = dp[sum];
            int pick = (arr[i] <= sum) ? dp[sum - arr[i]] : 0;
            current[sum] = (notpick + pick) % mod;
        }
        dp = current;
    }
    return dp[target];
}
```

## Complexity Analysis

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Recursive + Memoization    | O(N \* Target)  | O(N \* Target)   |
| Tabulation (Bottom-Up)     | O(N \* Target)  | O(N \* Target)   |
| Space Optimized Tabulation | O(N \* Target)  | O(Target)        |

## How to Run the Code

### For C++

1. Save the code in a file named `perfect_sum.cpp`.
2. Compile the code using:

   ```sh
   g++ perfect_sum.cpp -o perfect_sum
   ```

3. Run the executable:

   ```sh
   ./perfect_sum
   ```

4. Provide input in the expected format and check the output.

### Example Usage

```sh
Input:
1
5 2 3 10 6 8
10

Output:
3
```

This implementation efficiently computes the number of subsets that sum up to the given target using optimized Dynamic Programming techniques.

## Other Solutions

### Solution - 1

```cpp
class Solution
{
public:
  int helper(vector<int> &arr, int target, int idx, vector<vector<int>> &dp)
  {
    if (idx >= arr.size())
    {
      if (target == 0)
      {
        return 1;
      }
      else
      {
        return 0;
      }
    };
    if (dp[idx][target] != -1)
    {
      return dp[idx][target];
    }
    // Pick
    int pick = (arr[idx] <= target) ? helper(arr, target - arr[idx], idx + 1, dp) : 0;
    // Not Pick
    int not_pick = helper(arr, target, idx + 1, dp);
    return dp[idx][target] = pick + not_pick;
  }
  int perfectSum(vector<int> &arr, int target)
  {
    // code here
    vector<vector<int>> dp(arr.size(), vector<int>(target + 1, -1));
    return helper(arr, target, 0, dp);
  }
};
```
