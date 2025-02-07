# Printing the Longest Increasing Subsequence

## Table of Contents

- [Printing the Longest Increasing Subsequence](#printing-the-longest-increasing-subsequence)
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

## Introduction

The problem requires finding the **Longest Increasing Subsequence (LIS)** from a given array of integers. Additionally, if multiple LIS are possible, the one that is **index-wise lexicographically smallest** should be returned.

## Problem Description

Given an integer `n` (size of the array) and an array `arr`, return the **Longest Increasing Subsequence (LIS)** which is **index-wise lexicographically smallest**.

### Examples

#### Example 1

**Input:**

```cpp
n = 16
arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
```

**Output:**

```cpp
0 4 6 9 13 15
```

**Explanation:**  
The longest increasing subsequence is `[0, 4, 6, 9, 13, 15]` with a length of 6.

#### Example 2

**Input:**

```cpp
n = 1
arr = [1]
```

**Output:**

```cpp
1
```

### Constraints

- `1 <= n <= 1000`
- `0 <= arr[i] <= 10^9`

## Approach

1. **Dynamic Programming Approach**
   - Maintain a `dp` array where `dp[i]` stores the length of the LIS ending at index `i`.
   - Maintain a `hash` array to reconstruct the LIS.
   - Iterate through the array, updating `dp[i]` based on previous elements.
   - Use `hash` to track the indices of elements forming the LIS.
   - Backtrack using `hash` to construct the LIS sequence.
   - Reverse the sequence to get the correct order.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        vector<int> dp(n, 1); // dp[i] stores the length of LIS ending at index i
        vector<int> hash(n);  // hash[i] stores the previous index in the LIS ending at index i

        int maxi = 1;         // Length of the longest LIS found so far
        int lastIndex = 0;    // Index of the last element in the longest LIS

        // Fill dp and hash arrays
        for (int i = 0; i < n; i++) {
            hash[i] = i; // Initialize hash[i] to itself
            for (int p = 0; p < i; p++) {
                if (arr[p] < arr[i] && 1 + dp[p] > dp[i]) {
                    dp[i] = 1 + dp[p];
                    hash[i] = p;
                }
            }
            // Update maxi and lastIndex if a longer LIS is found
            if (dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the LIS using the hash array
        vector<int> lis;
        while (hash[lastIndex] != lastIndex) {
            lis.push_back(arr[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        lis.push_back(arr[lastIndex]); // Add the first element of the LIS

        // Reverse to get the correct order
        reverse(lis.begin(), lis.end());

        return lis;
    }
};

// Driver Code
int main() {
    Solution sol;
    vector<int> arr = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n = arr.size();
    vector<int> result = sol.longestIncreasingSubsequence(n, arr);

    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(n^2)` - Due to the nested loops iterating over all elements.
- **Space Complexity:** `O(n)` - Used for `dp` and `hash` arrays.

## How to Run the Code

### For C++

1. Save the above code in a file, e.g., `LIS.cpp`.
2. Compile using:

   ```bash
   g++ -std=c++17 LIS.cpp -o LIS
   ```

3. Run the executable:

   ```bash
   ./LIS
   ```

This will output the **longest increasing subsequence** in the correct order.
