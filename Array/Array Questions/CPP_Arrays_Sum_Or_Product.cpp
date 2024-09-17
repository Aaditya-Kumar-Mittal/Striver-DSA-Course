#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

// Function to compute sum or product of first n natural numbers
long long int sumOrProduct(long long int n, long long int q)
{
  // If q == 1, return the sum of first n natural numbers modulo MOD
  if (q == 1)
  {
    // Using the formula (n * (n + 1)) / 2, but applying modulo during the calculation
    long long int sum = (n * (n + 1) / 2) % MOD;
    return sum;
  }
  // If q == 2, return the product of first n numbers modulo MOD
  else if (q == 2)
  {
    long long int result = 1;
    for (int i = 1; i <= n; i++)
    {
      result = (result * i) % MOD;
    }
    return result;
  }
  return -1; // Just in case an invalid query is given
}

int main()
{
  long long int n, q;
  cin >> n >> q;

  cout << sumOrProduct(n, q) << endl;

  return 0;
}

/*

### Explanation:
1. **Sum Calculation**:
   - Instead of directly calculating `(n * (n + 1)) / 2`, the modulo is applied after calculating the sum to prevent overflow for large values of `n`.
2. **Product Calculation**:
   - The factorial modulo \(10^9 + 7\) is calculated using a loop, where we take modulo at every step to keep the result manageable.

### Time Complexity:
- For **sum**: \(O(1)\), as we directly use the formula for the sum.
- For **product**: \(O(n)\), since we iterate from 1 to \(n\) to calculate the factorial.

### Space Complexity:
- \(O(1)\), only a few variables are used for calculations.

### Example:
- Input: `n = 5`, `q = 1`
  - Output: Sum = `(5 * (5 + 1)) / 2 = 15`
- Input: `n = 5`, `q = 2`
  - Output: Product = `5! = 120`

  */