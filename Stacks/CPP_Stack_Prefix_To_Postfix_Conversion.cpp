#include <bits/stdc++.h>
using namespace std;

/*
    Function to check if a character is an operand (A-Z, a-z, 0-9).
    Operands are characters or digits that will be pushed onto the stack.
    Returns true if the character is an operand, false otherwise.
*/
bool isOperand(char ch)
{
  return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9');
}

/*
    Function to convert a prefix expression to postfix.
    The approach is to use a stack to process each character of the prefix expression.
    If the character is an operand, it is pushed onto the stack.
    If the character is an operator, the top two operands are popped from the stack,
    and a postfix expression is formed by concatenating the two operands followed by the operator.
    This newly formed postfix expression is then pushed back onto the stack.

    Parameters:
    - string &s: The prefix expression input.

    Returns:
    - string: The equivalent postfix expression.
*/
string prefixToPostfix(string &s)
{
  int len = s.size(); // Length of the prefix expression
  int i = len - 1;    // Index to traverse the prefix expression from right to left
  stack<string> st;   // Stack to hold operands and intermediate results

  while (i >= 0)
  {
    // If the character is an operand, push it to the stack as a string
    if (isOperand(s[i]))
    {
      st.push(string(1, s[i]));
    }
    // If the character is an operator, pop two elements and form the postfix expression
    else
    {
      string t1 = st.top(); // Get the first operand (right operand)
      st.pop();
      string t2 = st.top(); // Get the second operand (left operand)
      st.pop();
      // Push the postfix expression formed by concatenating the two operands followed by the operator
      st.push(t1 + t2 + s[i]);
    }
    i--; // Move to the next character in the prefix expression
  }

  return st.top(); // The final result is the only element left in the stack
}

/****************************************************************

Problem Name: Prefix to Postfix Conversion

Time Complexity:
- O(n), where n is the length of the prefix expression.
  The function processes each character of the prefix expression exactly once,
  and each operation (push or pop) on the stack takes O(1) time.

Space Complexity:
- O(n), where n is the length of the prefix expression.
  In the worst case, the stack can hold all operands, requiring O(n) space.
  Additionally, the result string is also stored, which is proportional to the length of the input.

Explanation:
1. **Prefix and Postfix**:
   - Prefix expressions have operators before their operands (e.g., "+AB"), while in postfix expressions, operators come after operands (e.g., "AB+").
   - This function converts a prefix expression like "+AB" to its equivalent postfix form "AB+".

2. **Stack-Based Approach**:
   - The stack is used to store operands. When an operator is encountered, two operands are popped, and a new postfix string is formed by concatenating the two operands followed by the operator. This new postfix string is pushed back onto the stack.

3. **Edge Cases**:
   - Proper handling of invalid or empty prefix expressions can be added based on constraints provided in the problem.

*****************************************************************/

int main()
{
  // Number of test cases
  int t;
  cin >> t;

  // Loop over each test case
  while (t--)
  {
    string prefix;
    cin >> prefix;

    // Convert prefix to postfix
    string postfix = prefixToPostfix(prefix);

    // Output the postfix expression
    cout << postfix << endl;
  }

  return 0;
}

/*

Explanation:

1. **Prefix and Postfix**:
   - Prefix expressions have operators preceding their operands (e.g., "+AB"), while in postfix expressions, the operators follow the operands (e.g., "AB+").
   - This function converts a prefix expression like "+AB" into the corresponding postfix form "AB+".

2. **Stack-Based Approach**:
   - The stack is used to hold operands (letters or numbers). When an operator is encountered, the two topmost operands are popped from the stack, and a new postfix string is formed by placing the two operands first, followed by the operator. This new postfix string is pushed back onto the stack.
   - The final result will be the only element left in the stack after processing the entire prefix expression.

3. **Time and Space Complexity**:
   - **Time Complexity**: O(n), where n is the length of the prefix expression. The function traverses the prefix string once and performs constant-time stack operations.
   - **Space Complexity**: O(n), where n is the length of the prefix expression. In the worst case, the stack can hold n elements if all are operands before any operator is encountered.

*/
