//{ Driver Code Starts
// Initial Template for C++

/*
    This code converts a postfix expression into an infix expression.
    Postfix expressions are those in which the operator appears after the operands.
    For example, the postfix expression "ABC+*" corresponds to the infix expression "(A * (B + C))".
    Infix expressions are those where operators are between operands, such as "(A + B)".

    The approach uses a stack to handle this conversion.
    If a character is an operand (letter or digit), we push it onto the stack.
    When an operator is encountered, the top two operands are popped, and an infix expression
    is formed by enclosing them with parentheses and inserting the operator between them.
    This infix expression is then pushed back onto the stack.
*/

// Including all standard libraries needed
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
  // Function to check if a character is an operand (A-Z, a-z, 0-9)
  bool isOperand(char ch)
  {
    // Check if the character is an alphabet or a digit
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
  }

  /*
  Function to convert postfix expression to infix expression.
  The idea is to traverse the postfix expression from left to right.
  If the current character is an operand, push it to the stack.
  If the current character is an operator, pop two elements from the stack,
  form a new string with those two elements and the operator in between,
  and push the new string back to the stack.

  Steps:
  1. Initialize a stack to store operands and intermediate infix expressions.
  2. For each character in the postfix expression:
     a. If the character is an operand, push it onto the stack.
     b. If the character is an operator:
        - Pop the top two elements from the stack.
        - Form an infix expression with these two elements and the operator between them.
        - Push the new infix expression back onto the stack.
  3. The final infix expression is the only element left in the stack.
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

//{ Driver Code Starts.

// Driver function to test the solution
int main()
{
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
// } Driver Code Ends

/****************************************************************

Problem Name: Postfix to Infix Conversion

Time Complexity:
- O(n), where n is the length of the postfix expression.
  The function processes each character in the postfix string exactly once,
  and each operation (push or pop) on the stack takes O(1) time.

Space Complexity:
- O(n), where n is the length of the postfix expression.
  In the worst case, the stack can hold all operands, requiring O(n) space.
  Additionally, the result string is also stored, which is proportional to the length of the input.

Explanation:
1. **Postfix and Infix**:
   - Postfix expressions (e.g., `ABC+*`) represent operations in which the operator follows the operands.
   - Infix expressions (e.g., `(A * (B + C))`) represent operations in which operators are placed between operands.

2. **Stack Approach**:
   - The stack is used to temporarily store operands (letters or digits). When an operator is encountered, the top two operands are popped, and an infix expression is formed by placing the operator between them. This expression is then pushed back to the stack.

3. **Edge Cases**:
   - If the input string contains only one operand, it remains as the infix expression.
   - Proper error handling for invalid postfix expressions (e.g., missing operands) is assumed to be handled by valid input as per the problem's constraints.

*****************************************************************/
