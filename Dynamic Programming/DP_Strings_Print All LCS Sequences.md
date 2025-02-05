# Print All LCS Sequences

## Table of Contents

- [Print All LCS Sequences](#print-all-lcs-sequences)
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
  - [Summary](#summary)

---

## Introduction

The problem requires us to find and print all the longest common subsequences (LCS) of two given strings in lexicographical order.

A subsequence of a string is a sequence derived by deleting some or no characters without changing the relative order of the remaining characters.

The longest common subsequence (LCS) is the longest sequence that appears as a subsequence in both given strings.

---

## Problem Description

Given two strings `s` and `t`, the task is to find all longest common subsequences and return them in lexicographical order.

### Examples

#### Example 1

Input:  
`s = "abaaa"`  
`t = "baabaca"`

Output:  
`aaaa abaa baaa`

Explanation:  
The LCS length is 4. The LCS sequences in lexicographical order are:  
`aaaa, abaa, baaa`

---

#### Example 2

Input:  
`s = "aaa"`  
`t = "a"`

Output:  
`a`

Explanation:  
The only LCS is `"a"`.

---

### Constraints

- `1 ≤ |s|, |t| ≤ 50` (length of both strings)
- The solution must return all LCS sequences in lexicographical order.
- Expected Time Complexity: O(n³)
- Expected Space Complexity: O(k \* n) where `k` is a constant less than `n`.

---

## Approach

The solution involves two major steps:

1. Dynamic Programming Table Construction (`dp[][]`)

   - Use a 2D DP table where `dp[i][j]` stores the length of LCS of `s[0...i-1]` and `t[0...j-1]`.
   - The recurrence relation:
     - If `s[i-1] == t[j-1]`:  
       `dp[i][j] = 1 + dp[i-1][j-1]`
     - Else:  
       `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`

2. Backtracking to Find All LCS Strings
   - Start from `dp[n][m]` and reconstruct all LCS using backtracking.
   - Use a set to store unique LCS sequences.
   - Use memoization with an unordered map to avoid duplicate states.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
public:
    // Function to find all LCS sequences using backtracking
    void allLCS(vector<vector<int>> &dp, set<string> &st, unordered_map<string, bool> &mp,
                string &s, string &t, int i, int j, string ds) {
        // Base Case: If we reach the beginning of either string
        if (i == 0 || j == 0) {
            reverse(ds.begin(), ds.end()); // Reverse to get correct order
            st.insert(ds);
            return;
        }

        // Memoization check
        string key = to_string(i) + '$' + to_string(j) + '$' + ds;
        if (mp.find(key) != mp.end()) return;
        mp[key] = true;

        // Case 1: If characters match, include them in LCS
        if (s[i - 1] == t[j - 1]) {
            ds.push_back(s[i - 1]);
            allLCS(dp, st, mp, s, t, i - 1, j - 1, ds);
        }
        // Case 2: Explore both possible paths in DP table
        else {
            if (dp[i][j] == dp[i - 1][j]) {
                allLCS(dp, st, mp, s, t, i - 1, j, ds);
            }
            if (dp[i][j] == dp[i][j - 1]) {
                allLCS(dp, st, mp, s, t, i, j - 1, ds);
            }
        }
    }

    // Function to compute all longest common subsequences
    vector<string> all_longest_common_subsequences(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Step 1: Fill the DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // Step 2: Use backtracking to generate all LCS
        set<string> st;
        unordered_map<string, bool> mp;
        string ds = "";

        allLCS(dp, st, mp, s, t, n, m, ds);

        // Step 3: Convert set to sorted vector
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};

// { Driver Code Starts
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        vector<string> ans = ob.all_longest_common_subsequences(s, t);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
```

---

## Complexity Analysis

- Time Complexity:
  - O(n × m) for DP table construction.
  - O(k \* n) for backtracking, where `k` is a small constant.
  - Overall: O(n³) in the worst case.
- Space Complexity:
  - O(n × m) for DP table.
  - O(k \* n) for storing LCS sequences.
  - Overall: O(k \* n), where k < n.

---

## How to Run the Code

### For C++

1. Compile the code using:

   ```bash
   g++ filename.cpp -o output
   ```

2. Run the executable:

   ```bash
   ./output
   ```

3. Provide input (example):

   ```bash
   1
   abaaa baabaca
   ```

4. Expected Output:

   ```bash
   aaaa abaa baaa
   ```

---

## Summary

- We use dynamic programming to compute the LCS length.
- We use backtracking with memoization to extract all possible LCS.
- The set ensures lexicographical order.
- The approach runs in O(n³) time and O(k \* n) space.

This solution efficiently finds and prints all longest common subsequences in lexicographical order! 🚀
