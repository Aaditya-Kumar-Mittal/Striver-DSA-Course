#include <bits/stdc++.h>
using namespace std;

int CountSubArrayWithSumK(vector<int> arr, int n, int K)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;

        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == K)
            {
                count++;
            }
        }
    }
    return count;
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

    int K;
    cin >> K;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The count of subarrays with sum equal to " << K << " is: " << CountSubArrayWithSumK(arr, n, K) << endl;

    return 0;
}

/*
Analysis of Problem

Name: Count Subarrays with Sum K
Time Complexity: O(N^2)
Space Complexity: O(1)
Explanation:
- The function `CountSubArrayWithSumK` uses two nested loops to iterate over all possible subarrays, resulting in a time complexity of O(N^2), where N is the size of the input array.
- The space complexity is O(1) because the function uses only a constant amount of extra space regardless of the input size.
*/
