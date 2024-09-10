//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

void toBinary(int N)
{
  vector<int> ans; // Vector to store binary digits

  int temp = N; // Copy of N to perform operations

  // Loop to calculate the binary representation
  while (temp > 0)
  {

    // If current bit is 1, push 1 to the vector, otherwise push 0
    if (temp % 2 == 1)
      ans.push_back(1);
    else
      ans.push_back(0);

    // Divide the number by 2 to process the next bit
    temp /= 2;
  }

  // Reverse the vector to get the correct binary order
  reverse(ans.begin(), ans.end());

  // Print the binary digits
  for (auto it : ans)
  {
    cout << it;
  }
}

//{ Driver Code Starts.

int main()
{
  // code

  int t;
  cin >> t; // Input number of test cases

  while (t--)
  {
    int n;
    cin >> n; // Input number N

    toBinary(n);  // Call the function to print binary representation
    cout << endl; // Print new line after each result
  }
  return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem Name: Binary Representation of an Integer

Approach:
1. **Objective:** Convert a given integer `N` to its binary representation and print it.
2. **Vector Storage:**
   - Use a vector `ans` to store the binary digits in reverse order (from least significant to most significant).
3. **Loop to Generate Binary Digits:**
   - While `temp` (copy of `N`) is greater than 0:
     - If the current value of `temp % 2 == 1`, it implies that the current bit is 1, so append `1` to `ans`.
     - If `temp % 2 == 0`, append `0` to `ans`.
     - Divide `temp` by 2 to process the next bit.
4. **Reversing:** The binary digits are generated in reverse order, so we reverse the vector before printing.
5. **Edge Case:** The loop skips when `N == 0`, but that case is typically managed outside by checking and directly printing `0` if needed.

Time Complexity:
- **Loop to generate binary digits:** The loop runs approximately `log2(N)` times, as `N` is divided by 2 in each iteration.
- **Reversing the vector:** Reversing the vector takes O(k), where k is the number of bits in the binary representation (≈ log2(N)).
- **Printing the digits:** Printing the binary digits also takes O(k).
- **Overall Time Complexity:** O(log N)

Space Complexity:
- **Auxiliary Space:**
  - The vector `ans` stores the binary digits, requiring O(k) space.
- **Overall Space Complexity:** O(log N), where k ≈ log2(N).

Example:
- **Input:** N = 5
  - **Binary Representation:**
    - 5 % 2 = 1 → append 1 to `ans`
    - 5 / 2 = 2
    - 2 % 2 = 0 → append 0 to `ans`
    - 2 / 2 = 1
    - 1 % 2 = 1 → append 1 to `ans`
    - 1 / 2 = 0 → loop ends
    - Reverse `ans`: "101" → Output: "101"

- **Input:** N = 10
  - **Binary Representation:**
    - 10 % 2 = 0 → append 0 to `ans`
    - 10 / 2 = 5
    - 5 % 2 = 1 → append 1 to `ans`
    - 5 / 2 = 2
    - 2 % 2 = 0 → append 0 to `ans`
    - 2 / 2 = 1
    - 1 % 2 = 1 → append 1 to `ans`
    - 1 / 2 = 0 → loop ends
    - Reverse `ans`: "1010" → Output: "1010"

*/
