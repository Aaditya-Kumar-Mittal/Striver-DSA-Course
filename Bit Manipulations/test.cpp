#include <iostream>

using namespace std;

int main()
{

  int a, b;

  cin >> a >> b;

  std::cout << "Modulo by 2^k " << (a & ((1 << b) - 1)) << std::endl;

  return 0;
}