#include <bits/stdc++.h>

using namespace std;

int main()
{

  int n;

  // Prompt the user for the length of the binary string
  std::cout << "Enter the length of the bit-string: " << std::endl;
  cin >> n;

  // Iterate over all numbers from 0 to 2^n - 1
  // (1 << n) is equivalent to 2^n, shifting 1 left by n positions
  for (int i = 0; i < (1 << n); i++)
  {
    // Create a bitset of size 32 to represent the binary form of the number i
    bitset<32> b(i);

    // Convert the bitset to a string and take only the last n characters
    // This gives us the n-bit binary representation of the number i
    cout << b.to_string().substr(32 - n) << endl;
  }

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
 * - This approach leverages bit manipulation to generate all binary strings of length `n`.
 * - By iterating over the range from 0 to 2^n - 1, we can generate each binary string.
 * - For each number `i` in this range, we convert it into its binary form using a `bitset`.
 * - The `bitset` is then converted to a string, and only the last `n` bits are extracted and printed.
 *
 * Time Complexity:
 * - The time complexity is O(n * 2^n).
 * - We generate 2^n binary strings, and each string has a length of `n`.
 * - Therefore, for each of the 2^n strings, an O(n) operation (substring extraction) is performed.
 *
 * Space Complexity:
 * - The auxiliary space complexity is O(n) because the space needed to store the binary string is proportional
 *   to its length, which is `n`.
 * - The `bitset` and the string conversion take up space that scales with the length of the binary string.
 *
 * Comparison with Recursive Approach:
 * - This approach differs from the recursive approach in that it uses bit manipulation and iteration rather than
 *   recursion to generate the binary strings.
 * - The recursive approach has a time complexity of O(2^n) and an auxiliary space complexity of O(n) due to the recursion stack.
 * - The bit manipulation approach, while having a similar auxiliary space complexity, involves an additional O(n) factor in
 *   time complexity due to the substring operation needed to extract the relevant bits.
 * - The bit manipulation approach may be more intuitive and easier to implement for generating binary strings, but
 *   it may involve a slightly higher time complexity due to the additional string operations.
 */
