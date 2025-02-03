# Delete Operation for Two Strings

## Table of Contents

- [Delete Operation for Two Strings](#delete-operation-for-two-strings)
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
  - [Other Solutions](#other-solutions)
    - [Java Programmes](#java-programmes)

## Introduction

The problem requires finding the **minimum number of deletion operations** needed to make two given strings identical. In each step, exactly one character can be deleted from either string.

## Problem Description

Given two strings `word1` and `word2`, return the **minimum number of steps** required to make them equal.

### Examples

#### Example 1

**Input:**

```cpp
word1 = "sea", word2 = "eat";
```

**Output:**

```cpp
2
```

**Explanation:**  
Deleting 's' from "sea" and 't' from "eat" results in "ea".

#### Example 2

**Input:**

```cpp
word1 = "leetcode", word2 = "etco";
```

**Output:**

```cpp
4
```

### Constraints

- `1 ≤ word1.length, word2.length ≤ 500`
- `word1` and `word2` consist of only lowercase English letters.

## Approach

The problem can be solved using **Dynamic Programming (DP)**:

1. Compute the **Longest Common Subsequence (LCS)** of `word1` and `word2`.
2. The **minimum deletions** required = `(word1 length + word2 length) - (2 * LCS length)`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized DP approach to find LCS of two strings
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

    // Function to find minimum deletions to make two strings equal
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        int lenLCS = tabulation_optimized(n, m, word1, word2);
        return ((n + m) - (2 * lenLCS));
    }
};

// Driver Code
int main() {
    Solution sol;
    string word1 = "sea", word2 = "eat";
    cout << "Minimum Steps to Make Strings Equal: " << sol.minDistance(word1, word2) << endl;
    return 0;
}
```

## Complexity Analysis

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Tabulation (1D DP) | `O(n * m)`      | `O(m)`           |

### Explanation

- **Time Complexity:** `O(n * m)`, as we compute LCS of `word1` and `word2`.
- **Space Complexity:** `O(m)`, due to the optimized DP approach storing only two arrays.

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
Minimum Steps to Make Strings Equal: 2
```

## Other Solutions

### Java Programmes

1. NAIVE RECURSIVE APPROACH

   ```java
       private int solve(String s, String t, int m, int n){

       if(m == 0 || n == 0) return  m + n;

       if(s.charAt(m - 1) == t.charAt(n - 1))
           return solve(s, t, m - 1, n - 1);

       int deleteInS = solve(s, t, m - 1, n);
       int deleteInT = solve(s, t, m, n - 1);

       return Math.min(deleteInS, deleteInT) + 1;
   }
   ```

2. MEMOIZED APPROACH

   ```java
       private int solve(String s, String t, int m, int n, int[][] dp){

        if(m == 0 || n == 0) return dp[m][n] = m + n;

        if(dp[m][n] != -1) return dp[m][n];

        if(s.charAt(m - 1) == t.charAt(n - 1))
            return solve(s, t, m - 1, n - 1, dp);

        int deleteInS = solve(s, t, m - 1, n, dp);
        int deleteInT = solve(s, t, m, n - 1, dp);

        return dp[m][n] = Math.min(deleteInS, deleteInT) + 1;
    }
   ```

3. Tabulation Approach

   ```java
      public int minDistance(String s, String t) {

        int m = s.length(), n = t.length();
        int[][] dp = new int[m + 1][n + 1];
        for(int[] row : dp) Arrays.fill(row, -1);

        for(int i = 0; i <= m; i++)
            dp[i][0] = i;

        for(int j = 0; j <= n; j++)
            dp[0][j] = j;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s.charAt(i - 1) == t.charAt(j - 1))
                    dp[i][j] = dp[i - 1][j - 1];
                else{
                    int deleteInS = dp[i - 1][j];
                    int deleteInT = dp[i][j - 1];
                    dp[i][j] = Math.min(deleteInS, deleteInT) + 1;
                }
            }
        }

        return dp[m][n];
    }
   ```

4. SPACE OPTIMIZED 1D ARRAY

   ```java
   class Solution {

    public int minDistance(String s, String t) {

        int m = s.length(), n = t.length();
        int[] dp = new int[n + 1];

        for(int j = 0; j <= n; j++) dp[j] = j;


        for(int i = 1; i <= m; i++){
            int[] curr = new int[n + 1];
            curr[0] = i;

            for(int j = 1; j <= n; j++){
                if(s.charAt(i - 1) == t.charAt(j - 1)){
                    curr[j] = dp[j - 1];
                } else {
                    int deleteInS = dp[j];
                    int deleteInT = curr[j - 1];
                    curr[j] = Math.min(deleteInS, deleteInT) + 1;
                }
            }
            dp = curr;
        }
        return dp[n];
    }
   }
   ```

| Algorithm          | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Recursive          | `O(2^(m+n))`    | `O(m + n)`       |
| Memoization        | `O(m * n)`      | `O(m * n)`       |
| Tabulation (2D DP) | `O(m * n)`      | `O(m * n)`       |
| Tabulation (1D DP) | `O(m * n)`      | `O(n)`           |
