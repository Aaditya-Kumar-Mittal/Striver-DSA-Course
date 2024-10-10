# Sliding Window and Two Pointers - Max Consecutive Ones III

## Problem Description

Given a binary array `nums` and an integer `k`, the task is to find the maximum number of consecutive `1`s that can be achieved in the array if you are allowed to flip at most `k` `0`s into `1`s.

### Example Scenarios

1. **Example 1**:

   - **Input**: `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`
   - **Output**: `6`
   - **Explanation**: By flipping two `0`s (the 4th and 5th positions), the longest sequence of consecutive `1`s becomes `1,1,1,0,0,1,1,1,1,1,1`.

2. **Example 2**:
   - **Input**: `nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]`, `k = 3`
   - **Output**: `10`
   - **Explanation**: By flipping three `0`s (the 4th, 5th, and 10th positions), the longest sequence of consecutive `1`s becomes `0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1`.

### Constraints

- `1 <= nums.length <= 10^5`
- `nums[i]` is either `0` or `1`.
- `0 <= k <= nums.length`

---

### Approach

To solve this problem, we use a **sliding window** approach:

1. **Sliding Window with Two Pointers**:
   - Use two pointers, `left` and `right`, to define the window of consideration.
   - As `right` moves over the array, if the current element is `0`, increase the `zeroCount` by `1`.
2. **Validating the Window**:
   - If `zeroCount` exceeds `k`, increment the `left` pointer until the `zeroCount` is within the allowed limit.
   - This ensures that the window size represents a valid segment of flipped `0`s.
3. **Track Maximum Length**:
   - For each valid window, calculate its length using `right - left + 1` and update `maxLen` with the maximum length observed.

### Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the length of `nums`. Both pointers, `left` and `right`, traverse the array at most once.
- **Space Complexity**: `O(1)`, as only a few variables are used for tracking window size and counts.

---

### Code Implementation

```cpp
class Solution {
public:
    /**
     * @brief Finds the maximum number of consecutive 1's in the array if up to `k` 0's can be flipped.
     *
     * @param nums The binary array where elements are either 0 or 1.
     * @param k The maximum number of 0's that can be flipped to 1's.
     * @return int The maximum length of consecutive 1's after flipping at most `k` 0's.
     */
    int longestOnes(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int left = 0, right = 0;   // Pointers for the sliding window
        int maxLen = 0;            // Variable to store the maximum length of consecutive 1's
        int zeroCount = 0;         // Tracks the number of 0's in the current window
        int n = nums.size();       // Size of the input array

        // Iterate through the array with the `right` pointer
        while (right < n) {
            // If the current element is 0, increment `zeroCount`
            if (nums[right] == 0) {
                zeroCount++;
            }

            // If `zeroCount` exceeds `k`, shrink the window from the left
            if (zeroCount > k) {
                // If the element at `left` is 0, decrement `zeroCount`
                if (nums[left] == 0) {
                    zeroCount--;
                }
                // Move the `left` pointer to maintain a valid window
                left++;
            }

            // Calculate the length of the current window
            int len = right - left + 1;

            // Update `maxLen` with the maximum length found so far
            maxLen = max(maxLen, len);

            // Move the `right` pointer to the next element
            right++;
        }

        // Return the maximum length of consecutive 1's
        return maxLen;
    }
};
```

---

### Explanation of the Code

1. **Initial Setup**:

   - `left` and `right` pointers are used to define the window of consideration.
   - `zeroCount` keeps track of the number of `0`s in the current window.
   - `maxLen` keeps track of the maximum length of `1`s found so far.

2. **Iterating with the `right` Pointer**:

   - As `right` iterates over `nums`, each `0` encountered increases the `zeroCount`.
   - If `zeroCount` exceeds `k`, adjust the `left` pointer until `zeroCount` is at most `k`.

3. **Updating the Window**:

   - Calculate the length of the current window using `right - left + 1`.
   - Update `maxLen` if the current window length is greater than the previously recorded maximum.

4. **Return the Result**:
   - After processing all elements, `maxLen` will contain the length of the longest sequence of `1`s.

---

### Example Walkthrough

For `nums = [1,1,1,0,0,0,1,1,1,1,0]`, `k = 2`:

1. `left = 0`, `right = 0`, `zeroCount = 0`.
2. Iterate through `nums`:
   - `right = 3`, `zeroCount = 1` (one `0` encountered).
   - `right = 5`, `zeroCount = 3` (three `0`s encountered).
   - Adjust `left` until `zeroCount <= 2`.
   - Continue until `right = 10`.
3. The longest sequence of consecutive `1`s is `6`.

---

### Edge Cases

1. **All `1`s**: If `nums` contains only `1`s, then the output should be the length of `nums` as no flipping is needed.
2. **All `0`s**: If `nums` contains only `0`s and `k` is at least the length of `nums`, the output should be the length of `nums` because all `0`s can be flipped to `1`s.
3. **No Flips Allowed (`k = 0`)**: If `k` is `0`, then the output should be the length of the longest segment of consecutive `1`s without flipping any `0`s.

---

### Conclusion

The sliding window approach efficiently solves the problem by keeping track of the number of `0`s and adjusting the window size to maximize the number of consecutive `1`s. With a time complexity of `O(n)`, the solution is optimal for large input sizes.

## Other Approaches

### Approach - 2

```cpp
class Solution
{
public:
  int longestOnes(vector<int> &nums, int k)
  {
    for (auto &i : nums)
    {
      if (i == 1)
        i = 0;
      else
        i = 1;
    }
    int l = 0, r = 0, ans = 0, sum = 0;
    while (r < nums.size())
    {
      sum += nums[r];
      while (sum > k)
      {
        sum -= nums[l];
        l++;
      }
      if (sum <= k)
      {
        ans = max(ans, r - l + 1);
      }
      r++;
    }
    return ans;
  }
};
```
