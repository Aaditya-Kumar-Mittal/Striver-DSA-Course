# Stacks - Check or Validate Parentheses, Brackets, and Braces

## Problem Statement

Given a string containing only parentheses `()`, square brackets `[]`, and curly braces `{}`, write a function that determines if the input string is valid.

The input string is considered valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

For example:

- `Input: "()" → Output: true`
- `Input: "([{}])" → Output: true`
- `Input: "(]" → Output: false`
- `Input: "([)]" → Output: false`

### C++ Code

```cpp
class Solution {
public:
    /**
     * @brief This function validates whether the given string of parentheses,
     *        brackets, and braces is properly balanced or not.
     *
     * @param s The input string containing only '(', ')', '{', '}', '[' and ']' characters.
     *
     * @return true if the input string is valid (balanced), otherwise false.
     *
     * ### Approach:
     * 1. We use a stack to store opening parentheses, brackets, or braces as we encounter them.
     * 2. When we encounter a closing parenthesis, bracket, or brace:
     *    - We check if the stack is empty (meaning there is no corresponding opening symbol).
     *      If it's empty, the string is invalid.
     *    - If it's not empty, we pop from the stack and check if the top of the stack contains
     *      the corresponding opening symbol for the current closing one. If it doesn't match,
     *      the string is invalid.
     * 3. After processing the entire string, the stack should be empty for the string to be valid.
     *    If it's not empty, it means there are unmatched opening symbols.
     */
    bool isValid(string s) {
        // Stack to keep track of opening brackets
        stack<char> st;

        // Traverse the string character by character
        for (char it : s) {
            // If the character is an opening bracket, push it onto the stack
            if (it == '(' || it == '[' || it == '{') {
                st.push(it);
            }
            else {
                // If stack is empty, it means we have an unmatched closing bracket
                if (st.empty())
                    return false;

                // Retrieve the top element from the stack
                char ch = st.top();
                st.pop();

                // Check if the current closing bracket matches the top element in the stack
                if ((it == ')' && ch != '(') ||
                    (it == ']' && ch != '[') ||
                    (it == '}' && ch != '{')) {
                    return false;  // If it doesn't match, return false
                }
            }
        }

        // In the end, the stack should be empty if the string is valid
        return st.empty();
    }
};
```

### Explanation

1. **Stack Initialization**:

   - A stack `st` is used to track the opening parentheses, brackets, and braces.
   - The stack helps ensure that every closing bracket has a corresponding and correctly ordered opening bracket.

2. **For Loop Iteration**:

   - The for-loop iterates through every character `it` in the string `s`.

3. **Handling Opening Brackets**:

   - If the current character is an opening bracket `(`, `[`, or `{`, it is pushed onto the stack.

4. **Handling Closing Brackets**:

   - When a closing bracket `)`, `]`, or `}` is encountered:
     - **Empty Stack Check**: If the stack is empty, it indicates that there was no matching opening bracket for this closing bracket, and hence the string is invalid.
     - **Top Element Comparison**: If the stack is not empty, we pop the top element (which should be the corresponding opening bracket) and compare it with the closing bracket:
       - If it matches, we continue processing.
       - If it doesn't match, the string is invalid.

5. **Final Stack Check**:
   - After processing all the characters, if the stack is empty, it means all opening brackets had matching closing brackets in the correct order, so the string is valid.
   - If the stack is not empty, some opening brackets were left unmatched, and the string is invalid.

### Time and Space Complexity

- **Time Complexity**: O(n), where `n` is the length of the input string. We traverse the string once, and each operation (push and pop) takes constant time.
- **Space Complexity**: O(n), since in the worst case (e.g., for a string of all opening brackets), the stack can store up to `n` elements.

### Example

#### Input

```cpp
string s = "([{}])";
Solution sol;
bool result = sol.isValid(s);
```

#### Output

```cpp
true
```

In this example, the input string has matching parentheses, brackets, and braces in the correct order, so the output is `true`.
