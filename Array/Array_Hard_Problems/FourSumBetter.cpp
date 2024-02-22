#include <bits/stdc++.h>

using namespace std;

// Function to solve the Four Sum Problem
vector<vector<int>> FourSumProblem(vector<int> arr, int n, int target) {
    set<vector<int>> st; // Set to store unique quadruplets

    // Nested loops to check all possible quadruplets
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashSet; // HashSet to store unique values
            for (int k = j + 1; k < n; k++) {
                // Calculate sum of first three elements
                long long sum = (long long)arr[i] + arr[j] + arr[k];
                // Calculate the fourth element to make sum equal to target
                long long fourth = target - sum;
                
                // If fourth element exists in hashSet, a quadruplet is found
                if (hashSet.find(fourth) != hashSet.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)fourth}; // Create the quadruplet
                    sort(temp.begin(), temp.end()); // Sort the quadruplet
                    st.insert(temp); // Insert the quadruplet into the set
                }
                // Insert the current element into the hashSet
                hashSet.insert(arr[k]);
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end()); // Convert set to vector
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int targetSum;
    cout << "Enter the target sum: ";
    cin >> targetSum;

    // Print the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Find and print Four Sum Quadruplets with target sum
    cout << "Four sum Quadruplets with target sum " << targetSum << " are:  " << endl;
    vector<vector<int>> ans = FourSumProblem(arr, n, targetSum);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "]\n";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers, your task is to find unique quadruplets that add up to give a target sum.

Time Complexity:
    O(N^3 * log(M)), where N = size of the array, M = no. of elements in the set.
Reason: The algorithm uses 3 nested loops to generate all possible triplets. Inside the loops, there are operations on the set data structure which take log(M) time complexity.

Space Complexity:
    O(2 * no. of quadruplets) + O(N), as space is used to store the answer and the array elements. We are using a set data structure and a list to store the quadruplets, and a set to store the array elements. So, the space complexity is O(no. of quadruplets) + O(N).
*/
