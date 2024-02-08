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

    // Initialize index for inserting elements into the result array
    if (positives.size() > negatives.size())
    {
        for (int i = 0; i < negatives.size(); i++)
        {
            ans[2 * i] = positives[i];
            ans[2 * i + 1] = negatives[i];
        }

        int index = negatives.size() * 2;
        for (int i = negatives.size(); i < positives.size(); i++)
        {
            ans[index++] = positives[i];
        }
    }
    else
    {
        for (int i = 0; i < positives.size(); i++)
        {
            ans[2 * i] = positives[i];
            ans[2 * i + 1] = negatives[i];
        }

        int index = positives.size() * 2;
        for (int i = positives.size(); i < negatives.size(); i++)
        {
            ans[index++] = negatives[i];
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


There’s an array ‘A’ of size ‘N’ with positive and negative elements (not necessarily equal). Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values. The leftover elements should be placed at the very end in the same order as in array A.


Approach:
- First, separate positive and negative numbers into two separate arrays.
- Then, rearrange the positive and negative numbers alternately by placing positive numbers at even indices and negative numbers at odd indices in the resulting array.
- Finally, if there are any remaining positive or negative numbers, insert them at the end of the array in the same order as in the input array.

Name: Rearrange Alternately Positive and Negative Numbers
Time Complexity: O(2*N) { The worst case complexity is O(2*N) which is a combination of O(N) of traversing the array to segregate into neg and pos array and O(N) for adding the elements alternatively to the main array}.4
- The second O(N) is a combination of O(min(pos, neg)) + O(leftover elements). There can be two cases: when only positive or only negative elements are present, O(min(pos, neg)) + O(leftover) = O(0) + O(N), and when equal no. of positive and negative elements are present, O(min(pos, neg)) + O(leftover) = O(N/2) + O(0). So, from these two cases, we can say the worst-case time complexity is O(N) for the second part, and by adding the first part we get the total complexity of O(2*N).


Space Complexity: O(N/2 + N/2) = O(N) { N/2 space required for each of the positive and negative element arrays, where N = size of the array A}.
*/