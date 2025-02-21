# Minimum Window Subsequence

## Table of Contents

- [Minimum Window Subsequence](#minimum-window-subsequence)
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

## Introduction

The problem requires us to find the **smallest contiguous substring** `W` of `S`, such that `T` is a subsequence of `W`. If multiple such windows exist, we return the one with the **smallest starting index**.

A **subsequence** is a sequence derived by removing zero or more elements without changing order, whereas a **substring** is a contiguous part of a string.

## Problem Description

Given two strings `S` and `T`, find the **minimum-length substring** in `S` that contains all characters of `T` in order. If no such substring exists, return an empty string `""`.

### Examples

#### Example 1

**Input:**

```bash
S = "abcdebdde"
T = "bde"
```

**Output:**

```bash
"bcde"
```

**Explanation:**  
The substring "bcde" is the shortest contiguous substring that contains "bde" in the same order.

#### Example 2

**Input:**

```bash
S = "hello"
T = "eo"
```

**Output:**

```bash
"ello"
```

### Constraints

- `1 <= |S| <= 1000`
- `1 <= |T| <= 100`
- The time limit for execution is **1 second**.

## Approach

1. **Two-Pointer Technique:**
   - Use two pointers `i` and `j` to traverse `S`.
   - `j` moves forward to find matches for characters in `T`.
   - Once all characters in `T` are matched, move `i` backward to find the minimum window.
2. **Sliding Window with Backtracking:**
   - Once a valid window is found, shrink it from the left.
   - Keep track of the minimum-length substring found so far.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

string minWindow(string S, string T) {
    int i = 0, j = 0, k = 0, res = INT_MAX;
    string str;

    while (j < S.length()) {
        if (S[j] == T[k]) {
            k++; // Match characters of T in S
        }

        // If all characters of T are matched
        if (k == T.length()) {
            i = j; // Start from the end of the window
            k = T.length() - 1; // Reset k to the last character of T

            // Move backward to find the start of the window
            while (i >= 0 && k >= 0) {
                if (S[i] == T[k]) {
                    k--;
                }
                i--;
            }
            i++; // Adjust i to the start of the window

            // Calculate the window length
            int windowLen = j - i + 1;

            // Update the result if this window is smaller
            if (res > windowLen) {
                res = windowLen;
                str = S.substr(i, windowLen);
            }

            // Reset k to 0 to search for the next window
            k = 0;
            j = i + 1; // Move j to the next character after i
        } else {
            j++; // Move j forward to find the next match
        }
    }

    // If no valid window is found, return an empty string
    return (res == INT_MAX) ? "" : str;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N * M)`, where `N` is the length of `S` and `M` is the length of `T`.
  - We iterate through `S` once (`O(N)`) and for each valid window, we backtrack (`O(M)`).
- **Space Complexity:** `O(1)`, since we only use a few integer variables and a string to store the result.

## How to Run the Code

### For C++

1. **Compile the code** using a C++ compiler:

   ```sh
   g++ -o min_window min_window.cpp
   ```

2. **Run the compiled program:**

   ```sh
   ./min_window
   ```

3. **Input example:**

   ```sh
   Enter string S: abcdebdde
   Enter string T: bde
   ```

4. **Output example:**

   ```sh
   Minimum Window Subsequence: bcde
   ```

This concludes the detailed explanation of the **Minimum Window Subsequence** problem. 🚀
