#include <bits/stdc++.h>
using namespace std;

vector<int> LeadersInAnArray(vector<int> a, int n)
{
    // Initialize a vector to store the leaders found
    vector<int> ans;

    // Iterate through the array from right to left
    int maxRight = INT_MIN; // Initialize the maximum element encountered so far
    for (int i = n - 1; i >= 0; i--)
    {
        // Check if the current element is greater than or equal to the maximum element encountered so far
        if (a[i] >= maxRight)
        {
            // If yes, update the maximum element
            maxRight = a[i];
            // Add the current element to the leaders list
            ans.push_back(a[i]);
        }
    }

    // Reverse the leaders list to maintain the original order
    reverse(ans.begin(), ans.end());

    // Return the list of leaders
    return ans;
}

int main()
{
    // Input the size of the array
    int n;
    cin >> n;

    // Input the array elements
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Output the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find the leaders in the array
    vector<int> leads = LeadersInAnArray(arr, n);

    // Output the leaders found
    std::cout << "The leaders in the given array are: " << std::endl;
    for (int i = 0; i < leads.size(); i++)
    {
        cout << leads[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Name: Leaders in an Array

Time Complexity: O(N)
- Single pass through the array from right to left.

Space Complexity: O(N)
- Additional space is required to store the leaders found.
- Output vector of leaders has a space complexity of O(N).
*/
