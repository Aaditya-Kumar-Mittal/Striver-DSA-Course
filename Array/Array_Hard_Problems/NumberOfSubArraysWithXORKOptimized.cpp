#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Count the number of subarrays with XOR equal to a given target.
 *
 * @param a The input array.
 * @param n The size of the array.
 * @param target The target XOR value.
 * @return int The count of subarrays with XOR equal to the target.
 */
int countNumberOfSubarraywithXORk(vector<int> a, int n, int target)
{
    // Initialize the XOR value and the map to store prefix XOR and their counts
    int XR = 0;
    map<int, int> mpp;
    // Initialize the count of XOR 0 as 1
    mpp[XR]++;

    int count = 0;

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // Update the XOR value for the current element
        XR = XR ^ a[i];

        // Calculate the XOR value needed to achieve the target
        int x = XR ^ target;

        // Add the count of previous XOR values found
        count += mpp[x];

        // Increment the count of current XOR value
        mpp[XR]++;
    }

    return count;
}

int main()
{
    // Input the size of the array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    // Input the elements of the array
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Input the target XOR value
    int K;
    cout << "Enter the target XOR value: ";
    cin >> K;

    // Output the array elements
    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Output the count of subarrays with XOR equal to the target
    cout << "Printing the count of subarrays with XOR equal to " << K << endl;
    cout << countNumberOfSubarraywithXORk(arr, n, K) << endl;

    return 0;
}

/*
Analysis:

Observation:
Assume the prefix XOR of a subarray ending at index i is `xr`. In that subarray, we will search for another subarray ending at index i, whose XOR is equal to k. Here, we need to observe that if there exists another subarray ending at index i with XOR k, then the prefix XOR of the rest of the subarray will be `xr^k`.

Approach:
- We declare a map to store the prefix XORs and their counts.
- Set the value of 0 as 1 on the map.
- Iterate through the array and for each index i, we:
  - XOR the current element to the existing prefix XOR.
  - Calculate the prefix XOR for which we need the occurrence.
  - Add the occurrence of the prefix XOR to our answer.
  - Store the current prefix XOR in the map increasing its occurrence by 1.

Time Complexity:
- O(N) or O(N*logN) depending on which map data structure we are using, where N is the size of the array.
- For example, if we are using an unordered_map data structure in C++, the time complexity will be O(N), but if we are using a map data structure, the time complexity will be O(N*logN). The least complexity will be O(N) as we are using a loop to traverse the array.

Space Complexity:
- O(N) as we are using a map data structure.
*/
