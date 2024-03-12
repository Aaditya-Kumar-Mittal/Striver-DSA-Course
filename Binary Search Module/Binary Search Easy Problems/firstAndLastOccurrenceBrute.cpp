/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Function to find the first and last occurrence of an element in the array using brute force approach
 * @param a The array of integers
 * @param n The size of the array
 * @param element The target element whose occurrences need to be found
 * @return A pair containing the indices of the first and last occurrence of the element
 */
pair<int, int> firstAndLastOccurrenceBrute(vector<int> a, int n, int element)
{
    int first = -1, last = -1;

    // Iterate through the array to find the first and last occurrence
    for (int i = 0; i < n; i++)
    {
        if (a[i] == element)
        {
            if (first == -1)
            {
                first = i; // Update first occurrence
            }
            last = i; // Update last occurrence
        }
    }

    return {first, last}; // Return pair of indices
}

int main()
{
    // Input size of the array
    int n;
    cin >> n;

    // Input elements of the array
    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    // Print the array elements
    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    // Input the target element to search for
    int target;
    cin >> target;

    // Find the first and last occurrence of the target element
    pair<int, int> ans = firstAndLastOccurrenceBrute(array, n, target);
    if (ans.first != -1 && ans.second != -1)
    {
        cout << "The first and the last occurrence of " << target << " in the given array is : " << ans.first << " and " << ans.second << endl;
    }
    else
    {
        cout << "The element " << target << " is not found in the array" << endl;
    }

    return 0;
}

/*
Analysis of Problem

Name: First and Last Occurrence of an Element in an Array

Time Complexity: O(n)
The brute force approach iterates through the array once to find the first and last occurrence of the element, resulting in a linear time complexity.

Space Complexity: O(1)
The space complexity is constant as the algorithm uses only a fixed amount of extra space regardless of the input size.
*/
