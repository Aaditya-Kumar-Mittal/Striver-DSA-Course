# 1248. Count Number of Nice Subarrays

<!-- markdownlint-disable MD024 -->

## Problem Statement

Given an array of integers `nums` and an integer `k`, a continuous subarray is called **nice** if there are exactly `k` odd numbers in it.

**Objective:** Return the number of **nice** subarrays.

### Examples

1. **Example 1:**

   - **Input:** `nums = [1, 1, 2, 1, 1], k = 3`
   - **Output:** `2`
   - **Explanation:** The subarrays with 3 odd numbers are:
     - `[1, 1, 2, 1]`
     - `[1, 2, 1, 1]`

2. **Example 2:**

   - **Input:** `nums = [2, 4, 6], k = 1`
   - **Output:** `0`
   - **Explanation:** There are no odd numbers in the array.

3. **Example 3:**
   - **Input:** `nums = [2, 2, 2, 1, 2, 2, 1, 2, 2, 2], k = 2`
   - **Output:** `16`

### Constraints

- \(1 \leq \text{nums.length} \leq 50,000\)
- \(1 \leq \text{nums[i]} \leq 10^5\)
- \(1 \leq k \leq \text{nums.length}\)

---

## Solutions

### 1. Optimized Sliding Window Approach

The problem can be solved using a **sliding window** technique that counts subarrays with at most `goal` odd numbers, allowing us to derive the number of subarrays with exactly `k` odd numbers by taking the difference between counts for `k` and `k-1`.

### Approach

1. **Helper Function**: `numberOfSubarraysLessThanOrEqual` counts the number of subarrays that have at most a specified number of odd elements:

   - Use two pointers (`left` and `right`) to maintain a window.
   - Increment `right` and add the parity (0 for even, 1 for odd) of `nums[right]` to `sum`.
   - If `sum` exceeds the `goal`, increment `left` and adjust `sum` until it meets the condition.
   - For each valid window, count the number of subarrays by adding `(right - left + 1)`.

2. **Main Function**: `numberOfSubarrays` uses the helper function to find the difference between subarrays with at most `k` odd numbers and `k-1` odd numbers, yielding the count of subarrays with exactly `k` odd numbers.

3. **Time Complexity**: \(O(n)\), where \(n\) is the length of `nums`. Each element is processed at most twice.
4. **Space Complexity**: \(O(1)\), as only a few extra variables are used for tracking the window.

---

### C++ Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * numberOfSubarraysLessThanOrEqual - Helper function to count the number of subarrays with at most a specified number of odd numbers.
     *
     * @param nums The input array of integers.
     * @param goal The target count of odd numbers.
     * @return The count of subarrays with at most `goal` odd numbers.
     *
     * Time Complexity: O(2n), where n is the size of the input array `nums`.
     * Space Complexity: O(1), as the function uses a few extra variables for tracking.
     */
    int numberOfSubarraysLessThanOrEqual(vector<int>& nums, int goal) {
        if (goal < 0) return 0; // Base case: if goal is negative, return 0.
        int n = nums.size();
        int left = 0, right = 0, sum = 0, count = 0;

        // Traverse through the array using the right pointer.
        while (right < n) {
            sum += (nums[right] % 2); // Add 1 to sum if the current number is odd.

            // Adjust the window if the sum exceeds the goal.
            while (sum > goal) {
                sum -= (nums[left] % 2); // Subtract 1 if the number at `left` is odd.
                left++; // Shrink the window from the left.
            }

            // Count subarrays that end at `right` with sums less than or equal to `goal`.
            count += (right - left + 1);
            right++; // Move the right pointer to expand the window.
        }

        return count;
    }

    /**
     * numberOfSubarrays - Main function to count the number of subarrays with exactly `k` odd numbers.
     *
     * @param nums The input array of integers.
     * @param k The target count of odd numbers in each subarray.
     * @return The count of subarrays with exactly `k` odd numbers.
     *
     * Uses the difference between counts for `k` and `k-1` to find the exact count.
     */
    int numberOfSubarrays(vector<int>& nums, int k) {
        return numberOfSubarraysLessThanOrEqual(nums, k) -
               numberOfSubarraysLessThanOrEqual(nums, k - 1);
    }
};

/*
Analysis:
- Time Complexity: O(4n), where n is the length of the input array. The sliding window ensures that each element is processed at most twice.
- Space Complexity: O(1), as the solution uses a constant amount of extra space for variables like `left`, `right`, `sum`, and `count`.
- This approach efficiently calculates the count of subarrays with exactly `k` odd numbers using a sliding window technique.
*/
```

### Explanation of the Code

1. **Helper Function**: `numberOfSubarraysLessThanOrEqual` calculates the number of subarrays with a sum of odd numbers less than or equal to a given `goal`.
2. **Main Function**: `numberOfSubarrays` calculates the difference between:
   - Subarrays with up to `k` odd numbers.
   - Subarrays with up to `k - 1` odd numbers.
   - This difference gives the count of subarrays with exactly `k` odd numbers.

---

## Conclusion

This solution effectively handles large input sizes using the sliding window technique, maintaining a balance between simplicity and performance. It is well-suited for competitive programming and real-world scenarios involving large arrays and specific conditions. Feel free to explore and modify the code for your needs!
