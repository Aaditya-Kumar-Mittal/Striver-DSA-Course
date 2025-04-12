# Indexes of Subarray Sum

## Table of Contents

- [Indexes of Subarray Sum](#indexes-of-subarray-sum)
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
    - [Justification](#justification)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In this problem, we're given an array of **non-negative integers** and a **target sum**. We need to find the **first continuous subarray** (i.e., a contiguous sequence of elements) that sums up exactly to the target. The output should be the **1-based indices** of the starting and ending positions of this subarray. If no such subarray exists, return `[-1]`.

---

## Problem Description

Given:

- An array `arr[]` containing only non-negative integers.
- A target integer `target`.

Find:

- The **first** (leftmost) subarray which has a sum equal to `target`.
- Return the **1-based index** of the starting and ending position of this subarray.
- If no subarray exists with the given sum, return `[-1]`.

### Examples

#### Example 1

```plaintext
Input: arr = [1, 2, 3, 7, 5], target = 12
Output: [2, 4]
Explanation: The subarray [2, 3, 7] (indices 2 to 4) has the sum 12.
```

#### Example 2

```plaintext
Input: arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], target = 15
Output: [1, 5]
Explanation: The subarray [1, 2, 3, 4, 5] has the sum 15.
```

#### Example 3

```plaintext
Input: arr = [5, 3, 4], target = 2
Output: [-1]
Explanation: No subarray has the sum 2.
```

---

### Constraints

- `1 <= arr.size() <= 10⁶`
- `0 <= arr[i] <= 10³`
- `0 <= target <= 10⁹`

---

## Approach

This problem is a classic use case of the **sliding window technique**. Here's how it works:

1. **Initialize** a `left` and `right` pointer at the beginning of the array.
2. Keep a running `sum` of elements between `left` and `right`.
3. If the current sum is less than the target, expand the window to the right.
4. If the sum is greater than the target, contract the window from the left.
5. If the sum equals the target, return the 1-based indices `[left+1, right+1]`.

> Note: This approach works because all elements are **non-negative**, ensuring that increasing the window size only increases the sum.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int left = 0, right = 0;
        long long sum = arr[0];

        while (right < n) {
            // Shrink the window if sum is greater than target
            while (left <= right && sum > target) {
                sum -= arr[left];
                left++;
            }

            // If sum matches the target, return the indices (1-based)
            if (sum == target) {
                return {left + 1, right + 1};
            }

            // Expand the window to the right
            right++;
            if (right < n) {
                sum += arr[right];
            }
        }

        // No valid subarray found
        return {-1};
    }
};
```

---

## Complexity Analysis

| Metric              | Value         |
|---------------------|---------------|
| **Time Complexity** | `O(n)`        |
| **Space Complexity**| `O(1)`        |

### Justification

- Each element is **visited at most twice**, once by `right` and once by `left`, resulting in linear time complexity.
- Only a few integer variables are used, so space complexity is constant.

---

## How to Run the Code

### For C++

1. **Install g++ compiler** (if not already installed):

   ```bash
   sudo apt install g++
   ```

2. **Save the code in a file**, e.g., `main.cpp`.

3. **Compile and Run**:

   ```bash
   g++ main.cpp -o output
   ./output
   ```

---
