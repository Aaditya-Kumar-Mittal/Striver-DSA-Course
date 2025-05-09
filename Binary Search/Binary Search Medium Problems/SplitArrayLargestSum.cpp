/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Function to count the minimum number of subarrays required such that the sum of each subarray does not exceed 'pages'.
 *
 * @param arr: A vector of integers representing the elements of the array.
 * @param n: The total number of elements in the array.
 * @param pages: The maximum sum allowed for any subarray.
 * @return The number of subarrays required.
 */
int countPartitions(vector<int> &arr, int n, int pages)
{
    int partitions = 1;        // Initialize the number of partitions
    long long subArraySum = 0; // To keep track of the sum of the current subarray

    for (int i = 0; i < n; i++)
    {
        if (subArraySum + arr[i] <= pages)
        {
            // If adding the current element to the current subarray does not exceed the limit
            subArraySum += arr[i];
        }
        else
        {
            // Start a new subarray with the current element
            partitions++;
            subArraySum = arr[i];
        }
    }
    return partitions;
}

/**
 * Brute force approach to find the minimum possible value of the largest sum among 'm' subarrays.
 *
 * @param arr: A vector of integers representing the elements of the array.
 * @param n: The total number of elements in the array.
 * @param m: The number of subarrays.
 * @return The minimized largest sum of the subarrays.
 */
int largestSumArraySumMinimizedBruteForce(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        // If there are more subarrays required than elements, it is impossible to split
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());   // Minimum possible value (largest single element)
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible value (sum of all elements)

    // Brute force search from the largest single element to the sum of all elements
    for (int maxSum = low; maxSum <= high; maxSum++)
    {
        if (countPartitions(arr, n, maxSum) == m)
        {
            return maxSum;
        }
    }

    return low; // Default return value in case of failure
}

/**
 * Optimized approach using binary search to find the minimum possible value of the largest sum among 'm' subarrays.
 *
 * @param arr: A vector of integers representing the elements of the array.
 * @param n: The total number of elements in the array.
 * @param m: The number of subarrays.
 * @return The minimized largest sum of the subarrays.
 */
int largestSumArraySumMinimizedBinarySearch(vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        // If there are more subarrays required than elements, it is impossible to split
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());   // Minimum possible value (largest single element)
    int high = accumulate(arr.begin(), arr.end(), 0); // Maximum possible value (sum of all elements)

    // Binary search to find the minimum possible largest sum
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Middle point of the current range

        int partitions = countPartitions(arr, n, mid);

        if (partitions > m)
        {
            // If more subarrays are needed, increase the lower bound
            low = mid + 1;
        }
        else
        {
            // Otherwise, decrease the upper bound
            high = mid - 1;
        }
    }
    return low; // The point where low meets high is the minimum largest sum required
}

int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    int numberOfSubArrays;
    cout << "Enter the number of subarrays: ";
    cin >> numberOfSubArrays;

    int bruteAns = largestSumArraySumMinimizedBruteForce(array, n, numberOfSubArrays);
    cout << "The minimized largest sum of the split arrays is (Brute Force Solution): " << bruteAns << endl;

    int binarySearchAns = largestSumArraySumMinimizedBinarySearch(array, n, numberOfSubArrays);
    cout << "The minimized largest sum of the split arrays is (Binary Search Solution): " << binarySearchAns << endl;

    return 0;
}

/*
Analysis of Problem

Name: Array Partitioning Problem

Brute Force Solution:
Time Complexity: O(N * (sum(arr[])-max(arr[])+1))
    - Where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    - We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of the maximum sum. Inside the loop, we are calling the countPartitions() function for each number. The countPartitions() function has a time complexity of O(N).

Space Complexity: O(1)
    - We are not using any extra space to solve this problem.

Binary Search Solution:
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))
    - Where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    - We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPartitions() function for the value of ‘mid’. The countPartitions() function has a time complexity of O(N).

Space Complexity: O(1)
    - We are not using any extra space to solve this problem.
*/
