// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++

class Solution
{
public:
  // Function to find the number of bits needed to be flipped to convert A to B
  int countBitsFlip(int a, int b)
  {
    // XOR the numbers 'a' and 'b' to find differing bits
    int ans = a ^ b;

    // Initialize the count of flipped bits
    int count = 0;

    // Loop through all the bits of 'ans'
    while (ans != 0)
    {
      // Increment count if the least significant bit (LSB) is set
      count += ans & 1;

      // Right shift 'ans' to check the next bit
      ans >>= 1;
    }

    // If 'ans' is exactly 1, meaning only one bit differs, return 1
    // Otherwise, return the total count of differing bits
    if (ans == 1)
      return 1;
    else
      return count;
  }
};

// { Driver Code Starts.
// Driver Code

int main()
{
  int t;
  // Input the number of test cases
  cin >> t;
  while (t--)
  { // Loop through all test cases
    int a, b;
    // Input two integers 'a' and 'b'
    cin >> a >> b;

    // Create an instance of Solution and call countBitsFlip function
    Solution ob;
    cout << ob.countBitsFlip(a, b) << endl; // Output the result
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Count Bits Flip
This problem asks to find how many bits need to be flipped to convert an integer 'a' to another integer 'b'.

Approach:
1. XOR of two numbers gives a result where bits are set at positions where 'a' and 'b' differ.
2. We count the number of set bits in this XOR result by checking each bit using bitwise AND operation.
3. We right shift the result to examine all bits.

Time Complexity: O(log N)
The time complexity is determined by the number of bits in the integers, which is logarithmic in the size of the input numbers.

Space Complexity: O(1)
We use a constant amount of space to store variables for counting and XOR results.
*/
