#include <bits/stdc++.h>
using namespace std;

// Function to rearrange positive and negative numbers alternately
vector<int> rearrangeAlternateNumbers(vector<int> a, int n)
{
    vector<int> ans(n, 0); // Initialize result array with zeros

    int posIndex = 0, negIndex = 1; // Initialize indices for positive and negative numbers

    // Traverse the input array
    for (int i = 0; i < n; i++)
    {
        // If current element is positive, place it at even index in result array
        if (a[i] > 0)
        {
            ans[posIndex] = a[i];
            posIndex += 2; // Move to next even index for positive numbers
        }
        // If current element is negative, place it at odd index in result array
        else
        {
            ans[negIndex] = a[i];
            negIndex += 2; // Move to next odd index for negative numbers
        }
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

    // Rearrange the array
    vector<int> ans = rearrangeAlternateNumbers(arr, n);

    // Output the rearranged array
    cout << "Rearranged Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem:

Name: Rearrange Array with Alternating Positive and Negative Numbers
- This problem involves rearranging an array of positive and negative integers such that positive and negative numbers appear alternately.
- The approach used here is to maintain two indices, one for positive numbers and one for negative numbers.
- We traverse the input array and place positive numbers at even indices and negative numbers at odd indices in the result array.
- After traversing the entire array, we obtain the rearranged array with positive and negative numbers appearing alternately.
- Time Complexity: O(N), where N is the size of the input array.
- Space Complexity: O(N) for storing the result array.
*/
