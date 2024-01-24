#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int low, int mid, int high)
{
    // Use vector constructor to copy the elements
    vector<int> temp(a.begin() + low, a.begin() + high + 1);

    int left = 0;
    int right = mid - low + 1;
    int index = low;

    while (left <= mid - low && right <= high - low)
    {
        if (temp[left] <= temp[right])
        {
            a[index++] = temp[left++];
        }
        else
        {
            a[index++] = temp[right++];
        }
    }

    // Copy the remaining elements from the left subarray
    while (left <= mid - low)
    {
        a[index++] = temp[left++];
    }
}

void mergeSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;

        mergeSort(a, low, mid);
        mergeSort(a, mid + 1, high);

        merge(a, low, mid, high);
    }
}

void SORT(vector<int> &a)
{
    mergeSort(a, 0, a.size() - 1);
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

    cout << "Array before SORTING: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    SORT(arr);

    cout << "Array after SORTING: ";
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
