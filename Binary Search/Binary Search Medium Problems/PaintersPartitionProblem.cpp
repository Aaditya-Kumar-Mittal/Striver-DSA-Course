/*
Aaditya Kumar Mittal - All the bright and beautiful things fade so fast and they don't come back.
*/

#include <bits/stdc++.h>

using namespace std;

/**
 * Function to count the minimum number of painters required such that the time taken by each painter does not exceed 'time'.
 *
 * @param boards: A vector of integers representing the lengths of the boards.
 * @param n: The total number of boards.
 * @param time: The maximum time allowed for any painter.
 * @return The number of painters required.
 */
int countPainters(vector<int> &boards, int n, int time)
{
    int painters = 1;      // Initialize the number of painters required
    long long boardsPainter = 0; // To keep track of the time spent by the current painter

    for (int i = 0; i < n; i++)
    {
        if (boardsPainter + boards[i] <= time)
        {
            // If adding the current board to the current painter's workload does not exceed the limit
            boardsPainter += boards[i];
        }
        else
        {
            // Start a new painter with the current board
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

/**
 * Brute force approach to find the minimum possible time required to paint all boards by 'm' painters.
 *
 * @param boards: A vector of integers representing the lengths of the boards.
 * @param n: The total number of boards.
 * @param m: The number of painters.
 * @return The minimum time required to paint all boards.
 */
int minimumTimeMaxAreaBruteForce(vector<int> &boards, int n, int m)
{
    if (m > n)
    {
        // If there are more painters required than boards, it is impossible to split
        return -1;
    }

    int low = *max_element(boards.begin(), boards.end()); // Minimum possible time (longest single board)
    int high = accumulate(boards.begin(), boards.end(), 0); // Maximum possible time (sum of all board lengths)

    // Brute force search from the longest single board to the sum of all board lengths
    for (int time = low; time <= high; time++)
    {
        if (countPainters(boards, n, time) == m)
        {
            return time;
        }
    }

    return low; // Default return value in case of failure
}

/**
 * Optimized approach using binary search to find the minimum possible time required to paint all boards by 'm' painters.
 *
 * @param boards: A vector of integers representing the lengths of the boards.
 * @param n: The total number of boards.
 * @param m: The number of painters.
 * @return The minimum time required to paint all boards.
 */
int minimumTimeMaxAreaBinarySearch(vector<int> &boards, int n, int m)
{
    if (m > n)
    {
        // If there are more painters required than boards, it is impossible to split
        return -1;
    }

    int low = *max_element(boards.begin(), boards.end()); // Minimum possible time (longest single board)
    int high = accumulate(boards.begin(), boards.end(), 0); // Maximum possible time (sum of all board lengths)

    // Binary search to find the minimum possible time
    while (low <= high)
    {
        int mid = low + (high - low) / 2; // Middle point of the current range

        int painters = countPainters(boards, n, mid);

        if (painters > m)
        {
            // If more painters are needed, increase the lower bound
            low = mid + 1;
        }
        else
        {
            // Otherwise, decrease the upper bound
            high = mid - 1;
        }
    }
    return low; // The point where low meets high is the minimum time required
}

int main()
{
    int n;
    cout << "Enter the number of boards: ";
    cin >> n;

    vector<int> array(n);
    cout << "Enter the lengths of the boards: ";
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

    int numberOfPainters;
    cout << "Enter the number of painters: ";
    cin >> numberOfPainters;

    int bruteAns = minimumTimeMaxAreaBruteForce(array, n, numberOfPainters);
    cout << "The minimum time to paint all the boards (Brute Force Solution): " << bruteAns << endl;

    int binarySearchAns = minimumTimeMaxAreaBinarySearch(array, n, numberOfPainters);
    cout << "The minimum time to paint all the boards (Binary Search Solution): " << binarySearchAns << endl;

    return 0;
}

/*
Analysis of Problem

Name: Painter Partition Problem

Brute Force Solution:
Time Complexity: O(N * (sum(arr[])-max(arr[])+1))
    - Where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    - We are using a loop from max(arr[]) to sum(arr[]) to check all possible values of time. Inside the loop, we are calling the countPainters() function for each number. The countPainters() function has a time complexity of O(N).

Space Complexity: O(1)
    - We are not using any extra space to solve this problem.

Binary Search Solution:
Time Complexity: O(N * log(sum(arr[])-max(arr[])+1))
    - Where N = size of the array, sum(arr[]) = sum of all array elements, max(arr[]) = maximum of all array elements.
    - We are applying binary search on [max(arr[]), sum(arr[])]. Inside the loop, we are calling the countPainters() function for the value of ‘mid’. The countPainters() function has a time complexity of O(N).

Space Complexity: O(1)
    - We are not using any extra space to solve this problem.
*/
