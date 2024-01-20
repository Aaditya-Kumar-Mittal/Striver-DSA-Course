#include <bits/stdc++.h>
using namespace std;

int freqCharArray[26] = {0};

int main()
{
    string s;
    getline(cin, s);

    // precomputation
    for (int i = 0; i < s.size(); i++)
    {
        freqCharArray[s[i] - 'a']++;
    }

    // fetching;

    int q;
    cin >> q;
    while (q--)
    {
        char c;
        cin >> c;
        cout << c << " " << freqCharArray[c - 'a'] << endl;
    }

    return 0;
}
