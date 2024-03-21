#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Calculates the sum of divisors for each element in the array.
 * @param a Vector containing the elements.
 * @param n Size of the array.
 * @param div The divisor to calculate the sum.
 * @return The sum of divisors.
 */
int sumOfDivs(vector<int> a, int n, int div)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)a[i] / double(div));
    }
    return sum;
}

/**
 * @brief Finds the smallest divisor given a threshold using brute force approach.
 * @param a Vector containing the elements.
 * @param n Size of the array.
 * @param threshold The threshold to compare the sum of divisors against.
 * @return The smallest divisor such that the sum of divisors is less than or equal to the threshold.
 */
int smallestDivisiorGivenThresholdBrute(vector<int> a, int n, int threshold)
{
    int maxi = *max_element(a.begin(), a.end());

    for (int i = 1; i <= maxi; i++)
    {
        int sumDivs = sumOfDivs(a, n, i);
        if (sumDivs <= threshold)
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the smallest divisor given a threshold using binary search approach.
 * @param a Vector containing the elements.
 * @param n Size of the array.
 * @param threshold The threshold to compare the sum of divisors against.
 * @return The smallest divisor such that the sum of divisors is less than or equal to the threshold.
 */
int smallestDivisiorGivenThresholdBinarySearch(vector<int> a, int n, int threshold)
{
    if (n > threshold)
        return -1;

    int low = 1, high = *max_element(a.begin(), a.end()), ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (sumOfDivs(a, n, mid) <= threshold)
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

    int threshold;
    cin >> threshold;

    cout << "Minimum number of divisors given a threshold are: " << smallestDivisiorGivenThresholdBrute(array, n, threshold) << endl;
    cout << "Minimum number of divisors given a threshold are: " << smallestDivisiorGivenThresholdBinarySearch(array, n, threshold) << endl;

    return 0;
}

/*

Analysis of Problem

Name: Smallest Divisor Given a Threshold

Time Complexity:
    - Brute Force Approach: O(max * N), where max is the maximum element in the array and N is the size of the array. It involves iterating over all possible divisors up to max.
    - Binary Search Approach: O(N * log(max)), where max is the maximum element in the array and N is the size of the array. Binary search is used to find the smallest divisor.

Space Complexity: O(1) for both approaches. They only use a constant amount of extra space.

*/
