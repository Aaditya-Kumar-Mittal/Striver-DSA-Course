/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainMap()
{
    map<int, int> mpp;
    map<string, int> mppStr;

    // Storing for int int

    auto itend = mpp.end();

    mpp[1] = 2;
    mpp.emplace(3, 2);
    mpp.insert({5, 16});
    for (auto i : mpp)
    {
        std::cout << i.first << " " << i.second << std::endl;
    }

    cout << mpp[1] << endl;
    cout << mpp[4] << endl; // Doesn't exist prints null or 0

    auto it = mpp.find(4); // not present points to the after mpp.end()

    auto it1 = mpp.lower_bound(2);

    auto it2 = mpp.upper_bound(6);

    // erase, swap, reverse are same as above

    map<int, pair<int, int>> mpp1;

    map<pair<int, int>, int> mpp2;
}

void explainMultimap()
{

    // Same as map, you can store duplicate keys
    // only map[key] functionality cannot be used

    multimap<int, int> mpp;
    multimap<string, int> mppS;

    cout << "insert() – to insert an element in the multimap. " << endl;
    mpp.insert({1, 10});
    mpp.insert({2, 20});

    std::cout << "find() – to search for an element in the map." << std::endl;

    if (mpp.find(2) != mpp.end())
        cout << "true" << endl;

    std::cout << "begin() – return an iterator pointing to the first element in the multimap." << std::endl;

    std::cout << "mp.end(); – returns an iterator to the theoretical element after the last element." << std::endl;

    multimap<int, int> mp;
    for (int i = 1; i <= 5; i++)
    {
        mp.insert({i, i * 10});
    }
    mp.insert({4, 40});

    cout << "Elements present in the multimap: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    int n = 2;
    if (mp.find(2) != mp.end())
        cout << n << " is present in multimap" << endl;

    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "The size of the multimap is: " << mp.size() << endl;

    if (mp.empty() == false)
        cout << "The multimap is not empty " << endl;
    else
        cout << "The multimap is empty" << endl;
    mp.clear();
    cout << "Size of the multimap after clearing all the elements: " << mp.size();

    //
}

void explainUnorderedMap()
{
    // same as map random key not in sorted order works in O(1) in worst case O(n)

    unordered_map<int, int> mp;
    for (int i = 1; i <= 5; i++)
    {
        mp.insert({i, i * 10});
    }

    cout << "Elements present in the map: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    int n = 2;
    if (mp.find(2) != mp.end())
        cout << n << " is present in map" << endl;

    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "The size of the map is: " << mp.size() << endl;

    if (mp.empty() == false)
        cout << "The map is not empty " << endl;
    else
        cout << "The map is empty" << endl;
    mp.clear();
    cout << "Size of the set after clearing all the elements: " << mp.size();
}

int main()
{
    explainMap();

    // A unique key and value type of container
    // key can be of any data structure stores key in sorted order similar to set data structure

    cout << endl
         << endl
         << "-------------------------------------------------------------------------------" << endl
         << endl;
    map<int, int> mp;
    for (int i = 1; i <= 5; i++)
    {
        mp.insert({i, i * 10});
    }

    cout << "Elements present in the map: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    int n = 2;
    if (mp.find(2) != mp.end())
        cout << n << " is present in map" << endl;

    mp.erase(mp.begin());
    cout << "Elements after deleting the first element: " << endl;
    cout << "Key\tElement" << endl;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << "\t" << it->second << endl;
    }

    cout << "The size of the map is: " << mp.size() << endl;

    if (mp.empty() == false)
        cout << "The map is not empty " << endl;
    else
        cout << "The map is empty" << endl;
    mp.clear();
    cout << "Size of the map after clearing all the elements: " << mp.size();

    cout << endl
         << endl
         << "-------------------------------------------------------------------------------" << endl
         << endl;

    explainMultimap();

    cout << endl
         << endl
         << "-------------------------------------------------------------------------------" << endl
         << endl;

    explainUnorderedMap();

    cout << endl
         << endl
         << "-------------------------------------------------------------------------------" << endl
         << endl;

    return 0;
}