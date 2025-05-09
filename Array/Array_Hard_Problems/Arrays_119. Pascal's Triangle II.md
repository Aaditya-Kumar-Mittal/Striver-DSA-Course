# Pascal's Triangle II

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Pascal's Triangle II](#pascals-triangle-ii)
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
    - [C++ Implementation - Method 1 (Using Factorial Logic)](#c-implementation---method-1-using-factorial-logic)
      - [Explanation](#explanation)
    - [C++ Implementation - Method 2 (Using Optimized Iterative Combinatorics)](#c-implementation---method-2-using-optimized-iterative-combinatorics)
      - [Explanation](#explanation-1)
  - [Complexity Analysis](#complexity-analysis)
    - [Method 1](#method-1)
    - [Method 2 (Optimized)](#method-2-optimized)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2](#solution---2)

---

## Introduction

Pascal’s Triangle is a famous number triangle where each element is the sum of the two elements directly above it in the previous row. Each row corresponds to the coefficients of the binomial expansion of \((a + b)^n\).

---

## Problem Description

Given an integer `rowIndex`, return the `rowIndex`th (0-indexed) row of Pascal's triangle.

Each element of a row can be computed either:

- Recursively by using the values of the row above, or
- Using combinatorics, i.e., **nCr = n! / (r! \* (n - r)!)**

### Examples

#### Example 1

```plaintext
Input: rowIndex = 3
Output: [1, 3, 3, 1]
```

#### Example 2

```plaintext
Input: rowIndex = 0
Output: [1]
```

#### Example 3

```plaintext
Input: rowIndex = 1
Output: [1, 1]
```

---

### Constraints

- 0 <= rowIndex <= 33

---

## Approach

We present two approaches:

1. **Method 1** – Using a helper function that computes nCr using a loop (factorial logic).
2. **Method 2** – Optimized method that uses previous value to compute the next value directly, saving space and avoiding repeated calculations.

---

## Detailed Explanation of Code

### C++ Implementation - Method 1 (Using Factorial Logic)

```cpp
class Solution {
public:
    int calculateNCRthElement(int n, int r) {
        long long res = 1;
        for (int i = 0; i < r; i++) {
            res *= (n - i);
            res /= (i + 1);
        }
        return res;
    }

    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        // Function-Based Approach using calculateNCRthElement
        for (int column = 0; column <= rowIndex; column++) {
            ans.push_back(calculateNCRthElement(rowIndex, column));
        }
        return ans;
    }
};
```

#### Explanation

- We define a helper function `calculateNCRthElement(n, r)` to calculate each term of the Pascal row.
- For each index from 0 to rowIndex, we compute `nCr` and add to the result vector.

---

### C++ Implementation - Method 2 (Using Optimized Iterative Combinatorics)

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long result = 1;

        // First element is always 1
        ans.push_back(result);

        for (int column = 1; column <= rowIndex; column++) {
            // Compute next binomial coefficient using previous value
            result *= (rowIndex + 1 - column);
            result /= column;
            ans.push_back(result);
        }

        return ans;
    }
};
```

#### Explanation

- Begin with 1 (C(n, 0) = 1).
- Use the relationship `C(n, k) = C(n, k-1) * (n - k + 1) / k` to iteratively build each value without recalculating factorials.
- This approach ensures that space and computation are minimized.

---

## Complexity Analysis

### Method 1

- **Time Complexity:** O(rowIndex)
- **Space Complexity:** O(rowIndex)

### Method 2 (Optimized)

- **Time Complexity:** O(rowIndex)
- **Space Complexity:** O(rowIndex)
- **Extra Space:** Constant (excluding result array)

---

## How to Run the Code

### For C++

1. Save the code into a `.cpp` file.
2. Include a main function to test the `getRow()` method:

   ```cpp
    #iclude <iostream>
    #include <vector>
    using namespace std;

    // Include the Solution class here

    int main() {
        Solution sol;
        int rowIndex = 5;
        vector<int> result = sol.getRow(rowIndex);

        for (int val : result) {
            cout << val << " ";
        }
        cout << endl;

        return 0;
    }
   ```

3. Compile and run:

```bash
g++ -o pascal pascal.cpp
./pascal
```

---

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> A(rowIndex+1, 0);
        A[0] = 1;
        for(int i=1; i<rowIndex+1; i++)
            for(int j=i; j>=1; j--)
                A[j] += A[j-1];
        return A;
    }
};
```

```java
public class Solution {
    public List<Integer> getRow(int k) {
        Integer[] arr = new Integer[k + 1];
        Arrays.fill(arr, 0);
        arr[0] = 1;

        for (int i = 1; i <= k; i++)
            for (int j = i; j > 0; j--)
                arr[j] = arr[j] + arr[j - 1];

        return Arrays.asList(arr);
    }
}
```

### Solution - 2

```java

class Solution {

    public List<Integer> getRow(int r) {
        List<Integer> ans = new ArrayList<>();
        ans.add(1);
        long temp = 1;
        for (int i = 1, up = r, down = 1; i <= r; i++, up--, down++) {
            temp = temp * up / down;
            ans.add((int) temp);
        }
        return ans;
    }
}

```

```cpp
class Solution
{
public:
  vector<int> getRow(int r)
  {
    vector<int> v(r + 1);
    long temp = 1;
    v[0] = v[r] = 1;
    for (int i = 1, up = r, down = 1; i < r; i++, up--, down++)
    {
      temp = temp * up / down;
      v[i] = temp;
    }
    return v;
  }
};
```
