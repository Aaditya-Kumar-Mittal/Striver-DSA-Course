#include <bits/stdc++.h>

using namespace std;

// Function to find the missing and repeating numbers in an array
vector<int> findMissingAndRepeatingNumber(vector<int> a, int n)
{
    int missing = -1, repeating = -1;

    // Array to store the frequency of each number
    int hashArr[n + 1] = {0};

    // Count the frequency of each number
    for (int i = 0; i < n; i++)
    {
        hashArr[a[i]]++;
    }

    // Find the missing and repeating numbers
    for (int i = 1; i <= n; i++)
    {
        if (hashArr[i] == 2)
        {
            repeating = i;
        }
        else if (hashArr[i] == 0)
        {
            missing = i;
        }

        // If both missing and repeating numbers are found, exit the loop
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }
    return {missing, repeating};
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

    // Find missing and repeating numbers
    vector<int> ans = findMissingAndRepeatingNumber(arr, n);
    std::cout << "Missing number: " << ans[0] << std::endl;
    std::cout << "Repeating number: " << ans[1] << std::endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, find the missing and repeating numbers in the array.

Time Complexity: O(N) + O(N)
Reason: We iterate through the array once to count the frequency of each number, resulting in a time complexity of O(N).

Space Complexity: O(N)
Reason: We use an additional hash array of size N + 1 to store the frequency of each number, resulting in a space complexity of O(N).

*/
