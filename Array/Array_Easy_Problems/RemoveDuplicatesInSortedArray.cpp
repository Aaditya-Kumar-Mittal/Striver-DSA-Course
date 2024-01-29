/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to check if the array is sorted
bool CHECKSORT(vector<int> &a, int n)
{
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }
    return true;
}

// Remove duplicates from sorted array using set
int brute_approach(vector<int> &a, int n)
{
    set<int> mySet;
    int index = 0;

    for (int i = 0; i < n; i++)
    {
        if (!i || a[i] != a[i - 1])
        {
            a[index++] = a[i];
        }
    }

    return index;
}

// Remove duplicates from sorted array using two pointers
int best_approach(vector<int> &a, int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }

    int index = 0;

    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[index])
        {
            a[index++] = a[i];
        }
    }

    return index - 1;
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

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Array is sorted or not? :" << CHECKSORT(arr, n) << endl;

    cout << "Removing duplicates in sorted array using the brute force approach and returning the array size: " << brute_approach(arr, n) << endl;

    cout << "Removing duplicates in sorted array using the best approach and returning the array size: " << best_approach(arr, n) << endl;

    return 0;
}
