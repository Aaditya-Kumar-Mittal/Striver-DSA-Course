# Stack - Prefix to Infix Conversion in C++

This project contains a C++ program to convert a **prefix expression** to an **infix expression**. It utilizes a stack-based approach to manage operands and operators efficiently during the conversion process.

### Table of Contents

- [Stack - Prefix to Infix Conversion in C++](#stack---prefix-to-infix-conversion-in-c)
    - [Table of Contents](#table-of-contents)
    - [Problem Description](#problem-description)
    - [Approach](#approach)
    - [Code Walkthrough](#code-walkthrough)
      - [1. `isOperand(char ch)`](#1-isoperandchar-ch)
      - [2. `preToInfix(string pre_exp)`](#2-pretoinfixstring-pre_exp)
      - [3. `main()`](#3-main)
    - [Dependencies](#dependencies)
    - [How to Run the Code](#how-to-run-the-code)
    - [Example](#example)
      - [Input](#input)
      - [Output](#output)
    - [Analysis](#analysis)
      - [Time Complexity](#time-complexity)
      - [Space Complexity](#space-complexity)
    - [Conclusion](#conclusion)
    - [Future Enhancements](#future-enhancements)

### Problem Description

Prefix expressions are mathematical expressions where the operator precedes its operands. In contrast, infix expressions have operators between their operands. For example:

- **Prefix Expression**: `*+AB-CD`
- **Infix Expression**: `((A+B)*(C-D))`

The objective of this project is to convert a given prefix expression into its corresponding infix expression using a **stack**.

---

### Approach

The conversion from prefix to infix involves the following steps:

1. **Traverse the Prefix Expression from Right to Left**:

   - **If an operand** (A-Z, a-z, or 0-9) is encountered, push it onto the stack.
   - **If an operator** is encountered:
     - Pop two operands from the stack.
     - Combine these operands with the operator into an infix expression enclosed in parentheses.
     - Push the resulting infix expression back onto the stack.

2. **Final Expression**:
   - Once the entire prefix expression is processed, the final infix expression will be the only element left in the stack.

---

### Code Walkthrough

The main program consists of the following key components:

#### 1. `isOperand(char ch)`

This helper function checks whether the given character `ch` is an operand (either a letter or a number). If the character is within the ranges `'A'`-`'Z'`, `'a'`-`'z'`, or `'0'`-`'9'`, it is considered an operand.

```cpp
/*
Function to check if a character is an operand (A-Z, a-z, 0-9)
@param ch The character to check
@return true if the character is an operand, false otherwise
*/
bool isOperand(char ch) {
    // Check if the character is an alphabet or a digit
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return true;
    }
    return false;
}
```

#### 2. `preToInfix(string pre_exp)`

This function converts a given prefix expression into an infix expression. The conversion is achieved by using a stack to handle operands and forming infix expressions when operators are encountered.

```cpp
/*
Function to convert a prefix expression to infix expression.
@param pre_exp The prefix expression as a string
@return The resulting infix expression as a string
*/
string preToInfix(string pre_exp) {
    // Get the length of the prefix expression
    int len = pre_exp.size();

    // Stack to store operands and intermediate infix expressions
    stack<string> infix;

    // Traverse the prefix expression from right to left
    int i = len - 1;
    while (i >= 0) {
        // If the character is an operand, push it to the stack
        if (isOperand(pre_exp[i])) {
            infix.push(string(1, pre_exp[i]));  // Convert char to string and push
        } else {
            // Pop two operands from the stack
            string t1 = infix.top();
            infix.pop();
            string t2 = infix.top();
            infix.pop();

            // Form the infix expression "(t1 operator t2)" and push back to the stack
            string t3 = '(' + t1 + pre_exp[i] + t2 + ')';
            infix.push(t3);
        }
        // Move to the previous character
        i--;
    }

    // The final infix expression is the only element left in the stack
    return infix.top();
}
```

#### 3. `main()`

The driver function to take user input for the number of test cases and the prefix expression for each test case. It then calls the `preToInfix` function and outputs the corresponding infix expression.

```cpp
/*
Main function to test the prefix to infix conversion.
*/
int main() {
    // Number of test cases
    int t = 1;
    cin >> t;

    // Process each test case
    while (t--) {
        // Input: prefix expression
        string prefix;
        cin >> prefix;

        // Create an instance of the Solution class
        Solution obj;

        // Output the converted infix expression
        cout << obj.preToInfix(prefix) << endl;
    }
    return 0;
}
```

---

### Dependencies

The code is written in **C++** and uses the standard library components:

- `iostream` for input/output.
- `stack` for managing operands during the conversion process.
- `string` for handling character manipulation and infix expressions.

Ensure that the C++ development environment is set up with any standard compiler such as GCC or Clang.

---

### How to Run the Code

1. Clone this repository or download the C++ file.
2. Compile the program using any C++ compiler. For example, if you're using `g++`:

   ```bash
   g++ -o pre_to_infix pre_to_infix.cpp
   ```

3. Run the executable:

   ```bash
   ./pre_to_infix
   ```

4. Provide the required input. First, input the number of test cases, followed by the prefix expressions for each test case.

Example:

```plaintext
Input:
1
*+AB-CD

Output:
((A+B)*(C-D))
```

---

### Example

Here’s a sample test case with input and output:

#### Input

```text
1
*+AB-CD
```

#### Output

```text
((A+B)*(C-D))
```

**Explanation**:

- Prefix: `*+AB-CD`
- Infix: `((A+B)*(C-D))`

Steps:

1. Start from the right of the prefix expression.
2. Encounter `D` and `C` (operands), push them onto the stack.
3. Encounter `-` (operator), pop `D` and `C`, form the expression `(C-D)`, and push it back onto the stack.
4. Continue this process until the entire expression is processed.

Here's an **Analysis section** that includes both **time complexity** and **space complexity** for the provided C++ code.

---

### Analysis

#### Time Complexity

The time complexity of the program depends on the number of characters in the input prefix expression. Let's denote the length of the prefix expression as **`n`**.

1. **Traversal of the prefix string**:

   - The program iterates over the entire prefix expression from right to left. This involves a single loop that processes each character exactly once.
   - Time Complexity for this traversal is **O(n)**, where `n` is the length of the prefix expression.

2. **Operations on the stack**:
   - For each character in the prefix expression:
     - If it's an operand, it is pushed onto the stack (O(1)).
     - If it's an operator, two elements are popped from the stack, an infix string is formed, and the result is pushed back (each of these operations takes O(1) time, though string concatenation is amortized O(1) due to stack size being proportional to the expression size).

Thus, the overall time complexity is:

- **O(n)**, where `n` is the number of characters in the prefix expression.

#### Space Complexity

The space complexity is determined by the extra memory used for the stack and the storage of intermediate strings.

1. **Stack Usage**:

   - In the worst case, the stack will hold at most **n/2** operands before any operators are encountered, meaning the space required for the stack is **O(n)**.

2. **Infix String Formation**:
   - The resulting infix expression is constructed using intermediate strings for each operation. In the worst case, the final infix expression will be roughly of size **2n** (due to the added parentheses and operators), but this still scales linearly.

Thus, the overall space complexity is:

- **O(n)**, where `n` is the number of characters in the prefix expression.

---

### Conclusion

- **Time Complexity**: O(n) – Linear, where `n` is the length of the prefix expression.
- **Space Complexity**: O(n) – Linear, as the stack grows proportional to the size of the expression.

This efficient linear solution handles the conversion of prefix expressions to infix with minimal overhead.

### Future Enhancements

- **Support for More Operators**: Extend support for additional operators (like division `/` and exponentiation `^`).
- **Error Handling**: Implement error handling for invalid expressions (e.g., mismatched operands and operators).
- **Postfix Conversion**: Add functionality to also convert prefix expressions into postfix expressions.
