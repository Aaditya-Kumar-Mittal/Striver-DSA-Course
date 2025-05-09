# Minimize Max Distance to Gas Station

## Table of Contents

- [Minimize Max Distance to Gas Station](#minimize-max-distance-to-gas-station)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Brute Force Solution](#brute-force-solution)
    - [Priority Queue Optimization](#priority-queue-optimization)
    - [Binary Search Optimal Solution](#binary-search-optimal-solution)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
  - [My Submission](#my-submission)

---

## Introduction

This problem aims to **minimize the maximum distance** between adjacent gas stations after placing `k` additional stations. The original gas stations are placed on a **strictly increasing** horizontal number line, and you are to determine the **minimum possible value of the maximum gap** between stations **accurate to 2 decimal places**.

---

## Problem Description

Given:

- An array `stations` representing positions of gas stations on a number line.
- An integer `k`, representing the number of additional gas stations you can insert.

You need to insert these `k` gas stations such that the **maximum distance** between **any two adjacent gas stations** is minimized.

### Examples

#### Example 1

```plaintext
Input:
stations = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 9

Output:
0.50

Explanation:
Insert 1 station between each pair of adjacent stations to split the segments evenly.
```

#### Example 2

```plaintext
Input:
stations = [3, 6, 12, 19, 33, 44, 67, 72, 89, 95]
k = 2

Output:
14.00

Explanation:
Insert stations between the segments [44, 67] and [72, 89] to reduce the largest gap.
```

### Constraints

- `10 <= n <= 10000`
- `0 <= stations[i] <= 10^9`
- `0 <= k <= 10^5`
- `stations` is in **strictly increasing order**

---

## Approach

We explore three methods:

1. **Brute Force (Greedy Placement)**
2. **Priority Queue Optimization**
3. **Binary Search on Answer**

---

## Detailed Explanation of Code

### Brute Force Solution

This greedy approach places each new station iteratively in the segment which currently has the **largest section length**.

```cpp
long double findSmallestMaxDistBrute(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howManyPlaced(n-1 , 0);

    for(int station = 1; station <= k; station++) {
        long double maxSectionLength = -1;
        int maxSectionIndex = -1;

        for(int i = 0; i < n-1; i++) {
            long double sectionDifference = stations[i+1] - stations[i];
            long double sectionLength = sectionDifference / (howManyPlaced[i] + 1);
            if(maxSectionLength < sectionLength) {
                maxSectionLength = sectionLength;
                maxSectionIndex = i;
            }
        }

        howManyPlaced[maxSectionIndex]++;
    }

    long double maxSectionLength = -1;
    for(int i = 0; i < n-1; i++) {
        long double sectionDifference = stations[i+1] - stations[i];
        long double sectionLength = sectionDifference / (howManyPlaced[i] + 1);
        maxSectionLength = max(maxSectionLength, sectionLength);
    }

    return maxSectionLength;
}
```

---

### Priority Queue Optimization

We optimize the greedy approach using a **priority queue (max heap)** to always pick the segment with the largest current gap.

```cpp
double findSmallestMaxDistPQ(vector<int> &stations, int k) {
    int n = stations.size();
    vector<int> howManyPlaced(n-1 , 0);
    priority_queue<pair<double, int>> pq;

    for(int i = 0; i < n - 1; i++) {
        pq.push({stations[i+1] - stations[i], i});
    }

    for(int station = 1; station <= k; station++) {
        auto top = pq.top(); pq.pop();
        int sectionIndex = top.second;

        howManyPlaced[sectionIndex]++;
        double sectionDifference = stations[sectionIndex + 1] - stations[sectionIndex];
        double newSectionLength = sectionDifference / (howManyPlaced[sectionIndex] + 1);
        pq.push({newSectionLength, sectionIndex});
    }

    return pq.top().first;
}
```

---

### Binary Search Optimal Solution

We perform a **binary search** on the answer space from `0` to `max_gap` and check if a given distance `d` can be achieved using `k` or fewer stations.

```cpp
int numberRequired(double distance, vector<int> &arr) {
    int n = arr.size(), count = 0;
    for(int i = 1 ; i < n; i++) {
        int numberInBetween = (arr[i] - arr[i-1]) / distance;
        if((arr[i] - arr[i-1]) == (distance * numberInBetween)) numberInBetween--;
        count += numberInBetween;
    }
    return count;
}

double findSmallestMaxDist(vector<int> &stations, int k) {
    int n = stations.size();
    double low = 0, high = 0;

    for(int i = 0 ; i < n - 1; i++) {
        high = max(high, (double) stations[i + 1] - stations[i]);
    }

    double difference = 1e-7;
    while(high - low > difference) {
        double mid = (low + high) / 2.0;
        int getCount = numberRequired(mid, stations);
        if(getCount > k) low = mid;
        else high = mid;
    }

    return round(high * 100) / 100;
}
```

---

## Complexity Analysis

| Approach       | Time Complexity          | Space Complexity |
| -------------- | ------------------------ | ---------------- |
| Brute Force    | O(k \* n)                | O(n)             |
| Priority Queue | O(k \* log n)            | O(n)             |
| Binary Search  | O(n \* log(max_gap / ε)) | O(1)             |

- `ε` is the required precision (1e-7).
- Binary search is the most efficient and recommended for large input sizes.

---

## How to Run the Code

### For C++

1. **Install a C++ compiler (like g++):**

   ```bash
   sudo apt install g++
   ```

2. **Create a file `main.cpp` and paste the above code.**

3. **Compile and run:**

   ```bash
   g++ main.cpp -o main
   ./main
   ```

4. **Sample Input Usage:**

   ```cpp
   vector<int> stations = {3, 6, 12, 19, 33, 44, 67, 72, 89, 95};
   int k = 2;
   Solution obj;
   cout << obj.findSmallestMaxDist(stations, k) << endl;
   ```

---

## Other Solutions

## My Submission

```cpp

class Solution {
  public:
     long double findSmallestMaxDistBrute(vector<int> &stations, int k) {
        // Code here

        int n = stations.size();

        vector<int> howManyPlaced(n-1 , 0);

        for(int station = 1; station <= k; station++)
        {
            long double maxSectionLength = -1;

            int maxSectionIndex = -1;

            for(int i = 0; i < n-1; i++)
            {
                long double sectionDifference = stations[i+1] - stations[i];

                long double sectionLength = sectionDifference/ (long double) (howManyPlaced[i] + 1);

                if(maxSectionLength < sectionLength)
                {
                    maxSectionLength = sectionLength;

                    maxSectionIndex = i;
                }
            }

            howManyPlaced[maxSectionIndex]++;
        }

        long double maxSectionLength = -1;

        for(int i = 0; i < n-1; i++)
        {
            long double sectionDifference = stations[i+1] - stations[i];

            long double sectionLength = sectionDifference/ (long double) (howManyPlaced[i] + 1);

            maxSectionLength = max(maxSectionLength, sectionLength);
        }

        return maxSectionLength;
    }

    double findSmallestMaxDistPQ(vector<int> &stations, int k)
    {
        int n = stations.size();

        vector<int> howManyPlaced(n-1 , 0);

        priority_queue<pair<double, int>> pq;

        for(int i = 0; i < n - 1; i++)
        {
            pq.push({stations[i+1] - stations[i], i});
        }

        for(int station = 1; station <= k; station++)
        {
            auto top = pq.top();

            pq.pop();

            int sectionIndex = top.second;

            howManyPlaced[sectionIndex]++;

            double sectionDifference = stations[sectionIndex + 1] - stations[sectionIndex];

            double newSectionLength = sectionDifference/ (long double) (howManyPlaced[sectionIndex] + 1);

            pq.push({newSectionLength, sectionIndex});
        }

        return pq.top().first;

    }

    int numberRequired(double distance, vector<int> &arr)
    {
        int n = arr.size();

        int count = 0;

        for(int i = 1 ; i < n; i++)
        {
            int numberInBetween = (arr[i] - arr[i-1]) / distance;

            if((arr[i] - arr[i-1]) == (distance * numberInBetween)) numberInBetween--;

            count += numberInBetween;
        }

        return count;
    }

    double findSmallestMaxDist(vector<int> &stations, int k)
    {
        int n = stations.size();

        double low = 0, high = 0;

        for(int i = 0 ; i < n - 1; i++)
        {
            high = max(high, (double) stations[i + 1] - stations[i]);
        }

        double difference = 1e-7;

        while(high - low > difference)
        {
            double mid = (low + high) / 2.0;

            int getCount = numberRequired(mid, stations);

            if(getCount > k) low = mid;

            else high = mid;
        }

         return round(high * 100) / 100;
    }
};
```

```cpp
#include <bits/stdc++.h>

using namespace std;

int getNumberOfStations(double distance, vector<int> &arr)
{
  int n = arr.size();

  int count = 0;

  for (int i = 1; i < n; i++)
  {
    double gap = arr[i] - arr[i - 1];
    int stations = floor(gap / distance);

    // If gap divides perfectly, subtract 1 to avoid placing an extra station
    if (fabs(stations * distance - gap) < 1e-9)
      stations--;
    count += stations;
  }

  return count;
}

double minimiseMaxDistance(vector<int> &arr, int k)
{

  int n = arr.size();

  double low = 0, high = 0;

  for (int i = 0; i < n - 1; i++)
    high = max(high, (double)(arr[i + 1] - arr[i]));

  double difference = 1e-6;

  while (high - low > difference)
  {
    double mid = (high + low) / 2.0;

    int count = getNumberOfStations(mid, arr);

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

double minimiseMaxDistancePriorityQueue(vector<int> &arr, int k)
{

  int n = arr.size();

  vector<int> sectionCheck(n - 1, 0);

  priority_queue<pair<double, int>> pq;

  for (int i = 0; i < n - 1; i++)
    pq.push({arr[i + 1] - arr[i], i});

  for (int gasStation = 0; gasStation < k; gasStation++)
  {
    auto top = pq.top();
    pq.pop();
    int sectionIndex = top.second;

    sectionCheck[sectionIndex]++;

    double difference = arr[sectionIndex + 1] - arr[sectionIndex];
    double sectionLength = difference / ((long double)(sectionCheck[sectionIndex] + 1));

    pq.push({sectionLength, sectionIndex});
  }

  return pq.top().first;
}

double minimiseMaxDistanceBrute(vector<int> &arr, int k)
{
  // Write your code here.

  int n = arr.size();

  vector<int> sectionCheck(n - 1, 0);

  for (int gasStation = 0; gasStation < k; gasStation++)
  {
    double maxSectionLength = -1;

    int maxIndex = -1;

    for (int i = 0; i < n - 1; i++)
    {
      double difference = arr[i + 1] - arr[i];

      double sectionLength = difference / ((long double)(sectionCheck[i] + 1));

      if (sectionLength > maxSectionLength)
      {
        maxSectionLength = sectionLength;

        maxIndex = i;
      }
    }

    sectionCheck[maxIndex]++;
  }

  double maxAns = -1;

  for (int i = 0; i < n - 1; i++)
  {
    double difference = arr[i + 1] - arr[i];

    double sectionLength = difference / ((long double)(sectionCheck[i] + 1));

    maxAns = max(maxAns, sectionLength);
  }

  return maxAns;
}
```
