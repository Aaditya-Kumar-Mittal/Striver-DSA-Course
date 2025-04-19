# Pascal's Triangle

## Table of Contents

- [Pascal's Triangle](#pascals-triangle)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Explanation](#explanation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Other Solutions](#other-solutions)
    - [Solution - 1 Using Recursion](#solution---1-using-recursion)
    - [Method 2: Using Combinatorial Formula](#method-2-using-combinatorial-formula)
    - [Method 3: Using Dynamic Programming with 1D Array](#method-3-using-dynamic-programming-with-1d-array)
    - [Solution - 4](#solution---4)

---

## Introduction

Pascal's Triangle is a triangular array of numbers where each number is the sum of the two numbers directly above it. It is widely used in combinatorics and probability, and each row represents the binomial coefficients of \((a + b)^n\).

---

## Problem Description

Given an integer `numRows`, return the first `numRows` of Pascal's Triangle.

Each row is constructed based on the values from the previous row. The first and last elements of each row are always `1`, and all other elements are the sum of the two elements above it from the previous row.

### Examples

#### Example 1

```plaintext
Input: numRows = 5
Output: [[1],
         [1,1],
         [1,2,1],
         [1,3,3,1],
         [1,4,6,4,1]]
```

#### Example 2

```plaintext
Input: numRows = 1
Output: [[1]]
```

---

### Constraints

- 1 <= numRows <= 30

---

## Approach

We can generate Pascal's Triangle by:

1. Initializing the first row with `[1]`.
2. Iteratively computing each subsequent row based on the previous one:
   - The first element of every row is always `1`.
   - Every intermediate element is computed using the formula:  
     \[
     C(n, k) = C(n, k-1) \cdot \frac{n-k+1}{k}
     \]
   - The final element of every row is again `1`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalTriangle;

        int element = 1;

        // Add the first row manually
        pascalTriangle.push_back({element});

        for (int row = 1; row < numRows; row++) {
            vector<int> pascalRow;

            // First element is always 1
            pascalRow.push_back(element);
            element = 1;

            // Compute intermediate elements
            for (int col = 1; col <= row; col++) {
                element *= (row - col + 1);
                element /= col;
                pascalRow.push_back(element);
            }

            pascalTriangle.push_back(pascalRow);
        }

        return pascalTriangle;
    }
};
```

```cpp
#include <bits/stdc++.h>

vector<vector<long long int>> printPascal(int n)
{
  // Write your code here.

  vector<vector<long long int>> pascalTriangle(n);

  for(int row = 1; row <= n; row++)
  {
    long long int element = 1;

    vector<long long int> pascalRow;

    for(int col = 1; col <= row; col++)
    {
      pascalRow.push_back((int)element);

      element = element * (row - col) / col;
    }

    pascalTriangle.push_back(pascalRow);
  }

  return pascalTriangle;
}
```

#### Explanation

- We start with a base row of `[1]`.
- For each new row:
  - Begin with `1`.
  - Use the mathematical formula for combinations to derive the remaining elements.
  - Push the entire row into the result triangle.

This approach is efficient as it avoids nested loops and redundant computations by leveraging the iterative form of the binomial coefficient.

---

## Complexity Analysis

- **Time Complexity:** O(numRows²)  
  Each row has at most `numRows` elements, and we compute them in a nested fashion.

- **Space Complexity:** O(numRows²)  
  We're storing all rows up to `numRows` in a 2D vector.

---

## How to Run the Code

### For C++

1. Save the code into a `.cpp` file.
2. Include a main function to test the `generate()` method:

   ```cpp
   #include <iostream>
   #include <vector>
   using namespace std;

   // Include the Solution class here

   int main() {
       Solution sol;
       int numRows = 5;
       vector<vector<int>> triangle = sol.generate(numRows);

       for (const auto& row : triangle) {
           for (int val : row) {
               cout << val << " ";
           }
           cout << endl;
       }

       return 0;
   }
   ```

3. Compile and run:

```bash
g++ -o pascal_triangle pascal_triangle.cpp
./pascal_triangle
```

---

### Other Solutions

### Solution - 1 Using Recursion

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};

        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);

        for (int i = 1; i < numRows - 1; i++) {
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }

        prevRows.push_back(newRow);
        return prevRows;
    }
};
```

```java
class Solution {
    public List<List<Integer>> generate(int numRows) {
        if (numRows == 0) return new ArrayList<>();
        if (numRows == 1) {
            List<List<Integer>> result = new ArrayList<>();
            result.add(Arrays.asList(1));
            return result;
        }

        List<List<Integer>> prevRows = generate(numRows - 1);
        List<Integer> newRow = new ArrayList<>();

        for (int i = 0; i < numRows; i++) {
            newRow.add(1);
        }

        for (int i = 1; i < numRows - 1; i++) {
            newRow.set(i, prevRows.get(numRows - 2).get(i - 1) + prevRows.get(numRows - 2).get(i));
        }

        prevRows.add(newRow);
        return prevRows;
    }
}
```

### Method 2: Using Combinatorial Formula

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for (int i = 0; i < numRows; i++) {
            vector<int> row(i + 1, 1);
            for (int j = 1; j < i; j++) {
                row[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(row);
        }
        return result;
    }
};
```

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) {
            return result;
        }

        List<Integer> firstRow = new ArrayList<>();
        firstRow.add(1);
        result.add(firstRow);

        for (int i = 1; i < numRows; i++) {
            List<Integer> prevRow = result.get(i - 1);
            List<Integer> currentRow = new ArrayList<>();
            currentRow.add(1);

            for (int j = 1; j < i; j++) {
                currentRow.add(prevRow.get(j - 1) + prevRow.get(j));
            }

            currentRow.add(1);
            result.add(currentRow);
        }

        return result;
    }
}
```

### Method 3: Using Dynamic Programming with 1D Array

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> prevRow;

        for (int i = 0; i < numRows; i++) {
            vector<int> currentRow(i + 1, 1);

            for (int j = 1; j < i; j++) {
                currentRow[j] = prevRow[j - 1] + prevRow[j];
            }

            result.push_back(currentRow);
            prevRow = currentRow;
        }

        return result;
    }
};
```

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> result = new ArrayList<>();
        if (numRows == 0) {
            return result;
        }

        if (numRows == 1) {
            List<Integer> firstRow = new ArrayList<>();
            firstRow.add(1);
            result.add(firstRow);
            return result;
        }

        result = generate(numRows - 1);
        List<Integer> prevRow = result.get(numRows - 2);
        List<Integer> currentRow = new ArrayList<>();
        currentRow.add(1);

        for (int i = 1; i < numRows - 1; i++) {
            currentRow.add(prevRow.get(i - 1) + prevRow.get(i));
        }

        currentRow.add(1);
        result.add(currentRow);

        return result;
    }
}
```

### Solution - 4

```cpp
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].assign(i + 1, 1);

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};
```

```cpp
vector<vector<int>> generate(int numRows)
{
  vector<vector<int>> ret;
  for (int i = 0; i < numRows; i++)
  {
    vector<int> row(i + 1, 1);
    for (int j = 1; j < i; j++)
    {
      row[j] = ret[i - 1][j] + ret[i - 1][j - 1];
    }
    ret.push_back(row);
  }
  return ret;
}
```
