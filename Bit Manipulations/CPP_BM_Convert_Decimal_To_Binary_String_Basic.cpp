//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to reverse a given string
  string reverse(string r)
  {
    string ans = "";

    // Traverse the string from the end to the start
    for (int i = r.size() - 1; i >= 0; i--)
    {
      ans += r[i]; // Add each character to the result
    }

    return ans; // Return the reversed string
  }

  // Function to get a 30-bit binary representation of an integer N
  string getBinaryRep(int N)
  {
    string res = ""; // To store the binary representation

    // Keep dividing N by 2 and store the remainders as binary digits
    while (N > 0)
    {
      if (N % 2 == 1)
        res += '1';
      else
        res += '0';
      N /= 2;
    }

    // Reverse the binary string to get the correct binary order
    string ans = reverse(res);

    // If the binary string is less than 30 bits, pad it with leading zeros
    while (ans.size() < 30)
    {
      ans = '0' + ans;
    }

    return ans; // Return the 30-bit binary string
  }
};

//{ Driver Code Starts.

int main()
{
  int t; // Number of test cases
  cin >> t;
  while (t--)
  {
    int N;
    cin >> N; // Input integer N for each test case

    Solution ob;                     // Create an object of the Solution class
    string ans = ob.getBinaryRep(N); // Get the 30-bit binary representation of N
    cout << ans << endl;             // Output the binary representation
  }
  return 0;
}
// } Driver Code Ends

/*
Problem Name: 30-bit Binary Representation

The task is to return the 30-bit binary representation of a given integer N.
If the binary representation is less than 30 bits, we pad it with leading zeros to ensure a 30-bit string.

Time Complexity Analysis:
- The time complexity of the `getBinaryRep` function is O(log(N)) due to the while loop that divides the number by 2 until N becomes 0.
- The string reversal and padding operations both take O(k), where k is the length of the binary string, but since k is at most 30, these operations are constant time.
- Overall, the time complexity is O(log(N)).

Space Complexity Analysis:
- The space complexity is O(1) extra space, not counting the output string, as we are only using a few additional variables.
- The binary string itself takes O(30) space due to the fixed size of the binary representation.
*/
