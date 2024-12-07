# Multiply by \( 2^k \)

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Multiply by ( 2^k )](#multiply-by--2k-)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Bitwise Left Shift (( \<\< ))](#bitwise-left-shift---)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Explanation](#explanation)
    - [Java Implementation](#java-implementation)
      - [Explanation](#explanation-1)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

This program multiplies a given number \( a \) by \( 2^k \) using the bitwise **left shift operator (`<<`)**. This approach provides a highly efficient method to perform such operations without explicit multiplication.

---

## Problem Description

Given an integer \( a \) and an integer \( k \), compute the value of \( a \times 2^k \) using bitwise operations.

### Examples

#### Example 1

**Input**: `a = 3, k = 2`  
**Output**: `12`  
**Explanation**: \( 3 \times 2^2 = 3 \times 4 = 12 \).

#### Example 2

**Input**: `a = 5, k = 3`  
**Output**: `40`  
**Explanation**: \( 5 \times 2^3 = 5 \times 8 = 40 \).

#### Example 3

**Input**: `a = 7, k = 0`  
**Output**: `7`  
**Explanation**: Multiplying by \( 2^0 \) leaves the number unchanged.

---

### Constraints

1. \( a \) is an integer.
2. \( k \) is a non-negative integer.
3. The result of \( a \times 2^k \) fits within the range of the data type.

---

## Approach

### Bitwise Left Shift (\( << \))

The left shift operation \( a << k \) shifts the binary representation of \( a \) to the left by \( k \) positions. Each shift effectively multiplies \( a \) by \( 2 \). Therefore:
\[
a \times 2^k = a << k
\]

### Steps

1. Take two inputs \( a \) and \( k \).
2. Use the left shift operator to compute \( a << k \).
3. Output the result.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

int main() {
    int a, b;

    // Take user inputs
    cin >> a >> b;

    // Multiply a by 2^b and display the result
    cout << "Multiply by 2^k " << (a << b) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a >> b;` takes two integers \( a \) and \( b \) as input.
2. **Bitwise Multiplication**:
   - The operation \( a << b \) computes \( a \times 2^b \).
3. **Output**:
   - Displays the result of multiplying \( a \) by \( 2^b \).

---

### Java Implementation

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take user inputs
        int a = sc.nextInt();
        int b = sc.nextInt();

        // Multiply a by 2^b and display the result
        System.out.println("Multiply by 2^k " + (a << b));

        sc.close();
    }
}
```

#### Explanation

1. **Input Handling**:
   - `Scanner` is used to read \( a \) and \( b \).
2. **Bitwise Multiplication**:
   - The operation \( a << b \) computes \( a \times 2^b \).
3. **Output**:
   - Displays the result of multiplying \( a \) by \( 2^b \).

---

## Complexity Analysis

### Time Complexity

- **Bitwise Shift**: \( O(1) \)
- Total: \( O(1) \)

### Space Complexity

- Uses constant space.
- Total: \( O(1) \)

---

## How to Run the Code

### For C++

1. Save the code in a file named `main.cpp`.
2. Compile the code using:

   ```bash
   g++ -o main main.cpp
   ```

3. Run the executable:

   ```bash
   ./main
   ```

4. Enter two integers when prompted:
   - The first integer represents \( a \).
   - The second integer represents \( k \) (exponent).

### For Java

1. Save the code in a file named `Main.java`.
2. Compile the code using:

   ```bash
   javac Main.java
   ```

3. Run the program:

   ```bash
   java Main
   ```

4. Enter two integers when prompted:
   - The first integer represents \( a \).
   - The second integer represents \( k \) (exponent).
