/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int KadanesMaximumSubarraySum(vector<int> v, int n)
{
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += v[j];
            maxSum = max(maxSum, sum);
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
In the provided code, the function `KadanesMaximumSubarraySum` implements the brute-force approach to find the maximum subarray sum. Here's the analysis of the problem:

Name: Brute Force Maximum Subarray Sum

Time Complexity: O(n^2)

Space Complexity: O(1)

Explanation:

- The function `KadanesMaximumSubarraySum` iterates through all possible subarrays of the input array `v`.
- For each starting index `i`, it calculates the sum of all subarrays starting at index `i` and ending at each index `j` from `i` to `n-1`.
- It maintains a variable `maxSum` to store the maximum subarray sum found so far.
- The time complexity of this approach is O(n^2) because for each starting index `i`, it takes O(n-i) time to calculate the sum of subarrays.
- The space complexity is O(1) because it only uses a constant amount of extra space regardless of the input size.
  
Overall, while this approach is simple to implement, it is not the most efficient solution for finding the maximum subarray sum, especially for large input sizes. Kadane's algorithm provides a more efficient solution with O(n) time complexity.
*/
