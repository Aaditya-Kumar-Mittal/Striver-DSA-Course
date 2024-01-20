#include <bits/stdc++.h>
using namespace std;

int freqCharArray[256] = {0};

int main()
{
    string s;
    getline(cin, s);

    // precomputation
    for (int i = 0; i < s.size(); i++)
    {
        freqCharArray[s[i]]++;
    }

    // fetching;

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << c << " " << freqCharArray[c] << endl;
    }

    return 0;
}
