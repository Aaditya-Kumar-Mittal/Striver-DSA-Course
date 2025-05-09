/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the minimum element in a rotated sorted array with unique elements.
 * @param a The rotated sorted array.
 * @param n The size of the array.
 * @return The minimum element in the array.
 */
int minimuminUniqueRotatedSortedArray(vector<int> a, int n)
{
    int low = 0, high = n - 1;
    int ans = INT_MAX;

    // Binary search
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (a[low] <= a[high])
        {
            // Search space is already sorted
            // Minimum element is always a[low]
            ans = min(a[low], ans);
            break;
        }

        if (a[low] <= a[mid])
        {
            // Left half is sorted, minimum may be in the right half
            ans = min(ans, a[low]);
            low = mid + 1;
        }
        else
        {
            // Right half is sorted, minimum may be in the left half
            ans = min(ans, a[mid]);
            high = mid - 1;
        }
    }

    return ans;
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

    cout << "Minimum Element in Rotated Sorted Array with Unique Elements is: " << minimuminUniqueRotatedSortedArray(array, n) << endl;
}

/*

Analysis of Problem

Name: Finding minimum element in a rotated sorted array with unique elements

Time Complexity: O(log n) where n is the number of elements in the array. Binary search is employed to find the minimum element.

Space Complexity: O(1). The algorithm uses only a constant amount of extra space for variables regardless of the size of the input array.

*/
