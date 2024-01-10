/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

/*
void OneToN(int n)
{
    if (n == 0)
    {
        return;
    }

    n--;
    OneToN(n);
    cout << n + 1 << " ";
}
*/

// Second approach
void OneToN(int i, int n)
{
    if (i > n)
    {
        return;
    }

    cout << i << " ";
    OneToN(i + 1, n);
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        OneToN(1, n);
        cout << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

Print linearly 1 to n;

*/