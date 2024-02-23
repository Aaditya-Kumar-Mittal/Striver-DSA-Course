#include <bits/stdc++.h>
using namespace std;

int countNumberOfSubarraywithXORk(vector<int> a, int n, int target)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int XOR = 0;
        for (int j = i; j < n; j++)
        {
            XOR ^= a[j];
            if (XOR == target)
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
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int K;
    cout << "Enter the target XOR value: ";
    cin >> K;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find and print the count of subarrays with XOR equal to K
    cout << "Count of subarrays with XOR equal to " << K << ": ";
    cout << countNumberOfSubarraywithXORk(arr, n, K) << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of integers A and an integer B, find the total number of subarrays having bitwise XOR of all elements equal to k.

Time Complexity: O(N^2), where N is the size of the array.
Reason: The algorithm uses two nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space besides the input array.
*/
