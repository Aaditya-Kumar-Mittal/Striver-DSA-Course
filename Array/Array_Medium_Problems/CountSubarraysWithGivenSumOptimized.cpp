#include <bits/stdc++.h>
using namespace std;

// Function to count the number of subarrays with sum equal to K
int CountSubArrayWithSumK(vector<int> arr, int n, int K)
{
    // Map to store prefix sum frequencies
    unordered_map<int, int> prefixSumFreq;

    // Initialize prefix sum to 0 with frequency 1
    prefixSumFreq[0] = 1;

    int prefixSum = 0; // Initialize prefix sum
    int count = 0;     // Initialize count of subarrays with sum K

    // Traverse the array and calculate prefix sum
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];            // Update prefix sum
        int complement = prefixSum - K; // Calculate complement (prefix sum - K)

        // If complement exists in prefix sum frequencies, add its frequency to count
        count += prefixSumFreq[complement];

        // Increment prefix sum frequency
        prefixSumFreq[prefixSum]++;
    }

    return count; // Return count of subarrays with sum K
}

int main()
{
    int n;
    cin >> n; // Input size of the array

    vector<int> arr(n);
    // Input array elements
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int K;
    cin >> K; // Input target sum K

    // Output array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Calculate and output the count of subarrays with sum K
    cout << "The count of subarrays with sum equal to " << K << " is: " << CountSubArrayWithSumK(arr, n, K) << endl;

    return 0;
}

/*
Analysis of Problem

Name: Count Subarrays with Sum K
Time Complexity: O(N), where N is the size of the array.
Reason: We traverse the array once, and for each element, we perform constant-time operations.

Space Complexity: O(N)
Reason: We use an unordered_map to store prefix sum frequencies, which may require O(N) space in the worst case if all prefix sums are unique.
*/
