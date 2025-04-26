# Search in Rotated Sorted Array II

## Table of Contents

- [Search in Rotated Sorted Array II](#search-in-rotated-sorted-array-ii)
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

---

## Introduction

This problem is a variant of binary search in a rotated sorted array, with an added challenge—**the array may contain duplicates**. The task is to determine whether a given target value exists in the array. The presence of duplicates requires handling ambiguous midpoints during the binary search process.

---

## Problem Description

You are given an integer array `nums` that is sorted in **non-decreasing order**, then rotated at an unknown pivot. Your task is to determine if a given `target` is present in the array. The array **may contain duplicates**, and you must optimize the search as much as possible.

### Examples

#### Example 1

**Input:**  
`nums = [2, 5, 6, 0, 0, 1, 2], target = 0`  
**Output:**  
`true`

#### Example 2

**Input:**  
`nums = [2, 5, 6, 0, 0, 1, 2], target = 3`  
**Output:**  
`false`

---

### Constraints

- \( 1 \leq \text{nums.length} \leq 5000 \)
- \( -10^4 \leq \text{nums}[i], \text{target} \leq 10^4 \)
- Array is guaranteed to be rotated at some pivot
- Duplicates are allowed

---

## Approach

This problem uses a **modified binary search**:

1. Initialize two pointers: `low` and `high`.
2. While `low <= high`:
   - Calculate the midpoint.
   - If `nums[mid] == target`, return true.
   - If duplicates are found at `low`, `mid`, and `high`, move both ends inward to skip ambiguity.
   - Determine which half is sorted.
   - If the target is within the sorted half, adjust `low` and `high` accordingly.
   - Repeat until found or the range is exhausted.

**Handling duplicates** is crucial. When `nums[low] == nums[mid] == nums[high]`, we can't decide which side is sorted, so we reduce the range by incrementing `low` and decrementing `high`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) return true;

            // Handle duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};
```

---

## Complexity Analysis

| Complexity | Value                                                         |
| ---------- | ------------------------------------------------------------- |
| Time       | O(log n) in best case, O(n) in worst case (due to duplicates) |
| Space      | O(1)                                                          |

- **Time Complexity:** Average case is O(log n). However, in the **worst case with many duplicates**, each step may only eliminate one element, degrading to O(n).
- **Space Complexity:** Constant extra space is used.

---

## How to Run the Code

### For C++

1. **Include necessary headers:**

   ```cpp
   #include <iostream>
   #include <vector>
   using namespace std;
   ```

2. **Sample main function:**

   ```cpp
   int main() {
       Solution sol;
       vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
       int target = 0;
       cout << (sol.search(nums, target) ? "Found" : "Not Found") << endl;
       return 0;
   }
   ```

3. **Compile and run:**

   ```bash
   g++ -o search_rotated search_rotated.cpp
   ./search_rotated
   ```

---
