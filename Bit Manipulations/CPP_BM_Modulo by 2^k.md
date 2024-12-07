# Modulo by \( 2^k \)

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Modulo by ( 2^k )](#modulo-by--2k-)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Bitwise AND with Mask](#bitwise-and-with-mask)
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

This program calculates the modulo operation \( a \mod 2^k \) using bitwise operations. The method efficiently uses the **bitwise AND operator (`&`)** to compute the result.

---

## Problem Description

Given an integer \( a \) and an integer \( k \), compute \( a \mod 2^k \) using bitwise operations.

---

### Examples

#### Example 1

**Input**: `a = 13, k = 3`  
**Output**: `5`  
**Explanation**: \( 13 \mod 2^3 = 13 \mod 8 = 5 \).

#### Example 2

**Input**: `a = 15, k = 4`  
**Output**: `15`  
**Explanation**: \( 15 \mod 2^4 = 15 \mod 16 = 15 \).

#### Example 3

**Input**: `a = 20, k = 2`  
**Output**: `0`  
**Explanation**: \( 20 \mod 2^2 = 20 \mod 4 = 0 \).

---

### Constraints

1. \( a \) is an integer.
2. \( k \) is a non-negative integer.
3. \( k \leq \text{number of bits in integer representation}\).

---

## Approach

### Bitwise AND with Mask

The formula \( a \mod 2^k \) can be calculated as:
\[
a \& ((1 << k) - 1)
\]

- \( (1 << k) \): Left shifts `1` by \( k \) positions to create a mask \( 2^k \).
- Subtracting `1` from \( 2^k \) results in a bitmask where the last \( k \) bits are set to `1`.
- Applying bitwise AND (`&`) with \( a \) retains the last \( k \) bits of \( a \), effectively computing \( a \mod 2^k \).

### Steps

1. Take two inputs \( a \) and \( k \).
2. Compute \( a \& ((1 << k) - 1) \).
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

    // Compute a modulo 2^b
    cout << "Modulo by 2^k " << (a & ((1 << b) - 1)) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a >> b;` takes two integers \( a \) and \( b \) as input.
2. **Bitwise Modulo Operation**:
   - The expression \( a \& ((1 << b) - 1) \) computes \( a \mod 2^b \).
3. **Output**:
   - Displays the result of \( a \mod 2^b \).

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

        // Compute a modulo 2^b
        System.out.println("Modulo by 2^k " + (a & ((1 << b) - 1)));

        sc.close();
    }
}
```

#### Explanation

1. **Input Handling**:
   - `Scanner` is used to read \( a \) and \( b \).
2. **Bitwise Modulo Operation**:
   - The expression \( a \& ((1 << b) - 1) \) computes \( a \mod 2^b \).
3. **Output**:
   - Displays the result of \( a \mod 2^b \).

---

## Complexity Analysis

### Time Complexity

- **Bitwise AND Operation**: \( O(1) \)
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
