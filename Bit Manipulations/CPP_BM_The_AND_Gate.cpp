//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  // Function to perform AND operation across all elements of the array
  int andGate(vector<int> a, int N)
  {

    // Initialize the answer as the first element in the array
    int ans = a[0];

    // Traverse through all elements of the array
    for (int i = 0; i < N; i++)
    {

      // If any element is 0, the AND result will immediately be 0
      if (a[i] == 0)
        return 0;

      // Perform bitwise AND with the current element
      ans &= a[i];
    }

    // Return the final result of the AND operation
    return ans;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t; // Input the number of test cases
  while (t--)
  {
    int N;
    cin >> N; // Input the size of the array
    vector<int> v;
    for (int i = 0; i < N; i++)
    {
      int x;
      cin >> x; // Input the elements of the array
      v.push_back(x);
    }
    Solution ob;
    // Output the result of the AND gate function
    cout << ob.andGate(v, N) << endl;
  }
  return 0;
}

// } Driver Code Ends

/*
Analysis:

Problem Name: AND Gate Operation

Approach:
1. The task is to compute the bitwise AND of all elements in an array.
2. The AND operation between bits results in a 1 only if both bits are 1. This means that even if a single element in the array is 0, the result will be 0.
3. The function starts by initializing the result as the first element in the array. It then iterates through the array, performing the AND operation between the current result and each element.
4. If a 0 is encountered during iteration, the function returns 0 early, as the AND of any number with 0 is 0.

Example:
- If the array is `a = [1, 3, 7]`, the binary values of the elements are:
  - 1 in binary: `001`
  - 3 in binary: `011`
  - 7 in binary: `111`
  - The bitwise AND operation proceeds as:
    - `1 & 3 = 001 & 011 = 001` (binary `001`, decimal `1`)
    - `1 & 7 = 001 & 111 = 001` (binary `001`, decimal `1`)
  - The result is `1`.

Time Complexity:
- The time complexity is O(N), where N is the size of the array, as we iterate through all elements of the array.

Space Complexity:
- The space complexity is O(1), since no additional space is used apart from the input array and a few variables.
*/
