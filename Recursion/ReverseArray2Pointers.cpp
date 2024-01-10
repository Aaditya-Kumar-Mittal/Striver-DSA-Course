/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to swap elements using two pointers
void SWAP(vector<int> &vec, int f, int r)
{
    // Base case: if the front pointer is greater than or equal to the rear pointer
    if (f >= r)
    {
        return;
    }

    // Swap elements at front and rear positions
    swap(vec[f], vec[r]);

    // Recursive call to swap elements in the remaining subarray
    SWAP(vec, f + 1, r - 1);
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Display the original array
    cout << "Before Swapping the Array: " << endl;
    for (int i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // Call the swap function to reverse the array
    SWAP(arr, 0, n - 1);

    // Display the reversed array
    cout << "After Swapping the Array: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis Portion and Comments:

Reverse Array using Two pointers
*/