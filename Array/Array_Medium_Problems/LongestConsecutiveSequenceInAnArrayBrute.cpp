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
    int longest = 1;
    // Iterate through each element in the array
    for (int i = 0; i < n; i++)
    {
        int x = a[i];
        int count = 1;
        // Continue counting consecutive sequence as long as the next element is found
        while (linearSearch(a, x + 1) == true)
        {
            x = x + 1;
            count++;
        }
        // Update the length of the longest consecutive sequence
        longest = max(longest, count);
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
Time Complexity: O(N^2)
    - The main loop runs N times, and for each iteration, the linearSearch function may run up to N times in the worst case.
Space Complexity: O(1)
    - No extra space is used apart from a few variables, resulting in constant space complexity.
*/
