# Stack - Postfix to Prefix Conversion

This document provides a detailed overview of a C++ program that converts postfix expressions to prefix expressions using a stack-based approach.

## Code Overview

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    Function to check if a character is an operand (A-Z, a-z, 0-9).
    Operands are characters or digits that will be pushed onto the stack.
    Returns true if the character is an operand, false otherwise.
*/
bool isOperand(char ch) {
    // Check if the character is within the ranges of uppercase letters,
    // lowercase letters, or digits.
    if (
        (ch >= 'A' && ch <= 'Z') || // Uppercase letters
        (ch >= 'a' && ch <= 'z') || // Lowercase letters
        (ch >= '0' && ch <= '9')    // Digits
    )
        return true; // Character is an operand
    return false; // Character is not an operand
}

/*
    Function to convert a postfix expression to prefix.

    The approach is to use a stack to process each character of the postfix expression.
    If the character is an operand, it is pushed onto the stack.
    If the character is an operator, the top two operands are popped from the stack,
    and a prefix expression is formed by concatenating the operator before the two operands.
    This newly formed prefix expression is then pushed back onto the stack.

    Parameters:
    - string &s: The postfix expression input.

    Returns:
    - string: The equivalent prefix expression.
*/
string postfixToPrefix(string &s) {
    int len = s.size(); // Length of the postfix expression
    int i = 0; // Index to traverse the postfix expression
    stack<string> st; // Stack to hold operands and intermediate results

    // Iterate through each character in the postfix expression
    while (i < len) {
        // If the character is an operand, push it to the stack as a string
        if (isOperand(s[i])) {
            st.push(string(1, s[i])); // Convert char to string and push
        }
        // If the character is an operator
        else {
            // Pop the top two operands from the stack
            string t1 = st.top(); // Get the first operand
            st.pop(); // Remove the first operand from the stack
            string t2 = st.top(); // Get the second operand
            st.pop(); // Remove the second operand from the stack

            // Form the prefix expression: operator followed by operands
            st.push(s[i] + t2 + t1); // Push the new prefix expression onto the stack
        }
        i++; // Move to the next character in the postfix expression
    }

    // The final result is the only element left in the stack
    return st.top();
}

/****************************************************************
    Problem Name: Postfix to Prefix Conversion
    Time Complexity:
    - O(n), where n is the length of the postfix expression.
      The function processes each character of the postfix expression
      exactly once, and each operation (push or pop) on the stack takes O(1) time.

    Space Complexity:
    - O(n), where n is the length of the postfix expression.
      In the worst case, the stack can hold all operands, requiring O(n) space.
      Additionally, the result string is also stored, which is proportional to the length of the input.

    Explanation:
    1. **Postfix and Prefix**:
       - Postfix expressions have operators following the operands,
         whereas in prefix expressions, operators precede their operands.
       - This function converts a postfix expression like "ABC+*" to its
         equivalent prefix form "*A+BC".

    2. **Stack-Based Approach**:
       - The stack is used to store operands. When an operator is encountered,
         two operands are popped, and a new prefix string is formed by
         placing the operator before the operands. This new prefix string
         is pushed back onto the stack.

    3. **Edge Cases**:
       - Proper handling of invalid or empty postfix expressions can be
         added based on constraints provided in the problem.
*****************************************************************/

int main() {
    // Number of test cases
    int t;
    cin >> t;

    // Loop over each test case
    while (t--) {
        string postfix; // Variable to hold the postfix expression
        cin >> postfix; // Input the postfix expression

        // Convert postfix to prefix
        string prefix = postfixToPrefix(postfix);

        // Output the prefix expression
        cout << prefix << endl;
    }

    return 0;
}
```

## Functionality

The provided code implements a simple program that reads a postfix expression, converts it into a prefix expression using a stack, and then outputs the result.

### Key Components

- **isOperand Function**: Determines if a character is an operand (either a letter or a digit).
- **postfixToPrefix Function**: Converts a given postfix expression to its prefix form using a stack-based approach.
- **main Function**: Handles input and output, allowing the user to test multiple postfix expressions.

### Complexity Analysis

- **Time Complexity**: The algorithm runs in O(n) time, where n is the length of the input postfix expression, as each character is processed once.
- **Space Complexity**: The space complexity is also O(n), as the stack may need to hold all operands.

### Usage

To use the program, compile and run it. Enter the number of test cases followed by the postfix expressions you want to convert. The program will output the corresponding prefix expressions.

## Conclusion

This program effectively demonstrates the conversion from postfix to prefix notation, highlighting the utility of stacks in expression evaluation and transformation. It can be further improved by adding error handling for invalid expressions.
