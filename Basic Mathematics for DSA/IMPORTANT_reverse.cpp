/* Question is Return a decimal number after reversing the binary representation of a given decimal number*/
#include <bits/stdc++.h>

using namespace std;

long reverseBits(long n)
{
    // Write your code here.
    long ans = 0;
    int bit = 31;

    while (n > 0)
    {
        int l = n % 2;
        ans += pow(2, bit) * l;
        bit--;
        n /= 2;
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
        cout << "Reverse of " << n << " is: " << reverseBits(n) << endl;
    }

    return 0;
}