/*
Aaditya Kumar Mittal - Was a song once heard, but have been singing all my life.
*/

#include <bits/stdc++.h>
using namespace std;

int NumberOccurringOnce(vector<int> a, int n)
{
    // Find the max element
    int maxi = a[0];
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }

    vector<int> hash(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        if (hash[a[i]] == 1)
            return a[i];
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Printing Array Elements: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Element Appearing Once in a Twice Element Array is: " << NumberOccurringOnce(arr, n)
         << endl;

    return 0;
    
}

/*
Analysis of Problem

Name:- Number appearing once in twice array Better Approach(Using Hashing)

Intuition:
In the previous approach, we were finding the occurrence of an element using linear search. We can optimize this using hashing technique. We can simply hash the elements along with their occurrences in the form of (key, value) pair. Thus, we can reduce the cost of finding the occurrence and hence the time complexity.
Now, hashing can be done in two different ways and they are the following:
Array hashing(not applicable if the array contains negatives or very large numbers)
Hashing using the map data structure

Time Complexity: O(N)+O(N)+O(N), where N = size of the array
Reason: One O(N) is for finding the maximum, the second one is to hash the elements and the third one is to search the single element in the array.

Space Complexity: O(maxElement+1) where maxElement = the maximum element of the array.
*/