# Longest Common Subsequence

## Table of Contents

- [Longest Common Subsequence](#longest-common-subsequence)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
  - [Tabulation Approach Optimized](#tabulation-approach-optimized)
    - [Main Function](#main-function)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [My Leetcode Submission](#my-leetcode-submission)

## Introduction

The **Longest Common Subsequence (LCS)** problem is a fundamental problem in computer science and dynamic programming. Given two strings, the goal is to find the length of the longest subsequence that appears in both strings in the same relative order.

## Problem Description

Given two strings `text1` and `text2`, return the length of their longest common subsequence. If there is no common subsequence, return `0`.

A **subsequence** of a string is a new string generated from the original string by deleting some characters (or none) without changing the relative order of the remaining characters.

A **common subsequence** of two strings is a subsequence that appears in both strings.

### Examples

#### Example 1

**Input:**

```cpp
text1 = "abcde", text2 = "ace"
```

**Output:**

```cpp
3
```

**Explanation:** The longest common subsequence is "ace" with length `3`.

#### Example 2

**Input:**

```cpp
text1 = "abc", text2 = "abc"
```

**Output:**

```cpp
3
```

**Explanation:** The longest common subsequence is "abc" with length `3`.

#### Example 3

**Input:**

```cpp
text1 = "abc", text2 = "def"
```

**Output:**

```cpp
0
```

**Explanation:** There is no common subsequence, so the result is `0`.

### Constraints

- `1 <= text1.length, text2.length <= 1000`
- `text1` and `text2` consist of only lowercase English characters.

## Approach

There are three common approaches to solving the **Longest Common Subsequence** problem:

1. **Recursive Approach** - Using a brute-force method.
2. **Memoization Approach** - Optimizing recursion with caching.
3. **Tabulation Approach** - Using a bottom-up dynamic programming table.

## Detailed Explanation of Code

### Recursive Approach

This approach recursively computes LCS by checking:

1. If the last characters match, include them in the LCS and move to the previous characters in both strings.
2. If they don’t match, consider both possibilities (excluding one character at a time) and take the maximum.

```cpp
int recursive_solution(int i, int j, string s1, string s2) {
    if (i < 0 || j < 0)
        return 0;
    if (s1[i] == s2[j])
        return 1 + recursive_solution(i - 1, j - 1, s1, s2);
    return max(recursive_solution(i, j - 1, s1, s2),
               recursive_solution(i - 1, j, s1, s2));
}
```

### Memoization Approach

This is an optimized version of recursion using a **2D DP table** to store previously computed values and avoid redundant computations.

```cpp
int memoization(int i, int j, string s1, string s2, vector<vector<int>>& dp) {
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i] == s2[j])
        return dp[i][j] = 1 + memoization(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = max(memoization(i, j - 1, s1, s2, dp),
                          memoization(i - 1, j, s1, s2, dp));
}
```

### Tabulation Approach

A bottom-up dynamic programming solution that iteratively fills up a **2D DP table**.

```cpp
int tabulation(int n, int m, string s1, string s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}
```

## Tabulation Approach Optimized

This approach is an optimized version of the tabulation approach using 2 **1D arrays** instead of a **2D DP table**.

```cpp
int tabulation_optimized(int n, int m, string s1, string s2) {
        vector<int> dp(m + 1, 0), current(m + 1, 0);
        for (int j = 0; j <= m; j++)
            dp[j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    current[j] = 1 + dp[j - 1];
                else
                    current[j] = max(dp[j], current[j - 1]);
            }
            dp = current;
        }

        return dp[m];
    }
```

### Main Function

```cpp
int longestCommonSubsequence(string text1, string text2) {
    int n1 = text1.size();
    int n2 = text2.size();
    return tabulation(n1, n2, text1, text2);
}
```

## Complexity Analysis

| Approach        | Time Complexity | Space Complexity     |
| --------------- | --------------- | -------------------- |
| Recursive       | `O(2^N)`        | `O(N)` (stack calls) |
| Memoization     | `O(N*M)`        | `O(N*M) + O(N+M)`    |
| Tabulation      | `O(N*M)`        | `O(N*M)`             |
| Space Optimized | `O(N*M)`        | `O(M)`               |

## How to Run the Code

### For C++

1. Copy the code into a C++ file, e.g., `lcs.cpp`.
2. Compile using:

   ```~~~~
   g++ lcs.cpp -o lcs
   ```

3. Run the program:

   ```sh
   ./lcs
   ```

## Other Solutions

### My Leetcode Submission

```cpp
class Solution {
public:
    int recursive_solution(int i, int j, string s1, string s2) {
        if (i < 0 || j < 0)
            return 0;

        if (s1[i] == s2[j])
            return 1 + recursive_solution(i - 1, j - 1, s1, s2);
        return max(recursive_solution(i, j - 1, s1, s2),
                   recursive_solution(i - 1, j, s1, s2));
    }

    int memoization(int i, int j, string s1, string s2,
                    vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i] == s2[j])
            return dp[i][j] = 1 + memoization(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = max(memoization(i, j - 1, s1, s2, dp),
                              memoization(i - 1, j, s1, s2, dp));
    }

    int recursive_solution_index_shifted(int i, int j, string s1, string s2) {

        // call -> recursive_solution_index_shifted(n, m, text1, text2);

        if (i == 0 || j == 0)
            return 0;

        if (s1[i - 1] == s2[j - 1])
            return 1 + recursive_solution_index_shifted(i - 1, j - 1, s1, s2);
        return max(recursive_solution_index_shifted(i, j - 1, s1, s2),
                   recursive_solution_index_shifted(i - 1, j, s1, s2));
    }

    int memoization_index_shifted(int i, int j, string s1, string s2,
                                  vector<vector<int>>& dp) {
        if (i == 0 || j == 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s1[i - 1] == s2[j - 1])
            return dp[i][j] =
                       1 + memoization_index_shifted(i - 1, j - 1, s1, s2, dp);
        return dp[i][j] = max(memoization_index_shifted(i, j - 1, s1, s2, dp),
                              memoization_index_shifted(i - 1, j, s1, s2, dp));
    }

    int tabulation(int n, int m, string s1, string s2) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int j = 0; j <= m; j++)
            dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }

    int tabulation_optimized(int n, int m, string s1, string s2) {
        vector<int> dp(m + 1, 0), current(m + 1, 0);
        for (int j = 0; j <= m; j++)
            dp[j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    current[j] = 1 + dp[j - 1];
                else
                    current[j] = max(dp[j], current[j - 1]);
            }
            dp = current;
        }

        return dp[m];
    }

    int longestCommonSubsequence(string text1, string text2) {

        int n1 = text1.size();
        int n2 = text2.size();

        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return recursive_solution_index_shifted(n1, n2, text1, text2);
        // vector<vector<int>> dp1(n1 + 1, vector<int>(n2 + 1, -1));
        // return memoization_index_shifted(n1, n2, text1, text2, dp1);
        return tabulation_optimized(n1, n2, text1, text2);
    }
};
```
