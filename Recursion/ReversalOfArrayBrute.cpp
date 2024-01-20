/*
Aaditya Mittal - My lack of commitment to my goals is an insult to those who believe in me.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input the size of the array
    int n;
    cin >> n;

    // Create a vector to store the array elements
    vector<int> arr(n);

    // Input the array elements
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    // Display the array before reversal
    cout << "Array before Reversal: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    // Initialize pointers for array reversal
    int start = 0;
    int end = n - 1;

    // Reverse the array using a two-pointer approach
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start += 1;
        end -= 1;
    }

    // Display the array after reversal
    cout << "Array after Reversal: " << endl;
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis Portion and Comments:

- The program takes an integer 'n' as input, representing the size of the array.
- It then reads 'n' elements into a vector 'arr'.
- Displays the original array.
- Initializes two pointers 'start' and 'end' for array reversal.
- The while loop correctly reverses the array using a two-pointer approach.
- Displays the reversed array.
*/
