# Divide by \( 2^k \)

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Divide by ( 2^k )](#divide-by--2k-)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Bitwise Right Shift (( \>\> ))](#bitwise-right-shift---)
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

This program divides a given number \( a \) by \( 2^k \) using the bitwise **right shift operator (`>>`)**. This method is an efficient way to perform division by powers of 2.

---

## Problem Description

Given an integer \( a \) and an integer \( k \), compute the value of \( a / 2^k \) using bitwise operations.

---

### Examples

#### Example 1

**Input**: `a = 8, k = 2`  
**Output**: `2`  
**Explanation**: \( 8 / 2^2 = 8 / 4 = 2 \).

#### Example 2

**Input**: `a = 15, k = 3`  
**Output**: `1`  
**Explanation**: \( 15 / 2^3 = 15 / 8 = 1 \) (integer division).

#### Example 3

**Input**: `a = 64, k = 6`  
**Output**: `1`  
**Explanation**: \( 64 / 2^6 = 64 / 64 = 1 \).

---

### Constraints

1. \( a \) is an integer.
2. \( k \) is a non-negative integer.
3. \( k \leq \text{number of bits in integer representation}\).

---

## Approach

### Bitwise Right Shift (\( >> \))

The right shift operation \( a >> k \) shifts the binary representation of \( a \) to the right by \( k \) positions. Each shift effectively divides \( a \) by \( 2 \), discarding any remainder. Therefore:
\[
a / 2^k = a >> k
\]

### Steps

1. Take two inputs \( a \) and \( k \).
2. Use the right shift operator to compute \( a >> k \).
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

    // Divide a by 2^b and display the result
    cout << "Divide by 2^k " << (a >> b) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a >> b;` takes two integers \( a \) and \( b \) as input.
2. **Bitwise Division**:
   - The operation \( a >> b \) computes \( a / 2^b \).
3. **Output**:
   - Displays the result of dividing \( a \) by \( 2^b \).

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

        // Divide a by 2^b and display the result
        System.out.println("Divide by 2^k " + (a >> b));

        sc.close();
    }
}
```

#### Explanation

1. **Input Handling**:
   - `Scanner` is used to read \( a \) and \( b \).
2. **Bitwise Division**:
   - The operation \( a >> b \) computes \( a / 2^b \).
3. **Output**:
   - Displays the result of dividing \( a \) by \( 2^b \).

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
