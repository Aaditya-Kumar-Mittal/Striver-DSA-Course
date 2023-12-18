#include <iostream>
using namespace std;

void pattern13(int n)
{
    int start = 1;
    for (int i = 0; i < n; i++)
    {
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
        pattern13(n);
        cout << endl;
    }

    return 0;
}