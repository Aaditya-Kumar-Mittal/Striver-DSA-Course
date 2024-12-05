# Jump Game II - Comprehensive Solutions

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Jump Game II - Comprehensive Solutions](#jump-game-ii---comprehensive-solutions)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Constraints](#constraints)
  - [Approaches](#approaches)
    - [Solution - I (Brute Force) (Rejected)](#solution---i-brute-force-rejected)
      - [Code](#code)
      - [Time Complexity](#time-complexity)
    - [Solution - II (Recursive Dynamic Programming - Memoization)](#solution---ii-recursive-dynamic-programming---memoization)
      - [Code](#code-1)
      - [Time Complexity](#time-complexity-1)
    - [Solution - III (Iterative Dynamic Programming - Tabulation)](#solution---iii-iterative-dynamic-programming---tabulation)
      - [Code](#code-2)
      - [Time Complexity](#time-complexity-2)
    - [Solution - IV (Greedy BFS)](#solution---iv-greedy-bfs)
      - [Code](#code-3)
      - [Time Complexity](#time-complexity-3)
  - [Complexity Analysis](#complexity-analysis)

---

## Introduction

The **Jump Game II** problem is about finding the minimum number of jumps required to reach the last index of an array. Each array element represents the maximum number of steps you can jump forward. Various methods like brute force, dynamic programming, and greedy techniques can be used to solve this problem.

---

## Problem Description

You are given a **0-indexed** array `nums` of length `n`. You are initially positioned at `nums[0]`. Each element `nums[i]` represents the maximum length of a forward jump from index `i`. Return the minimum number of jumps to reach the last index.

### Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- It is guaranteed that you can reach `nums[n - 1]`.

---

## Approaches

### Solution - I (Brute Force) (Rejected)

This approach explores all possible paths from the current index. At each step, it recursively calculates the minimum jumps required to reach the end.

#### Code

```cpp
int jump(vector<int>& nums, int pos = 0) {
    if (pos >= nums.size() - 1) return 0;

    int minJumps = 10001; // Initialize to maximum possible jumps + 1
    for (int j = 1; j <= nums[pos]; j++) // Explore all jump sizes
        minJumps = min(minJumps, 1 + jump(nums, pos + j));

    return minJumps;
}
```

#### Time Complexity

- **O(N!)**: At each index, we recursively explore all possible jump sizes.
- **Space Complexity**: **O(N)** due to recursion stack.

---

### Solution - II (Recursive Dynamic Programming - Memoization)

This improves the brute force approach by storing the results of already computed subproblems in a `dp` array, avoiding redundant calculations.

#### Code

```cpp
int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), 10001); // Initialize all to max possible jumps + 1
    return solve(nums, dp, 0);
}

int solve(vector<int>& nums, vector<int>& dp, int pos) {
    if (pos >= nums.size() - 1) return 0; // Reached the end
    if (dp[pos] != 10001) return dp[pos]; // Return precomputed result

    for (int j = 1; j <= nums[pos]; j++)
        dp[pos] = min(dp[pos], 1 + solve(nums, dp, pos + j));

    return dp[pos];
}
```

#### Time Complexity

- **O(N²)**: For each position, all possible jump lengths are explored.
- **Space Complexity**: **O(N)** for the `dp` array and recursion stack.

---

### Solution - III (Iterative Dynamic Programming - Tabulation)

This approach uses a bottom-up method to calculate the minimum jumps required for each position iteratively.

#### Code

```cpp
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 10001);
    dp[n - 1] = 0; // No jumps needed if already at the last index

    for (int i = n - 2; i >= 0; i--) {
        for (int jumpLen = 1; jumpLen <= nums[i]; jumpLen++)
            dp[i] = min(dp[i], 1 + dp[min(n - 1, i + jumpLen)]); // Handle bounds
    }

    return dp[0];
}
```

#### Time Complexity

- **O(N²)**: Double loop where each index explores possible jumps.
- **Space Complexity**: **O(N)** for the `dp` array.

---

### Solution - IV (Greedy BFS)

This method keeps track of the maximum reachable index at each level (`maxReachable`) and updates the minimum jumps required when moving to the next level.

#### Code

```cpp
int jump(vector<int>& nums) {
    int n = nums.size(), i = 0, maxReachable = 0, lastJumpedPos = 0, jumps = 0;

    while (lastJumpedPos < n - 1) {
        maxReachable = max(maxReachable, i + nums[i]); // Furthest reachable index
        if (i == lastJumpedPos) { // Finished exploring the current level
            lastJumpedPos = maxReachable; // Move to the next level
            jumps++; // Increment jump count
        }
        i++;
    }

    return jumps;
}
```

#### Time Complexity

- **O(N)**: Each index is visited once.
- **Space Complexity**: **O(1)** as no extra space is used.

---

## Complexity Analysis

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Brute Force                | O(N!)           | O(N)             |
| Recursive DP (Memoization) | O(N²)           | O(N)             |
| Iterative DP (Tabulation)  | O(N²)           | O(N)             |
| Greedy BFS                 | O(N)            | O(1)             |

---

This comprehensive breakdown showcases the evolution of solutions, from inefficient brute force to optimal greedy algorithms. Each method balances trade-offs between complexity and resource usage.
