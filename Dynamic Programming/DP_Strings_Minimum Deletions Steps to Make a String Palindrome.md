# Minimum Number of Deletions to Make a String Palindrome

## Table of Contents

- [Minimum Number of Deletions to Make a String Palindrome](#minimum-number-of-deletions-to-make-a-string-palindrome)
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

The problem requires finding the **minimum number of deletions** needed to make a given string a palindrome. A palindrome is a string that reads the same forward and backward.

## Problem Description

Given a string `str` of length `n`, return the **minimum number of characters** that need to be removed to make `str` a palindrome.

### Examples

#### Example 1

**Input:**

```cpp
n = 7, str = "aebcbda";
```

**Output:**

```cpp
2
```

**Explanation:**  
Removing 'e' and 'd' results in "abcba", which is a palindrome.

#### Example 2

**Input:**

```cpp
n = 3, str = "aba";
```

**Output:**

```cpp
0
```

**Explanation:**  
The string "aba" is already a palindrome.

### Constraints

- `1 ≤ |str| ≤ 10^3`

## Approach

The problem can be solved using **Dynamic Programming (DP)**:

1. Compute the **Longest Palindromic Subsequence (LPS)** of `str`.
2. The **minimum deletions** required = `length of str - LPS length`.
3. The **LPS** is found by computing the **Longest Common Subsequence (LCS)** of `str` and its **reversed version** `t`.

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

    // Function to find minimum deletions to make a palindrome
    int minDeletions(string s, int n) {
        string t = s;
        reverse(t.begin(), t.end());
        return n - tabulation_optimized(n, n, s, t);
    }
};

// Driver Code
int main() {
    Solution sol;
    string s = "aebcbda";
    cout << "Minimum Deletions to Make Palindrome: " << sol.minDeletions(s, s.size()) << endl;
    return 0;
}
```

## Complexity Analysis

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Tabulation (1D DP) | `O(n^2)`        | `O(n)`           |

### Explanation

- **Time Complexity:** `O(n^2)`, as we compute LCS of `s` and `t`.
- **Space Complexity:** `O(n)`, due to the optimized DP approach storing only two arrays.

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
Minimum Deletions to Make Palindrome: 2
```

This confirms that the implementation correctly computes the minimum deletions needed to make the given string a palindrome.
