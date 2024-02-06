/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int LongestSubarraywithSumK(vector<int> &a, int K)
{

    int n = a.size();

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            long long sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }

            if (sum == K)
            {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
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

    int k;
    cin >> k;

    int len = LongestSubarraywithSumK(arr, k);

    std::cout << "The length of longest subArray with sum K is: " << len << std::endl;
}

/*
Analysis of Problem

Name:- LongestSubarraywithSumKBrute
Time Complexity:- O(N^3) Three nested loops
Space Complexity:- O(1) no extra space used

*/