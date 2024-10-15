# 992. Subarrays with K Different Integers

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of **good subarrays** of `nums`.

A **good array** is an array where the number of different integers in that array is exactly `k`. For example, `[1,2,3,1,2]` has `3` different integers: `1`, `2`, and `3`.

A **subarray** is a contiguous part of an array.

## Examples

1. **Example 1:**

   - **Input:**

     ```plaintext
     nums = [1, 2, 1, 2, 3], k = 2
     ```

   - **Output:**

     ```plaintext
     7
     ```

   - **Explanation:** Subarrays formed with exactly `2` different integers:
     - `[1, 2]`
     - `[2, 1]`
     - `[1, 2]`
     - `[2, 3]`
     - `[1, 2, 1]`
     - `[2, 1, 2]`
     - `[1, 2, 1, 2]`

2. **Example 2:**

   - **Input:**

     ```plaintext
     nums = [1, 2, 1, 3, 4], k = 3
     ```

   - **Output:**

     ```plaintext
     3
     ```

   - **Explanation:** Subarrays formed with exactly `3` different integers:
     - `[1, 2, 1, 3]`
     - `[2, 1, 3]`
     - `[1, 3, 4]`

### Constraints

- \(1 \leq \text{nums.length} \leq 2 \times 10^4\)
- \(1 \leq \text{nums[i]}, k \leq \text{nums.length}\)

---

### Solutions

#### Approach

The problem can be solved efficiently using the **Sliding Window** technique combined with a **Hash Map** for counting the occurrences of elements within the window. The key insight is to use the difference between the counts of subarrays with **at most** `k` distinct integers and **at most** `k-1` distinct integers.

#### Strategy

To count the number of subarrays with exactly `k` distinct integers, we can leverage a helper function that counts the number of subarrays with **at most** `k` distinct integers. The difference between the counts for `k` and `k-1` gives the number of subarrays with **exactly** `k` distinct integers:

\[ \text{exactly k distinct} = \text{at most k distinct} - \text{at most (k - 1) distinct} \]

#### Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Helper function to count subarrays with at most `k` distinct elements.
     *
     * @param nums The input array of integers.
     * @param k The maximum number of distinct elements allowed in the subarray.
     * @return The count of subarrays with at most `k` distinct elements.
     */
    int subarraysWithKDistinctLessThanEqualTo(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = 0, count = 0;
        unordered_map<int, int> mpp; // To store the frequency of elements in the current window

        // Sliding window to traverse the array
        while (right < n) {
            mpp[nums[right]]++; // Increment frequency of the element at `right`

            // If the number of distinct elements exceeds `k`, adjust the window
            while (mpp.size() > k) {
                mpp[nums[left]]--; // Decrement the frequency of the element at `left`
                if (mpp[nums[left]] == 0) {
                    mpp.erase(nums[left]); // Remove the element if its frequency becomes 0
                }
                left++; // Move the left pointer to shrink the window
            }

            // Count subarrays with at most `k` distinct elements
            count += (right - left + 1);
            right++; // Move the right pointer to expand the window
        }

        return count;
    }

    /**
     * Main function to count the subarrays with exactly `k` distinct elements.
     *
     * @param nums The input array of integers.
     * @param k The exact number of distinct elements in the subarray.
     * @return The count of subarrays with exactly `k` distinct elements.
     */
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        cout.tie(NULL);

        return subarraysWithKDistinctLessThanEqualTo(nums, k) -
               subarraysWithKDistinctLessThanEqualTo(nums, k - 1);
    }
};
```

---

### Explanation

#### `subarraysWithKDistinctLessThanEqualTo` Function

- **Purpose:** Count subarrays with at most `k` distinct integers.
- **Sliding Window Technique:**
  - Expand the window by moving `right` and adding `nums[right]` to the window.
  - If the number of distinct integers exceeds `k`, increment `left` to shrink the window until the number of distinct integers becomes ≤ `k`.
  - At each step, count the number of valid subarrays ending at `right` as `(right - left + 1)`.

#### `subarraysWithKDistinct` Function

- Uses the helper function to compute:
  - Subarrays with at most `k` distinct integers.
  - Subarrays with at most `k-1` distinct integers.
  - Subtracts the two results to find the number of subarrays with exactly `k` distinct integers.

---

### Complexity Analysis

- **Time Complexity:**
  - **O(4 \* n)**, where `n` is the length of the input array `nums`. The sliding window ensures that each element is processed at most twice (once when the `right` pointer moves and once when the `left` pointer moves).
- **Space Complexity:**
  - **O(2 \* k)**, where `k` is the number of distinct elements allowed in the subarray. This is due to the space used by the `unordered_map` to store the frequency of elements within the sliding window.

### Edge Cases

1. **All Elements Are Distinct:** If `k` is equal to the length of the array and all elements are distinct, the entire array itself is the only valid subarray.
2. **All Elements Are the Same:** If `k` is `1` and all elements are the same, every possible subarray will be a valid subarray.
3. **`k` Greater Than Number of Unique Elements:** If `k` is greater than the number of unique elements in the array, there will be no valid subarrays.

---

### Conclusion

This approach efficiently solves the problem using a sliding window technique combined with a hash map for frequency counting. By leveraging the properties of subarrays with at most `k` distinct integers, we can derive the count of subarrays with exactly `k` distinct integers through subtraction. This solution is optimized for the given constraints and performs well even with larger input sizes.

## Other Solutions

### Solution - 2

```cpp
#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int window(vector<int>& a, int k) {
        vector<int>m(20001);
        int start = 0;
        int len = 0;
        int total=0;
        for (int end = 0; end < a.size(); end++) {
            if(m[a[end]]++==0)total++;
            while (total > k) {
                m[a[start]]--;
                if (!m[a[start]]) {
                    total--;
                }
                start++;
            }
            len += (end - start + 1);
        }
        return len - a.size();
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        return window(a,k)-window(a,k-1);
    }
};
static const auto booster = []()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    return false;
}();
```
