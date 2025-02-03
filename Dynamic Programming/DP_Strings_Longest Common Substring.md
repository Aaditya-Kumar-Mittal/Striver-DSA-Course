# Longest Common Substring

## Table of Contents

- [Longest Common Substring](#longest-common-substring)
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
    - [Explanation](#explanation)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Expected Output](#expected-output)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

## Introduction

The problem requires finding the **length of the longest common substring** between two given strings. A substring is a contiguous sequence of characters within a string. The longest common substring is the one that appears in both strings with the maximum length.

## Problem Description

Given two strings `s1` and `s2`, determine the length of the **longest common substring**.

### Examples

#### Example 1

**Input:**

```cpp
s1 = "ABCDGH";
s2 = "ACDGHR";
```

**Output:**

```cpp
4
```

**Explanation:**  
The longest common substring is **"CDGH"**, which has a length of **4**.

#### Example 2

**Input:**

```cpp
s1 = "abc";
s2 = "acb";
```

**Output:**

```cpp
1
```

**Explanation:**  
The longest common substrings are **"a"**, **"b"**, and **"c"**, each of length **1**.

#### Example 3

**Input:**

```cpp
s1 = "YZ";
s2 = "yz";
```

**Output:**

```cpp
0
```

**Explanation:**  
There are no common substrings, so the output is **0**.

### Constraints

- `1 <= s1.size(), s2.size() <= 1000`
- Strings `s1` and `s2` consist of **uppercase and lowercase English letters**.

## Approach

The solution employs **Dynamic Programming (DP)** to efficiently compute the length of the longest common substring.

1. **Tabulation (2D DP)**: We create a `dp` table where `dp[i][j]` stores the length of the longest common substring ending at `s1[i-1]` and `s2[j-1]`.
2. **Space Optimized Approach (1D DP)**: Instead of using a full 2D table, we maintain two 1D arrays (`dp` and `current`) to store previous and current row values, reducing space complexity.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Tabulation Approach (2D DP)
    int tabulation(int n, int m, string& s1, string& s2) {
        int ans = 0;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }
        return ans;
    }

    // Optimized Tabulation (1D DP)
    int tabulation_optimized(int n, int m, string& s1, string& s2) {
        int ans = 0;
        vector<int> dp(m + 1, 0), current(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    current[j] = 1 + dp[j - 1];
                    ans = max(ans, current[j]);
                } else {
                    current[j] = 0;
                }
            }
            dp = current;
        }
        return ans;
    }

    // Function to find longest common substring length
    int longestCommonSubstr(string& s1, string& s2) {
        int n = s1.size();
        int m = s2.size();
        return tabulation_optimized(n, m, s1, s2);
    }
};

// Driver Code
int main() {
    Solution sol;
    string s1 = "ABCDGH", s2 = "ACDGHR";
    cout << "Longest Common Substring Length: " << sol.longestCommonSubstr(s1, s2) << endl;
    return 0;
}
```

## Complexity Analysis

| Approach                     | Time Complexity | Space Complexity |
| ---------------------------- | --------------- | ---------------- |
| Tabulation (2D DP)           | `O(n * m)`      | `O(n * m)`       |
| Optimized Tabulation (1D DP) | `O(n * m)`      | `O(m)`           |

### Explanation

- **Time Complexity:** We iterate through both strings, filling the DP table, which results in `O(n * m)` operations.
- **Space Complexity:**
  - The **2D DP approach** requires `O(n * m)` space.
  - The **optimized approach** reduces space to `O(m)` by using only two 1D arrays.

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
Longest Common Substring Length: 4
```

## Other Solutions

### My Submission

```cpp
class Solution
{
public:
  int tabulation(int n, int m, string &s1, string &s2)
  {
    int ans = 0;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          ans = max(ans, dp[i][j]);
        }
        else
        {
          dp[i][j] = 0;
        }
      }
    }

    return ans;
  }

  int tabulation_optimized(int n, int m, string &s1, string &s2)
  {
    int ans = 0;

    vector<int> dp(m + 1, 0), current(m + 1, 0);

    // Fill DP table
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= m; j++)
      {
        if (s1[i - 1] == s2[j - 1])
        {
          current[j] = 1 + dp[j - 1];
          ans = max(ans, current[j]);
        }
        else
        {
          current[j] = 0;
        }
      }
      dp = current;
    }

    return ans;
  }

  int longestCommonSubstr(string &s1, string &s2)
  {

    int n = s1.size();
    int m = s2.size();

    return tabulation_optimized(n, m, s1, s2);
  }
};
```
