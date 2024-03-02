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
    vector<int> temp(n + m); // Temporary array to store merged elements
    int left = 0;            // Pointer for array a
    int right = 0;           // Pointer for array b
    int index = 0;           // Index of temporary array

    // Merge elements from both arrays while there are elements remaining in both arrays
    while (left < n && right < m)
    {
        if (a[left] < b[right])
        {
            temp[index++] = a[left++]; // Place smaller element from array a into temporary array
        }
        else
        {
            temp[index++] = b[right++]; // Place smaller element from array b into temporary array
        }
    }

    // Copy remaining elements from array a, if any
    while (left < n)
    {
        temp[index++] = a[left++];
    }

    // Copy remaining elements from array b, if any
    while (right < m)
    {
        temp[index++] = b[right++];
    }

    // Copy elements from temporary array back to arrays a and b
    for (int i = 0; i < (n + m); i++)
    {
        if (i < n)
        {
            a[i] = temp[i];
        }
        else
        {
            b[i - n] = temp[i];
        }
    }
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

Time Complexity: O(N + M) + O(N + M)
Reason: We iterate through both arrays twice, where N is the size of array a and M is the size of array b.

Space Complexity: O(N + M)
Reason: We use a temporary array of size N + M to store the merged elements.
*/
