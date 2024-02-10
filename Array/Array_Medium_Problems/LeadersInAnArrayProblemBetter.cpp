/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find leaders in an array
vector<int> LeadersInAnArray(vector<int> a, int n)
{
    // Initialize an empty vector to store leaders
    vector<int> ans;

    // Iterate through each element in the array
    for (int i = 0; i < n; i++)
    {
        // Assume the current element is a leader
        bool leader = true;

        // Check elements to the right of the current element
        for (int j = i + 1; j < n; j++)
        {
            // If any element to the right is greater, the current element is not a leader
            if (a[j] > a[i])
            {
                leader = false;
                break;
            }
        }

        // If the current element is a leader, add it to the answer vector
        if (leader)
        {
            ans.push_back(a[i]);
        }
    }

    // Return the vector containing leaders
    return ans;
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

    // Find leaders in the array
    vector<int> leads = LeadersInAnArray(arr, n);

    // Display the leaders in the array
    std::cout << "The leaders in the given array are:  " << std::endl;
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

Intuition: The problem aims to find all the leaders in an array, where a leader is an element that is greater than or equal to all the elements to its right.

Approach:
1. **Brute Force Iteration**: Start iterating through the array from left to right.
2. **Check for Leaders**: For each element, iterate through all the elements to its right. If any element to the right is greater than the current element, it cannot be a leader. If no such element is found, the current element is a leader.
3. **Collect Leaders**: Store all the leaders found in a separate array.

Time Complexity:
- **Brute Force Iteration**: O(n^2) - Nested loops are used where each element is compared with all elements to its right.
- Overall time complexity: O(n^2).

Space Complexity:
- **Output Array**: O(n) - Additional space is required to store the leaders found.
- Overall space complexity: O(n).

*/
