# Shortest Common Supersequence

## Table of Contents

- [Shortest Common Supersequence](#shortest-common-supersequence)
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
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The **Shortest Common Supersequence (SCS)** of two given strings is the shortest string that contains both input strings as subsequences. This problem is related to the **Longest Common Subsequence (LCS)** problem, as LCS helps in determining the minimal characters that need to be added to form the SCS.

## Problem Description

Given two strings `s1` and `s2`, find the length of the **smallest string** which has both `s1` and `s2` as subsequences. The strings `s1` and `s2` can contain both uppercase and lowercase English letters.

### Examples

#### Example 1

**Input:**

```cpp
s1 = "geek"
s2 = "eke"
```

**Output:**

```cpp
5
```

**Explanation:**

- The string "geeke" contains both "geek" and "eke" as subsequences.

#### Example 2

**Input:**

```cpp
s1 = "AGGTAB"
s2 = "GXTXAYB"
```

**Output:**

```cpp
9
```

**Explanation:**

- The string "AGXGTXAYB" contains both "AGGTAB" and "GXTXAYB" as subsequences.

#### Example 3

**Input:**

```cpp
s1 = "geek"
s2 = "ek"
```

**Output:**

```cpp
4
```

**Explanation:**

- The string "geek" contains both "geek" and "ek" as subsequences.

### Constraints

- `1 <= s1.size(), s2.size() <= 500`

## Approach

1. Compute the **Longest Common Subsequence (LCS)** of `s1` and `s2` using a space-optimized **dynamic programming** approach.
2. Use the formula:

   \[ \text{SCS Length} = \text{s1.length} + \text{s2.length} - \text{LCS Length} \]

   to determine the shortest common supersequence length.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int tabulation_optimized(int n, int m, string s1, string s2) {
        vector<int> dp(m + 1, 0), current(m + 1, 0);

        // Initialize the DP table with zero values
        for (int j = 0; j <= m; j++)
            dp[j] = 0;

        // Compute LCS using space-optimized DP
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

    // Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string &s1, string &s2) {
        int n = s1.size();
        int m = s2.size();
        int LCS = tabulation_optimized(n, m, s1, s2);
        return n + m - LCS;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(n * m)`, where `n` and `m` are the lengths of `s1` and `s2`, respectively. This is due to the DP table computation.
- **Space Complexity:** `O(m)`, as only two 1D arrays of size `m` are used for optimization instead of a full 2D table.

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
