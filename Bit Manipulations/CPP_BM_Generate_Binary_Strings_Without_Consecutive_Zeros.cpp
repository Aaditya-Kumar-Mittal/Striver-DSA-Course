#include <bits/stdc++.h>

using namespace std;

vector<string> generateBinaryStringsNoConscZeros(int n)
{

  if (n == 0)
    return {""};

  if (n == 1)
    return {"0", "1"};

  vector<string> ans;

  for (string str : generateBinaryStringsNoConscZeros(n - 1))
  {

    // Add 1 to all the strings and add them to ans arr
    ans.push_back(str + '1');

    // Add 0 only to string ending with 1
    if (str[str.length() - 1] != '0')
    {
      ans.push_back(str + '0');
    }
  }

  return ans;
}

int main()
{

  int n;

  // Prompt the user for the length of the binary string
  std::cout << "Enter the length of the bit-string: " << std::endl;
  cin >> n;

  vector<string> binary_strings = generateBinaryStringsNoConscZeros(n);

  for (auto str : binary_strings)
  {
    std::cout << str << std::endl;
  }

  return 0;
}