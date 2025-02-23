# Remove All Occurrences of a Substring

## Table of Contents

- [Remove All Occurrences of a Substring](#remove-all-occurrences-of-a-substring)
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

Given two strings `s` and `part`, the goal is to repeatedly remove all occurrences of `part` from `s` until it no longer appears in `s`. The final modified string is then returned.

## Problem Description

We are given:

- A string `s` consisting of lowercase English letters.
- Another string `part` which is a substring to be removed iteratively.

The task is to find the leftmost occurrence of `part` in `s` and remove it, repeating this process until `part` no longer appears in `s`.

### Examples

#### Example 1

**Input:**

```plaintext
s = "daabcbaabcbc"
part = "abc"
```

**Output:**

```plaintext
"dab"
```

**Explanation:**

1. Remove "abc" from "daabcbaabcbc" → "dabaabcbc"
2. Remove "abc" from "dabaabcbc" → "dababc"
3. Remove "abc" from "dababc" → "dab"

#### Example 2

**Input:**

```plaintext
s = "axxxxyyyyb"
part = "xy"
```

**Output:**

```plaintext
"ab"
```

**Explanation:**

1. Remove "xy" from "axxxxyyyyb" → "axxxyyyb"
2. Remove "xy" from "axxxyyyb" → "axxyyb"
3. Remove "xy" from "axxyyb" → "axyb"
4. Remove "xy" from "axyb" → "ab"

### Constraints

- `1 <= s.length <= 1000`
- `1 <= part.length <= 1000`
- `s` and `part` consist of lowercase English letters only.

## Approach

- Use a loop to repeatedly find and remove the leftmost occurrence of `part` from `s`.
- Continue this process until `part` is no longer present in `s`.
- Return the modified `s`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.length() > 0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};
```

## Complexity Analysis

- **Finding a substring (`s.find(part)`)** takes _O(N)_ in the worst case.
- **Erasing the substring (`s.erase()`)** takes _O(N)_ in the worst case.
- Since this is done repeatedly until all occurrences are removed, in the worst case, we may have to traverse `s` multiple times.
- **Overall complexity:** _O(N^2)_ in the worst case when `part` occurs frequently in `s`.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `remove_occurrences.cpp`.
2. Compile it using:

   ```sh
   g++ remove_occurrences.cpp -o remove_occurrences
   ```

3. Run the executable:

   ```sh
   ./remove_occurrences
   ```

This implementation successfully removes all occurrences of `part` from `s` iteratively and efficiently.
