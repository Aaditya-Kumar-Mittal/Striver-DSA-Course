/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> TwoSumBetter(vector<int> &v, int n, int target)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int a = v[i];

        int rem = target - a;

        if (mpp.find(rem) != mpp.end())
        {
            return {mpp[rem], i};
        }
        mpp[a] = i;
    }
    return {};
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

    vector<int> ans = TwoSumBetter(arr, n, targetSum);

    if (ans.empty())
    {
        cout << targetSum << " Does it exist in the given array? : NO" << endl;
    }
    else
    {
        cout << targetSum << " exists in the array at indices: " << endl;
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: Two Sum
Time Complexity: O(n)
Space Complexity: O(n)
*/
