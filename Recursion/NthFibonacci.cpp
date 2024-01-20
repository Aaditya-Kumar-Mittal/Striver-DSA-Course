/*
Aaditya Mittal - My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

int NthFibonacci(int n)
{

    if (n <= 1)
    {

        return n;
    }
    return NthFibonacci(n - 1) + NthFibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        /* code */
        std::cout << "The " << i + 1 << "th Fibonacci number is: " << NthFibonacci(i) << std::endl;
    }

    return 0;
}

/*
Analysis Portion and Comments:

- Understanding Multiple Recursion call using Fibonacci Series
*/
