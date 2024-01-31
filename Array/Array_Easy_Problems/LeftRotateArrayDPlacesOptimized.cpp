/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void RotateElementsDPlaceOptimized(vector<int> &a, int n, int d)
{

    // Reverese Array Thrice

    d = d % n;

    reverse(a.begin(), a.begin() + d);
    reverse(a.begin() + d, a.end());
    reverse(a.begin(), a.end());
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

    int d;
    cin >> d;

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    RotateElementsDPlaceOptimized(arr, n, d);

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Name:- Rotate Elements D Places Optimized

Time Complexity:- O(n-d)+O(n)+O(d)  The time complexity of the optimized approach for rotating elements d places in an array is O(n), where n is the number of elements in the array. This is because the algorithm involves reversing the array three times, each taking linear time.

Space Complexity:- The space complexity of the optimized approach is O(1), which is constant space complexity. This is because the algorithm performs the rotations in place without using any additional space proportional to the size of the input array.

*/