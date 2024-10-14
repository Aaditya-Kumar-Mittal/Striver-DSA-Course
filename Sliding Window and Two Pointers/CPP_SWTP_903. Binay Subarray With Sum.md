# 903. Binary Subarrays with Sum

## Overview

This project solves the problem of counting the number of non-empty subarrays in a binary array that have a sum equal to a given goal. It utilizes the **sliding window** technique and mathematical manipulation to efficiently calculate the number of valid subarrays.

## Problem Statement

### Given

- A binary array `nums` containing only `0`s and `1`s.
- An integer `goal`, representing the desired sum of subarrays.

### Task

Return the number of non-empty subarrays in `nums` whose sum equals `goal`.

### Example

- **Input:** `nums = [1, 0, 1, 0, 1]`, `goal = 2`
  - **Output:** `4`
  - **Explanation:** The subarrays with a sum of `2` are:
    - `[1, 0, 1]`
    - `[0, 1, 0, 1]`
    - `[1, 0, 1]`
    - `[1, 0, 1]`
- **Input:** `nums = [0, 0, 0, 0, 0]`, `goal = 0`
  - **Output:** `15`
  - **Explanation:** All subarrays formed have a sum of `0`.

## Constraints

- \(1 \leq \text{nums.length} \leq 30,000\)
- \(0 \leq \text{goal} \leq \text{nums.length}\)
- `nums[i]` is either `0` or `1`.

## Approach

The solution uses a sliding window approach to count the number of subarrays with a sum less than or equal to a given value, which is then used to derive the number of subarrays with a sum exactly equal to `goal`.

### Explanation

1. **Helper Function**: `numSubarraysWithSumLessThanOrEqual` counts the subarrays with a sum less than or equal to a specified `goal` using a sliding window:

   - Maintain a window defined by two pointers, `left` and `right`.
   - Expand the `right` pointer and add the corresponding element to the `sum`.
   - If the `sum` exceeds `goal`, increment the `left` pointer to shrink the window until `sum` is less than or equal to `goal`.
   - The count of subarrays ending at the `right` index that have sums less than or equal to `goal` is `right - left + 1`.
   - Sum this value to get the total count of valid subarrays.

2. **Main Function**: `numSubarraysWithSum` calculates the difference between:

   - Subarrays with sums less than or equal to `goal`.
   - Subarrays with sums less than or equal to `goal - 1`.
   - This difference gives the count of subarrays with sums exactly equal to `goal`.

3. **Time Complexity**: \(O(n)\) - Each element is processed at most twice (once when expanding `right` and possibly once when contracting `left`).
4. **Space Complexity**: \(O(1)\) - The extra space used is only for variables (`left`, `right`, `sum`, `count`).

## Code - 1

Here is the complete implementation of the solution:

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * numSubarraysWithSumLessThanOrEqual - Helper function to count the number of subarrays with a sum less than or equal to a given goal.
     *
     * @param nums The binary input array.
     * @param goal The target sum.
     * @return The number of subarrays with a sum less than or equal to the goal.
     *
     * Time Complexity: O(2n) - Each element is processed at most twice.
     * Space Complexity: O(1) - Only a few extra variables are used.
     */
    int numSubarraysWithSumLessThanOrEqual(vector<int>& nums, int goal) {
        if (goal < 0) return 0;
        int n = nums.size();
        int left = 0, right = 0, sum = 0, count = 0;

        while (right < n) {
            sum += nums[right]; // Expand the window by adding the right element

            // Shrink the window from the left if the sum exceeds the goal
            while (sum > goal) {
                sum -= nums[left]; // Remove the left element from the sum
                left++; // Move the left pointer to the right
            }

            // Count subarrays ending at the 'right' index
            count += (right - left + 1);
            right++; // Move the right pointer to expand the window
        }

        return count;
    }

    /**
     * numSubarraysWithSum - Main function to calculate the number of subarrays with a sum exactly equal to the goal.
     *
     * @param nums The binary input array.
     * @param goal The target sum.
     * @return The number of subarrays with a sum equal to the goal.
     *
     * Uses the difference between subarrays with sums less than or equal to 'goal' and 'goal - 1' to find the exact number.
     */
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithSumLessThanOrEqual(nums, goal) -
               numSubarraysWithSumLessThanOrEqual(nums, goal - 1);
    }
};
```

## Code - 2

```cpp
class Solution
{
public:
  int numSubarraysWithSum(vector<int> &nums, int goal)
  {
    int n = nums.size();
    map<int, int> mpp;
    mpp[0] = 1;
    int presum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
      presum = presum + nums[i];
      int remove = presum - goal;
      cnt = cnt + mpp[remove];
      mpp[presum] = mpp[presum] + 1;
    }
    return cnt;
  }
};
```

## Code - 3

```cpp
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int>mp;
        mp[0] = 1;
        int res = 0;
        int sum = 0;
        for(auto i : nums){
            sum += i;
            int diff = sum - goal;
            if(mp.find(diff) != mp.end())
            res += mp[diff];
            mp[sum]++;
        }
        return res;
    }
};
```
