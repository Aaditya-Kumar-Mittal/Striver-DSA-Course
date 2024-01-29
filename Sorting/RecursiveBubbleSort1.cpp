#include <bits/stdc++.h>
using namespace std;

void recursiveBubbleSort(vector<int> &a, int n)
{
    if (n == 1)
        return;

    for (int j = 0; j <= n - 2; j++)
    {
        if (a[j] > a[j + 1])
        {
            swap(a[j], a[j + 1]);
        }
    }

    recursiveBubbleSort(a, n - 1);
}
void SORT(vector<int> &a, int n)
{
    recursiveBubbleSort(a, n);
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
