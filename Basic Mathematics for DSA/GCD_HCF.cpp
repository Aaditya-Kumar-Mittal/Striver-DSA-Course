/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

int GCD_Brute(int n1, int n2)
{
    int gcd = 1;

    int minNo = min(n1, n2);

    for (int i = 1; i <= minNo; i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}

int GCD_Euclidean_Algorithm(int n1, int n2)
{
    int gcd = 1;

    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else if (n1 < n2)
            n2 = n2 % n1;
    }

    if (n1 == 0)
    {
        return n2;
    }
    else
    {
        return n1;
    }
}

int main()
{

    // print all divisors

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        std::cout << "GCD of " << n1 << " and " << n2 << " is : " << GCD_Brute(n1, n2) << std::endl;
        std::cout << "GCD of " << n1 << " and " << n2 << " is : " << GCD_Euclidean_Algorithm(n1, n2) << std::endl;
    }
    return 0;
}

/*
Ananlysis Portion and Comments:

1. Every two numbers will must have 1  as one of their factors, so it is possible that they may have 1 as their greatest common factor;

2. It is better to run the loop to run till the minimum of the two numbers to prevent exhausting the for loop  on a greater value of n since we will get our answer within the smaller loop, saving TC.

3. For Brute Force, the Time Complexity is O(min(n1,n2));

4. ALso, if youll loop (i=min(n1,n2)' i>=1;i--) the Time Complexity is still O(min(n1,n2));

5. gcd(n1,n2)= gcd(n1-n2,n2)  n1>n2 Euclidean ALgorithm

6. gcd(n1,n2)= gcd(n1%n2,n2)  n1>n2  Better Euclidean ALgorithm

7. Time Complexity of Better Euclidean ALgorithm is O(log phi (min(n1,n1)))

*/