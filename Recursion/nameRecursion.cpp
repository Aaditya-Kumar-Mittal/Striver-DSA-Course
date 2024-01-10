/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void nameRecursion(int n)
{

    if (n == 0)
    {
        return;
    }

    cout << "Aaditya Kumar" << endl;
    n--;
    nameRecursion(n);
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        nameRecursion(n);
        cout << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

Print name n number of times using recursion

*/