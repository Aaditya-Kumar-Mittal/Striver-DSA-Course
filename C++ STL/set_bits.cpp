#include <bits/stdc++.h>
using namespace std;

int count_setbits(int N)
{
    int cnt = 0;

    while (N > 0)
    {
        cnt += (N & 1);
        N = N >> 1;
    }

    return cnt;
}

int main()
{

    cout << "To find out set bits using the user defined function: " << count_setbits(7) << endl;

    std::cout << "To find out set bits using the __builtin_popcount functions: " << __builtin_popcount(7) << std::endl;

    long long n = 77777777777777;

    cout << "To find out set bits of long long int using the __builtin_popcountll functions: " << __builtin_popcountll(n);

    return 0;
}