# Find a Peak Element II

## Table of Contents

- [Find a Peak Element II](#find-a-peak-element-ii)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)

---

## Introduction

The problem involves finding a **peak element** in a 2D grid. A peak is defined as an element that is strictly greater than its adjacent elements in the top, bottom, left, and right directions. The matrix is surrounded by `-1` values virtually, and no two adjacent elements in the matrix are equal.

This problem is a classic application of **Binary Search** in a 2D matrix to achieve better than brute-force time complexity.

---

## Problem Description

You're given an `m x n` matrix `mat` where no two adjacent cells are equal. Your goal is to return the indices `[i, j]` of **any** peak element in the matrix.

### Examples

**Example 1:**

```plaintext
Input: mat = \[\[1,4],
\[3,2]]
Output: \[0,1]
Explanation: 4 is a peak (greater than 1, -1, -1, and 2). 3 is also a peak, so \[1,0] is also valid.
```

**Example 2:**

```plaintext
Input: mat = \[\[10,20,15],
\[21,30,14],
\[7,16,32]]
Output: \[1,1]
Explanation: 30 is a peak. 32 is also a valid peak. Any of these indices is acceptable.
```

### Constraints

- `m == mat.length`
- `n == mat[i].length`
- `1 <= m, n <= 500`
- `1 <= mat[i][j] <= 10⁵`
- No two adjacent cells are equal.

---

## Approach

We can achieve **O(m log n)** or **O(n log m)** complexity using **Binary Search** on either rows or columns. This solution uses Binary Search on columns:

1. Perform binary search on the columns.
2. For a mid-column, find the maximum element in that column.
3. Compare it with its immediate neighbors (left and right).
4. Based on the comparison, move the search space to the side with a larger neighbor.
5. If the mid-column maximum is greater than both neighbors, it is a peak.

This greedy approach works due to the strictly increasing or decreasing nature of neighboring values ensured by the problem constraints.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Helper function to find the index of the maximum element in a column
    int maxIndexForRow(vector<vector<int>>& mat, int rows, int cols, int colIndex) {
        int maxElement = -1, index = -1;
        for (int row = 0; row < rows; row++) {
            if (mat[row][colIndex] > maxElement) {
                maxElement = mat[row][colIndex];
                index = row;
            }
        }
        return index;
    }

    // Main function to find a peak element
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        if (rows == 1 && cols == 1)
            return {0, 0};

        int low = 0, high = cols - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int rowIndex = maxIndexForRow(mat, rows, cols, mid);
            int leftElement = mid - 1 >= 0 ? mat[rowIndex][mid - 1] : -1;
            int rightElement = mid + 1 < cols ? mat[rowIndex][mid + 1] : -1;

            if (mat[rowIndex][mid] > leftElement && mat[rowIndex][mid] > rightElement)
                return {rowIndex, mid};
            else if (mat[rowIndex][mid] < leftElement)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return {-1, -1};  // Should never reach here due to constraints
    }
};
```

---

## Complexity Analysis

| Metric               | Value                                                                                |
| -------------------- | ------------------------------------------------------------------------------------ |
| **Time Complexity**  | O(m \* log n) — Binary search on columns, and linear scan on rows to find column max |
| **Space Complexity** | O(1) — No extra space used                                                           |

---

## How to Run the Code

### For C++

1. **Setup**: Use any modern C++ compiler (GCC, Clang, MSVC).
2. **Command**:

   ```sh
   g++ solution.cpp -o peak_finder
   ./peak_finder
   ```

3. **Input/Output**: Create a driver `main()` function to read input matrix and call `findPeakGrid()` method.

```cpp
int main() {
    Solution sol;
    vector<vector<int>> mat = {{10, 20, 15}, {21, 30, 14}, {7, 16, 32}};
    vector<int> result = sol.findPeakGrid(mat);
    cout << "Peak found at: [" << result[0] << ", " << result[1] << "]" << endl;
    return 0;
}
```

---

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int startCol = 0, endCol = mat[0].size()-1;

        while(startCol <= endCol){
            int maxRow = 0, midCol = startCol + (endCol-startCol)/2;

            for(int row=0; row<mat.size(); row++){
                maxRow = mat[row][midCol] >= mat[maxRow][midCol]? row : maxRow;
            }

            bool leftIsBig    =   midCol-1 >= startCol  &&  mat[maxRow][midCol-1] > mat[maxRow][midCol];
            bool rightIsBig   =   midCol+1 <= endCol    &&  mat[maxRow][midCol+1] > mat[maxRow][midCol];

            if(!leftIsBig && !rightIsBig)          // we have found the peak element
                return vector<int>{ maxRow, midCol};

            else if(rightIsBig) // if rightIsBig, then there is an element in 'right' that is bigger than all the elements in the 'midCol',
                startCol = midCol+1;    //so 'midCol' cannot have a 'peakPlane'

            else // leftIsBig
                endCol = midCol-1;
        }
        return vector<int>{-1,-1};
    }
};
```

```java
class Solution {
    public int[] findPeakGrid(int[][] mat) {
        int startCol = 0, endCol = mat[0].length-1;

        while(startCol <= endCol){
            int maxRow = 0, midCol = startCol + (endCol-startCol)/2;

            for(int row=0; row<mat.length; row++){
                 maxRow = mat[row][midCol] >= mat[maxRow][midCol]? row : maxRow;
            }

            boolean leftIsBig    =   midCol-1 >= startCol  &&  mat[maxRow][midCol-1] > mat[maxRow][midCol];
            boolean rightIsBig   =   midCol+1 <= endCol    &&  mat[maxRow][midCol+1] > mat[maxRow][midCol];

            if(!leftIsBig && !rightIsBig)   // we have found the peak element
                return new int[]{maxRow, midCol};

            else if(rightIsBig)  // if rightIsBig, then there is an element in 'right' that is bigger than all the elements in the 'midCol',
                startCol = midCol+1; //so 'midCol' cannot have a 'peakPlane'

            else // leftIsBig
                endCol = midCol-1;
        }
        return null;
    }
}
```
