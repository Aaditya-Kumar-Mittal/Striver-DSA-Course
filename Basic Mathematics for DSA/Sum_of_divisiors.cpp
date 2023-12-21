/*
    Time Complexity: O(n*sqrt(n))

    Space Complexity: O(1)

    Where 'n' is the given integer.
*/
#include <bits/stdc++.h>

using namespace std;

int sumOfAllDivisors(int n)
{
    int ans = 0;

    // Iterating over all 'i'.
    for (int i = 1; i <= n; i++)
    {

        // Calculating the value of ’sumOfDivisors(i)’ for current 'i'.
        for (int j = 1; j * j <= i; j++)
        {
            if (i % j == 0)
            {

                // Avoid counting sqrt(i) twice.
                if (i / j == j)
                {
                    ans += j;
                }
                else
                {
                    ans += j + i / j;
                }
            }
        }
    }

    return ans;
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long n;
        cin >> n;
        cout << "Sum of all divisors of : " << n << " is: " << sumOfAllDivisors(n) << endl;
    }

    return 0;
}