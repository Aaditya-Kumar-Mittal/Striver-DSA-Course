//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
  // Function to recursively generate all subsets
  void generateSubsets(vector<int> &A, vector<int> &subset, vector<vector<int>> &ans, int index)
  {
    if (index >= A.size())
    {
      ans.push_back(subset); // Base case: Add the current subset to the answer
      return;
    }

    // Exclude the current element and move to the next
    generateSubsets(A, subset, ans, index + 1);

    // Include the current element and move to the next
    subset.push_back(A[index]);
    generateSubsets(A, subset, ans, index + 1);

    subset.pop_back();
  }

  vector<vector<int>> subsets(vector<int> &a)
  {
    vector<vector<int>> ans; // To store all subsets
    vector<int> subset;      // To store the current subset

    // Generate all subsets
    generateSubsets(a, subset, ans, 0);

    // Sort subsets lexicographically
    sort(ans.begin(), ans.end());

    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n, x;
    cin >> n;

    vector<int> array;
    for (int i = 0; i < n; i++)
    {
      cin >> x;
      array.push_back(x);
    }

    Solution ob;
    vector<vector<int>> res = ob.subsets(array);

    // Print result
    for (int i = 0; i < res.size(); i++)
    {
      for (int j = 0; j < res[i].size(); j++)
        cout << res[i][j] << " ";
      cout << endl;
    }
  }

  return 0;
}
// } Driver Code Ends

/*
Analysis Section:

Problem Name: Generate All Subsets

Description:
This code generates all possible subsets (the power set) of an input array. The solution uses a recursive backtracking approach to explore all combinations of inclusion and exclusion for each element of the array. Once all subsets are generated, they are sorted lexicographically.

Time Complexity:
- Each element in the array has two possibilities: either it is included in a subset, or it is not. Hence, for an array of size `n`, the number of subsets is `2^n`.
- Sorting the subsets lexicographically will take `O(2^n * k log(2^n))` where `k` is the average length of the subset.
- Total time complexity: **O(2^n * k log(2^n))**, where `n` is the size of the array.

Space Complexity:
- The recursive calls in `generateSubsets` will require space for each recursive level, and the maximum depth of recursion will be `n` (the length of the array).
- The space required for storing all subsets is also `O(2^n * k)` where `k` is the average subset size.
- Total space complexity: **O(2^n * k)** for storing subsets and `O(n)` for recursion stack space.

*/
