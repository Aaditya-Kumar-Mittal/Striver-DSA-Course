#include <bits/stdc++.h>
using namespace std;

// Function to find elements that appear more than floor(N/3) times in the array
vector<int> MajorityElementNBy3(vector<int> &arr, int n)
{
    int count1 = 0, count2 = 0, ele1 = INT_MIN, ele2 = INT_MIN;

    // Finding potential majority elements
    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && ele2 != arr[i])
        {
            count1 = 1;
            ele1 = arr[i];
        }
        else if (count2 == 0 && ele1 != arr[i])
        {
            count2 = 1;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1)
            count1++;
        else if (arr[i] == ele2)
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }

    // Manually check if the stored elements in
    // ele1 and ele2 are the majority elements:
    count1 = 0, count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
            count1++;
        if (arr[i] == ele2)
            count2++;
    }

    // Minimum count required for an element to be a majority element
    int minCount = (n / 3) + 1;
    vector<int> list;

    if (count1 >= minCount)
        list.push_back(ele1);

    if (count2 >= minCount)
        list.push_back(ele2);

    return list; // Return the list of majority elements
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

    // Find and print majority elements occurring more than floor(n/3) times
    cout << "Printing the Majority Elements occurring floor (n/3) times: " << endl;
    vector<int> ans = MajorityElementNBy3(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Analysis of Problem

Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

Time Complexity:
    O(N), where N = size of the given array.
Reason: The first O(N) is to calculate the counts and find the expected majority elements. The second one is to check if the calculated elements are the majority ones or not.

Space Complexity:
    O(1) as we are only using a list that stores a maximum of 2 elements. The space used is so small that it can be considered constant.
*/
