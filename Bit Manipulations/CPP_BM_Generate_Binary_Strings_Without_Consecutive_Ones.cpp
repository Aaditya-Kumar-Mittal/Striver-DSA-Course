#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Generates all binary strings of length n that do not have consecutive 1s.
 *
 * This function recursively generates all binary strings of length `n`
 * where no two consecutive bits are `1`. It starts by generating all valid
 * binary strings for length `n-1` and extends them by appending `0` to every
 * string and `1` only to those strings that do not end with `1`.
 *
 * @param n The length of the binary strings to generate.
 * @return A vector of strings containing all valid binary strings of length `n`.
 */
vector<string> generateBinaryStringsNoConscOnes(int n)
{
  // Base case: if n is 0, return an empty string.
  if (n == 0)
    return {""};

  // Base case: if n is 1, return "0" and "1".
  if (n == 1)
    return {"0", "1"};

  vector<string> ans;

  // Recursive case: generate all valid strings of length n-1.
  for (string str : generateBinaryStringsNoConscOnes(n - 1))
  {
    // Add '0' to all strings.
    ans.push_back(str + '0');

    // Add '1' only to strings that do not end with '1'.
    if (str[str.length() - 1] != '1')
    {
      ans.push_back(str + '1');
    }
  }

  return ans;
}

int main()
{
  int n;

  // Prompt the user for the length of the binary string.
  std::cout << "Enter the length of the bit-string: " << std::endl;
  cin >> n;

  // Generate all valid binary strings of length n.
  vector<string> binary_strings = generateBinaryStringsNoConscOnes(n);

  // Print all generated binary strings.
  for (auto str : binary_strings)
  {
    std::cout << str << std::endl;
  }

  return 0;
}

/*
Analysis:
---------
Problem: Generate all binary strings of length `n` that do not contain consecutive `1`s.

Time Complexity: O(2^n)
- The time complexity is O(2^n) because, in the worst case, each recursive call generates two new strings, leading to a total of 2^n possible strings.

Space Complexity: O(n * 2^n)
- The space complexity is O(n * 2^n) because we store all the generated strings in a vector. Each string is of length `n`, and there are at most 2^n such strings.

Approach:
- The function uses a recursive approach to generate valid binary strings of length `n-1` and extends them by adding '0' or '1' to form strings of length `n`.
- '1' is only appended to strings that do not end in '1' to avoid consecutive '1's.
- This approach ensures that all generated strings meet the problem's constraints.
*/
