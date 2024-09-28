#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
  vector<int> help_classmate(vector<int> arr, int n)
  {
    vector<int> NSE(n); // Result vector to store next smaller elements
    stack<int> st;      // Stack to store elements for comparison

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--)
    {
      // Pop elements from stack while top of stack is >= current element
      while (!st.empty() && st.top() >= arr[i])
        st.pop();

      // If stack is empty, there is no smaller element
      if (st.empty())
        NSE[i] = -1;
      else
        NSE[i] = st.top(); // Top of the stack is the next smaller element

      // Push the current element onto the stack
      st.push(arr[i]);
    }

    return NSE;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> array(n);
    for (int i = 0; i < n; ++i)
    {
      cin >> array[i];
    }
    Solution obj;
    vector<int> result = obj.help_classmate(array, n);
    for (int i = 0; i < n; ++i)
    {
      cout << result[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends