# Minimum Number of Removals to Make Mountain Array

<!-- markdownlint-disable MD024-->

## Table of Contents

- [Minimum Number of Removals to Make Mountain Array](#minimum-number-of-removals-to-make-mountain-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1 (My Leetcode Submission)](#solution---1-my-leetcode-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
      - [Problem Statement](#problem-statement)
      - [Approach](#approach-1)
        - [Approach 1: LIS Using Dynamic Programming](#approach-1-lis-using-dynamic-programming)
        - [Algorithm](#algorithm)
        - [Complexity Analysis](#complexity-analysis-1)
      - [Approach 2: LIS Using Binary Search](#approach-2-lis-using-binary-search)
        - [Intuition](#intuition)
        - [Algorithm](#algorithm-1)
        - [Complexity Analysis](#complexity-analysis-2)
    - [Summary](#summary)

## Introduction

Given an integer array `nums`, we need to find the **minimum number of elements** to remove in order to make `nums` a **mountain array**.

A **mountain array** is defined as follows:

- The array length must be at least 3.
- There exists some peak index `i` (`0 < i < nums.length - 1`) such that:
  - `nums[0] < nums[1] < ... < nums[i]` (strictly increasing sequence before the peak)
  - `nums[i] > nums[i+1] > ... > nums[nums.length - 1]` (strictly decreasing sequence after the peak)

## Problem Description

### Examples

#### Example 1

**Input:**

```cpp
nums = [1,3,1]
```

**Output:**

```cpp
0
```

**Explanation:** The array itself is a mountain array, so no elements need to be removed.

#### Example 2

**Input:**

```cpp
nums = [2,1,1,5,6,2,3,1]
```

**Output:**

```cpp
3
```

**Explanation:** One possible solution is to remove elements at indices `0, 1,` and `5`, making the array `[1,5,6,3,1]` a valid mountain array.

### Constraints

- `3 <= nums.length <= 1000`
- `1 <= nums[i] <= 10^9`
- It is guaranteed that a mountain array can be formed.

## Approach

1. Compute the **Longest Increasing Subsequence (LIS)** ending at each index.
2. Compute the **Longest Decreasing Subsequence (LDS)** starting at each index.
3. Identify the valid **mountain peak indices**, ensuring that LIS and LDS both have values greater than 1.
4. The maximum length of a valid mountain sequence is `max(LIS[i] + LDS[i] - 1)` for valid peaks.
5. The minimum removals needed = `n - maxMountainLength`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return 0; // Mountain sequence must have at least 3 elements

        vector<int> dp1(n, 1); // LIS ending at index i
        vector<int> dp2(n, 1); // LDS starting at index i

        // Compute LIS ending at each index
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[p]);
                }
            }
        }

        // Compute LDS starting at each index
        for (int i = n - 1; i >= 0; i--) {
            for (int p = n - 1; p > i; p--) {
                if (nums[p] < nums[i]) {
                    dp2[i] = max(dp2[i], 1 + dp2[p]);
                }
            }
        }

        // Find the longest valid mountain sequence
        int maxMountainLength = 0;
        for (int i = 1; i < n - 1; i++) { // Peak cannot be the first or last element
            if (dp1[i] > 1 && dp2[i] > 1) { // Valid peak condition
                maxMountainLength = max(maxMountainLength, dp1[i] + dp2[i] - 1);
            }
        }

        return maxMountainLength > 0 ? (n - maxMountainLength) : 0;
    }
};
```

## Complexity Analysis

- **Computing LIS:** `O(n^2)` (nested loops)
- **Computing LDS:** `O(n^2)` (nested loops)
- **Finding valid peak:** `O(n)`
- **Overall Complexity:** `O(n^2)` (since LIS and LDS computations dominate the runtime)

## How to Run the Code

### For C++

1. Compile the code using:

   ```sh
   g++ -o solution solution.cpp -std=c++17
   ```

2. Run the executable:

   ```sh
   ./solution
   ```

3. Provide the input in the `nums` array and test accordingly.

---

This documentation follows a structured approach to describe the problem, solution, and implementation details in a clear and detailed manner.

## Other Solutions

### Solution - 1 (My Leetcode Submission)

```cpp
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return 0; // Mountain sequence must have at least 3 elements

        vector<int> dp1(n, 1); // LIS ending at index i
        vector<int> dp2(n, 1); // LIS starting at index i (Reverse LIS)

        // Compute LIS ending at each index
        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i]) {
                    dp1[i] = max(dp1[i], 1 + dp1[p]);
                }
            }
        }

        // Compute LIS starting at each index (Reverse LIS)
        for (int i = n - 1; i >= 0; i--) {
            for (int p = n - 1; p > i; p--) {
                if (nums[p] < nums[i]) {
                    dp2[i] = max(dp2[i], 1 + dp2[p]);
                }
            }
        }

        // Find the valid mountain sequence
        int maxi = 0;
        for (int i = 1; i < n - 1;
             i++) { // Peak cannot be first or last element
            if (dp1[i] > 1 && dp2[i] > 1) { // Valid peak condition
                maxi = max(maxi, dp1[i] + dp2[i] - 1);
            }
        }

        return maxi > 0 ? (n - maxi) : 0; // If no valid mountain, return 0
    }
};
```

### Solution - 2

```cpp
class Solution {
public:

    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lis(N, -1), lds(N, -1);
        vector<int> seq({nums[0]}), dseq({nums[N-1]});

        for(int i=1; i<N-1; i++) {
            if(seq.back() < nums[i]) seq.push_back(nums[i]);
            else {
                int idx = lower_bound(seq.begin(), seq.end(), nums[i])-seq.begin();
                seq[idx] = nums[i];
            }
            lis[i] = seq.size();

            int j = N - 1 - i;
            if(dseq.back() < nums[j]) dseq.push_back(nums[j]);
            else {
                int idx = lower_bound(dseq.begin(), dseq.end(), nums[j])-dseq.begin();
                dseq[idx] = nums[j];
            }
            lds[j] = dseq.size();
        }
        int ans = N+1;
        for(int i=1; i<N-1; i++) {
            if(lis[i] > 1 and lds[i] > 1)
                ans = min(ans, N-(lis[i]+lds[i]-1));
        }
        return ans;
    }
};
```

### Solution - 3

#### Problem Statement

We are given an array `nums` of length `N`, and our task is to determine the **minimum number of elements** to remove in order to transform it into a **mountain array**.

A **mountain array** is defined as one that first strictly increases to a **peak** element at an index `i`, then strictly decreases after that. The sequence should not be flat at any point.

#### Approach

To solve this problem, we must choose a **peak element** at index `i` such that:

- The left subarray `nums[0...i]` forms a **strictly increasing** sequence.
- The right subarray `nums[i...N - 1]` forms a **strictly decreasing** sequence.

For each candidate index `i`:

- Let `L1` be the length of the **Longest Increasing Subsequence (LIS)** that **ends** at index `i`.
- Let `L2` be the length of the **Longest Decreasing Subsequence (LDS)** that **starts** at index `i`.

The **total number of elements to remove** to make `i` the peak is:

\[ \text{removals} = (i + 1 - L1) + (N - i - L2) = N + 1 - L1 - L2 \]

This formula calculates the total removals required if `i` is chosen as the peak element.

Thus, our solution boils down to evaluating each index `i` as a **potential peak** and determining the lengths of ordered subsequences on both sides of it.

##### Approach 1: LIS Using Dynamic Programming

Instead of calculating LIS and LDS for each index on the fly (which is inefficient), we **precompute** them for all indices.

To find these lengths, we use **Dynamic Programming (DP)** similar to the approach in **"300. Longest Increasing Subsequence."**

- **Step 1:** Compute LIS for each index `i` (left-to-right pass).
- **Step 2:** Compute LDS for each index `i` (right-to-left pass).
- **Step 3:** Iterate over all indices and calculate the minimum removals required.

##### Algorithm

1. **Initialize LIS and LDS arrays:**
   - Create two arrays `lisLength` and `ldsLength` of size `N`, initialized to `1`.
2. **Compute LIS (Longest Increasing Subsequence) from left to right:**
   - For each index `i`, iterate through all indices `j < i`.
   - If `nums[i] > nums[j]`, update LIS length:
     \[ \text{lisLength}[i] = \max(\text{lisLength}[i], \text{lisLength}[j] + 1) \]
3. **Compute LDS (Longest Decreasing Subsequence) from right to left:**
   - For each index `i`, iterate through all indices `j > i`.
   - If `nums[i] > nums[j]`, update LDS length:
     \[ \text{ldsLength}[i] = \max(\text{ldsLength}[i], \text{ldsLength}[j] + 1) \]
4. **Find the minimum removals:**
   - Iterate over all indices `i`.
   - If `lisLength[i] > 1` and `ldsLength[i] > 1` (valid peak condition), compute:
     \[ \text{removals} = N - (\text{lisLength}[i] + \text{ldsLength}[i] - 1) \]
   - Return the **minimum** removals.

##### Complexity Analysis

- **Time Complexity:** \( O(N^2) \) due to nested loops in LIS and LDS computations.
- **Space Complexity:** \( O(N) \) for storing `lisLength` and `ldsLength` arrays.

---

#### Approach 2: LIS Using Binary Search

##### Intuition

This approach is similar to the **Dynamic Programming** method but **optimizes LIS and LDS calculations** using **Binary Search**, reducing time complexity.

Instead of using **nested loops**, we use **Binary Search with a patience sorting strategy** to construct the LIS in `O(N log N)` time.

##### Algorithm

1. **Define a helper function `getLongestIncreasingSubsequenceLength(v)`:**

   - Maintain an array `lis` storing the LIS sequence.
   - Use **binary search** (lower bound) to find the correct position of each `v[i]` in `lis`.
   - If `v[i]` is larger than all elements, append it.
   - Otherwise, replace the first larger element.
   - Store `lisLength[i] = len(lis)` at each index.

2. **Compute LIS for left-to-right and LDS for right-to-left:**

   - Use `getLongestIncreasingSubsequenceLength(nums)` for LIS.
   - Reverse `nums` and apply the same function for LDS.
   - Reverse LDS array back to align with the original indices.

3. **Compute minimum removals:**
   - Iterate over all indices `i`.
   - If `lisLength[i] > 1` and `ldsLength[i] > 1`, compute:
     \[ \text{removals} = N - (\text{lisLength}[i] + \text{ldsLength}[i] - 1) \]
   - Return the **minimum** removals.

##### Complexity Analysis

- **Time Complexity:** \( O(N \log N) \)
  - Computing LIS and LDS with **Binary Search** reduces time complexity to `O(N log N)`.
  - Final pass over `nums` for computing removals takes `O(N)`, so overall is `O(N log N)`.
- **Space Complexity:** \( O(N) \)
  - Uses arrays `lisLen` and `ldsLen` of size `N`.

### Summary

| Approach                       | Time Complexity   | Space Complexity |
| ------------------------------ | ----------------- | ---------------- |
| **Dynamic Programming (DP)**   | \( O(N^2) \)      | \( O(N) \)       |
| **Binary Search Optimization** | \( O(N \log N) \) | \( O(N) \)       |

The **Binary Search Optimization** is more efficient than the DP-based approach, making it the preferred choice for larger values of `N`.
