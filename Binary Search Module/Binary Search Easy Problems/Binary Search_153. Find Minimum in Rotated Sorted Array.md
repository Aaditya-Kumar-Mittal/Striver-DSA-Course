# Find Minimum in Rotated Sorted Array

## Table of Contents

- [Find Minimum in Rotated Sorted Array](#find-minimum-in-rotated-sorted-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Key Insights](#key-insights)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In this problem, you are given a **sorted array** of unique integers, which has been **rotated** at an unknown pivot. Your task is to find the **minimum element** in this rotated array. The array was originally sorted in ascending order, and after rotating it, you need to identify the minimum element in `O(log n)` time.

This problem can be solved efficiently using **binary search**.

---

## Problem Description

Given a sorted and rotated array `nums` of unique integers, return the **minimum element** in the array. The array was originally sorted in ascending order and then rotated at some pivot.

### Example 1

```plaintext
Input: nums = [3,4,5,1,2]

Output: 1

Explanation:
- The original array was [1,2,3,4,5], and it was rotated 3 times.
- The minimum element is 1.
```

---

### Example 2

```plaintext
Input: nums = [4,5,6,7,0,1,2]

Output: 0

Explanation:
- The original array was [0,1,2,4,5,6,7], and it was rotated 4 times.
- The minimum element is 0.
```

---

### Example 3

```plaintext
Input: nums = [11,13,15,17]

Output: 11

Explanation:
- The original array was [11,13,15,17], and it was rotated 4 times.
- The minimum element is 11.
```

---

### Constraints

- `n == nums.length`
- `1 ≤ n ≤ 5000`
- `-5000 ≤ nums[i] ≤ 5000`
- All the integers of `nums` are unique.
- `nums` is sorted and rotated between `1` and `n` times.

---

## Approach

The **rotated sorted array** has a property where the smallest element is the only one that is smaller than its previous element. Using **binary search**, we can find the minimum element by checking certain conditions based on the current segment of the array.

### Steps

1. Initialize:
   - `low = 0`
   - `high = n - 1`
   - `ans = INT_MAX` (to store the minimum element found)
2. While `low <= high`:

   - If `nums[low] <= nums[high]`, it means the subarray from `low` to `high` is already sorted, and the smallest element is at `low`.
   - Otherwise, compare `nums[mid]` with `nums[low]` to decide whether to search the left or right subarray:
     - If `nums[low] <= nums[mid]`, then the minimum must be in the right half, so set `low = mid + 1`.
     - If `nums[low] > nums[mid]`, then the minimum is in the left half, so set `high = mid - 1`.

3. Return the minimum element.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
// User function Template for C++
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;  // Initialize ans to the maximum integer
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the subarray is sorted, the minimum is at 'low'
            if (nums[low] <= nums[high]) {
                ans = min(ans, nums[low]);
                break;  // Exit the loop since the minimum is found
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);  // The minimum could be at low
                low = mid + 1;  // Search in the right half
            } else {
                ans = min(ans, nums[mid]);  // The minimum could be at mid
                high = mid - 1;  // Search in the left half
            }
        }

        return ans;  // Return the minimum found
    }
};
```

### Key Insights

- **Binary Search** is applied to the rotated sorted array.
- We check whether the left half of the array is sorted, and if it is, the minimum element is in the right half.
- The condition `nums[low] <= nums[high]` is used to detect when the array is fully sorted.

---

## Complexity Analysis

| Complexity                  | Time       | Space  |
| --------------------------- | ---------- | ------ |
| **Best/Average/Worst Case** | `O(log N)` | `O(1)` |

- **Time Complexity:**

  - We halve the search space with each iteration of the loop ⇒ `O(log N)`.

- **Space Complexity:**
  - The algorithm uses a constant amount of space ⇒ `O(1)`.

---

## How to Run the Code

### For C++

1. Save the code in a file named `solution.cpp`.
2. Open terminal/command prompt and compile the code:

   ```bash
   g++ solution.cpp -o solution
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

---
