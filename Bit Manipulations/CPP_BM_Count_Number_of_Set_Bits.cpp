//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Function to count the number of set bits in the binary representation of a number
  int setBits(int n)
  {
    int count = 0; // Variable to store the count of set bits
    int temp = n;  // Temporary variable to manipulate the input number

    // Loop until all bits are processed
    while (temp != 0)
    {
      // Increment count if the least significant bit is 1
      count += temp & 1;
      // Right shift the number by 1 bit to check the next bit
      temp >>= 1;
    }

    // This condition is redundant, but checking if temp equals 1
    if (temp == 1)
      return 1;

    // Return the total count of set bits
    return count;
  }
};

//{ Driver Code Starts
int main()
{
  int t;
  cin >> t; // Input the number of test cases

  // Iterate through each test case
  while (t--)
  {
    int N;
    cin >> N; // Input the integer for which set bits are to be counted

    Solution ob;
    int cnt = ob.setBits(N); // Call the function to count set bits
    cout << cnt << endl;     // Output the result
  }

  return 0;
}
// } Driver Code Ends

/*
Analysis:
----------
Problem Name: Count Set Bits in an Integer
Time Complexity: O(log N)
    - The time complexity is determined by the number of bits in the integer, which is proportional to log N.
    - Each iteration of the loop shifts the number by 1 bit, which results in a logarithmic number of iterations.
Space Complexity: O(1)
    - The space complexity is constant as only a few integer variables are used, regardless of the size of the input.
*/
