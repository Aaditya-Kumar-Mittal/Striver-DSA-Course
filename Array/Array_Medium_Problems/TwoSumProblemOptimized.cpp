#include <bits/stdc++.h>
using namespace std;

string TwoSumOptimized(vector<int> v, int n, int target)
{
    int left = 0, right = n - 1;

    sort(v.begin(), v.end());

    while (left < right)
    {
        int sum = v[left] + v[right];

        if (sum == target)
        {
            return "YES";
        }
        else if (sum < target)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    return "NO";
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

    int targetSum;
    cin >> targetSum;

    cout << targetSum << " Does it exist in the given array? : " << TwoSumOptimized(arr, n, targetSum) << endl;

    return 0;
}

/*
Analysis of Problem

Name: Two Sum
Time Complexity: O(n log n) due to sorting
Space Complexity: O(n) for the input array
*/
