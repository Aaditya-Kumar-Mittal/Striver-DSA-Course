# Longest Common Subsequence (LCS)

## Table of Contents

- [Longest Common Subsequence (LCS)](#longest-common-subsequence-lcs)
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

---

## Introduction

The Longest Common Subsequence (LCS) problem is a classic problem in computer science and dynamic programming. Given two strings, we aim to find the longest subsequence that appears in both strings in the same order but not necessarily consecutively.

## Problem Description

You are given two strings `s1` and `s2`. Your task is to return the longest common subsequence of these strings. If there is no such subsequence, return an empty string. If multiple subsequences are possible, return any one of them.

### Examples

#### Example 1

**Input:**

```sh
5 6
s1 = "abcab"
s2 = "cbab"
```

**Output:**

```sh
"bab"
```

**Explanation:**
"bab" is a valid LCS that appears in both `s1` and `s2`.

#### Example 2

**Input:**

```sh
3 3
s1 = "xyz"
s2 = "abc"
```

**Output:**

```sh
""
```

**Explanation:**
There is no common subsequence between `s1` and `s2`, so an empty string is returned.

### Constraints

- `1 <= n, m <= 10^3`
- Time Limit: `1 sec`

---

## Approach

The problem is solved using **Dynamic Programming**. We create a 2D DP table where `dp[i][j]` stores the length of the longest common subsequence of `s1[0..i-1]` and `s2[0..j-1]`. The approach follows these steps:

1. Initialize a DP table of size `(n+1) x (m+1)` with all values set to `0`.
2. Fill the DP table based on whether the characters match:
   - If `s1[i-1] == s2[j-1]`, then `dp[i][j] = 1 + dp[i-1][j-1]`.
   - Otherwise, `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
3. Backtrack through the DP table to reconstruct the LCS string.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

string findLCS(int n, int m, string &s1, string &s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct the LCS string
    int len = dp[n][m];
    string ans(len, '$'); // Initialize string with placeholder characters
    int index = len - 1, i = n, j = m;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            ans[index] = s1[i - 1];
            index--, i--, j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    return ans;
}

int main() {
    int n, m;
    string s1, s2;
    cin >> n >> m >> s1 >> s2;
    string result = findLCS(n, m, s1, s2);
    cout << result << endl;
    return 0;
}
```

---

## Complexity Analysis

- **Time Complexity:** `O(n * m)`, where `n` and `m` are the lengths of `s1` and `s2`.
- **Space Complexity:** `O(n * m)` due to the DP table.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `lcs.cpp`.
2. Compile using:

   ```sh
   g++ -o lcs lcs.cpp
   ```

3. Run the executable:

   ```sh
   ./lcs
   ```

4. Provide input as specified, e.g.,:

   ```sh
   5 6
   abcab
   cbab
   ```

5. The output will be:

   ```sh
   bab
   ```
