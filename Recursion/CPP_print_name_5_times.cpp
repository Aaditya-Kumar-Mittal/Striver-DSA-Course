#include <bits/stdc++.h>

using namespace std;

void printName(string name, int count)
{

  if (count == 0)
    return;

  cout << name << endl;

  printName(name, count - 1);
}

void printName_2(string name, int start, int end)
{

  if (start > end)
    return;

  cout << name << endl;

  printName_2(name, start + 1, end);
}

int main()
{

  string name;

  cin >> name;

  printName(name, 5);

  std::cout << std::endl;

  printName_2(name, 1, 5);

  return 0;
}