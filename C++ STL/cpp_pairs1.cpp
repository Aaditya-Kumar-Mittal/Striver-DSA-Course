#include <bits/stdc++.h>

using namespace std;
int main()
{

  pair<int, string> p1 = {1, "String"};

  pair<int, string> p2 = make_pair(2, "String2");

  cout << p1.first << " : " << p1.second << endl;
  
  cout << p2.first << " : " << p2.second << endl;

  return 0;
}