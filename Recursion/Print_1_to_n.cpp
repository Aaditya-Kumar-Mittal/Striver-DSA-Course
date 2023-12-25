/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void numbers(int i, int n)
{
    if (i > n)
        return;

    cout << i << " ";
    numbers(i + 1, n);
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
        numbers(1, n);
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

numbers(4)
  numbers(3)
    numbers(2)
      numbers(1)
        numbers(0)
        Print: 0
      Print: 1
    Print: 2
  Print: 3
Print: 4



Using vector

vector<int> printNos(int x) {


    if(x==0){
      return {};
    }

    vector<int> ans=printNos(x-1);
    ans.push_back(x);
    return ans;
}   
*/