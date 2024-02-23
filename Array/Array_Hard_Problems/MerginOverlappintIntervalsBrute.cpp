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
        int start = arr[i][0];
        int end = arr[i][1];

        // If the current interval overlaps with the last merged interval, update the end time
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }

        // Merge overlapping intervals
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j][0] <= end)
            {
                end = max(end, arr[j][1]);
            }
            else
            {
                break;
            }
        }

        // Add the merged interval to the result
        ans.push_back({start, end});
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
O(N*logN) + O(2*N), where N = the size of the given array.
Reason: Sorting the given array takes O(N*logN) time complexity. Now, after that, we are using 2 loops i and j. But while using loop i, we skip all the intervals that are merged with loop j. So, we can conclude that every interval is roughly visited twice(roughly, once for checking or skipping and once for merging). So, the time complexity will be 2*N instead of N^2.

Space Complexity:
O(N), as we are using an answer list to store the merged intervals. Except for the answer array, we are not using any extra space.
*/
