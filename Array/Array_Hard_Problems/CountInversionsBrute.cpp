#include <bits/stdc++.h>

using namespace std;

// Function to count inversions in the array
// Parameters:
// arr: The input array
// n: Size of the array
// Returns: Number of inversions in the array
int countInversions(vector<int> arr, int n)
{
    int count = 0;
    // Nested loops to compare each pair of elements
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // If the condition for inversion is satisfied, increment count
            if (arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    int n;
    // Input size of the array
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Printing the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the count of inversions in the array
    std::cout << "Printing the count of inversions in the array: " << countInversions(arr, n) << std::endl;
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, count the inversion of the array (using merge-sort). What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

Time Complexity: O(N^2), where N = size of the given array.
Reason: We are using nested loops here and those two loops roughly run for N times.

Space Complexity: O(1) as we are not using any extra space to solve this problem.
*/