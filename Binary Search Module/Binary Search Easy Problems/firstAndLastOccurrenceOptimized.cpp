/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Function to find the lower bound of an element in a sorted array
 * @param a The sorted array
 * @param n The size of the array
 * @param k The target element
 * @return The index of the first occurrence of an element greater than or equal to k
 */
int lowerBound(vector<int> a, int n, int k) {
    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] >= k) {
            ans = mid; // Update lower bound index
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

/**
 * @brief Function to find the upper bound of an element in a sorted array
 * @param a The sorted array
 * @param n The size of the array
 * @param k The target element
 * @return The index of the first occurrence of an element strictly greater than k
 */
int upperBound(vector<int> a, int n, int k) {
    int low = 0, high = n - 1, ans = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (a[mid] > k) {
            ans = mid; // Update upper bound index
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

/**
 * @brief Function to find the first and last occurrence of an element in a sorted array
 * @param a The sorted array
 * @param n The size of the array
 * @param element The target element
 * @return A pair containing the indices of the first and last occurrence of the element
 */
pair<int, int> firstAndLastOccurrenceOptimized(vector<int> a, int n, int element) {
    int lb = lowerBound(a, n, element);

    // If element not found, return {-1, -1}
    //If element is not in the given array, lowerBound points to the next greater which is wrong
    //If search reaches end, then lowerBound will point to an index out of array, which is hypothetical.
    if (lb == -1 || a[lb] != element) {
        return {-1, -1};
    }

    // Find upper bound for the last occurrence
    int ub = upperBound(a, n, element);

    return {lb, ub - 1}; // Return pair of indices
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

    // Find the first and last occurrence of the target element
    pair<int, int> ans = firstAndLastOccurrenceOptimized(array, n, target);
    if (ans.first != -1 && ans.second != -1) {
        cout << "The first and the last occurrence of " << target << " in the given array is : " << ans.first << " and " << ans.second << endl;
    } else {
        cout << "The element " << target << " is not found in the array" << endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: First and Last Occurrence of an Element in a Sorted Array

Time Complexity: O(2 * log n)
The optimized binary search approach has a time complexity of O(log n) as it performs two binary searches to find the lower and upper bounds of the target element.

Space Complexity: O(1)
The space complexity is constant as the algorithm uses only a fixed amount of extra space regardless of the input size.
*/
