// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h> // Include all standard libraries
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
  /* You are required to complete this method */
  int atoi(string s)
  {
    int ans = 0;      // To store the final result
    int sign = 1;     // To keep track of the sign of the number
    int n = s.size(); // Length of the input string

    // Loop through the string from the end to the beginning
    for (int i = n - 1; i >= 0; --i)
    {
      if (s[i] >= '0' && s[i] <= '9')
      {
        // If character is a digit, convert it to integer and add it to result
        ans += (s[i] - '0') * sign;

        // Update the sign to move to the next higher place value (tens, hundreds, etc.)
        sign *= 10;
      }
      else
      {
        // If the character is not a digit and not handled before, return -1
        return -1;
      }
    }

    // Handle the case where the number is negative
    if (s[0] == '-')
    {
      ans *= -1;
    }
    else if (s[0] >= '0' && s[0] <= '9')
    {
      // If the first character is a digit, adjust the result
      ans += (s[0] - '0') * sign;
    }
    else
    {
      // If the first character is not a digit and not '-'
      return -1;
    }

    return ans; // Return the final result
  }
};

// { Driver Code Starts.
int main()
{
  int t;    // Number of test cases
  cin >> t; // Read the number of test cases
  while (t--)
  {
    string s;             // Input string
    cin >> s;             // Read the input string
    Solution ob;          // Create an instance of Solution class
    int ans = ob.atoi(s); // Convert string to integer
    cout << ans << endl;  // Print the result
  }
}
// } Driver Code Ends

/*
Analysis:
- **Problem Name**: String to Integer Conversion (similar to `atoi` function)
- **Time Complexity**: O(n), where `n` is the length of the input string. This is because we process each character of the string once.
- **Space Complexity**: O(1), as we use a constant amount of extra space (variables `ans`, `sign`, `n`).

Explanation:
1. **Initialization**:
   - `ans`: Stores the resulting integer value.
   - `sign`: Tracks the place value (units, tens, hundreds, etc.).
   - `n`: Length of the string.

2. **Loop through the string**:
   - We start from the end of the string and move backwards.
   - Convert each digit to its integer value and add it to `ans`, adjusted for its place value using `sign`.

3. **Handle negative numbers**:
   - Check the first character to determine if the number is negative.

4. **Edge Cases**:
   - If a non-digit character is encountered or if the first character is neither a digit nor a minus sign, return `-1`.
*/
