#include <bits/stdc++.h>
using namespace std;

/*
    Function to check if a character is an operand (A-Z, a-z, 0-9).
    Operands are characters or digits that will be pushed onto the stack.
    Returns true if the character is an operand, false otherwise.
*/
bool isOperand(char ch)
{
  if (
      (ch >= 'A' && ch <= 'Z') ||
      (ch >= 'a' && ch <= 'z') ||
      (ch >= '0' && ch <= '9'))
    return true;
  return false;
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
string postfixToPrefix(string &s)
{
  int len = s.size(); // Length of the postfix expression
  int i = 0;          // Index to traverse the postfix expression
  stack<string> st;   // Stack to hold operands and intermediate results

  while (i < len)
  {
    // If the character is an operand, push it to the stack as a string
    if (isOperand(s[i]))
    {
      st.push(string(1, s[i]));
    }
    // If the character is an operator, pop two elements and form the prefix expression
    else
    {
      string t1 = st.top(); // Get the first operand
      st.pop();
      string t2 = st.top(); // Get the second operand
      st.pop();
      // Push the prefix expression formed by concatenating operator with two operands
      st.push(s[i] + t2 + t1);
    }
    i++; // Move to the next character in the postfix expression
  }

  return st.top(); // The final result is the only element left in the stack
}

/****************************************************************

Problem Name: Postfix to Prefix Conversion

Time Complexity:
- O(n), where n is the length of the postfix expression.
  The function processes each character of the postfix expression exactly once,
  and each operation (push or pop) on the stack takes O(1) time.

Space Complexity:
- O(n), where n is the length of the postfix expression.
  In the worst case, the stack can hold all operands, requiring O(n) space.
  Additionally, the result string is also stored, which is proportional to the length of the input.

Explanation:
1. **Postfix and Prefix**:
   - Postfix expressions have operators following the operands, whereas in prefix expressions, operators precede their operands.
   - This function converts a postfix expression like "ABC+*" to its equivalent prefix form "*A+BC".

2. **Stack-Based Approach**:
   - The stack is used to store operands. When an operator is encountered, two operands are popped, and a new prefix string is formed by placing the operator before the operands. This new prefix string is pushed back onto the stack.

3. **Edge Cases**:
   - Proper handling of invalid or empty postfix expressions can be added based on constraints provided in the problem.

*****************************************************************/

int main()
{
  // Number of test cases
  int t;
  cin >> t;

  // Loop over each test case
  while (t--)
  {
    string postfix;
    cin >> postfix;

    // Convert postfix to prefix
    string prefix = postfixToPrefix(postfix);

    // Output the prefix expression
    cout << prefix << endl;
  }

  return 0;
}

/*

Problem Name: Postfix to Prefix Conversion

Time Complexity:
- O(n), where n is the length of the postfix expression.
  The function processes each character of the postfix expression exactly once,
  and each operation (push or pop) on the stack takes O(1) time.

Space Complexity:
- O(n), where n is the length of the postfix expression.
  In the worst case, the stack can hold all operands, requiring O(n) space.
  Additionally, the result string is also stored, which is proportional to the length of the input.

Explanation:
1. **Postfix and Prefix**:
   - Postfix expressions have operators following the operands, whereas in prefix expressions, operators precede their operands.
   - This function converts a postfix expression like "ABC+*" to its equivalent prefix form "*A+BC".

2. **Stack-Based Approach**:
   - The stack is used to store operands. When an operator is encountered, two operands are popped, and a new prefix string is formed by placing the operator before the operands. This new prefix string is pushed back onto the stack.

3. **Edge Cases**:
   - Proper handling of invalid or empty postfix expressions can be added based on constraints provided in the problem.

*/