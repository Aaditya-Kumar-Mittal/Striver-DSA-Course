#include <bits/stdc++.h>

using namespace std;

// Function to merge two sorted subarrays and count inversions
// Parameters:
// arr: The input array
// low: Starting index of the first subarray
// mid: Ending index of the first subarray, mid+1 being the starting index of the second subarray
// high: Ending index of the second subarray
// Returns: Number of inversions between the two subarrays
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // Temporary array to store merged subarrays
    int left = low;      // Pointer for the left subarray
    int right = mid + 1; // Pointer for the right subarray

    // Modification 1: Count variable to count the inversions
    int count = 0;

    // Merge the two subarrays while counting inversions
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]); // Append element from left subarray to temp
            left++;
        }
        else
        {
            temp.push_back(arr[right]); // Append element from right subarray to temp
            count += (mid - left + 1);  // Count inversions
            right++;
        }
    }

    // Copy remaining elements from left subarray to temp
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // Copy remaining elements from right subarray to temp
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // Copy merged elements from temp back to original array
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return count; // Return inversion count
}

// Recursive function to perform merge sort and count inversions
// Parameters:
// arr: The input array
// low: Starting index of the array/subarray
// high: Ending index of the array/subarray
// Returns: Number of inversions in the array/subarray
int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0; // Initialize inversion count
    if (low < high)
    {
        int mid = low + (high - low) / 2; // Calculate the midpoint of the array/subarray
        count += mergeSort(arr, low, mid); // Recursively sort and count inversions in the left subarray
        count += mergeSort(arr, mid + 1, high); // Recursively sort and count inversions in the right subarray
        count += merge(arr, low, mid, high); // Merge the sorted subarrays and count inversions
    }
    return count; // Return inversion count
}

// Function to count inversions in the array using merge sort
// Parameters:
// arr: The input array
// n: Size of the array
// Returns: Number of inversions in the array
int countInversions(vector<int> &arr, int n)
{
    return mergeSort(arr, 0, n - 1); // Call merge sort function to count inversions
}

int main()
{
    int n;
    cin >> n; // Input size of the array

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i]; // Input array elements
    }

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " "; // Print array elements
    }
    cout << endl;

    // Output the count of inversions in the array
    cout << "Printing the count of inversions in the array: " << countInversions(arr, n) << endl;
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort). What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Time Complexity: O(N log N), where N = size of the given array.
Reason: We are using merge sort to sort the array, which has a time complexity of O(N log N).

Space Complexity: O(N) due to the additional space required for the temporary array used in merge sort.
*/
