#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Function to find the insertion position of a target element in a sorted array
 * @param a The sorted array
 * @param n The size of the array
 * @param x The target element to be inserted
 * @return The insertion position of the target element
 */
int searchInsertionPosition(vector<int> &a, int n, int x)
{
    // Finding the lower bound position for insertion
    int low = 0, high = n - 1, mid, ans = n;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (a[mid] >= x)
        {
            ans = mid;      // Update the answer to the current mid
            high = mid - 1; // Move to the left half
        }
        else
        {
            low = mid + 1; // Move to the right half
        }
    }
    return ans; // Return the insertion position
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

    // Perform binary search to find the insertion position
    int insertionPosition = searchInsertionPosition(array, n, target);
    cout << "Position of " << target << " to be inserted in the array while maintaining the sorted array is : " << insertionPosition << " using function" << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement:
Given a sorted array, find the insertion position of a target element while maintaining the sorted order.

Time Complexity:
The time complexity of this algorithm is O(log n) as it performs binary search to find the insertion position.

Space Complexity:
The space complexity is O(1) as the algorithm uses only a constant amount of extra space.
*/
