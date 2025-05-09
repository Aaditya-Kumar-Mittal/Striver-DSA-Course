# Search a 2D Matrix II

## Table of Contents

- [Search a 2D Matrix II](#search-a-2d-matrix-ii)
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

Searching in a 2D matrix can be inefficient if treated as an unstructured grid. But given constraints — **rows and columns both sorted** — open up an opportunity to **optimize the search** using a clever traversal strategy, avoiding a brute-force approach.

---

## Problem Description

You are given an `m x n` matrix of integers and an integer `target`. The matrix has the following properties:

1. Each row is sorted in **ascending order** from **left to right**.
2. Each column is sorted in **ascending order** from **top to bottom**.

You must determine whether the target exists in the matrix.

### Examples

#### Example 1

![enter image description here](https://assets.leetcode.com/uploads/2020/11/24/searchgrid2.jpg)

```text
Input:
matrix = [
  [ 1,  4,  7, 11, 15],
  [ 2,  5,  8, 12, 19],
  [ 3,  6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
target = 5

Output: true
```

#### Example 2

![enter image description here](https://assets.leetcode.com/uploads/2020/11/24/searchgrid.jpg)

```text
Input:
matrix = [
  [ 1,  4,  7, 11, 15],
  [ 2,  5,  8, 12, 19],
  [ 3,  6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
target = 20

Output: false
```

---

### Constraints

- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 300`
- `-10^9 <= matrix[i][j] <= 10^9`
- Each row is sorted in ascending order.
- Each column is sorted in ascending order.
- `-10^9 <= target <= 10^9`

---

## Approach

### Key Insight

Start from the **top-right corner** of the matrix:

- If the current element equals the target → return `true`.
- If the current element is **greater** than the target → move **left**.
- If the current element is **less** than the target → move **down**.

This strategy works because:

- Moving left brings smaller values.
- Moving down brings larger values.

By eliminating one row or one column at each step, we get a very efficient traversal.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();           // Total rows
        int cols = matrix[0].size();        // Total columns

        int row = 0;                        // Start from top-right
        int col = cols - 1;

        // Traverse until we go out of bounds
        while (row < rows && col >= 0) {
            if (matrix[row][col] == target) {
                return true;
            } else if (matrix[row][col] < target) {
                row++;  // Move down to a larger value
            } else {
                col--;  // Move left to a smaller value
            }
        }

        return false;  // Target not found
    }
};
```

---

## Complexity Analysis

- **Time Complexity:** `O(m + n)`
  At each step, we eliminate a row or column — total steps = `rows + columns`.

- **Space Complexity:** `O(1)`
  No additional memory is used apart from a few variables.

---

## How to Run the Code

### For C++

1. Save the above code in a file, e.g., `search_matrix.cpp`.
2. Add a `main()` function to call `searchMatrix()` with your test input.
3. Compile the code:

   ```bash
   g++ -std=c++17 search_matrix.cpp -o search
   ```

4. Run the executable:

   ```bash
   ./search
   ```

---
