/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void RotateElementsDPlaceBruteForce(vector<int> &a, int n, int d)
{

    d = d % n;

    vector<int> tempArr(d);

    for (int i = 0; i < d; i++)
    {
        tempArr[i] = a[i];
    }

    for (int i = d; i < n; i++)
    {
        a[i - d] = a[i];
    }

    for (int i = n - d; i < n; i++)
    {
        a[i] = tempArr[i - (n - d)];
    }
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

    RotateElementsDPlaceBruteForce(arr, n, d);

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

Name:- Rotate Elements D Places Brute Force

Time Complexity:- The time complexity of the brute force approach for rotating elements d places in an array is O(n * d), where n is the number of elements in the array and d is the number of places to rotate. This is because for each rotation, we shift the elements by one place, and we repeat this process d times.

Space Complexity:- The space complexity of the brute force approach is O(d), where d is the number of places to rotate. This is because we use an additional array of size d to store the elements that need to be rotated.

*/