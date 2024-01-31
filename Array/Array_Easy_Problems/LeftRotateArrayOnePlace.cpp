/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void RotateElementsOnePlace(vector<int> &a, int n)
{
    int temp = a[0];
    for (int i = 1; i < n; i++)
    {
        a[i - 1] = a[i];
    }

    a[n - 1] = temp;
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

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    RotateElementsOnePlace(arr, n);

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Name:- Rotate Array By one place
Time Complexity:- O(N)
Space Complexity:- O(1) storing the first element

*/