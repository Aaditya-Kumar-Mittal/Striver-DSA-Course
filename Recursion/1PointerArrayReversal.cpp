/*
Aaditya Mittal - My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    swap(arr[start], arr[end]);
    reverseArray(arr, start + 1, end - 1);
}

int main()
{
    // Input the size of the array
    int n;
    cin >> n;

    // Create a vector to store the array elements
    vector<int> arr(n);

    // Input the array elements
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Display the array before reversal
    cout << "Array before Reversal: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    reverseArray(arr, 0, n - 1);

    // Display the array after reversal
    cout << "Array after Reversal: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis Portion and Comments:

*/
