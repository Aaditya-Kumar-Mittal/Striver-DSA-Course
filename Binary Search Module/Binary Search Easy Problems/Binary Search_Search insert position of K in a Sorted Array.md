# Search Insert Position of K in a Sorted Array

## Table of Contents

- [Search Insert Position of K in a Sorted Array](#search-insert-position-of-k-in-a-sorted-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Key Insights](#key-insights)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

Given a **sorted array** and a target integer `k`, the goal is to either:

1. Find the index where `k` already exists.
2. Or, find the **index where `k` should be inserted** to keep the array sorted.

This is a classic **binary search** problem with a twist—if the element is not present, we still return the position where it would logically fit.

---

## Problem Description

- Given a sorted array `Arr[]` of size `N`.
- Given an integer `k`.
- If `k` exists in `Arr`, return the **index**.
- If `k` doesn't exist, return the index where it can be **inserted** to maintain the sorted order.

---

### Examples

#### Example 1

```plaintext
Input:
N = 4
Arr = {1, 3, 5, 6}
k = 5

Output:
2

Explanation:
Since 5 is present at index 2 (Arr[2] = 5), return 2.
```

---

#### Example 2

```plaintext
Input:
N = 4
Arr = {1, 3, 5, 6}
k = 2

Output:
1

Explanation:
2 is not present in the array.
However, if inserted at index 1, the array remains sorted.
So, return 1.
```

---

### Constraints

- `1 ≤ N ≤ 10^4`
- `-10^3 ≤ Arr[i] ≤ 10^3`
- `-10^3 ≤ k ≤ 10^3`

---

## Approach

This problem can be efficiently solved using **Binary Search** in `O(log N)` time.

### Steps

1. Initialize `low = 0`, `high = N-1`.
2. Maintain a variable `ans` initialized to `N` (worst case, insert at the end).
3. Perform binary search:
   - If `Arr[mid]` is **greater than or equal to** `k`, update `ans = mid` and move to the **left half**.
   - Else, move to the **right half**.
4. After the loop, return `ans`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
//User function Template for C++
class Solution {
public:
    int searchInsertK(vector<int> Arr, int N, int k) {
        int low = 0, high = N - 1;
        int ans = N; // Default: insert at the end

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (Arr[mid] >= k) {
                ans = mid; // Possible position
                high = mid - 1; // Move left to find earlier position
            } else {
                low = mid + 1; // Move right
            }
        }

        return ans;
    }
};
```

### Key Insights

- **When `Arr[mid] >= k`:**  
  We record `mid` as a potential answer, but we still look to the left to see if we can insert it earlier.
- **When `Arr[mid] < k`:**  
  We discard the left half, and search the right side since `k` is larger.

---

## Complexity Analysis

| Complexity            | Time       | Space  |
| --------------------- | ---------- | ------ |
| **Best/Average Case** | `O(log N)` | `O(1)` |
| **Worst Case**        | `O(log N)` | `O(1)` |

- **Time Complexity:**  
  Since binary search halves the search space with each iteration, the complexity is `O(log N)`.

- **Space Complexity:**  
  No extra space is used, so `O(1)`.

---

## How to Run the Code

### For C++

1. Copy the solution into a file `solution.cpp`.
2. Compile the code:

   ```bash
   g++ solution.cpp -o solution
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

---

**Quick Tip:**

- This is a frequently asked question in interviews (especially for FAANG companies), so mastering this gives you an edge!

---
