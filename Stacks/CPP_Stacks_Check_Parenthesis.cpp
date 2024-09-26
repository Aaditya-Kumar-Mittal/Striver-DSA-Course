//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to check if the brackets in the string are balanced or not.
  bool ispar(string x)
  {
    // Stack to store the opening brackets
    stack<char> st;

    // Iterate through each character in the string
    for (char it : x)
    {
      // If the character is an opening bracket, push it to the stack
      if (it == '(' || it == '[' || it == '{')
        st.push(it);
      else
      {
        // If stack is empty while encountering a closing bracket, return false
        if (st.empty())
          return false;

        // Get the top element from the stack and pop it
        char ch = st.top();
        st.pop();

        // Check if the top of the stack matches the current closing bracket
        if (
            (it == ')' && ch == '(') || // Check for round brackets
            (it == ']' && ch == '[') || // Check for square brackets
            (it == '}' && ch == '{')    // Check for curly brackets
        )
          continue; // If matched, continue to the next character
        else
          return false; // If not matched, return false
      }
    }

    // After iterating, the stack should be empty for balanced brackets
    return st.empty();
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  string a;
  cin >> t;
  while (t--)
  {
    cin >> a;
    Solution obj;
    if (obj.ispar(a))
      cout << "balanced" << endl;
    else
      cout << "not balanced" << endl;
  }
  return 0;
}
// } Driver Code Ends

/****************************************************************

Problem Name: Balanced Parentheses

Time Complexity:
- O(n), where n is the length of the string. The function processes each character of the string once and performs O(1) operations for each character.

Space Complexity:
- O(n), where n is the length of the string. In the worst case, the stack may store all opening brackets before finding their matching closing brackets.

Explanation:
1. **Stack Usage**:
   - A stack is used to keep track of opening brackets (`'('`, `'{'`, `'['`). When a closing bracket is encountered, the top of the stack is checked for the corresponding opening bracket.

2. **Validation Logic**:
   - If an opening bracket is encountered, it is pushed onto the stack. When a closing bracket is found, the top of the stack must match the type of closing bracket. If not, the string is invalid.

3. **Edge Cases**:
   - The function handles edge cases like extra closing brackets or leftover opening brackets (if the stack is not empty after processing the entire string).

4. **Final Check**:
   - At the end of the iteration, if the stack is empty, it indicates all brackets are matched and balanced. If not, the string is unbalanced.

*****************************************************************/
