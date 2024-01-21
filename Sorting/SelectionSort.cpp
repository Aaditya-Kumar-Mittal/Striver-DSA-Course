#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &vec, int size)
{
    // Select the minimum and swap

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

    selectionSort(arr, n);

    cout << "Array after SORTING: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
