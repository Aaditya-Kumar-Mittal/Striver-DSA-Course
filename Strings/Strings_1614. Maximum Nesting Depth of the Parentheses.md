# Maximum Nesting Depth of Parentheses

## Table of Contents

- [Maximum Nesting Depth of Parentheses](#maximum-nesting-depth-of-parentheses)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [1️⃣ Open Bracket Count Solution (Optimized)](#1️⃣-open-bracket-count-solution-optimized)
    - [2️⃣ Stack-Based Solution](#2️⃣-stack-based-solution)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [1️⃣ Open Bracket Count Solution (Optimized Approach - O(n))](#1️⃣-open-bracket-count-solution-optimized-approach---on)
    - [2️⃣ Stack-Based Solution (Alternative Approach - O(n))](#2️⃣-stack-based-solution-alternative-approach---on)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Summary](#summary)

---

## Introduction

The nesting depth of a valid parentheses string (VPS) is the maximum number of open parentheses encountered at any point in the expression.

Given a valid parentheses string `s`, we need to return the maximum depth of nested parentheses.

---

## Problem Description

### Examples

#### Example 1

🔹 Input: `s = "(1+(2*3)+((8)/4))+1"`  
🔹 Output: `3`  
🔹 Explanation: The digit `8` is inside 3 nested parentheses.

#### Example 2

🔹 Input: `s = "(1)+((2))+(((3)))"`  
🔹 Output: `3`  
🔹 Explanation: The digit `3` is inside 3 nested parentheses.

#### Example 3

🔹 Input: `s = "()(())((()()))"`  
🔹 Output: `3`  
🔹 Explanation: The deepest nesting level is `3`.

---

## Constraints

- `1 <= s.length <= 100`
- `s` consists of digits (0-9) and characters '+', '-', '\*', '/', '(', and ')'.
- `s` is guaranteed to be a valid parentheses string (VPS).

---

## Approach

We will discuss two approaches:

1. Open Bracket Count Method (Efficient O(n) Solution)
2. Stack-Based Method (Less Efficient but Intuitive O(n) Solution)

### 1️⃣ Open Bracket Count Solution (Optimized)

✅ Maintain a variable `openBrackets` to track the current depth.  
✅ Increase count when encountering `'('`.  
✅ Decrease count when encountering `')'`.  
✅ Track the maximum count throughout the iteration.

### 2️⃣ Stack-Based Solution

✅ Use a stack to simulate opening and closing brackets.  
✅ Push '(' onto the stack and pop ')' when encountered.  
✅ The maximum stack size at any point is the nesting depth.

---

## Detailed Explanation of Code

### 1️⃣ Open Bracket Count Solution (Optimized Approach - O(n))

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int openBrackets = 0;  // Tracks currently open '('
        int maxDepth = 0;  // Stores the maximum nesting depth

        for (char ch : s) {
            if (ch == '(') {
                openBrackets++;  // Increase depth when '(' is found
                maxDepth = max(maxDepth, openBrackets);  // Update maximum depth
            } else if (ch == ')') {
                openBrackets--;  // Decrease depth when ')' is found
            }
        }
        return maxDepth;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.maxDepth("(1+(2*3)+((8)/4))+1") << endl;  // Output: 3
    cout << sol.maxDepth("(1)+((2))+(((3)))") << endl;    // Output: 3
    cout << sol.maxDepth("()(())((()()))") << endl;       // Output: 3
    return 0;
}
```

---

### 2️⃣ Stack-Based Solution (Alternative Approach - O(n))

```cpp
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        stack<char> stk;  // Stack to keep track of '('
        int maxDepth = 0;  // Stores the maximum nesting depth

        for (char ch : s) {
            if (ch == '(') {
                stk.push(ch);  // Push '(' onto the stack
                maxDepth = max(maxDepth, (int)stk.size());  // Update max depth
            } else if (ch == ')') {
                stk.pop();  // Pop stack when ')' is encountered
            }
        }
        return maxDepth;
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.maxDepth("(1+(2*3)+((8)/4))+1") << endl;  // Output: 3
    cout << sol.maxDepth("(1)+((2))+(((3)))") << endl;    // Output: 3
    cout << sol.maxDepth("()(())((()()))") << endl;       // Output: 3
    return 0;
}
```

---

## Complexity Analysis

| Approach           | Time Complexity | Space Complexity | Explanation                                   |
| ------------------ | --------------- | ---------------- | --------------------------------------------- |
| Open Bracket Count | `O(n)`          | `O(1)`           | Only uses integer variables, no extra memory. |
| Stack-Based        | `O(n)`          | `O(n)`           | Uses a stack to store open parentheses.       |

Best Approach? ✅ Open Bracket Count is faster and more space-efficient than using a stack.

---

## How to Run the Code

### For C++

1️⃣ Compile the code:

```bash
g++ -o max_nesting_depth max_nesting_depth.cpp
```

2️⃣ Run the executable:

```bash
./max_nesting_depth
```

---

## Summary

| Approach           | Method                 | Time Complexity | Space Complexity | Best For                             |
| ------------------ | ---------------------- | --------------- | ---------------- | ------------------------------------ |
| Open Bracket Count | Using integer variable | `O(n)`          | `O(1)`           | Fastest & Most Efficient ✅          |
| Stack-Based        | Using stack            | `O(n)`          | `O(n)`           | Good for understanding depth concept |
