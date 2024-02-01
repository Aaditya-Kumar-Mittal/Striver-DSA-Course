/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int NumberOccurringOnce(vector<int> a, int n)
{

    // Run a loop for selecting elements:
    for (int i = 0; i < n; i++)
    {
        int num = a[i]; // selected element
        int cnt = 0;

        // find the occurrence using linear search:
        for (int j = 0; j < n; j++)
        {
            if (a[j] == num)
                cnt++;
        }

        // if the occurrence is 1 return ans:
        if (cnt == 1)
            return num;
    }

    // This line will never execute
    // if the array contains a single element.
    return -1;
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

    cout << "Element Appearing Once in a Twice Element Array is: " << NumberOccurringOnce(arr, n)
         << endl;

    return 0;
}

/*
Analysis of Problem

Name:- Brute for element occurring once

Time Complexity:- O(N2), where N = size of the given array.  For every element, we are performing a linear search to count its occurrence. The linear search takes O(N) time complexity. And there are N elements in the array. So, the total time complexity will be O(N2).

Space Complexity:-O(1) as we are not using any extra space.

*/