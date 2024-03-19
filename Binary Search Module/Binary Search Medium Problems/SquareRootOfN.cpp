/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the square root of a number using brute force approach.
 * @param num The number.
 * @return The square root of the number.
 */
int FindSquareRootBruteForceApproach(int num)
{
    int ans = 1;
    for (int i = 1; i < num; i++)
    {
        if (i * i <= num)
        {
            ans = i;
        }
        else
        {
            break;
        }
    }
    return ans;
}

/**
 * @brief Finds the square root of a number using binary search.
 * @param num The number.
 * @return The square root of the number.
 */
int FindSquareRootBinarySearch(int num)
{
    int ans = 1;
    int low = 1, high = num;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (mid * mid <= num)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
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

    int k;
    cin >> k;

    int ans = FindSquareRootBruteForceApproach(k);
    cout << "Square Root of " << k << " using brute force approach is: " << ans << endl;
    int ans1 = FindSquareRootBinarySearch(k);
    cout << "Square Root of " << k << " using binary search approach is: " << ans1 << endl;

    return 0;
}

/*

Analysis of Problem

Name: Finding the square root of a number

Time Complexity:
    - Brute Force Approach: O(sqrt(n)), where n is the number for which we are finding the square root. The algorithm iterates from 1 to sqrt(n) to find the square root.
    - Binary Search Approach: O(log n), where n is the number for which we are finding the square root. Binary search is employed to find the square root.

Space Complexity: O(1). The algorithms use only a constant amount of extra space for variables regardless of the size of the input number.

*/
