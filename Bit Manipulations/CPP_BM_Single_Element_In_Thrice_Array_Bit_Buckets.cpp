//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution
{
public:
  /*
      Function to find the element that appears once when all others appear thrice.

      Parameters:
      - arr[]: Array of integers where every element appears thrice except one.
      - N: The number of elements in the array.

      Returns:
      - The single element that appears only once.

      Approach:
      - This function uses bitwise operators to keep track of counts of bits across the elements.
      - We maintain two variables `ones` and `twos` to track the bits that appear one and two times respectively.
  */
  int singleElement(int arr[], int N)
  {
    // Variables to store the bits appearing once and twice
    int ones = 0, twos = 0;

    // Iterate over all elements in the array
    for (int i = 0; i < N; i++)
    {
      // Update `ones` with the current element while making sure that the bits that are
      // present in `twos` (appeared twice) are not set in `ones`.
      ones = (ones ^ arr[i]) & (~twos);

      // Update `twos` with the current element while making sure that the bits that are
      // present in `ones` (appeared once) are not set in `twos`.
      twos = (twos ^ arr[i]) & (~ones);
    }

    // The element that appears only once is now stored in `ones`.
    return ones;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t; // Input number of test cases

  while (t--)
  {
    int N;
    cin >> N; // Input size of the array

    int arr[N];
    // Input elements of the array
    for (int i = 0; i < N; i++)
    {
      cin >> arr[i];
    }

    Solution ob;
    // Output the single element that appears once
    cout << ob.singleElement(arr, N) << "\n";
  }

  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem: Find the Element Occurring Once When All Others Are Present Thrice
Approach: Bit Manipulation (Bucket Concept)

1. **Concept**:
   - The problem requires finding an element that appears exactly once while all other elements appear exactly three times.
   - A direct approach using hash maps would take O(N) space, but we aim to solve it with O(1) space using bitwise operations.

2. **Explanation**:
   - We use two variables, `ones` and `twos`, to track the occurrence of each bit in the array.
   - `ones` stores the bits that have appeared exactly once so far.
   - `twos` stores the bits that have appeared exactly twice so far.
   - By using bitwise operations, we ensure that bits which appear three times are reset, leaving only the bits that appear once.

3. **Key Steps**:
   - `(ones ^ arr[i])`: Updates `ones` with the current element's bits.
   - `(~twos)`: Ensures that bits that have already appeared twice don't interfere with `ones`.
   - Similarly, we update `twos` while ensuring that bits in `ones` don’t affect it.
   - After processing all elements, `ones` will hold the result.

**Time Complexity**:
- `O(N)` where `N` is the size of the array. We traverse the array once.

**Space Complexity**:
- `O(1)` as no extra space is used except for a few variables to track the bits.

**Example**:
For input:
N = 4
arr = {3, 3, 2, 3}
Output: 2
Explanation: 2 appears once while 3 appears three times.
*/
