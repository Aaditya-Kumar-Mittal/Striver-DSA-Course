# Stack - Postfix to Infix Expression Conversion in C++

This program converts a **postfix expression** (also called reverse Polish notation) into an **infix expression** using a stack-based approach.

## Problem Description

A **postfix expression** is a mathematical notation where the operators follow their operands. For example, the postfix expression `"ABC+*"` is equivalent to the infix expression `"(A * (B + C))"`.

This program will take a postfix expression as input and convert it to the equivalent infix expression.

### Example

- **Postfix Expression**: `"ABC+*"`
- **Infix Expression**: `"(A * (B + C))"`

## Approach

### Steps

1. Initialize a stack to store operands and intermediate infix expressions.
2. Traverse the given postfix expression from left to right.
3. For each character:
   - If it is an **operand** (a letter or digit), push it onto the stack.
   - If it is an **operator**, pop two elements from the stack, form a new infix expression, and push it back to the stack.
4. After traversing the entire postfix expression, the only element remaining in the stack will be the final infix expression.

## Code Implementation

```cpp
// Including all standard libraries needed
#include <bits/stdc++.h>
using namespace std;

// Solution class to convert postfix to infix
class Solution {
public:
    // Function to check if a character is an operand (A-Z, a-z, 0-9)
    bool isOperand(char ch)
    {
        // Check if the character is an alphabet or a digit
        return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
    }

    /*
    Function to convert postfix expression to infix expression.
    The algorithm traverses the postfix expression from left to right:
    1. If the character is an operand, push it onto the stack.
    2. If the character is an operator, pop two elements from the stack,
       form a new string by combining them with the operator between,
       and push the result back onto the stack.
    3. After the traversal, the final expression in the stack will be the
       complete infix expression.
    */
    string postfixToInfix(string postfix_exp)
    {
        // Stack to store operands and intermediate infix expressions
        stack<string> infix;

        // Iterate over the postfix expression from left to right
        for (char ch : postfix_exp)
        {
            // If the character is an operand, push it to the stack
            if (isOperand(ch))
            {
                infix.push(string(1, ch)); // Convert char to string and push
            }
            // If the character is an operator
            else
            {
                // Pop the first operand from the stack (right-hand operand)
                string t1 = infix.top();
                infix.pop();

                // Pop the second operand from the stack (left-hand operand)
                string t2 = infix.top();
                infix.pop();

                // Form the infix expression "(t2 operator t1)" and push back to the stack
                string t3 = '(' + t2 + ch + t1 + ')';
                infix.push(t3);
            }
        }

        // The final infix expression is the only element left in the stack
        return infix.top();
    }
};

// Driver function to test the solution
int main() {
    // Number of test cases
    int t = 1;
    cin >> t;

    // While there are test cases
    while (t--)
    {
        // Input: a postfix expression
        string postfix;
        cin >> postfix;

        // Creating an instance of the Solution class
        Solution obj;

        // Output the converted infix expression
        cout << obj.postfixToInfix(postfix) << endl;
    }

    return 0;
}
```

## Explanation

- **isOperand function**: This helper function checks whether a given character is an operand (either a letter or a digit).
- **postfixToInfix function**:
  - **Input**: A postfix expression.
  - **Output**: The corresponding infix expression.
  - The function iterates over each character of the postfix expression. If the character is an operand, it pushes it onto the stack. If it's an operator, it pops two operands from the stack, forms a new infix expression, and pushes it back to the stack. Finally, the last remaining element in the stack is the fully formed infix expression.

## Time Complexity

- **Traversal of Postfix Expression**: The algorithm traverses the postfix expression once, which has a time complexity of `O(n)` where `n` is the length of the postfix expression.
- **Stack Operations**: Each character results in a constant-time push or pop operation on the stack, making the overall time complexity for stack operations `O(n)`.

- **Total Time Complexity**:  
  The total time complexity is `O(n)` since the algorithm processes each character of the postfix expression in constant time.

## Space Complexity

- **Stack Space**: In the worst case, the stack could hold all operands of the postfix expression before encountering operators. The space complexity due to the stack is `O(n)` where `n` is the length of the postfix expression.

- **Auxiliary Space**: The algorithm also uses a constant amount of space for storing temporary variables, making the overall space complexity `O(n)`.

## Test Cases

### Test Case 1

**Input**:

```plaintext
ABC+*
```

**Output**:

```plaintext
(A*(B+C))
```

### Test Case 2

**Input**:

```plaintext
AB+C-
```

**Output**:

```plaintext
((A+B)-C)
```

### Test Case 3

**Input**:

```plaintext
ABCD+-*
```

**Output**:

```plaintext
(A*(B-(C+D)))
```

## Conclusion

This solution effectively converts a postfix expression into an infix expression using a stack. The algorithm is simple yet efficient, with a time and space complexity of `O(n)`, making it suitable for converting postfix expressions of varying lengths.
