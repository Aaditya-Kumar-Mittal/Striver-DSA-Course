#include <iostream>
using namespace std;

void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        char start = 'A';
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
        pattern14(n);
        cout << endl;
    }

    return 0;
}