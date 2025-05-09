# Binary Search

## Table of Contents

- [Binary Search](#binary-search)
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
    - [Recursive Implementation](#recursive-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

Binary Search is a classic algorithm used to efficiently locate a target element in a **sorted array**. Unlike linear search, which has a time complexity of O(n), binary search works in O(log n) time by halving the search space at each step.

In this problem, you are given a **sorted array** and an integer `k`, and you are to find the **smallest index** (0-based) where `k` is located using binary search. If `k` is not present, return `-1`.

---

## Problem Description

You are given a sorted array `arr[]` and a target value `k`. Implement a binary search algorithm that returns:

- The **first occurrence** (smallest index) of `k` if it exists in the array.
- `-1` if `k` does not exist in the array.

### Examples

#### Example 1

**Input:**

```cpp
arr[] = [1, 2, 3, 4, 5], k = 4
```

**Output:**

```plaintext
3
```

**Explanation:**
4 is found at index 3.

---

#### Example 2

**Input:**

```cpp
arr[] = [11, 22, 33, 44, 55], k = 445
```

**Output:**

```plaintext
-1
```

**Explanation:**
445 is not present in the array.

---

#### Example 3

**Input:**

```cpp
arr[] = [1, 1, 1, 1, 2], k = 1
```

**Output:**

```plaintext
0
```

**Explanation:**
Though 1 appears multiple times, its first occurrence is at index 0.

---

### Constraints

- 1 ≤ arr.size() ≤ 10⁵
- 1 ≤ arr[i] ≤ 10⁶
- 1 ≤ k ≤ 10⁶
- Expected Time Complexity: O(log n)
- Expected Auxiliary Space: O(1)

---

## Approach

1. Initialize two pointers: `low = 0` and `high = n - 1`.
2. Perform a standard binary search:
   - Compute `mid = low + (high - low) / 2`.
   - If `arr[mid] == k`, store the index as a potential answer and continue the search in the **left half** (`high = mid - 1`) to find the **smallest index**.
   - If `arr[mid] < k`, discard the left half (`low = mid + 1`).
   - If `arr[mid] > k`, discard the right half (`high = mid - 1`).
3. If no match is found, return `-1`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int binarysearch(vector<int> &arr, int k) {
        int low = 0, high = arr.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (arr[mid] == k) {
                ans = mid;         // potential answer
                high = mid - 1;    // keep searching to the left
            } else if (arr[mid] < k) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return ans;  // -1 if not found
    }
};
```

### Recursive Implementation

```cpp


int binaryRecursion(vector<int> &arr, int target, int low, int high)
{
  if(low > high) return -1;

  int mid = low + (high - low) / 2;

  if(arr[mid] == target) return mid;

  else if(arr[mid] < target) return binaryRecursion(arr, target, mid + 1, high);

  else return binaryRecursion(arr, target, low, mid - 1);
}

int search(vector<int> &nums, int target) {
    // Write your code here.

  return binaryRecursion(nums, target, 0, nums.size() - 1);
}
```

---

## Complexity Analysis

| Complexity | Value    |
| ---------- | -------- |
| Time       | O(log n) |
| Space      | O(1)     |

- **Time Complexity:** In each iteration, the search space is reduced by half → `O(log n)`
- **Space Complexity:** Only a few variables are used → `O(1)`

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile the code using:

   ```bash
   g++ filename.cpp -o output
   ```

3. Run the program:

   ```bash
   ./output
   ```

4. Provide input in the format:

   ```plaintext
   1
   4
   1 2 3 4 5
   ```

---
