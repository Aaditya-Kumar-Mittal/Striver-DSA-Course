# Rank Transform of an Array

<!-- markdownlint-disable MD024 -->

## Problem Description

Given an array of integers `arr`, replace each element in the array with its rank. The rank is determined based on the following rules:

- Rank is an integer starting from 1.
- The larger the element, the larger the rank.
- If two elements are equal, they share the same rank.
- Ranks should be as small as possible.

### Examples

#### Example 1

- **Input**: `[40, 10, 20, 30]`
- **Output**: `[4, 1, 2, 3]`
- **Explanation**: 40 is the largest element, 10 is the smallest, 20 is the second smallest, and 30 is the third smallest.

#### Example 2

- **Input**: `[100, 100, 100]`
- **Output**: `[1, 1, 1]`
- **Explanation**: All elements are the same, so they share the same rank.

#### Example 3

- **Input**: `[37, 12, 28, 9, 100, 56, 80, 5, 12]`
- **Output**: `[5, 3, 4, 2, 8, 6, 7, 1, 3]`

### Constraints

- `0 <= arr.length <= 10^5`
- `-10^9 <= arr[i] <= 10^9`

---

## Solution 1: Brute Force Solution

The brute force solution involves sorting the array to determine the rank of each element based on its order. This solution leverages a hash map to keep track of the rank for each unique element in the array.

### Implementation

```cpp
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    /**
     * @brief Returns the rank-transformed array.
     *
     * This function sorts a copy of the input array, assigns ranks to each unique element,
     * and then maps each element in the original array to its corresponding rank.
     *
     * @param arr Vector of integers representing the input array.
     * @return Vector of integers where each element is replaced with its rank.
     */
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        int n = arr.size();

        // Create a sorted copy of the array
        std::vector<int> sortedArr = arr;
        std::sort(sortedArr.begin(), sortedArr.end());

        // Map to store the rank of each unique element
        std::unordered_map<int, int> rankMap;
        int rank = 1;

        // Assign ranks based on sorted array
        for (int i = 0; i < n; i++) {
            if (rankMap.find(sortedArr[i]) == rankMap.end()) {
                rankMap[sortedArr[i]] = rank;
                rank++;
            }
        }

        // Generate the rank array for the original array
        std::vector<int> rankArr(n);
        for (int i = 0; i < n; i++) {
            rankArr[i] = rankMap[arr[i]];
        }

        return rankArr;
    }
};

inline const auto optimize = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
```

---

## Solution 2: Min-Heap Solution

In this approach, we use a min-heap to pop elements in increasing order and assign ranks based on the sorted order of elements. This method avoids explicitly sorting the array by directly using a min-heap to track element order.

### Implementation

```cpp
#include <vector>
#include <queue>
#include <utility>

class Solution {
public:
    /**
     * @brief Returns the rank-transformed array using a min-heap.
     *
     * This function uses a min-heap to process elements in increasing order
     * and assign ranks based on sorted positions.
     *
     * @param arr Vector of integers representing the input array.
     * @return Vector of integers where each element is replaced with its rank.
     */
    std::vector<int> arrayRankTransform(std::vector<int>& arr) {
        int n = arr.size();

        // Min-heap to store values and their original indices
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;

        // Push all elements into the priority queue
        for (int i = 0; i < n; i++) {
            pq.push({arr[i], i});
        }

        std::vector<int> ans(n, 0);
        int rank = 1;

        // Process elements from the priority queue
        while (!pq.empty()) {
            std::pair<int, int> temp = pq.top();
            ans[temp.second] = rank;
            pq.pop();

            // Only increase rank if the next element is different
            if (!pq.empty() && pq.top().first != temp.first) {
                rank++;
            }
        }

        return ans;
    }
};

inline const auto optimize = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
```

---

## Analysis

### Brute Force Solution

- **Problem Name**: Rank Transform of an Array
- **Time Complexity**: `O(n log n)` due to sorting the array.
- **Space Complexity**: `O(n)` for storing the sorted array and rank map.
- **Explanation**:
  1. Sorting the array requires `O(n log n)` time.
  2. Creating the rank map and accessing ranks takes `O(n)` space.
  3. Final rank assignment and map lookup contribute an additional `O(n)`.

### Min-Heap Solution

- **Problem Name**: Rank Transform of an Array
- **Time Complexity**: `O(n log n)` due to inserting elements into the min-heap.
- **Space Complexity**: `O(n)` for storing heap elements and the result array.
- **Explanation**:
  1. Inserting elements into a min-heap takes `O(n log n)` time.
  2. Extracting ranks and checking elements involves an additional `O(n)`.
  3. This approach efficiently handles unique ranks without explicitly sorting the entire array.

## Other Solutions

### Solution - 3

```cpp
static auto speedup = [](){
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);
    return NULL;
}();

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> vec;

        for (int i = 0; i < arr.size(); i++) vec.push_back(make_pair(arr[i], i));
        sort(vec.begin(), vec.end());

        int rank = 0;
        int prev = INT_MIN;
        for (const auto& p : vec) {
            if (prev < p.first) rank++;
            arr[p.second] = rank;
            prev = p.first;
        }

        return arr;
    }
};
```
