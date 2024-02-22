#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> FourSumProblem(vector<int> arr, int n, int target)
{
    set<vector<int>> st;

    // checking all possible quadruplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];

                    if (sum == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
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

    int targetSum;
    cin >> targetSum;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

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

Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.
Time Complexity:
Space Complexity:

*/
