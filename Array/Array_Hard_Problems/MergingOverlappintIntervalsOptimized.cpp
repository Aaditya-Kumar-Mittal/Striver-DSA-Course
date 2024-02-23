#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Function to merge overlapping intervals.
 *
 * @param arr The array of intervals.
 * @param n The number of intervals.
 * @return vector<vector<int>> The merged intervals.
 */
vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> arr, int n)
{
    // Sorting the intervals based on the start time
    sort(arr.begin(), arr.end());

    // Vector to store the merged intervals
    vector<vector<int>> ans;

    // Loop through each interval
    for (int i = 0; i < n; i++)
    {
        // If the current interval doesn't overlap with the previous merged interval, add it directly
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // If the current interval overlaps with the previous merged interval, merge them
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    // Return the merged intervals
    return ans;
}

int main()
{
    // Input the number of intervals
    int n;
    cin >> n;

    // Input the intervals
    vector<vector<int>> arr(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Output the input intervals
    cout << "Printing Array Elements: " << endl;
    for (auto it : arr)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }

    // Merge overlapping intervals
    vector<vector<int>> overlappedIntervals = mergeOverlappingIntervals(arr, n);

    // Output the merged intervals
    cout << "Printing Overlapping Interval Elements: " << endl;
    for (auto it : overlappedIntervals)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }

    return 0;
}

/*
Analysis of Problem

Problem Statement:
Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

Time Complexity:
O(N*logN) + O(N), where N is the number of intervals.
Reason: Sorting the intervals based on the start time takes O(N*logN) time complexity.

Space Complexity:
O(N), where N is the number of intervals.
Reason: We are using a vector to store the merged intervals, which has a space complexity of O(N).
*/
