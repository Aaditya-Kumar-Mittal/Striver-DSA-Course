#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  /**
   * @brief Finds the largest prime factor of a given integer N.
   *
   * This function iteratively checks for prime factors starting from 2 up to the square root of N.
   * When a factor is found, it reduces N by dividing it with the factor until it no longer divides evenly.
   * Finally, if N is greater than 1, it means N itself is a prime factor.
   *
   * @param N The number for which the largest prime factor is to be found.
   * @return The largest prime factor of N.
   *
   * Time Complexity: O(sqrt(N)) - The loop runs from 2 to sqrt(N) to find prime factors.
   * Space Complexity: O(1) - Only a few variables are used for calculations, no additional data structures.
   */
  long long int largestPrimeFactor(int N)
  {
    vector<int> list; // Vector to store prime factors

    // Check for factors from 2 to sqrt(N)
    for (int i = 2; i * i <= N; i++)
    {
      if (N % i == 0)
      {                    // If i is a factor
        list.push_back(i); // Store the prime factor
        // Divide N by i until it no longer divides evenly
        while (N % i == 0)
        {
          N /= i; // Reduce N
        }
      }
    }

    // If N is greater than 1, it is a prime factor
    if (N > 1)
    {
      list.push_back(N);
    }

    // Find and return the largest prime factor
    long long int ans = *max_element(list.begin(), list.end());
    return ans;
  }
};

// Driver Code
int main()
{
  int t;
  cin >> t; // Number of test cases
  while (t--)
  {
    int N;
    cin >> N; // Input number
    Solution ob;
    cout << ob.largestPrimeFactor(N) << endl; // Output the largest prime factor
  }
  return 0;
}

/**
 * Analysis:
 *
 * Problem Name: Largest Prime Factor
 *
 * Time Complexity:
 * - O(sqrt(N)) for finding prime factors where N is the input number.
 *
 * Space Complexity:
 * - O(1) since the only space used is for a few variables and a vector to store factors,
 *   which is not significant compared to the input size.
 */
