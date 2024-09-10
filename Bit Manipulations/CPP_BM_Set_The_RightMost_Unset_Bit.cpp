//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to set the least significant bit that is not set in the integer n
  int setBit(int n)
  {
    // Bitwise OR between n and n+1 sets the least significant bit that is not set
    return (n | (n + 1));
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t; // Input number of test cases
  while (t--)
  {
    int N;
    cin >> N; // Input number N
    Solution ob;
    int ans = ob.setBit(N); // Call the function to get the result
    cout << ans << endl;    // Print the result
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Set the Least Significant Unset Bit

Approach:
1. **Objective:** For a given integer `n`, set the least significant bit that is not set.
2. **Function Logic:**
   - Use bitwise OR between `n` and `n + 1`.
   - This operation sets the least significant bit that is not currently set in `n`.
   - Example:
     - For `n = 5` (binary: `0101`), `n + 1 = 6` (binary: `0110`).
     - Performing `5 | 6` results in `0111` (binary) which is `7` in decimal.
3. **Why It Works:**
   - Adding 1 to `n` flips the least significant zero to one and all trailing ones to zero.
   - The OR operation then sets this newly flipped bit and retains all other bits.

Time Complexity:
- **Bitwise Operations:** The OR operation runs in constant time.
- **Overall Time Complexity:** O(1)

Space Complexity:
- **Auxiliary Space:** No extra space is used apart from the input and output.
- **Overall Space Complexity:** O(1)

Example:
- **Input:** N = 5
  - **Binary Representation:** 0101
  - **N + 1:** 6 → 0110
  - **Result of (5 | 6):** 0111 → Output: 7

- **Input:** N = 2
  - **Binary Representation:** 0010
  - **N + 1:** 3 → 0011
  - **Result of (2 | 3):** 0011 → Output: 3

*/
