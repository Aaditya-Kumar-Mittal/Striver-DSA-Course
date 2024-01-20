#include <bits/stdc++.h>
using namespace std;

//Time Complexity is N+N and not N*N

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for (auto &i : arr)
    {
        cin >> i;
    }

    // preComputation
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // fetching;

    int q;
    cin >> q;
    while (q--)
    {
        int number;
        cin >> number;
        cout << number << " " << mpp[number] << endl;
    }

    // iterating the map
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    return 0;
}
