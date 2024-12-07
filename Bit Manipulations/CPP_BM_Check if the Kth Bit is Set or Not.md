# Check if the Kth Bit is Set or Not

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Check if the Kth Bit is Set or Not](#check-if-the-kth-bit-is-set-or-not)
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

This program checks if the **Kth bit** of a given integer \( x \) is set (i.e., equals 1). The solution leverages **bitwise operations** to perform the check efficiently.

---

## Problem Description

The task is to determine if the \( K \)-th bit of a number \( x \) is set. Bits are zero-indexed, meaning the least significant bit (LSB) is at position 0.

### Examples

#### Example 1

**Input**: `x = 5, k = 0`  
**Output**: `true`  
**Explanation**: The binary representation of `5` is `101`. The 0th bit (LSB) is `1`.

#### Example 2

**Input**: `x = 8, k = 2`  
**Output**: `false`  
**Explanation**: The binary representation of `8` is `1000`. The 2nd bit is `0`.

#### Example 3

**Input**: `x = 7, k = 2`  
**Output**: `true`  
**Explanation**: The binary representation of `7` is `111`. The 2nd bit is `1`.

---

### Constraints

1. \( x \) is a non-negative integer.
2. \( 0 \leq k < \text{number of bits in } x \).
3. Input values are within the range of the respective data types (e.g., `int` in C++ and Java).

---

## Approach

1. **Bitwise AND Operation**:

   - To check if the \( K \)-th bit of \( x \) is set, we use the operation \( x \& (1 \ll K) \).
   - \( 1 \ll K \): Creates a number with only the \( K \)-th bit set.
   - \( x \& (1 \ll K) \): Retains the \( K \)-th bit of \( x \), setting all other bits to 0.

2. **Result Interpretation**:

   - If \( x \& (1 \ll K) \neq 0 \), the \( K \)-th bit is set.
   - Otherwise, the \( K \)-th bit is not set.

3. **Edge Case**:
   - If \( k \) exceeds the bit length of \( x \), the result is always `false`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Function to check if the Kth bit is set or not
bool checkIfKthBitisSetOrNot(int x, int k) {
    return x & (1 << k);
}

int main() {
    int a, b;

    // Take user inputs
    cin >> a >> b;

    // Check and display if the Kth bit is set or not
    cout << "Check if Kth bit is set or not: " << checkIfKthBitisSetOrNot(a, b) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a >> b;` takes the integer \( x \) and the bit position \( k \) from the user.
2. **Bit Check**:
   - The function `checkIfKthBitisSetOrNot` uses the bitwise operation \( x \& (1 \ll k) \) to determine if the \( k \)-th bit of \( x \) is set.
3. **Output**:
   - Displays `1` if the \( k \)-th bit is set and `0` otherwise.

---

### Java Implementation

```java
import java.util.Scanner;

public class Main {
    // Function to check if the Kth bit is set or not
    static boolean checkIfKthBitisSetOrNot(int x, int k) {
        return (x & (1 << k)) != 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take user inputs
        int a = sc.nextInt();
        int b = sc.nextInt();

        // Check and display if the Kth bit is set or not
        System.out.println("Check if Kth bit is set or not: " + checkIfKthBitisSetOrNot(a, b));

        sc.close();
    }
}
```

#### Explanation

1. **Input Handling**:
   - `Scanner` is used to take user input for \( x \) and \( k \).
2. **Bit Check**:
   - The function `checkIfKthBitisSetOrNot` uses the bitwise operation \( x \& (1 \ll k) \) to determine if the \( k \)-th bit of \( x \) is set.
   - `(x & (1 << k)) != 0` ensures the output is `true` or `false`.
3. **Output**:
   - Displays `true` if the \( k \)-th bit is set and `false` otherwise.

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
   - The first integer represents \( x \).
   - The second integer represents \( k \).

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
   - The first integer represents \( x \).
   - The second integer represents \( k \).
