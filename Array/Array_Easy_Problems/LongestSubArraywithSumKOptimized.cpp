/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int LongestSubarraywithSumL(vector<int> &a, long long K)
{

    int n = a.size();

    int left = 0, right = 0, maxLen = 0;

    long long sum = a[0];

    while (right < n)
    {
        while (left <= right && sum > K)
        {
            sum -= a[left];
            left++;
        }

        if (sum == K)
        {
            maxLen = max(maxLen, right - left + 1);
        }

        right++;
        if (right < n)
        {
            sum += a[right];
        }
    }
    return maxLen;
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

Name:-
Time Complexity:- O(2*N), where N = size of the given array. The outer while loop i.e. the right pointer can move up to index n-1(the last index). Now, the inner while loop i.e. the left pointer can move up to the right pointer at most. So, every time the inner loop does not run for n times rather it can run for n times in total. So, the time complexity will be O(2*N) instead of O(N2).

Space Complexity:- O(1) as we are not using any extra space.

*/