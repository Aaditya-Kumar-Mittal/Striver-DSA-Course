#include <bits/stdc++.h>

using namespace std;

int countNumberOfSubarraywithXORk(vector<int> a, int n, int target)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xorr = 0;
            for (int k = i; k <= j; k++)
            {
                xorr = xorr ^ a[k];
            }

            // step 3:check XOR and count:
            if (xorr == target)
                count++;
        }
    }
    return count;
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

    int K;
    cin >> K;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    std::cout << "Printing the count of subarrays with XOR equal to " << K << std::endl;
    std::cout << countNumberOfSubarraywithXORk(arr, n, K) << std::endl;
    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of integers A and an integer B, find the total number of subarrays having bitwise XOR of all elements equal to k.

Time Complexity: O(N^3), where N is the size of the array.
Reason: The algorithm uses three nested loops, each running approximately N times.

Space Complexity: O(1) as we are not using any extra space besides the input array.
*/
