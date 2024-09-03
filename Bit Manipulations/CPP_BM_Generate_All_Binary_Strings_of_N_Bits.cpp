#include <bits/stdc++.h>

using namespace std;

// Function to print the contents of the array
void printArr(vector<int> &arr, int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " "; // Print each element followed by a space
  }
  cout << endl; // Print a newline after printing the array
}

// Recursive function to generate all binary strings of length n
void generateAllBinaryStrings(int n, vector<int> &arr, int i)
{

  // Base case: If the current index i equals n, the array is fully populated
  if (i == n)
  {
    printArr(arr, n); // Print the current binary string
    return;           // Exit the current recursive call
  }

  // Recursive case 1: Set the current index to 0 and recurse
  arr[i] = 0;
  generateAllBinaryStrings(n, arr, i + 1);

  // Recursive case 2: Set the current index to 1 and recurse
  arr[i] = 1;
  generateAllBinaryStrings(n, arr, i + 1);
}

int main()
{
  int n;

  // Prompt the user for the length of the binary string
  std::cout << "Enter the length of the bit-string: " << std::endl;
  cin >> n;

  // Initialize an array of size n to store the binary string
  vector<int> arr(n);

  // Generate all binary strings of length n starting from index 0
  generateAllBinaryStrings(n, arr, 0);

  return 0;
}

/**
 * Analysis:
 *
 * Problem:
 * - Generate and print all possible binary strings of a given length `n`.
 * - A binary string is a sequence of 0s and 1s.
 *
 * Approach:
 * - This problem is solved using a recursive backtracking approach.
 * - The function `generateAllBinaryStrings` recursively builds all possible binary strings
 *   by assigning 0 and 1 to each index and then proceeding to the next index.
 * - The base case occurs when the current index `i` equals `n`, at which point the current binary
 *   string (stored in `arr`) is printed.
 * - The recursion explores all 2^n possible combinations of binary strings.
 *
 * Time Complexity:
 * - The time complexity is O(2^n) because for each index, there are two possible choices (0 or 1),
 *   leading to 2^n total binary strings.
 *
 * Space Complexity:
 * - The space complexity is O(n) due to the space needed to store the binary string in the array `arr`
 *   and the space used by the recursion stack, which has a maximum depth of `n`.
 *
 * Notes:
 * - This approach is efficient for generating all binary strings of small to moderate lengths,
 *   but as `n` increases, the time and space requirements grow exponentially.
 * - This solution leverages backtracking, which is useful in scenarios where all possible combinations
 *   need to be explored.
 */