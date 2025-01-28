# Partition Equal Subset Sum

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Partition Equal Subset Sum](#partition-equal-subset-sum)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
      - [Algorithm](#algorithm)
      - [Code](#code)
    - [Memoization Solution](#memoization-solution)
      - [Algorithm](#algorithm-1)
      - [Code](#code-1)
    - [Tabulation Solution](#tabulation-solution)
      - [Algorithm](#algorithm-2)
      - [Code](#code-2)
    - [Space-Optimized Tabulation Solution](#space-optimized-tabulation-solution)
      - [Algorithm](#algorithm-3)
      - [Code](#code-3)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [0/1 Knapsack Solution](#01-knapsack-solution)
    - [0/1 Knapsack Solution Optimized](#01-knapsack-solution-optimized)
    - [Brute Force](#brute-force)

---

## Introduction

The problem requires determining if an integer array can be partitioned into two subsets such that the sum of the elements in both subsets is equal.

---

## Problem Description

Given an integer array `nums`, return `true` if the array can be partitioned into two subsets with equal sums, and `false` otherwise.

### Examples

#### Example 1

**Input:**

```bash
nums = [1,5,11,5]
```

**Output:**

```bash
true
```

**Explanation:**
The array can be partitioned as `[1, 5, 5]` and `[11]`.

#### Example 2

**Input:**

```bash
nums = [1,2,3,5]
```

**Output:**

```bash
false
```

**Explanation:**
The array cannot be partitioned into equal sum subsets.

### Constraints

- `1 <= nums.length <= 200`
- `1 <= nums[i] <= 100`

---

## Approach

The problem is solved using dynamic programming. Below are four approaches:

### Recursive Solution

#### Algorithm

1. Start from the first index and explore subsets that include or exclude the current element.
2. Base cases:
   - If the target is `0`, return `true`.
   - If the index becomes invalid, return `false`.
3. Recursively call for both possibilities and return their results.

#### Code

```cpp
bool recursive(int index, int target, vector<int>& arr) {
    if (target == 0) return true;
    if (index < 0 || target < 0) return false;

    bool include = recursive(index - 1, target - arr[index], arr);
    bool exclude = recursive(index - 1, target, arr);

    return include || exclude;
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    return recursive(nums.size() - 1, sum / 2, nums);
}
```

---

### Memoization Solution

#### Algorithm

1. Use a 2D table to store results of subproblems indexed by the current index and target.
2. If the result is already computed, use it from the table.
3. Otherwise, compute the result recursively.

#### Code

```cpp
bool memoization(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (index < 0 || target < 0) return false;
    if (dp[index][target] != -1) return dp[index][target];

    bool include = memoization(index - 1, target - arr[index], arr, dp);
    bool exclude = memoization(index - 1, target, arr, dp);

    return dp[index][target] = include || exclude;
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));

    return memoization(nums.size() - 1, target, nums, dp);
}
```

---

### Tabulation Solution

#### Algorithm

1. Create a 2D `dp` table where `dp[i][j]` indicates whether it is possible to achieve sum `j` using the first `i` elements.
2. Base cases:
   - `dp[i][0] = true` (target `0` is always achievable).
   - `dp[0][arr[0]] = true` if `arr[0] <= target`.
3. Transition:
   - `dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]]`.

#### Code

```cpp
bool tabulation(int n, int target, vector<int>& arr) {
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    for (int i = 0; i < n; i++) dp[i][0] = true;
    if (arr[0] <= target) dp[0][arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            bool not_take = dp[i - 1][j];
            bool take = (j >= arr[i]) ? dp[i - 1][j - arr[i]] : false;
            dp[i][j] = take || not_take;
        }
    }

    return dp[n - 1][target];
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    return tabulation(nums.size(), sum / 2, nums);
}
```

---

### Space-Optimized Tabulation Solution

#### Algorithm

1. Use a 1D `dp` array instead of a 2D table to optimize space.
2. Iterate over the array and update `dp` in reverse to prevent overwriting previous results.

#### Code

```cpp
bool tabulation_optimized(int n, int target, vector<int>& arr) {
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    if (arr[0] <= target) dp[arr[0]] = true;

    for (int i = 1; i < n; i++) {
        for (int j = target; j >= 0; j--) {
            if (j >= arr[i]) dp[j] = dp[j] || dp[j - arr[i]];
        }
    }

    return dp[target];
}

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    return tabulation_optimized(nums.size(), sum / 2, nums);
}
```

---

## Complexity Analysis

| Approach                   | Time Complexity  | Space Complexity |
| -------------------------- | ---------------- | ---------------- |
| Recursive Solution         | \(O(2^n)\)       | \(O(n)\)         |
| Memoization Solution       | \(O(n \cdot T)\) | \(O(n \cdot T)\) |
| Tabulation Solution        | \(O(n \cdot T)\) | \(O(n \cdot T)\) |
| Space-Optimized Tabulation | \(O(n \cdot T)\) | \(O(T)\)         |

Where \(T\) is the target sum \(\text{sum} / 2\).

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file (e.g., `partition_equal_subset_sum.cpp`).
2. Compile the code using a C++ compiler (e.g., `g++ -std=c++17 partition_equal_subset_sum.cpp -o solution`).
3. Run the executable (e.g., `./solution`).

## Other Solutions

### My Submission

```cpp
class Solution {
    // Tabulation Solution Space Optimized
    bool tabulation_optimized(int n, int target, vector<int>& arr) {
        if (arr[0] > target)
            return false; // Handle edge case: single element exceeding the
                          // target

        vector<bool> dp(target + 1, false); // Represents the current row
        dp[0] = true;                       // Target 0 is always achievable
        if (arr[0] <= target)
            dp[arr[0]] = true; // Initialize with the first element

        // Iterate through the array
        for (int i = 1; i < n; i++) {
            vector<bool> current(target + 1,
                                 false); // New row for the current index
            current[0] = true;           // Target 0 is always achievable

            for (int j = 1; j <= target; j++) {
                bool not_take = dp[j]; // Exclude the current element
                bool take = (j >= arr[i])
                                ? dp[j - arr[i]]
                                : false; // Include the current element if valid

                current[j] = take || not_take; // Update current state
            }
            dp = current; // Move to the next row
        }

        return dp[target];
    }

public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =
            accumulate(nums.begin(), nums.end(), 0); // Calculate the total sum

        if (sum % 2 != 0)
            return false; // Odd sum can't be divided equally
        int s1 = sum / 2; // Target for one subset

        return tabulation_optimized(n, s1, nums);
    }
};
```

### 0/1 Knapsack Solution

```java
public boolean canPartition(int[] nums) {
    int sum = 0;

    for (int num : nums) {
        sum += num;
    }

    if ((sum & 1) == 1) {
        return false;
    }
    sum /= 2;

    int n = nums.length;
    boolean[][] dp = new boolean[n+1][sum+1];
    for (int i = 0; i < dp.length; i++) {
        Arrays.fill(dp[i], false);
    }

    dp[0][0] = true;

    for (int i = 1; i < n+1; i++) {
        dp[i][0] = true;
    }
    for (int j = 1; j < sum+1; j++) {
        dp[0][j] = false;
    }

    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < sum+1; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i-1]) {
                dp[i][j] = (dp[i][j] || dp[i-1][j-nums[i-1]]);
            }
        }
    }

    return dp[n][sum];
}
```

### 0/1 Knapsack Solution Optimized

```java
public boolean canPartition(int[] nums) {
    int sum = 0;

    for (int num : nums) {
        sum += num;
    }

    if ((sum & 1) == 1) {
        return false;
    }
    sum /= 2;

    int n = nums.length;
    boolean[] dp = new boolean[sum+1];
    Arrays.fill(dp, false);
    dp[0] = true;

    for (int num : nums) {
        for (int i = sum; i > 0; i--) {
            if (i >= num) {
                dp[i] = dp[i] || dp[i-num];
            }
        }
    }

    return dp[sum];
}
```

### Brute Force

```cpp
class Solution {
public:
    bool canPartition(vector<int>& nums, int i = 0, int sum1 = 0, int sum2 = 0) {
        if(i >= size(nums)) return sum1 == sum2;                    // check if both subset have equal sum
        return canPartition(nums, i+1, sum1 + nums[i], sum2) || canPartition(nums, i+1, sum1, sum2 + nums[i]);        // try including into subset-1 // try including into subset-2
    }
};
```

```python
class Solution:
    def canPartition(self, nums, i = 0, sum1 = 0, sum2 = 0):
        if i >= len(nums): return sum1 == sum2
        return self.canPartition(nums, i+1, sum1 + nums[i], sum2) or self.canPartition(nums, i+1, sum1, sum2 + nums[i])
```
