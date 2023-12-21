#include <bits/stdc++.h>

using namespace std;

bool checkArmstrong(int n)
{

    int temp = n;
    int org = n;

    string num = to_string(n);
    int len = num.length();

    int ans = 0;

    while (temp > 0)
    {
        int last = temp % 10;
        ans += last * len;
        temp /= 10;
    }

    return org == ans;
}

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        long n;
        cin >> n;
        cout << n << " is an Armstrong: " << checkArmstrong(n) << endl;
    }

    return 0;
}