#include <bits/stdc++.h>
using namespace std;

// Function to unset the rightmost set bit of n
int fun(unsigned int n)
{
  // Unset the rightmost set bit
  return n & (n - 1);
}

// Driver Code
int main()
{
  int n = 7; // Example input
  cout << "The number after unsetting the ";
  cout << "rightmost set bit: " << fun(n) << endl;
  return 0;
}

/*
Analysis:

Problem Name: Unset the Rightmost Set Bit

Approach:
1. **Objective:** Given an unsigned integer `n`, unset the rightmost set bit in its binary representation.
2. **Function Logic:**
   - The function `fun` performs the operation `n & (n - 1)`.
   - **Explanation:**
     - `n - 1` flips all the bits after the rightmost set bit in `n` (including the rightmost set bit itself).
     - Performing `n & (n - 1)` will turn off this rightmost set bit while keeping all other bits unchanged.
   - Example:
     - For `n = 7` (binary: `0111`), `n - 1 = 6` (binary: `0110`).
     - Performing `7 & 6` results in `0110` (binary) which is `6` in decimal.
3. **Why It Works:**
   - Subtracting 1 from `n` changes the least significant 1-bit and all bits to its right to 0.
   - The AND operation with `n` will thus clear the rightmost set bit.

Time Complexity:
- **Bitwise Operations:** The AND operation and subtraction are performed in constant time.
- **Overall Time Complexity:** O(1)

Space Complexity:
- **Auxiliary Space:** No extra space is used apart from the input and output.
- **Overall Space Complexity:** O(1)

Example:
- **Input:** n = 7
  - **Binary Representation:** 0111
  - **n - 1:** 6 → 0110
  - **Result of (7 & 6):** 0110 → Output: 6

- **Input:** n = 10
  - **Binary Representation:** 1010
  - **n - 1:** 9 → 1001
  - **Result of (10 & 9):** 1000 → Output: 8

*/
