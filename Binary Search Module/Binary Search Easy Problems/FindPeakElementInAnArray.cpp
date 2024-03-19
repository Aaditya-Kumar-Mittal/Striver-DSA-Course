#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Finds the peak element in an array using brute force.
 * @param a The array.
 * @param n The size of the array.
 * @return The index of the peak element.
 */
int FindPeakElementBrute(vector<int> a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if ((i == 0 || a[i - 1] < a[i]) && (i == n - 1 || a[i + 1] < a[i]))
        {
            return i;
        }
    }
    return -1; // Return -1 if no peak element found (shouldn't happen for valid inputs)
}

/**
 * @brief Finds the peak element in an array using binary search.
 * @param a The array.
 * @param n The size of the array.
 * @return The index of the peak element.
 */
int FindPeakElementBinarySearch(vector<int> a, int n)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if ((mid == 0 || a[mid - 1] < a[mid]) && (mid == n - 1 || a[mid + 1] < a[mid]))
        {
            return mid;
        }
        else if (mid > 0 && a[mid - 1] > a[mid]) // Move left if the element to the left is greater
        {
            high = mid - 1;
        }
        else // Move right if the element to the right is greater or equal
        {
            low = mid + 1;
        }
    }
    return -1; // Return -1 if no peak element found (shouldn't happen for valid inputs)
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

    int index = FindPeakElementBrute(array, n);
    int index1 = FindPeakElementBinarySearch(array, n);
    cout << "The Peak Element in the array using brute force is: " << array[index] << endl;
    cout << "The Peak Element in the array using binary search is: " << array[index1] << endl;

    return 0;
}

/*

Analysis of Problem

Name: Finding the peak element in an array

Time Complexity:
    - Brute Force: O(n), where n is the number of elements in the array. In the worst case, it requires scanning the entire array.
    - Binary Search: O(log n), where n is the number of elements in the array. Binary search is employed to find the peak element.

Space Complexity: O(1). The algorithms use only a constant amount of extra space for variables regardless of the size of the input array.

*/