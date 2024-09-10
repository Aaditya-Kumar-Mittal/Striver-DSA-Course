//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
  // Function to swap two numbers using bitwise XOR
  pair<int, int> get(int a, int b)
  {

    // Step 1: XOR both numbers, and store the result in 'a'
    a = a ^ b;

    // Step 2: XOR 'a' (which is now 'a ^ b') with 'b', this effectively makes 'b' equal to original 'a'
    b = a ^ b;

    // Step 3: XOR 'a' (which is now 'a ^ b') with 'b' (which is now original 'a'), making 'a' equal to original 'b'
    a = a ^ b;

    // Return the swapped pair of numbers
    return {a, b};
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int a, b;
    cin >> a >> b;

    Solution ob;

    // Call the function to get the swapped values
    pair<int, int> p = ob.get(a, b);

    // Output the swapped values
    cout << p.first << ' ' << p.second << endl;
  }

  return 0;
}

// } Driver Code Ends

/*
Analysis:

Problem Name: Swap Two Numbers Using Bitwise XOR

Approach:
1. The problem is to swap two numbers `a` and `b` without using a temporary variable.
2. The XOR bitwise operation is used for swapping:
   - XOR has the property that `x ^ x = 0` and `x ^ 0 = x`.
   - The steps performed using XOR ensure that `a` gets the value of `b` and vice versa, without needing extra space.
3. This technique works because XOR allows bits to be toggled in such a way that both numbers effectively swap values through three operations.

Time Complexity:
- The time complexity is O(1), since the algorithm performs a fixed number of XOR operations regardless of the input size.

Space Complexity:
- The space complexity is also O(1), as no extra space (like arrays or lists) is used beyond a few variables.

*/
