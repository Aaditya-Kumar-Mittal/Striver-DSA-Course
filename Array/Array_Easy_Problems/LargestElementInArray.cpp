#include <bits/stdc++.h>

using namespace std;

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
    if (low < high)
    {
        int pIndex = partition(a, low, high);
        quickSort(a, low, pIndex - 1);
        quickSort(a, pIndex + 1, high);
    }
}

int CompareLargest(vector<int> &a, int n)
{
    int largest = a[0];

    for (int i = 0; i < n; i++)
    {
        largest = max(largest, a[i]);
    }

    return largest;
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

    /* Method-1 sort the element and print the last
    - Using quickSort TC NlogN and Space Complexity is O(1)*/
    /*
    quickSort(arr, 0, n - 1);

    std::cout << "Printing Array Elements: " << std::endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Printing the largest element using sorting: " << arr[n - 1] << endl;

    /*

    /*Method-2 Use a pointer to compare the elements and return the largest at last
    - TC O(N) SC - O(1) */

    cout << "Printing the largest element using Pointer Comparison: " << CompareLargest(arr, n) << endl;

    cout << "Printing the largest element using max STL: " << *max_element(arr.begin(), arr.end()) << endl;

    return 0;
}