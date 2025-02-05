# Wildcard Matching

## Table of Contents

- [Wildcard Matching](#wildcard-matching)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Task](#task)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
    - [Space-Optimized Tabulation](#space-optimized-tabulation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)
  - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)
    - [Solution - 5](#solution---5)
      - [Recursive Solution](#recursive-solution)
      - [Memoized Approach](#memoized-approach)
      - [Tabulation Solution](#tabulation-solution)
      - [Space Optimization](#space-optimization)

---

## Introduction

Wildcard Matching is a string pattern matching problem where we need to match an input string `s` against a pattern `p` containing special wildcard characters:

- `?` Matches any **single** character.
- `*` Matches any **sequence** of characters (including an empty sequence).

This problem requires full-string matching, meaning the entire string must match the pattern.

## Problem Description

### Given

- A string `s`
- A pattern `p` (which includes lowercase English letters, `?`, and `*`)

### Task

Determine whether `s` matches the entire pattern `p`.

### Examples

#### Example 1

**Input:**

```cpp
s = "aa", p = "a"
```

**Output:**

```cpp
false
```

**Explanation:** "a" does not match the entire string "aa".

#### Example 2

**Input:**

```cpp
s = "aa", p = "*"
```

**Output:**

```cpp
true
```

**Explanation:** `'*'` matches any sequence.

#### Example 3

**Input:**

```cpp
s = "cb", p = "?a"
```

**Output:**

```cpp
false
```

**Explanation:** `'?'` matches `'c'`, but `'a'` does not match `'b'`.

### Constraints

- `0 <= s.length, p.length <= 2000`
- `s` contains only lowercase English letters.
- `p` contains only lowercase English letters, `?`, or `*`.

## Approach

We use **Dynamic Programming (DP)** to solve this problem efficiently:

1. **Recursive Approach** - Simple but inefficient.
2. **Memoization (Top-down DP)** - Improves efficiency by caching results.
3. **Tabulation (Bottom-up DP)** - Uses a DP table to store results iteratively.
4. **Space-Optimized Tabulation** - Further reduces space complexity.

## Detailed Explanation of Code

### Recursive Approach

A naive recursive function checks all possibilities:

```cpp
bool recursive_solution(int i, int j, string s, string p) {
    if (i < 0 && j < 0) return true;
    if (j < 0) return false;
    if (i < 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }
    if (s[i] == p[j] || p[j] == '?') return recursive_solution(i - 1, j - 1, s, p);
    if (p[j] == '*') return recursive_solution(i - 1, j, s, p) || recursive_solution(i, j - 1, s, p);
    return false;
}
```

### Memoization Approach

Optimizes recursion using a DP table:

```cpp
bool memoization(int i, int j, string s, string p, vector<vector<int>>& dp) {
    if (i < 0 && j < 0) return true;
    if (j < 0) return false;
    if (i < 0) {
        for (int k = 0; k <= j; k++) {
            if (p[k] != '*') return false;
        }
        return true;
    }
    if (dp[i][j] != -1) return dp[i][j];
    if (s[i] == p[j] || p[j] == '?') return dp[i][j] = memoization(i - 1, j - 1, s, p, dp);
    if (p[j] == '*') return dp[i][j] = memoization(i - 1, j, s, p, dp) || memoization(i, j - 1, s, p, dp);
    return dp[i][j] = false;
}
```

### Tabulation Approach

Fills a DP table bottom-up:

```cpp
bool tabulation(int n, int m, string s, string p) {
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= m; j++) {
        dp[0][j] = (p[j - 1] == '*' && dp[0][j - 1]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                dp[i][j] = dp[i - 1][j - 1];
            else if (p[j - 1] == '*')
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
        }
    }
    return dp[n][m];
}
```

### Space-Optimized Tabulation

Reduces space complexity using a rolling array:

```cpp
bool tabulation_optimized(int n, int m, string s, string p) {
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    prev[0] = 1;
    for (int j = 1; j <= m; j++) prev[j] = (p[j - 1] == '*' && prev[j - 1]);
    for (int i = 1; i <= n; i++) {
        cur[0] = 0;
        for (int j = 1; j <= m; j++) {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                cur[j] = prev[j - 1];
            else if (p[j - 1] == '*')
                cur[j] = prev[j] || cur[j - 1];
            else cur[j] = 0;
        }
        prev = cur;
    }
    return prev[m];
}
```

## Complexity Analysis

| Approach                   | Time Complexity | Space Complexity |
| -------------------------- | --------------- | ---------------- |
| Recursive                  | Exponential     | O(N+M) (Stack)   |
| Memoization                | O(N\*M)         | O(N\*M)          |
| Tabulation                 | O(N\*M)         | O(N\*M)          |
| Space-Optimized Tabulation | O(N\*M)         | O(M)             |

## How to Run the Code

```cpp
Solution sol;
bool result = sol.isMatch("abc", "a*c");
cout << (result ? "True" : "False");
```

This will return `True` as "a\*c" matches "abc".

## Other Solutions

### My Submission

```cpp
class Solution {
public:
    bool recursive_solution(int i, int j, string s, string p) {
        // Base cases
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0) {
            // If the remaining pattern is all '*', it can match an empty string
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        // If characters match or pattern has '?'
        if (s[i] == p[j] || p[j] == '?') {
            return recursive_solution(i - 1, j - 1, s, p);
        }

        // If pattern has '*', it can either match nothing or one or more
        // characters
        if (p[j] == '*') {
            return recursive_solution(i - 1, j, s, p) ||
                   recursive_solution(i, j - 1, s, p);
        }

        // If none of the above, no match
        return false;
    }

    bool memoization(int i, int j, string s, string p,
                     vector<vector<int>>& dp) {
        // Base cases
        if (i < 0 && j < 0)
            return true;
        if (j < 0)
            return false;
        if (i < 0) {
            // If the remaining pattern is all '*', it can match an empty string
            for (int k = 0; k <= j; k++) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match or pattern has '?'
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = memoization(i - 1, j - 1, s, p, dp);
        }

        // If pattern has '*', it can either match nothing or one or more
        // characters
        if (p[j] == '*') {
            return dp[i][j] = memoization(i - 1, j, s, p, dp) ||
                              memoization(i, j - 1, s, p, dp);
        }

        // If none of the above, no match
        return dp[i][j] = false;
    }

    bool memoization_index_shifted(int i, int j, string& s, string& p,
                                   vector<vector<int>>& dp) {
        // Base cases
        if (i == 0 && j == 0)
            return true; // Both strings are empty
        if (i == 0 && j > 0)
            return false; // Pattern is empty but string is not

        if (j == 0 && i > 0) {
            // If `s` is empty, `p` should only contain '*'
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*')
                    return false;
            }
            return true;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // If characters match or pattern has '?'
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
            return dp[i][j] = memoization_index_shifted(i - 1, j - 1, s, p, dp);
        }

        // If pattern has '*', it can either match nothing or one or more
        // characters
        if (p[j - 1] == '*') {
            return dp[i][j] = memoization_index_shifted(i - 1, j, s, p, dp) ||
                              memoization_index_shifted(i, j - 1, s, p, dp);
        }

        return dp[i][j] = false;
    }

    bool tabulation(int n, int m, string str, string pattern) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        dp[0][0] = 1; // i == 0 && j == 0

        // If pattern is empty j == 0 so i > 0

        for (int i = 1; i <= n; i++) {
            dp[i][0] = 0;
        }

        // If string is emtpy i == 0 but pattern is not j > 0
        // Pattern can have stars(True) and if not then false
        for (int j = 1; j <= m; j++) {
            int flag = true;
            for (int k = 1; k <= j; k++) {
                if (pattern[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }

        // Loops for changing parameters
        for (int j = 1; j <= m; j++) // for pattern
        {
            for (int i = 1; i <= n; i++) // for string
            {
                if (str[i - 1] == pattern[j - 1] || pattern[j - 1] == '?') {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (pattern[j - 1] == '*') {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        return dp[n][m];
    }

    bool tabulation_optimized(int n, int m, string pattern, string str) {
        vector<int> dp(m + 1, 0), current(m + 1, 0);

        dp[0] = 1; // i == 0 && j == 0

        // If pattern is empty i == 0 so j > 0

        for (int j = 1; j <= m; j++) {
            dp[j] = 0;
        }

        // If string is emtpy j == 0 but pattern is not i > 0
        // Pattern can have stars(True) and if not then false
        // Doing this for every row
        // Fo every row assigning the 0th column value;
        // Loops for changing parameters
        for (int i = 1; i <= n; i++) // for pattern
        {
            // current is the current rows column
            // that current's 0th column has to be assigned

            int flag = true;
            for (int k = 1; k <= i; k++) {
                if (pattern[k - 1] != '*') {
                    flag = false;
                    break;
                }
            }
            current[0] = flag;

            for (int j = 1; j <= m; j++) // for string
            {
                if (pattern[i - 1] == str[j - 1] || pattern[i - 1] == '?') {
                    current[j] = dp[j - 1];
                } else if (pattern[i - 1] == '*') {
                    current[j] = dp[j] || current[j - 1];
                } else {
                    current[j] = 0;
                }
            }

            dp = current;
        }

        return dp[m];
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // vector<vector<int>> dp1(n + 1, vector<int>(m + 1, -1));
        // return tabulation(n, m, s, p);

        return tabulation_optimized(m, n, p, s);
    }
};
```

## Solution - 2

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        // Initialize pointers for the string and pattern
        int i = 0, j = 0;
        // Variables to track the position of the last '*' in the pattern
        int star = -1, match = 0;

        // Traverse the string `s`
        while (i < s.size()) {
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                // Case 1: Characters match or `?` matches any single character
                i++;
                j++;
            } else if (j < p.size() && p[j] == '*') {
                // Case 2: '*' can match zero or more characters
                star = j;    // Save the position of '*'
                match = i;   // Save the current position in `s` for backtracking
                j++;         // Move to the next character in the pattern
            } else if (star >= 0) {
                // Case 3: No match, but a previous '*' allows backtracking
                j = star + 1;  // Revert `j` to the position after '*'
                i = ++match;   // Increment `match` to include the next character in `s`
            } else {
                // Case 4: No match and no previous '*', return false
                return false;
            }
        }

        // Ensure the remaining characters in `p` are all `*`
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        // If we have consumed the entire pattern, return true
        return j == p.size();
    }
};
```

- Time Complexity: O(m \* n)
- Space Complexity: O(1)

### Solution - 3

```cpp
class Solution {
public:
    int n, m;
    vector<vector<int>> mem;

    int dp(int i1, int i2, string& s, string& p) {
        if (i1 == n) {
            while(i2 < m and p[i2] == '*') i2++;
            return i2 == m;
        }

        if (i2 == m) return 0;

        if (mem[i1][i2] != -1) {
            return mem[i1][i2];
        }

        char c1 = s[i1];
        char c2 = p[i2];
        int ans = 0;
        if (c2 == '*') {
            ans |= dp(i1, i2+1, s, p);
            ans |= dp(i1+1, i2, s, p);
        }
        else if (c1 == c2 or c2 == '?') {
            ans |= dp(i1+1, i2+1, s, p);
        }

        return mem[i1][i2] = ans;
    }

    bool isMatch(const std::string& s, const std::string& p) {
        int m = s.size(), n = p.size();
        int sIdx = 0, pIdx = 0;  // Pointers for string and pattern
        int starIdx = -1, matchIdx = 0;

        while (sIdx < m) {
            if (pIdx < n && (p[pIdx] == s[sIdx] || p[pIdx] == '?')) {
                // Characters match or '?'
                sIdx++;
                pIdx++;
            } else if (pIdx < n && p[pIdx] == '*') {
                // Found '*', record positions
                starIdx = pIdx;
                matchIdx = sIdx;
                pIdx++;
            } else if (starIdx != -1) {
                // Backtrack to last '*'
                pIdx = starIdx + 1;
                matchIdx++;
                sIdx = matchIdx;
            } else {
                // No match
                return false;
            }
        }

        // Check remaining characters in pattern
        while (pIdx < n && p[pIdx] == '*') {
            pIdx++;
        }

        return pIdx == n;
    }
};
```

### Solution - 4

```cpp
 bool isMatch(const char *s, const char *p) {
        const char* star=NULL;
        const char* ss=s;
        while (*s){
            //advancing both pointers when (both characters match) or ('?' found in pattern)
            //note that *p will not advance beyond its length
            if ((*p=='?')||(*p==*s)){s++;p++;continue;}

            // * found in pattern, track index of *, only advancing pattern pointer
            if (*p=='*'){star=p++; ss=s;continue;}

            //current characters didn't match, last pattern pointer was *, current pattern pointer is not *
            //only advancing pattern pointer
            if (star){ p = star+1; s=++ss;continue;}

           //current pattern pointer is not star, last patter pointer was not *
           //characters do not match
            return false;
        }

       //check for remaining characters in pattern
        while (*p=='*'){p++;}

        return !*p;
    }
```

```java
  boolean comparison(String str, String pattern) {
        int s = 0, p = 0, match = 0, starIdx = -1;
        while (s < str.length()){
            // advancing both pointers
            if (p < pattern.length()  && (pattern.charAt(p) == '?' || str.charAt(s) == pattern.charAt(p))){
                s++;
                p++;
            }
            // * found, only advancing pattern pointer
            else if (p < pattern.length() && pattern.charAt(p) == '*'){
                starIdx = p;
                match = s;
                p++;
            }
           // last pattern pointer was *, advancing string pointer
            else if (starIdx != -1){
                p = starIdx + 1;
                match++;
                s = match;
            }
           //current pattern pointer is not star, last patter pointer was not *
          //characters do not match
            else return false;
        }

        //check for remaining characters in pattern
        while (p < pattern.length() && pattern.charAt(p) == '*')
            p++;

        return p == pattern.length();
    }
```

- Time Complexity: O(m \* n)
- Space Complexity: O(1)

### Solution - 5

#### Recursive Solution

```cpp
//Recursion code

bool matchStrings(string& pattern, string& text, int patternIndex, int textIndex)
{
    //BASE CASES
    //If both the pattern and the string text are exhausted:
    if(patternIndex<0 and textIndex<0)
        return true;    //the pattern matches the string!

    //If only the pattern is exhausted:
    if(patternIndex<0 and textIndex >= 0)
        return false;    //the pattern doesn't match the string

    if(textIndex<0)    //obviously, patternIndex >= 0
    {
        for(int currentPatternIndex = patternIndex; currentPatternIndex >= 0; currentPatternIndex--)
        {
            if(pattern[currentPatternIndex] != '*')
                return false;   //because the string text is exhausted
        }
        return true;    //taking '*' to be 0 characters
    }


    //If char are same or char is a '?', decrement both indexes and continue matching
    if(pattern[patternIndex] == text[textIndex] or pattern[patternIndex] == '?')
        return matchStrings(pattern, text, patternIndex-1, textIndex-1);

    //If pattern is a *, take 0 or more characters to compare
    if(pattern[patternIndex] == '*')
    {
        return
        //take 0 characters in the text
        matchStrings(pattern, text, patternIndex-1, textIndex)
        or
        //take 1 charcter (recursively it'll take till end of string 'text')
        matchStrings(pattern, text, patternIndex, textIndex-1);
    }

    //if characters in the pattern and text don't match, return false
    return false;
}

bool wildcardMatching(string pattern, string text)
{
    return matchStrings(pattern, text, pattern.size()-1, text.size()-1);
}
```

#### Memoized Approach

```cpp
//Memoization code

#include<bits/stdc++.h>

bool matchStrings(string& pattern, string& text, int patternIndex, int textIndex, vector<vector<int>>& memory)
{
    //BASE CASES
    //If both the pattern and the string text are exhausted:
    if(patternIndex<0 and textIndex<0)
        return true;    //the pattern matches the string!

    //If only the pattern is exhausted:
    if(patternIndex<0 and textIndex >= 0)
        return false;    //the pattern doesn't match the string

    if(textIndex<0)    //obviously, patternIndex >= 0
    {
        for(int currentPatternIndex = patternIndex; currentPatternIndex >= 0; currentPatternIndex--)
        {
            if(pattern[currentPatternIndex] != '*')
                return false;   //because the string text is exhausted
        }
        return true;    //taking '*' to be 0 characters
    }

    if(memory[patternIndex][textIndex] != -1)
        return memory[patternIndex][textIndex];

    //If char are same or char is a '?', decrement both indexes and continue matching
    if(pattern[patternIndex] == text[textIndex] or pattern[patternIndex] == '?')
        return memory[patternIndex][textIndex] =
        matchStrings(pattern, text, patternIndex-1, textIndex-1, memory);

    //If pattern is a *, take 0 or more characters to compare
    if(pattern[patternIndex] == '*')
    {
        return memory[patternIndex][textIndex] =
        //take 0 characters in the text
        matchStrings(pattern, text, patternIndex-1, textIndex, memory)
        or
        //take 1 charcter (recursively it'll take till end of string 'text')
        matchStrings(pattern, text, patternIndex, textIndex-1, memory);
    }

    //if characters in the pattern and text don't match, return false
    return false;
}

bool wildcardMatching(string pattern, string text)
{
    vector<vector<int>> memory(pattern.size(), vector<int>(text.size(), -1));
    return matchStrings(pattern, text, pattern.size()-1, text.size()-1, memory);
}
```

#### Tabulation Solution

```cpp
//Tabulation code - I've done Ph.D on this. Period.

#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
    //Note the "+1" to make writing base case easier
    //This can be filled with anything. It'll be overwritten with the correct data
    vector<vector<int>> memory(pattern.size()+1, vector<int>(text.size()+1, -1));

    //if there is no pattern and no text, they both match (trivial case)
    memory[0][0] = true;

    //if there is no pattern, but the text is remaining, they don't 'match'
    for(int textIndex=1; textIndex <= text.size(); textIndex++)
    {
        memory[0][textIndex] = false;
    }

    //if there is no text, the pattern must be all * for answer to be true
    for(int patternIndex=1; patternIndex <= pattern.size(); patternIndex++)
    {
        //if there was previously a non * char, then all further chars will also give false
        if(memory.at(patternIndex-1).at(0) == false)
        {
            memory.at(patternIndex).at(0) = false;
            continue;
        }

        //if the corresponding char is non *, then ans is false, because the text is null
        if(pattern[patternIndex-1] != '*')
            memory.at(patternIndex).at(0) = false;
        else
            memory.at(patternIndex).at(0) = true;
    }

    for(int patternIndex=1; patternIndex<=pattern.size(); patternIndex++)
    {
        //YOU HAVE TO START THIS WITH 1. IF YOU START WITH 0, YOU'D BE ACCESSING VECTOR OUT OF BOUNDS!
        for(int textIndex=1; textIndex<=text.size(); textIndex++)
        {
            //If char are same or char is a '?', decrement both indexes and continue matching
            //Don't forget the -1 while accessing characters of the strings
            if(pattern[patternIndex-1] == text[textIndex-1] or pattern[patternIndex-1] == '?')
                memory.at(patternIndex).at(textIndex) = memory.at(patternIndex-1).at(textIndex-1);

            //If pattern is a *, take 0 or more characters to compare
            //Don't forget the -1 while accessing characters of the strings
            else if(pattern[patternIndex-1] == '*')
            {
                memory.at(patternIndex).at(textIndex) =
                //take 0 characters in the text
                memory.at(patternIndex-1).at(textIndex)
                or
                //take 1 charcter (recursively it'll take till end of string 'text')
                memory.at(patternIndex).at(textIndex-1);
            }

            else
            {
                //if characters in the pattern and text don't match, set it as false
                memory.at(patternIndex).at(textIndex) = false;
            }
        }
    }

    return memory.at(pattern.size()).at(text.size());
}
```

#### Space Optimization

```cpp
//Space Optimisation code

#include<bits/stdc++.h>

bool wildcardMatching(string pattern, string text)
{
    //Note the "+1" to make writing base case easier
    //This can be filled with anything. It'll be overwritten with the correct data
    vector<int> prevPatternChar(text.size()+1, -1), currPatternChar(text.size()+1, -1);

    //if there is no pattern and no text, they both match (trivial case)
    prevPatternChar.at(0) = true;

    //if there is no pattern, but the text is remaining, they don't 'match'
    for(int textIndex=1; textIndex <= text.size(); textIndex++)
    {
        prevPatternChar.at(textIndex) = false;
    }

    //OUTER FOR LOOP
    for(int patternIndex=1; patternIndex<=pattern.size(); patternIndex++)
    {
        //SETTING THE FIRST COLUMN OF THE CURRENT ROW
        //if there was previously a non * char, then all further chars will also give false
        if(prevPatternChar.at(0) == false)
        {
            currPatternChar.at(0) = false;
        }
        //if the corresponding char is non *, then ans is false, because the text is null
        else if(pattern[patternIndex-1] != '*')
            currPatternChar.at(0) = false;
        else
            currPatternChar.at(0) = true;

        //INNER FOR LOOP
        //YOU HAVE TO START THIS WITH 1. IF YOU START WITH 0, YOU'D BE ACCESSING VECTOR OUT OF BOUNDS!
        for(int textIndex=1; textIndex<=text.size(); textIndex++)
        {
            //If char are same or char is a '?', decrement both indexes and continue matching
            //Don't forget the -1 while accessing characters of the strings
            if(pattern[patternIndex-1] == text[textIndex-1] or pattern[patternIndex-1] == '?')
                currPatternChar.at(textIndex) = prevPatternChar.at(textIndex-1);

            //If pattern is a *, take 0 or more characters to compare
            //Don't forget the -1 while accessing characters of the strings
            else if(pattern[patternIndex-1] == '*')
            {
                currPatternChar.at(textIndex) =
                //take 0 characters in the text
                prevPatternChar.at(textIndex)
                or
                //take 1 charcter (recursively it'll take till end of string 'text')
                currPatternChar.at(textIndex-1);
            }

            else
            {
                //if characters in the pattern and text don't match, set it as false
                currPatternChar.at(textIndex) = false;
            }
        }
        prevPatternChar = currPatternChar;
    }

    return prevPatternChar.at(text.size());
}
```
