# Stack - Convert Infix Expression to Postfix

## Problem Statement

Given an infix expression, write a function that converts it to a postfix expression. The infix expression contains:

- Operands (A-Z, a-z, 0-9)
- Operators (`+`, `-`, `*`, `/`, `^`)
- Parentheses for grouping (`()`)

In postfix expressions (also known as Reverse Polish notation), the operator comes after the operands, which eliminates the need for parentheses and makes it easier to evaluate expressions in computer science.

**Example:**

- Infix: `(A+B)*(C-D)`
- Postfix: `AB+CD-*`

---

### C++ Code

```cpp
//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    /**
     * @brief This function converts an infix expression to a postfix expression.
     *
     * @param s The input string representing an infix expression
     *
     * @return The converted postfix expression as a string
     *
     * ### Approach:
     * 1. Use a stack to store operators and handle precedence.
     * 2. Traverse the input infix expression:
     *    - If an operand (A-Z, a-z, 0-9) is encountered, append it to the result.
     *    - If an opening parenthesis is encountered, push it onto the stack.
     *    - If a closing parenthesis is encountered, pop from the stack until an opening parenthesis is found.
     *    - If an operator is encountered, pop from the stack while the top of the stack has higher or equal precedence, then push the operator onto the stack.
     * 3. After processing the input string, pop all remaining operators from the stack and append them to the result.
     */
    string infixToPostfix(string s) {
        // String to store the result (postfix expression)
        string ans = "";

        // Stack to store operators
        stack<char> stk;

        // Traverse the infix expression
        for (int i = 0; i < s.size(); i++) {
            // If the character is an operand, add it to the result
            if ((s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9')) {
                ans += s[i];
            }
            // If the character is an opening parenthesis, push it to the stack
            else if (s[i] == '(') {
                stk.push(s[i]);
            }
            // If the character is a closing parenthesis, pop and output from the stack
            // until an opening parenthesis is encountered
            else if (s[i] == ')') {
                while (!stk.empty() && stk.top() != '(') {
                    ans += stk.top();
                    stk.pop();
                }
                // Pop the opening parenthesis '('
                if (!stk.empty()) {
                    stk.pop();
                }
            }
            // If the character is an operator
            else {
                // Pop operators from the stack with higher or equal precedence
                while (!stk.empty() && priority(s[i]) <= priority(stk.top())) {
                    ans += stk.top();
                    stk.pop();
                }
                // Push the current operator to the stack
                stk.push(s[i]);
            }
        }

        // Pop all the remaining operators from the stack
        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        // Return the final postfix expression
        return ans;
    }

    /**
     * @brief Function to define operator precedence.
     *
     * @param ch The operator character
     * @return The precedence value of the operator:
     *         - '^' has the highest precedence (3)
     *         - '*' and '/' have medium precedence (2)
     *         - '+' and '-' have the lowest precedence (1)
     */
    int priority(char ch) {
        if (ch == '^') {
            return 3;  // Exponent has the highest precedence
        } else if (ch == '*' || ch == '/') {
            return 2;  // Multiplication and Division have medium precedence
        } else if (ch == '+' || ch == '-') {
            return 1;  // Addition and Subtraction have the lowest precedence
        } else {
            return -1; // Invalid character
        }
    }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}
// } Driver Code Ends
```

---

### Explanation

1. **String to Store Result (`ans`)**:

   - This will hold the final postfix expression.

2. **Stack for Operators (`stk`)**:

   - This stack will temporarily store operators and parentheses while processing the infix expression. The stack helps ensure correct order of operators based on their precedence.

3. **Traversing the Expression**:

   - We iterate through each character of the infix expression. Based on whether the character is an operand, an opening/closing parenthesis, or an operator, we handle it accordingly.

4. **Handling Operands**:

   - If the current character is an operand (either an alphabet or a digit), it is directly appended to the result string `ans`.

5. **Handling Parentheses**:

   - If the current character is an opening parenthesis `(`, it is pushed onto the stack.
   - If it is a closing parenthesis `)`, we pop from the stack and append to the result string until we find an opening parenthesis `(`.

6. **Handling Operators**:

   - For an operator, we pop all operators from the stack that have **equal or higher precedence** and append them to the result string. Afterward, the current operator is pushed onto the stack.

7. **Emptying the Stack**:

   - After traversing the entire infix expression, we pop all remaining operators from the stack and append them to the result string.

8. **Operator Precedence Function (`priority`)**:
   - This helper function returns the precedence level of an operator. Exponentiation (`^`) has the highest precedence, followed by multiplication (`*`) and division (`/`), and addition (`+`) and subtraction (`-`) have the lowest precedence.

---

### Example

#### Input

```cpp
(A+B)*(C-D)
```

#### Output

```plaintext
AB+CD-*
```

**Explanation**:

- First, we process `(A+B)` and convert it to `AB+`.
- Then, we process `(C-D)` and convert it to `CD-`.
- Finally, the multiplication operator `*` is added after the operands, resulting in `AB+CD-*`.

---

### Time and Space Complexity

- **Time Complexity**: O(n), where `n` is the length of the input expression. Each character is processed once.
- **Space Complexity**: O(n), where `n` is the size of the stack used for storing operators.
