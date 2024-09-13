#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  /*
      Function to generate all possible permutations of the given array `arr`.
      This function uses backtracking to explore all permutations while maintaining
      an auxiliary frequency array to keep track of the visited elements.

      Parameters:
      - ds: Vector used to store the current permutation being built.
      - arr: Input array for which we are generating permutations.
      - ans: Vector of vectors storing all the generated permutations.
      - freq: An array to keep track of which elements are already included in the current permutation.
  */
  void generatePermutations(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[])
  {
    // If the current permutation is of the same length as the input array, add it to the results
    if (ds.size() == arr.size())
    {
      ans.push_back(ds);
      return;
    }

    // Try placing each element in the current position, if it's not already used
    for (int i = 0; i < arr.size(); i++)
    {
      if (!freq[i])
      {                       // If the element hasn't been used in the current permutation
        ds.push_back(arr[i]); // Add element to the current permutation
        freq[i] = 1;          // Mark element as used

        // Recur to build the next position in the permutation
        generatePermutations(ds, arr, ans, freq);

        // Backtrack: remove the element and mark it as unused
        freq[i] = 0;
        ds.pop_back();
      }
    }
  }

  /*
      Main function to find all permutations of the given input array `nums`.

      Parameters:
      - nums: Input vector of integers for which we are generating permutations.

      Returns:
      - A vector of vectors containing all the permutations of `nums`.
  */
  vector<vector<int>> permute(vector<int> &nums)
  {
    ios_base::sync_with_stdio(0); // Fast I/O
    cin.tie(NULL);                // Disable I/O synchronization
    cout.tie(NULL);

    vector<vector<int>> ans; // To store all permutations
    vector<int> ds;          // Temporary vector to store current permutation

    // Frequency array to mark whether an element is included in the current permutation
    int frequency[nums.size()];
    for (int i = 0; i < nums.size(); i++)
      frequency[i] = 0; // Initialize all elements to unused

    // Start generating permutations using backtracking
    generatePermutations(ds, nums, ans, frequency);

    return ans; // Return the list of permutations
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {1, 2, 3};

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
    1. Problem Name: Permutations (Backtracking Approach)

    2. Time Complexity:
       - The time complexity is O(n * n!), where n is the size of the input array.
       - There are n! permutations in total, and for each permutation, we need O(n) time to construct and store it.
       - The recursive calls and backtracking explore all possible permutations.

    3. Space Complexity:
       - The space complexity is O(n) for the recursion stack and the temporary vector `ds`.
       - Additionally, the frequency array takes O(n) space, so the overall space complexity is O(n).
       - The result vector `ans` will take O(n * n!) space to store all the permutations.

    4. Optimizations:
       - This solution uses backtracking to efficiently explore permutations while ensuring that each element is used only once in each permutation.
       - A frequency array keeps track of used elements, and backtracking ensures that all combinations are explored.
*/
