# Single Among Doubles in a Sorted Array

## Table of Contents

- [Single Among Doubles in a Sorted Array](#single-among-doubles-in-a-sorted-array)
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
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In a sorted array where every element appears exactly twice except for one unique element, the goal is to find that single element in **O(log n)** time and **O(1)** space complexity. The sorted property of the array enables us to apply binary search techniques.

---

## Problem Description

You are given a sorted array `arr[]` where all elements appear exactly twice except for one element which appears only once. Your task is to find that single element using an efficient approach with logarithmic time complexity and constant space usage.

### Examples

#### Example 1

**Input:**  
`arr[] = [1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65]`  
**Output:**  
`4`  
**Explanation:**  
4 is the only element that appears exactly once.

#### Example 2

**Input:**  
`arr[] = [5]`  
**Output:**  
`5`  
**Explanation:**  
Array contains only one element, which is the unique one.

#### Example 3

**Input:**  
`arr[] = [1, 2, 2, 3, 3]`  
**Output:**  
`1`  
**Explanation:**  
1 appears only once at the beginning of the array.

---

### Constraints

- \( 1 \leq \text{arr.size()} \leq 10^6 \)
- \( 1 \leq \text{arr}[i] \leq 10^6 \)
- The array is sorted.
- Only one element appears once, all others appear exactly twice.

---

## Approach

This problem can be optimally solved using **binary search**:

- **Observation:**
  In a properly paired array, elements occur in pairs:
  - Index `i` is even ⇒ `arr[i] == arr[i+1]`
  - Index `i` is odd ⇒ `arr[i] == arr[i-1]`
  
- **Disruption occurs** after the index where the unique element exists.
  
- We apply binary search and check:
  - If `arr[mid] != arr[mid+1]` and `arr[mid] != arr[mid-1]`, it is the unique element.
  - If the pair starts at `mid` (even index) and `arr[mid] == arr[mid+1]`, move `low = mid + 1`
  - Otherwise, move `high = mid - 1`

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int findOnce(vector<int>& arr) {
        int n = arr.size();
        
        // Edge case: only one element
        if(n == 1) return arr[0];

        // Unique element is the first one
        if(arr[0] != arr[1]) return arr[0];

        // Unique element is the last one
        if(arr[n-1] != arr[n-2]) return arr[n-1];

        int low = 1, high = n - 2;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            // Check if mid is the unique element
            if(arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
                return arr[mid];

            // Determine which half to search
            if((mid % 2 == 0 && arr[mid] == arr[mid + 1]) ||
               (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1; // Should not reach here if input is valid
    }
};
```

---

## Complexity Analysis

| Complexity | Value        |
|------------|--------------|
| Time       | O(log n)     |
| Space      | O(1)         |

- **Time Complexity:** Each iteration halves the search space, hence logarithmic.
- **Space Complexity:** No extra space is used, constant space.

---

## How to Run the Code

### For C++

1. **Include required headers:**

    ```cpp
    #include <iostream>
    #include <vector>
    using namespace std;
    ```

2. **Example usage:**

    ```cpp
    int main() {
        Solution sol;
        vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 50, 50, 65, 65};
        cout << "The single element is: " << sol.findOnce(arr) << endl;
        return 0;
    }
    ```

3. **Compile & Run:**

    ```bash
    g++ -o single_element single_element.cpp
    ./single_element
    ```

---
