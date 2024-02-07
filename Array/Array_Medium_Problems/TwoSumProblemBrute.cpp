/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

string TwoSumBrute(vector<int> &v, int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] + v[j] == target)
            {
                return "YES";
            }
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

    cout << targetSum << " Does it exit in the given array? : " << TwoSumBrute(arr, n, targetSum) << endl;
    return 0;
}

/*
Analysis of Problem

Name:- Brute Force for Two Sum Problem
Time Complexity:- O(n^2)
Space Complexity:- O(1)

*/