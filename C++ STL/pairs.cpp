#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainPairs()
{

    pair<int, int> p = {1, 3};

    std::cout << "Printing the pair elements: " << p.first << " " << p.second << std::endl;

    pair<int, pair<int, int>> p1 = {18, {11, 31}};

    std::cout << "Printing the pair elements: " << p1.first << " " << p1.second.first << " " << p1.second.second << std::endl;

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};

    std::cout << "Printing the pair elements of pair type array: " << arr[1].first << " " << arr[2].second << " " << arr[0].second << std::endl;
}

int main()
{
    explainPairs();

    return 0;
}