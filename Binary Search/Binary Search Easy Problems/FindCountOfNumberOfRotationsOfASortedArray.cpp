/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the index of the minimum element in a rotated sorted array with unique elements.
 * @param a The rotated sorted array.
 * @param n The size of the array.
 * @return The index of the minimum element in the array.
 */
int findCountOfRotationsOfUniqueRotatedSortedArray(vector<int> a, int n)
{
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;

    // Binary search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[low] <= a[high])
        {
            // Search space is already sorted
            // Minimum element is always a[low]
            if (a[low] < ans)
            {
                index = low;
                ans = a[low];
            }
            break;
        }

        if (a[low] <= a[mid])
        {
            // Left half is sorted
            if (a[low] < ans)
            {
                index = low;
                ans = a[low];
            }
            low = mid + 1;
        }
        else
        {
            // Right half is sorted
            if (a[mid] < ans)
            {
                index = mid;
                ans = a[mid];
            }
            high = mid - 1;
        }
    }

    return index;
}

/**
 * @brief Finds the index of the minimum element in a rotated sorted array with unique elements.
 * This function is named differently for comparison purposes.
 * @param arr The rotated sorted array.
 * @return The index of the minimum element in the array.
 */
int findKRotation(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high) {
        int mid = (low + high) / 2;
        //search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if (arr[low] <= arr[high]) {
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }
            break;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            if (arr[low] < ans) {
                index = low;
                ans = arr[low];
            }

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            if (arr[mid] < ans) {
                index = mid;
                ans = arr[mid];
            }

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return index;
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

    cout << "Count of Rotations in Rotated Sorted Array with Unique Elements is: " << findCountOfRotationsOfUniqueRotatedSortedArray(array, n) << endl;
    cout << "Count of Rotations in Rotated Sorted Array with Unique Elements (Alternative Function) is: " << findKRotation(array) << endl;
}

/*

Analysis of Problem

Name: Finding the index of the minimum element in a rotated sorted array with unique elements

Time Complexity: O(log n) where n is the number of elements in the array. Binary search is employed to find the index of the minimum element.

Space Complexity: O(1). The algorithm uses only a constant amount of extra space for variables regardless of the size of the input array.

*/
