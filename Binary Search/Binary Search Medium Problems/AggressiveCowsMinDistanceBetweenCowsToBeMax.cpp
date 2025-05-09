#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Checks if it is possible to place cows with given distance.
 * @param places Array of places where cows can be placed.
 * @param n Size of the array.
 * @param distance Minimum distance between two cows.
 * @param cows Number of cows to be placed.
 * @return True if cows can be placed with given distance, false otherwise.
 */
bool canWePlaceCows(vector<int> &places, int n, int distance, int cows)
{
    int countCows = 1;
    int lastCowPlace = places[0];

    for (int i = 1; i < n; i++)
    {
        if (places[i] - lastCowPlace >= distance)
        {
            countCows++;
            lastCowPlace = places[i];
        }

        if (countCows >= cows)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief Finds the maximum of the minimum distance between two aggressive cows using brute force approach.
 * @param places Array of places where cows can be placed.
 * @param n Size of the array.
 * @param cows Number of cows to be placed.
 * @return The maximum of the minimum distance between two consecutive cows.
 */
int maxOfTheMinDistaceBetween2AggressiveCowsBrute(vector<int> &places, int n, int cows)
{
    sort(places.begin(), places.end());

    for (int distance = 1; distance <= (places[n - 1] - places[0]); distance++)
    {
        if (canWePlaceCows(places, n, distance, cows))
        {
            continue;
        }
        else
        {
            return distance - 1;
        }
    }
    return places[n - 1] - places[0];
}

/**
 * @brief Finds the maximum of the minimum distance between two aggressive cows using binary search approach.
 * @param places Array of places where cows can be placed.
 * @param n Size of the array.
 * @param cows Number of cows to be placed.
 * @return The maximum of the minimum distance between two consecutive cows.
 */
int maxOfTheMinDistaceBetween2AggressiveCowsBinarySearch(vector<int> &places, int n, int cows)
{
    sort(places.begin(), places.end());

    int low = 1, high = places[n - 1] - places[0];
    int ans = places[n - 1] - places[0];

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (canWePlaceCows(places, n, mid, cows))
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

    int cows;
    cin >> cows;

    cout << "Max of the minimum distance between two consecutive cows is: " << maxOfTheMinDistaceBetween2AggressiveCowsBrute(array, n, cows) << endl;
    cout << "Max of the minimum distance between two consecutive cows is: " << maxOfTheMinDistaceBetween2AggressiveCowsBinarySearch(array, n, cows) << endl;

    return 0;
}

/*

Analysis of Problem

Name: Max of the Minimum Distance Between Two Aggressive Cows

Time Complexity:
- Brute Force Approach: O(N^2 log N) due to sorting.
- Binary Search Approach: O(N log N + N log (max distance)) where N is the number of places.

Space Complexity: O(N) for storing the array of places.

*/
