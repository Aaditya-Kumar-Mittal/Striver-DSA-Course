#include <iostream>
#include <vector>
using namespace std;

/*
   Function to recursively check if there exists a subset of the array 'arr' that sums up to 'sum'.
   It explores all subsets of the array by including and excluding the current element.

   Parameters:
   - ind: Current index in the array.
   - ds: Vector storing the current subset being considered.
   - s: Current sum of the subset.
   - sum: Target sum we want to achieve.
   - arr: The input array.
   - n: Size of the array.

   Returns:
   - true if a subset with the given sum is found.
   - false otherwise.
*/
bool checkSubset(int ind, vector<int> &ds, int s, int sum, vector<int> &arr, int n)
{

  // Base case: If we've reached the end of the array
  if (ind == n)
  {
    // If the current subset sum matches the target sum, return true
    if (s == sum)
    {
      return true;
    }
    return false;
  }

  // Include the current element in the subset
  ds.push_back(arr[ind]);
  s += arr[ind];

  // Recur for the next element
  if (checkSubset(ind + 1, ds, s, sum, arr, n))
    return true;

  // Backtrack: Exclude the current element from the subset
  ds.pop_back();
  s -= arr[ind];

  // Recur for the next element without including the current one
  if (checkSubset(ind + 1, ds, s, sum, arr, n))
    return true;

  return false;
}

/*
   Main function to check if there exists any subset in the array 'a' that sums up to 'k'.

   Parameters:
   - n: Size of the array.
   - k: Target sum.
   - a: The input array.

   Returns:
   - true if such a subset exists.
   - false otherwise.
*/
bool isSubsetPresent(int n, int k, vector<int> &a)
{
  int s = 0;      // Current sum of the subset
  vector<int> ds; // Stores the current subset
  return checkSubset(0, ds, s, k, a, n);
}

int main()
{
  // Example input
  int n = 6;
  int k = 10;
  vector<int> a = {2, 3, 7, 8, 10};

  // Function call to check if the subset sum exists
  bool result = isSubsetPresent(n, k, a);

  if (result)
  {
    cout << "Subset with the given sum exists." << endl;
  }
  else
  {
    cout << "Subset with the given sum does not exist." << endl;
  }

  return 0;
}

/*
   Analysis:
   1. Problem Name: Subset Sum Problem (Recursive Backtracking Approach)

   2. Time Complexity:
      - The function explores every possible subset of the array.
      - For each element, there are two possibilities: either include it in the subset or exclude it.
      - This results in 2^n possible subsets, where n is the number of elements in the array.
      - Therefore, the time complexity of this approach is O(2^n), which is exponential.

   3. Space Complexity:
      - The space complexity is O(n), where n is the size of the array.
      - This is because the recursive stack can go as deep as n levels (due to recursion and backtracking), and the vector 'ds' (used to store the subset) can also have a maximum size of n.

   4. Limitations:
      - The current approach might be inefficient for larger values of n due to the exponential time complexity.
      - A more optimized solution, such as dynamic programming, would be better suited for larger datasets.
*/
