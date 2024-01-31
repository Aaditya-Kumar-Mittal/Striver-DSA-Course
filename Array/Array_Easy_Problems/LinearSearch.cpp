/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

bool LinearSearch(vector<int> &a, int n, int d)
{
    for (int i = 0; i < n; i++)
    {
        if (d == a[i])
        {
            return true;
        }
    }
    return false;
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

    bool found = LinearSearch(arr, n, d);

    if (found)
    {
        std::cout << "Element was found in the given array." << std::endl;
    }
    else
    {
        std::cout << "Element was not found in the given array." << std::endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: Linear Search

Time Complexity: The time complexity of linear search in the worst-case scenario is O(n), where n is the number of elements in the array. This is because the algorithm iterates through each element in the array until it finds the target element or reaches the end of the array.

Space Complexity: The space complexity of linear search is O(1), which is constant space complexity. This is because the algorithm uses a fixed amount of space regardless of the size of the input array.

The provided code implements linear search to find an element in an array. The algorithm iterates through the array and compares each element with the target element until it finds a match or reaches the end of the array.

*/