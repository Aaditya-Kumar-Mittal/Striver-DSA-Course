# Product of an Array

## Table of Contents

- [Product of an Array](#product-of-an-array)
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
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

The problem is a simple, classic task where we need to compute the **product of all elements** in an array while keeping the result within a **modulo** value of \(10^9 + 7\) to prevent overflow. This technique is extremely common in competitive programming and large number computations.

---

## Problem Description

Given an array `arr[]` of positive integers, compute the **product of all elements** modulo \(10^9 + 7\).

- **Modulo Operation**: The modulo operation finds the remainder when one number is divided by another.

---

### Examples

#### Example 1

**Input**:  
`arr[] = [1, 2, 3, 4]`

**Output**:  
`24`

**Explanation**:  
Product = \(1 \times 2 \times 3 \times 4 = 24\).  
Since 24 is smaller than \(10^9+7\), the output is simply 24.

---

#### Example 2

**Input**:  
`arr[] = [100000, 100000, 100000]`

**Output**:  
`993000007`

**Explanation**:  
Product = \(100000 \times 100000 \times 100000 = 10^{15}\).  
Taking modulo \(10^9+7\),  
\(10^{15} \mod 10^9+7 = 993000007\).

---

### Constraints

- \( 1 \leq \text{arr.size} \leq 10^5 \)
- \( 1 \leq \text{arr[i]} \leq 10^5 \)

---

## Approach

- Initialize a variable `product` to 1.
- Traverse through each element of the array.
- For each element, multiply it with `product` and take modulo \(10^9+7\) immediately to avoid overflow.
- Finally, return the `product` value.

This method ensures that the product remains within manageable limits and respects the modulo constraint throughout.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
// User function Template for C++

class Solution {
public:
    // arr[] is the input array
    long long mod = 1e9+7;

    long long int product(vector<int> &arr) {
        long long int product = 1; // Initialize product to 1

        // Traverse through each item in the array
        for (int item : arr) {
            product = (product * item) % mod; // Multiply and apply modulo
        }

        // Return the final product modulo 1e9+7
        return product;
    }
};
```

---

## Complexity Analysis

|       Type       |                         Complexity                          |
| :--------------: | :---------------------------------------------------------: |
| Time Complexity  |           \( O(n) \) — Single traversal of array            |
| Space Complexity | \( O(1) \) — No extra space used apart from a few variables |

---

## How to Run the Code

### For C++

1. **Environment**:

   - Install a C++ compiler (GCC recommended).
   - Use any IDE like VS Code, Code::Blocks, or online compilers like CodeChef IDE.

2. **Steps**:

   - Save the code in a file with `.cpp` extension (e.g., `ProductOfArray.cpp`).
   - Compile the code:

     ```bash
     g++ ProductOfArray.cpp -o ProductOfArray
     ```

   - Run the executable:

     ```bash
     ./ProductOfArray
     ```

3. **Input Format**:
   - Pass a vector of integers as the array input.
   - Invoke the `product` method by creating an object of the `Solution` class.

---
