/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void numbers(int i, int n)
{
    if (i < 1)
        return;

    cout << i << " ";
    numbers(i - 1, n);
}

int main()
{

    // print all divisors

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        numbers(n, n);
        cout << endl;
    }
    return 0;
}
