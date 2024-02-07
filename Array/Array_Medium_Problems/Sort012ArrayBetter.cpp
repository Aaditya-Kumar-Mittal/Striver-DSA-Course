#include <bits/stdc++.h>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s
void SORT012ArrayBetter(vector<int> &a, int n)
{
    // Count the occurrences of 0s, 1s, and 2s in the array
    int count0 = 0, count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
        {
            count0++;
        }
        else if (a[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }

    // Overwrite the original array with the sorted elements
    for (int i = 0; i < count0; i++)
    {
        a[i] = 0;
    }
    for (int i = count0; i < count0 + count1; i++)
    {
        a[i] = 1;
    }
    for (int i = count0 + count1; i < n; i++)
    {
        a[i] = 2;
    }
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print original array
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the sorting function
    SORT012ArrayBetter(arr, n);

    // Print sorted array
    cout << "Printing Array Elements after 012 Sorting: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem:

Name: Sorting an array of 0s, 1s, and 2s
Time Complexity: O(2n) - Two passes through the array
Space Complexity: O(1) - Only a constant amount of extra space is used for counting variables
*/
