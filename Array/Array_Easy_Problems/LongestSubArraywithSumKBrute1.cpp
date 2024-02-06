/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int LongestSubarraywithSumL(vector<int> &a, int K)
{

    int n = a.size();

    int len = 0;

    for (int i = 0; i < n; i++)
    {
        long long sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += a[j];
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

    int len = LongestSubarraywithSumL(arr, k);

    std::cout << "The length of longest subArray with sum K is: " << len << std::endl;
}

/*
Analysis of Problem

Name:- Brute force with only 2 loops
Time Complexity:- O(N^2)
Space Complexity:- O(1)

*/