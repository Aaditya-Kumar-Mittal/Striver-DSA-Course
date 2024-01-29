/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>

using namespace std;

// Second Largest and Smallest Element in an Array

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (i <= high && a[i] <= pivot)
        {
            i++;
        }

        while (j >= low && a[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(a[i], a[j]);
        }
    }
    swap(a[low], a[j]);
    return j;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low >= high)
        return;

    int pIndex = partition(a, low, high);
    quickSort(a, low, pIndex - 1);
    quickSort(a, pIndex + 1, high);
}

int BRUTE_FORCE_APPROACH(vector<int> &a, int n)
{
    // Sort the array using quick sort since it takes TC:- Nlog N and SC is O(1)

    quickSort(a, 0, n - 1);

    int largest = a[n - 1];
    int slargest = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] != largest)
        {
            slargest = a[i];
            break;
        }
    }

    return slargest;
}

int BETTER_APPROACH(vector<int> &a, int n)
{
    int largest = a[0];

    for (int i = 1; i < n; i++)
    {
        largest = max(largest, a[i]);
    }

    int slargest = -1;

    for (int i = 0; i < n; i++)
    {
        if (a[i] != largest && a[i] > slargest)
        {
            slargest = a[i];
        }
    }

    return slargest;
}

int OPTIMIZED_APPROACH(vector<int> &a, int n)
{
    int largest = a[0];
    int slargest = -1;

    for (int i = 1; i < n; i++)
    {
        if (a[i] > largest)
        {
            slargest = largest;
            largest = a[i];
        }
        else if (a[i] != largest && a[i > slargest])
        {
            slargest = a[i];
        }
    }

    return slargest;
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

    /*
    - BRUTE FORCE APPROACH
    - TC total = O(N log N) + O(N)
    */

    cout << "Second largest element in the given array using brute force apporach: " << BRUTE_FORCE_APPROACH(arr, n) << endl;

    /* Better Approach TC- O(2N) ~ O(N) */
    cout << "Second largest element in the given array using better apporach: " << BETTER_APPROACH(arr, n) << endl;

    /*Optimized Approach TC- O(N)*/
    cout << "Second largest element in the given array using OPTIMIZED apporach: " << OPTIMIZED_APPROACH(arr, n) << endl;

    return 0;
}