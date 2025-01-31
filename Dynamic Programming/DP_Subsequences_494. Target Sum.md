# Target Sum

## Table of Contents

- [Target Sum](#target-sum)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Optimized DP Solution](#optimized-dp-solution)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The **Target Sum** problem is a variation of the subset sum problem where we assign a `+` or `-` sign to each element in the given array and determine how many different expressions can be formed to reach a given `target` sum.

## Problem Description

You are given an integer array `nums` and an integer `target`. You want to build an expression by adding either `+` or `-` before each integer in `nums`, then concatenate all the numbers to form an expression.

Return the number of different expressions that evaluate to `target`.

### Examples

#### Example 1

**Input:**

```cpp
nums = [1,1,1,1,1], target = 3
```

**Output:**

```cpp
5
```

**Explanation:**
There are 5 ways to assign symbols to get sum = 3:

- `-1 + 1 + 1 + 1 + 1 = 3`
- `+1 - 1 + 1 + 1 + 1 = 3`
- `+1 + 1 - 1 + 1 + 1 = 3`
- `+1 + 1 + 1 - 1 + 1 = 3`
- `+1 + 1 + 1 + 1 - 1 = 3`

#### Example 2

**Input:**

```cpp
nums = [1], target = 1
```

**Output:**

```cpp
1
```

### Constraints

- `1 <= nums.length <= 20`
- `0 <= nums[i] <= 1000`
- `0 <= sum(nums[i]) <= 1000`
- `-1000 <= target <= 1000`

## Approach

This problem can be solved using **Dynamic Programming (DP)** with the following transformations:

- Let `S1` be the subset with `+` signs and `S2` be the subset with `-` signs.
- The given equation is:  
  `S1 - S2 = target`
- We also know:  
  `S1 + S2 = sum(nums)`
- Adding both equations:  
  `2 * S1 = target + sum(nums)`
- This means that finding the number of ways to reach `S1 = (target + sum(nums)) / 2` will give the required answer.

Thus, we reduce the problem to **finding the count of subsets with sum = (target + sum(nums)) / 2**.

### Optimized DP Solution

- Use **tabulation with space optimization** to store only previous row results.
- Build the DP array iteratively.
- Use **modulo `1e9+7`** to avoid integer overflow.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int mod = 1e9;

    // Optimized Tabulation DP
    int tabulation_optimized(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(target + 1, 0), current(target + 1, 0);
        dp[0] = 1;

        if (arr[0] == 0) dp[0] = 2; // Special case for zero
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

    // Convert target sum problem to subset sum problem
    int countPartitions(vector<int>& arr, int d) {
        int n = arr.size();
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        if (totalSum - d < 0 || (totalSum - d) % 2) return 0;

        return tabulation_optimized(arr, (totalSum - d) / 2);
    }

    // Main function to find target sum ways
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums, target);
    }
};
```

## Complexity Analysis

| Approach       | Time Complexity | Space Complexity   |
| -------------- | --------------- | ------------------ |
| Recursive DP   | O(2^N)          | O(N) (stack space) |
| Memoization DP | O(N \* sum)     | O(N \* sum)        |
| Tabulation DP  | O(N \* sum)     | O(sum) (optimized) |

- The **time complexity** is **O(N \* sum(nums))** for the optimized DP approach.
- The **space complexity** is **O(sum(nums))**, reducing the 2D table to a single array.

## How to Run the Code

### For C++

1. Compile using `g++ -std=c++17 solution.cpp -o solution`.
2. Run using `./solution`.
3. Provide input values directly in the `main()` function or read from standard input.

This approach ensures optimal performance while solving the problem effectively. 🚀
