//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++
class Solution
{
public:
  // Function to find the element that appears only once in the array
  int search(int n, int arr[])
  {
    int XOR = 0; // Initialize XOR variable

    // Iterate through all elements of the array
    for (int i = 0; i < n; i++)
    {
      // XOR all the elements, which will cancel out pairs and leave the unique element
      XOR = XOR ^ arr[i];
    }

    // Return the element that appears once
    return XOR;
  }
};

//{ Driver Code Starts
// Driver program
int main()
{
  int t, len;
  cin >> t; // Input number of test cases

  // Iterate through each test case
  while (t--)
  {
    cin >> len;   // Input the length of the array
    int arr[len]; // Declare an array of size 'len'

    // Input all elements of the array
    for (int i = 0; i < len; i++)
    {
      cin >> arr[i];
    }

    Solution ob;
    // Output the element that appears only once
    cout << ob.search(len, arr) << '\n';
  }

  return 0;
}
// } Driver Code Ends

/*
Analysis:
----------
Problem Name: Find the Element that Appears Once
Time Complexity: O(n)
    - The time complexity is linear because we traverse the entire array of size n exactly once.
    - XOR operation is performed in constant time for each element.
Space Complexity: O(1)
    - The space complexity is constant as only a single integer variable (XOR) is used for storing the result, regardless of the input size.
*/
