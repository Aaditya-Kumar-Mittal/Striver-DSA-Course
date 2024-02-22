#include <bits/stdc++.h>
using namespace std;

// Function to find elements that appear more than floor(N/3) times in the array
vector<int> MajorityElementNBy3(vector<int> &arr, int n)
{
    vector<int> list;
    unordered_map<int, int> mpp; // Using unordered_map for O(1) average insertion time

    int minCount = (n / 3) + 1; // Minimum count required for an element to be a majority element

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++; // Increment count of the current element

        if (mpp[arr[i]] == minCount)
        {                           // If the count reaches the minimum required count
            list.push_back(arr[i]); // Add the element to the result list
        }

        if (list.size() == 2) // If two majority elements are found, break the loop
            break;
    }

    return list; // Return the list of majority elements
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Print the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find and print majority elements occurring more than floor(n/3) times
    cout << "Printing the Majority Elements occurring floor (n/3) times: " << endl;
    vector<int> ans = MajorityElementNBy3(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector. Used Hashing
Time Complexity:
    O(N), where N = size of the given array.
Reason: We are using an unordered_map which has average insertion time complexity of O(1). So, iterating through N elements and inserting them results in O(N) time complexity.

Space Complexity:
    O(N) as we are using an unordered_map to store the count of each element. We are also using a list that stores a maximum of 2 elements. That space used is so small that it can be considered constant.
*/
