# Largest Odd Number in String

## Table of Contents

- [Largest Odd Number in String](#largest-odd-number-in-string)
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
  - [Summary](#summary)

## Introduction

Given a string `num` representing a large integer, the goal is to find the **largest-valued odd integer** that is a **non-empty substring** of `num`. If no odd integer exists, return an **empty string** `""`.

## Problem Description

### Examples

#### Example 1

**Input:**

```cpp
num = "52"
```

**Output:**

```cpp
"5"
```

**Explanation:**

- Possible substrings: `"5"`, `"2"`, and `"52"`.
- The only odd number among them is `"5"`.

#### Example 2

**Input:**

```cpp
num = "4206"
```

**Output:**

```cpp
""
```

**Explanation:**

- No odd digits exist in `"4206"`, so return `""`.

#### Example 3

**Input:**

```cpp
num = "35427"
```

**Output:**

```cpp
"35427"
```

**Explanation:**

- The entire number `"35427"` is already an odd number.

### Constraints

- `1 <= num.length <= 10^5`
- `num` consists only of digits (`0-9`).
- `num` does not contain leading zeros.

## Approach

1. **Traverse the string from the rightmost character to the left**:
   - Since we want the largest-valued odd number, we search for the last odd digit in `num`.
   - If found, return the substring from the start of `num` to that position.
2. **Check each character if it is odd**:

   - A digit is odd if `(digit % 2 == 1)`.
   - If found, return the substring from index `0` to `i+1`.

3. **If no odd digit is found, return an empty string**.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        for (int i = num.length() - 1; i >= 0; i--) { // Traverse from right to left
            int digit = num[i] - '0';  // Convert character to integer
            if (digit % 2 == 1) {      // Check if the digit is odd
                return num.substr(0, i + 1); // Return substring from 0 to i
            }
        }
        return "";  // No odd digit found
    }
};

// Driver Code
int main() {
    Solution solution;
    string num;
    cout << "Enter a number: ";
    cin >> num;
    cout << "Largest Odd Number: " << solution.largestOddNumber(num) << endl;
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(n)`, where `n` is the length of `num`.

  - We traverse the string **once** from right to left, making the solution **linear**.

- **Space Complexity:** `O(1)`.
  - We use only a few integer variables, and **no extra space** is allocated except for the output string.

## How to Run the Code

### For C++

1. **Save the code** in a file, e.g., `largest_odd_number.cpp`.
2. **Compile** the program using:

   ```sh
   g++ -o largest_odd_number largest_odd_number.cpp
   ```

3. **Run** the executable:

   ```sh
   ./largest_odd_number
   ```

4. **Input Example:**

   ```sh
   Enter a number: 35427
   ```

5. **Expected Output:**

   ```sh
   Largest Odd Number: 35427
   ```

## Summary

| Step | Description                                                             |
| ---- | ----------------------------------------------------------------------- |
| 1    | Traverse from the last digit to the first digit.                        |
| 2    | Check if the digit is odd.                                              |
| 3    | If an odd digit is found, return the substring from index `0` to `i+1`. |
| 4    | If no odd digit is found, return an empty string `""`.                  |

This approach ensures an **efficient and optimal** way to find the largest odd number in a string. 🚀
