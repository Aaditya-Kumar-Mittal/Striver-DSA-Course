/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Function to find the largest element in the array that is less than or equal to the target
 * @param a The sorted array
 * @param n The size of the array
 * @param x The target element
 * @return The index of the floor element in the array
 */
int floorUsingBinarySearch(vector<int> &a, int n, int x) {
    // Finding the lower bound
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] <= x) {
            ans = mid; // Update answer to current mid
            low = mid + 1; // Move to the right half
        } else {
            high = mid - 1; // Move to the left half
        }
    }
    return ans; // Return the index of the floor element
}

/**
 * @brief Function to find the smallest element in the array that is greater than or equal to the target
 * @param a The sorted array
 * @param n The size of the array
 * @param x The target element
 * @return The index of the ceil element in the array
 */
int ceilUsingBinarySearch(vector<int> &a, int n, int x) {
    // Finding the upper bound
    int low = 0, high = n - 1, ans = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] >= x) {
            ans = mid; // Update answer to current mid
            high = mid - 1; // Move to the left half
        } else {
            low = mid + 1; // Move to the right half
        }
    }
    return ans; // Return the index of the ceil element
}

int main() {
    // Input size of the array
    int n;
    cin >> n;

    // Input elements of the array
    vector<int> array(n);
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    // Print the array elements
    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    // Input the target element to search for
    int target;
    cin >> target;

    // Perform binary search to find the floor and ceil elements
    int floorTarget = floorUsingBinarySearch(array, n, target);
    if (floorTarget != -1) {
        cout << "Floor of " << target << " in the array is : " << array[floorTarget] << " using function" << endl;
    } else {
        cout << "There is no floor element for " << target << " in the array" << endl;
    }
    int ceilTarget = ceilUsingBinarySearch(array, n, target);
    if (ceilTarget != -1) {
        cout << "Ceil of " << target << " in the array is : " << array[ceilTarget] << " using function" << endl;
    } else {
        cout << "There is no ceil element for " << target << " in the array" << endl;
    }

    return 0;
}

/*
Analysis of Problem

Problem Statement:
Given a sorted array, find the largest element that is less than or equal to the target (floor) and the smallest element that is greater than or equal to the target (ceil).

Time Complexity:
The time complexity of both functions is O(log n) as they perform binary search to find the floor and ceil elements.

Space Complexity:
The space complexity is O(1) as the algorithms use only a constant amount of extra space.
*/