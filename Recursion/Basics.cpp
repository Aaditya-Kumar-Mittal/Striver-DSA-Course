/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void name(int n)
{
    if (n == 0)
        return;

    cout << "Aaditya Mittal" << endl;
    n--;
    name(n);
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
        name(n);
        cout<<endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

- Recursion:- When a functon calls itself within itself, it is called recursion, until the base condition is met.

- Base Condtition :- The condition required to terminate an infinte recursive function and prevent stack overflow/ segmentation fault.

*/