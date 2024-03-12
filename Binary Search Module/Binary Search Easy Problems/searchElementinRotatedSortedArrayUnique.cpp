#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Searches for an element in a unique rotated sorted array using binary search.
 *
 * @param a The rotated sorted array.
 * @param n The size of the array.
 * @param k The target element to search for.
 * @return The index of the target element if found, otherwise -1.
 */
int searchElementInUniqueRotatedSortedArray(vector<int> a, int n, int k)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] == k)
        {
            return mid; // Element found
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

    return -1; // Element not found
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

    int result = searchElementInUniqueRotatedSortedArray(array, n, target);
    if (result != -1)
    {
        cout << "Element found in the array at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}

/*

Analysis of Problem

Name: Search Element in Unique Rotated Sorted Array

Time Complexity:
- The time complexity of binary search is O(log n), where n is the size of the array.

Space Complexity:
- The space complexity is O(1) because we use only a constant amount of extra space regardless of the input size.

*/