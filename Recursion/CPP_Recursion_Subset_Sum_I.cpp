//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
  // Helper function to compute the sum of all subsets
  void subsetSum(int index, int sum, vector<int> &nums, int size, vector<int> &ans)
  {
    // Base condition: if we've processed all elements
    if (index == size)
    {
      ans.push_back(sum); // Add the current sum to the results
      return;
    }

    // Recursive case 1: pick the current element and add it to the sum
    subsetSum(index + 1, sum + nums[index], nums, nums.size(), ans);

    // Recursive case 2: don't pick the current element, keep the sum as is
    subsetSum(index + 1, sum, nums, nums.size(), ans);
  }

  // Main function to find distinct sums of all subsets of the given array
  vector<int> DistinctSum(vector<int> nums)
  {

    vector<int> sumOfSubsets; // Vector to store all subset sums

    // Call the helper function to calculate all possible subset sums
    subsetSum(0, 0, nums, nums.size(), sumOfSubsets);

    // Sort the subset sums in ascending order
    sort(sumOfSubsets.begin(), sumOfSubsets.end());

    return sumOfSubsets; // Return the sorted list of subset sums
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
      cin >> nums[i];
    Solution obj;
    vector<int> ans = obj.DistinctSum(nums);
    for (auto i : ans)
      cout << i << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Distinct Sum of Subsets

Approach:
1. The problem asks to find all distinct sums that can be obtained from the subsets of the given array.
2. We use recursion to explore two options at every index of the array:
   - Either include the element in the current subset sum or exclude it.
3. The recursion generates all possible sums of subsets. At the base condition of the recursion, the sum is added to the result list.
4. After calculating all the sums, we sort the result to make it easier to analyze the subset sums.

Time Complexity:
- The time complexity is O(2^N) because there are 2^N possible subsets in the array.
- Sorting the result takes O(N log N), where N is the number of subset sums generated.
- Overall time complexity: O(2^N + N log N).

Space Complexity:
- The recursion depth can go as deep as O(N), where N is the number of elements in the array.
- We use additional space for storing subset sums, which is also O(2^N).
- Overall space complexity: O(2^N).

*/
