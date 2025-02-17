# Palindrome Partitioning II

## Table of Contents

- [Palindrome Partitioning II](#palindrome-partitioning-ii)
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
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
    - [Solution - 2](#solution---2)

## Introduction

The problem requires partitioning a given string `s` such that every substring in the partition is a palindrome. The objective is to return the minimum number of cuts needed to achieve this partitioning.

## Problem Description

Given a string `s`, partition `s` so that every substring of the partition is a palindrome. Return the minimum cuts needed for a palindrome partitioning of `s`.

### Examples

#### Example 1

**Input:**

```cpp
s = "aab"
```

**Output:**

```cpp
1
```

**Explanation:** The palindrome partitioning `["aa", "b"]` could be produced using `1` cut.

#### Example 2

**Input:**

```cpp
s = "a"
```

**Output:**

```cpp
0
```

#### Example 3

**Input:**

```cpp
s = "ab"
```

**Output:**

```cpp
1
```

### Constraints

- `1 <= s.length <= 2000`
- `s` consists of lowercase English letters only.

## Approach

The problem can be solved using **Dynamic Programming (DP)**:

1. **Recursive Approach**: Try all possible partitions recursively and count the minimum cuts needed.
2. **Memoization (Top-Down DP)**: Store previously computed results to avoid recomputation.
3. **Tabulation (Bottom-Up DP)**: Build a DP table iteratively to compute the minimum cuts efficiently.
4. **Palindrome Check**: Use a helper function to check if a given substring is a palindrome.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Function to check if a substring is a palindrome
    bool isPalindrome(int i, int j, string& str) {
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    // Memoization approach
    int memoization(int index, int n, string& str, vector<int>& dp) {
        if (index == n)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int minCost = INT_MAX;
        for (int i = index; i < n; i++) {
            if (isPalindrome(index, i, str)) {
                int cost = 1 + memoization(i + 1, n, str, dp);
                minCost = min(minCost, cost);
            }
        }
        return dp[index] = minCost;
    }

    // Tabulation approach
    int tabulation(int n, string& str) {
        vector<int> dp(n + 1, 0);
        for (int index = n - 1; index >= 0; index--) {
            int minCost = INT_MAX;
            for (int i = index; i < n; i++) {
                if (isPalindrome(index, i, str)) {
                    int cost = 1 + dp[i + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[index] = minCost;
        }
        return dp[0] - 1;
    }

    // Main function to return the minimum cuts required
    int minCut(string s) {
        int n = s.size();
        return tabulation(n, s);
    }
};
```

## Complexity Analysis

- **Recursive Approach:** `O(2^n)` (Exponential) due to repeated calculations.
- **Memoization Approach:** `O(n^2)` (Polynomial) since we store results to avoid recomputation.
- **Tabulation Approach:** `O(n^2)` for filling the DP table and `O(n^2)` for checking palindromes.
- **Overall Time Complexity:** `O(n^2)`.
- **Space Complexity:** `O(n)`, as we use a `dp` array of size `n`.

## How to Run the Code

### For C++

1. Copy the provided C++ code into a file, e.g., `solution.cpp`.
2. Compile the code using:

   ```sh
   g++ solution.cpp -o solution
   ```

3. Run the executable:

   ```sh
   ./solution
   ```

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    bool isPalindrome(int i, int j, string& str) {
        while (i < j) {
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int memoization(int index, int n, string& str, vector<int>& dp) {
        if (index == n)
            return 0;
        if (dp[index] != -1)
            return dp[index];
        int minCost = INT_MAX;

        for (int i = index; i < n; i++) {
            if (isPalindrome(index, i, str)) {
                int cost = 1 + memoization(i + 1, n, str, dp);
                minCost = min(minCost, cost);
            }
        }

        return dp[index] = minCost;
    }

    int recursive_solution(int index, int n, string& str) {
        if (index == n)
            return 0;

        int minCost = INT_MAX;

        for (int i = index; i < n; i++) {
            if (isPalindrome(index, i, str)) {
                int cost = 1 + recursive_solution(i + 1, n, str);
                minCost = min(minCost, cost);
            }
        }

        return minCost;
    }

    int tabulation(int n, string& str) {
        vector<int> dp(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            int minCost = INT_MAX;

            for (int i = index; i < n; i++) {
                if (isPalindrome(index, i, str)) {
                    int cost = 1 + dp[i + 1];
                    minCost = min(minCost, cost);
                }
            }

            dp[index] = minCost;
        }

        return dp[0] - 1;
    }

    int minCut(string& s) {
        // Write your code here

        int n = s.size();

        // vector<int> dp(n, -1);

        //  return memoization(0, n, str, dp) - 1;

        return tabulation(n, s);
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cut(n+1, 0);  // number of cuts for the first k characters
        for (int i = 0; i <= n; i++) cut[i] = i-1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; i-j >= 0 && i+j < n && s[i-j]==s[i+j] ; j++) // odd length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j]);

            for (int j = 1; i-j+1 >= 0 && i+j < n && s[i-j+1] == s[i+j]; j++) // even length palindrome
                cut[i+j+1] = min(cut[i+j+1],1+cut[i-j+1]);
        }
        return cut[n];
    }
};
```

This implementation efficiently computes the minimum cuts required for palindrome partitioning using dynamic programming techniques.
