# Partition Array for Maximum Sum

## Table of Contents

- [Partition Array for Maximum Sum](#partition-array-for-maximum-sum)
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
    - [Memoization](#memoization)
    - [Tabulation](#tabulation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

## Introduction

The problem requires partitioning an integer array into contiguous subarrays of length at most `k`. Each subarray is transformed so that all elements become the maximum value in that subarray. The goal is to return the largest sum possible after partitioning.

## Problem Description

Given an integer array `arr` and an integer `k`, partition the array into contiguous subarrays, with each subarray having a maximum length of `k`. The sum is calculated by changing each subarray's values to its maximum value and summing up the entire array.

### Examples

#### Example 1

**Input:**  
`arr = [1,15,7,9,2,5,10], k = 3`  
**Output:**  
`84`  
**Explanation:**  
After partitioning, `arr` becomes `[15,15,15,9,10,10,10]`.

#### Example 2

**Input:**  
`arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4`  
**Output:**  
`83`

#### Example 3

**Input:**  
`arr = [1], k = 1`  
**Output:**  
`1`

### Constraints

- `1 <= arr.length <= 500`
- `0 <= arr[i] <= 10^9`
- `1 <= k <= arr.length`

## Approach

Three different approaches can be used to solve this problem:

1. **Recursive Solution**: Solve the problem using recursion by trying all possible partitions.
2. **Memoization**: Optimize recursion using memoization to store computed values.
3. **Tabulation**: Implement a bottom-up approach using dynamic programming to compute the result iteratively.

## Detailed Explanation of Code

### Recursive Solution

```cpp
int recursive_solution(int index, int k, int n, vector<int>& arr) {
    if (index == n)
        return 0;

    int maxAns = INT_MIN;
    int len = 0, maxi = INT_MIN;

    for (int j = index; j < min(n, index + k); j++) {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + recursive_solution(j + 1, k, n, arr);
        maxAns = max(maxAns, sum);
    }

    return maxAns;
}
```

- This function partitions the array recursively.
- It considers all possible partitions and selects the maximum sum.
- The time complexity is **exponential**, making it inefficient for large inputs.

### Memoization

```cpp
int memoization(int index, int k, int n, vector<int>& arr, vector<int>& dp) {
    if (index == n)
        return 0;
    if (dp[index] != -1)
        return dp[index];

    int maxAns = INT_MIN;
    int len = 0, maxi = INT_MIN;

    for (int j = index; j < min(n, index + k); j++) {
        len++;
        maxi = max(maxi, arr[j]);
        int sum = (len * maxi) + memoization(j + 1, k, n, arr, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[index] = maxAns;
}
```

- Uses **memoization** (top-down DP) to store results of previously computed subproblems.
- Improves efficiency significantly compared to the recursive solution.
- **Time Complexity:** `O(n*k)`, **Space Complexity:** `O(n)`.

### Tabulation

```cpp
int tabulation(int k, int n, vector<int>& arr) {
    vector<int> dp(n + 1, 0);

    for (int index = n - 1; index >= 0; index--) {
        int maxAns = INT_MIN;
        int len = 0, maxi = INT_MIN;

        for (int j = index; j < min(n, index + k); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = (len * maxi) + dp[j + 1];
            maxAns = max(maxAns, sum);
        }

        dp[index] = maxAns;
    }

    return dp[0];
}
```

- Uses **bottom-up DP** (tabulation) to compute the solution iteratively.
- More space-efficient than memoization since it avoids recursion overhead.
- **Time Complexity:** `O(n*k)`, **Space Complexity:** `O(n)`.

## Complexity Analysis

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Recursion   | `O(k^n)`        | `O(n)` (stack)   |
| Memoization | `O(n*k)`        | `O(n)`           |
| Tabulation  | `O(n*k)`        | `O(n)`           |

## How to Run the Code

1. **Compile the Code**

   ```bash
   g++ -o solution solution.cpp
   ```

2. **Run the Executable**

   ```bash
   ./solution
   ```

3. **Example Input & Output**

   ```bash
   Input: arr = [1,15,7,9,2,5,10], k = 3
   Output: 84
   ```

---

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int k, int n, vector<int>& arr) {
        if (index == n)
            return 0;

        int maxAns = INT_MIN;

        int len = 0, maxi = INT_MIN;

        for (int j = index; j < min(n, index + k); j++) {
            len++;

            maxi = max(maxi, arr[j]);

            int sum = (len * maxi) + recursive_solution(j + 1, k, n, arr);

            maxAns = max(maxAns, sum);
        }

        return maxAns;
    }

    int memoization(int index, int k, int n, vector<int>& arr,
                    vector<int>& dp) {
        if (index == n)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int maxAns = INT_MIN;

        int len = 0, maxi = INT_MIN;

        for (int j = index; j < min(n, index + k); j++) {
            len++;

            maxi = max(maxi, arr[j]);

            int sum = (len * maxi) + memoization(j + 1, k, n, arr, dp);

            maxAns = max(maxAns, sum);
        }

        return dp[index] = maxAns;
    }

    int tabulation(int k, int n, vector<int>& arr) {
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int maxAns = INT_MIN;

            int len = 0, maxi = INT_MIN;

            for (int j = index; j < min(n, index + k); j++) {
                len++;

                maxi = max(maxi, arr[j]);

                int sum = (len * maxi) + memoization(j + 1, k, n, arr, dp);

                maxAns = max(maxAns, sum);
            }

            dp[index] = maxAns;
        }

        return dp[0];
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        // Write your code here.

        int n = arr.size();

        // vector<int> dp(n, -1);

        // return memoization(0, k, n, arr, dp);

        return tabulation(k, n, arr);
    }
};
```

This document provides a complete explanation of the **Partition Array for Maximum Sum** problem, detailing multiple approaches and their complexities. 🚀
