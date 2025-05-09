# Find Minimum in Rotated Sorted Array II

## Table of Contents

- [Find Minimum in Rotated Sorted Array II](#find-minimum-in-rotated-sorted-array-ii)
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

---

## Introduction

In this problem, we are given a **sorted and rotated** array that **may contain duplicates**, and our goal is to **find the minimum element** in the array. Unlike standard rotated arrays, the presence of duplicates introduces ambiguity in certain scenarios and makes the problem more challenging.

---

## Problem Description

Given an integer array `nums` sorted in ascending order and rotated between 1 and n times, where duplicates may be present, return the minimum element in the array. You must try to reduce the number of operations as much as possible.

### Examples

#### Example 1

**Input:**  
`nums = [1, 3, 5]`  
**Output:**  
`1`

#### Example 2

**Input:**  
`nums = [2, 2, 2, 0, 1]`  
**Output:**  
`0`

---

### Constraints

- \( n = \text{nums.length} \)
- \( 1 \leq n \leq 5000 \)
- \( -5000 \leq \text{nums}[i] \leq 5000 \)
- The array is **sorted** and **rotated** between 1 and n times.
- **Duplicates are allowed**.

---

## Approach

We use a **modified binary search** strategy:

1. **Binary Search** helps in achieving O(log n) complexity in the best case, but due to **duplicates**, we may degrade to O(n) in the worst case.
2. Maintain variables `low`, `high`, and `ans` (to store the minimum encountered).
3. At each iteration:
   - If the subarray `nums[low]` to `nums[high]` is sorted, update `ans = min(ans, nums[low])` and break.
   - If duplicates make comparison ambiguous (`nums[low] == nums[mid] == nums[high]`), increment `low` and decrement `high`.
   - If the left half is sorted, move to the right half.
   - Otherwise, move to the left half.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int ans = INT_MAX;

        while (low <= high) {
            // Subarray is already sorted
            if (nums[low] < nums[high]) {
                ans = min(ans, nums[low]);
                break;
            }

            int mid = low + (high - low) / 2;

            // Ambiguity due to duplicates
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                ans = min(ans, nums[low]);
                low++;
                high--;
            }
            // Left half is sorted
            else if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            // Right half is unsorted, minimum lies there
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }

        return ans;
    }
};
```

```java
class Solution {
    public int findMin(int[] nums) {
        int n=nums.length, low=0, high=n-1, ans=Integer.MAX_VALUE;

        while(low <= high)
        {
            int mid=(low+high)/2;

            if (nums[low] < nums[high]) { // fully sorted
                ans = Math.min(ans, nums[low]);
                break;
            }

            if(nums[low] <= nums[high])//IF BOTH PART WILL BE SOORTED or  if (nums[low] == nums[mid] && nums[mid] == nums[high]) are equal
            {
                ans=Math.min(ans, nums[low]);
                low++;
                high--;
            }
            else if(nums[low] <= nums[mid])//LEFT SORETD
            {
                ans=Math.min(ans, nums[low]);
                low=mid+1;

            }
            else//RIGHT SORETD
            {
                ans=Math.min(ans, nums[mid]);
                high=mid-1;
            }
        }

        return ans;
    }
}
```

---

## Complexity Analysis

| Complexity | Value            |
|------------|------------------|
| Time       | O(log n) average, O(n) worst due to duplicates |
| Space      | O(1)             |

- **Time Complexity:** Best case is logarithmic using binary search. Worst case becomes linear when many duplicates prevent binary elimination of search space.
- **Space Complexity:** Constant as no extra space is used.

---

## How to Run the Code

### For C++

1. **Include necessary headers:**

    ```cpp
    #include <iostream>
    #include <vector>
    #include <climits>
    using namespace std;
    ```

2. **Example main function:**

    ```cpp
    int main() {
        Solution sol;
        vector<int> nums = {2, 2, 2, 0, 1};
        cout << "Minimum element is: " << sol.findMin(nums) << endl;
        return 0;
    }
    ```

3. **Compile and run:**

    ```bash
    g++ -o find_min_rotated find_min_rotated.cpp
    ./find_min_rotated
    ```

---
