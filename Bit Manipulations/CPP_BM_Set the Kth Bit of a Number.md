# Set the Kth Bit of a Number

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Set the Kth Bit of a Number](#set-the-kth-bit-of-a-number)
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

This program **sets the Kth bit** of a given integer \( a \). Setting a bit means ensuring the bit's value is `1` regardless of its initial value.

The solution utilizes **bitwise OR (|)** operation for an efficient implementation.

---

## Problem Description

Given an integer \( a \) and a bit position \( k \), set the \( k \)-th bit of \( a \) to `1` and return the resulting number.

### Examples

#### Example 1

**Input**: `a = 5, k = 1`  
**Output**: `7`  
**Explanation**: The binary representation of `5` is `101`. After setting the 1st bit, it becomes `111`, which is `7`.

#### Example 2

**Input**: `a = 8, k = 0`  
**Output**: `9`  
**Explanation**: The binary representation of `8` is `1000`. After setting the 0th bit, it becomes `1001`, which is `9`.

#### Example 3

**Input**: `a = 7, k = 2`  
**Output**: `7`  
**Explanation**: The binary representation of `7` is `111`. Since the 2nd bit is already `1`, the result remains unchanged.

---

### Constraints

1. \( a \) is a non-negative integer.
2. \( 0 \leq k < \text{number of bits in } a \).
3. Input values are within the range of the respective data types (e.g., `int` in C++ and Java).

---

## Approach

1. **Bitwise OR Operation**:
   - To set the \( k \)-th bit of \( a \), use \( a | (1 \ll k) \).
   - \( 1 \ll k \): Creates a number with only the \( k \)-th bit set.
   - \( a | (1 \ll k) \): Ensures the \( k \)-th bit is `1` while leaving other bits unchanged.

2. **Result Explanation**:
   - If the \( k \)-th bit is already `1`, the result remains the same.
   - If the \( k \)-th bit is `0`, the OR operation changes it to `1`.

3. **Edge Case**:
   - If \( k \) exceeds the bit length of \( a \), the result behaves as if \( k \)-th bit is outside the number.

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

    // Set the Kth bit and display the result
    cout << "Set kth Bit: " << (a | (1 << b)) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a >> b;` takes the integer \( a \) and the bit position \( k \) (stored in \( b \)) from the user.
2. **Bit Setting**:
   - The operation \( a | (1 \ll b) \) sets the \( b \)-th bit of \( a \) to `1`.
3. **Output**:
   - Displays the resulting integer after setting the \( b \)-th bit.

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

        // Set the Kth bit and display the result
        System.out.println("Set kth Bit: " + (a | (1 << b)));

        sc.close();
    }
}
```

#### Explanation

1. **Input Handling**:
   - `Scanner` is used to take user input for \( a \) and \( b \).
2. **Bit Setting**:
   - The operation \( a | (1 \ll b) \) sets the \( b \)-th bit of \( a \) to `1`.
3. **Output**:
   - Displays the resulting integer after setting the \( b \)-th bit.

---

## Complexity Analysis

### Time Complexity

- **Bitwise Operation**: \( O(1) \)
- **Input and Output**: \( O(1) \)
- Total: \( O(1) \)

### Space Complexity

- The program uses a constant amount of space.
- Space complexity: \( O(1) \).

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
   - The second integer represents \( k \) (bit position to set).

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
   - The second integer represents \( k \) (bit position to set).
