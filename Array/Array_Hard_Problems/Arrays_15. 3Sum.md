# 3Sum

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [3Sum](#3sum)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Brute-force using HashSet](#brute-force-using-hashset)
    - [Optimized Two-Pointer Approach](#optimized-two-pointer-approach)
  - [Complexity Analysis](#complexity-analysis)
    - [Brute-force using HashSet](#brute-force-using-hashset-1)
    - [Optimized Two-Pointer](#optimized-two-pointer)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)

## Introduction

The 3Sum problem is a classic algorithmic challenge frequently encountered in coding interviews. The goal is to identify all unique triplets in an array that sum to zero.

## Problem Description

Given an integer array `nums`, return _all_ the triplets `[nums[i], nums[j], nums[k]]` such that:

- `i != j`, `i != k`, and `j != k`
- `nums[i] + nums[j] + nums[k] == 0`

The solution must avoid duplicate triplets.

### Examples

**Example 1:**

```text
Input: nums = [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

**Example 2:**

```text
Input: nums = [0, 1, 1]
Output: []
```

**Example 3:**

```text
Input: nums = [0, 0, 0]
Output: [[0, 0, 0]]
```

### Constraints

- `3 <= nums.length <= 3000`
- `-10^5 <= nums[i] <= 10^5`

## Approach

We explore two approaches:

1. **Brute-force using HashSet**: Iterate through all pairs, calculate the third number, and use a set to avoid duplicates.
2. **Optimized Two-Pointer**: Sort the array and use a fixed pointer with a two-pointer technique to efficiently find triplets that sum to zero.

## Detailed Explanation of Code

### Brute-force using HashSet

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> ansSet;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        set<int> hashSet;
        for (int j = i + 1; j < n; j++) {
            int third = -(nums[i] + nums[j]);
            if (hashSet.find(third) != hashSet.end()) {
                vector<int> temp = {nums[i], nums[j], third};
                sort(temp.begin(), temp.end());
                ansSet.insert(temp);
            }
            hashSet.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}
```

### Optimized Two-Pointer Approach

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) {
                j++;
            } else if (sum > 0) {
                k--;
            } else {
                ans.push_back({nums[i], nums[j], nums[k]});
                j++;
                k--;
                while (j < k && nums[j] == nums[j - 1]) j++;
            }
        }
    }
    return ans;
}
```

## Complexity Analysis

### Brute-force using HashSet

- **Time Complexity**: `O(n^2 * log m)` where `m` is the number of unique triplets
- **Space Complexity**: `O(n^2)` due to the set used to store triplets

### Optimized Two-Pointer

- **Time Complexity**: `O(n^2)` — Sorting takes `O(n log n)`, and each pair is evaluated in linear time
- **Space Complexity**: `O(1)` — No extra space other than the output list

## How to Run the Code

### For C++

1. Save the code in a file named `three_sum.cpp`.
2. Compile using a C++ compiler:

   ```sh
   g++ -o three_sum three_sum.cpp
   ./three_sum
   ```

3. Provide input directly in the code or through standard input depending on implementation.

## Other Solutions

### Solution - 1

```cpp
/*

    Time Complexity : O(N^3), Here three nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(N), Hash Table(set) space.

    Solved using Array(Three Nested Loop) + Sorting + Hash Table(set). Brute Force Approach.

    Note : this will give TLE.

*/

/***************************************** Approach 1 *****************************************/

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> output;
    for (int i = 0; i < n - 2; i++)
    {
      for (int j = i + 1; j < n - 1; j++)
      {
        for (int k = j + 1; k < n; k++)
        {
          if ((nums[i] + nums[j] + nums[k] == 0) && i != j && j != k && k != i)
          {
            set.insert({nums[i], nums[j], nums[k]});
          }
        }
      }
    }
    for (auto it : set)
    {
      output.push_back(it);
    }
    return output;
  }
};

/*

    Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(N), Hash Table(set) space.

    Solved using Array(Two Nested Loop) + Sorting + Hash Table(set).

*/

/***************************************** Approach 2 *****************************************/

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> output;
    for (int i = 0; i < n - 2; i++)
    {
      int low = i + 1, high = n - 1;
      while (low < high)
      {
        if (nums[i] + nums[low] + nums[high] < 0)
        {
          low++;
        }
        else if (nums[i] + nums[low] + nums[high] > 0)
        {
          high--;
        }
        else
        {
          set.insert({nums[i], nums[low], nums[high]});
          low++;
          high--;
        }
      }
    }
    for (auto it : set)
    {
      output.push_back(it);
    }
    return output;
  }
};

/*

    Time Complexity : O(N^2), Here Two nested loop creates the time complexity. Where N is the size of the
    array(nums).

    Space Complexity : O(1), Constant space. Extra space is only allocated for the Vector(output), however the
    output does not count towards the space complexity.

    Solved using Array(Two Nested Loop) + Sorting. Optimized Approach.

*/

/***************************************** Approach 3 *****************************************/

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int> &nums)
  {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    vector<vector<int>> output;
    for (int i = 0; i < n - 1; i++)
    {
      int low = i + 1, high = n - 1;
      while (low < high)
      {
        if (nums[i] + nums[low] + nums[high] < 0)
        {
          low++;
        }
        else if (nums[i] + nums[low] + nums[high] > 0)
        {
          high--;
        }
        else
        {
          output.push_back({nums[i], nums[low], nums[high]});
          int tempIndex1 = low, tempIndex2 = high;
          while (low < high && nums[low] == nums[tempIndex1])
            low++;
          while (low < high && nums[high] == nums[tempIndex2])
            high--;
        }
      }
      while (i + 1 < n && nums[i] == nums[i + 1])
        i++;
    }
    return output;
  }
};
```
