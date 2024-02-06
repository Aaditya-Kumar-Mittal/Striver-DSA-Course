/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int LongestSubarraywithSumL(vector<int> &a, long long K)
{

    int n = a.size();

    int maxlen = 0;

    map<long long, int> prefixSum;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];

        if (sum == K)
        {
            maxlen = max(maxlen, i + 1);
        }

        long long rem = sum - K;

        if (prefixSum.find(rem) != prefixSum.end())
        {
            int len = i - prefixSum[rem];
            maxlen = max(maxlen, len);
        }

        if (prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }
    return maxlen;
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

Name:- IMPORTANT This better approach works best for array with negative elements, for 0s and postives use the optimized approach
Time Complexity:- O(N) or O(N*logN) depending on which map data structure we are using, where N = size of the array. if we are using an unordered_map data structure in C++ the time complexity will be O(N)(though in the worst case, unordered_map takes O(N) to find an element and the time complexity becomes O(N2)) but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Space Complexity:- O(N) as we are using a map data structure.

*/