#include <bits/stdc++.h>

using namespace std;

// Function to find the missing and repeating numbers in an array
vector<int> findMissingAndRepeatingNumber(vector<int> a, int n)
{
    int missing = -1, repeating = -1;

    // Iterate through numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        int count = 0;

        // Count occurrences of the current number in the array
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
            {
                count++;
            }
        }

        // If count is 2, then the number is repeating
        if (count == 2)
        {
            repeating = i;
        }
        // If count is 0, then the number is missing
        else if (count == 0)
        {
            missing = i;
        }

        // If both missing and repeating numbers are found, exit the loop
        if (repeating != -1 && missing != -1)
        {
            break;
        }
    }

    // Return the missing and repeating numbers
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
Time Complexity: O(N^2)
Reason: We iterate through numbers from 1 to N and for each number, we count its occurrences in the array, resulting in nested loops. Thus, the time complexity is O(N^2).

Space Complexity: O(1)
Reason: We are not using any extra space besides a few integer variables, regardless of the size of the input array. Thus, the space complexity is O(1).

*/
