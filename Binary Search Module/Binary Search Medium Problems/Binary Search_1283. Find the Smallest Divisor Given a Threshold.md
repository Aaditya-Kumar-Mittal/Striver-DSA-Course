# Find the Smallest Divisor Given a Threshold

## Table of Contents

- [Find the Smallest Divisor Given a Threshold](#find-the-smallest-divisor-given-a-threshold)
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
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Visual Diagram: Binary Search for Smallest Divisor](#visual-diagram-binary-search-for-smallest-divisor)
    - [Initial Setup](#initial-setup)
    - [Binary Search Steps](#binary-search-steps)
      - [Step 1](#step-1)
      - [Step 2](#step-2)
      - [Step 3](#step-3)
      - [Step 4](#step-4)
      - [Exit Condition](#exit-condition)
    - [Full Binary Search Flow Diagram](#full-binary-search-flow-diagram)
    - [Quick Summary Table](#quick-summary-table)

---

## Introduction

This problem involves finding the smallest possible divisor of an array such that the sum of the ceiling division results of the array elements by this divisor does not exceed a given threshold.  
We use binary search to efficiently find this smallest divisor.

---

## Problem Description

You are given an array of positive integers `nums` and an integer `threshold`. You must find the smallest positive integer divisor such that:

- For each element in `nums`, divide the element by the divisor and round **up** to the nearest integer.
- The sum of all rounded-up results must be **less than or equal** to `threshold`.

If multiple divisors satisfy the condition, return the **smallest** one.

---

### Examples

#### Example 1

**Input:**

```plaintext
nums = [1,2,5,9], threshold = 6
```

**Output:**

```plaintext
5
```

**Explanation:**

- Dividing by 5, we get [1, 1, 1, 2].
- Their sum is 5, which is <= 6.

---

#### Example 2

**Input:**

```plaintext
nums = [44,22,33,11,1], threshold = 5
```

**Output:**

```plaintext
44
```

**Explanation:**

- Dividing each element by 44, we get [1, 1, 1, 1, 1].
- Their sum is exactly 5.

---

### Constraints

- `1 <= nums.length <= 5 * 10^4`
- `1 <= nums[i] <= 10^6`
- `nums.length <= threshold <= 10^6`
- Test cases are **guaranteed to have a valid answer**.

---

## Approach

The naive (brute-force) approach is to try every divisor from `1` to `max(nums)`.  
However, it is inefficient for large arrays.

Thus, we use **binary search**:

1. **Low** = 1, **High** = max(nums).
2. While low <= high:
   - Find mid.
   - If sum of ceiling divisions at mid <= threshold, store mid as potential answer and search left (high = mid - 1).
   - Else, search right (low = mid + 1).
3. The smallest valid divisor will be the answer.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Helper function to calculate the sum of divisions
    int checkSum(vector<int> arr, int divisor) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += ceil((double)arr[i] / (double)divisor);
        }
        return sum;
    }

    // Brute-force approach
    int smallestDivisorBrute(vector<int>& arr, int limit) {
        int n = arr.size();
        if (n > limit) return -1;

        int maxPossible = *max_element(arr.begin(), arr.end());

        for (int divisor = 1; divisor <= maxPossible; divisor++) {
            int getSum = checkSum(arr, divisor);
            if (getSum <= limit)
                return divisor;
        }
        return -1;
    }

    // Optimized binary search approach
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        if (n > threshold) return -1;

        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int getSum = checkSum(nums, mid);

            if (getSum <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans != INT_MAX) ? ans : -1;
    }
};
```

---

### Java Implementation

```java
class Solution {
    // Helper function to calculate the sum of divisions
    public int checkSum(int[] arr, int divisor) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + divisor - 1) / divisor; // Equivalent to ceil(num / divisor)
        }
        return sum;
    }

    // Brute-force approach
    public int smallestDivisorBrute(int[] arr, int limit) {
        int n = arr.length;
        if (n > limit) return -1;

        int maxPossible = Arrays.stream(arr).max().getAsInt();

        for (int divisor = 1; divisor <= maxPossible; divisor++) {
            int getSum = checkSum(arr, divisor);
            if (getSum <= limit)
                return divisor;
        }
        return -1;
    }

    // Optimized binary search approach
    public int smallestDivisor(int[] nums, int threshold) {
        int n = nums.length;
        if (n > threshold) return -1;

        int low = 1, high = Arrays.stream(nums).max().getAsInt();
        int ans = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int getSum = checkSum(nums, mid);

            if (getSum <= threshold) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans != Integer.MAX_VALUE ? ans : -1;
    }
}
```

---

## Complexity Analysis

| Approach      | Time Complexity        | Space Complexity |
| ------------- | ---------------------- | ---------------- |
| Brute-force   | O(N \* max(nums))      | O(1)             |
| Binary Search | O(N \* log(max(nums))) | O(1)             |

- `N` is the number of elements in the array `nums`.
- `max(nums)` is the largest value in the array.

---

## How to Run the Code

### For C++

1. Save the code in a file named `solution.cpp`.
2. Compile using:

   ```bash
   g++ solution.cpp -o solution
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

### For Java

1. Save the code in a file named `Solution.java`.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```

---

## Visual Diagram: Binary Search for Smallest Divisor

Suppose we have:

**Input:**

```plaintext
nums = [1, 2, 5, 9]
threshold = 6
```

---

### Initial Setup

| Variable | Value                      |
| -------- | -------------------------- |
| low      | 1                          |
| high     | 9 (max element of nums)    |
| ans      | ∞ (placeholder for result) |

---

### Binary Search Steps

#### Step 1

- **mid = (1 + 9) / 2 = 5**
- Calculate sum with divisor = 5:

  ```plaintext
  1/5 = 1, 2/5 = 1, 5/5 = 1, 9/5 = 2 → Sum = 5
  ```

- 5 ≤ 6 ✅ → valid
- Update `ans = 5`
- Search left side → `high = mid - 1 = 4`

---

#### Step 2

- **mid = (1 + 4) / 2 = 2**
- Calculate sum with divisor = 2:

  ```plaintext
  1/2 = 1, 2/2 = 1, 5/2 = 3, 9/2 = 5 → Sum = 10
  ```

- 10 > 6 ❌ → invalid
- Search right side → `low = mid + 1 = 3`

---

#### Step 3

- **mid = (3 + 4) / 2 = 3**
- Calculate sum with divisor = 3:

  ```plaintext
  1/3 = 1, 2/3 = 1, 5/3 = 2, 9/3 = 3 → Sum = 7
  ```

- 7 > 6 ❌ → invalid
- Search right side → `low = mid + 1 = 4`

---

#### Step 4

- **mid = (4 + 4) / 2 = 4**
- Calculate sum with divisor = 4:

  ```plaintext
  1/4 = 1, 2/4 = 1, 5/4 = 2, 9/4 = 3 → Sum = 7
  ```

- 7 > 6 ❌ → invalid
- Search right side → `low = mid + 1 = 5`

---

#### Exit Condition

- Now `low > high` → binary search ends.
- Final `ans = 5`

✅ Thus, the smallest divisor is **5**.

---

### Full Binary Search Flow Diagram

```plaintext
Low=1, High=9
   |
mid = 5 → sum = 5 → Valid → ans=5, High=4
   |
Low=1, High=4
   |
mid = 2 → sum = 10 → Not valid → Low=3
   |
Low=3, High=4
   |
mid = 3 → sum = 7 → Not valid → Low=4
   |
Low=4, High=4
   |
mid = 4 → sum = 7 → Not valid → Low=5
   |
low > high → End → Answer = 5
```

---

### Quick Summary Table

| Step | low | high | mid | sum of ceilings | Result    | Action            |
| ---: | --: | ---: | --: | --------------: | --------- | ----------------- |
|    1 |   1 |    9 |   5 |               5 | Valid     | ans = 5, high = 4 |
|    2 |   1 |    4 |   2 |              10 | Not Valid | low = 3           |
|    3 |   3 |    4 |   3 |               7 | Not Valid | low = 4           |
|    4 |   4 |    4 |   4 |               7 | Not Valid | low = 5           |
