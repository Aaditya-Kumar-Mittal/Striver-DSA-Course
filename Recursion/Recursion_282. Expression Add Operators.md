# Expression Add Operators

## Table of Contents

- [Expression Add Operators](#expression-add-operators)
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

## Introduction

The problem requires inserting binary operators (`+`, `-`, and `*`) between the digits of a given numeric string to form valid expressions that evaluate to a given target value. The operands in the generated expressions should not have leading zeros.

## Problem Description

### Examples

#### Example 1

**Input:**

```bash
num = "123", target = 6
```

**Output:**

```bash
["1*2*3", "1+2+3"]
```

**Explanation:**  
Both `1*2*3` and `1+2+3` evaluate to 6.

#### Example 2

**Input:**

```bash
num = "232", target = 8
```

**Output:**

```bash
["2*3+2", "2+3*2"]
```

**Explanation:**  
Both `2*3+2` and `2+3*2` evaluate to 8.

#### Example 3

**Input:**

```bash
num = "3456237490", target = 9191
```

**Output:**

```bash
[]
```

**Explanation:**  
No valid expressions can be formed to achieve the target.

### Constraints

- `1 <= num.length <= 10`
- `num` consists of only digits.
- `-2^31 <= target <= 2^31 - 1`

## Approach

The problem is solved using **Backtracking**:

- We iterate through the string and form numbers from consecutive digits.
- We recursively explore different possible expressions by inserting `+`, `-`, or `*`.
- Multiplication requires careful handling due to precedence.
- Leading zeros are handled by ensuring numbers do not start with zero unless it is a single-digit operand.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> ans;

    void solve(string s, int target, int index, const string& path, long eval, long residual) {
        if (index == s.length()) {
            if (eval == target) {
                ans.push_back(path);
            }
            return;
        }

        string currentString;
        long num = 0;
        for (int j = index; j < s.length(); j++) {
            // Handle leading zeros
            if (j > index && s[index] == '0') {
                break;
            }

            currentString += s[j];
            num = num * 10 + (s[j] - '0');

            if (index == 0) {
                // First number, no operator needed
                solve(s, target, j + 1, path + currentString, num, num);
            } else {
                // Try adding '+'
                solve(s, target, j + 1, path + "+" + currentString, eval + num, num);
                // Try adding '-'
                solve(s, target, j + 1, path + "-" + currentString, eval - num, -num);
                // Try adding '*'
                solve(s, target, j + 1, path + "*" + currentString, eval - residual + residual * num, residual * num);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        if (num.empty()) {
            return ans;
        }
        solve(num, target, 0, "", 0, 0);
        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(3^n)`, where `n` is the length of the `num` string. This is because for each digit, we consider three possibilities (`+`, `-`, `*`).
- **Space Complexity:** `O(n)`, due to the recursive call stack depth.

## How to Run the Code

1. Copy the C++ code into a `.cpp` file.
2. Compile using:

   ```bash
   g++ -std=c++17 filename.cpp -o output
   ```

3. Run the executable:

   ```bash
   ./output
   ```

This program correctly finds all expressions that evaluate to the given target using backtracking.
