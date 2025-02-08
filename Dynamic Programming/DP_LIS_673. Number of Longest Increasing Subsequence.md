# Number of Longest Increasing Subsequences

## Table of Contents

- [Number of Longest Increasing Subsequences](#number-of-longest-increasing-subsequences)
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
  - [Other Solutions](#other-solutions)
    - [Solution - 1 (My Leetcode Submission)](#solution---1-my-leetcode-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)
    - [Solution - 5](#solution---5)

## Introduction

Given an integer array `nums`, the task is to return the number of longest increasing subsequences (LIS). A sequence is strictly increasing if each element is greater than the previous one.

## Problem Description

### Examples

#### Example 1

**Input:**

```cpp
nums = [1,3,5,4,7]
```

**Output:**

```cpp
2
```

**Explanation:**  
The two longest increasing subsequences are `[1, 3, 4, 7]` and `[1, 3, 5, 7]`.

#### Example 2

**Input:**

```cpp
nums = [2,2,2,2,2]
```

**Output:**

```cpp
5
```

**Explanation:**  
The length of the longest increasing subsequence is `1`, and there are `5` increasing subsequences of length `1`.

### Constraints

- `1 <= nums.length <= 2000`
- `-10^6 <= nums[i] <= 10^6`
- The answer is guaranteed to fit inside a 32-bit integer.

## Approach

1. Use **Dynamic Programming** to calculate the length of the LIS for each index.
2. Maintain a **count array** to store the number of times each LIS length occurs.
3. Iterate through the array and update the LIS length and count dynamically.
4. Finally, sum the counts of all subsequences that have the maximum LIS length.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);
        int maxi = 1; // Length of the longest LIS found so far

        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i] && 1 + dp[p] > dp[i]) {
                    dp[i] = 1 + dp[p];
                    count[i] = count[p];
                } else if (nums[p] < nums[i] && 1 + dp[p] == dp[i]) {
                    count[i] += count[p];
                }
            }
            maxi = max(maxi, dp[i]);
        }

        int nos = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                nos += count[i];
        }
        return nos;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n^2)` - We iterate over each pair `(i, p)` in the nested loop.
- **Space Complexity:** `O(n)` - Two arrays (`dp` and `count`) are used, each of size `n`.

## How to Run the Code

### For C++

1. Copy the provided C++ code into a `.cpp` file.
2. Compile using:

   ```sh
   g++ -std=c++11 filename.cpp -o output
   ```

3. Run the executable:

   ```sh
   ./output
   ```

This implementation efficiently calculates the number of longest increasing subsequences while maintaining optimal performance.

## Other Solutions

### Solution - 1 (My Leetcode Submission)

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, 1), count(n, 1);

        int maxi = 1; // Length of the longest LIS found so far

        // Fill dp
        for (int i = 0; i < n; i++) {

            for (int p = 0; p < i; p++) {
                if (nums[p] < nums[i] && 1 + dp[p] > dp[i]) {
                    dp[i] = 1 + dp[p];
                    count[i] = count[p];
                } else if (nums[p] < nums[i] && 1 + dp[p] == dp[i]) {
                    count[i] += count[p];
                }
            }

            maxi = max(maxi, dp[i]);
        }

        int nos = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == maxi)
                nos += count[i];
        }

        return nos;
    }
};
```

```java
public int findNumberOfLIS(int[] nums) {
        int n = nums.length, res = 0, max_len = 0;
        int[] len =  new int[n], cnt = new int[n];
        for(int i = 0; i<n; i++){
            len[i] = cnt[i] = 1;
            for(int j = 0; j <i ; j++){
                if(nums[i] > nums[j]){
                    if(len[i] == len[j] + 1)cnt[i] += cnt[j];
                    if(len[i] < len[j] + 1){
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }
                }
            }
            if(max_len == len[i])res += cnt[i];
            if(max_len < len[i]){
                max_len = len[i];
                res = cnt[i];
            }
        }
        return res;
    }
```

### Solution - 2

```cpp
class BinaryIndexedTree
{
  int n;
  vector<int> bit;
  vector<int> count;

public:
  BinaryIndexedTree(int n) : n(n), bit(n + 1, 0), count(n + 1, 0) {}
  void update(int idx, int val, int c)
  {
    for (; idx <= n; idx += (idx & -idx))
    {
      if (bit[idx] < val)
      {
        count[idx] = c;
      }
      else if (bit[idx] == val)
      {
        count[idx] += c;
      }
      bit[idx] = max(bit[idx], val);
    }
  }
  pair<int, int> query(int idx)
  {
    int ans = 0;
    int cnt = 0;
    for (; idx > 0; idx -= (idx & -idx))
    {
      if (bit[idx] > ans)
      {
        cnt = count[idx];
      }
      else if (bit[idx] == ans)
      {
        cnt += count[idx];
      }
      ans = max(bit[idx], ans);
    }
    return {ans, cnt};
  }
};

class Solution
{
public:
  int findNumberOfLIS(vector<int> &nums)
  {
    vector<int> arr = nums;
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    int m = arr.size();
    BinaryIndexedTree tree(m);
    for (int x : nums)
    {
      auto it = lower_bound(arr.begin(), arr.end(), x);
      int i = distance(arr.begin(), it) + 1;
      auto [v, cnt] = tree.query(i - 1);
      tree.update(i, v + 1, max(cnt, 1));
    }
    return tree.query(m).second;
  }
};
```

### Solution - 3

```cpp
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if (nums.empty())
            return 0;

        //
        // ns - stores the elements and their index in the original array
        // bit - the Binary Index Tree (aka Fenwick tree)
        //
        // The tree will store maximum lengths of increasing subsequences,
        // along with their corresponding count
        //
        std::vector<std::pair<int, int>> ns(nums.size()), bit(nums.size());
        std::pair<int, int> max, m;
        int k;

        //
        // Remember the original position of each element
        //
        for (unsigned i = 0; i < nums.size(); ++i)
            ns[i] = {nums[i], i};

        //
        // Sort the elements in increasing order.
        // The equal elements need to appear in reverse order relative to
        // their original position (opposite of stable sort)
        //
        std::sort(std::begin(ns), std::end(ns), [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) {
            if (p1.first == p2.first)
                return p1.second > p2.second;
            return p1.first < p2.first;
        });

        for (const auto &p : ns)
        {
            //
            // Get the maximum value and its count left to
            // the index of current element
            //
            m = {0, 1}, k = p.second;
            while (k > 0)
            {
                if (bit[k - 1].first > m.first)
                    m = bit[k - 1];
                else if (bit[k - 1].first == m.first)
                    m.second += bit[k - 1].second;
                k = k & (k - 1);
            }
            ++m.first;

            //
            // Update the global maximum
            //
            if (m.first > max.first)
                max = m;
            else if (m.first == max.first)
                max.second += m.second;

            //
            // Update the tree
            //
            k = p.second + 1;
            while (k <= static_cast<int>(nums.size()))
            {
                if (m.first > bit[k - 1].first)
                    bit[k - 1] = m;
                else if (m.first == bit[k - 1].first)
                    bit[k - 1].second += m.second;
                k += k & (-k);
            }
        }

        return max.second;
    }
};
```

### Solution - 4

```cpp
class Solution {
    int binarySearch(int n, function<bool(int)> f) {
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (f(mid)) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<vector<int>> d, cnt;
        for (int v : nums) {
            int i = binarySearch(d.size(), [&](int i) { return d[i].back() >= v; });
            int c = 1;
            if (i > 0) {
                int k = binarySearch(d[i - 1].size(), [&](int k) { return d[i - 1][k] < v; });
                c = cnt[i - 1].back() - cnt[i - 1][k];
            }
            if (i == d.size()) {
                d.push_back({v});
                cnt.push_back({0, c});
            } else {
                d[i].push_back(v);
                cnt[i].push_back(cnt[i].back() + c);
            }
        }
        return cnt.back().back();
    }
};
```

### Solution - 5

```cpp
#include <algorithm>
#include <cstddef>
#include <cstdlib>
#include <unordered_map>
#include <vector>

template <typename T = std::pair<int, int>>
class PURQ {
 public:
  PURQ(int m) : n_(m), ft_(m + 1, {0, 0}) {}

  // prefix sum
  constexpr T prefix(int i) const { return query(i); }

  // i is 1-indexed.
  constexpr void update(int i, T val) {
    while (i <= n_) {
      if (ft_[i].first < val.first) {
        ft_[i] = val;
      } else if (ft_[i].first == val.first) {
        ft_[i].second += val.second;
      }

      i += i & -i;
    }
  }

 private:
  // i is 1-indexed, as this can only be invoked internally.
  constexpr T query(int i) const {
    T sum = {0, 0};
    while (i > 0) {
      if (sum.first < ft_[i].first) {
        sum = ft_[i];
      } else if (sum.first == ft_[i].first) {
        sum.second += ft_[i].second;
      }
      i -= i & -i;
    }

    return sum;
  }

  std::size_t n_{};
  std::vector<T> ft_;
};

class Solution {
 public:
  int findNumberOfLIS(std::vector<int>& nums) {
    // discretize/compress
    std::vector<int> sorted = nums;
    std::sort(sorted.begin(), sorted.end());

    // 1-indexed.
    int k = 1;
    std::unordered_map<int, int> indices;
    indices.reserve(sorted.size());
    indices[sorted[0]] = k;
    for (int i = 1; i < sorted.size(); ++i) {
      if (sorted[i] != sorted[i - 1]) {
        indices[sorted[i]] = ++k;
      }
    }

    int maxLength = 0;
    int lisCount = 0;

    PURQ<std::pair<int, int>> purq(k);
    for (int num : nums) {
      const int idx = indices[num];

      // query the greatest subsequence length and the respective count of
      // elements smaller than this num.
      auto [len, cnt] = purq.prefix(idx - 1);

      ++len;  // to include the current element in the subsequence.
      if (cnt == 0) {
        cnt = 1;  // start a new sequence ending with this value.
      }

      if (len > maxLength) {
        maxLength = len;
        lisCount = cnt;
      } else if (len == maxLength) {
        lisCount += cnt;
      }

      purq.update(idx, {len, cnt});
    }
    return lisCount;
  }
};
```
