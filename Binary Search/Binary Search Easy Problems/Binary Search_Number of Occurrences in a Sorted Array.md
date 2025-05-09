# Number of Occurrences in a Sorted Array

## Table of Contents

- [Number of Occurrences in a Sorted Array](#number-of-occurrences-in-a-sorted-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [1. Linear Search (Brute Force)](#1-linear-search-brute-force)
    - [2. Using STL (C++)](#2-using-stl-c)

---

## Introduction

In many applications, especially those involving sorted data, we often need to determine the frequency of a specific element. This problem targets efficient search mechanisms using binary search to find the number of occurrences of a given element in a **sorted array**.

---

## Problem Description

Given a sorted array `arr[]` and a number `target`, find the number of times `target` appears in the array.

### Examples

- **Input:** `arr[] = [1, 1, 2, 2, 2, 2, 3]`, `target = 2`  
  **Output:** `4`  
  **Explanation:** `2` occurs 4 times.

- **Input:** `arr[] = [1, 1, 2, 2, 2, 2, 3]`, `target = 4`  
  **Output:** `0`  
  **Explanation:** `4` is not in the array.

- **Input:** `arr[] = [8, 9, 10, 12, 12, 12]`, `target = 12`  
  **Output:** `3`  
  **Explanation:** `12` occurs 3 times.

### Constraints

- `1 ≤ arr.size() ≤ 10^6`
- `1 ≤ arr[i] ≤ 10^6`
- `1 ≤ target ≤ 10^6`

---

## Approach

To find the number of occurrences of a target element in a sorted array, we perform two binary searches:

1. **First Binary Search** to find the **first occurrence** of the target.
2. **Second Binary Search** to find the **last occurrence** of the target.

Once both indices are known:

- If the element is not found, return `0`.
- Else, the number of occurrences is `last - first + 1`.

This approach ensures logarithmic time complexity due to binary search.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        int first = -1, last = -1;

        // Find first occurrence using binary search
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                first = mid;
                high = mid - 1; // continue searching left
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Find last occurrence using binary search
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                last = mid;
                low = mid + 1; // continue searching right
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        if (first == -1 || last == -1) return 0;
        return (last - first) + 1;
    }
};
```

---

## Complexity Analysis

- ⏱️ **Time Complexity:** `O(log n)`  
  Two binary searches are performed, each taking `O(log n)` time.

- 🚀 **Space Complexity:** `O(1)`  
  No additional data structures are used, only constant extra space.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `count_occurrences.cpp`.
2. Compile using:

   ```bash
   g++ -o count_occurrences count_occurrences.cpp
   ```

3. Run the executable:

   ```bash
   ./count_occurrences
   ```

---

## Other Solutions

### 1. Linear Search (Brute Force)

- Traverse the array and increment a counter whenever the element matches the target.
- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

```cpp
int countFreq(vector<int>& arr, int target) {
    int count = 0;
    for (int num : arr) {
        if (num == target) count++;
    }
    return count;
}
```

---

### 2. Using STL (C++)

Use `lower_bound` and `upper_bound` from the C++ STL:

```cpp
#include <algorithm>

int countFreq(vector<int>& arr, int target) {
    auto first = lower_bound(arr.begin(), arr.end(), target);
    auto last = upper_bound(arr.begin(), arr.end(), target);
    return last - first;
}
```

- **Time Complexity:** `O(log n)`
- **Space Complexity:** `O(1)`

---

This problem is commonly seen in coding interviews to assess knowledge of binary search and optimization in sorted arrays.
