# String to Integer (atoi)

## Table of Contents

- [String to Integer (atoi)](#string-to-integer-atoi)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Rules](#rules)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Task](#task)
    - [Examples](#examples)
      - [**Example 1:**](#example-1)
      - [**Example 2:**](#example-2)
      - [**Example 3:**](#example-3)
      - [**Example 4:**](#example-4)
      - [**Example 5:**](#example-5)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Explanation](#explanation)
  - [Complexity Analysis](#complexity-analysis)
    - [**Time Complexity:**](#time-complexity)
    - [**Space Complexity:**](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [**For C++:**](#for-c)
  - [Summary](#summary)

---

## Introduction

The **`myAtoi(string s)`** function converts a given string into a 32-bit signed integer (`int`). The function follows specific rules for parsing, handling signs, and managing out-of-range values.

### Rules

1. **Ignore leading whitespaces**.
2. **Determine the sign** (`+` or `-`).
3. **Read digits until a non-digit character is encountered** or the string ends.
4. **Clamp values that exceed 32-bit integer range**:
   - If value exceeds `2^31 - 1` (`2147483647`), return `2147483647`.
   - If value is less than `-2^31` (`-2147483648`), return `-2147483648`.

---

## Problem Description

### Given

A string `s` containing:

- English letters (uppercase and lowercase)
- Digits (0-9)
- Spaces (`' '`)
- Signs (`'+'`, `'-'`)
- Decimal points (`'.'`)

### Task

Return the integer representation of `s`, following the parsing rules.

### Examples

#### **Example 1:**

```bash
Input:  s = "42"
Output: 42
Explanation:
- No leading whitespace
- No sign, assume positive
- "42" is parsed as integer
```

#### **Example 2:**

```bash
Input:  s = "   -042"
Output: -42
Explanation:
- Ignore leading whitespace
- Sign is '-'
- Read digits "042", ignoring leading zero
```

#### **Example 3:**

```bash
Input:  s = "1337c0d3"
Output: 1337
Explanation:
- Read "1337", stop at first non-digit ('c')
```

#### **Example 4:**

```bash
Input:  s = "0-1"
Output: 0
Explanation:
- Read "0", stop at '-'
```

#### **Example 5:**

```bash
Input:  s = "words and 987"
Output: 0
Explanation:
- No valid integer prefix
```

---

### Constraints

- `0 ≤ s.length ≤ 200`
- `s` consists of letters, digits, spaces, `+`, `-`, and `.`.

---

## Approach

To efficiently implement `myAtoi`, we use the following **step-by-step process**:

1. **Skip leading whitespaces**.
2. **Check for sign (`+` or `-`)**:
   - If '-' is found, set `sign = -1`.
   - If '+' is found, set `sign = 1`.
   - Default sign is `1`.
3. **Read digits until a non-digit is encountered**:
   - Convert digits into an integer.
   - Stop if the character is non-numeric.
4. **Clamp the result**:
   - If number exceeds `INT_MAX (2147483647)`, return `2147483647`.
   - If number is below `INT_MIN (-2147483648)`, return `-2147483648`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <climits> // For INT_MAX and INT_MIN
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0)
            return 0;

        int i = 0;

        // 1. Ignore leading whitespaces
        while (i < s.length() && s[i] == ' ')
            i++;

        // 2. Check for sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            i++;
        }

        // 3. Read and convert digits
        long ans = 0;
        while (i < s.length() && isdigit(s[i])) {
            ans = ans * 10 + (s[i] - '0');

            // 4. Clamp to 32-bit integer range
            if (sign == -1 && (-1 * ans) < INT_MIN)
                return INT_MIN;
            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;

            i++;
        }

        return (int)(ans * sign);
    }
};

// Driver Code
int main() {
    Solution solution;
    string input;

    cout << "Enter string: ";
    getline(cin, input);

    cout << "Converted Integer: " << solution.myAtoi(input) << endl;
    return 0;
}
```

---

### Explanation

1. **Skip Whitespaces**:

   - Move `i` forward until we find a non-space character.

2. **Check for Sign (`+` or `-`)**:

   - If `-`, set `sign = -1`.
   - If `+`, set `sign = 1` (default).

3. **Convert Digits to Integer**:

   - Multiply previous result by `10` and add new digit.
   - Stop when encountering a non-digit.

4. **Clamp Values in Range `[-2147483648, 2147483647]`**:
   - If `ans` exceeds `INT_MAX`, return `INT_MAX`.
   - If `ans` goes below `INT_MIN`, return `INT_MIN`.

---

## Complexity Analysis

### **Time Complexity:**

- **O(n)**: We traverse the string once, processing each character.

### **Space Complexity:**

- **O(1)**: We use a few integer variables, requiring constant space.

---

## How to Run the Code

### **For C++:**

1. **Save the code in a file (`atoi.cpp`)**.
2. **Compile the program** using:

   ```bash
   g++ -o atoi atoi.cpp
   ```

3. **Run the executable**:

   ```bash
   ./atoi
   ```

4. **Input Example:**

   ```bash
   Enter string:   -12345
   Converted Integer: -12345
   ```

5. **Expected Output:**

   ```bash
   -12345
   ```

---

## Summary

| Step                     | Description                                                 |
| ------------------------ | ----------------------------------------------------------- |
| 1. Ignore Leading Spaces | Skip all initial spaces.                                    |
| 2. Identify Sign         | Detect '+' or '-' to determine sign.                        |
| 3. Convert Digits        | Read digits and form integer.                               |
| 4. Stop at Non-Digit     | Stop parsing when a non-digit character is encountered.     |
| 5. Handle Overflow       | Clamp to `INT_MAX (2147483647)` or `INT_MIN (-2147483648)`. |
| 6. Return Final Result   | Multiply by sign and return.                                |

---

This documentation provides a clear and structured breakdown of how to efficiently convert a string into an integer (`atoi`) while handling edge cases such as whitespaces, signs, invalid characters, and overflow conditions. 🚀
