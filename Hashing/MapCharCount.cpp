#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    // preComputation
    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        mpp[s[i]]++;
    }

    // fetching;

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << c << " " << mpp[c] << endl;
    }

    // iterating the map
    for (auto it : mpp)
    {
        cout << it.first << "->" << it.second << endl;
    }

    return 0;
}
