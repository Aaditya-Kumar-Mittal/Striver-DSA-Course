#include <iostream>
using namespace std;

void pattern16(int n)
{
    char start = 'A';
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i + 1; j++)
        {
            cout << start << " ";
        }
        start += 1;

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