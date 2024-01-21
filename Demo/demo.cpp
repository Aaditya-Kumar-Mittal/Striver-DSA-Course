#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &vec, int size)
{
    /*
    - Select the minimum and then swap
    - Time Complexity for all the cases is O(N^2)
    */

    for (int i = 0; i <= size - 2; i++)
    {
        int minIndex = i;

        for (int j = i; j <= size - 1; j++)
        {
            if (vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }
        swap(vec[minIndex], vec[i]);
    }
}

void bubbleSort(vector<int> &a, int n)
{

    for (int i = n - 1; i >= 1; i--)
    {
        int didRun = 0;
        for (int j = 0; j <= i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                didRun = 1;
            }
        }
        if (didRun == 0)
        {
            break;
        }
        cout << "Run" << endl;
    }
}

void insertionSort(vector<int> &a, int n)
{
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
