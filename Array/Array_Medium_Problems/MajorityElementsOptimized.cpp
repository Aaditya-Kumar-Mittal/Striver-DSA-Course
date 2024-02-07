#include <bits/stdc++.h>
using namespace std;

// Function to find the majority element in an array with more than n/2 occurrences
int MajorityElementN2Optimized(vector<int> v, int n)
{
    int count = 0, ele;

    // Find potential majority element using Moore's Voting Algorithm
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            // If count becomes 0, update potential majority element
            ele = v[i];
            count = 1;
        }
        else if (v[i] == ele)
        {
            // If current element is equal to potential majority element, increment count
            count++;
        }
        else
        {
            // If current element is different from potential majority element, decrement count
            count--;
        }
    }

    // Verify if the potential majority element is the majority element by counting occurrences
    int count1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == ele)
        {
            count1++;
        }
    }

    // If occurrences of potential majority element is greater than n/2, return it as the majority element
    if (count1 > (n / 2))
    {
        return ele;
    }
    else
    {
        return -1; // If no majority element found, return -1
    }
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
    cout << "Majority element with occurrences greater than n/2 is: " << MajorityElementN2Optimized(arr, n) << endl;

    return 0;
}

/*
Analysis of Problem:

Name: Moore's Voting Algorithm for Majority Element
Intuition: Moore's Voting Algorithm finds the potential majority element in a single pass through the array.
Approach: Traverse the array to find the potential majority element using a count variable. Then, verify if the potential majority element is the actual majority element by counting its occurrences.
Time Complexity: O(n) - Single pass through the array.
Space Complexity: O(1) - Constant extra space used.
*/
