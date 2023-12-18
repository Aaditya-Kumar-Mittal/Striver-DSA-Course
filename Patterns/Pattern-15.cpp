#include <iostream>
using namespace std;

void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        char start = 'A';
        for (int j = n - i - 1; j >= 0; j--)
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
        pattern15(n);
        cout << endl;
    }

    return 0;
}