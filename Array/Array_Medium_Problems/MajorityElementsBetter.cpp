#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element in an array with more than n/2 occurrences
int MajorityElementN2(vector<int> v, int n)
{
    // Create a map to store the count of each element
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[v[i]]++;
    }

    // Traverse the map to find the element with occurrences greater than n/2
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first; // Return the majority element
        }
    }
    return -1; // If no majority element found, return -1
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

    // Print original array
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find and print the majority element
    cout << "Majority element with occurrences greater than n/2 is: " << MajorityElementN2(arr, n) << endl;

    return 0;
}

/*
Analysis of Problem:

Name: Majority Element (with more than n/2 occurrences)
Intuition: A majority element in an array occurs more than n/2 times. We can use a hash map to count the occurrences of each element.
Approach: Use a hash map to count the occurrences of each element. Then, iterate through the map to find the element with occurrences greater than n/2.
Time Complexity: O(n) - We traverse the array once and the map once.
Space Complexity: O(n) - We use extra space to store the count of each element in the hash map.
*/
