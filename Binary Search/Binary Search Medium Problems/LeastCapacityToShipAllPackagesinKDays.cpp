#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/**
 * @brief Counts the number of days required to ship packages given the capacity of each day.
 * @param weights Vector containing the weights of packages.
 * @param capacity The capacity of each day.
 * @return The number of days required to ship all packages.
 */
int dayCounter(vector<int> weights, int capacity)
{
    int countDays = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > capacity)
        {
            countDays += 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return countDays;
}

/**
 * @brief Finds the least capacity required to ship all packages within K days using brute force approach.
 * @param weights Vector containing the weights of packages.
 * @param n Size of the array.
 * @param Kdays The maximum number of days allowed to ship all packages.
 * @return The least capacity required to ship all packages within K days.
 */
int leastCapacityToShipPackagesinKDaysBrute(vector<int> weights, int n, int Kdays)
{
    int maxEle = *max_element(weights.begin(), weights.end());
    int sumEle = accumulate(weights.begin(), weights.end(), 0);
    for (int capacity = maxEle; capacity < sumEle; capacity++)
    {
        int daysRequired = dayCounter(weights, capacity);
        if (daysRequired <= Kdays)
        {
            return capacity;
        }
    }
    return -1;
}

/**
 * @brief Finds the least capacity required to ship all packages within K days using binary search approach.
 * @param weights Vector containing the weights of packages.
 * @param n Size of the array.
 * @param Kdays The maximum number of days allowed to ship all packages.
 * @return The least capacity required to ship all packages within K days.
 */
int leastCapacityToShipPackagesinKDaysBinarySearch(vector<int> weights, int n, int Kdays)
{
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
    int ans = high;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int daysRequired = dayCounter(weights, mid);
        if (daysRequired <= Kdays)
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

    int days;
    cin >> days;

    cout << "Least Capacity to ship all packages within " << days << " days are: " << leastCapacityToShipPackagesinKDaysBrute(array, n, days) << endl;
    cout << "Least Capacity to ship all packages within " << days << " days are: " << leastCapacityToShipPackagesinKDaysBinarySearch(array, n, days) << endl;

    return 0;
}

/*

Analysis of Problem

Name: Least Capacity to Ship Packages in K Days

Time Complexity:
    - Brute Force Approach: O((sumWeight - maxWeight + 1) * N), where maxWeight is the maximum weight of a package, sumWeight is the sum of weights of all packages, and N is the number of packages. It involves iterating over all possible capacities between the maximum weight and the sum of weights.
    - Binary Search Approach: O(N * log(sumWeight - maxWeight + 1)), where maxWeight is the maximum weight of a package and N is the number of packages. Binary search is used to find the least capacity required.

Space Complexity: O(1) for both approaches. They only use a constant amount of extra space.

*/ 
