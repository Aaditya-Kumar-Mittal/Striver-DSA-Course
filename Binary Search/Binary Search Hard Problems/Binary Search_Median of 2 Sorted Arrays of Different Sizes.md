# Median of 2 Sorted Arrays of Different Sizes

## Table of Contents

- [Median of 2 Sorted Arrays of Different Sizes](#median-of-2-sorted-arrays-of-different-sizes)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Brute Force Approach](#brute-force-approach)
    - [Optimized Binary Search Approach](#optimized-binary-search-approach)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem asks to find the **median** of two sorted arrays of possibly **different sizes**. Instead of merging the arrays directly, we aim to solve this efficiently in logarithmic time using a binary search-based partitioning strategy.

## Problem Description

You are given two **sorted arrays** `a[]` and `b[]`. Find and return the **median** of the combined array as if the two arrays were merged into one.

### Examples

#### Example 1

- **Input:**  
  `a = [-5, 3, 6, 12, 15]`  
  `b = [-12, -10, -6, -3, 4, 10]`
- **Output:** `3`
- **Explanation:** Merged array = `[-12, -10, -6, -5, -3, 3, 4, 6, 10, 12, 15]`, Median = 3

#### Example 2

- **Input:**  
  `a = [2, 3, 5, 8]`, `b = [10, 12, 14, 16, 18, 20]`
- **Output:** `11`
- **Explanation:** Merged array = `[2, 3, 5, 8, 10, 12, 14, 16, 18, 20]`, Median = (10 + 12) / 2 = 11

#### Example 3

- **Input:**  
  `a = []`, `b = [2, 4, 5, 6]`
- **Output:** `4.5`
- **Explanation:** Merged array = `[2, 4, 5, 6]`, Median = (4 + 5)/2 = 4.5

### Constraints

- 0 ≤ a.size(), b.size() ≤ 10⁶
- 1 ≤ a[i], b[i] ≤ 10⁹
- a.size() + b.size() > 0

## Approach

There are two main approaches to solve this problem:

1. **Brute Force Approach**:

   - Merge both arrays.
   - Find the median from the combined sorted array.
   - Time Complexity: O(n + m)

2. **Optimized Binary Search Approach**:
   - Perform a binary search on the **smaller** array.
   - Partition both arrays such that the combined left and right halves are balanced.
   - Use max of lefts and min of rights to compute the median.
   - Time Complexity: **O(log(min(n, m)))**

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Brute force approach
    double medianOf2Brute(vector<int>& a, vector<int>& b) {
        int n1 = a.size(), n2 = b.size();
        int n = n1 + n2;
        int index1 = (n - 1) / 2, index2 = n / 2;
        int count = 0, i = 0, j = 0;
        int e1 = -1, e2 = -1;

        while (i < n1 && j < n2) {
            int val = (a[i] < b[j]) ? a[i++] : b[j++];
            if (count == index1) e1 = val;
            if (count == index2) e2 = val;
            count++;
        }

        while (i < n1) {
            if (count == index1) e1 = a[i];
            if (count == index2) e2 = a[i];
            count++; i++;
        }

        while (j < n2) {
            if (count == index1) e1 = b[j];
            if (count == index2) e2 = b[j];
            count++; j++;
        }

        return (n % 2 == 0) ? (e1 + e2) / 2.0 : e2;
    }

    // Binary search optimized approach
    double median(vector<int>& a, vector<int>& b, int m, int n) {
        if (m > n) return median(b, a, n, m); // ensure a is smaller
        int low = 0, high = m;
        int total = m + n;
        int leftSize = (total + 1) / 2;

        while (low <= high) {
            int cut1 = (low + high) >> 1;
            int cut2 = leftSize - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : a[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : b[cut2 - 1];
            int r1 = (cut1 == m) ? INT_MAX : a[cut1];
            int r2 = (cut2 == n) ? INT_MAX : b[cut2];

            if (l1 > r2) high = cut1 - 1;
            else if (l2 > r1) low = cut1 + 1;
            else {
                if (total % 2 == 1)
                    return max(l1, l2);
                else
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
        }

        return 0.0; // not reached
    }

    double medianOf2(vector<int>& a, vector<int>& b) {
        return median(a, b, a.size(), b.size());
    }
};
```

```cpp

class Solution {
  public:
    double medianOf2Brute(vector<int>& a, vector<int>& b) {
        // Your code goes here

        int n1 = a.size();
        int n2 = b.size();

        int i = 0, j = 0, n = n1 + n2;

        int index2 = n/2;
        int index1 = index2 - 1;

        int count  = 0;

        int element1 = -1, element2 = -1;

        while(i < n1 && j < n2)
        {
            if(a[i] < b[j])
            {
                if(count == index1) element1 = a[i];
                if(count == index2) element2 = a[i];
                count++; i++;
            }
            else{

                if(count == index1) element1 = b[j];
                if(count == index2) element2 = b[j];
                count++; j++;
            }
        }

        while(i < n1)
        {
            if(count == index1) element1 = a[i];
            if(count == index2) element2 = a[i];
            count++; i++;
        }

        while(j < n2)
        {
            if(count == index1) element1 = b[j];
            if(count == index2) element2 = b[j];
            count++; j++;
        }

        if(n % 2 == 1) return element2;

        return (double)(element1 + element2) / 2.0;
    }

    double median(vector<int>& a, vector<int>& b, int m, int n)
    {
        if(m > n) return median(b, a, n, m);

        int low = 0, high = m;

        int size = m + n;

        int left = (size + 1) / 2;

        while(low <= high)
        {
            int mid1 = (low + high) >> 1;

            int mid2 = left - mid1;

            int r1 = (mid1 < m) ? a[mid1] : INT_MAX;
            int r2 = (mid2 < n) ? b[mid2] : INT_MAX;

            int l1 = (mid1 - 1 >= 0) ? a[mid1 - 1] : INT_MIN;
            int l2 = (mid2 - 1 >= 0) ? b[mid2 - 1] : INT_MIN;

            if(l1 > r2)
            {
                high = mid1 - 1;
            }
            else if(l2 > r1)
            {
                low = mid1 + 1;
            }
            else{

                if(size % 2 == 1)
                {
                    return max(l1, l2);
                }
                else{
                    return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
                }
            }
        }

        return high; // never reached
    }

    double medianOf2(vector<int>& a, vector<int>& b){

        int m = a.size();
        int n = b.size();

        return median(a, b, m, n);
    }
};
```

## Complexity Analysis

### Brute Force Approach

- **Time Complexity:** O(n + m)
- **Space Complexity:** O(1) (if using two pointers, no extra space for merge)

### Optimized Binary Search Approach

- **Time Complexity:** O(log(min(n, m)))
- **Space Complexity:** O(1)

## How to Run the Code

### For C++

1. Copy the code into a file `median.cpp`
2. Use any C++ compiler, e.g., g++

   ```bash
   g++ median.cpp -o median
   ./median
   ```

3. Test with various inputs using function calls from `main()` or a test suite.

---
