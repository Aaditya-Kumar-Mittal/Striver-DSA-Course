#include <bits/stdc++.h>

using namespace std;

int sumN(int i, int n)
{
  if (i == n)
    return i;

  int sum = 0;

  sum += sumN(i + 1, n);

  return sum + i;
}

// Functional Recursion
int sumofN(int n)
{

  if (n == 0)
    return 0;

  return n + sumofN(n - 1);
}

// Parameterized Recursion
void sumofNParameterized(int i, int sum)
{

  if (i < 0)
  {
    cout << sum;

    return;
  }

  sumofNParameterized(i - 1, sum + i);
}

int main()
{

  int n;

  cin >> n;

  int finalSum = sumN(0, n);

  std::cout << finalSum << std::endl;

  int functionlRecursionSum = sumofN(n);

  std::cout << functionlRecursionSum << std::endl;

  sumofNParameterized(n, 0);

  return 0;
}