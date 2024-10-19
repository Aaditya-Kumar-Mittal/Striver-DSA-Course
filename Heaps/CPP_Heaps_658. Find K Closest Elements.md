# 658. Find K Closest Elements

## Table of Contents

- [658. Find K Closest Elements](#658-find-k-closest-elements)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Input/Output](#inputoutput)
    - [Constraints](#constraints)
    - [Closeness Criteria](#closeness-criteria)
  - [Solution Overview](#solution-overview)
    - [Approach](#approach)
    - [Why a Max-Heap?](#why-a-max-heap)
  - [Code Explanation](#code-explanation)
    - [Explanation](#explanation)
  - [Example](#example)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Usage](#usage)
    - [Output](#output)
  - [Time and Space Complexity](#time-and-space-complexity)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [Other Solutions](#other-solutions)
    - [Solution - 1 (Using Binary Search)](#solution---1-using-binary-search)
    - [Solution - 2](#solution---2)
    - [Solution - 4](#solution---4)

---

## Problem Description

**Problem**: Given a sorted integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should be sorted in ascending order.

### Input/Output

- **Input**:
  - `arr`: A sorted vector of integers.
  - `k`: An integer representing the number of closest elements to return.
  - `x`: An integer to which the closeness is calculated.
- **Output**: A vector of `k` closest integers to `x`, sorted in ascending order.

### Constraints

- `1 <= k <= arr.length`
- `1 <= arr.length <= 10^4`
- `arr` is sorted in ascending order.
- `-10^4 <= arr[i], x <= 10^4`

### Closeness Criteria

- An integer `a` is closer to `x` than an integer `b` if:
  - `|a - x| < |b - x|`, or
  - `|a - x| == |b - x|` and `a < b`.

---

## Solution Overview

### Approach

1. **Using a Max-Heap**:
   - Iterate over each element of the array and calculate its absolute difference with `x`.
   - Use a max-heap (priority queue) to keep track of the `k` closest elements.
   - Store each element as a pair `(difference, element)` in the heap.
   - If the heap size exceeds `k`, remove the element with the largest difference.
   - After processing all elements, the heap will contain `k` closest elements to `x`.
   - Extract the elements from the heap, sort them in ascending order, and return them.

### Why a Max-Heap?

- Using a max-heap allows us to efficiently maintain the `k` closest elements by removing the element with the largest difference whenever the heap size exceeds `k`.

---

## Code Explanation

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * @class Solution
 * @brief A class to find the k closest elements to a given integer x.
 */
class Solution {
public:
    /**
     * @brief Finds the k closest integers to x in the array.
     * @param arr A sorted vector of integers.
     * @param k An integer representing the number of closest elements to find.
     * @param x The target integer to find closeness to.
     * @return A vector of k closest integers sorted in ascending order.
     */
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Max-heap to store pairs of (difference, element).
        priority_queue<pair<int, int>> pq;

        // Iterate over each element in the sorted array.
        for (int ele : arr) {
            // Push the absolute difference and the element as a pair.
            pq.push({abs(ele - x), ele});

            // If the size of the heap exceeds k, remove the element with the largest difference.
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Extract the elements from the heap into a vector.
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        // Sort the resulting vector to ensure the elements are in ascending order.
        sort(ans.begin(), ans.end());

        return ans;
    }
};

// Optimizations for faster I/O in competitive programming.
inline const auto optimize = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
```

### Explanation

1. **Heap Initialization**:
   - A max-heap (`priority_queue`) is used to store pairs of `(difference, element)`.
2. **Iterate and Store**:
   - For each element in the array, calculate its absolute difference with `x` and store it in the heap.
   - If the heap size exceeds `k`, remove the element with the highest difference, ensuring that only the closest elements remain.
3. **Extract and Sort**:
   - Extract the elements from the heap into a vector.
   - Sort the vector to return the elements in ascending order.
4. **Optimization**:
   - I/O optimizations are included for faster execution in competitive programming scenarios.

---

## Example

### Example 1

**Input**:

- `arr = [1, 2, 3, 4, 5]`
- `k = 4`, `x = 3`

**Output**: `[1, 2, 3, 4]`

**Explanation**:

- The 4 elements closest to `3` are `1`, `2`, `3`, and `4`.

### Example 2

**Input**:

- `arr = [1, 1, 2, 3, 4, 5]`
- `k = 4`, `x = -1`

**Output**: `[1, 1, 2, 3]`

**Explanation**:

- The 4 elements closest to `-1` are `1`, `1`, `2`, and `3`.

---

## Usage

```cpp
int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4, x = 3;
    Solution sol;

    vector<int> result = sol.findClosestElements(arr, k, x);
    cout << "K closest elements to " << x << " are: ";
    for (int ele : result) {
        cout << ele << " ";
    }
    cout << endl;

    return 0;
}
```

### Output

```bash
K closest elements to 3 are: 1 2 3 4
```

---

## Time and Space Complexity

### Time Complexity

- **Building the Max-Heap**: `O(n log k)`, where `n` is the number of elements in `arr`.
  - For each element, insertion into the heap takes `O(log k)` time, and we iterate over `n` elements.
- **Sorting the Result Vector**: `O(k log k)` for sorting the `k` closest elements.

### Space Complexity

- **Heap Storage**: `O(k)` for storing `k` elements in the heap.
- **Result Storage**: `O(k)` for storing the `k` closest elements in the output vector.
- **Overall Space Complexity**: `O(k)`.

## Other Solutions

### Solution - 1 (Using Binary Search)

```cpp
class Solution {
public:
    int binarySearch(vector<int>& arr, int x) {
        int l = 0;
        int r = arr.size() - 1;
        int res = arr.size() / 2;
        while (l <= r) {
            int m = l + ((r - l) / 2);
            // check if we are closer
            int mdiff = abs(arr[m] - x);
            int rdiff = abs(arr[res] - x);
            if (mdiff < rdiff) {
                res = m;
            } else if (mdiff == rdiff) {
                res = min(res, m);
            }

            if (x == arr[m]) {
                return m;
            } else if (x < arr[m]) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return res;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int idx = binarySearch(arr, x);
        int l = idx;
        int r = idx + 1;
        while (l >= 0 && r < arr.size() && r - l - 1 < k) {
            int ldiff = abs(arr[l] - x);
            int rdiff = abs(arr[r] - x);
            if (ldiff < rdiff || (ldiff == rdiff && l < r)) {
                l--;
            } else {
                r++;
            }
        }
        while (l >= 0 && r - l  - 1 < k) {
            l--;
        }
        while (r < arr.size() && r - l - 1 < k) {
            r++;
        }
        vector<int> output(arr.begin() + l + 1, arr.begin() + r);
        /*
        for (int i = l + 1; i < r; i++) {
            output.push_back(arr[i]);
        }
        */
        return output;
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int l=0;
        int r=arr.size()-1;
        while(r-l>=k)
        {
            if(abs(arr[l]-x)>abs(arr[r]-x))
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        vector <int> ans(arr.begin()+l,arr.begin()+r+1);
        return ans;
    }
};
```

### Solution - 4

```cpp
class Solution {
public:

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        int n = arr.size();

        //Finding the closest element in the array using Linear Search
        int idx = 0;
        for(int i = 1; i<n; i++){
            if(abs(arr[i] - x) < abs(arr[idx] - x)){
                idx = i;
            }
        }

        int i = idx-1 , j = idx+1, count = 1;
        while(count < k){
            if(i<0){
                while(count < k){
                    j++; count++;
                }
            }
            else if(j > n-1){
                while(count < k){
                    i--; count++;
                }
            }
            else if(abs(arr[i] - x) > abs(arr[j] - x)) j++;
            else i--;
            count++;
        }
        i++; j--;

        for(int l = i ; l<=j; l++){
            ans.push_back(arr[l]);
        }

        return ans;
    }
};
```
