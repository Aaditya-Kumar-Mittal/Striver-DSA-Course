/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

// Iterative Binary Search Function
int binarySearchIterative(vector<int> &a, int n, int x)
{
    int low = 0, high = n - 1, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}

// Recursive Binary Search Function
int binarySearchRecursive(vector<int> &a, int low, int high, int x)
{
    if (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == x)
        {
            return mid;
        }
        else if (a[mid] > x)
        {
            return binarySearchRecursive(a, low, mid - 1, x);
        }
        else
        {
            return binarySearchRecursive(a, mid + 1, high, x);
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n; // Input size of the array

    // Input elements of the array
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // Print the array elements
    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // Input the target element to search for
    int target;
    cin >> target;

    // Perform iterative binary search
    int binarySearchIndex = binarySearchIterative(array, n, target);
    cout << target << " element found at index : " << binarySearchIndex << " (Iterative)" << endl;

    // Perform recursive binary search
    int binarySearchIndex2 = binarySearchRecursive(array, 0, n - 1, target);
    cout << target << " element found at index : " << binarySearchIndex2 << " (Recursive)" << endl;

    // Using STL binary_search function 1 means true and 0 means false
    cout << target << " element found at index : " << binary_search(array.begin(), array.end(), target) << " (STL)" << endl;

    return 0;
}

/*

Analysis of Problem

Problem Statement: Given a sorted array of integers and a target element, perform binary search to find the index of the target element in the array.

Time Complexity: O(log N)
Reason: Binary search reduces the search space by half at each step.

Space Complexity: O(1)
Reason: Only a constant amount of extra space is used for variables.

*/
