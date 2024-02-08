#include <bits/stdc++.h>
using namespace std;

// Function to rearrange positive and negative numbers alternately
vector<int> rearrangeAlternateNumbers(vector<int> a, int n)
{
    vector<int> positives, negatives;
    vector<int> ans(n);

    // Separate positive and negative numbers
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            positives.push_back(a[i]);
        }
        else
        {
            negatives.push_back(a[i]);
        }
    }

    // Rearrange positive and negative numbers alternately
    for (int i = 0; i < n / 2; i++)
    {
        ans[2 * i] = positives[i];     // Place positive number at even index
        ans[2 * i + 1] = negatives[i]; // Place negative number at odd index
    }

    return ans; // Return the rearranged array
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print the input array
    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Rearrange and print the alternate positive and negative numbers
    vector<int> ans = rearrangeAlternateNumbers(arr, n);
    cout << "Array after Rearrangement: ";
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

Approach:
- First, separate positive and negative numbers into two separate arrays.
- Then, rearrange the positive and negative numbers alternately by placing positive numbers at even indices and negative numbers at odd indices in the resulting array.

Name: Rearrange Alternately Positive and Negative Numbers
Time Complexity:
- O(n), where n is the size of the input array. The algorithm iterates through the array once.
- O(N+N/2) { O(N) for traversing the array once for segregating positives and negatives and another O(N/2) for adding those elements alternatively to the array, where N = size of the array A}.
Space Complexity:
- O(n), where n is the size of the input array. Additional space is used to store positive and negative numbers separately.
- O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
*/
