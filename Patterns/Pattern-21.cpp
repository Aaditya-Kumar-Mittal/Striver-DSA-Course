#include <iostream>
using namespace std;

void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || i == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << '*';
            }
        }
        else
        {
            cout << '*';
            for (int j = 0; j < n - 2; j++)
            {
                cout << " ";
            }
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
        pattern21(n);
        cout << endl;
    }

    return 0;
}