#include <bits/stdc++.h>
//My code was almost correct but missed the idea of static_cast<long>
using namespace std;

int Reversal(int n)
{

    long int ans = 0;
    long int temp;

    if (n < 0)
    {
        temp = -static_cast<long>(n); // Convert to long to avoid type mismatch
    }
    else
    {
        temp = static_cast<long>(n); // Convert to long to avoid type mismatch
    }

    while (temp > 0)
    {
        int last = temp % 10;
        ans = ans * 10 + last;

        // Check for overflow before updating temp
        if (ans < INT_MIN || ans > INT_MAX)
        {
            return 0;
        }

        temp /= 10;
    }

    if (n < 0)
    {
        return -static_cast<int>(ans); // Convert back to int
    }
    else
    {
        return static_cast<int>(ans); // Convert back to int
    }
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << "Reverse of " << n << " is: " << Reversal(n) << endl;
    }

    return 0;
}