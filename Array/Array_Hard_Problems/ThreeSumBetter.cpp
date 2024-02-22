#include <bits/stdc++.h>

using namespace std;

// Function to solve the Three Sum Problem
vector<vector<int>> ThreeSumProblem(vector<int> arr, int n)
{
    set<vector<int>> st; // Set to store unique triplets

    // Loop through each element in the array
    for (int i = 0; i < n; i++)
    {
        set<int> hashSet; // HashSet to store unique values

        // Loop through remaining elements in the array
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]); // Calculate the third element

            // If the third element exists in the hashSet, a triplet is found
            if (hashSet.find(third) != hashSet.end())
            {
                vector<int> temp = {arr[i], arr[j], third}; // Create the triplet
                sort(temp.begin(), temp.end());             // Sort the triplet
                st.insert(temp);                            // Insert the triplet into the set
            }
            hashSet.insert(arr[j]); // Insert the current element into the hashSet
        }
    }

    vector<vector<int>> ans(st.begin(), st.end()); // Convert set to vector
    return ans;
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
    O(N^2 * log(no. of unique triplets)), where N = size of the array.
Reason: Here, we are mainly using 2 nested loops. And inserting triplets into the set takes O(log(no. of unique triplets)) time complexity. But we are not considering the time complexity of sorting as we are just sorting 3 elements every time.

Space Complexity:
    O(2 * no. of the unique triplets) as we are using a set data structure and a list to store the triplets.
*/

