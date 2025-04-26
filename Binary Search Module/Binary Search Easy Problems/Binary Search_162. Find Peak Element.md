# Find Peak Element

<!-- markdownlint-disable MD033-->

## Table of Contents

- [Find Peak Element](#find-peak-element)
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

The goal of this problem is to find a peak element in a given array. An element is considered a peak if it is strictly greater than its neighbors. We are guaranteed that adjacent elements are not equal, which helps us find a peak efficiently.

## Problem Description

Given a 0-indexed integer array `nums`, find a peak element and return its index. If the array contains multiple peaks, return the index of any one of the peaks. The solution must be in **O(log n)** time complexity.

### Examples

**Example 1:**

```plaintext
Input: nums = [1, 2, 3, 1]
Output: 2
Explanation: 3 is a peak element and its index is 2.
```

**Example 2:**

```plaintext
Input: nums = [1, 2, 1, 3, 5, 6, 4]
Output: 5
Explanation: 6 is a peak element at index 5, but index 1 (element 2) is also a peak.
```

### Constraints

- 1 <= nums.length <= 1000
- -2<sup>31</sup> <= nums[i] <= 2<sup>31</sup> - 1
- `nums[i] != nums[i + 1]` for all valid `i`

## Approach

To achieve O(log n) time complexity, we use a **Binary Search** approach:

1. Check the boundaries:

   - If the first element is greater than the second, it's a peak.
   - If the last element is greater than the second last, it's a peak.

2. Perform binary search between index 1 and n-2:
   - For mid index:
     - If `nums[mid] > nums[mid - 1]` and `nums[mid] > nums[mid + 1]`, return `mid`.
     - If `nums[mid] > nums[mid - 1]`, shift to the right (low = mid + 1).
     - If `nums[mid] > nums[mid + 1]`, shift to the left (high = mid - 1).
     - Otherwise, continue searching towards right.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();

        // Edge cases
        if (n == 1)
            return 0;

        if (nums[0] > nums[1])
            return 0;

        if (nums[n - 1] > nums[n - 2])
            return n - 1;

        int low = 1, high = n - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
                return mid;
            } else if (nums[mid] > nums[mid - 1]) {
                low = mid + 1;
            } else if (nums[mid] > nums[mid + 1]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return -1; // Will never reach here if input is valid
    }
};
```

## Complexity Analysis

- **Time Complexity:** O(log n)

  - Binary search divides the problem space in half each time.

- **Space Complexity:** O(1)
  - Only a constant amount of extra space is used.

## How to Run the Code

### For C++

1. Save the code in a file named `solution.cpp`
2. Compile using:

   ```bash
   g++ -std=c++11 solution.cpp -o solution
   ```

3. Run using:

   ```bash
   ./solution
   ```
