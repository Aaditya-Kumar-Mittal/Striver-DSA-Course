#include <bits/stdc++.h>

using namespace std;

void printLinearReverse(int n)
{

  if (n == 0)
    return;

  cout << n << " ";

  printLinearReverse(n - 1);
}

void printLinearBackTracking(int i, int n)
{

  if (i == 0)
    return;

  printLinearBackTracking(i - 1, n);

  cout << n - i + 1 << " ";
}

int main()
{

  int n;

  cin >> n;

  printLinearReverse(n);
  cout << endl;

  printLinearBackTracking(n, n);
  cout << endl;

  return 0;
}