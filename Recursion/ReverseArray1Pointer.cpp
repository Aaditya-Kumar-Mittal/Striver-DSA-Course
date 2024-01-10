/*
Aaditya Mittal- My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to swap elements using two pointers
void ReverseArray(vector<int> &vec, int i)
{
    if (i >= vec.size() / 2)
    {
        return;
    }

    // Swap elements at front and rear positions
    swap(vec[i], vec[vec.size() - 1 - i]);

    // Recursive call to swap elements in the remaining subarray
    ReverseArray(vec, i + 1);
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
    ReverseArray(arr, 0);

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

Reverse Array using Single Pointer
*/