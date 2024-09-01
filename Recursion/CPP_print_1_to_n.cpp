#include <bits/stdc++.h>

using namespace std;

void printLinear(int i, int n)
{

  if (i > n)
    return;

  std::cout << i << " ";

  printLinear(i + 1, n);
}

void printLinearSecondApproach(int n)
{

  if (n == 0)
    return;

  printLinearSecondApproach(n - 1);

  cout << n << " ";
}

int main()
{

  int i, n;

  cin >> i >> n;

  printLinear(i, n);
  cout << endl;

  return 0;
}