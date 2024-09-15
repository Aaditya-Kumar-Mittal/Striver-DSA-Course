// Initial Template for C++
// Include necessary headers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
      Function to find two numbers with odd occurrences in an array.

      Parameters:
      - Arr[]: Array of integers where all numbers except two occur an even number of times.
      - N: The size of the array.

      Returns:
      - A vector containing the two odd occurring numbers in decreasing order.

      Approach:
      - Use XOR to find the XOR of the two odd occurring numbers.
      - The XOR of all numbers gives the XOR of the two odd occurring numbers.
      - Use the rightmost set bit to partition the numbers into two groups.
      - XOR each group separately to find the two odd occurring numbers.
  */
  vector<long long int> twoOddNum(long long int Arr[], long long int N)
  {
    long long int XXOR = 0;

    // XOR all elements of the array. This will give the XOR of the two odd occurring numbers.
    for (int i = 0; i < N; i++)
    {
      XXOR = XXOR ^ Arr[i];
    }

    // Find the rightmost set bit in XXOR
    long long int rightMostSet = XXOR & ~(XXOR - 1);

    long long int b1 = 0, b2 = 0;

    // Divide the array elements into two groups based on the rightmost set bit
    for (int i = 0; i < N; i++)
    {
      if (Arr[i] & rightMostSet)
      {
        // If the bit is set, XOR with b1
        b1 = b1 ^ Arr[i];
      }
      else
      {
        // If the bit is not set, XOR with b2
        b2 = b2 ^ Arr[i];
      }
    }

    // Return the numbers in decreasing order
    return (b1 > b2) ? vector<long long int>{b1, b2} : vector<long long int>{b2, b1};
  }
};

// Driver code
int main()
{
  int t;
  // Read number of test cases
  cin >> t;

  // Process each test case
  while (t--)
  {
    long long int N;
    // Input size of the array
    cin >> N;

    long long int Arr[N];
    // Input elements of the array
    for (long long int i = 0; i < N; i++)
    {
      cin >> Arr[i];
    }

    Solution ob;
    // Get the two odd occurring numbers
    vector<long long int> ans = ob.twoOddNum(Arr, N);
    // Print the result
    for (long long int i = 0; i < ans.size(); i++)
    {
      cout << ans[i] << " ";
    }
    cout << endl;
  }

  return 0;
}

/*
Analysis:
    - Problem: Two numbers with odd occurrences in an array
    - Difficulty: Medium

1. **Concept**:
   - The problem is to find two numbers in the array that appear an odd number of times, while all other numbers appear an even number of times.
   - XOR operation is key here, as XOR of two identical numbers is zero (`x ^ x = 0`), and XOR of a number with zero is the number itself (`x ^ 0 = x`).
   - XOR of the entire array gives the XOR of the two odd occurring numbers (since all even occurring numbers cancel out).

2. **Approach**:
   - **Step 1**: XOR all elements in the array to get `XXOR`, which represents the XOR of the two odd occurring numbers.
   - **Step 2**: Find the rightmost set bit of `XXOR` (this helps differentiate the two odd occurring numbers).
   - **Step 3**: Use this bit to partition the numbers into two groups: one group with the set bit and one without.
   - **Step 4**: XOR each group separately to retrieve the two odd occurring numbers.
   - **Step 5**: Return the numbers in decreasing order.

3. **Key Points**:
   - `XXOR = arr[0] ^ arr[1] ^ ... ^ arr[N-1]` gives the XOR of the two odd occurring numbers.
   - `rightMostSet = XXOR & ~(XXOR - 1)` isolates the rightmost set bit.
   - We XOR the numbers where the rightmost bit is set separately from those where it is not set, effectively separating the two odd occurring numbers.

4. **Time Complexity**:
   - `O(N)` where `N` is the size of the array. We traverse the array twice: once to calculate the XOR and once to partition the numbers.

5. **Space Complexity**:
   - `O(1)` as we only use a few extra variables for XOR calculations.

6. **Example**:
   - Input: Arr = {12, 23, 34, 12, 34, 12, 12, 23, 45, 67}, N = 10
   - Output: 67 45
   - Explanation: 67 and 45 are the numbers that occur an odd number of times, all others appear an even number of times.
*/
