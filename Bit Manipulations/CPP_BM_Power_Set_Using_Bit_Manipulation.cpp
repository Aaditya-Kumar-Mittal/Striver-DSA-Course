#include <bits/stdc++.h>
using namespace std;

/*
    Function to generate the power set of a given array.

    Parameters:
    - arr: A vector of integers representing the input array.

    Returns:
    - A 2D vector containing all subsets (power set) of the input array.

    Approach:
    - We use bit manipulation to generate all subsets.
    - There are 2^n possible subsets for an array of size n, which can be represented by the binary values from 0 to 2^n - 1.
    - For each binary number, the set bits (1s) correspond to the elements to include in the current subset.
*/

vector<vector<int>> powerSet(vector<int> arr)
{
  // Calculate the total number of subsets (2^n)
  int subsets = 1 << arr.size();

  // Vector to store all subsets (power set)
  vector<vector<int>> ans;

  // Iterate over all possible subset representations
  for (int i = 0; i < subsets; i++)
  {
    vector<int> childSet;

    // Check each bit of the current subset representation
    for (int j = 0; j < arr.size(); j++)
    {
      // If the j-th bit of i is set, include arr[j] in the current subset
      if (i & (1 << j))
      {
        childSet.push_back(arr[j]);
      }
    }

    // Add the current subset to the result
    ans.push_back(childSet);
  }

  return ans;
}

int main()
{
  // Input the number of elements in the array
  int n;
  cin >> n;

  // Input the elements of the array
  vector<int> array(n);
  for (int i = 0; i < n; i++)
  {
    cin >> array[i];
  }

  // Generate the power set of the array
  vector<vector<int>> power_set = powerSet(array);

  // Output all subsets
  cout << "Printing all subsets (power set):" << endl;
  for (const auto &subset : power_set)
  {
    cout << "{ ";
    for (const auto &elem : subset)
    {
      cout << elem << " ";
    }
    cout << "}" << endl;
  }

  return 0;
}

/*
    Analysis:
    - Problem: Generate all possible subsets (power set) of an array.

    1. **Concept**:
       - The power set of a set is the collection of all its subsets.
       - For an array of size `n`, there are 2^n possible subsets, including the empty subset and the full set.
       - Using bit manipulation, we can efficiently generate all subsets by treating each subset as a binary number.
       - Each bit in the binary number corresponds to the presence (1) or absence (0) of an element in the subset.

    2. **Approach**:
       - The total number of subsets is 2^n for an array of size `n`, so we loop over all numbers from `0` to `2^n - 1`.
       - For each number, we check its binary representation to determine which elements to include in the subset.
       - We use the bitwise AND operation to check if the `j`-th element is included in the current subset.

    3. **Time Complexity**:
       - `O(n * 2^n)`: There are `2^n` subsets, and for each subset, we may check all `n` elements to decide whether to include them.

    4. **Space Complexity**:
       - `O(2^n * n)`: The space complexity is dominated by the space required to store the power set, which consists of `2^n` subsets, each of size at most `n`.

    5. **Example**:
       - Input: array = [1, 2, 3]
       - Output:
         { }
         { 1 }
         { 2 }
         { 1 2 }
         { 3 }
         { 1 3 }
         { 2 3 }
         { 1 2 3 }
*/
