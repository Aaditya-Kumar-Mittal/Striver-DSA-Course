# Set Matrix Zeroes

## Table of Contents

- [Set Matrix Zeroes](#set-matrix-zeroes)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Optimal Implementation (Constant Space)](#c-optimal-implementation-constant-space)
    - [C++ Simple Approach Using O(M+N) Space](#c-simple-approach-using-omn-space)
    - [C++ Brute Force Approach with Marking](#c-brute-force-approach-with-marking)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The task is to modify a given matrix such that if any element is `0`, its entire row and column are set to `0`. The catch is to do this **in place**, minimizing space usage.

## Problem Description

Given an `m x n` integer matrix `matrix`, set the entire row and column to `0` if any element is `0`. Do this in-place.

### Examples

**Example 1:**

```plaintext
Input:  matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:**

```plaintext
Input:  matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

### Constraints

- `1 <= m, n <= 200`
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

## Approach

We discuss three approaches:

1. **Optimal Approach (O(1) space):** Use the first row and column as markers.
2. **Better Approach (O(M+N) space):** Use separate row and column arrays to mark zeros.
3. **Brute Force (With Marker Value):** Use a placeholder (e.g. -1) to mark and change later.

## Detailed Explanation of Code

### C++ Optimal Implementation (Constant Space)

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int columnStart = 1;
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Use first row and col as markers
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(matrix[row][col] == 0) {
                    matrix[row][0] = 0;
                    if(col != 0) matrix[0][col] = 0;
                    else columnStart = 0;
                }
            }
        }

        // Step 2: Use markers to set inner matrix to 0
        for(int row = 1; row < n; row++) {
            for(int col = 1; col < m; col++) {
                if(matrix[row][0] == 0 || matrix[0][col] == 0)
                    matrix[row][col] = 0;
            }
        }

        // Step 3: Handle first row
        if(matrix[0][0] == 0) {
            for(int col = 0; col < m; col++) matrix[0][col] = 0;
        }

        // Step 4: Handle first column
        if(columnStart == 0) {
            for(int row = 0; row < n; row++) matrix[row][0] = 0;
        }
    }
};
```

### C++ Simple Approach Using O(M+N) Space

```cpp
void setMatrixOnes(vector<vector<int>> &MAT, int n, int m) {
    int rows[n] = {0}, cols[m] = {0};

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m; j++) {
            if(MAT[i][j] == 1) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < m; j++) {
            if(rows[i] || cols[j]) MAT[i][j] = 1;
        }
    }
}
```

### C++ Brute Force Approach with Marking

```cpp
void markRow(vector<vector<int>> &arr, int i, int m) {
    for (int j = 0; j < m; j++) {
        if (arr[i][j] != 0) arr[i][j] = -1;
    }
}

void markColumn(vector<vector<int>> &arr, int j, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i][j] != 0) arr[i][j] = -1;
    }
}

void SetMatrixZeros(vector<vector<int>> &arr, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, i, m);
                markColumn(arr, j, n);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) arr[i][j] = 0;
        }
    }
}
```

## Complexity Analysis

| Approach | Time Complexity | Space Complexity                    |
| -------- | --------------- | ----------------------------------- |
| Optimal  | O(m \* n)       | O(1)                                |
| Better   | O(m \* n)       | O(m + n)                            |
| Brute    | O(m \* n)       | O(1), but modifies data temporarily |

## How to Run the Code

### For C++

1. Save the code in a file `main.cpp`.
2. Compile with: `g++ -std=c++17 main.cpp -o program`
3. Run using: `./program`

Make sure to include `#include <vector>` and `#include <iostream>` as needed for testing.
