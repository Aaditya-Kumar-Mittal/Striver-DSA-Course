# Shortest Common Supersequence

## Table of Contents

- [Shortest Common Supersequence](#shortest-common-supersequence)
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

## Introduction

The **Shortest Common Supersequence (SCS)** of two given strings is the shortest string that contains both input strings as subsequences. The problem is closely related to the **Longest Common Subsequence (LCS)** problem.

## Problem Description

Given two strings `str1` and `str2`, return the shortest string that has both `str1` and `str2` as subsequences. If there are multiple valid strings, return any of them.

### Examples

#### Example 1

**Input:**

```cpp
str1 = "abac"
str2 = "cab"
```

**Output:**

```cpp
"cabac"
```

**Explanation:**

- `str1 = "abac"` is a subsequence of "cabac" (by deleting the first 'c').
- `str2 = "cab"` is a subsequence of "cabac" (by deleting the last "ac").

#### Example 2

**Input:**

```cpp
str1 = "aaaaaaaa"
str2 = "aaaaaaaa"
```

**Output:**

```cpp
"aaaaaaaa"
```

### Constraints

- `1 <= str1.length, str2.length <= 1000`
- `str1` and `str2` consist of lowercase English letters.

## Approach

1. Compute the **Longest Common Subsequence (LCS)** of `str1` and `str2` using Dynamic Programming.
2. Use the LCS to construct the Shortest Common Supersequence:
   - Traverse both strings from the end towards the start.
   - Include characters from both strings while preserving order.
   - If a common character is found, include it only once.
   - Add any remaining characters from both strings.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill DP table for LCS calculation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        // Construct the shortest common supersequence
        int i = n, j = m;
        string ans = "";

        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                ans += str1[i - 1];
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                ans += str1[i - 1];
                i--;
            } else {
                ans += str2[j - 1];
                j--;
            }
        }

        // Add remaining characters
        while (i > 0) {
            ans += str1[i - 1];
            i--;
        }

        while (j > 0) {
            ans += str2[j - 1];
            j--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n * m)`, where `n` and `m` are the lengths of `str1` and `str2`, respectively. This is due to the DP table computation and backtracking to construct the result.
- **Space Complexity:** `O(n * m)`, as we use a 2D `dp` array for storing intermediate results.

## How to Run the Code

### For C++

1. Save the implementation in a `.cpp` file (e.g., `scs.cpp`).
2. Compile using:

   ```sh
   g++ scs.cpp -o scs
   ```

3. Run the executable:

   ```sh
   ./scs
   ```
