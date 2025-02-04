# Edit Distance

## Table of Contents

- [Edit Distance](#edit-distance)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Solution](#recursive-solution)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
    - [Space Optimized Tabulation Approach](#space-optimized-tabulation-approach)
    - [Complexity Analysis](#complexity-analysis)
      - [1. **Recursive Approach**](#1-recursive-approach)
      - [2. **Memoization (Top-Down DP)**](#2-memoization-top-down-dp)
      - [3. **Tabulation (Bottom-Up DP)**](#3-tabulation-bottom-up-dp)
      - [4. **Optimized Tabulation (Space-Optimized DP)**](#4-optimized-tabulation-space-optimized-dp)
    - [How to Run the Code](#how-to-run-the-code)
      - [**For C++**](#for-c)

## Introduction

The **Edit Distance** problem aims to determine the minimum number of operations required to convert one string into another. The allowed operations include:

1. **Insertion** of a character.
2. **Deletion** of a character.
3. **Replacement** of a character.

## Problem Description

Given two strings `word1` and `word2`, return the minimum number of operations required to convert `word1` into `word2`.

### Examples

#### Example 1

**Input:**

```cpp
word1 = "horse"
word2 = "ros"
```

**Output:**

```cpp
3
```

**Explanation:**

1. `horse` → `rorse` (replace 'h' with 'r')
2. `rorse` → `rose` (remove 'r')
3. `rose` → `ros` (remove 'e')

#### Example 2

**Input:**

```cpp
word1 = "intention"
word2 = "execution"
```

**Output:**

```cpp
5
```

**Explanation:**

1. `intention` → `inention` (remove 't')
2. `inention` → `enention` (replace 'i' with 'e')
3. `enention` → `exention` (replace 'n' with 'x')
4. `exention` → `exection` (replace 'n' with 'c')
5. `exection` → `execution` (insert 'u')

### Constraints

- `0 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of lowercase English letters.

## Approach

We use **Dynamic Programming** (DP) to solve the problem efficiently. We discuss four methods:

1. **Recursive Approach**
2. **Memoization (Top-Down DP)**
3. **Tabulation (Bottom-Up DP)**
4. **Space-Optimized Tabulation**

## Detailed Explanation of Code

### Recursive Solution

A straightforward recursive solution that explores all possible edit operations.

```cpp
int recursive_solution(int i, int j, string s1, string s2) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (s1[i] == s2[j]) {
        return recursive_solution(i - 1, j - 1, s1, s2);
    } else {
        int insertion = 1 + recursive_solution(i, j - 1, s1, s2);
        int deletion = 1 + recursive_solution(i - 1, j, s1, s2);
        int replacement = 1 + recursive_solution(i - 1, j - 1, s1, s2);
        return min(insertion, min(deletion, replacement));
    }
}
```

**Time Complexity:** O(3^(n+m))

### Memoization Approach

An optimized recursive approach using a memoization table to store results of subproblems.

```cpp
int memoization(int i, int j, string& s1, string& s2, vector<vector<int>>& memo) {
    if (i < 0) return j + 1;
    if (j < 0) return i + 1;

    if (memo[i][j] != -1) return memo[i][j];

    if (s1[i] == s2[j]) {
        return memo[i][j] = memoization(i - 1, j - 1, s1, s2, memo);
    } else {
        int insertion = 1 + memoization(i, j - 1, s1, s2, memo);
        int deletion = 1 + memoization(i - 1, j, s1, s2, memo);
        int replacement = 1 + memoization(i - 1, j - 1, s1, s2, memo);
        return memo[i][j] = min(insertion, min(deletion, replacement));
    }
}
```

**Time Complexity:** O(n\*m)

### Tabulation Approach

A bottom-up DP approach using a 2D table.

```cpp
int tabulation(int n, int m, string& s1, string& s2) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;
    for (int j = 0; j <= m; j++) dp[0][j] = j;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int insertion = 1 + dp[i][j - 1];
                int deletion = 1 + dp[i - 1][j];
                int replacement = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insertion, deletion, replacement});
            }
        }
    }
    return dp[n][m];
}
```

**Time Complexity:** O(n*m), **Space Complexity:** O(n*m)

### Space Optimized Tabulation Approach

Reduces space complexity to O(m) using two arrays.

```cpp
int tabulation_optimized(int n, int m, string& s1, string& s2) {
    vector<int> dp(m + 1, 0), current(m + 1, 0);
    for (int j = 0; j <= m; j++) dp[j] = j;

    for (int i = 1; i <= n; i++) {
        current[0] = i;
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1])
                current[j] = dp[j - 1];
            else
                current[j] = min({1 + current[j - 1], 1 + dp[j], 1 + dp[j - 1]});
        }
        dp = current;
    }
    return dp[m];
}
```

**Time Complexity:** O(n\*m), **Space Complexity:** O(m)

### Complexity Analysis

#### 1. **Recursive Approach**

- **Time Complexity:** \( O(3^{\max(n, m)}) \)
  - Each character in `word1` can be transformed in three ways (insert, delete, replace), leading to an exponential recursion tree.
- **Space Complexity:** \( O(\max(n, m)) \)
  - The recursion depth can go up to the length of the longer string.

#### 2. **Memoization (Top-Down DP)**

- **Time Complexity:** \( O(n \times m) \)
  - Each subproblem is computed only once and stored in a memoization table.
- **Space Complexity:** \( O(n \times m) \)
  - The memoization table stores intermediate results.

#### 3. **Tabulation (Bottom-Up DP)**

- **Time Complexity:** \( O(n \times m) \)
  - A DP table of size \( (n+1) \times (m+1) \) is filled iteratively.
- **Space Complexity:** \( O(n \times m) \)
  - The DP table requires \( O(n \times m) \) space.

#### 4. **Optimized Tabulation (Space-Optimized DP)**

- **Time Complexity:** \( O(n \times m) \)
  - Similar to standard tabulation, every cell is computed in a single pass.
- **Space Complexity:** \( O(m) \)
  - Instead of storing the entire DP table, only two rows are maintained, reducing space complexity to \( O(m) \).

| Approach                                  | Time Complexity         | Space Complexity    |
| ----------------------------------------- | ----------------------- | ------------------- |
| Recursive                                 | \( O(3^{\max(n, m)}) \) | \( O(\max(n, m)) \) |
| Memoization (Top-Down DP)                 | \( O(n \times m) \)     | \( O(n \times m) \) |
| Tabulation (Bottom-Up DP)                 | \( O(n \times m) \)     | \( O(n \times m) \) |
| Optimized Tabulation (Space-Optimized DP) | \( O(n \times m) \)     | \( O(m) \)          |

---

### How to Run the Code

#### **For C++**

1. **Compile the code:**

   ```bash
   g++ edit_distance.cpp -o edit_distance
   ```

2. **Run the executable:**

   ```bash
   ./edit_distance
   ```

3. **Sample Input:**

   ```cpp
   string word1 = "horse";
   string word2 = "ros";
   Solution obj;
   cout << obj.minDistance(word1, word2) << endl;
   ```

4. **Expected Output:**

   ```bash
   3
   ```
