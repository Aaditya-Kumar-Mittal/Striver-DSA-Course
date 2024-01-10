/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

// Second approach
void NToOne(int i, int n)
{
    if (i < 1)
    {
        return;
    }

    cout << i << " ";
    NToOne(i - 1, n);
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        NToOne(n, n);
        cout << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

Print reversely n to 1

*/