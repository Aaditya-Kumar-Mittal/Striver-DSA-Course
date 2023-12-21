#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    else
    {
        long int temp = x;
        long int ans = 0;

        while (temp > 0)
        {
            int last = temp % 10;
            ans = ans * 10 + last;
            temp /= 10;
        }

        return ans == x;
    }
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long n;
        cin >> n;
        cout << n << " is a Palindrome: " << isPalindrome(n) << endl;
    }

    return 0;
}