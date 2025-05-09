# Longest Subarray with 0 Sum

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Longest Subarray with 0 Sum](#longest-subarray-with-0-sum)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Brute Force Approach](#brute-force-approach)
    - [Optimized Approach (Using HashMap)](#optimized-approach-using-hashmap)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation (Brute Force)](#c-implementation-brute-force)
    - [C++ Implementation (Optimized)](#c-implementation-optimized)
  - [Complexity Analysis](#complexity-analysis)
    - [Brute Force Approach](#brute-force-approach-1)
    - [Optimized Approach](#optimized-approach)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

This problem requires identifying the length of the longest contiguous subarray that sums to zero. Given an array with both positive and negative integers, we seek the longest subarray that satisfies this condition.

---

## Problem Description

You are given an array `arr[]` of size `n`. The array contains both positive and negative integers. Your task is to find the length of the longest subarray whose sum is zero.

### Examples

#### Example 1

```txt
Input: arr[] = [15, -2, 2, -8, 1, 7, 10, 23]
Output: 5
Explanation: The subarray [-2, 2, -8, 1, 7] sums to 0.
```

#### Example 2

```txt
Input: arr[] = [2, 10, 4]
Output: 0
Explanation: No subarray has a sum of 0.
```

#### Example 3

```txt
Input: arr[] = [1, 0, -4, 3, 1, 0]
Output: 5
Explanation: The subarray [0, -4, 3, 1, 0] sums to 0.
```

### Constraints

- `1 <= arr.length <= 10^6`
- `-10^3 <= arr[i] <= 10^3`

---

## Approach

### Brute Force Approach

We iterate over all possible subarrays and calculate their sum. If the sum is 0, we update the maximum length found.

### Optimized Approach (Using HashMap)

We use a prefix sum and a hash map to store the first occurrence of a particular sum. If the same sum occurs again, it means that the subarray in between sums to zero.

---

## Detailed Explanation of Code

### C++ Implementation (Brute Force)

```cpp
int maxLen(vector<int>& arr) {
    int n = arr.size();
    int max_len = 0;

    for (int i = 0; i < n; i++) {
        int curr_sum = 0;
        for (int j = i; j < n; j++) {
            curr_sum += arr[j];
            if (curr_sum == 0) {
                max_len = max(max_len, j - i + 1);
            }
        }
    }

    return max_len;
}
```

### C++ Implementation (Optimized)

```cpp
int maxLen(vector<int>& arr) {
    unordered_map<int, int> presum;
    int sum = 0;
    int max_len = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum += arr[i];

        if (sum == 0) {
            max_len = i + 1;
        }

        if (presum.find(sum) != presum.end()) {
            max_len = max(max_len, i - presum[sum]);
        } else {
            presum[sum] = i;
        }
    }

    return max_len;
}
```

---

## Complexity Analysis

### Brute Force Approach

- **Time Complexity:** O(n^2)
- **Space Complexity:** O(1)

### Optimized Approach

- **Time Complexity:** O(n)
- **Space Complexity:** O(n) for the hash map

---

## How to Run the Code

### For C++

1. Save the file as `longest_zero_sum_subarray.cpp`
2. Compile the code:

   ```bash
   g++ -o longest_zero_sum_subarray longest_zero_sum_subarray.cpp
   ```

3. Run the executable:

   ```bash
   ./longest_zero_sum_subarray
   ```

4. Add a `main()` function to test with custom inputs.

---

Let me know if you’d like Java or Python versions too!
