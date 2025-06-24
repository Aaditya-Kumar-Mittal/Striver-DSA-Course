# Range Sum Query - Immutable

## Table of Contents

- [Range Sum Query - Immutable](#range-sum-query---immutable)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Functional Requirements](#functional-requirements)
    - [Examples](#examples)
      - [Input](#input)
      - [Output](#output)
      - [Explanation](#explanation)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Code Explanation](#code-explanation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
      - [Sample `main.cpp`](#sample-maincpp)

---

## Introduction

This problem is a classic example of optimizing repeated range sum queries on an immutable array. Instead of computing the sum for each query in O(n) time, we use prefix sums to answer each in O(1).

---

## Problem Description

Given an immutable integer array `nums`, efficiently answer multiple queries where each query asks for the sum of a subarray from index `left` to `right` (inclusive).

### Functional Requirements

- `NumArray(int[] nums)` – Initializes the data structure with the array `nums`.
- `int sumRange(int left, int right)` – Returns the sum of elements from `nums[left]` to `nums[right]`.

---

### Examples

#### Input

```text
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
```

#### Output

```text
[null, 1, -1, -3]
```

#### Explanation

```text
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);

numArray.sumRange(0, 2); // returns 1: -2 + 0 + 3 = 1
numArray.sumRange(2, 5); // returns -1: 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // returns -3: sum of all elements
```

---

### Constraints

- 1 ≤ nums.length ≤ 10⁴
- -10⁵ ≤ nums\[i] ≤ 10⁵
- 0 ≤ left ≤ right < nums.length
- At most 10⁴ calls will be made to `sumRange`.

---

## Approach

To avoid recalculating sums every time `sumRange` is called, we preprocess the input array using **prefix sums**. The prefix sum at index `i` stores the sum of all elements from the start up to index `i`.

Then, to compute the sum from `left` to `right`, we simply subtract:

```cpp
sumRange(left, right) = prefixSum[right] - prefixSum[left - 1]
```

When `left == 0`, we just return `prefixSum[right]`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class NumArray {
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);
        prefixSum[0] = nums[0];

        for (int i = 1; i < n; ++i) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};
```

#### Code Explanation

- **Initialization**: We construct the `prefixSum` array such that `prefixSum[i] = nums[0] + nums[1] + ... + nums[i]`.
- **sumRange**:

  - If `left == 0`, return `prefixSum[right]` directly.
  - Otherwise, subtract `prefixSum[left - 1]` from `prefixSum[right]` to get the sum in the desired range.

---

## Complexity Analysis

| Operation   | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Constructor | O(n)            | O(n)             |
| sumRange    | O(1)            | O(1)             |

- **Time**: We spend O(n) upfront to build the prefix sum. Each query then takes constant time.
- **Space**: O(n) extra space is used to store the prefix sum array.

---

## How to Run the Code

### For C++

1. **Create a C++ file**, e.g., `main.cpp`.
2. **Include the class** and instantiate with input array.
3. **Call the `sumRange` method** with desired `left` and `right` values.
4. **Compile & Run**:

```bash
g++ main.cpp -o main
./main
```

#### Sample `main.cpp`

```cpp
#include <iostream>
#include <vector>
using namespace std;

class NumArray {
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);
        prefixSum[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left - 1];
    }
};

int main() {
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);

    cout << numArray.sumRange(0, 2) << endl; // Output: 1
    cout << numArray.sumRange(2, 5) << endl; // Output: -1
    cout << numArray.sumRange(0, 5) << endl; // Output: -3

    return 0;
}
```

---
