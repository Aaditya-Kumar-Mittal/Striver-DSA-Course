#include <bits/stdc++.h>
using namespace std;

// Function to find elements that appear more than floor(N/3) times in the array
vector<int> MajorityElementNBy3(vector<int> &arr, int n)
{
    vector<int> list; // Vector to store the majority elements
    for (int i = 0; i < n; i++)
    {

        // Check if the list is empty or the current element is different from the first element in the list
        if (list.size() == 0 || list[0] != arr[i])
        {
            int count = 0; // Counter to count occurrences of the current element
            // Iterate through the array to count occurrences of the current element
            for (int j = 0; j < n; j++)
            {
                if (arr[j] == arr[i])
                {
                    count++;
                }
            }

            // If the count of the current element is greater than floor(n/3), add it to the list
            if (count > (n / 3))
            {
                list.push_back(arr[i]);
            }
        }

        // If two majority elements are found, break the loop
        if (list.size() == 2)
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

Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

Time Complexity:
    O(N^2), where N = size of the given array.
Reason: For every element of the array, the inner loop runs for N times. And there are N elements in the array. So, the total time complexity is O(N^2).

Space Complexity:
    O(1) as we are using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.
*/
