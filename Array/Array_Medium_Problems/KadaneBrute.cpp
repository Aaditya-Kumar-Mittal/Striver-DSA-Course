#include <bits/stdc++.h>
using namespace std;

int KadanesMaximumSubarraySum(vector<int> v, int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)  // Fix: Start from i instead of 0
        {
            int sum = 0;
            for (int k = i; k <= j; k++)  // Fix: Correct loop condition
            {
                sum += v[k];  // Fix: Add v[k] to the sum
                maxSum = max(maxSum, sum);  // Fix: Update maxSum with the maximum value
            }
        }
    }
    return maxSum;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    std::cout << "The max sum for a subarray in the given array using Brute Force is: " << KadanesMaximumSubarraySum(arr, n) << std::endl;

    return 0;
}

/*
Analysis of Problem

Name: Brute Force Maximum Subarray Sum
Time Complexity: O(n^3)
Space Complexity: O(1)
*/
