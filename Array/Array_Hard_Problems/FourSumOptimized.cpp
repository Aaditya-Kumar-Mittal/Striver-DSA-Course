#include <bits/stdc++.h>

using namespace std;

// Function to solve the Four Sum Problem
vector<vector<int>> FourSumProblem(vector<int> arr, int n, int target)
{
    vector<vector<int>> ans; // Vector to store quadruplets

    // Sort the array
    sort(arr.begin(), arr.end());

    // Calculate quadruplets
    for (int i = 0; i < n; i++)
    {
        // Skip duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // Skip duplicates for the second element
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            // Two pointers approach
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum == target)
                {
                    // Quadruplet found, add to answer
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    // Skip duplicates for third and fourth elements
                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    return ans;
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

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Print the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find and print Four Sum Quadruplets with target sum
    cout << "Four sum Quadruplets with target sum " << targetSum << " are:  " << endl;
    vector<vector<int>> ans = FourSumProblem(arr, n, targetSum);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, find all unique quadruplets that add up to a target sum.

Time Complexity:
    O(N^3), where N is the size of the array.
Reason: The algorithm uses nested loops to generate all possible quadruplets. The outer loop runs N times, and the inner loops run approximately N times each, resulting in a time complexity of O(N^3).

Space Complexity:
    O(no. of quadruplets), as space is used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
