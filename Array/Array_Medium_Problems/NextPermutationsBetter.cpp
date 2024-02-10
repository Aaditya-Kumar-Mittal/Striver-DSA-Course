#include <bits/stdc++.h>
using namespace std;

// Function to find the next lexicographically greater permutation of a sequence
vector<int> nextPermutation(vector<int> a, int n)
{
    // Using C++ standard library function to find next permutation
    next_permutation(a.begin(), a.end());

    return a; // Return the next permutation
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input array
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Find the next permutation
    vector<int> nextPerm = nextPermutation(arr, n);

    // Output the next permutation
    cout << "Next Permutation: ";
    for (int i = 0; i < n; i++)
    {
        cout << nextPerm[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem:

Name: Next Permutation
- The problem involves finding the lexicographically next greater permutation of a given sequence of numbers.
- The C++ standard library function next_permutation() is used to find the next permutation.
- Time Complexity: O(N log N), where N is the size of the input array.
- Space Complexity: O(N) for storing the input array.
*/
