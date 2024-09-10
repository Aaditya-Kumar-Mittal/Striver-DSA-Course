//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to reverse a given string
  string reverseString(string r)
  {
    string ans = "";

    // Iterate from the last character to the first
    for (int i = r.size() - 1; i >= 0; i--)
    {
      ans += r[i];
    }

    return ans;
  }

  // Function to get the binary representation of an integer N
  string getBinaryRep(int N)
  {
    // Handle the special case when N is 0
    if (N == 0)
      return "0";

    string res = "";

    // Continue until N becomes 0
    while (N != 0)
    {
      // If N is odd, append '1' to the result
      if (N % 2 == 1)
        res += '1';
      else
        res += '0';

      // Divide N by 2 to process the next bit
      N /= 2;
    }

    // Reverse the result to get the correct binary representation
    string ans = reverseString(res);

    return ans;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t; // Taking the number of test cases
  while (t--)
  {
    int N;
    cin >> N; // Input number N

    Solution ob;
    string ans = ob.getBinaryRep(N); // Get binary representation of N
    cout << ans << endl;             // Output the binary representation
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Binary Representation of an Integer

Approach:
1. **Objective:** Convert a given integer `N` into its binary representation as a string.
2. **Handling Special Case:** If `N` is 0, the binary representation is simply "0".
3. **Conversion Process:**
   - Initialize an empty string `res` to store the binary digits in reverse order.
   - Use a loop to divide `N` by 2 iteratively:
     - If `N` is odd (`N % 2 == 1`), append '1' to `res`.
     - If `N` is even, append '0' to `res`.
     - Update `N` by dividing it by 2 (`N /= 2`).
   - Continue this process until `N` becomes 0.
4. **Reversing the String:**
   - Since the binary digits are collected in reverse order, use the `reverseString` function to reverse `res` and obtain the correct binary representation.
5. **Function `reverseString`:**
   - Iterates through the input string from the end to the beginning.
   - Constructs a new string `ans` by appending characters in reverse order.

Time Complexity:
- **Conversion Loop:** The while loop runs approximately `log2(N)` times, as `N` is divided by 2 in each iteration.
- **Reversing the String:** The reverse operation runs in O(k) time, where k is the number of bits in the binary representation (k ≈ log2(N)).
- **Overall Time Complexity:** O(log N)

Space Complexity:
- **Auxiliary Space:**
  - The `res` string stores the binary digits, requiring O(k) space.
  - The `ans` string after reversal also requires O(k) space.
- **Overall Space Complexity:** O(k), where k ≈ log2(N)

Example:
- **Input:** N = 5
  - **Conversion Steps:**
    - 5 % 2 = 1 → res = "1"
    - 5 / 2 = 2
    - 2 % 2 = 0 → res = "10"
    - 2 / 2 = 1
    - 1 % 2 = 1 → res = "101"
    - 1 / 2 = 0 → loop ends
  - **Reversed `res`:** "101" → "101" (remains the same)
  - **Output:** "101"

- **Input:** N = 0
  - **Output:** "0"

Notes:
- The original `reverse` function had an off-by-one error in the loop condition (`i >= 0` should start from `r.size() - 1` instead of `r.size()` to avoid accessing out-of-bounds memory).
- The corrected function `reverseString` ensures that all characters are accessed within the valid range of the string.

*/
