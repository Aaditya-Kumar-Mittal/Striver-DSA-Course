# Maximal Rectangle

## Table of Contents

- [Maximal Rectangle](#maximal-rectangle)
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

## Introduction

The **Maximal Rectangle** problem requires finding the largest rectangular area containing only `1's` in a given `rows x cols` binary matrix.

## Problem Description

Given a binary matrix filled with `0's` and `1's`, return the area of the largest rectangle containing only `1's`.

### Examples

#### Example 1

**Input:**

```cpp
matrix = [["1","0","1","0","0"],
          ["1","0","1","1","1"],
          ["1","1","1","1","1"],
          ["1","0","0","1","0"]]
```

**Output:** `6`

#### Example 2

**Input:**

```cpp
matrix = [["0"]]
```

**Output:** `0`

#### Example 3

**Input:**

```cpp
matrix = [["1"]]
```

**Output:** `1`

### Constraints

- `rows == matrix.length`
- `cols == matrix[i].length`
- `1 <= row, cols <= 200`
- `matrix[i][j]` is `'0'` or `'1'`

## Approach

The problem is solved using the **Largest Rectangle in Histogram** concept. We:

1. Convert each row of the matrix into a histogram of heights.
2. Use the **Largest Rectangle Area** function to compute the maximal rectangle in each row.
3. Keep track of the maximum rectangle area encountered so far.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& histo) {
        stack<int> st;
        int maxA = 0;
        int n = histo.size();

        for (int i = 0; i <= n; i++) {
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()];
                st.pop();
                int width;
                if (st.empty())
                    width = i;
                else
                    width = i - st.top() - 1;
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0;
            }
            int area = largestRectangleArea(heights);
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};
```

## Complexity Analysis

- **Building the height array:** `O(rows * cols)`
- **Computing the largest rectangle in histogram:** `O(cols)` for each row
- **Overall Complexity:** `O(rows * cols)`

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `maximal_rectangle.cpp`.
2. Compile the code using `g++`:

   ```sh
   g++ maximal_rectangle.cpp -o maximal_rectangle
   ```

3. Run the executable:

   ```sh
   ./maximal_rectangle
   ```
