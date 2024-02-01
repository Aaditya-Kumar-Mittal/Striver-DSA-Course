/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int MaxConsecutiveOnes(vector<int> a, int n)
{
    int maxi = 0;
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1)
        {
            counter++;
            maxi = max(counter, maxi);
        }
        else
        {
            counter = 0;
        }
    }

    return maxi;
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

    cout << "The Maximum Number of Consecutive 1's in the array is: " << MaxConsecutiveOnes(arr, n)
         << endl;

    return 0;
}

/*
Analysis of Problem

Name: Maximum Consecutive Ones

The problem aims to find the maximum number of consecutive 1's in a binary array.

Approach:
- Iterate through the array and maintain a counter to track the current consecutive count of 1's.
- Update the maximum count whenever a 1 is encountered, and reset the counter when a 0 is encountered.
- Return the maximum count of consecutive 1's found.

Comments:
- The provided code implements a straightforward approach to solve the problem.
- It iterates through the array once, updating the maximum count whenever consecutive 1's are encountered.
- The time complexity of the algorithm is O(n), where n is the size of the input array.
- The space complexity is O(1) as the algorithm uses only a constant amount of extra space.

Overall, the implementation efficiently finds the maximum number of consecutive 1's in the array. However, it assumes that the array contains only 0's and 1's. If the array may contain other numbers, additional checks or modifications may be necessary.

*/