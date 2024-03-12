/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Function to find the first occurrence of an element in a sorted array
 * @param a The sorted array
 * @param n The size of the array
 * @param element The target element
 * @return The index of the first occurrence of the element, or -1 if not found
 */
int firstOccurrence(vector<int> a, int n, int element)
{
    int low = 0, high = n - 1, first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == element)
        {
            first = mid; // Update first occurrence index
            high = mid - 1;
        }
        else if (a[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return first; // Verify if found element is equal to target
}

/**
 * @brief Function to find the last occurrence of an element in a sorted array
 * @param a The sorted array
 * @param n The size of the array
 * @param element The target element
 * @return The index of the last occurrence of the element, or -1 if not found
 */
int lastOccurrence(vector<int> a, int n, int element)
{
    int low = 0, high = n - 1, last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == element)
        {
            last = mid; // Update last occurrence index
            low = mid + 1;
        }
        else if (a[mid] < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return last;
}

pair<int, int> firstAndLastPosition(vector<int> &arr, int n, int k)
{
    int first = firstOccurrence(arr, n, k);
    if (first == -1)
        return {-1, -1};
    int last = lastOccurrence(arr, n, k);
    return {first, last};
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

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

    // Find the first and last occurrence of the target element
    pair<int, int> ans = firstAndLastPosition(array, n, target);
    cout << "The first and the last occurrence of " << target << " in the given array is : " << ans.first << " and " << ans.second << endl;

    return 0;
}

/*
Analysis of Problem

Name: First and Last Occurrence of an Element in a Sorted Array

Time Complexity: O(2 * log n)
Both functions use binary search, which has a time complexity of O(log n) in the worst case scenario.

Space Complexity: O(1)
The space complexity is constant as the algorithms use only a fixed amount of extra space regardless of the input size.
*/
