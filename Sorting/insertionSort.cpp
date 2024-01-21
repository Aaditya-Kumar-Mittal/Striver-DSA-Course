#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &a, int n)
{

    /*
    - Take an element an place it in correct order.
    - O(N^2) is the time complexity for the worst and average cases
    - O(N) is the time complexity for the best case
    */

    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;

        while (j > 0 && a[j - 1] > a[j])
        {
            swap(a[j], a[j - 1]);
            j--;
        }
    }
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

    cout << "Array before SORTING: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    insertionSort(arr, n);

    cout << "Array after SORTING: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
