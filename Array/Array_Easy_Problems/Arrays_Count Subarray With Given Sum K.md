# Count Subarrays with Given Sum K

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Count Subarrays with Given Sum K](#count-subarrays-with-given-sum-k)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Brute Force Approach](#brute-force-approach)
      - [Explanation](#explanation)
    - [Optimized HashMap Approach](#optimized-hashmap-approach)
      - [Explanation](#explanation-1)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

This problem requires counting the number of **contiguous subarrays** within a given integer array whose sum equals a specific target value `k`. This is a common problem involving **prefix sums** and **hash maps** for optimization.

---

## Problem Description

Given an integer array `nums` and an integer `k`, return the **total number of continuous subarrays** whose sum equals to `k`.

### Examples

#### Example 1

```plaintext
Input: nums = [1,1,1], k = 2
Output: 2
Explanation: The subarrays [1,1] and [1,1] sum to 2.
```

#### Example 2

```plaintext
Input: nums = [1,2,3], k = 3
Output: 2
Explanation: The subarrays [1,2] and [3] sum to 3.
```

---

### Constraints

- `1 <= nums.length <= 2 * 10⁴`
- `-1000 <= nums[i] <= 1000`
- `-10⁷ <= k <= 10⁷`

---

## Approach

There are two main approaches:

1. **Brute Force**: Calculate the sum of all possible subarrays and count those that equal `k`.
2. **Optimized using HashMap and Prefix Sum**: Use a hash map to keep track of prefix sums and their frequencies. This avoids recalculating subarray sums and drastically improves efficiency.

---

## Detailed Explanation of Code

### Brute Force Approach

```cpp
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int sum = nums[i];
        if (sum == k) ans++;

        for (int j = i + 1; j < n; j++) {
            sum += nums[j];
            if (sum == k) ans++;
        }
    }

    return ans;
}
```

#### Explanation

- For every starting index `i`, compute all subarray sums ending at every `j > i`.
- Increment counter each time the subarray sum equals `k`.

---

### Optimized HashMap Approach

```cpp
int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, count = 0;
    unordered_map<int, int> mpp;

    for(int i = 0; i < n; i++) {
        sum += nums[i];

        if (sum == k) count++;

        int rem = sum - k;
        if (mpp.find(rem) != mpp.end())
            count += mpp[rem];

        mpp[sum]++;
    }

    return count;
}
```

#### Explanation

- `sum` maintains the current prefix sum.
- For each element, check if `sum - k` has been seen before.
- If yes, that means there's a subarray ending at current index whose sum is `k`.
- Use a hashmap to store how many times each prefix sum has occurred.

---

## Complexity Analysis

| Approach         | Time Complexity | Space Complexity |
| ---------------- | --------------- | ---------------- |
| Brute Force      | O(n²)           | O(1)             |
| HashMap Approach | O(n)            | O(n)             |

---

## How to Run the Code

### For C++

1. Include the `vector` and `unordered_map` headers.
2. Create an instance of the `Solution` class.
3. Call the `subarraySum()` method with the `nums` vector and integer `k`.

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0, count = 0;
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            if (sum == k) count++;

            int rem = sum - k;
            if (mpp.find(rem) != mpp.end())
                count += mpp[rem];

            mpp[sum]++;
        }

        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 3;
    cout << "Total Subarrays: " << sol.subarraySum(nums, k) << endl;
    return 0;
}
```

---
