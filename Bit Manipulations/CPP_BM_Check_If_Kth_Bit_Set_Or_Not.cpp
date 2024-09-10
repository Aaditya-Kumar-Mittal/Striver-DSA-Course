//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  // Function to check if the Kth bit is set (i.e., 1) or not in the binary representation of n
  bool checkKthBit(int n, int k)
  {
    // Using bitwise AND to check if the Kth bit is set
    // The expression (1 << k) shifts 1 left by k bits, which creates a mask where only the Kth bit is 1
    // n & (1 << k) will result in a non-zero value if the Kth bit in n is 1, otherwise it results in 0
    return (n & (1 << k));
  }
};

//{ Driver Code Starts.

// Driver Code
int main()
{
  int t;
  cin >> t; // taking test cases

  while (t--)
  {
    long long n;
    cin >> n; // input number n
    int k;
    cin >> k; // bit number k to check
    Solution obj;

    // If the Kth bit is set, print "Yes", otherwise print "No"
    if (obj.checkKthBit(n, k))
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Check if Kth Bit is Set

Approach:
1. The goal is to determine if the Kth bit (0-indexed) of a given number `n` is set (i.e., 1) or not.
2. The bitwise left shift (`1 << k`) is used to create a mask where only the Kth bit is set to 1.
   - Example: For `k = 3`, `1 << 3` results in the binary number `00001000` (in 8-bit representation).
3. Performing `n & (1 << k)` will check if the Kth bit in `n` is 1 or not:
   - If the Kth bit in `n` is 1, the result will be non-zero, and if it's 0, the result will be zero.
4. The function returns true if the Kth bit is set and false otherwise.

Time Complexity:
- The time complexity is O(1) because the bitwise operations (shift and AND) are constant-time operations.

Space Complexity:
- The space complexity is O(1), as no extra space beyond a few variables is used.
*/
