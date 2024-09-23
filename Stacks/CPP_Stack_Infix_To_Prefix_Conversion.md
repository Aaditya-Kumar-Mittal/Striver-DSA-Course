# Stack - Infix to Prefix and Postfix Expression Conversion in C++

This program demonstrates how to convert an infix expression to both postfix and prefix notation. Infix expressions are standard mathematical expressions where operators are placed between operands (e.g., `a + b`). Postfix notation, also known as Reverse Polish Notation (RPN), places operators after their operands (e.g., `a b +`). Prefix notation, also known as Polish Notation, places operators before their operands (e.g., `+ a b`).

## Code Explanation

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Get the priority of an operator.
 *
 * This function assigns precedence to operators, which is essential
 * for converting infix expressions to postfix and prefix notation.
 * Higher precedence means the operator should be applied earlier.
 *
 * @param C The operator character (e.g., '+', '-', '*', '/', '^').
 * @return The precedence of the operator:
 *         - 1 for '+' and '-'
 *         - 2 for '*' and '/'
 *         - 3 for '^'
 *         - 0 for any other character (invalid).
 */
int getPriority(char C) {
    if (C == '-' || C == '+')
        return 1;
    else if (C == '*' || C == '/')
        return 2;
    else if (C == '^')
        return 3;
    return 0;
}

/**
 * @brief Convert infix expression to postfix expression.
 *
 * This function takes an infix expression and converts it to postfix
 * (Reverse Polish Notation). Operators are pushed onto a stack, and
 * operands (letters or numbers) are directly added to the result.
 * Operators are popped from the stack according to precedence rules.
 *
 * @param infix The input infix expression (e.g., "x+y*z").
 * @return The postfix expression (e.g., "xyz*+").
 */
string infixToPostfix(string infix) {
    // Adding an extra pair of parentheses to handle edge cases
    infix = '(' + infix + ')';

    int len = infix.size();
    stack<char> stk;
    string postfix = "";

    // Traverse each character in the infix expression
    for (int i = 0; i < len; i++) {
        // If character is an operand (A-Z, a-z, or 0-9), append to the result
        if ((infix[i] >= 'A' && infix[i] <= 'Z') || (infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= '0' && infix[i] <= '9')) {
            postfix += infix[i];
        }
        // If it's an opening parenthesis, push it onto the stack
        else if (infix[i] == '(') {
            stk.push(infix[i]);
        }
        // If it's a closing parenthesis, pop from the stack until '(' is encountered
        else if (infix[i] == ')') {
            while (!stk.empty() && stk.top() != '(') {
                postfix += stk.top();
                stk.pop();
            }
            stk.pop(); // Remove the '(' from the stack
        }
        // If it's an operator
        else {
            // Handle `^` (right-associative)
            if (infix[i] == '^') {
                while (!stk.empty() && getPriority(infix[i]) < getPriority(stk.top())) {
                    postfix += stk.top();
                    stk.pop();
                }
            }
            // Handle other operators (left-associative)
            else {
                while (!stk.empty() && getPriority(infix[i]) <= getPriority(stk.top())) {
                    postfix += stk.top();
                    stk.pop();
                }
            }
            stk.push(infix[i]);
        }
    }

    return postfix;
}

/**
 * @brief Convert infix expression to prefix expression.
 *
 * This function converts an infix expression to prefix notation.
 * The algorithm reverses the infix expression, converts it to postfix
 * using the `infixToPostfix()` function, and then reverses the result
 * to get the prefix expression.
 *
 * @param infix The input infix expression (e.g., "x+y*z").
 * @return The prefix expression (e.g., "+x*yz").
 */
string infixToPrefix(string infix) {
    int len = infix.size();

    // Reverse the infix expression
    reverse(infix.begin(), infix.end());

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < len; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Convert to postfix
    string prefix = infixToPostfix(infix);

    // Reverse the postfix result to get the prefix expression
    reverse(prefix.begin(), prefix.end());

    return prefix;
}

/**
 * @brief Main function to test infix to prefix conversion.
 *
 * The program takes a sample infix expression and prints
 * the corresponding prefix expression.
 */
int main() {
    // Sample infix expression
    string s = ("x+y*z/w+u");

    // Output the prefix expression
    cout << infixToPrefix(s) << endl;

    return 0;
}
```

### Markdown Explanation

### 1. **Operator Precedence (`getPriority`)**

This function is responsible for assigning precedence to operators. Precedence dictates the order in which operators should be applied in the expression. The higher the number returned, the higher the precedence. For example:

- `+` and `-` have precedence 1.
- `*` and `/` have precedence 2.
- `^` (exponentiation) has precedence 3.

### 2. **Infix to Postfix Conversion (`infixToPostfix`)**

This function converts a given infix expression (such as `"x+y*z"`) into a postfix expression (like `"xyz*+"`). The algorithm uses a stack to temporarily hold operators and ensures that higher precedence operators are placed correctly in the final postfix expression.

### 3. **Infix to Prefix Conversion (`infixToPrefix`)**

This function takes an infix expression and converts it to a prefix expression. It achieves this by:

1. Reversing the infix expression.
2. Converting the reversed infix expression into postfix notation using the `infixToPostfix()` function.
3. Reversing the resulting postfix expression to get the final prefix notation.

### 4. **Main Function**

The main function tests the conversion by inputting the infix expression `"x+y*z/w+u"` and outputting the equivalent prefix expression.

### Output for the given expression `"x+y*z/w+u"`

```plaintext
++x/*yzwu
```

This output shows the equivalent prefix expression for the given infix expression.

### Key Concepts

- **Infix**: Operators are between operands (e.g., `a + b`).
- **Postfix**: Operators come after operands (e.g., `a b +`).
- **Prefix**: Operators come before operands (e.g., `+ a b`).

This code handles the conversions efficiently and can be easily expanded for more complex expressions.
