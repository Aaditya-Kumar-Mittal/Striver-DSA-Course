# Distinct Subsequences

## Table of Contents

- [Distinct Subsequences](#distinct-subsequences)
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
    - [My Submission](#my-submission)

## Introduction

The **Distinct Subsequences** problem requires determining the number of distinct ways to form string `t` as a subsequence of string `s`. The solution must fit within a **32-bit signed integer**.

## Problem Description

Given two strings `s` and `t`, return the number of distinct subsequences of `s` that equal `t`.

### Examples

#### Example 1

**Input:**

```cpp
s = "rabbbit"
t = "rabbit"
```

**Output:**

```cpp
3
```

**Explanation:**
There are three ways to generate "rabbit" from "rabbbit":

- rabbbit
- rabbbit
- rabbbit

#### Example 2

**Input:**

```cpp
s = "babgbag"
t = "bag"
```

**Output:**

```cpp
5
```

**Explanation:**
There are five ways to generate "bag" from "babgbag":

- babgbag
- babgbag
- babgbag
- babgbag
- babgbag

### Constraints

- `1 <= s.length, t.length <= 1000`
- `s` and `t` consist of English letters.

## Approach

1. **Recursive Approach:** Recursively check all subsequences of `s` that match `t`.
2. **Memoization:** Optimize recursion by storing computed results in a DP table.
3. **Tabulation:** Construct a DP table iteratively to store results.
4. **Space Optimization:** Reduce space complexity by using a 1D DP array.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int recursive_solution(int i, int j, string s, string t) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (s[i] == t[j]) {
            return recursive_solution(i - 1, j - 1, s, t) + recursive_solution(i - 1, j, s, t);
        } else {
            return recursive_solution(i - 1, j, s, t);
        }
    }

    int memoization(int i, int j, string s, string t, vector<vector<int>> &dp) {
        if (j < 0) return 1;
        if (i < 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = memoization(i - 1, j - 1, s, t, dp) + memoization(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = memoization(i - 1, j, s, t, dp);
        }
    }

    int tabulation(int n, int m, string s, string t) {
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int j = 1; j <= m; j++) dp[0][j] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][m];
    }

    int tabulation_optimized_better(int n, int m, string s, string t) {
        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }
        }
        return dp[m];
    }

    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return tabulation_optimized_better(n, m, s, t);
    }
};
```

## Complexity Analysis

- **Recursive Approach:** `O(2^n)`, exponential time complexity due to recursive calls.
- **Memoization:** `O(n * m)`, reduces redundant computations.
- **Tabulation:** `O(n * m)`, dynamic programming table fills efficiently.
- **Optimized Tabulation:** `O(n * m)`, with space complexity reduced to `O(m)`.

| Approach             | Time Complexity | Space Complexity |
| -------------------- | --------------- | ---------------- |
| Recursive Approach   | `O(2^n)`        | `O(n + m)`       |
| Memoization          | `O(n * m)`      | `O(n * m)`       |
| Tabulation           | `O(n * m)`      | `O(n * m)`       |
| Optimized Tabulation | `O(n * m)`      | `O(m)`           |

## How to Run the Code

### For C++

1. Save the implementation in a `.cpp` file (e.g., `distinct_subsequences.cpp`).
2. Compile using:

   ```sh
   g++ distinct_subsequences.cpp -o distinct_subsequences
   ```

3. Run the executable:

   ```sh
   ./distinct_subsequences
   ```

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    int recursive_solution(int i, int j, string s, string t) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (s[i] == t[j]) {
            return recursive_solution(i - 1, j - 1, s, t) +
                   recursive_solution(i - 1, j, s, t);
        } else {
            return recursive_solution(i - 1, j, s, t);
        }
    }

    int memoization(int i, int j, string s, string t, vector<vector<int>> dp) {
        if (j < 0)
            return 1;
        if (i < 0)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = memoization(i - 1, j - 1, s, t, dp) +
                              memoization(i - 1, j, s, t, dp);
        } else {
            return dp[i][j] = memoization(i - 1, j, s, t, dp);
        }
    }

    int tabulation(int n, int m, string s, string t) {
        // Create a DP table of size (n+1) x (m+1)
        vector<vector<unsigned long long>> dp(
            n + 1, vector<unsigned long long>(m + 1, 0));

        // Base case: If t is empty, there is exactly one subsequence (delete
        // all characters of s)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Base case: If s is empty and t is not empty, no subsequences can be
        // formed
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;
        }

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    // If characters match, add the two possibilities:
                    // 1. Use s[i-1] and t[j-1] (dp[i-1][j-1])
                    // 2. Do not use s[i-1] (dp[i-1][j])
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    // If characters do not match, carry over the result from
                    // s[0..i-1]
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        // The answer is in dp[n][m]
        return dp[n][m];
    }

    int tabulation_optimized(int n, int m, string s, string t) {
        // Create a DP table of size (m+1)
        vector<unsigned long long> dp(m + 1, 0), current(m + 1, 0);

        dp[0] = current[0] = 1;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    current[j] = dp[j - 1] + dp[j];
                } else {
                    current[j] = dp[j];
                }
            }
            dp = current;
        }

        // The answer is in dp[n][m]
        return dp[m];
    }

    int tabulation_optimized_better(int n, int m, string s, string t) {
        // Create a DP table of size (m+1)
        vector<unsigned long long> dp(m + 1, 0);

        dp[0] = 1;

        // Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j - 1] + dp[j];
                } else {
                    dp[j] = dp[j];
                }
            }
        }

        // The answer is in dp[n][m]
        return dp[m];
    }

    int numDistinct(string s, string t) {

        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return tabulation_optimized_better(n, m, s, t);
    }
};
```
