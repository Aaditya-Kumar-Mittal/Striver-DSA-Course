#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the index of the first occurrence of an element in a sorted array.
 *
 * @param a The sorted array.
 * @param n The size of the array.
 * @param element The target element to search for.
 * @return The index of the first occurrence of the element, or -1 if not found.
 */
int firstOccurrence(vector<int> a, int n, int element)
{
    int low = 0, high = n - 1, first = -1;

    // Binary search loop
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If the middle element is equal to the target element
        if (a[mid] == element)
        {
            first = mid;    // Update the index of the first occurrence
            high = mid - 1; // Continue searching in the left half
        }
        // If the middle element is less than the target element
        else if (a[mid] < element)
        {
            low = mid + 1; // Search in the right half
        }
        // If the middle element is greater than the target element
        else
        {
            high = mid - 1; // Search in the left half
        }
    }

    return first; // Return the index of the first occurrence
}

/**
 * @brief Finds the index of the last occurrence of an element in a sorted array.
 *
 * @param a The sorted array.
 * @param n The size of the array.
 * @param element The target element to search for.
 * @return The index of the last occurrence of the element, or -1 if not found.
 */
int lastOccurrence(vector<int> a, int n, int element)
{
    int low = 0, high = n - 1, last = -1;

    // Binary search loop
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        // If the middle element is equal to the target element
        if (a[mid] == element)
        {
            last = mid;    // Update the index of the last occurrence
            low = mid + 1; // Continue searching in the right half
        }
        // If the middle element is less than the target element
        else if (a[mid] < element)
        {
            low = mid + 1; // Search in the right half
        }
        // If the middle element is greater than the target element
        else
        {
            high = mid - 1; // Search in the left half
        }
    }

    return last; // Return the index of the last occurrence
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

    // Find the first and last occurrence of the target
    int first = firstOccurrence(array, n, target);
    int last = lastOccurrence(array, n, target);

    if (first != -1)
    {
        // If the target is found, calculate the count
        int count = last - first + 1;
        cout << "The first and the last occurrence of " << target << " in the given array is: " << first << " and " << last << endl;
        cout << "The count of " << target << " in the given array is: " << count << endl;
    }
    else
    {
        // If the target is not found
        cout << "The element " << target << " is not found in the array." << endl;
    }

    return 0;
}

/*

Analysis of Problem

Name: Count of Target in Sorted Array

Time Complexity:
- The time complexity of the binary search algorithm is O(log n), where n is the number of elements in the array.
- Since we perform binary search twice (for finding the first and last occurrences), the overall time complexity is O(log n).

Space Complexity:
- The space complexity is O(1) because we use a constant amount of extra space regardless of the input size.

*/
