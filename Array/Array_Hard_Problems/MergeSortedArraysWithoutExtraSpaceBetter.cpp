#include <bits/stdc++.h>

using namespace std;

/**
 * Function to merge two sorted arrays
 * @param n Size of array a
 * @param m Size of array b
 * @param a First sorted array
 * @param b Second sorted array
 */
void merge(int n, int m, vector<int> &a, vector<int> &b)
{
    int left = n - 1; // Pointer for array a starting from the end
    int right = 0;    // Pointer for array b starting from the beginning

    // Merge elements from both arrays until one of them is exhausted
    while (left >= 0 && right < m)
    {
        if (a[left] > b[right]) // Change comparison to '>' for swapping when element in a is greater
        {
            swap(a[left], b[right]); // Swap elements if needed
            left--;
            right++;
        }
        else
        {
            break; // Break loop if element in a is not greater than element in b
        }
    }

    // Sort both arrays after merging
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int main()
{
    int n, m;
    cin >> n >> m; // Input sizes of arrays

    // Input elements of array a
    vector<int> arr1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    // Input elements of array b
    vector<int> arr2(m);
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }

    // Print elements of array a
    cout << "Printing Array-1 Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Print elements of array b
    cout << "Printing Array-2 Elements: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    // Merge the two arrays
    merge(n, m, arr1, arr2);

    // Print elements of array a after merging
    cout << "Printing Array-1 Elements after merging: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    // Print elements of array b after merging
    cout << "Printing Array-2 Elements after merging: " << endl;
    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given two sorted arrays a and b, merge them into a single sorted array.

Time Complexity: O(N log N + M log M)
Reason: We sort both arrays after merging.

Space Complexity: O(1)
Reason: We use constant extra space.
*/
