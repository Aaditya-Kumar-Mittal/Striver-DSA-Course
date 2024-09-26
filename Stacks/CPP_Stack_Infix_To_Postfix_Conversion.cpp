//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to convert an infix expression to a postfix expression.
  string infixToPostfix(string s)
  {
    // String to store the result (postfix expression)
    string ans = "";

    // Stack to store operators
    stack<char> stk;

    // Traverse the infix expression
    for (int i = 0; i < s.size(); i++)
    {
      // If the character is an operand, add it to the result
      if ((s[i] >= 'A' && s[i] <= 'Z') ||
          (s[i] >= 'a' && s[i] <= 'z') ||
          (s[i] >= '0' && s[i] <= '9'))
      {
        ans += s[i];
      }
      // If the character is an opening parenthesis, push it to the stack
      else if (s[i] == '(')
      {
        stk.push(s[i]);
      }
      // If the character is a closing parenthesis, pop and output from the stack
      // until an opening parenthesis is encountered
      else if (s[i] == ')')
      {
        while (!stk.empty() && stk.top() != '(')
        {
          ans += stk.top();
          stk.pop();
        }
        // Pop the opening parenthesis '('
        if (!stk.empty())
        {
          stk.pop();
        }
      }
      // If the character is an operator
      else
      {
        // Pop operators from the stack with higher or equal precedence
        while (!stk.empty() && priority(s[i]) <= priority(stk.top()))
        {
          ans += stk.top();
          stk.pop();
        }
        // Push the current operator to the stack
        stk.push(s[i]);
      }
    }

    // Pop all the remaining operators from the stack
    while (!stk.empty())
    {
      ans += stk.top();
      stk.pop();
    }

    // Return the final postfix expression
    return ans;
  }

  // Function to define operator precedence
  int priority(char ch)
  {
    if (ch == '^')
    {
      return 3; // Exponent has the highest precedence
    }
    else if (ch == '*' || ch == '/')
    {
      return 2; // Multiplication and Division have the second highest precedence
    }
    else if (ch == '+' || ch == '-')
    {
      return 1; // Addition and Subtraction have the lowest precedence
    }
    else
    {
      return -1; // Invalid character
    }
  }
};

//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
  int t;
  cin >> t;
  cin.ignore(INT_MAX, '\n');
  while (t--)
  {
    string exp;
    cin >> exp;
    Solution ob;
    cout << ob.infixToPostfix(exp) << endl;
  }
  return 0;
}
// } Driver Code Ends
