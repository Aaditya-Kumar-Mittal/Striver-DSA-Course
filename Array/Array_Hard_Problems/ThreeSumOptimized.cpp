#include <bits/stdc++.h>

using namespace std;

// Function to solve the Three Sum Problem
vector<vector<int>> ThreeSumProblem(vector<int> arr, int n)
{
    vector<vector<int>> ans;      // Vector to store triplets with sum 0
    sort(arr.begin(), arr.end()); // Sort the input array

    // Loop through each element in the array
    for (int i = 0; i < n; i++)
    {
        // Skip duplicates of i
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1; // Pointer j starts at i + 1
        int k = n - 1; // Pointer k starts at the end of the array

        // Two-pointer technique
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k]; // Calculate the sum of triplet

            // If sum is less than 0, increment j to move towards larger elements
            if (sum < 0)
                j++;
            // If sum is greater than 0, decrement k to move towards smaller elements
            else if (sum > 0)
                k--;
            // If sum is zero, triplet found
            else
            {
                // Add triplet to the result
                ans.push_back({arr[i], arr[j], arr[k]});
                j++; // Increment j
                k--; // Decrement k

                // Skip duplicates of j and k
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans; // Return the result
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

    // Find and print Three Sum Triplets with sum 0
    cout << "Three Sum Triplets with sum 0 are:  " << endl;
    vector<vector<int>> ans = ThreeSumProblem(arr, n);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "]\n";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, your task is to find unique triplets that add up to give a sum of zero. In short, you need to return an array of all the unique triplets [arr[a], arr[b], arr[c]] such that i!=j, j!=k, k!=i, and their sum is equal to zero.

Time Complexity:
    O(NlogN) + O(N^2), where N = size of the array.
Reason: The input array is sorted in O(NlogN) time. Then, the nested loop runs approximately O(N^2) times to find triplets with sum 0.

Space Complexity:
    O(no. of triplets), as space is used to store the answer. We are not using any extra space to solve this problem. So, from that perspective, space complexity can be written as O(1).
*/
