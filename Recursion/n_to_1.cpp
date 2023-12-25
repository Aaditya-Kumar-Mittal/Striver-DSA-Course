/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void numbers(int n)
{
    if (n == 0)
        return;

    cout << n << " ";
    n--;
    numbers(n);
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
        numbers(n);
        cout << endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

- Recursion:- When a functon calls itself within itself, it is called recursion, until the base condition is met.

- Base Condtition :- The condition required to terminate an infinte recursive function and prevent stack overflow/ segmentation fault.

-Recursion Tree:

Call Stack:

Call Stack:

numbers(4)
  Print: 4
  numbers(3)
    Print: 3
    numbers(2)
      Print: 2
      numbers(1)
        Print: 1
        numbers(0)
        Return
      Return
    Return
  Return
Return



*/