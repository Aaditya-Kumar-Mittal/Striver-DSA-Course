# Rotate String

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Rotate String](#rotate-string)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Brute Force Approach](#brute-force-approach)
    - [Optimized Approach](#optimized-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Brute Force Approach - C++ Implementation](#brute-force-approach---c-implementation)
    - [Optimized Approach - C++ Implementation](#optimized-approach---c-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Brute Force Approach](#brute-force-approach-1)
    - [Optimized Approach](#optimized-approach-1)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem requires us to determine if a string `s` can be transformed into another string `goal` by performing a series of left shifts on `s`. A left shift operation moves the leftmost character of `s` to the rightmost position.

## Problem Description

Given two strings `s` and `goal`, return `true` if and only if `s` can become `goal` after some number of shifts.

### Examples

#### Example 1

**Input:**

```cpp
s = "abcde", goal = "cdeab"
```

**Output:**

```cpp
true
```

**Explanation:** After two shifts: "abcde" → "bcdea" → "cdeab"

#### Example 2

**Input:**

```cpp
s = "abcde", goal = "abced"
```

**Output:**

```cpp
false
```

**Explanation:** No sequence of shifts can make `s` equal to `goal`.

### Constraints

- `1 <= s.length, goal.length <= 100`
- `s` and `goal` consist of lowercase English letters only.

## Approach

### Brute Force Approach

1. If `s` and `goal` have different lengths, return `false`.
2. Rotate `s` one character at a time up to `s.length()` times.
3. If at any point `s` matches `goal`, return `true`.
4. If no match is found after all rotations, return `false`.

### Optimized Approach

Instead of manually rotating the string multiple times, we use the **concatenation trick**:

- If `s` and `goal` have different lengths, return `false`.
- Concatenate `s` with itself (`s + s`).
- If `goal` is a substring of the concatenated string, return `true`.

This approach leverages the property that all possible rotations of `s` appear as substrings in `s + s`.

## Detailed Explanation of Code

### Brute Force Approach - C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        // If lengths do not match, rotation is impossible
        if (m != n)
            return false;

        // Rotate s one character at a time and check
        for (int count = 1; count <= m; count++) {
            rotate(s.begin(), s.begin() + 1, s.end());
            if (s == goal)
                return true;
        }

        return false;
    }
};

// Driver Code
ing main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    cout << (solution.rotateString(s, goal) ? "true" : "false") << endl;
    return 0;
}
```

### Optimized Approach - C++ Implementation

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        int m = s.length();
        int n = goal.length();

        // If lengths do not match, rotation is impossible
        if (m != n)
            return false;

        // Check if 'goal' is a substring of 's + s'
        if ((s + s).find(goal) != string::npos)
            return true;

        return false;
    }
};

// Driver Code
ing main() {
    Solution solution;
    string s = "abcde";
    string goal = "cdeab";
    cout << (solution.rotateString(s, goal) ? "true" : "false") << endl;
    return 0;
}
```

## Complexity Analysis

### Brute Force Approach

- **Time Complexity:** `O(N^2)`, since we rotate the string `N` times and compare it with `goal` each time.
- **Space Complexity:** `O(1)`, as we modify the string in place.

### Optimized Approach

- **Time Complexity:** `O(N)`, where `N` is the length of the string. The `find` function in `s + s` operates in `O(N)`, making this approach efficient.
- **Space Complexity:** `O(N)`, as concatenating `s + s` temporarily stores a copy of `s`.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `rotate_string.cpp`.
2. Compile the code using a C++ compiler:

   ```sh
   g++ rotate_string.cpp -o rotate_string
   ```

3. Run the executable:

   ```sh
   ./rotate_string
   ```
