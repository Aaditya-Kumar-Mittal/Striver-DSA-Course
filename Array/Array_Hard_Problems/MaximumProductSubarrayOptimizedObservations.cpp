#include <bits/stdc++.h>

using namespace std;

// Function to find the maximum product of a subarray
int maximumProductSubarray(vector<int> a, int n)
{
    int maxProduct = INT_MIN;
    int prefixProduct = 1, suffixProduct = 1;

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // Reset prefix and suffix products if they become zero
        if (prefixProduct == 0)
        {
            prefixProduct = 1;
        }
        if (suffixProduct == 0)
        {
            suffixProduct = 1;
        }

        // Update prefix and suffix products
        prefixProduct *= a[i];
        suffixProduct *= a[n - i - 1];

        // Update the maximum product with the maximum of current prefix and suffix products
        maxProduct = max(maxProduct, max(prefixProduct, suffixProduct));
    }
    return maxProduct;
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

Time Complexity: O(N)
Reason: We iterate through the array once, performing constant-time operations in each iteration.

Space Complexity: O(1)
Reason: We use only a few additional variables regardless of the size of the input array. Thus, the space complexity is O(1).

*/
