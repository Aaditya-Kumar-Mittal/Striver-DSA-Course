#include <bits/stdc++.h>

using namespace std;

// Function to find the maximum product of a subarray
int maximumProductSubarray(vector<int> a, int n)
{
    int maxP = INT_MIN;

    // Iterate through each element as the starting point of the subarray
    for (int i = 0; i < n; i++)
    {
        int product = 1;

        // Calculate the product of the subarray starting from index i
        for (int j = i; j < n; j++)
        {
            product *= a[j];
            maxP = max(maxP, product);
        }
    }
    return maxP;
}

int main()
{
    // Input the size of the array
    int n;
    cin >> n;

    // Input the array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find the maximum product of a subarray
    std::cout << "Maximum Product for a subarray in array is: " << maximumProductSubarray(arr, n) << std::endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of integers, find the maximum product of a subarray.

Time Complexity: O(N^2)
Reason: The nested loops iterate through each element of the array, resulting in a quadratic time complexity.

Space Complexity: O(1)
Reason: We use only a few additional variables regardless of the size of the input array. Thus, the space complexity is O(1).

*/
