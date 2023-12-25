/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void divisors(long n)
{
    set<int> DIVS;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            DIVS.insert(i);
            if (n / i != i)
            {
                DIVS.insert(n / i);
            }
        }
    }

    // Time complexity of the above code is: O(sqrt of n)

    for (auto &i : DIVS)
    {
        std::cout << i << " ";
    }
}

int main()
{

    // print all divisors

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long n;
        cin >> n;
        divisors(n);
        cout << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:
Suppposedly for 36
1*36
2*18
3*12
4*9
6*6
-------
9*4
12*3
18*2
36*1

Above the line we can virtually get all the divisors, so why exhaut our trials instead iterate till the desired i*i<=n, even if loop till square root of n, we can get our answer.
*/