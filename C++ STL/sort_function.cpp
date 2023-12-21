#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}

int main()
{

    int a[] = {5, 18, 5, 0, 6, 489797, 3, 58, 54};

    std::cout << "Before Sorting array elements are: " << std::endl;
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    std::cout << "Sorting using sort function." << std::endl;
    sort(a, a + 9);
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    std::cout << "Sorting using sort function in descending order using comparator greater<int>(): " << std::endl;
    sort(a, a + 9, greater<int>());
    for (auto i : a)
    {
        cout << i << " ";
    }
    cout << endl;

    int a1[] = {5, 18, 5, 0, 6, 489797, 3, 58, 54};
    std::cout << "Sorting using sort function." << std::endl;
    sort(a1 + 2, a1 + 6);
    for (auto i : a1)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> a2 = {6464, 8979, 65646, 9794684, 46494};
    std::cout << "Before Sorting Vector elements are: " << std::endl;
    for (auto i : a2)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<pair<int, int>> vec = {{10, 3}, {20, 1}, {30, 2}};
    std::cout << "Before Sorting Vector elements are: " << std::endl;
    for (auto i : vec)
    {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;

    std::cout << "Custom Sorting using sort function in descending order using comparator sortbysec: " << std::endl;
    sort(vec.begin(), vec.end(), sortbysec);

    for (int i = 0; i < 3; i++)
    {
        cout << vec[i].first << " " << vec[i].second << "\n";
    }

    // sort(a1.begin(),a1.end()); for vector type sorting only

    // sort(a,a+n);  n is size of the array, also similar to {start,end}, end generally donates a pointer outside the last element of the container which means things to be performed are from start to end-1; with end not included
    
    return 0;
}