# 678. Valid Parenthesis String

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [678. Valid Parenthesis String](#678-valid-parenthesis-string)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
      - [Key Observations](#key-observations)
      - [Base Case](#base-case)
    - [Memoization](#memoization)
      - [Optimization](#optimization)
    - [Tabulation](#tabulation)
    - [Greedy Approach](#greedy-approach)
      - [Rules](#rules)
      - [Validity](#validity)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Recursive Solution](#recursive-solution-1)
      - [Memoization](#memoization-1)
      - [Tabulation](#tabulation-1)
      - [Greedy Solution](#greedy-solution)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Recursive Solution](#recursive-solution-2)
    - [Memoization](#memoization-2)
    - [Tabulation](#tabulation-2)
    - [Greedy Solution](#greedy-solution-1)

---

## Introduction

The problem is to determine if a string consisting of `(`, `)`, and `*` is a valid parenthesis string.  
`*` can be interpreted as:

1. An opening bracket `(`.
2. A closing bracket `)`.
3. An empty string.

---

## Problem Description

Given a string `s`, return `true` if the string is valid under the following rules:

1. Every `(` must have a corresponding `)`.
2. Every `)` must have a preceding `(`.
3. `*` can act as any of `(`, `)` or an empty string.

---

### Examples

#### Example 1

**Input**:  
`s = "()"`  
**Output**:  
`true`

#### Example 2

**Input**:  
`s = "(*)"`  
**Output**:  
`true`

#### Example 3

**Input**:  
`s = "(*))"`  
**Output**:  
`true`

---

### Constraints

- \( 1 \leq \text{s.length} \leq 100 \)
- \( \text{s[i]} \in \{ '(', ')', '\*' \} \)

---

## Approach

### Recursive Solution

The recursive approach involves examining all possibilities for each `*`:

1. Treat it as `(`, `)`, or empty.
2. Maintain a count of unmatched opening brackets.
3. At the end, if the count is 0, the string is valid.

#### Key Observations

- If we encounter `(`, increase the count.
- If we encounter `)`, decrease the count (if possible).
- If `*`, explore all three possibilities.

#### Base Case

- If we reach the end of the string, the string is valid if and only if the unmatched opening count is 0.

### Memoization

Memoization avoids recalculating results for the same index and unmatched opening count by caching results.

#### Optimization

Use a DP table where:

- `dp[index][openCount]` represents whether the string from `index` onwards is valid with `openCount` unmatched opening brackets.

---

### Tabulation

The tabulation approach builds the solution iteratively:

1. Create a DP table `dp[index][openCount]`.
2. Start from the end of the string and work backward.
3. Use the base case directly in the table.
4. Fill in values for each `index` and `openCount` by iterating over the string.

---

### Greedy Approach

We maintain two counters:

1. **`minC` (minimum open count)**: Tracks the minimum possible open parentheses count.
2. **`maxC` (maximum open count)**: Tracks the maximum possible open parentheses count.

#### Rules

- Increment both `minC` and `maxC` when encountering `(`.
- Decrement both `minC` and `maxC` when encountering `)`.  
  If `minC` becomes negative, reset it to 0 since negative counts aren't possible.
- For `*`, treat it as both `(` and `)`:
  - Increment `maxC`.
  - Decrement `minC`.

#### Validity

- At any point, if `maxC` becomes negative, the string is invalid (too many `)` encountered).
- At the end of the traversal, if `minC` is 0, the string is valid.

---

## Detailed Explanation of Code

### C++ Implementation

#### Recursive Solution

```cpp
class Solution {
    bool ex(int ind, int openingBracket, string &s) {
        if (ind == s.size())
            return openingBracket == 0;

        bool ans = false;
        if (s[ind] == '*') {
            ans |= ex(ind + 1, openingBracket + 1, s);  // Treat '*' as '('
            if (openingBracket)
                ans |= ex(ind + 1, openingBracket - 1, s);  // Treat '*' as ')'
            ans |= ex(ind + 1, openingBracket, s);  // Treat '*' as empty
        } else {
            if (s[ind] == '(') {
                ans = ex(ind + 1, openingBracket + 1, s);
            } else {
                if (openingBracket)
                    ans = ex(ind + 1, openingBracket - 1, s);
            }
        }

        return ans;
    }

public:
    bool checkValidString(string s) {
        return ex(0, 0, s);
    }
};
```

---

#### Memoization

```cpp
class Solution {
    bool ex(int ind, int openingBracket, string &s, vector<vector<int>> &dp) {
        if (ind == s.size())
            return openingBracket == 0;

        if (dp[ind][openingBracket] != -1)
            return dp[ind][openingBracket];

        bool ans = false;
        if (s[ind] == '*') {
            ans |= ex(ind + 1, openingBracket + 1, s, dp);
            if (openingBracket)
                ans |= ex(ind + 1, openingBracket - 1, s, dp);
            ans |= ex(ind + 1, openingBracket, s, dp);
        } else {
            if (s[ind] == '(') {
                ans = ex(ind + 1, openingBracket + 1, s, dp);
            } else {
                if (openingBracket)
                    ans = ex(ind + 1, openingBracket - 1, s, dp);
            }
        }

        return dp[ind][openingBracket] = ans;
    }

public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        return ex(0, 0, s, dp);
    }
};
```

---

#### Tabulation

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(s.size() + 1, 0));
        dp[s.size()][0] = 1;  // Base case

        for (int ind = s.size() - 1; ind >= 0; ind--) {
            for (int openingBracket = 0; openingBracket < s.size(); openingBracket++) {
                bool ans = false;

                if (s[ind] == '*') {
                    ans |= dp[ind + 1][openingBracket + 1];  // Treat '*' as '('
                    if (openingBracket)
                        ans |= dp[ind + 1][openingBracket - 1];  // Treat '*' as ')'
                    ans |= dp[ind + 1][openingBracket];  // Treat '*' as empty
                } else {
                    if (s[ind] == '(') {
                        ans |= dp[ind + 1][openingBracket + 1];
                    } else {
                        if (openingBracket)
                            ans |= dp[ind + 1][openingBracket - 1];
                    }
                }

                dp[ind][openingBracket] = ans;
            }
        }

        return dp[0][0];
    }
};
```

#### Greedy Solution

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int maxC = 0, minC = 0, n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                minC += 1;
                maxC += 1;
            } else if (s[i] == ')') {
                minC -= 1;
                maxC -= 1;
            } else { // '*'
                minC -= 1;
                maxC += 1;
            }
            if (minC < 0)
                minC = 0; // Reset to 0 if negative
            if (maxC < 0)
                return false; // Invalid
        }

        return minC == 0; // Valid if no unmatched '(' remains
    }
};
```

---

### Java Implementation

```java
class Solution {
    public boolean checkValidString(String s) {
        int maxC = 0, minC = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s.charAt(i) == '(') {
                minC++;
                maxC++;
            } else if (s.charAt(i) == ')') {
                minC--;
                maxC--;
            } else { // '*'
                minC--;
                maxC++;
            }
            if (minC < 0)
                minC = 0; // Reset to 0 if negative
            if (maxC < 0)
                return false; // Invalid
        }

        return minC == 0; // Valid if no unmatched '(' remains
    }
}
```

---

## Complexity Analysis

### Recursive Solution

- **Time Complexity**: \( O(3^n) \) — Exponential due to three choices for `*`.
- **Space Complexity**: \( O(n) \) — Recursion stack.

### Memoization

- **Time Complexity**: \( O(n^2) \) — Solves each state once.
- **Space Complexity**: \( O(n^2) \) — DP table.

### Tabulation

- **Time Complexity**: \( O(n^2) \).
- **Space Complexity**: \( O(n^2) \).

### Greedy Solution

- **C++** and **Java**: \( O(n) \), where \( n \) is the length of the string `s`.
- A single traversal is sufficient to compute the result
- **C++** and **Java**: \( O(1) \).
- Only two variables (`minC` and `maxC`) are used.
