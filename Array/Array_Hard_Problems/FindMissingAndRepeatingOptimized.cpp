#include <bits/stdc++.h>

using namespace std;

// Function to find the missing and repeating numbers in an array
vector<int> findMissingAndRepeatingNumber(vector<int> a, int n)
{
    int xr = 0;

    // Calculate the XOR of array elements and numbers from 1 to N
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ a[i];
        xr = xr ^ (i + 1);
    }

    // Find the rightmost set bit in the XOR result
    int bitNo = 0;
    while (1)
    {
        if ((xr & (1 << bitNo)) != 0)
        {
            break;
        }
        bitNo++;
    }

    // Separate the elements into two groups based on the bit at bitNo position
    int zero = 0, one = 0;
    for (int i = 0; i < n; i++)
    {
        if ((a[i] & (1 << bitNo)) != 0)
        {
            one = one ^ a[i];
        }
        else
        {
            zero = zero ^ a[i];
        }
    }

    // Separate the numbers from 1 to N into the same two groups
    for (int i = 1; i <= n; i++)
    {
        if ((i & (1 << bitNo)) != 0)
        {
            one = one ^ i;
        }
        else
        {
            zero = zero ^ i;
        }
    }

    // Count occurrences of the zero value in the array
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == zero)
        {
            count++;
        }
    }

    // If zero occurs twice, it is the repeating number; otherwise, it is the missing number
    if (count == 2)
    {
        return {one, zero};
    }
    return {zero, one};
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

    // Find the missing and repeating numbers
    vector<int> ans = findMissingAndRepeatingNumber(arr, n);
    std::cout << "Missing number: " << ans[0] << std::endl;
    std::cout << "Repeating number: " << ans[1] << std::endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, find the missing and repeating numbers in the array.

Time Complexity: O(N)
Reason: We iterate through the array once to calculate the XOR of array elements and numbers from 1 to N. Then, we iterate again to separate the elements based on a specific bit position. Both iterations contribute to linear time complexity.

Space Complexity: O(1)
Reason: We only use a few integer variables to store intermediate results, regardless of the size of the input array. Thus, the space complexity is O(1).

*/
