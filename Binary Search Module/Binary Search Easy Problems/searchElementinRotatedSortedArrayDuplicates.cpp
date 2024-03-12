#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Searches for an element in a duplicate rotated sorted array using binary search.
 *
 * @param a The rotated sorted array.
 * @param n The size of the array.
 * @param k The target element to search for.
 * @return True if the element is found, otherwise false.
 */
bool searchElementInDuplicateRotatedSortedArray(vector<int> a, int n, int k)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == k)
        {
            return true; // Element found
        }

        // Handle duplicates at the start, middle, and end of the array
        if (a[low] == a[mid] && a[mid] == a[high])
        {
            low++;
            high--;
            continue;
        }

        // Check if left half is sorted
        if (a[low] <= a[mid])
        {
            if (a[low] <= k && k <= a[mid])
            {
                high = mid - 1; // Search in the left half
            }
            else
            {
                low = mid + 1; // Search in the right half
            }
        }
        else // Right half is sorted
        {
            if (a[mid] <= k && k <= a[high])
            {
                low = mid + 1; // Search in the right half
            }
            else
            {
                high = mid - 1; // Search in the left half
            }
        }
    }

    return false; // Element not found
}

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    int target;
    cin >> target;

    if (searchElementInDuplicateRotatedSortedArray(array, n, target))
    {
        cout << "Element found in the array." << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

/*

Analysis of Problem

Name: Search Element in Duplicate Rotated Sorted Array

Time Complexity:
- The time complexity for average case is O(log n), where n is the size of the array.
- The time complexity for worst case is O(n/2), where n is the size of the array, may trim down the array to half.

Space Complexity:
- The space complexity is O(1) because we use only a constant amount of extra space regardless of the input size.

*/