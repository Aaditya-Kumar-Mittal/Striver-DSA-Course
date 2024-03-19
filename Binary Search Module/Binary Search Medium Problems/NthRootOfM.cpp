/*

Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.

*/

#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Function to compute the power of a number.
 * @param n The exponent.
 * @param num The base number.
 * @return The result of num raised to the power of n.
 */
int func1(int n, int num)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= num;
    }
    return ans;
}

/**
 * @brief Finds the nth root of m using brute force approach.
 * @param n The value of n.
 * @param m The value of m.
 * @return The nth root of m.
 */
int NthRootOfMBruteForceApproach(int n, int m)
{
    for (int i = 1; i < m; i++)
    {
        if (func1(i, n) == m)
        {
            return i;
        }
        else if (func1(i, n) > m)
        {
            break;
        }
    }
    return -1;
}

/**
 * @brief Helper function to perform binary search for finding the nth root of m.
 * @param mid The mid value.
 * @param n The value of n.
 * @param m The value of m.
 * @return 1 if ans==n, 0 if ans<n, 2 if ans>n.
 */
int function2(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 0; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > n)
        {
            return 2;
        }
    }
    if (ans == n)
    {
        return 1;
    }
    if (ans < n)
    {
        return 0;
    }
}

/**
 * @brief Finds the nth root of m using binary search approach.
 * @param n The value of n.
 * @param m The value of m.
 * @return The nth root of m.
 */
int NthRootOfMBinarySearch(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midN = function2(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int k, l;
    cin >> k >> l;

    int ans = NthRootOfMBruteForceApproach(k, l);
    cout << k << "th Root of " << l << " is : " << ans << endl;
    int ans1 = NthRootOfMBinarySearch(k, l);
    cout << k << "th Root of " << l << " is : " << ans1 << endl;

    return 0;
}

/*

Analysis of Problem

Name: Finding the nth root of m

Time Complexity:
    - Brute Force Approach: O(m), where m is the number for which we are finding the nth root. The algorithm iterates from 1 to m to find the nth root.
    - Binary Search Approach: O(log m * n), where m is the number for which we are finding the nth root and n is the value of n. Binary search is employed to find the nth root.

Space Complexity: O(1). The algorithms use only a constant amount of extra space for variables regardless of the size of the input numbers.

*/
