# Array Partition with Minimum Difference (Coding Ninjas)

## Table of Contents

- [Array Partition with Minimum Difference (Coding Ninjas)](#array-partition-with-minimum-difference-coding-ninjas)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Tabulation Solution (Gives TLE)](#tabulation-solution-gives-tle)
    - [Tabulation Solution Optimized (Gives TLE)](#tabulation-solution-optimized-gives-tle)
    - [Optimized For TLE](#optimized-for-tle)

---

## Introduction

The task is to partition an array into two subsets such that the absolute difference between the sums of these subsets is minimized. Each element of the array must belong to exactly one subset, and the subsets do not need to be contiguous.

---

## Problem Description

Given:

- An array `arr` containing `n` non-negative integers.

Objective:

- Partition the array into two subsets such that the absolute difference between their sums is minimized.

### Examples

#### Example 1

**Input:**

```bash
n = 5
arr = [3, 1, 5, 2, 8]
```

**Output:**

```bash
1
```

**Explanation:**
We can partition the array into `{3, 1, 5}` and `{2, 8}`. The absolute difference is `|10 - 9| = 1`.

#### Example 2

**Input:**

```bash
n = 4
arr = [1, 2, 3, 4]
```

**Output:**

```bash
0
```

**Explanation:**
Partition the array into `{2, 3}` and `{1, 4}`. The absolute difference is `|5 - 5| = 0`.

#### Example 3

**Input:**

```bash
n = 3
arr = [8, 6, 5]
```

**Output:**

```bash
3
```

**Explanation:**
Partition the array into `{8}` and `{6, 5}`. The absolute difference is `|11 - 8| = 3`.

### Constraints

- \(1 \leq n \leq 10^3\)
- \(0 \leq arr[i] \leq 10^3\)
- \(0 \leq \sum arr[i] \leq 10^4\)
- Time Limit: 1 second

---

## Approach

1. **Problem Analysis:**

   - Compute the total sum of the array, denoted as `sum`.
   - Our goal is to find subsets whose sums are as close as possible to `sum / 2`.

2. **Dynamic Programming:**

   - Use a 1D DP array to track achievable subset sums.
   - Let `dp[j]` represent whether a subset with sum `j` is possible.

3. **Steps:**
   - Initialize `dp[0]` as `true` since a sum of 0 is always achievable.
   - Iterate over the elements of the array, updating `dp` in reverse order to avoid overwriting.
   - Finally, iterate through possible subset sums up to `sum / 2` and compute the minimum absolute difference.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubsetSumDifference(vector<int> &arr, int n) {
        int totalSum = accumulate(arr.begin(), arr.end(), 0);

        vector<bool> dp(totalSum + 1, false);
        dp[0] = true; // Base case: sum 0 is always achievable

        if (arr[0] <= totalSum)
            dp[arr[0]] = true; // Initialize with the first element

        // Iterate over the array
        for (int i = 1; i < n; i++) {
            for (int j = totalSum; j >= arr[i]; j--) {
                dp[j] = dp[j] || dp[j - arr[i]];
            }
        }

        // Compute the minimum absolute difference
        int mini = INT_MAX;
        for (int s1 = 0; s1 <= totalSum / 2; s1++) {
            if (dp[s1]) {
                mini = min(mini, abs(totalSum - 2 * s1));
            }
        }

        return mini;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 1, 5, 2, 8};
    int n = arr.size();
    cout << sol.minSubsetSumDifference(arr, n) << endl;
    return 0;
}
```

---

## Complexity Analysis

1. **Time Complexity:**

   - Initializing and iterating through the DP array involves \(O(n \cdot \text{sum})\), where `sum` is the total sum of the array elements.
   - Overall complexity: \(O(n \cdot \sum arr[i])\).

2. **Space Complexity:**
   - The DP array requires \(O(\text{sum})\) space.
   - Overall complexity: \(O(\text{sum})\).

---

## How to Run the Code

### For C++

1. Save the code in a file named `solution.cpp`.
2. Compile the code using:

   ```bash
   g++ -std=c++17 -o solution solution.cpp
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

4. Provide the necessary inputs as defined in the problem statement.

## Other Solutions

### Tabulation Solution (Gives TLE)

```cpp
int minSubsetSumDifference(vector<int> &nums, int n)
{

  int sum = accumulate(nums.begin(), nums.end(), 0);

  vector<vector<bool>> dp(n, vector<bool>(sum + 1, false));

  for (int i = 0; i < n; i++)
  {
    dp[i][0] = true;
  }
  if (nums[0] <= sum)
  {
    dp[0][nums[0]] = true;
  }

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      bool not_take = dp[i - 1][j];
      bool take = (j >= nums[i]) ? dp[i - 1][j - nums[i]] : false;
      dp[i][j] = take || not_take;
    }
  }

  int mini = 1e9;

  for (int s1 = 0; s1 <= sum / 2; s1++)
  {
    if (dp[n - 1][s1] == true)
    {
      mini = min(mini, abs(sum - 2 * s1));
    }
  }

  return mini;
}
```

### Tabulation Solution Optimized (Gives TLE)

```cpp
int minSubsetSumDifference(vector<int> &arr, int n)
{

  int target = accumulate(arr.begin(), arr.end(), 0);

  vector<bool> dp(target + 1, false), current(target + 1, false);

  dp[0] = current[0] = true;
  if (arr[0] <= target)
    dp[arr[0]] = true;

  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= target; j++)
    {
      bool not_take = dp[j];
      bool take = false;
      if (j >= arr[i])
        take = dp[j - arr[i]];
      current[j] = take || not_take;
    }
    dp = current;
  }

  int mini = 1e9;

  for (int s1 = 0; s1 <= target / 2; s1++)
  {
    if (dp[s1] == true)
    {
      mini = min(mini, abs(target - 2 * s1));
    }
  }

  return mini;
}
```

### Optimized For TLE

```cpp
int minSubsetSumDifference(vector<int> &arr, int n)
{

  int target = accumulate(arr.begin(), arr.end(), 0);

  vector<bool> dp(target + 1, false);
  dp[0] = true; // Base case: target 0 is always achievable

  if (arr[0] <= target)
    dp[arr[0]] = true; // First element initialization

  for (int i = 1; i < n; i++)
  {
    for (int j = target; j >= arr[i]; j--)
    { // Iterate backwards to
      // avoid overwriting
      dp[j] = dp[j] || dp[j - arr[i]];
    }
  }

  int mini = 1e9;

  for (int s1 = 0; s1 <= target / 2; s1++)
  {
    if (dp[s1] == true)
    {
      mini = min(mini, abs(target - 2 * s1));
    }
  }

  return mini;
}
```
