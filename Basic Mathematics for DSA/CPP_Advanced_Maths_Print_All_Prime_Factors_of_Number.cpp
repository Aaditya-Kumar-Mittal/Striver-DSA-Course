// Initial Template for C++
// Include necessary headers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
      Function to find all unique prime factors of a given number N.

      Parameters:
      - N: The number for which prime factors are to be found.

      Returns:
      - A vector containing all unique prime factors of N.

      Approach:
      - This function iterates from 2 to the square root of N to find prime factors.
      - For each integer i, if it is a divisor of N, it is a prime factor. We then divide N by i as long as i is a divisor.
      - After processing all factors up to the square root, if N is still greater than 1, it is itself a prime factor.
  */
  vector<int> AllPrimeFactors(int N)
  {
    vector<int> ans;

    // Iterate from 2 to the square root of N
    for (int i = 2; i * i <= N; i++)
    {
      // Check if i is a factor of N
      if (N % i == 0)
      {
        // Add i to the list of prime factors
        ans.push_back(i);
        // Remove all occurrences of i from N
        while (N % i == 0)
          N /= i;
      }
    }

    // If N is still greater than 1, then it is a prime factor
    if (N != 1)
      ans.push_back(N);

    return ans;
  }
};

// Driver code
int main()
{
  int tc;
  // Read the number of test cases
  cin >> tc;

  // Process each test case
  while (tc--)
  {
    long long int N;
    // Read the number for which we need to find prime factors
    cin >> N;
    Solution ob;
    // Call the function to get prime factors
    vector<int> ans = ob.AllPrimeFactors(N);
    // Print all prime factors
    for (auto i : ans)
    {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}

/* Analysis:
    - Problem: Find All Unique Prime Factors of a Number
    - Approach: Iteration and Division

    1. **Concept**:
       - The problem requires finding all unique prime factors of a given number.
       - A prime factor is a prime number that divides the given number without leaving a remainder.

    2. **Explanation**:
       - We iterate from 2 to the square root of the number to find all possible prime factors.
       - For each integer `i`, if `i` divides `N`, we add `i` to the list of prime factors.
       - We then remove all occurrences of `i` from `N` by continuously dividing `N` by `i`.
       - After processing all factors up to the square root, if `N` is still greater than 1, it means `N` itself is a prime factor.

    3. **Key Steps**:
       - `(N % i == 0)`: Checks if `i` is a factor of `N`.
       - `ans.push_back(i)`: Adds the prime factor `i` to the list.
       - `while (N % i == 0) N /= i`: Removes all occurrences of `i` from `N`.
       - After the loop, if `N` is greater than 1, add `N` to the list of prime factors.

    **Time Complexity**:
       - `O(sqrt(N))` for finding and processing all prime factors up to the square root of `N`.

    **Space Complexity**:
       - `O(log(N))` in the worst case for storing the prime factors (since the number of prime factors is typically much smaller than `N`).

    **Example**:
       - For input: N = 60
       - Output: 2 3 5
       - Explanation: The prime factors of 60 are 2, 3, and 5.
*/
