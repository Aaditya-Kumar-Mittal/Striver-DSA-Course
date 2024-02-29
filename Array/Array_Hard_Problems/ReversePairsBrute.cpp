#include <bits/stdc++.h>

using namespace std;

int reversePairs(vector<int> arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++) // Loop runs N times
    {
        for (int j = i + 1; j < n; j++) // Nested loop runs N times
        {
            if (arr[i] > 2 * arr[j]) // Constant time operation
            {
                count++; // Constant time operation
            }
        }
    }
    return count;
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Output the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the count of reverse pairs in the array
    cout << "Printing the count of reverse pairs in the array: " << reversePairs(arr, n) << endl;
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, count the reverse pairs in the array. A reverse pair (i, j) is defined as i < j and nums[i] > 2 * nums[j].

Time Complexity: O(N^2), where N is the size of the given array.
Reason: We are using nested loops here, where the outer loop runs from 0 to N-1 and the inner loop runs from i+1 to N-1. Thus, the time complexity is quadratic.

Space Complexity: O(1)
Reason: We are not using any extra space that grows with the input size, so the space complexity is constant.
*/
