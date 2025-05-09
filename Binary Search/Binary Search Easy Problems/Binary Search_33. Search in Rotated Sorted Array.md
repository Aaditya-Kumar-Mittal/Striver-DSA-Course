# Search in Rotated Sorted Array

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Search in Rotated Sorted Array](#search-in-rotated-sorted-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Sample Test Case in Main](#sample-test-case-in-main)
  - [Detailed Explanation of Code](#detailed-explanation-of-code-1)
    - [Key Insight](#key-insight)
    - [Code Walkthrough (C++ Version)](#code-walkthrough-c-version)
    - [Step-by-Step Algorithm](#step-by-step-algorithm)
    - [Dry Run Example](#dry-run-example)
      - [Input](#input)
    - [Why Identify the Sorted Half?](#why-identify-the-sorted-half)
    - [Time and Space Complexity](#time-and-space-complexity)

---

## Introduction

In this problem, we are given a rotated version of a sorted array and a target value. Our goal is to return the **index** of the target if found, otherwise return **-1**. The key requirement is achieving **O(log n)** time complexity, which suggests using **binary search**.

---

## Problem Description

An array of distinct integers `nums` is originally sorted in **ascending order** but is possibly **rotated** at some pivot. For example:

- Original: `[0, 1, 2, 4, 5, 6, 7]`
- Rotated: `[4, 5, 6, 7, 0, 1, 2]` (rotated at index 3)

You are given this rotated array and an integer `target`. You must return the index of `target` if it exists in the array, else return `-1`.

### Examples

#### Example 1

**Input:**  
`nums = [4,5,6,7,0,1,2]`, `target = 0`  
**Output:** `4`  
**Explanation:** 0 is at index 4 in the rotated array.

#### Example 2

**Input:**  
`nums = [4,5,6,7,0,1,2]`, `target = 3`  
**Output:** `-1`  
**Explanation:** 3 is not present in the array.

#### Example 3

**Input:**  
`nums = [1]`, `target = 0`  
**Output:** `-1`

---

## Constraints

- `1 <= nums.length <= 5000`
- `-10^4 <= nums[i] <= 10^4`
- All elements in `nums` are **distinct**
- `nums` is an ascending sorted array, possibly rotated
- `-10^4 <= target <= 10^4`

---

## Approach

The problem can be efficiently solved using **modified binary search**. At each step, we determine which half of the array is **sorted** and then decide whether the `target` lies in the sorted half or the unsorted one.

### Steps

1. Use binary search to find `mid = (low + high) / 2`.
2. If `nums[mid] == target`, return `mid`.
3. Determine which part is sorted:
   - If `nums[low] <= nums[mid]`: Left half is sorted.
   - Else: Right half is sorted.
4. Based on the sorted half, check if `target` lies within it.
   - If yes, move the `low` or `high` accordingly to continue the search.
   - If not, discard that half and search in the other half.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {

        auto lb = lower_bound(nums.begin(), nums.end(), target);

        return lb - nums.begin();
    }
};
```

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return mid;

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // Target is in the left sorted half
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                // Target is in the right sorted half
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};
```

---

## Complexity Analysis

- ⏱️ **Time Complexity:** `O(log n)`
  Binary search ensures logarithmic time by halving the search space each step.

- 🧠 **Space Complexity:** `O(1)`
  No extra space is used apart from variables for indices.

---

## How to Run the Code

### For C++

1. Save the file as `search_rotated.cpp`.
2. Add a test `main()` function to pass sample inputs.
3. Compile and run:

```bash
g++ -o search_rotated search_rotated.cpp
./search_rotated
```

### Sample Test Case in Main

```cpp
int main() {
    Solution sol;
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    cout << "Index of target: " << sol.search(nums, target) << endl;
    return 0;
}
```

## Detailed Explanation of Code

This problem involves searching for a target value in a rotated sorted array using a modified version of **binary search**. Though the array is rotated, we can still utilize binary search by identifying the **sorted portion** of the array in each step and narrowing our search accordingly.

### Key Insight

In any rotated sorted array, **at least one half (left or right) is always sorted**. This observation is crucial for binary search to work here in O(log n) time.

### Code Walkthrough (C++ Version)

```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Case 1: Target found
            if (nums[mid] == target) return mid;

            // Case 2: Left half is sorted
            if (nums[low] <= nums[mid]) {
                // Check if target lies within the sorted left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Case 3: Right half is sorted
            else {
                // Check if target lies within the sorted right half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};
```

---

### Step-by-Step Algorithm

1. **Initialization**

   - Set two pointers: `low = 0` and `high = nums.size() - 1`.

2. **Binary Search Loop**

   - While `low <= high`:
     - Compute `mid = (low + high) / 2`.

3. **Check for Target**

   - If `nums[mid] == target`: return `mid`.

4. **Determine Sorted Half**

   - **Left half sorted**: If `nums[low] <= nums[mid]`
     - If `nums[low] <= target < nums[mid]`: Target is in the left half → `high = mid - 1`.
     - Else: Target is in the right half → `low = mid + 1`.
   - **Right half sorted**: Else
     - If `nums[mid] < target <= nums[high]`: Target is in the right half → `low = mid + 1`.
     - Else: Target is in the left half → `high = mid - 1`.

5. **Return -1** if loop ends without finding the target.

---

### Dry Run Example

#### Input

```cpp
nums = [4,5,6,7,0,1,2]
target = 0
```

- Initial pointers: `low=0`, `high=6`, `mid=3 → nums[mid]=7`
- Left half `[4,5,6,7]` is sorted.
- Target `0` not in left half → move `low = mid + 1 = 4`

- Now: `low=4`, `high=6`, `mid=5 → nums[mid]=1`
- Left half `[0,1]` is sorted.
- Target `0` is in left half → move `high = mid - 1 = 4`

- Now: `low=4`, `high=4`, `mid=4 → nums[mid]=0`
- Target found! Return `4`

---

### Why Identify the Sorted Half?

It's difficult to reason about the side of the array that is **not** sorted. However, by identifying the **sorted** half, we can confidently say whether the `target` lies in that half or not. This allows us to effectively reduce our search space every time, maintaining O(log n) complexity.

---

### Time and Space Complexity

- **Time Complexity**: `O(log n)` — each step halves the search range.
- **Space Complexity**: `O(1)` — no extra space used.

---
