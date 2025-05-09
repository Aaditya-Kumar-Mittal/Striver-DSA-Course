#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Finds the kth missing number in the array using brute force approach.
 * @param arr The input array.
 * @param n The size of the array.
 * @param K The kth missing number to find.
 * @return The kth missing number.
 */
int findKthMissingNumberBrute1(vector<int> arr, int n, int K)
{
    if (K < arr[0])
    {
        return K;
    }
    if (K > arr[n - 1] - n)
    {
        return K + n;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= K)
        {
            K++;
        }
        else
        {
            break;
        }
    }
    return K;
}

/**
 * @brief Finds the kth missing number in the array using a different brute force approach.
 * @param arr The input array.
 * @param n The size of the array.
 * @param K The kth missing number to find.
 * @return The kth missing number.
 */
int findKthMissingNumberBrute2(vector<int> arr, int n, int K)
{
    if (K < arr[0])
    {
        return K;
    }
    if (K > arr[n - 1] - n)
    {
        return K + n;
    }

    int j = 1, i = 0;

    while (K > 0)
    {
        if (i < n && arr[i] == j)
        {
            i++;
        }
        else
        {
            K--;
        }
        j++;
    }

    return j - 1;
}

/**
 * @brief Finds the kth missing number in the array using binary search approach.
 * @param arr The input array.
 * @param n The size of the array.
 * @param K The kth missing number to find.
 * @return The kth missing number.
 */
int findKthMissingNumberBinarySearch(vector<int> arr, int n, int K)
{
    if (K < arr[0])
    {
        return K;
    }
    if (K > arr[n - 1] - n)
    {
        return K + n;
    }
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < K)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high + 1 + K;
}

int main()
{
    int n;
    cin >> n;

    vector<int> array(n);
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Printing Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    int K;
    cin >> K;

    cout << "The " << K << "th missing element in the array is: " << findKthMissingNumberBrute1(array, n, K) << endl;
    cout << "The " << K << "th missing element in the array is: " << findKthMissingNumberBrute2(array, n, K) << endl;
    cout << "The " << K << "th missing element in the array is: " << findKthMissingNumberBinarySearch(array, n, K) << endl;

    return 0;
}

/*

Analysis of Problem

Name: Finding the kth Missing Number in an Array

Time Complexity:
- Brute Force Approach 1: O(N)
- Brute Force Approach 2: O(N)
- Binary Search Approach: O(log N)

Space Complexity: O(1) for all approaches.

*/
