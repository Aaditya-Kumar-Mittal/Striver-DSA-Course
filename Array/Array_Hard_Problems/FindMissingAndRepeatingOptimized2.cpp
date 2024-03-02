#include <bits/stdc++.h>

using namespace std;

// Function to find the missing and repeating numbers in an array
vector<int> findMissingAndRepeatingNumber(vector<int> a, int n)
{
    // Calculate the sum of first N natural numbers and their squares
    long long SumN = (n * (n + 1)) / 2;
    long long Sum2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate the sum of elements and their squares in the array
    long long Sum = 0, Sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        Sum += a[i];
        Sum2 += ((long long)a[i] * (long long)a[i]);
    }

    // Calculate the difference between the expected and actual sums
    int value1 = Sum - SumN;
    int value2 = Sum2 - Sum2N;

    // Calculate the repeating and missing numbers
    value2 = value2 / value1;
    long long repeating = (value1 + value2) / 2;
    long long missing = repeating - value1;

    return {(int)missing, (int)repeating};
}

int main()
{
    // Input size of the array
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

    // Find missing and repeating numbers
    vector<int> ans = findMissingAndRepeatingNumber(arr, n);
    std::cout << "Missing number: " << ans[0] << std::endl;
    std::cout << "Repeating number: " << ans[1] << std::endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, find the missing and repeating numbers in the array.

Time Complexity: O(N)
Reason: We iterate through the array once to calculate the sum of elements and their squares, resulting in a time complexity of O(N).

Space Complexity: O(1)
Reason: We only use a few integer variables to store the sum values, regardless of the size of the input array. Thus, the space complexity is O(1).

*/
