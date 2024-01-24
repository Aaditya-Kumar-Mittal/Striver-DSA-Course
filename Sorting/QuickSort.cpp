#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high)
{
    int pivot = a[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        // moment it crosses the left and right have already been separated in greater and lesser sides
        while (a[i] <= pivot && i <= high)
        {
            i++;
            /*
            - Find an element greater than pivot
            - Once found it is marked by index i for swapping
            - i<= high for it should not go out of array
            - a[i]<=a[pivot] once this becomes false, greater element has been found till then i keeps increasing.
            */
        }

        while (a[j] > pivot && j >= low)
        {
            j--;
            /*
            - Find an element lesser than pivot
            - Once found it is marked by index j for swapping
            - j>=low for it should not go out of array while decreasing
            - a[j]>=a[pivot] once this becomes false, lesser element has been found till then j keeps decrementing.
            */
        }

        if (i < j)
        {
            // Both have been marked swap em
            swap(a[i], a[j]);
        }
    }

    swap(a[low], a[j]); // To bring the pivot to the right position.
    return j;
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        // if low==high it means only 1 element, so it is already sorted
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
