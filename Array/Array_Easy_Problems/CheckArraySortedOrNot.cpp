/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>

using namespace std;

// Check if Array is sorted in non-descending order or not

bool CHECKSORT(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] >= a[i - 1])
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{

    int n;

    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    std::cout << "Printing Array Elements: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    std::cout << "Array is sorted or not? :" << CHECKSORT(arr, n) << std::endl;

    return 0;
}