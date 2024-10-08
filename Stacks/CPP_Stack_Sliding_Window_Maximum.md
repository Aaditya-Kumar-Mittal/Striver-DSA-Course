# Max Sliding Window Problem

## Problem Description

You are given an array of integers `nums`, and there is a sliding window of size `k` which is moving from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position, you need to determine the maximum element in the current window.

### Example 1

- **Input**:
  - `nums = [1, 3, -1, -3, 5, 3, 6, 7]`
  - `k = 3`
- **Output**: `[3, 3, 5, 5, 6, 7]`
- **Explanation**:
  - Window position | Max
  - ------------------------------|-----
  - `[1  3  -1] -3  5  3  6  7` | 3
  - `1 [3  -1  -3] 5  3  6  7` | 3
  - `1  3 [-1  -3  5] 3  6  7` | 5
  - `1  3  -1 [-3  5  3] 6  7` | 5
  - `1  3  -1  -3 [5  3  6] 7` | 6
  - `1  3  -1  -3  5 [3  6  7]` | 7

### Example 2

- **Input**:
  - `nums = [1]`
  - `k = 1`
- **Output**: `[1]`
- **Explanation**:
  - With only one element and `k = 1`, the sliding window only contains the element itself, so the output is `[1]`.

### Constraints

- `1 <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`
- `1 <= k <= nums.length`

---

## Approaches

### 1. Brute Force Approach

In the brute force approach, we compute the maximum for each window of size `k` by iterating through all possible windows.

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxSlides;

        // Iterate over all windows of size 'k'
        for (int i = 0; i <= n - k; i++) {
            int maxi = nums[i];

            // Find the maximum element in the current window
            for (int j = i; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
            }

            maxSlides.push_back(maxi);
        }

        return maxSlides;
    }
};
```

#### Time Complexity

- **Time**: `O(n * k) * O(k)` - For each window, we scan `k` elements to find the maximum.
- **Space**: `O(n - k)` - Only uses a few variables and the result vector.

### Drawbacks

- This approach is inefficient for large input sizes (`n` up to `10^5`) as it results in high time complexity.
- Suitable for small `n` but results in timeouts for larger inputs.

---

### 2. Optimized Approach using Deque

The optimized approach uses a **deque** to efficiently keep track of the indices of the elements in a way that helps find the maximum element for each window.

```cpp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxSlides;
        deque<int> dq;  // Store indices of elements in the current window

        for(int i = 0; i < n; i++) {
            // Remove indices from the deque that are outside the current window.
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Maintain the decreasing order of values in deque.
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add the current element index to the deque.
            dq.push_back(i);

            // Store the maximum value for the current window.
            if (i >= k - 1) {
                maxSlides.push_back(nums[dq.front()]);
            }
        }

        return maxSlides;
    }
};
```

### Time Complexity of Optimized Approach

- **Time**: `O(2n)` - Each element is pushed and popped from the deque at most once and `O(n)` for the entire for loop.
- **Space**: `O(k)` - The deque stores at most `k` indices at any time.

#### Explanation

- **Deque as a Monotonic Queue**:
  - The deque stores indices of elements in a way such that elements are in decreasing order.
  - This ensures that the front of the deque always has the index of the maximum element for the current window.
- **Efficient Window Management**:
  - If the front of the deque has an index outside the current window, it is removed.
  - Elements smaller than the current element are removed from the back of the deque to maintain order.

#### Advantages

- This approach is highly efficient for large inputs due to its `O(n)` time complexity.
- It significantly reduces redundant comparisons by maintaining a sorted deque.

---

## Example Analysis

### Example Input: `nums = [1, 3, -1, -3, 5, 3, 6, 7]`, `k = 3`

- **Step-by-Step with Deque**:
  - For `i = 0`: `nums[0] = 1`, add `0` to the deque.
  - For `i = 1`: `nums[1] = 3`, pop `0` and add `1` (as `3 > 1`).
  - For `i = 2`: `nums[2] = -1`, add `2` to the deque. Window is `[1, 3, -1]`, maximum is `nums[1] = 3`.
  - For `i = 3`: `nums[3] = -3`, add `3` to the deque. Window is `[3, -1, -3]`, maximum is `nums[1] = 3`.
  - Continue until `i = 7`.
  - The final result is `[3, 3, 5, 5, 6, 7]`.

---

## Summary

- **Brute Force**: Simple but inefficient for large arrays due to `O(n * k)` complexity.
- **Optimized Approach using Deque**: A more advanced solution that reduces the complexity to `O(n)` using a deque.
- **Use Cases**:
  - The brute force method can be used for small inputs for simplicity.
  - The deque approach is suitable for larger inputs and competitive programming.

---

## How to Use

1. **Choose Approach**: Use the brute force for smaller input sizes or if simplicity is preferred. Use the deque approach for larger input sizes.
2. **Input**: Provide `nums` and `k` as per the problem description.
3. **Output**: The function will return a vector containing the maximum values for each sliding window of size `k`.

---

## References

- Problem Link: [LeetCode - Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/)
- Concepts Used: Sliding window, deque, time complexity optimization.
