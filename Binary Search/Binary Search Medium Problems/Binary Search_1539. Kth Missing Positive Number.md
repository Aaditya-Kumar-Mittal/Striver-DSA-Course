# Kth Missing Positive Number

## Table of Contents

- [Kth Missing Positive Number](#kth-missing-positive-number)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The goal of this problem is to find the **k-th missing positive number** from a strictly increasing, sorted array of positive integers.

Two approaches are implemented:

- **Brute-force method** (Linear scan)
- **Optimized method** (Binary search)

## Problem Description

Given:

- An array `arr` of positive integers sorted in strictly increasing order.
- An integer `k`.

We need to return the **k-th missing positive integer** from this sequence.

### Examples

**Example 1:**

> Input: `arr = [2, 3, 4, 7, 11]`, `k = 5`  
> Output: `9`  
> Explanation:  
> Missing numbers are `[1, 5, 6, 8, 9, 10, 12, 13, ...]`.  
> The 5th missing number is `9`.

---

**Example 2:**

> Input: `arr = [1, 2, 3, 4]`, `k = 2`  
> Output: `6`  
> Explanation:  
> Missing numbers are `[5, 6, 7, ...]`.  
> The 2nd missing number is `6`.

---

### Constraints

- `1 <= arr.length <= 1000`
- `1 <= arr[i] <= 1000`
- `1 <= k <= 1000`
- `arr[i] < arr[j]` for all `1 <= i < j <= arr.length`

## Approach

We have two approaches:

1. **Brute-force Approach**:

   - Traverse the array while adjusting `k` when encountering numbers smaller than or equal to `k`.
   - Each time we pass a number `<= k`, it means that number already exists, so we need to look for one more missing number.

2. **Optimized Approach (Binary Search)**:
   - Find how many numbers are missing up to each index (`arr[i] - (i + 1)`).
   - Use binary search to efficiently locate where the k-th missing number lies.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Brute Force Approach
    int findKthPositiveBrute(vector<int>& arr, int k) {
        if (k < arr[0])
            return k;

        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] <= k)
                k++;
            else
                break;
        }

        return k;
    }

    // Optimized Binary Search Approach
    int findKthPositive(vector<int>& arr, int k) {
        if (k < arr[0])
            return k;

        int n = arr.size();
        // If k is greater than the total missing numbers in array
        if (k > arr[n - 1] - n)
            return k + n;

        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid + 1);

            if (missing < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return low + k;
    }
};
```

---

## Complexity Analysis

| Approach      | Time Complexity | Space Complexity | Explanation                                               |
| :------------ | :-------------: | :--------------: | :-------------------------------------------------------- |
| Brute Force   |      O(n)       |       O(1)       | We may traverse the entire array once adjusting `k`.      |
| Binary Search |    O(log n)     |       O(1)       | We use binary search to find the missing number position. |

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `solution.cpp`.
2. Compile the code:

   ```bash
   g++ solution.cpp -o solution
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

---
