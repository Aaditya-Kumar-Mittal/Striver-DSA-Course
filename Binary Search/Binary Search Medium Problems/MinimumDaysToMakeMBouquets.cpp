#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Checks if it's possible to make M bouquets in K days with flowers of up to day days.
 * @param a Vector containing the number of flowers blooming on each day.
 * @param day The maximum number of days a flower can be bloomed.
 * @param K The number of days available to make bouquets.
 * @param M The number of bouquets to make.
 * @return True if it's possible to make M bouquets in K days, false otherwise.
 */
bool possibleDays(vector<int> a, int day, int K, int M)
{
    int countDay = 0;
    int madeBouquets = 0;

    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] <= day)
        {
            countDay++;
        }
        else
        {
            madeBouquets += (countDay / K);
            countDay = 0;
        }
    }
    madeBouquets += (countDay / K);
    return madeBouquets >= M;
}

/**
 * @brief Finds the minimum number of days to make M bouquets using brute force approach.
 * @param a Vector containing the number of flowers blooming on each day.
 * @param size The size of the vector.
 * @param K The number of days available to make bouquets.
 * @param M The number of bouquets to make.
 * @return Minimum number of days required to make M bouquets, or -1 if it's impossible.
 */
int minimumNoOfDaysMBouquetsBrute(vector<int> a, int size, int K, int M)
{
    long long val = M * 1ll * K * 1ll;
    if (size < val)
    {
        return -1;
    }

    int mini = *min_element(a.begin(), a.end());
    int maxi = *max_element(a.begin(), a.end());

    for (int i = mini; i <= maxi; i++)
    {
        if (possibleDays(a, i, K, M))
        {
            return i;
        }
    }
    return -1;
}

/**
 * @brief Finds the minimum number of days to make M bouquets using binary search approach.
 * @param a Vector containing the number of flowers blooming on each day.
 * @param size The size of the vector.
 * @param K The number of days available to make bouquets.
 * @param M The number of bouquets to make.
 * @return Minimum number of days required to make M bouquets, or -1 if it's impossible.
 */
int minimumNoOfDaysMBouquetsBinarySearch(vector<int> a, int size, int K, int M)
{
    long long val = M * 1ll * K * 1ll;
    if (size < val)
    {
        return -1;
    }

    int low = *min_element(a.begin(), a.end());
    int high = *max_element(a.begin(), a.end());
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (possibleDays(a, mid, K, M))
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

    int noOfBouquets, flowersRequired;
    cin >> noOfBouquets >> flowersRequired;

    cout << "Minimum no of days to make " << noOfBouquets << " bouquets are: " << minimumNoOfDaysMBouquetsBrute(array, n, flowersRequired, noOfBouquets) << endl;
    cout << "Minimum no of days to make " << noOfBouquets << " bouquets are: " << minimumNoOfDaysMBouquetsBinarySearch(array, n, flowersRequired, noOfBouquets) << endl;
    return 0;
}

/*

Analysis of Problem

Name: Minimum Number of Days to Make M Bouquets

Time Complexity:
    - Brute Force Approach: O((max - min) * N), where N is the size of the array and max and min are the maximum and minimum values in the array, respectively. It involves iterating over all possible days within the range of min to max.
    - Binary Search Approach: O(N * log(max - min)), where N is the size of the array and max and min are the maximum and minimum values in the array, respectively. Binary search is used to find the minimum number of days required.

Space Complexity: O(1) for both approaches. They only use a constant amount of extra space.

*/
