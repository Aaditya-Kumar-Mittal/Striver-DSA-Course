#include <bits/stdc++.h>

using namespace std;

int main()
{
  char str[100];

  cout << "Enter String: ";
  cin.getline(str, 100, '$'); // Read until '$' is encountered it is called Delimiter
  cout << "String is: " << str << endl;
  return 0;
}