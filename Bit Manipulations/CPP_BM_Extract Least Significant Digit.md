# Extract Least Significant Digit

## Table of Contents

- [Extract Least Significant Digit](#extract-least-significant-digit)
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
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

This program calculates the **least significant digit (LSD)** of a given integer using the **bitwise AND operator**. The least significant digit for binary representation refers to the last bit in a number. For integers, the LSD corresponds to whether the number is **even (0)** or **odd (1)**.

---

## Problem Description

The task is to extract the least significant digit of an integer using an efficient bitwise operation and display it.

### Examples

#### Example 1

**Input**: `5`  
**Output**: `The least significant digit is: 1`  
**Explanation**: The binary representation of `5` is `101`. The last bit is `1`, indicating an odd number.

#### Example 2

**Input**: `8`  
**Output**: `The least significant digit is: 0`  
**Explanation**: The binary representation of `8` is `1000`. The last bit is `0`, indicating an even number.

---

### Constraints

1. Input is an integer, and its size is constrained by the limits of the `int` data type in the respective language.
2. Output is a single digit: `0` for even and `1` for odd.

---

## Approach

- Use the **bitwise AND operator** (`&`) to isolate the least significant bit of the number:
  - `a & 1`: Compares each bit of `a` with `1`. Since `1` in binary is `000...001`, only the last bit of `a` determines the result.
  - Result will be:
    - `0` for even numbers (last bit is `0`).
    - `1` for odd numbers (last bit is `1`).

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

int main() {
    int a;

    // Take user input
    cin >> a;

    // Calculate the least significant digit
    cout << "The least significant digit is: " << (a & 1) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a;` reads an integer from the user.
2. **Bitwise Operation**:
   - `(a & 1)` extracts the least significant bit of `a`.
3. **Output**:
   - Prints the LSD using `cout`.

---

### Java Implementation

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        // Create a scanner object for input
        Scanner scanner = new Scanner(System.in);

        // Prompt the user for input
        System.out.print("Enter an integer: ");
        int a = scanner.nextInt();

        // Determine the least significant digit (LSD)
        int lsd = a & 1;

        // Print the result
        System.out.println("The least significant digit is: " + lsd);

        // Close the scanner
        scanner.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Input Handling**: \( O(1) \)
- **Bitwise AND Operation**: \( O(1) \)
- **Output Operation**: \( O(1) \)

### Space Complexity

- The program uses only a single integer variable `a` for input and a constant amount of space for processing.
- Space complexity: \( O(1) \).

---

## How to Run the Code

### For C++

1. Save the code in a file named `main.cpp`.
2. Compile using:

   ```bash
   g++ -o main main.cpp
   ```

3. Run the compiled program:

   ```bash
   ./main
   ```

4. Enter an integer when prompted.

### For Java

1. Save the code in a file named `Main.java`.
2. Compile using:

   ```bash
   javac Main.java
   ```

3. Run the compiled program:

   ```bash
   java Main
   ```

4. Enter an integer when prompted.
