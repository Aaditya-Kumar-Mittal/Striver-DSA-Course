#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  /*
      Function to find all unique subsets of the given array 'nums'.
      The array may contain duplicates, so duplicates in the subset must be avoided.
      The function returns a vector of vectors where each inner vector represents a unique subset.

      Parameters:
      - nums: Vector of integers (input array).

      Returns:
      - A vector of vectors containing all unique subsets.
  */
  vector<vector<int>> subsetsWithDup(vector<int> &nums)
  {
    vector<vector<int>> ans; // To store all unique subsets
    vector<int> subset;      // Temporary vector to store the current subset

    // Sort the array to handle duplicates more easily
    sort(nums.begin(), nums.end());

    // Start recursive backtracking to find all subsets
    findSubsets(0, nums, subset, ans);

    return ans; // Return the result containing all subsets
  }

private:
  /*
      Recursive function to find subsets by exploring all possibilities of including or excluding elements.
      It handles duplicate elements by skipping over duplicates to ensure unique subsets.

      Parameters:
      - index: The current index in the array from which to consider elements.
      - arr: The input array, which is sorted to help in skipping duplicates.
      - subset: Vector storing the current subset being built.
      - ans: Vector of vectors to store all the subsets found.
  */
  void findSubsets(int index, vector<int> &arr, vector<int> &subset, vector<vector<int>> &ans)
  {
    // Add the current subset to the answer (even if it's empty)
    ans.push_back(subset);

    // Iterate over the elements starting from the 'index'
    for (int i = index; i < arr.size(); i++)
    {
      // Skip duplicates to ensure subsets are unique
      if (i != index && arr[i] == arr[i - 1])
        continue;

      // Include the current element in the subset
      subset.push_back(arr[i]);

      // Recur with the next index
      findSubsets(i + 1, arr, subset, ans);

      // Backtrack: remove the current element from the subset
      subset.pop_back();
    }
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 2};

  // Function call to find subsets with duplicates
  vector<vector<int>> result = sol.subsetsWithDup(nums);

  // Print the subsets
  for (const auto &subset : result)
  {
    cout << "[";
    for (int num : subset)
    {
      cout << num << " ";
    }
    cout << "]" << endl;
  }

  return 0;
}

/*
    Analysis:
    1. Problem Name: Subsets with Duplicates (Backtracking Approach)

    2. Time Complexity:
       - In the worst case, the solution generates 2^n subsets for an array of size n.
       - Sorting the array takes O(n log n) time.
       - The recursive function explores each subset and skips duplicates. Still, the overall time complexity is O(2^n) due to the exponential nature of generating subsets.
       - Hence, the time complexity is O(2^n * n), where n is the size of the input array (including the sorting step).

    3. Space Complexity:
       - The space complexity is O(n), where n is the maximum depth of the recursion (equal to the size of the input array).
       - Additionally, the space needed to store the results (subsets) is O(2^n * n) since we generate up to 2^n subsets, each containing up to n elements.
       - Therefore, the overall space complexity is O(2^n * n) considering both the recursion depth and storage requirements.

    4. Optimizations:
       - The input array is sorted to handle duplicates efficiently, and we skip over duplicate elements during the recursion to avoid generating duplicate subsets.
       - The backtracking technique helps explore all possible subsets while maintaining a space-efficient approach for small datasets.
*/
