# Largest Divisible Subset

## Table of Contents

- [Largest Divisible Subset](#largest-divisible-subset)
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
    - [Summary](#summary)

---

## Introduction

The **Largest Divisible Subset** problem requires finding the largest subset in which every pair satisfies one of the following conditions:

- `answer[i] % answer[j] == 0`
- `answer[j] % answer[i] == 0`

If multiple solutions exist, any valid subset can be returned.

---

## Problem Description

Given a set of distinct positive integers `nums`, return the largest subset satisfying the above conditions.

### Examples

#### Example 1

**Input:**

```cpp
nums = [1,2,3]
```

**Output:**

```cpp
[1,2]
```

**Explanation:** `[1,3]` is also a valid answer.

#### Example 2

**Input:**

```cpp
nums = [1,2,4,8]
```

**Output:**

```cpp
[1,2,4,8]
```

### Constraints

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10^9`
- All integers in `nums` are **unique**.

---

## Approach

1. **Sort the array** to ensure order consistency when checking divisibility.
2. Use **Dynamic Programming** to track the largest divisible subset up to each index.
3. Use a **hash array** to reconstruct the subset.
4. **Iterate** through previous elements to check divisibility conditions.
5. **Track the maximum subset length** and reconstruct the subset.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1); // dp[i] stores the length of LIS ending at index i
        vector<int> hash(n);  // hash[i] stores the previous index in the LIS ending at index i

        sort(nums.begin(), nums.end());

        int maxi = 1;  // Length of the longest LIS found so far
        int lastIndex = 0; // Index of the last element in the longest LIS

        for (int i = 0; i < n; i++) {
            hash[i] = i; // Initialize hash[i] to itself
            for (int p = 0; p < i; p++) {
                if (nums[i] % nums[p] == 0 && 1 + dp[p] > dp[i]) {
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
            lis.push_back(nums[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        lis.push_back(nums[lastIndex]);

        // Reverse to get the correct order
        reverse(lis.begin(), lis.end());

        return lis;
    }
};
```

---

## Complexity Analysis

| Complexity           | Explanation                                                                        |
| -------------------- | ---------------------------------------------------------------------------------- |
| **Time Complexity**  | `O(N^2)`, as each element is compared with all previous elements in a nested loop. |
| **Space Complexity** | `O(N)`, as we use two arrays `dp` and `hash` for storing intermediate results.     |

---

## How to Run the Code

### For C++

1. Copy the above C++ implementation into a `.cpp` file.
2. Compile using:

   ```sh
   g++ -o solution solution.cpp
   ```

3. Run the executable:

   ```sh
   ./solution
   ```

This will execute the function with a sample input.

---

### Summary

- **Sort** the input array.
- **Use DP** to track the longest divisible subset.
- **Use a hash array** to reconstruct the subset.
- **Time Complexity:** `O(N^2)`.
- **Space Complexity:** `O(N)`.

This approach ensures we efficiently find the **Largest Divisible Subset** while maintaining order consistency.
