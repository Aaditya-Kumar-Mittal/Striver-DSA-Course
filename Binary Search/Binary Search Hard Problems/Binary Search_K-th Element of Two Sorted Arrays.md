# K-th Element of Two Sorted Arrays

## Table of Contents

- [K-th Element of Two Sorted Arrays](#k-th-element-of-two-sorted-arrays)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Submissions](#my-submissions)

---

## Introduction

Given two sorted arrays, the task is to find the element at the **k-th position** (1-based indexing) in the final merged and sorted version of these two arrays without explicitly merging them.

---

## Problem Description

You're provided with:

- Two sorted arrays `arr1` of size `n`, and `arr2` of size `m`
- An integer `k`, where `1 <= k <= n + m`

Return the `k`-th element (1-based index) of the merged sorted array created by combining `arr1` and `arr2`.

### Examples

#### Example 1

**Input:**

```cpp
arr1 = [2, 3, 45], arr2 = [4, 6, 7, 8], k = 4
```

**Output:**

```cpp
6
```

**Explanation:**
Merged array = `[2, 3, 4, 6, 7, 8, 45]`.
4-th element = `6`.

---

#### Example 2

**Input:**

```cpp
arr1 = [2, 3, 6, 7, 9], arr2 = [1, 4, 8, 10], k = 4
```

**Output:**

```cpp
4
```

**Explanation:**
Merged array = `[1, 2, 3, 4, 6, 7, 8, 9, 10]`.
4-th element = `4`.

---

### Constraints

- `1 <= n, m <= 5000`
- `0 <= arr1[i], arr2[i] <= 10^9`
- `1 <= k <= n + m`
- Arrays are sorted in non-decreasing order
- Time Limit: `1 second`

---

## Approach

To find the k-th element efficiently without merging, we use **Binary Search on Partitions**.

The idea is:

- Partition the first `k` elements into two parts:

  - `mid1` elements from `arr1`
  - `k - mid1` elements from `arr2`

- Find `mid1` such that all elements in left partition are ≤ elements in right partition.
- Return the **maximum** element in the left partition as the k-th element.

We apply binary search on the number of elements to take from `arr1`:

- `low = max(0, k - m)`
- `high = min(k, n)`

For each midpoint `mid1`, we calculate:

- `mid2 = k - mid1`
- Check boundary elements:

  - `l1 = arr1[mid1 - 1]`, `r1 = arr1[mid1]`
  - `l2 = arr2[mid2 - 1]`, `r2 = arr2[mid2]`

- Ensure `l1 <= r2` and `l2 <= r1`
- If satisfied, `max(l1, l2)` is the k-th element.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    if(n > m) return kthElement(arr2, arr1, m, n, k);  // always binary search on smaller array

    int low = max(0, k - m); // can't take more than k from arr1 or less than 0
    int high = min(k, n);

    while(low <= high){
        int mid1 = (low + high) / 2; // elements from arr1
        int mid2 = k - mid1;         // elements from arr2

        int l1 = (mid1 == 0) ? INT_MIN : arr1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : arr2[mid2 - 1];
        int r1 = (mid1 == n) ? INT_MAX : arr1[mid1];
        int r2 = (mid2 == m) ? INT_MAX : arr2[mid2];

        if(l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if(l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    return -1; // should never be hit if k is valid
}
```

---

## Complexity Analysis

| Complexity | Value             |
| ---------- | ----------------- |
| Time       | O(log(min(n, m))) |
| Space      | O(1)              |

- We always perform binary search on the **smaller array**.
- The comparisons and boundary calculations are constant-time operations.

---

## How to Run the Code

### For C++

1. **Save the code in a file** (e.g., `kthElement.cpp`)
2. **Compile** the code using:

   ```bash
   g++ kthElement.cpp -o kthElement
   ```

3. **Run** the program:

   ```bash
   ./kthElement
   ```

---

## Other Solutions

### My Submissions

```cpp
#include <bits/stdc++.h>

using namespace std;

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here

    if(n > m) return kthElement(arr2, arr1, m, n, k);

    int low = max(0, k - m);

    int high = min(k, n);

    int left = k;

    while(low <= high)
    {
        int mid1 = (low + high) >> 1;

        int mid2 = left - mid1;

        int r1 = (mid1 < n) ? arr1[mid1] : INT_MAX;
        int r2 = (mid2 < m) ? arr2[mid2] : INT_MAX;

        int l1 = (mid1 - 1 >= 0) ? arr1[mid1 - 1] : INT_MIN;
        int l2 = (mid2 - 1 >= 0) ? arr2[mid2 - 1] : INT_MIN;

        if(l1 > r2) high = mid1 - 1;
        else if(l2 > r1) low = mid1 + 1;
        else return max(l1, l2);
    }

    return high;
}
```

```cpp

class Solution {
  public:

    int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k) {

        if(n > m) return kthElement(arr2, arr1, m, n, k);

        int low = max(0, k - m);

        int high = min(k, n);

        int left = k;

        while(low <= high)
        {
            int mid1 = (low + high) >> 1;

            int mid2 = left - mid1;

            int r1 = (mid1 < n) ? arr1[mid1] : INT_MAX;
            int r2 = (mid2 < m) ? arr2[mid2] : INT_MAX;

            int l1 = (mid1 - 1 >= 0) ? arr1[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? arr2[mid2 - 1] : INT_MIN;

            if(l1 > r2) high = mid1 - 1;
            else if(l2 > r1) low = mid1 + 1;
            else return max(l1, l2);
        }

        return high;
    }

    int kthElement(vector<int>& a, vector<int>& b, int k) {

        return kthElement(a,b,a.size(), b.size(), k);
    }
};
```
