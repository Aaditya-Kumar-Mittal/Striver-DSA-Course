#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &a, int n)
{

    /*
    - Push the max element to the last
    - O(N^2) is the time complexity for the worst and average cases
    - O(N) is the time complexity for the best case
    */
   
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

    bubbleSort(arr, n);

    cout << "Array after SORTING: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
