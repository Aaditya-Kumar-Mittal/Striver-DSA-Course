# Median in a Row-wise Sorted Matrix

## Table of Contents

- [Median in a Row-wise Sorted Matrix](#median-in-a-row-wise-sorted-matrix)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Sample Input 1](#sample-input-1)
      - [Sample Output 1](#sample-output-1)
      - [Sample Input 2](#sample-input-2)
      - [Sample Output 2](#sample-output-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

Finding the **median** of a row-wise sorted matrix can be challenging due to its 2D nature and the need to avoid flattening and sorting the entire matrix for efficiency. This problem specifically requires an optimized approach with logarithmic complexity in terms of the number range.

---

## Problem Description

You are given an `m x n` matrix named `mat` where each row is sorted in non-decreasing order. Your task is to find the **median of the matrix**.

> **Note:** Both `m` and `n` are always odd, so there will be a single median.

### Examples

#### Sample Input 1

```text
m = 5, n = 5
mat = [
  [ 1, 5, 7, 9, 11 ],
  [ 2, 3, 4, 8, 9 ],
  [ 4, 11, 14, 19, 20 ],
  [ 6, 10, 22, 99, 100 ],
  [ 7, 15, 17, 24, 28 ]
]
```

#### Sample Output 1

```bash
10
```

#### Sample Input 2

```text
m = 3, n = 5
mat = [
  [ 1, 2, 3, 4, 5 ],
  [ 8, 9, 11, 12, 13 ],
  [ 21, 23, 25, 27, 29 ]
]
```

#### Sample Output 2

```bash
11
```

---

### Constraints

- 1 ≤ m < 100
- 1 ≤ n < 100
- 1 ≤ mat\[i]\[j] ≤ 10⁹
- Time Limit: 1 sec
- Both `m` and `n` are odd.

---

## Approach

We need to avoid sorting all elements. Instead, we use a **binary search on the value range**:

1. Find the minimum and maximum element in the matrix (`low`, `high`).
2. Binary search the value range to find the smallest number `x` such that **more than half the elements are less than or equal to `x`**.
3. For each guessed `mid`, use `upper_bound` to count elements `<= mid` in each row (efficient due to sorting).
4. When the count of such elements exceeds half the total elements, adjust `high`; otherwise, adjust `low`.
5. The final value of `low` will be the median.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
/*
        Time Complexity: O((m * n) * log(m * n))
        Space complexity: O(m * n)

        Where 'm' denotes the number of rows and 'n' denotes the number of columns of the matrix.

*/

int median(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> spreadMatrix;

    // Transfer the elements
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            spreadMatrix.push_back(matrix[i][j]);
        }
    }

    // Sort to find the median
    sort(spreadMatrix.begin(), spreadMatrix.end());

    // Return the middle element
    return spreadMatrix[m * n / 2];
}
```

```cpp
/*
        Time Complexity: O(32 * m * log(n))
        Space complexity: O(1)

        Where 'm' denotes the number of rows and 'n' denotes the number of columns of the matrix.

*/

int median(vector<vector<int>> &matrix, int m, int n)
{
    int maximum = INT_MIN;
    int minimum = INT_MAX;

    // To find the minimum and maximum in the matrix
    for (int i = 0; i < m; i++)
    {
        if (matrix[i][0] < minimum)
        {
            minimum = matrix[i][0];
        }
        if (matrix[i][n - 1] > maximum)
        {
            maximum = matrix[i][n - 1];
        }
    }

    // Count for the number to be the median
    int checkCount = (m * n + 1) / 2;

    // Binary search for the median
    while (minimum < maximum)
    {
        int mid = minimum + (maximum - minimum) / 2;
        int count = 0;
        int find = 0;

        for (int i = 0; i < m; ++i)
        {

            // Binary search for finding the count in each row
            find = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();

            // Increment count
            count = count + find;
        }

        if (count < checkCount)
        {
            minimum = mid + 1;
        }
        else
        {
            maximum = mid;
        }
    }

    // Finally return the answer
    return minimum;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

// Helper function to count number of elements <= x in the matrix
int helper(vector<vector<int>> &matrix, int m, int n, int x) {
    int count = 0;
    for(int i = 0; i < m; i++) {
        count += (upper_bound(matrix[i].begin(), matrix[i].end(), x) - matrix[i].begin());
    }
    return count;
}

// Main function to find the median
int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    // Find minimum and maximum element in matrix
    for(int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n-1]);
    }

    int required = (m * n) / 2;

    // Binary search on value range
    while(low <= high) {
        int mid = (low + high) >> 1;
        int smallerEquals = helper(matrix, m, n, mid);

        if(smallerEquals <= required) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}
```

---

## Complexity Analysis

- **Time Complexity:** `O(32 * m * log(n))`

  - `32` comes from the max number of bits needed to represent values up to 10⁹ (binary search on value range).
  - `log(n)` per `upper_bound` call, and `m` rows are traversed.

- **Space Complexity:** `O(1)`

  - No extra space used apart from a few variables.

---

## How to Run the Code

### For C++

1. **Save the code** in a file named `median_matrix.cpp`.
2. **Compile** the code using:

   ```bash
   g++ -std=c++17 median_matrix.cpp -o median
   ```

3. **Run** the compiled file:

   ```bash
   ./median
   ```

You can modify the `main()` function to input your own matrix and print the result.

---
