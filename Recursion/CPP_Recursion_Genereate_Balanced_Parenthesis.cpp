//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Forward declaration of the function
vector<string> AllParenthesis(int n);

// } Driver Code Ends
// User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parentheses
class Solution
{
public:
  /**
   * @brief Recursively generates all balanced parentheses combinations.
   *
   * This function builds all possible valid combinations of balanced parentheses.
   *
   * @param open Number of open parentheses remaining to be added.
   * @param close Number of close parentheses remaining to be added.
   * @param s Current string being built.
   * @param ans Vector to store all valid combinations.
   */
  void generateParenthesis(int open, int close, string &s, vector<string> &ans)
  {
    // Base case: If no more open or close parentheses left, add the string to the result
    if (open == 0 && close == 0)
    {
      ans.push_back(s);
      return;
    }

    // If there are more close parentheses used than open, or if counts are negative, it's invalid
    if (open > close || open < 0 || close < 0)
    {
      return;
    }

    // Try adding an open parenthesis
    s.push_back('(');
    generateParenthesis(open - 1, close, s, ans);
    s.pop_back(); // Remove the last added parenthesis

    // Try adding a close parenthesis
    s.push_back(')');
    generateParenthesis(open, close - 1, s, ans);
    s.pop_back(); // Remove the last added parenthesis
  }

  /**
   * @brief Initializes the generation of balanced parentheses.
   *
   * Calls the recursive function with initial parameters for generating balanced parentheses.
   *
   * @param n Number of pairs of parentheses.
   * @return Vector containing all valid combinations of balanced parentheses.
   */
  vector<string> AllParenthesis(int n)
  {
    vector<string> res;
    string temp;
    generateParenthesis(n, n, temp, res);
    return res;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t; // Read number of test cases
  while (t--)
  {
    int n;
    cin >> n; // Read number of pairs of parentheses
    Solution ob;
    vector<string> result = ob.AllParenthesis(n);
    sort(result.begin(), result.end()); // Sort results lexicographically
    for (const auto &str : result)
    {
      cout << str << "\n"; // Print each valid combination
    }
  }
  return 0;
}

// } Driver Code Ends

/*
Analysis:

1. **Time Complexity**: O(4^n / sqrt(n)) - The time complexity of generating all valid combinations of balanced parentheses is exponential in nature. Specifically, it is related to the Catalan number, which is approximately 4^n / sqrt(n).

2. **Space Complexity**: O(4^n / sqrt(n)) - The space complexity is also exponential due to the storage requirements for all the valid combinations in the `res` vector. Additionally, the recursion stack contributes to space usage.

3. **Explanation**:
   - The `generateParenthesis` function is recursive and builds all possible strings of balanced parentheses by adding either '(' or ')' while maintaining balance constraints.
   - The base case is when both `open` and `close` are zero, which means a valid string has been built.
   - If the number of open parentheses becomes greater than close parentheses, or if any count becomes negative, the string cannot be valid, so the function returns.
   - The `AllParenthesis` function initializes the recursive process and collects all valid strings.
   - In the `main` function, results are sorted and printed for each test case.
*/
