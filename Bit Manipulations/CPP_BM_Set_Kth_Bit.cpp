//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to set the Kth bit of the number N
  int setKthBit(int N, int K)
  {
    // The bitwise OR operation is used to set the Kth bit.
    // 1 << K creates a number where only the Kth bit is 1.
    // N | (1 << K) will ensure the Kth bit of N is set to 1 without altering other bits.
    return (N | (1 << K));
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t; // Taking test cases as input
  while (t--)
  {
    int N, K;
    cin >> N >> K; // Input number N and the bit index K

    Solution ob;
    int ans = ob.setKthBit(N, K); // Call function to set the Kth bit
    cout << ans << endl;          // Output the result
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Set Kth Bit

Approach:
1. The task is to set the Kth bit (0-indexed) of the given number `N` to 1.
2. The expression `1 << K` shifts the number 1 left by K bits, resulting in a binary number with only the Kth bit set to 1.
   - Example: For `K = 2`, `1 << 2` results in `00000100` (in binary).
3. The bitwise OR operation `N | (1 << K)` ensures the Kth bit of N is set to 1. If the Kth bit is already set, the OR operation leaves it unchanged.

Example:
- If `N = 5` (binary `101`) and `K = 1`, `1 << 1` results in `010`, and performing `N | (010)` gives `111`, which is `7` in decimal.

Time Complexity:
- The time complexity is O(1) because the bitwise operations (shift and OR) are performed in constant time.

Space Complexity:
- The space complexity is O(1), as no extra space beyond a few variables is used.
*/
