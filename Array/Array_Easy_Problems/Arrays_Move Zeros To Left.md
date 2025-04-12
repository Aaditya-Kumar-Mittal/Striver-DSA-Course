# Move Zeros To Left

## Table of Contents

- [Move Zeros To Left](#move-zeros-to-left)
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
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

In this problem, you are required to move all the zeros in an array to the left side in-place. The challenge is to rearrange the elements so that all zeros appear at the beginning of the array while the relative order of the non-zero elements (toward the right) remains unchanged after the shifting.

---

## Problem Description

You are given an array `arr` of size `n`. Your task is to modify the array **in-place** such that all zeros are moved to the left end of the array while non-zero elements maintain their relative order from the original array.

For example, consider an array with some zeros interspersed with non-zero integers. The goal is to slide every zero toward the beginning of the array without using any extra space.

---

### Examples

#### Example 1

```cpp
Input:  arr = [1, 0, 2, 0, 4, 0, 5]
Output: [0, 0, 0, 1, 2, 4, 5]
```

#### Example 2

```cpp
Input:  arr = [0, 0, 1, 2]
Output: [0, 0, 1, 2]
```

#### Example 3

```cpp
Input:  arr = [1, 2, 3]
Output: [1, 2, 3]
```

---

### Constraints

- `1 <= n <= 10^5`
- Each element in `arr` can be any integer in the range `[-10^9, 10^9]`
- The operation must be done **in-place**, i.e., with O(1) extra space.
- Time limit: 1 second

---

## Approach

The approach for solving this problem is as follows:

1. **Locate the rightmost zero:**  
   Start from the end of the array and search backwards to find the first occurrence of a zero. Let the index of this zero be `j`.

2. **Traverse the array backwards:**  
   From index `j - 1` down to `0`, for each element:

   - If the element is **not zero**, swap it with the element at index `j` (which is zero).
   - Decrement `j` so that subsequent swaps target the next zero position moving left.

3. **Finish early if no zeros are present:**  
   If no zero is found in the initial scan (i.e., `j` remains `-1`), there is nothing to change, and you return immediately.

This strategy ensures that all zeros are shifted to the left while non-zero elements retain their original order towards the right.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void moveZerosToLeft(int *arr, int n) {
    // Step 1: Find the rightmost zero in the array
    int j = -1;
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == 0) {
            j = i;
            break;
        }
    }

    // If no zero is found, no need to modify the array.
    if (j == -1) return;

    // Step 2: Traverse from the element before the rightmost zero
    for (int i = j - 1; i >= 0; i--) {
        // If a non-zero element is found, swap it with the element at index j.
        if (arr[i] != 0) {
            swap(arr[i], arr[j]);
            // Decrement j to move to the next zero position
            j--;
        }
    }
}
```

### Java Implementation

If needed, the Java version of the function can be implemented similarly:

```java
import java.util.*;

public class MoveZerosToLeft {
    public static void moveZerosToLeft(int[] arr) {
        int n = arr.length;
        int j = -1;

        // Step 1: Find the rightmost zero in the array
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                j = i;
                break;
            }
        }

        // If no zero is found, return the array as is.
        if (j == -1) return;

        // Step 2: Swap non-zero elements with the zero at position j, moving backwards.
        for (int i = j - 1; i >= 0; i--) {
            if (arr[i] != 0) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                j--;
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 0, 2, 0, 4, 0, 5};
        moveZerosToLeft(arr);
        System.out.println(Arrays.toString(arr)); // Expected Output: [0, 0, 0, 1, 2, 4, 5]
    }
}
```

---

## Complexity Analysis

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(n)  |
| Space Complexity | O(1)  |

- **Time Complexity:**  
  The algorithm traverses the array at most twice (once for finding the rightmost zero and once for swapping elements), which results in O(n) time complexity.
- **Space Complexity:**  
  The algorithm performs all swaps in-place, so it only uses constant extra space, O(1).

---

## How to Run the Code

### For C++

1. **Save the code:**  
   Save the C++ code in a file named `moveZeros.cpp`.

2. **Add a main() function for testing:**

   ```cpp
   #include <iostream>
   #include <algorithm>
   using namespace std;

   void moveZerosToLeft(int *arr, int n) {
       int j = -1;
       for (int i = n - 1; i >= 0; i--) {
           if (arr[i] == 0) {
               j = i;
               break;
           }
       }

       if (j == -1) return;

       for (int i = j - 1; i >= 0; i--) {
           if (arr[i] != 0) {
               swap(arr[i], arr[j]);
               j--;
           }
       }
   }

   int main() {
       int arr[] = {1, 0, 2, 0, 4, 0, 5};
       int n = sizeof(arr) / sizeof(arr[0]);

       moveZerosToLeft(arr, n);

       for (int i = 0; i < n; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
       return 0;
   }
   ```

3. **Compile and run:**

   ```bash
   g++ moveZeros.cpp -o moveZeros
   ./moveZeros
   ```

   **Expected Output:**

   ```bash
   0 0 0 1 2 4 5
   ```

### For Java

1. **Save the code:**  
   Save the Java code in a file named `MoveZerosToLeft.java`.

2. **Compile and run:**

   ```bash
   javac MoveZerosToLeft.java
   java MoveZerosToLeft
   ```

   **Expected Output:**

   ```bash
   [0, 0, 0, 1, 2, 4, 5]
   ```

---
