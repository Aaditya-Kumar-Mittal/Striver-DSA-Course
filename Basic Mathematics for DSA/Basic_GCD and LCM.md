# LCM And GCD

## Table of Contents

- [LCM And GCD](#lcm-and-gcd)
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

---

## Introduction

This problem involves calculating two mathematical properties between a pair of integers: the **Least Common Multiple (LCM)** and the **Greatest Common Divisor (GCD)**. Given two positive integers, we are to return their LCM and GCD in an array.

---

## Problem Description

Given two integers `a` and `b`, compute their LCM and GCD and return them as an array in the format `[LCM, GCD]`.

### Examples

#### Example 1

**Input:**  
`a = 5`, `b = 10`  
**Output:**  
`[10, 5]`  
**Explanation:**  
GCD of 5 and 10 is 5  
LCM = (5 \* 10) / 5 = 10

#### Example 2

**Input:**  
`a = 14`, `b = 8`  
**Output:**  
`[56, 2]`  
**Explanation:**  
GCD of 14 and 8 is 2  
LCM = (14 \* 8) / 2 = 56

#### Example 3

**Input:**  
`a = 1`, `b = 1`  
**Output:**  
`[1, 1]`  
**Explanation:**  
GCD = 1  
LCM = (1 \* 1) / 1 = 1

---

### Constraints

- `1 <= a, b <= 10^9`

---

## Approach

1. **Calculate GCD** using the **Euclidean algorithm**.
2. **Calculate LCM** using the formula:  
   \[
   \text{LCM}(a, b) = \frac{a \times b}{\text{GCD}(a, b)}
   \]
3. Return the result as a vector/array: `[LCM, GCD]`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to calculate GCD using Euclidean Algorithm
    int calculateGCD(int a, int b) {
        while (a > 0 && b > 0) {
            if (a > b) a = a % b;
            else b = b % a;
        }
        return (a == 0) ? b : a;
    }

    // Function to compute both LCM and GCD
    vector<int> lcmAndGcd(int a, int b) {
        int myGCD = calculateGCD(a, b);
        long long product = 1LL * a * b;  // prevent overflow
        int myLCM = product / myGCD;
        return {myLCM, myGCD};
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        int A, B;
        cin >> A >> B;
        Solution ob;
        vector<int> ans = ob.lcmAndGcd(A, B);
        cout << ans[0] << " " << ans[1] << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity:** `O(log(min(a, b)))`
  - Due to the Euclidean Algorithm used in computing GCD.
- **Space Complexity:** `O(1)`
  - Constant space used.

---

## How to Run the Code

### For C++

1. Save the code to a file, say `main.cpp`.
2. Open terminal and compile the file:

   ```bash
   g++ main.cpp -o main
   ```

3. Run the compiled file:

   ```bash
   ./main
   ```

4. Provide input in the following format:

   ```bash
   2
   5 10
   14 8
   ```
