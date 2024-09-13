#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  /*
      Function to generate all permutations starting from a given index.
      The function uses the technique of swapping to generate permutations in-place.

      Parameters:
      - index: The current index from where we are generating permutations.
      - arr: The input array for which we are generating permutations.
      - ans: A vector of vectors storing all the permutations.

      This function uses backtracking by swapping elements back to their original position
      after exploring all possible permutations for a given configuration.
  */
  void genPermutes(int index, vector<int> &arr, vector<vector<int>> &ans)
  {
    // Base case: if we have generated a permutation for the entire array
    if (index == arr.size())
    {
      ans.push_back(arr); // Add the generated permutation to the result
      return;
    }

    // Recursive case: generate permutations by swapping the current element
    // with each element in the remaining subarray
    for (int i = index; i < arr.size(); i++)
    {
      swap(arr[index], arr[i]);         // Swap the current index with i to generate a new permutation
      genPermutes(index + 1, arr, ans); // Recur for the next index
      swap(arr[index], arr[i]);         // Backtrack to the original state (undo the swap)
    }
  }

  /*
      Main function to generate all permutations of the given input array `nums`.

      Parameters:
      - nums: A vector of integers for which we are generating all permutations.

      Returns:
      - A vector of vectors containing all the permutations of `nums`.
  */
  vector<vector<int>> permute(vector<int> &nums)
  {
    ios_base::sync_with_stdio(0); // Fast I/O
    cin.tie(NULL);                // Disable I/O synchronization
    cout.tie(NULL);

    vector<vector<int>> ans; // To store all permutations

    // Start generating permutations using backtracking from the first index
    genPermutes(0, nums, ans);

    return ans; // Return the list of permutations
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3}; // Example input array

  // Call the function to generate all permutations
  vector<vector<int>> result = sol.permute(nums);

  // Print the result
  for (const auto &perm : result)
  {
    cout << "[";
    for (int num : perm)
    {
      cout << num << " ";
    }
    cout << "]\n";
  }

  return 0;
}

/*
    Analysis:
    1. Problem Name: Permutations (In-place Swapping Backtracking Approach)

    2. Time Complexity:
       - The time complexity is O(n * n!), where n is the size of the input array.
       - There are n! permutations in total, and for each permutation, we spend O(n) time to generate it by swapping elements.

    3. Space Complexity:
       - The space complexity is O(n), due to the recursion stack depth.
       - No additional space is required to store intermediate results since permutations are generated in-place.

    4. Optimizations:
       - The use of in-place swapping reduces the space overhead of extra data structures.
       - The backtracking step ensures that the function explores all permutations without redundant calculations.
       - This approach is efficient for generating permutations as it avoids the need for extra arrays to store subsets or temporary results.
*/
