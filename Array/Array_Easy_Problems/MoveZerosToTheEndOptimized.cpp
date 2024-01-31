/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

void MoveZerosToTheEndOptimized(vector<int> &a, int n)
{

    int j = -1;
    for (int i = 0; i < n; i++)
    {
        // This loop ensures that j is stored at the whenver 0 occurs for the first time otherwise it is -1
        if (a[i] == 0)
        {
            j = i;
            break;
        }
    }

    for (int i = j + 1; i < n; i++)
    {
        if (a[i] != 0)
        {
            swap(a[i], a[j]);
            j++;
        }
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

    MoveZerosToTheEndOptimized(arr, n);

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

Name: Move Zeros to the End (Optimized)

Time Complexity: The time complexity of the optimized approach for moving zeros to the end of an array is O(n), where n is the number of elements in the array. The algorithm iterates through the array once, swapping non-zero elements with the first encountered zero element's position.

Space Complexity: The space complexity of the optimized approach is O(1), which is constant space complexity. The algorithm performs the operation in place without using any additional space proportional to the size of the input array.

The provided code implements an optimized approach to move zeros to the end of an array. The algorithm iterates through the array once, maintaining an index (j) pointing to the position where the next non-zero element should be placed. When encountering a non-zero element after the first zero element, it swaps the non-zero element with the element at index j, effectively moving the non-zero element to the end of the array.
*/