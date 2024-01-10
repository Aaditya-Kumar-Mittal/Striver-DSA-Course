/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void FactorialParametrized(int i, int fact)
{

    if (i <= 1)
    {
        cout << fact;
        return;
    }

    FactorialParametrized(i - 1, fact * i);
}

int FactorialFunctional(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    return n * FactorialFunctional(n - 1);
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        FactorialParametrized(n, 1);
        cout << " " << FactorialFunctional(n) << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

Factorial

*/