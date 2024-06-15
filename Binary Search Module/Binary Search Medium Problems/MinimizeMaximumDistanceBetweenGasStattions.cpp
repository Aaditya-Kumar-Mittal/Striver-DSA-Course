/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Function to minimize the maximum distance between gas stations using a brute force approach.
 *
 * @param arr: A vector of integers representing the positions of the existing gas stations.
 * @param k: An integer representing the number of additional gas stations to be added.
 * @return The minimized maximum distance between any two consecutive gas stations.
 */
long double minimizeMaxDistanceBrute(vector<int> &arr, int k)
{
    int n = arr.size();

    // Vector to store the number of additional gas stations placed between each pair of existing stations
    vector<int> howManyPlaced(n - 1, 0);

    // Adding 'k' additional gas stations
    for (int gasStations = 0; gasStations < k; gasStations++)
    {
        long double maxSectionLength = -1;
        int maxInd = -1;

        // Finding the section with the maximum length
        for (int i = 0; i < n - 1; i++)
        {
            long double difference = (arr[i + 1] - arr[i]);
            long double sectionLength = difference / ((long double)(howManyPlaced[i] + 1));

            if (sectionLength > maxSectionLength)
            {
                maxSectionLength = sectionLength;
                maxInd = i;
            }
        }

        // Placing an additional gas station in the section with the maximum length
        howManyPlaced[maxInd]++;
    }

    long double maxAns = -1;

    // Calculating the maximum section length after placing all additional gas stations
    for (int i = 0; i < n - 1; i++)
    {
        long double distance = arr[i + 1] - arr[i];
        long double sectionLength = distance / ((long double)(howManyPlaced[i] + 1));
        maxAns = max(maxAns, sectionLength);
    }

    return maxAns;
}

/**
 * Function to minimize the maximum distance between gas stations using a priority queue.
 *
 * @param arr: A vector of integers representing the positions of the existing gas stations.
 * @param k: An integer representing the number of additional gas stations to be added.
 * @return The minimized maximum distance between any two consecutive gas stations.
 */
long double minimizeMaxDistancePriorityQueue(vector<int> &arr, int k)
{
    int n = arr.size();

    // Vector to store the number of additional gas stations placed between each pair of existing stations
    vector<int> howManyPlaced(n - 1, 0);

    // Priority queue to keep track of the sections by their current length
    priority_queue<pair<long double, int>> pq;

    // Initial push of all sections into the priority queue
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    // Adding 'k' additional gas stations
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        // Extract the section with the maximum length
        auto top = pq.top();
        pq.pop();
        int sectionIndex = top.second;

        // Place an additional gas station in this section
        howManyPlaced[sectionIndex]++;

        long double initialDifference = arr[sectionIndex + 1] - arr[sectionIndex];
        long double newSectionLength = initialDifference / ((long double)howManyPlaced[sectionIndex] + 1);

        // Push the updated section length back into the priority queue
        pq.push({newSectionLength, sectionIndex});
    }

    // The top of the priority queue now holds the minimized maximum section length
    return pq.top().first;
}

/**
 * Helper function to calculate the number of gas stations required to ensure no section exceeds a given distance.
 *
 * @param distance: The maximum allowed distance between any two gas stations.
 * @param arr: A vector of integers representing the positions of the existing gas stations.
 * @return The number of additional gas stations required.
 */
int numberOfGasStationsRequired(long double distance, vector<int> &arr)
{
    int n = arr.size();
    int count = 0;

    for (int i = 1; i < n; i++)
    {
        int numberInBetween = ((arr[i] - arr[i - 1]) / distance);

        if ((arr[i] - arr[i - 1]) == (distance * numberInBetween))
        {
            numberInBetween--;
        }

        count += numberInBetween;
    }

    return count;
}

/**
 * Function to minimize the maximum distance between gas stations using binary search.
 *
 * @param arr: A vector of integers representing the positions of the existing gas stations.
 * @param k: An integer representing the number of additional gas stations to be added.
 * @return The minimized maximum distance between any two consecutive gas stations.
 */
long double minimizeMaxDistanceBinarySearch(vector<int> &arr, int k)
{
    int n = arr.size();

    // Setting initial bounds for binary search
    long double low = 0;
    long double high = 0;

    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (long double)(arr[i + 1] - arr[i]));
    }

    long double difference = 1e-6;

    while (high - low > difference)
    {
        long double mid = (low + high) / 2.0;
        int count = numberOfGasStationsRequired(mid, arr);

        if (count > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }

    return high;
}

int main()
{
    int n;
    cout << "Enter the number of existing gas stations: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the positions of the existing gas stations: ";
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
    cout << "Enter the number of additional gas stations to be added: ";
    cin >> k;

    long double bruteAns = minimizeMaxDistanceBrute(array, k);
    cout << "The minimized maximum distance between the gas stations is (Brute Solution): " << bruteAns << endl;

    long double priorityQueueAns = minimizeMaxDistancePriorityQueue(array, k);
    cout << "The minimized maximum distance between the gas stations is (Priority Queue Optimized Solution): " << priorityQueueAns << endl;

    long double binarySearchAns = minimizeMaxDistanceBinarySearch(array, k);
    cout << "The minimized maximum distance between the gas stations is (Binary Search Solution): " << binarySearchAns << endl;

    return 0;
}

/*
Analysis of Problem

Name: Minimize Maximum Distance Between Gas Stations

Time Complexity:
1. Brute Force: O(n * k)
   Where 'n' is the number of existing gas stations and 'k' is the number of additional gas stations.
   In each iteration for adding a gas station, we iterate through the 'n-1' sections to find the maximum section length.

2. Priority Queue: O(nlogn + klogn)
   - O(nlogn) for inserting all the initial sections into the priority queue.
   - O(klogn) for placing the gas stations, where each insertion takes logn time.

3. Binary Search: O(n * log(Len))
   - O(n) for calculating the number of gas stations required for each mid value.
   - O(log(Len)) for the binary search, where Len is the maximum initial section length.

Space Complexity:
1. Brute Force: O(n)
   For storing the 'howManyPlaced' vector which keeps track of the number of additional gas stations placed in each section.

2. Priority Queue: O(n)
   - O(n-1) for the 'howManyPlaced' vector.
   - O(n-1) for the priority queue.

3. Binary Search: O(1)
   No extra space required except for a few variables.
*/
