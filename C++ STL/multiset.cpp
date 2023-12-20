/*
Aaditya Mittal- When you make the same mistake twice, its not a mistake, its a decision.
*/

#include <bits/stdc++.h>
#include <math.h>
using namespace std;

void explainMultiSet()
{

    multiset<int> mst;

    mst.insert(1); //{1}
    mst.insert(1); //{1,1}
    mst.insert(1); //{1,1,1}

    // Erases single element only giving its iterator
    mst.erase(mst.find(1));

    // Erases all elements at once
    mst.erase(1);

    int count = mst.count(1);

    //Rest all functions are same as set
    
}

int main()
{
    explainMultiSet();

    // Set stores everything in sorted order and also stores only duplicate elements
    // In set, a tree order is maintained.

    return 0;
}