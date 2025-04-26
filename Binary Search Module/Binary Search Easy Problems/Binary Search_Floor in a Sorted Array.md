# Floor in a Sorted Array

## Table of Contents

- [Floor in a Sorted Array](#floor-in-a-sorted-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Key Points](#key-points)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

The task is to find the **floor** of a given number `x` in a sorted array `arr[]`.  
The floor of `x` is defined as the **largest element** in the array which is **less than or equal to** `x`.  
If no such element exists (i.e., all elements are greater than `x`), we return `-1`.  
The array is sorted in **ascending order**, and efficient search is crucial, especially given large input constraints.

---

## Problem Description

Given:

- A **sorted array** `arr[]`
- An integer value `x`

You need to:

- Find the index (0-based) of the largest element that is less than or equal to `x`.
- If multiple such elements exist (duplicates), **return the last occurrence** (highest index).
- If no such element exists, **return `-1`**.

### Examples

**Example 1:**

```bash
Input:
arr[] = [1, 2, 8, 10, 10, 12, 19]
x = 5

Output:
1

Explanation:
Largest number ≤ 5 is 2, at index 1.
```

**Example 2:**

```bash
Input:
arr[] = [1, 2, 8, 10, 10, 12, 19]
x = 11

Output:
4

Explanation:
Largest number ≤ 11 is 10.
10 appears at indices 3 and 4. We return the index of the last occurrence, which is 4.
```

**Example 3:**

```bash
Input:
arr[] = [1, 2, 8, 10, 10, 12, 19]
x = 0

Output:
-1

Explanation:
No number ≤ 0 exists. Hence, return -1.
```

### Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `0 ≤ x ≤ arr[n-1]`

---

## Approach

- We use **Binary Search** for efficient lookup because the array is **sorted**.
- Initialize two pointers:
  - `low = 0` (start of array)
  - `high = n-1` (end of array)
- Initialize an answer variable `ans = -1`.
- Perform binary search:
  - Find `mid = (low + high)/2`.
  - If `arr[mid]` is **less than or equal to `x`**, we update `ans = mid` and move to the **right half** (`low = mid + 1`) because we are looking for the largest index.
  - If `arr[mid]` is **greater than `x`**, move to the **left half** (`high = mid - 1`).
- After the loop, `ans` will either be:
  - The index of the floor element.
  - `-1` if no floor element exists.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int findFloor(vector<int>& arr, int x) {
        // Get the size of the array
        int n = arr.size();

        // Initialize low and high pointers
        int low = 0, high = n - 1;

        // Initialize answer to -1 (in case no floor is found)
        int ans = -1;

        // Binary Search
        while (low <= high) {
            // Calculate mid-point safely to avoid overflow
            int mid = low + (high - low) / 2;

            // If the mid element is less than or equal to x
            if (arr[mid] <= x) {
                ans = mid;           // Update answer
                low = mid + 1;        // Search in the right half for possibly larger value
            }
            else {
                high = mid - 1;        // Search in the left half
            }
        }

        // Return the answer
        return ans;
    }
};
```

#### Key Points

- We update `ans` every time we find `arr[mid] <= x`.
- Always look for a potentially **larger index** on the right side to satisfy the "last occurrence" requirement.

---

## Complexity Analysis

| Type                 | Complexity                   |
| -------------------- | ---------------------------- |
| **Time Complexity**  | `O(log n)`                   |
| **Space Complexity** | `O(1)` (no extra space used) |

**Explanation:**

- **Time Complexity** is logarithmic (`log n`) because we halve the search space at each step (binary search).
- **Space Complexity** is constant (`O(1)`) since only a few variables are used.

---

## How to Run the Code

### For C++

1. Install any C++ compiler (like g++, clang).
2. Save the code in a file, say `solution.cpp`.
3. Open a terminal and navigate to the file's location.
4. Compile the file:

   ```bash
   g++ solution.cpp -o solution
   ```

5. Run the executable:

   ```bash
   ./solution
   ```

6. You can integrate the `Solution` class into a test driver (`main` function) for quick testing.

---
