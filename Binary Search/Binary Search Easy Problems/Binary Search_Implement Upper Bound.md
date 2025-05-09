# Implement Upper Bound

## Table of Contents

- [Implement Upper Bound](#implement-upper-bound)
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
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In this problem, we are tasked with finding the **upper bound** of a given `target` element in a **sorted array**.

- **Upper Bound** of a number in an array is defined as the **smallest index** where the **element is greater than** the target.
- If **no such element exists**, we return the **length** of the array.

---

## Problem Description

You are given:

- A sorted array `arr[]`.
- A number `target`.

You need to find the **smallest index** where `arr[index] > target`.  
If no such element exists, return `arr.size()`.

---

### Examples

#### Example 1

**Input**:  
`arr[] = [2, 3, 7, 10, 11, 11, 25]`  
`target = 9`

**Output**:  
`3`

**Explanation**:  
At index `3`, `arr[3] = 10`, which is the first number greater than `9`.

---

#### Example 2

**Input**:  
`arr[] = [2, 3, 7, 10, 11, 11, 25]`  
`target = 11`

**Output**:  
`6`

**Explanation**:  
At index `6`, `arr[6] = 25`, which is the first number greater than `11`.

---

#### Example 3

**Input**:  
`arr[] = [2, 3, 7, 10, 11, 11, 25]`  
`target = 100`

**Output**:  
`7`

**Explanation**:  
No element is greater than `100`, so we return the size of the array, which is `7`.

---

### Constraints

- \( 1 \leq arr.size() \leq 10^6 \)
- \( 1 \leq arr[i] \leq 10^6 \)
- \( 1 \leq target \leq 10^6 \)

---

## Approach

We use a **binary search** approach because the array is already sorted:

1. Initialize `low = 0` and `high = n-1`, where `n` is the size of the array.
2. Maintain an `ans` variable initialized with `n`.
3. In each iteration:
   - Calculate `mid = low + (high - low) / 2`.
   - If `arr[mid] > target`, it could be a potential answer, so update `ans = mid` and move `high = mid - 1`.
   - Else, move `low = mid + 1`.
4. When the loop finishes, `ans` will contain the index of the upper bound.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
// User function Template for C++

class Solution {
public:
    int upperBound(vector<int>& arr, int target) {
        int n = arr.size();    // Size of the array
        int low = 0, high = n - 1;
        int ans = n;           // Default to n if no element > target

        while (low <= high) {
            int mid = low + (high - low) / 2; // Prevents overflow

            if (arr[mid] > target) {
                ans = mid;       // Potential answer found
                high = mid - 1;  // Search in the left half
            } else {
                low = mid + 1;   // Search in the right half
            }
        }

        return ans; // Return the final answer
    }
};
```

---

## Complexity Analysis

|       Type       |            Complexity            |
| :--------------: | :------------------------------: |
| Time Complexity  | \( O(\log n) \) — Binary Search  |
| Space Complexity | \( O(1) \) — No extra space used |

---

## How to Run the Code

### For C++

1. **Environment**:

   - Install a C++ compiler (e.g., GCC).
   - Use an IDE like Code::Blocks, VS Code, or an online IDE like LeetCode, GeeksforGeeks IDE.

2. **Steps**:

   - Save the file as `UpperBound.cpp`.
   - Compile:

     ```bash
     g++ UpperBound.cpp -o UpperBound
     ```

   - Run:

     ```bash
     ./UpperBound
     ```

3. **Input Format**:
   - Create a `vector<int>` with the sorted array elements.
   - Pass the array and target number to the `upperBound` function.

---
