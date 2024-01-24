#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i <= j)
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
    if (low < high)
    {
        int pIndex = partition(a, low, high);
        quickSort(a, low, pIndex - 1);
        quickSort(a, pIndex + 1, high);
    }
}

void SORT(vector<int> &a, int n)
{
    quickSort(a, 0, n - 1);
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

    cout << "Array before SORTING:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    SORT(arr, n);

    cout << "Array after SORTING:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
