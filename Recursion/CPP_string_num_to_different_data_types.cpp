#include <bits/stdc++.h>

using namespace std;

int main()
{

  // Converting string num --> long integer

  char str1[] = "564565456";

  long int num1 = atol(str1);

  std::cout << "Number converted from string num to long int is: " << num1 << std::endl;

  char str2[] = "56456545 6"; // string having space

  long int num2 = atol(str2);

  std::cout << "Number converted from string num to long int is: " << num2 << std::endl;

  /**
   * atoll() in C/C++
   * The atoll() function converts a C-style string, passed as an argument to atol() function, to a long long integer. It converts the C-string str to a value of type long long int by interpreting the characters of the string as numerical values. It discards the leading whitespace characters until a non-whitespace character is found.
   *
   * Syntax --> long long int atoll ( const char * str );
   *
   * Returns:
   * The function returns the long long int representation of the string.
   * It returns ‘0’ if no valid conversion can be performe.
   *
   * Note: If the C-string str passed to atol() function is either empty or contains only whitespace characters, it is not a valid integral number, no conversion will be performed and it will return zero.
   *
   */

  // char array of numbers
  char big_num1[] = "8239206483232728";

  // Function calling to convert to a long int
  long long int bignum1 = atoll(big_num1);

  cout << "Number is " << bignum1 << "\n";

  // char array of numbers of spaces
  char big_num2[] = "100000 9 1324100";

  // Function calling to convert to a long int
  long long int bignum2 = atoll(big_num2);

  cout << "Number is " << bignum2 << "\n";

  return 0;
}