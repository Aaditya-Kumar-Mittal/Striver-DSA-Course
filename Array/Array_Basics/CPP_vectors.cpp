#include <bits/stdc++.h>

using namespace std;

int main()
{

  vector<int> v = {5, 5, 6, 9, 8, 5, 62, 1, 58, 56, 5, 9, 3, 6, 45};

  cout << "Size of the vector : " << v.size() << endl;

  std::cout << "Elements in the vector : " << std::endl;

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }

  std::cout << std::endl;

  std::cout << "Vector after sorting using sort() function : " << std::endl;

  sort(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }

  std::cout << std::endl;

  cout << "Vector after reversing using reverse() function : " << endl;

  reverse(v.begin(), v.end());

  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }

   std::cout  << std::endl;

  return 0;
}