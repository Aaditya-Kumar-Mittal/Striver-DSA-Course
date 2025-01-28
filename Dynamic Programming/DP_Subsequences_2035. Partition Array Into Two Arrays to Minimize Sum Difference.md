# Partition Array Into Two Arrays to Minimize Sum Difference

## Table of Contents

- [Partition Array Into Two Arrays to Minimize Sum Difference](#partition-array-into-two-arrays-to-minimize-sum-difference)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [High Level Approach](#high-level-approach)
    - [Detailed Approach](#detailed-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Code Explanation](#code-explanation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2](#solution---2)
      - [1. Reason Why Tabulation Failed](#1-reason-why-tabulation-failed)
      - [2. Meet In The Middle Approach](#2-meet-in-the-middle-approach)
      - [Explanation of `int b = (totalSum - 2*a) / 2`](#explanation-of-int-b--totalsum---2a--2)
      - [Code Implementation](#code-implementation)
      - [Why Not Time Limit Exceeded (TLE)?](#why-not-time-limit-exceeded-tle)

## Introduction

The problem at hand involves partitioning an array of size \( 2n \) into two arrays, each of size \( n \), in such a way that the absolute difference between the sums of the two arrays is minimized. This is a variation of the well-known "Partition Problem," which is solved using a "Meet in the Middle" technique.

## Problem Description

You are given an integer array `nums` of size \( 2n \), and you need to partition it into two arrays of size \( n \) such that the absolute difference of their sums is minimized.

### Examples

**Example 1:**

Input:

```bash
nums = [3, 9, 7, 3]
```

Output:

```bash
2
```

Explanation: One optimal partition is: [3, 9] and [7, 3]. The absolute difference between the sums of the arrays is \( |(3 + 9) - (7 + 3)| = 2 \).

---

**Example 2:**

Input:

```bash
nums = [-36, 36]
```

Output:

```bash
72
```

Explanation: One optimal partition is: [-36] and [36]. The absolute difference between the sums of the arrays is \( |-36 - 36| = 72 \).

---

**Example 3:**

Input:

```bash
nums = [2, -1, 0, 4, -2, -9]
```

Output:

```bash
0
```

Explanation: One optimal partition is: [2, 4, -9] and [-1, 0, -2]. The absolute difference between the sums of the arrays is \( |(2 + 4 + -9) - (-1 + 0 + -2)| = 0 \).

### Constraints

- \( 1 \leq n \leq 15 \)
- \( \text{nums.length} = 2n \)
- \( -10^7 \leq \text{nums[i]} \leq 10^7 \)

## Approach

### High Level Approach

1. **Divide the Array**: Split the original array into two parts of size \( n \), called the LeftPart and RightPart.
2. **Enumerate Subsets**: For each part, compute all possible subset sums.
3. **Minimize Absolute Difference**: For each possible subset size \( sz \) from the LeftPart, find the corresponding subset from the RightPart such that the absolute difference in sums is minimized.
4. **Use Meet in the Middle**: This method ensures that the solution space remains manageable even for larger \( n \).

### Detailed Approach

- Split the array into two equal parts: LeftPart (`nums[0]` to `nums[n-1]`) and RightPart (`nums[n]` to `nums[2n-1]`).
- For each part, calculate all possible subset sums, grouped by the size of the subset.
- Sort the subset sums of the RightPart.
- For each subset sum \( a \) in the LeftPart, use binary search to find a complementary subset sum \( b \) in the RightPart that minimizes the absolute difference between the sums.
- Return the minimum possible absolute difference.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);

        int N = n / 2;
        vector<vector<int>> left(N + 1), right(N + 1);

        // Store all possible sums in left and right parts
        for (int mask = 0; mask < (1 << N); ++mask) {
            int sz = 0, l = 0, r = 0;
            for (int i = 0; i < N; ++i) {
                if (mask & (1 << i)) {
                    sz++;
                    l += nums[i];
                    r += nums[i + N];
                }
            }
            left[sz].push_back(l);
            right[sz].push_back(r);
        }

        // Sort right part sums
        for (int sz = 0; sz <= N; ++sz) {
            sort(right[sz].begin(), right[sz].end());
        }

        // Initialize the result with the difference when all elements are on one side
        res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        // Iterate over left part
        for (int sz = 1; sz < N; ++sz) {
            for (auto &a : left[sz]) {
                int b = (sum - 2 * a) / 2, rsz = N - sz;
                auto &v = right[rsz];
                auto itr = lower_bound(v.begin(), v.end(), b); // Binary search over right part

                if (itr != v.end()) {
                    res = min(res, abs(sum - 2 * (a + (*itr))));
                }
                if (itr != v.begin()) {
                    auto it = itr; --it;
                    res = min(res, abs(sum - 2 * (a + (*it))));
                }
            }
        }

        return res;
    }
};
```

### Code Explanation

1. **Initialization**:
   - Calculate the total sum of the input array.
   - Split the array into two parts (LeftPart and RightPart).
2. **Subset Sum Computation**:
   - Use bit masking to compute all possible subsets for both parts of the array.
   - For each subset, calculate the sum and store it in the respective part (LeftPart or RightPart).
3. **Optimization**:
   - Sort the RightPart subset sums for binary search optimization.
4. **Minimization**:
   - For each subset sum from the LeftPart, use binary search to find the best matching sum from the RightPart that minimizes the absolute difference between the sums of the two partitions.

## Complexity Analysis

### Time Complexity

- **Subset Sum Calculation**: Generating all subsets for each part has a time complexity of \( O(2^{N}) \), where \( N \) is the half-length of the input array.
- **Binary Search**: For each subset sum from the LeftPart, binary search in the RightPart takes \( O(\log(2^N)) \).
- Overall time complexity: \( O(2^N \cdot \log(2^N)) \), which is efficient given the constraint \( N \leq 15 \).

### Space Complexity

- The space complexity is \( O(2^N) \) due to the storage required for all possible subset sums in both parts.

## How to Run the Code

### For C++

1. **Set up the environment**:
   - Install a C++ compiler like GCC or use an IDE like Visual Studio or CLion.
2. **Compilation**:

   - Save the code in a `.cpp` file.
   - Use the following command to compile the code:

     ```bash
     g++ -o solution solution.cpp
     ```

3. **Execution**:

   - Run the program with:

     ```bash
     ./solution
     ```

   - Provide the input array to the program to test the solution.

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    vector<vector<int>> solve(vector<int>& arr) {
        int size = arr.size();
        vector<vector<int>> subsetSums(size + 1);
        subsetSums[0].push_back(0);

        for (int num : arr) {
            for (int i = size - 1; i >= 0; --i) {
                for (int sum : subsetSums[i]) {
                    subsetSums[i + 1].push_back(sum + num);
                }
            }
        }
        return subsetSums;
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());

        auto leftSums = solve(left);
        auto rightSums =solve(right);

        for (auto& sums : rightSums) {
            sort(sums.begin(), sums.end());
        }

        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int target = totalSum / 2;
        int minDiff = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            for (int leftSum : leftSums[i]) {
                int required = target - leftSum;
                auto& rightSubset = rightSums[n - i];
                auto it = lower_bound(rightSubset.begin(), rightSubset.end(), required);

                if (it != rightSubset.end()) {
                    int sum1 = leftSum + *it;
                    int sum2 = totalSum - sum1;
                    minDiff = min(minDiff, abs(sum1 - sum2));
                }
                if (it != rightSubset.begin()) {
                    it--;
                    int sum1 = leftSum + *it;
                    int sum2 = totalSum - sum1;
                    minDiff = min(minDiff, abs(sum1 - sum2));
                }
            }
        }

        return minDiff;
    }
};
```

### Solution - 2

**NOTE**: There's a problem in this i.e it will work only for positive integers (i.e. all values in the given array must be positive).

#### 1. Reason Why Tabulation Failed

As we encounter negative elements in the given array, there's a possibility that our total sum or range becomes negative. Once our range becomes negative, the tabulation method fails because it is impossible to create a 2D matrix of size less than 0 (i.e., negative). Another issue arises when our sum or range becomes 0—this too makes it impossible to create the 2D matrix. Therefore, the tabulation approach is not viable in such cases. We will follow another approach known as **Meet in the Middle**.

#### 2. Meet In The Middle Approach

Let's explain the approach with an example.

Here, the simple and effective strategy is to divide the array into two parts. As it is given that the array has an even length, we will have two equally sized partitions (of size `n/2`, where `n` is the size of the original array). Then, we find all the possible subset sums in both arrays—left and right. While calculating the subset sum of both the left and right arrays, we must also account for the number of elements used when calculating each sum.

We can store the sum and number of elements used in **MAP** or **2D vector**, depending on our requirement. In this case, we use a vector because it provides easier access to values.

For example, for an array `arr[] = [3, 9, 7, 3]`, after dividing it into two partitions:

- Left array: `[3, 9]`
- Right array: `[7, 3]`

The subset sum with the number of elements used would be as follows:

| Number of Elements | Left Array Subset Sum | Right Array Subset Sum |
| ------------------ | --------------------- | ---------------------- |
| 0                  | 0                     | 0                      |
| 1                  | 3, 9                  | 7, 3                   |
| 2                  | 12                    | 10                     |

Now, we iterate through the left array and try to find the nearest possible value in the right array that minimizes the difference between the sums.

To find the best match in the right array, we first sort it and use **binary search** to find the closest value. The goal is to make the left subset sum as close as possible to half of the total sum of the array.

For example, if we take 1 element from the left array (sum = `left_sums[1]`), we need to add an amount to get closer to `half = total / 2`. This required sum will be `required_sum = half - left_sum[1]`. We will binary search for this value in the right array.

The result will be the sum of the value found in the right array and the current value in the left array.

#### Explanation of `int b = (totalSum - 2*a) / 2`

Let `T = totalSum`. We want to minimize `abs(sum2 - sum1)`. Since `sum2 = T - sum1`, we can rewrite this as `abs(T - 2*sum1)`.

To minimize `abs(T - 2*sum1)`, the ideal case would be when `2*sum1 = T`. Thus, `sum1 = a + b`, where `a` comes from the left array. We can derive the value of `b` as:

```bash
2 * (a + b) = T
=> b = (T - 2*a) / 2
```

This clarifies the objective and helps us find the solution.

#### Code Implementation

```cpp
class Solution {
    public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        sum = accumulate(nums.begin(), nums.end(), 0);  // Find the total sum of the array

        int N = n / 2; // Divide the array into two equal parts as the length is even
        vector<vector<int>> left(N + 1), right(N + 1); // Left and right arrays

        // Generate and store all possible sums in the left and right parts using bit-masking
        for(int mask = 0; mask < (1 << N); ++mask) {  // 1 << N is equivalent to 2^N
            int idx = 0, l_sum = 0, r_sum = 0;
            for(int i = 0; i < N; ++i) {
                if(mask & (1 << i)) {  // Check if the bit is set
                    idx++;
                    l_sum += nums[i];
                    r_sum += nums[i + N];
                }
            }
            left[idx].push_back(l_sum);  // Store the sum in the left vector
            right[idx].push_back(r_sum); // Store the sum in the right vector
        }

        // Sort the right array to enable binary search
        for(int idx = 0; idx <= N; ++idx) {
            sort(right[idx].begin(), right[idx].end());
        }

        // Calculate the minimum result from the maximum sums of both arrays
        int res = min(abs(sum - 2 * left[N][0]), abs(sum - 2 * right[N][0]));

        // Iterate over the left array
        for(int idx = 1; idx < N; ++idx) {
            for(auto &a : left[idx]) {  // Check the sum at each position
                int b = (sum - 2 * a) / 2;  // Find the value to minimize
                int rightidx = N - idx; // Find the corresponding value in the right array
                auto &v = right[rightidx]; // Store the vector at the right number position
                auto itr = lower_bound(v.begin(), v.end(), b); // Binary search on the right part

                if(itr != v.end()) {
                    res = min(res, abs(sum - 2 * (a + (*itr)))); // Update the result if a closer sum is found
                }
            }
        }
        return res;
    }
};
```

#### Why Not Time Limit Exceeded (TLE)?

This works because we are generating all possible subset sums using only `k` elements, where `k` ranges from 1 to `N`. This results in a total of `2^k` possible sums. Since the maximum value of `k` is 15, we are handling `2^15 = 32,000` combinations, which is feasible.

However, if we tried to make all subset sums with the entire array (i.e., `2^N` where `N = 30`), we would end up with `2^30 = 1,073,741,824` possible subsets, which would definitely result in a Time Limit Exceeded (TLE) error. Therefore, by dividing the array and reducing the number of subsets we need to calculate, we avoid TLE.
