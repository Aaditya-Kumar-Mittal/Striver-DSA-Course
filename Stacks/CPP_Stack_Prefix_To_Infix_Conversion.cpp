//{ Driver Code Starts
// Initial Template for C++

/*
This code converts a prefix expression into an infix expression.
Prefix expressions are those in which the operator appears before the operands.
For example, the prefix expression "-+ABC" corresponds to the infix expression "(A + B) - C".
Infix expressions are those where operators are between operands, such as "(A + B)".

The approach uses a stack to handle this conversion.
If a character is an operand (letter or digit), we push it onto the stack.
When an operator is encountered, the top two operands are popped, and an infix expression is formed by enclosing them with parentheses and inserting the operator between them.
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
    // Check if character is an alphabet or a digit
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
    {
      return true;
    }
    return false;
  }

  /*
  Function to convert prefix expression to infix expression.
  The idea is to traverse the prefix expression from right to left.
  If the current character is an operand, push it to the stack.
  If the current character is an operator, pop two elements from the stack,
  form a new string with those two elements and the operator in between,
  and push the new string back to the stack.
  */
  string preToInfix(string pre_exp)
  {

    // Get the length of the prefix expression
    int len = pre_exp.size();

    // Traverse the prefix expression from right to left
    int i = len - 1;

    // Stack to store operands and intermediate infix expressions
    stack<string> infix;

    // Iterate over the prefix expression from right to left
    while (i >= 0)
    {

      // If the character is an operand, push it to the stack
      if (isOperand(pre_exp[i]))
      {
        infix.push(string(1, pre_exp[i])); // Convert char to string and push
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
    // Input: a prefix expression
    string prefix;
    cin >> prefix;

    // Creating an instance of the Solution class
    Solution obj;

    // Output the converted infix expression
    cout << obj.preToInfix(prefix) << endl;
  }

  return 0;
}

// } Driver Code Ends
