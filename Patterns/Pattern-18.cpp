#include <iostream>
using namespace std;

void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char start = 'A' + n - i - 1;
        for (int j = 1; j <= i + 1; j++)
        {
            cout << start << " ";
            start += 1;
        }

        cout << endl;
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
        pattern16(n);
        cout << endl;
    }

    return 0;
}