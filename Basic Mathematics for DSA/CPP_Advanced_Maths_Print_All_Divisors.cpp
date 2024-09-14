// Initial Template for C++
// Include necessary headers
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /*
      Function to print all divisors of a given number n.

      Parameters:
      - n: The number for which divisors are to be found.

      Approach:
      - This function uses a set to store and print all unique divisors of the given number.
      - It iterates from 1 to the square root of n to find all divisors and their pairs.
  */
  void print_divisors(int n)
  {
    // Use a set to store unique divisors
    set<int> st;

    // Iterate from 1 to the square root of n
    for (int i = 1; i * i <= n; i++)
    {
      // Check if i is a divisor of n
      if (n % i == 0)
      {
        // Add i to the set of divisors
        st.insert(i);
        // Add the corresponding divisor n / i, if it's not equal to i
        if (n / i != i)
        {
          st.insert(n / i);
        }
      }
    }

    // Print all the divisors
    for (auto it : st)
    {
      cout << it << " ";
    }
  }
};

// Driver code
int main()
{
  int T;
  // Read the number of test cases
  cin >> T;

  // Process each test case
  while (T--)
  {
    int n;
    // Read the number for which we need to find divisors
    cin >> n;
    Solution ob;
    // Call the function to print divisors
    ob.print_divisors(n);
    cout << endl;
  }
  return 0;
}

/* Analysis:
    - Problem: Print Divisors of a Number
    - Approach: Iteration and Set to Store Unique Divisors

    1. **Concept**:
       - The problem requires printing all divisors of a given number.
       - A divisor is a number that divides another number completely without leaving a remainder.

    2. **Explanation**:
       - We use a set to store divisors to ensure they are unique.
       - We iterate from 1 to the square root of the number. For each integer `i`, if `i` is a divisor, then both `i` and `n / i` are divisors.
       - By iterating up to the square root, we cover all possible divisors efficiently.

    3. **Key Steps**:
       - `(n % i == 0)`: Checks if `i` is a divisor of `n`.
       - `st.insert(i)`: Inserts the divisor `i` into the set.
       - `st.insert(n / i)`: Inserts the corresponding divisor `n / i` into the set if it's different from `i`.
       - After processing, we print all unique divisors stored in the set.

    **Time Complexity**:
       - `O(sqrt(n) log(sqrt(n)))` due to the iteration up to square root and insertion in the set.

    **Space Complexity**:
       - `O(sqrt(n))` due to the storage of divisors in the set.

    **Example**:
       - For input: n = 12
       - Output: 1 2 3 4 6 12
       - Explanation: These are all divisors of 12.
*/
