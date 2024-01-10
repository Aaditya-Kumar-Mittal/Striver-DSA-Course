/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

// Parameterised Way
void Sum1ToNParameterized(int i, int sum)
{
    if (i < 0)
    {
        cout << sum;
        return;
    }
    Sum1ToNParameterized(i - 1, sum + i);
}

int32_t Sum1ToNFunctional(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + Sum1ToNFunctional(n - 1);
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        Sum1ToNParameterized(n, 0);
        cout << " " << Sum1ToNFunctional(n) << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

Sum from 1 to n

*/