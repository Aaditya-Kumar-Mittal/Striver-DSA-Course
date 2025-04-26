# StackOverflow

## Table of Contents

- [StackOverflow](#stackoverflow)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Approach 1: Using `std::is_sorted_until`](#approach-1-using-stdis_sorted_until)
    - [Approach 2: Simple Counting Method](#approach-2-simple-counting-method)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

This document discusses the solution to LeetCode Problem **1752. Check if Array Is Sorted and Rotated**.  
We determine whether an array is sorted in non-decreasing order and rotated any number of times (including zero).  
We explore two methods:  

- A **pivot-based approach** using `std::is_sorted_until`.
- A **simple counting method** using basic iteration.
- [Link](https://stackoverflow.com/questions/78106553/check-if-array-is-sorted-and-rotated-on-leetcode)

---

## Problem Description

Given an array `nums`, return `true` if the array was originally sorted in non-decreasing order, and then rotated some number of times.  
Return `false` otherwise.

Duplicates **are allowed**.

An array **A** rotated by **x** positions results in array **B** where:

```bash
B[i] = A[(i + x) % A.length]
```

### Examples

**Example 1:**

```bash
Input: nums = [3,4,5,1,2]
Output: true
Explanation: [1,2,3,4,5] rotated 3 times results in [3,4,5,1,2]
```

**Example 2:**

```bash
Input: nums = [2,1,3,4]
Output: false
Explanation: This is not a rotated version of a sorted array.
```

**Example 3:**

```bash
Input: nums = [1,2,3]
Output: true
Explanation: Already sorted without any rotation.
```

**Example 4:**

```bash
Input: nums = [1,1,1]
Output: true
Explanation: All elements are equal and array is trivially sorted.
```

### Constraints

- `1 <= nums.length <= 100`
- `0 <= nums[i] <= 100`

---

## Approach

We discuss two approaches:

### Approach 1: Using `std::is_sorted_until`

- Find the **pivot** where array stops being sorted.
- Verify that:
  - The second part (from pivot to end) is sorted.
  - The last element is less than or equal to the first element.
- If the array is fully sorted (pivot is `nums.end()`), directly return `true`.

### Approach 2: Simple Counting Method

- Count the number of places where a number is **greater** than the next number (circularly).
- If this "drop" happens **more than once**, array cannot be a rotation of a sorted array.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <algorithm>

class Solution {
public:
    // Approach 1: Using pivot and sorted_until
    bool checkPivotMethod(const std::vector<int>& nums) {
        auto pivot = std::is_sorted_until(nums.begin(), nums.end());

        // Fully sorted case
        if (pivot == nums.end()) return true;

        // Check if pivot to end is sorted and last <= first
        return std::is_sorted(pivot, nums.end()) && nums.back() <= nums.front();
    }

    // Approach 2: Using simple count of unsorted places
    bool checkCountingMethod(const std::vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        return count <= 1;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

public class Solution {
    
    // Approach 1: Using pivot and sorted_until logic manually
    public boolean checkPivotMethod(int[] nums) {
        int pivot = -1;
        
        for (int i = 0; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                pivot = i + 1;
                break;
            }
        }
        
        if (pivot == -1) return true; // Fully sorted
        
        for (int i = pivot; i < nums.length - 1; i++) {
            if (nums[i] > nums[i + 1]) return false;
        }
        
        return nums[nums.length - 1] <= nums[0];
    }

    // Approach 2: Using simple counting method
    public boolean checkCountingMethod(int[] nums) {
        int count = 0;
        int n = nums.length;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }
        
        return count <= 1;
    }
}
```

---

## Complexity Analysis

| Approach                  | Time Complexity | Space Complexity |
|:---------------------------|:----------------|:-----------------|
| Pivot Method               | O(n)            | O(1)             |
| Simple Counting Method     | O(n)            | O(1)             |

- We only traverse the array once in both methods.
- No extra space apart from variables.

---

## How to Run the Code

### For C++

1. Save the code in a file named `solution.cpp`.
2. Compile using:

   ```bash
   g++ -std=c++17 solution.cpp -o solution
   ```

3. Run:

   ```bash
   ./solution
   ```

### For Java

1. Save the code in a file named `Solution.java`.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run:

   ```bash
   java Solution
   ```

---
