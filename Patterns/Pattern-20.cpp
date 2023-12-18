#include <iostream>
using namespace std;

void pattern20(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        for (int j = 2 * (n - i - 1); j > 0; j--)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    for (int i = 1; i < n ; i++)
    {
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << '*';
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= n - i - 1; j++)
        {
            cout << '*';
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
        pattern20(n);
        cout << endl;
    }

    return 0;
}