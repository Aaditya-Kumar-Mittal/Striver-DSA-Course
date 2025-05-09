# Implement Lower Bound

## Table of Contents

- [Implement Lower Bound](#implement-lower-bound)
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
    - [Key Insights](#key-insights)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

The **lower bound** of a target in a sorted array is the **smallest index** where the element at that index is **greater than or equal to** the target.

If all elements are smaller than the target, the lower bound is defined as the **length of the array**.

This is a classic **binary search** variant problem, widely used in competitive programming and technical interviews.

---

## Problem Description

- You are given a sorted array `arr[]` and an integer `target`.
- You need to find the **smallest index** where `arr[index] ≥ target`.
- If such an index doesn't exist (i.e., all elements are smaller), return `arr.length`.

---

### Examples

#### Example 1

```plaintext
Input:
arr[] = [2, 3, 7, 10, 11, 11, 25]
target = 9

Output:
3

Explanation:
- Element at index 3 is 10, which is the smallest number ≥ 9.
- So, the lower bound index is 3.
```

---

#### Example 2

```plaintext
Input:
arr[] = [2, 3, 7, 10, 11, 11, 25]
target = 11

Output:
4

Explanation:
- The element 11 occurs at indices 4 and 5.
- The first occurrence is at index 4.
- Thus, lower bound is 4.
```

---

#### Example 3

```plaintext
Input:
arr[] = [2, 3, 7, 10, 11, 11, 25]
target = 100

Output:
7

Explanation:
- All elements are smaller than 100.
- Hence, lower bound is the size of the array, i.e., 7.
```

---

### Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `1 ≤ target ≤ 10^6`

---

## Approach

We use a **modified Binary Search** to find the lower bound efficiently.

### Steps

1. Initialize:

   - `low = 0`
   - `high = n-1`
   - `ans = n` (default: array size if no element found)

2. While `low <= high`:

   - Find `mid = low + (high - low)/2`
   - If `arr[mid] >= target`, update `ans = mid` and move **left** (to find a smaller index).
   - Otherwise, move **right** to look for larger values.

3. Return `ans`.

This ensures you find the **first position** where the condition holds.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
// User function Template for C++
class Solution {
public:
    int lowerBound(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        int ans = n; // Default: If no element >= target found, return size

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] >= target) {
                ans = mid; // Possible answer found
                high = mid - 1; // Search on the left side for a smaller index
            } else {
                low = mid + 1; // Move right as arr[mid] < target
            }
        }

        return ans;
    }
};
```

### Key Insights

- **When `arr[mid] >= target`:**  
  Mid might be our answer, but let's see if we can find an even smaller index.
- **When `arr[mid] < target`:**  
  This mid cannot be our answer, so discard left part and move to right half.

---

## Complexity Analysis

| Complexity                  | Time       | Space  |
| --------------------------- | ---------- | ------ |
| **Best/Average/Worst Case** | `O(log N)` | `O(1)` |

- **Time Complexity:**

  - We halve the search space in every iteration ⇒ `O(log N)`.

- **Space Complexity:**
  - Only a few variables are used ⇒ `O(1)`.

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

**Note:**

- This problem is a fundamental building block for more advanced topics like "binary search on answer," "lower bound/upper bound in STL," etc.
- Mastering this improves your problem-solving skills dramatically for interview rounds!

---
