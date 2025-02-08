# Longest Bitonic Subsequence

## Table of Contents

- [Longest Bitonic Subsequence](#longest-bitonic-subsequence)
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
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [Solution - 2](#solution---2)

## Introduction

A **Bitonic Subsequence** of an array is a subsequence that is first strictly increasing and then strictly decreasing. The task is to find the **maximum length** of such a subsequence.

## Problem Description

Given an array of positive integers, find the length of the **Longest Bitonic Subsequence (LBS)**.

A strictly increasing or strictly decreasing sequence **is not** considered bitonic. That means there should be **at least one increasing and one decreasing segment** in the subsequence.

### Examples

#### Example 1

**Input:**

```cpp
n = 5, nums = [1, 2, 5, 3, 2]
```

**Output:**

```cpp
5
```

**Explanation:**
The bitonic subsequence `{1, 2, 5}` is increasing and `{3, 2}` is decreasing. Merging both gives a sequence of length `5`.

#### Example 2

**Input:**

```cpp
n = 8, nums = [1, 11, 2, 10, 4, 5, 2, 1]
```

**Output:**

```cpp
6
```

**Explanation:**
The bitonic sequence `{1, 2, 10, 4, 2, 1}` has a length of `6`.

#### Example 3

**Input:**

```cpp
n = 3, nums = [10, 10, 10]
```

**Output:**

```cpp
0
```

**Explanation:**
There is no strictly increasing or decreasing subsequence.

### Constraints

- `1 ≤ n ≤ 1000`
- `1 ≤ nums[i] ≤ 10000`

## Approach

1. **Compute LIS (Longest Increasing Subsequence)** for each index.
2. **Compute LDS (Longest Decreasing Subsequence)** for each index (reverse LIS calculation).
3. The **bitonic subsequence** for an index `i` is given by `dp1[i] + dp2[i] - 1`, where:
   - `dp1[i]` is the LIS ending at `i`
   - `dp2[i]` is the LIS starting at `i`
   - `-1` is to avoid double-counting the peak element.
4. Iterate over all indices to find the maximum bitonic sequence length.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        if (n == 0) return 0; // Edge case: Empty array

        vector<int> dp1(n, 1); // LIS ending at index i
        vector<int> dp2(n, 1); // LIS starting at index i (Reverse LIS)

        // Compute LIS ending at each index
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i] && 1 + dp1[p] > dp1[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[p]);
                }
            }
        }

        // Compute LIS starting at each index (Reverse LIS)
        for (int i = n - 1; i >= 0; i--) {
            for (int p = n - 1; p > i; p--) {
                if (nums[p] < nums[i] && 1 + dp2[p] > dp2[i]) {
                    dp2[i] = max(dp2[i], 1 + dp2[p]);
                }
            }
        }

        // Find maximum bitonic sequence length
        int maxi = 0;
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) // Ensure it's truly bitonic
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }

        return maxi;
    }
};
```

## Complexity Analysis

- **Computing LIS:** `O(n^2)`
- **Computing Reverse LIS:** `O(n^2)`
- **Final Computation:** `O(n)`
- **Overall Complexity:** `O(n^2)`
- **Space Complexity:** `O(n)` (for `dp1` and `dp2` arrays)

## How to Run the Code

### For C++

1. Save the code in a file `bitonic_subsequence.cpp`.
2. Compile using:

   ```sh
   g++ bitonic_subsequence.cpp -o bitonic_subsequence
   ```

3. Run the executable:

   ```sh
   ./bitonic_subsequence
   ```

---

This solution efficiently computes the **Longest Bitonic Subsequence** using **Dynamic Programming**. 🚀 Let me know if you need further optimizations or explanations!

## Other Solutions

### My Submission

```cpp
int longestBitonicSubsequence(vector<int> &arr, int n)
{
  // Write your code here.
  if (n == 0)
    return 0; // Edge case: Empty array

  vector<int> dp1(n, 1); // LIS ending at index i
  vector<int> dp2(n, 1); // LIS starting at index i (Reverse LIS)

  // Compute LIS ending at each index
  for (int i = 1; i < n; i++)
  {
    for (int p = 0; p < i; p++)
    {
      if (arr[p] < arr[i])
      {
        dp1[i] = max(dp1[i], 1 + dp1[p]);
      }
    }
  }

  // Compute LIS starting at each index (Reverse LIS)
  for (int i = n - 2; i >= 0; i--)
  {
    for (int p = n - 1; p > i; p--)
    {
      if (arr[p] < arr[i])
      {
        dp2[i] = max(dp2[i], 1 + dp2[p]);
      }
    }
  }

  // Find maximum bitonic sequence length
  int maxi = 0;
  for (int i = 0; i < n; i++)
  {
    maxi = max(maxi, dp1[i] + dp2[i] - 1);
  }

  return maxi;
}
```

### Solution - 2

```cpp

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {

        if (n == 0) return 0; // Edge case: Empty array

        vector<int> dp1(n, 1); // LIS ending at index i
        vector<int> dp2(n, 1); // LIS starting at index i (Reverse LIS)

        // Compute LIS ending at each index
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i] && 1 + dp1[p] > dp1[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[p]);
                }
            }
        }

        // Compute LIS starting at each index (Reverse LIS)
        for (int i = n - 1; i >= 0; i--) {
            for (int p = n - 1; p > i; p--) {
                if (nums[p] < nums[i] && 1 + dp2[p] > dp2[i]) {
                    dp2[i] = max(dp2[i], 1 + dp2[p]);
                }
            }
        }

        // Find maximum bitonic sequence length
        int maxi = 0;
        for (int i = 0; i < n; i++) {

            if(dp1[i] > 1 && dp2[i] > 1)
            maxi = max(maxi, dp1[i] + dp2[i] - 1);
        }

        return maxi;
    }
};
```
