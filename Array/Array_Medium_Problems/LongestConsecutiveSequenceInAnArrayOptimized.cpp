/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to count the length of the longest consecutive sequence in the array
int CountLongestConsecutiveSequenceArray(vector<int> a, int n)
{
    // If the array is empty, return 0
    if (n == 0)
        return 0;

    // Initialize the length of the longest consecutive sequence to 1
    int longest = 1;

    // Create an unordered set to store unique elements of the array
    unordered_set<int> mySet;
    for (int i = 0; i < n; i++)
    {
        mySet.insert(a[i]);
    }

    // Iterate through the elements of the set
    for (auto it : mySet)
    {
        // If the current element is the start of a consecutive sequence
        if (mySet.find(it - 1) == mySet.end())
        {
            int count = 1; // Initialize the count of the current consecutive sequence
            int x = it;    // Initialize the current element
            // Increment the current element to find the consecutive sequence
            while (mySet.find(x + 1) != mySet.end())
            {
                x = x + 1;
                count++; // Increment the count for each consecutive element found
            }
            // Update the length of the longest consecutive sequence if needed
            longest = max(longest, count);
        }
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
Time Complexity: O(N)
    - The function iterates through the array once and performs constant-time operations inside the loop.
Space Complexity: O(N)
    - An unordered set is used to store unique elements of the array, resulting in space complexity proportional to the size of the array.
*/
