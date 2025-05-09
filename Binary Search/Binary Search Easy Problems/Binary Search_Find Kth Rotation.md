# Find Kth Rotation

## Table of Contents

- [Find Kth Rotation](#find-kth-rotation)
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

In a sorted and right-rotated array of distinct integers, we are to find how many times the array has been rotated. The number of right rotations corresponds to the index of the minimum element in the array.

---

## Problem Description

You are given a sorted and rotated array `arr[]` which has been rotated `k` times to the right. Your task is to find the value of `k` — that is, the number of times the array was rotated. The solution must be efficient with logarithmic time complexity and constant space.

### Examples

#### Example 1

**Input:**  
`arr = [5, 1, 2, 3, 4]`  
**Output:**  
`1`  
**Explanation:**  
Original array: [1, 2, 3, 4, 5]  
Rotated 1 time to the right becomes: [5, 1, 2, 3, 4]  
Hence, k = 1

#### Example 2

**Input:**  
`arr = [1, 2, 3, 4, 5]`  
**Output:**  
`0`  
**Explanation:**  
Array is already sorted with no rotations. So, k = 0.

---

### Constraints

- \( 1 \leq n \leq 10^5 \)
- \( 1 \leq arr[i] \leq 10^7 \)
- Elements in the array are **distinct**.

---

## Approach

The number of rotations `k` is the index of the **minimum element** in the rotated array.

- If the subarray from `low` to `high` is already sorted (`arr[low] <= arr[high]`), then the smallest element is at index `low`, and we return `low`.
- Otherwise, apply binary search:
  - Calculate `mid = (low + high) / 2`.
  - If `arr[low] <= arr[mid]`, then the minimum must be in the right half, so set `low = mid + 1`.
  - Else, the minimum is in the left half (including `mid`), so set `high = mid`.

This approach ensures **O(log n)** time due to binary search.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int findKRotation(vector<int> &arr) {
        int n = arr.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            // If the current subarray is sorted, then the smallest element is at index 'low'
            if (arr[low] <= arr[high]) break;

            int mid = low + (high - low) / 2;

            // If left half is sorted, then the minimum is in the right half
            if (arr[low] <= arr[mid]) {
                low = mid + 1;
            } else {
                // Minimum could be at mid or to its left
                high = mid;
            }
        }

        // The index of the minimum element gives the number of rotations
        return low;
    }
};
```

---

## Complexity Analysis

| Complexity | Value        |
|------------|--------------|
| Time       | O(log n)     |
| Space      | O(1)         |

- **Time Complexity:** Efficient binary search reduces the search space logarithmically.
- **Space Complexity:** No additional space is used.

---

## How to Run the Code

### For C++

1. **Include necessary headers:**

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    ```

2. **Example main function:**

    ```cpp
    int main() {
        Solution sol;
        vector<int> arr = {5, 1, 2, 3, 4};
        cout << "The array is rotated " << sol.findKRotation(arr) << " times." << endl;
        return 0;
    }
    ```

3. **Compile and run:**

    ```bash
    g++ -o find_k_rotation find_k_rotation.cpp
    ./find_k_rotation
    ```

---
