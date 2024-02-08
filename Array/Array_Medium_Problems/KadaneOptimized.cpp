#include <bits/stdc++.h>
using namespace std;

long long KadanesMaximumSubarraySum(vector<int> v, int n)
{
    long long sum = 0, maxSum = LONG_LONG_MIN;
    int ansStart = 0, ansEnd = 0, start = 0;

    for (int i = 0; i < n; i++)
    {
        // If the current sum becomes 0, update the starting index for the potential new subarray
        if (sum == 0)
        {
            start = i;
        }

        // Add the current element to the sum
        sum += v[i];

        // Update the maximum sum and its corresponding indices if a new maximum is found
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        // If the sum becomes negative, reset it to 0, as any negative sum would only decrease the maximum subarray sum
        if (sum < 0)
        {
            sum = 0;
        }
    }

    // Print the elements of the maximum sum subarray
    cout << "Printing the max sum subarray: " << endl;
    for (int i = ansStart; i <= ansEnd; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    // Return the maximum sum
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

    // Print the input array
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the function to find the maximum sum subarray
    std::cout << "The max sum for a subarray in the given array using Kadane's Algorithm is: " << KadanesMaximumSubarraySum(arr, n) << std::endl;

    return 0;
}

/*
Analysis of Problem

Name: Kadane's Algorithm for Maximum Subarray Sum
Time Complexity: O(n)
Space Complexity: O(1)

Explanation:
- The function KadanesMaximumSubarraySum implements Kadane's algorithm to find the maximum subarray sum efficiently.
- It iterates through the input array only once, maintaining variables for current sum, maximum sum, and indices of the maximum sum subarray.
- If the current sum becomes zero, it updates the starting index for a potential new subarray.
- It updates the maximum sum and its corresponding indices whenever a new maximum is found.
- If the sum becomes negative, it resets it to zero, as any negative sum would only decrease the maximum subarray sum.
- Finally, it prints the elements of the maximum sum subarray and returns the maximum sum.
- The time complexity of this algorithm is O(n) as it processes each element of the array only once.
- The space complexity is O(1) as it uses only a constant amount of extra space regardless of the input size.
*/
