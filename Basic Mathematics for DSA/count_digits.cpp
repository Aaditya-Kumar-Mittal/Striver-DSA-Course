#include <bits/stdc++.h>

using namespace std;

int count_digits(int n)
{

    // Approach 1
    /*
    int count = 0;

    while (n > 0)
    {
        int l = n % 10;
        count++;
        n /= 10;
    }
    */

    // Approach 2
    int count = (int)log10(n) + 1;

    return count;
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        cout << "Number of digits in " << n << " is: " << count_digits(n) << endl;
    }

    return 0;
}