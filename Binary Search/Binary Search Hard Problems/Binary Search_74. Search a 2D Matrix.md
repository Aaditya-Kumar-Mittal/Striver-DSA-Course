# Search a 2D Matrix

## Table of Contents

- [Search a 2D Matrix](#search-a-2d-matrix)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Insight](#key-insight)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

This problem gives us a matrix where each row is **individually sorted**, and **each row's first element is greater than the previous row’s last element**. These properties allow us to **flatten** the 2D matrix into a 1D array for efficient binary search in `O(log(m * n))` time complexity.

---

## Problem Description

You are given an `m x n` integer matrix `matrix` with the following properties:

1. Each row is sorted in **non-decreasing order**.
2. The **first element** of each row is **greater than the last element** of the previous row.

Given an integer `target`, return `true` if `target` is in the matrix, otherwise return `false`.

### Examples

#### Example 1

![enter image description here](https://assets.leetcode.com/uploads/2020/10/05/mat.jpg)

```text
Input:
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 3

Output: true
```

#### Example 2

![enter image description here](https://assets.leetcode.com/uploads/2020/10/05/mat2.jpg)

```text
Input:
matrix = [
  [1, 3, 5, 7],
  [10, 11, 16, 20],
  [23, 30, 34, 60]
]
target = 13

Output: false
```

---

### Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

---

## Approach

### Key Insight

The matrix can be viewed as a **flattened sorted 1D array** due to the ordering constraints. This allows us to perform **binary search** directly on the entire matrix:

- Treat the 2D matrix as a 1D array of size `m * n`.
- Calculate row and column from the 1D index using:

  - `row = index / n`
  - `col = index % n`

Perform regular binary search using this mapping.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();         // Number of rows
        int m = matrix[0].size();      // Number of columns

        int low = 0;
        int high = (n * m) - 1;        // Last index in the flattened matrix

        while (low <= high) {
            int mid = (low + high) >> 1;  // Binary search midpoint
            int row = mid / m;           // Get actual row index
            int col = mid % m;           // Get actual column index

            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;  // Target not found
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(log(m * n))`
  Binary search on `m * n` elements (flattened view of matrix).

- **Space Complexity:** `O(1)`
  No extra space is used apart from a few variables.

---

## How to Run the Code

### For C++

1. Save the code into a file named `search_2d_matrix.cpp`.
2. Add a `main()` function to invoke `searchMatrix()` with sample inputs.
3. Compile the code:

   ```bash
   g++ -std=c++17 search_2d_matrix.cpp -o search
   ```

4. Run the executable:

   ```bash
   ./search
   ```

---
