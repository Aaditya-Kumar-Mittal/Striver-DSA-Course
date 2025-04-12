# Find Kth Rotation

## Table of Contents

- [Find Kth Rotation](#find-kth-rotation)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [✅ Linear Search Approach (Used in current code)](#-linear-search-approach-used-in-current-code)
    - [✅ Optimized Binary Search Approach (Recommended)](#-optimized-binary-search-approach-recommended)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Code Walkthrough](#code-walkthrough)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In this problem, we are given a sorted array of **distinct** integers that has been **rotated** `k` times to the **right**. The goal is to determine the value of `k` using an efficient algorithm.

---

## Problem Description

You are given an increasing sorted array `arr` of distinct integers. The array has been rotated `k` times to the right. Your task is to find the number of rotations `k`.

### Examples

#### Example 1

```plaintext
Input: arr = [5, 1, 2, 3, 4]
Output: 1
Explanation: The original sorted array is [1, 2, 3, 4, 5].
The array was rotated once to the right.
```

#### Example 2

```plaintext
Input: arr = [1, 2, 3, 4, 5]
Output: 0
Explanation: The array is already sorted and not rotated.
```

#### Example 3

```plaintext
Input: arr = [3, 4, 5, 1, 2]
Output: 3
```

### Constraints

- `1 <= n <= 10⁵`
- `1 <= arr[i] <= 10⁷`
- All array elements are **distinct**

---

## Approach

There are two main ways to solve this problem:

### ✅ Linear Search Approach (Used in current code)

1. Find the minimum element in the array.
2. The index of the minimum element is the number of rotations `k`.

> This approach works but takes **O(n)** time.

### ✅ Optimized Binary Search Approach (Recommended)

Since the array is **sorted and rotated**, we can use binary search to find the **minimum element**, which corresponds to the number of rotations.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        
        int minEle = *min_element(arr.begin(), arr.end());
        
        int n = arr.size();
        
        int rotation = 0;
        
        for(int i = 0 ; i < n; i++)
        {
            if(arr[i] == minEle)
            {
                rotation = i;
                break;
            }
        }
        
        return rotation;
    }
};
```

```cpp
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int minEle = *min_element(arr.begin(), arr.end());  // Find the smallest element
        int n = arr.size();
        int rotation = 0;

        for(int i = 0 ; i < n; i++) {
            if(arr[i] == minEle) {
                rotation = i;  // Index of the smallest element is the number of rotations
                break;
            }
        }

        return rotation;
    }
};
```

### Code Walkthrough

- The `min_element()` function finds the smallest value in the array.
- We loop through the array to find the **index** of this minimum element.
- That index is returned as the number of times the array has been rotated.

---

## Complexity Analysis

| Metric               | Value  |
| -------------------- | ------ |
| **Time Complexity**  | `O(n)` |
| **Space Complexity** | `O(1)` |

> Although correct, this is **not the most optimal solution** due to its linear time complexity.

---

## How to Run the Code

### For C++

1. **Install g++ compiler** (if not already):

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
