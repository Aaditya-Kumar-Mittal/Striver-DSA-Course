# Check if a Number is a Power of 2

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Check if a Number is a Power of 2](#check-if-a-number-is-a-power-of-2)
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

This program determines whether a given integer is a power of 2 using an efficient **bitwise operation**. A number is a power of 2 if it has only one set bit in its binary representation.

---

## Problem Description

The task is to check if an integer \( x \) is a power of 2. The program will output `true` if the number is a power of 2 and `false` otherwise.

### Examples

#### Example 1

**Input**: `4`  
**Output**: `true`  
**Explanation**: The binary representation of `4` is `100`. It has only one set bit, making it a power of 2.

#### Example 2

**Input**: `6`  
**Output**: `false`  
**Explanation**: The binary representation of `6` is `110`. It has more than one set bit, so it is not a power of 2.

#### Example 3

**Input**: `1`  
**Output**: `true`  
**Explanation**: The binary representation of `1` is `1`. It has exactly one set bit, making it a power of 2.

---

### Constraints

1. \( x \) is an integer within the range of the data type (`int` in C++ or Java).
2. \( x > 0 \) for valid input since only positive numbers can be powers of 2.

---

## Approach

1. **Observation**:

   - A number \( x \) is a power of 2 if and only if there is exactly one bit set in its binary representation.
   - For such \( x \), \( x - 1 \) flips all bits to the right of the set bit and clears the set bit itself.
   - Using the expression `x & (x - 1)`:
     - If \( x \) is a power of 2, this operation yields `0`.
     - If \( x \) is not a power of 2, this operation yields a non-zero result.

2. **Edge Case**:

   - If \( x = 0 \), it is not a power of 2.

3. **Implementation**:
   - Use the condition `x > 0 && !(x & (x - 1))` in Java or `x && !(x & (x - 1))` in C++:
     - `x`: Ensures \( x > 0 \).
     - `!(x & (x - 1))`: Confirms \( x \) is a power of 2.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Function to check if a number is a power of 2
bool isPowerOf2(int x) {
    return x && !(x & (x - 1));
}

int main() {
    int a;

    // Take user input
    cin >> a;

    // Check and display whether the number is a power of 2
    cout << "Is Power of 2: " << isPowerOf2(a) << endl;

    return 0;
}
```

#### Explanation

1. **Input Handling**:
   - `cin >> a;` reads an integer from the user.
2. **Power of 2 Check**:
   - The function `isPowerOf2(x)` uses the bitwise operation `x & (x - 1)` to determine if \( x \) is a power of 2.
   - The additional check `x` ensures \( x > 0 \).
3. **Output**:
   - Displays `1` if \( x \) is a power of 2 and `0` otherwise.

---

### Java Implementation

```java
import java.util.Scanner;

public class Main {
    // Function to check if a number is a power of 2
    static boolean isPowerOf2(int x) {
        return x > 0 && (x & (x - 1)) == 0;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Take user input
        int a = sc.nextInt();

        // Check and display whether the number is a power of 2
        System.out.println("Is Power of 2: " + isPowerOf2(a));

        sc.close();
    }
}
```

#### Explanation

1. **Input Handling**:
   - `Scanner` is used to take user input in Java.
2. **Power of 2 Check**:
   - The function `isPowerOf2(x)` uses the bitwise operation `x & (x - 1)` to determine if \( x \) is a power of 2.
   - The additional check `x > 0` ensures \( x \) is positive.
3. **Output**:
   - Displays `true` if \( x \) is a power of 2 and `false` otherwise.

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

4. Enter an integer when prompted, and the program will output whether it is a power of 2.

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

4. Enter an integer when prompted, and the program will output whether it is a power of 2.
