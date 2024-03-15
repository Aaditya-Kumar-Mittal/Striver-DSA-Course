/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Searches for the single element in a sorted array where all other elements appear exactly twice.
 * @param a The sorted array.
 * @param n The size of the array.
 * @return The single element in the array.
 */
int searchSingleElementInSortedArray(vector<int> a, int n)
{
    if (n == 1)
        return a[0];

    if (a[0] != a[1])
        return a[0];
    if (a[n - 1] != a[n - 2])
        return a[n - 1];

    int low = 1, high = n - 2;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[mid] != a[mid + 1] && a[mid] != a[mid - 1])
        {
            return a[mid];
        }

        if ((mid % 2 == 1 && a[mid - 1] == a[mid]) || (mid % 2 == 0 && a[mid + 1] == a[mid]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1; // Corrected from high = mid + 1 to high = mid - 1
        }
    }

    // If no single element is found (shouldn't reach here for valid inputs)
    return -1;
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

    cout << "Single Element in Sorted Array: " << searchSingleElementInSortedArray(array, n) << endl;
}

/*

Analysis of Problem

Name: Finding the single element in a sorted array where all other elements appear exactly twice

Time Complexity: O(log n) where n is the number of elements in the array. Binary search is employed to find the single element.

Space Complexity: O(1). The algorithm uses only a constant amount of extra space for variables regardless of the size of the input array.

*/
