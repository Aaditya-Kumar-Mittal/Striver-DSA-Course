# Stack - Sum of Subarray Ranges

## Problem Description

This program computes the sum of subarray ranges for a given array of integers. The subarray range is defined as the difference between the maximum and minimum elements in each subarray. The goal is to compute the sum of these ranges for all possible subarrays in linear time.

## Approach

We use a stack-based approach to compute the sum of subarray ranges efficiently. Specifically, we calculate the contribution of each element as the maximum and minimum element in various subarrays and aggregate the results.

## Time and Space Complexity

- **Time Complexity:** O(n), where `n` is the number of elements in the input array. Each element is pushed and popped from the stack at most once during the four passes through the array.
- **Space Complexity:** O(n), due to the use of four additional vectors to store the indices of the next and previous larger and smaller elements.

## Key Concepts

1. **Next Larger Element (NLE):** For each element, find the index of the next larger element. If no such element exists, set the value to `n` (size of the array).
2. **Previous Larger or Equal Element (PLEE):** For each element, find the index of the previous larger or equal element. If no such element exists, set the value to `-1`.
3. **Next Smaller Element (NSE):** For each element, find the index of the next smaller element. If no such element exists, set the value to `n`.
4. **Previous Smaller Element (PSEE):** For each element, find the index of the previous smaller element. If no such element exists, set the value to `-1`.

Using these arrays (NLE, PLEE, NSE, PSEE), we calculate how many subarrays each element can serve as the maximum and the minimum, and aggregate their contributions to the final answer.

## Code Explanation

```cpp
class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> st;
        vector<long long> NLE(n, 0), PLEE(n, 0), NSE(n, 0), PSEE(n, 0);

        // Calculate NLE (Next Larger Element)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] <= nums[i])
                st.pop();
            NLE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Calculate PLEE (Previous Larger or Equal Element)
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] < nums[i])
                st.pop();
            PLEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Calculate NSE (Next Smaller Element)
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && nums[st.top()] >= nums[i])
                st.pop();
            NSE[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Calculate PSEE (Previous Smaller Element)
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && nums[st.top()] > nums[i])
                st.pop();
            PSEE[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        long long ans = 0;

        // Calculate the contribution of each element to the final answer
        for (int i = 0; i < n; i++)
        {
            ans += (long)(nums[i] * (((i - PLEE[i]) * (NLE[i] - i)) - ((i - PSEE[i]) * (NSE[i] - i))));
        }

        return ans;
    }
};
```

## Example

Input:

```cpp
vector<int> nums = {1, 4, 6, 7, 3, 7, 8, 1};
```

Output:

```cpp
Sum of subarray ranges: 147
```

### How it Works

- **Next and Previous Calculations:** We use stacks to calculate four arrays: `NLE`, `PLEE`, `NSE`, and `PSEE`, which represent the next larger element, previous larger or equal element, next smaller element, and previous smaller element, respectively.
- **Contribution Calculation:** For each element in the array, we calculate how many subarrays it can act as the maximum and minimum element, and add their contributions accordingly to the result.

## Conclusion

This stack-based approach efficiently computes the sum of subarray ranges with optimal time complexity of O(n). By leveraging the next and previous larger/smaller element indices, the solution ensures that each element's contribution to the total range sum is calculated in linear time.

## Other Methods

### Solution - 2

```cpp
class Solution
{
public:
  long long subarrayRanges(int n, vector<int> &arr)
  {

    vector<pair<int, int>> vsm(n);
    vector<pair<int, int>> vmx(n);
    stack<pair<int, int>> sts;
    stack<pair<int, int>> stm;

    for (int i = n - 1; i >= 0; i--)
    {

      while (!sts.empty() && sts.top().first >= arr[i])
        sts.pop();
      while (!stm.empty() && stm.top().first <= arr[i])
        stm.pop();

      (sts.empty()) ? vsm[i].second = n - i : vsm[i].second = sts.top().second - i;
      (stm.empty()) ? vmx[i].second = n - i : vmx[i].second = stm.top().second - i;

      sts.push({arr[i], i});
      stm.push({arr[i], i});
    }

    while (!sts.empty())
    {
      sts.pop();
    }
    while (!stm.empty())
    {
      stm.pop();
    }

    for (int i = 0; i < n; i++)
    {

      while (!sts.empty() && sts.top().first > arr[i])
        sts.pop();
      while (!stm.empty() && stm.top().first < arr[i])
        stm.pop();

      (sts.empty()) ? vsm[i].first = i + 1 : vsm[i].first = i - sts.top().second;
      (stm.empty()) ? vmx[i].first = i + 1 : vmx[i].first = i - stm.top().second;

      sts.push({arr[i], i});
      stm.push({arr[i], i});
    }

    long long summ = 0;
    long long sums = 0;
    int mod = 1e9 + 7;
    for (int i = 0; i < n; i++)
    {
      summ = (summ + ((long long)vmx[i].first * vmx[i].second * arr[i]) % mod % mod);
      sums = (sums + ((long long)vsm[i].first * vsm[i].second * arr[i]) % mod % mod);
    }
    return summ - sums;
  }
};
```
