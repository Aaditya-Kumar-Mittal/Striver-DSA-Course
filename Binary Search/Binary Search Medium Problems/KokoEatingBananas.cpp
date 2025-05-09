#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Calculates the total hours required to eat all bananas at the given rate.
 * @param a Vector containing the number of bananas each pile has.
 * @param hourly Rate at which bananas are eaten per hour.
 * @return Total hours required to eat all bananas.
 */
int totalHours(vector<int> a, int hourly)
{
    int tH = 0;
    for (int i = 0; i < a.size(); i++)
    {
        tH += ceil((double)a[i] / (double)hourly);
    }
    return tH;
}

/**
 * @brief Finds the minimum eating rate using brute force approach.
 * @param a Vector containing the number of bananas each pile has.
 * @param n Size of the vector.
 * @param hours Total available hours to eat all bananas.
 * @return Minimum eating rate required to eat all bananas within given hours.
 */
int KokoEatingBananasBrute(vector<int> a, int n, int hours)
{
    int maxi = *max_element(a.begin(), a.end());
    for (int i = 1; i < maxi; i++)
    {
        int reqTime = totalHours(a, i);
        if (reqTime <= hours)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the minimum eating rate using binary search approach.
 * @param a Vector containing the number of bananas each pile has.
 * @param n Size of the vector.
 * @param hours Total available hours to eat all bananas.
 * @return Minimum eating rate required to eat all bananas within given hours.
 */
int KokoEatingBananasBinarySearch(vector<int> a, int n, int hours)
{
    int low = 1, high = *max_element(a.begin(), a.end()), ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int reqTime = totalHours(a, mid);
        if (reqTime <= hours)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
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

    int hourly;
    cin >> hourly;

    cout << "Koko will eat all the bananas in time (hours): " << KokoEatingBananasBrute(array, n, hourly) << endl;
    cout << "Koko will eat all the bananas in time (hours): " << KokoEatingBananasBinarySearch(array, n, hourly) << endl;

    return 0;
}

/*

Analysis of Problem

Name: Koko Eating Bananas

Time Complexity:
    - Brute Force Approach: O(N * M), where N is the number of piles of bananas and M is the maximum number of bananas in any pile. It involves iterating over all possible eating rates up to M.
    - Binary Search Approach: O(N * log(M)), where N is the number of piles of bananas and M is the maximum number of bananas in any pile. Binary search is used to find the minimum eating rate.

Space Complexity: O(1) for both approaches. They only use a constant amount of extra space.

*/
