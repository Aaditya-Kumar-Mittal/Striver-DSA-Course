#include <bits/stdc++.h>
using namespace std;

// Function to find the next lexicographically greater permutation of a sequence
vector<int> nextGreaterPermutation(vector<int> a, int n)
{
    int index = -1;

    // Step 1: Find the breakpoint
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }

    // Step 2: If no breakpoint found, reverse the array
    if (index == -1)
    {
        reverse(a.begin(), a.end());
        return a;
    }

    // Step 3: Find the next greater element and swap
    for (int i = n - 1; i > index; i--)
    {
        if (a[i] > a[index])
        {
            swap(a[i], a[index]);
            break;
        }
    }

    // Step 4: Reverse the right half of the array
    reverse(a.begin() + index + 1, a.end());

    return a;
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

    // Find the next greater permutation
    vector<int> nextPerm = nextGreaterPermutation(arr, n);

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

Name: Next Greater Permutation
- Intuition: The problem involves finding the lexicographically next greater permutation of a given sequence of numbers.
- Approach:
  1. Find the breakpoint where the current permutation can be modified to get the next greater permutation.
  2. Find the next greater element and swap it with the element at the breakpoint.
  3. Reverse the right half of the array to get the next permutation.


Time Complexity: O(3N), where N = size of the given array
Finding the break-point, finding the next greater element, and reversal at the end takes O(N) for each, where N is the number of elements in the input array. This sums up to 3*O(N) which is approximately O(3N).

Space Complexity: Since no extra storage is required. Thus, its space complexity is O(1).
*/
