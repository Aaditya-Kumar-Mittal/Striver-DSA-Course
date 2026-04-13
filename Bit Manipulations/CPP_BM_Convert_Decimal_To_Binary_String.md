# 🧮 Decimal to Binary Conversion

## Table of Contents

- [🧮 Decimal to Binary Conversion](#-decimal-to-binary-conversion)
  - [Table of Contents](#table-of-contents)
  - [🧾 Introduction](#-introduction)
  - [📋 Problem Description](#-problem-description)
    - [✅ Examples](#-examples)
  - [💡 Approach](#-approach)
    - [1. Using Division Method](#1-using-division-method)
    - [2. Using Recursion](#2-using-recursion)
    - [3. Using Bitwise Operators](#3-using-bitwise-operators)
    - [4. Using `bitset` from C++ STL](#4-using-bitset-from-c-stl)
  - [🧱 Detailed Explanation of Code](#-detailed-explanation-of-code)
    - [🧾 C++ Implementation](#-c-implementation)
  - [⏱️ Complexity Analysis](#️-complexity-analysis)
  - [🖥️ How to Run the Code](#️-how-to-run-the-code)
    - [✅ For C++](#-for-c)

---

## 🧾 Introduction

The purpose of this implementation is to provide **multiple techniques** for converting a **decimal number to its binary representation**. Each method offers a different perspective: from basic arithmetic division, to recursion, bit manipulation, and STL utilities like `bitset`.

---

## 📋 Problem Description

Given a non-negative integer `n`, convert it to its binary string representation without leading zeros.

### ✅ Examples

| Input | Output     |
| ----- | ---------- |
| 0     | `"0"`      |
| 1     | `"1"`      |
| 7     | `"111"`    |
| 10    | `"1010"`   |
| 32    | `"100000"` |

---

## 💡 Approach

The solution class implements **four distinct methods** for decimal to binary conversion:

### 1. Using Division Method

- Repeatedly divide the number by 2.
- Store the remainders in reverse order.
- Reverse the result to get the binary string.

### 2. Using Recursion

- Divide number recursively by 2 until base case (`n == 0`) is hit.
- On backtrack, append the remainders.

### 3. Using Bitwise Operators

- Use `n & 1` to get the least significant bit (LSB).
- Right shift the number using `n >> 1`.
- Reverse the result at the end.

### 4. Using `bitset` from C++ STL

- Create a `bitset<64>` to get a 64-bit binary string.
- Remove leading zeros by calculating `len = log2(n)` and taking substring from `64 - len - 1`.

---

## 🧱 Detailed Explanation of Code

### 🧾 C++ Implementation

```cpp
class Solution {
  public:
  
    // Method 1: Using Division
    string usingDivision(int n)
    {
        string binaryRep = "";
        
        while(n > 0)
        {
            int rem = n % 2;
            binaryRep.push_back('0' + rem);
            n = n / 2;
        }
        
        reverse(binaryRep.begin(), binaryRep.end());
        return binaryRep;
    }

    // Method 2: Using Recursion
    void usingRecursion(int n, string &bin)
    {
        if(n == 0) return;
        usingRecursion(n/2, bin);
        bin.push_back(n%2 + '0');
    }
  
    string decToBinary1(int n) {
        if(n == 0) return "0";
        string binaryRep = "";
        usingRecursion(n, binaryRep);
        return binaryRep;
    }

    // Method 3: Using Bitwise Operators
    string usingBinaryOps(int n)
    {
        string binaryRep = "";
        
        while(n > 0)
        {
            int rem = n & 1; // least significant bit
            binaryRep.push_back('0' + rem);
            n = n >> 1;
        }
        
        reverse(binaryRep.begin(), binaryRep.end());
        return binaryRep;
    }

    // Method 4: Using Bitset + log2 to strip leading zeros
    string decToBinary(int n) {
        if (n == 0) return "0";
        int len = (int)(log2(n));
        return bitset<64>(n).to_string().substr(64 - len - 1);
    }
};
```

---

## ⏱️ Complexity Analysis

| Method                | Time Complexity | Space Complexity | Notes                                                  |
| --------------------- | --------------- | ---------------- | ------------------------------------------------------ |
| **Using Division**    | `O(log₂ n)`     | `O(log₂ n)`      | Each division reduces `n` by half                      |
| **Using Recursion**   | `O(log₂ n)`     | `O(log₂ n)`      | Recursive stack + string append                        |
| **Using Bitwise Ops** | `O(log₂ n)`     | `O(log₂ n)`      | Faster due to bit operations                           |
| **Using Bitset**      | `O(1)`          | `O(1)`           | Always creates a 64-bit string, fast and constant-time |

> ℹ️ Note: While `bitset<64>` technically has `O(1)` time due to fixed size, the `substr()` and conversion still involve some minor overhead.

---

## 🖥️ How to Run the Code

### ✅ For C++

1. Save the code to a file, e.g., `BinaryConversion.cpp`
2. Compile using `g++`:

   ```bash
   g++ BinaryConversion.cpp -o BinaryConversion
   ```

3. Run the executable:

   ```bash
   ./BinaryConversion
   ```

🔹 Don’t forget to add a `main()` function to test like below:

```cpp
int main() {
    Solution sol;
    int n = 10;

    cout << "Using Division: " << sol.usingDivision(n) << endl;
    cout << "Using Recursion: " << sol.decToBinary1(n) << endl;
    cout << "Using Binary Ops: " << sol.usingBinaryOps(n) << endl;
    cout << "Using Bitset: " << sol.decToBinary(n) << endl;

    return 0;
}
```

---
