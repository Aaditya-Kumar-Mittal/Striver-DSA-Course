# 733. Flood Fill

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [733. Flood Fill](#733-flood-fill)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
    - [Python Implementation](#python-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
    - [For Python](#for-python)
  - [Other Solutions](#other-solutions)
    - [C++ Solution - 1](#c-solution---1)

---

## Introduction

Flood Fill is a common algorithm used in image processing. Given a starting pixel, the algorithm changes the color of all connected pixels with the same initial color to a new color. This is similar to the "paint bucket" tool in graphics editors.

---

## Problem Description

### Task

Perform a flood fill operation starting from pixel \( (sr, sc) \) in a given \( m \times n \) grid (image). Update all adjacent pixels (connected vertically or horizontally) with the same initial color as the starting pixel to the new color.

### Examples

#### Example 1

**Input:**  
`image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2`  
**Output:**  
`[[2,2,2],[2,2,0],[2,0,1]]`

**Explanation:**  
Starting from \( (1,1) \), change the connected pixels of the same color (blue region) to \( 2 \).

#### Example 2

**Input:**  
`image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0`  
**Output:**  
`[[0,0,0],[0,0,0]]`

**Explanation:**  
The starting pixel is already the same as the target color. No changes are made.

---

## Constraints

- \( 1 \leq m, n \leq 50 \)
- \( 0 \leq image[i][j], color < 2^{16} \)
- \( 0 \leq sr < m \)
- \( 0 \leq sc < n \)

---

## Approach

### Steps

1. **Base Case**: If the starting pixel already has the target color, return the image as is.
2. **Depth-First Search (DFS)**:
   - Mark the starting pixel with the new color.
   - Recursively apply the same operation to all adjacent pixels (up, down, left, right) that share the initial color.
3. **Boundary Check**: Ensure that adjacent pixels are within bounds and have not been updated already.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
using namespace std;

class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& image, 
             vector<vector<int>>& imageAns, int newColor, int initialColor, 
             int n, int m, int delRow[], int delCol[]) {
        // Update the color of the current pixel
        imageAns[row][col] = newColor;

        // Explore all 4 possible directions
        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            // Check boundary conditions and if the neighbor needs to be updated
            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                image[nRow][nCol] == initialColor &&
                imageAns[nRow][nCol] != newColor) {
                dfs(nRow, nCol, image, imageAns, newColor, initialColor, n, m, delRow, delCol);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        // If the initial color is the same as the new color, no operation is needed
        if (initialColor == color) return image;

        vector<vector<int>> imageAns = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int n = image.size();
        int m = image[0].size();

        dfs(sr, sc, image, imageAns, color, initialColor, n, m, delRow, delCol);

        return imageAns;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int row, int col, int[][] image, int[][] imageAns, int newColor, int initialColor, int n, int m, int[] delRow, int[] delCol) {
        imageAns[row][col] = newColor;

        for (int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < m &&
                image[nRow][nCol] == initialColor && imageAns[nRow][nCol] != newColor) {
                dfs(nRow, nCol, image, imageAns, newColor, initialColor, n, m, delRow, delCol);
            }
        }
    }

    public int[][] floodFill(int[][] image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        if (initialColor == color) return image;

        int[][] imageAns = new int[image.length][image[0].length];
        for (int i = 0; i < image.length; i++) {
            imageAns[i] = Arrays.copyOf(image[i], image[i].length);
        }

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};
        dfs(sr, sc, image, imageAns, color, initialColor, image.length, image[0].length, delRow, delCol);

        return imageAns;
    }
}
```

---

### Python Implementation

```python
class Solution:
    def floodFill(self, image, sr, sc, color):
        def dfs(row, col):
            image[row][col] = color
            for dr, dc in directions:
                nRow, nCol = row + dr, col + dc
                if 0 <= nRow < n and 0 <= nCol < m and image[nRow][nCol] == initialColor:
                    dfs(nRow, nCol)

        initialColor = image[sr][sc]
        if initialColor == color:
            return image

        n, m = len(image), len(image[0])
        directions = [(-1, 0), (0, 1), (1, 0), (0, -1)]
        dfs(sr, sc)
        return image
```

---

## Complexity Analysis

- **Time Complexity**: \( O(n \times m) \)  
  Every pixel is visited once.
- **Space Complexity**:  
  - \( O(n \times m) \) for the recursion stack in DFS (in the worst case when the entire grid is connected).
  - Additional storage for the output array in Java and C++ implementations.

---

## How to Run the Code

### For C++

1. Save the code to `flood_fill.cpp`.
2. Compile with `g++ flood_fill.cpp -o flood_fill`.
3. Run with `./flood_fill`.

### For Java

1. Save the code to `Solution.java`.
2. Compile with `javac Solution.java`.
3. Run with `java Solution`.

### For Python

1. Save the code to `flood_fill.py`.
2. Run with `python flood_fill.py`.

## Other Solutions

### C++ Solution - 1

```cpp
class Solution {
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        if (color != newColor) {
            dfs(image, sr, sc, color, newColor);
        }
        return image;
    }
    public void dfs(int[][] image, int r, int c, int color, int newColor) {
        if (image[r][c] == color) {
            image[r][c] = newColor;
            if (r >= 1) {
                dfs(image, r - 1, c, color, newColor);
            }
            if (c >= 1) {
                dfs(image, r, c - 1, color, newColor);
            }
            if (r + 1 < image.length) {
                dfs(image, r + 1, c, color, newColor);
            }
            if (c + 1 < image[0].length) {
                dfs(image, r, c + 1, color, newColor);
            }
        }
    }
}
```
