# Row With Maximum Ones

## Table of Contents

- [Row With Maximum Ones](#row-with-maximum-ones)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [1. Brute Force Count](#1-brute-force-count)
    - [2. Binary Search Optimization](#2-binary-search-optimization)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Brute Force Version (`rowAndMaximumOnes`)](#brute-force-version-rowandmaximumones)
    - [Optimized Version (`rowAndMaximumOnesSorted`)](#optimized-version-rowandmaximumonessorted)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Submissions](#my-submissions)

---

## Introduction

This problem asks us to find the **row with the maximum number of ones** in a binary matrix. If multiple rows contain the same maximum number of ones, we are to return the **row with the smallest index**.

---

## Problem Description

You are given an `m x n` binary matrix `mat`, where:

- Each element is either `0` or `1`.

You need to **identify the row** with the **highest count of ones**. In case of a tie, **the smallest index row** should be returned.

Return a vector/array of two integers:

- The **index of the row**, and
- The **number of ones** in that row.

---

### Examples

#### Example 1

```text
Input:  mat = [[0,1],[1,0]]
Output: [0,1]
Explanation: Both rows have 1 one, so the row with smaller index (0) is returned.
```

#### Example 2

```text
Input:  mat = [[0,0,0],[0,1,1]]
Output: [1,2]
Explanation: The second row (index 1) has 2 ones.
```

#### Example 3

```text
Input:  mat = [[0,0],[1,1],[0,0]]
Output: [1,2]
Explanation: Only the second row has 2 ones.
```

---

### Constraints

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 100`
- `mat[i][j]` is either `0` or `1`

---

## Approach

We provide **two approaches**:

### 1. Brute Force Count

- Iterate through every row.
- Count the number of ones manually.
- Track the row with the maximum number of ones.

### 2. Binary Search Optimization

- If rows are **sorted**, we can use `lower_bound` to find the **first 1** in each row.
- Number of ones = `total_columns - index_of_first_1`.

This optimized version improves the time complexity to `O(m * log n)`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Binary Search for the first occurrence of 1 in a sorted row
    int lowerBound(vector<int>& row, int m, int x) {
        int low = 0;
        int high = m - 1;
        int ans = m; // Default if 1 not found

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    // Optimized version for sorted rows
    vector<int> rowAndMaximumOnesSorted(vector<vector<int>>& mat) {
        int count_max = 0;
        int index = -1;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            int count_ones = cols - lowerBound(mat[i], cols, 1);
            if (count_ones > count_max) {
                count_max = count_ones;
                index = i;
            }
        }

        return {index, count_max};
    }

    // Brute-force version for unsorted rows
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count_max = 0;
        int index = -1;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            int count_ones = 0;

            for (int val : mat[i]) {
                if (val == 1)
                    count_ones++;
            }

            if (count_ones > count_max) {
                count_max = count_ones;
                index = i;
            }
        }

        // Handle case where no ones exist
        if (index == -1)
            return {0, 0};
        return {index, count_max};
    }
};
```

---

## Complexity Analysis

### Brute Force Version (`rowAndMaximumOnes`)

- **Time Complexity:** `O(m * n)`
  Iterates over all `m` rows and `n` columns.
- **Space Complexity:** `O(1)`
  Only uses constant space.

### Optimized Version (`rowAndMaximumOnesSorted`)

- **Time Complexity:** `O(m * log n)`
  Uses binary search on each row.
- **Space Complexity:** `O(1)`
  No extra space used.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `row_with_max_ones.cpp`.
2. Add a `main()` function with input and function calls.
3. Compile the code:

   ```bash
   g++ -std=c++17 row_with_max_ones.cpp -o max_ones
   ```

4. Run the output:

   ```bash
   ./max_ones
   ```

---

## Other Solutions

### My Submissions

```cpp
class Solution {
public:
    int lowerBound(vector<int>& row, int m, int x) {
        int low = 0;
        int high = m - 1;
        int ans = m; // Default to m if x not found

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnesSorted(vector<vector<int>>& mat) {
        int count_max = 0;
        int index = -1;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            int count_ones = cols - lowerBound(mat[i], cols, 1);
            if (count_ones > count_max) {
                count_max = count_ones;
                index = i;
            }
        }

        return {index, count_max};
    }

    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int count_max = 0;
        int index = -1;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {

            int count_ones = 0;

            for (int val : mat[i]) {
                if (val == 1)
                    count_ones++;
            }

            if (count_ones > count_max) {
                count_max = count_ones;
                index = i;
            }
        }

        if (index == -1)
            return {0, 0};
        return {index, count_max};
    }
};
```

```cpp

// User function template for C++
class Solution {
  public:

    int lowerBound(vector<int>& row, int m, int x) {
        int low = 0;
        int high = m - 1;
        int ans = m; // Default to m if x not found

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (row[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    vector<int> rowAndMaximumOnesSorted(vector<vector<int>>& mat) {
        int count_max = 0;
        int index = -1;
        int rows = mat.size();
        int cols = mat[0].size();

        for (int i = 0; i < rows; i++) {
            int count_ones = cols - lowerBound(mat[i], cols, 1);
            if (count_ones > count_max) {
                count_max = count_ones;
                index = i;
            }
        }

        return {index, count_max};
    }


    int rowWithMax1s(vector<vector<int>> &arr) {
        return rowAndMaximumOnesSorted(arr)[0];
    }
};
```
