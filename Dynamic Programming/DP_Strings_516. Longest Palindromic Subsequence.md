# Longest Palindromic Subsequence

## Table of Contents

- [Longest Palindromic Subsequence](#longest-palindromic-subsequence)
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
    - [Explanation](#explanation)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Expected Output](#expected-output)

## Introduction

The problem requires finding the **length of the longest palindromic subsequence** in a given string. A subsequence is a sequence derived by deleting some or no characters while maintaining the order of the remaining characters. A **palindromic subsequence** reads the same forward and backward.

## Problem Description

Given a string `s`, return the length of the **longest palindromic subsequence**.

### Examples

#### Example 1

**Input:**

```cpp
s = "bbbab";
```

**Output:**

```cpp
4
```

**Explanation:**  
One possible longest palindromic subsequence is **"bbbb"** with a length of **4**.

#### Example 2

**Input:**

```cpp
s = "cbbd";
```

**Output:**

```cpp
2
```

**Explanation:**  
One possible longest palindromic subsequence is **"bb"** with a length of **2**.

### Constraints

- `1 <= s.length <= 1000`
- `s` consists only of **lowercase English letters**.

## Approach

The solution employs **Dynamic Programming (DP)** to efficiently compute the length of the longest palindromic subsequence.

1. The problem can be reduced to finding the **Longest Common Subsequence (LCS)** of the string `s` and its **reversed version** `t`.
2. We use **tabulation (1D DP optimization)** to reduce space complexity.
3. We define `dp[i][j]` to store the length of the LCS for `s1[0...i-1]` and `s2[0...j-1]`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized DP approach to find LCS of s and its reverse
    int tabulation_optimized(int n, int m, string s1, string s2) {
        vector<int> dp(m + 1, 0), current(m + 1, 0);

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

    // Function to find longest palindromic subsequence length
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(), t.end());
        return tabulation_optimized(n, n, s, t);
    }
};

// Driver Code
int main() {
    Solution sol;
    string s = "bbbab";
    cout << "Longest Palindromic Subsequence Length: " << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
```

## Complexity Analysis

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Tabulation (1D DP) | `O(n^2)`        | `O(n)`           |

### Explanation

- **Time Complexity:** We iterate through both strings, filling the DP table, which results in `O(n^2)` operations.
- **Space Complexity:**
  - The **optimized approach** reduces space to `O(n)` by using only two 1D arrays instead of a 2D table.

## How to Run the Code

### For C++

1. Copy the provided C++ code into a file, e.g., `main.cpp`.
2. Compile the file using:

   ```sh
   g++ main.cpp -o output
   ```

3. Run the executable:

   ```sh
   ./output
   ```

### Expected Output

```sh
Longest Palindromic Subsequence Length: 4
```
