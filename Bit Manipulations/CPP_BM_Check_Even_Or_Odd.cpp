//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
  /*
      Function to check if a number is odd or even.

      Parameters:
      - n: The integer number to be checked.

      Returns:
      - A string "odd" if the number is odd, otherwise "even".

      Approach:
      - We can determine if a number is odd or even by checking the least significant bit.
      - If the least significant bit (LSB) is 1, the number is odd, otherwise, it is even.
      - We use a bitwise AND operation (`n & 1`) to check the LSB. If `n & 1` results in 1, the number is odd; otherwise, it is even.
  */
  string oddEven(int n)
  {
    // Use bitwise AND operation to determine odd/even
    return n & 1 ? "odd" : "even";
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  // Input number of test cases
  cin >> t;

  while (t--)
  {
    int N;
    // Input the number to check
    cin >> N;

    Solution ob;
    // Output whether the number is odd or even
    cout << ob.oddEven(N) << endl;
  }

  return 0;
}
// } Driver Code Ends

/*
Analysis:
    - Problem: Check whether a given number is odd or even.
    - Difficulty: Easy

1. **Concept**:
   - Every integer number can be classified as either odd or even based on its divisibility by 2.
   - If a number is divisible by 2 (i.e., `n % 2 == 0`), it is even. Otherwise, it is odd.
   - A more efficient way to check for odd or even is to examine the least significant bit (LSB) using bitwise operations:
     - If the LSB is 1, the number is odd.
     - If the LSB is 0, the number is even.

2. **Approach**:
   - **Step 1**: Perform a bitwise AND operation between `n` and `1`.
   - **Step 2**: If the result of `n & 1` is 1, return "odd". If the result is 0, return "even".
   - This approach leverages bitwise operations for efficiency, which is faster than the traditional modulo operation.

3. **Time Complexity**:
   - `O(1)` for each test case as checking the least significant bit takes constant time.

4. **Space Complexity**:
   - `O(1)` as no extra space is required other than the input number.

5. **Example**:
   - Input: N = 5
   - Output: "odd"
   - Explanation: The number 5 has its LSB set to 1, indicating it is odd.

   - Input: N = 4
   - Output: "even"
   - Explanation: The number 4 has its LSB set to 0, indicating it is even.
*/
