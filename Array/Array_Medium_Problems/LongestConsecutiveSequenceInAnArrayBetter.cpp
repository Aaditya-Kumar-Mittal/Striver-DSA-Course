/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform linear search for an element in the array
bool linearSearch(vector<int> a, int ele)
{
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == ele)
        {
            return true; // Element found
        }
    }
    return false; // Element not found
}

// Function to count the length of the longest consecutive sequence in the array
int CountLongestConsecutiveSequenceArray(vector<int> a, int n)
{
    // Sorting the array in ascending order
    sort(a.begin(), a.end());
    int longest = 1, countCurr = 0, lastSmaller = INT16_MIN;
    // Iterating through the sorted array
    for (int i = 0; i < n; i++)
    {
        // If the current element is one more than the previous, increase the count of the current sequence
        if (a[i] - 1 == lastSmaller)
        {
            countCurr += 1;
            lastSmaller = a[i];
        }
        // If the current element is equal to the previous, continue to the next element
        else if (a[i] == lastSmaller)
        {
            continue;
        }
        // If the current element is different from the previous, reset the current sequence count
        else if (a[i] != lastSmaller)
        {
            countCurr = 1;
            lastSmaller = a[i];
        }
        // Update the length of the longest consecutive sequence
        longest = max(longest, countCurr);
    }
    // Return the length of the longest consecutive sequence
    return longest;
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Display the original array
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find the count of longest consecutive sequence in the array
    cout << "The count of longest consecutive sequence in the array is: " << CountLongestConsecutiveSequenceArray(arr, n) << endl;

    return 0;
}

/*
Analysis of Problem

Name: Longest Consecutive Sequence
Time Complexity: O(N log N)
    - Sorting the array takes O(N log N) time, and then iterating through the sorted array takes linear time.
Space Complexity: O(1)
    - Only a few variables are used, resulting in constant space complexity.
*/
