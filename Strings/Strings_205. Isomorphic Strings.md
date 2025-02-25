# Isomorphic Strings

## Table of Contents

- [Isomorphic Strings](#isomorphic-strings)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Hash Map Based Approach](#hash-map-based-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem requires us to determine if two given strings `s` and `t` are **isomorphic**. Two strings are considered **isomorphic** if we can replace characters in `s` to get `t`, while maintaining a one-to-one mapping between characters.

## Problem Description

Given two strings `s` and `t`, return `true` if they are **isomorphic**, else return `false`.

### Examples

#### Example 1

**Input:**

```cpp
s = "egg", t = "add"
```

**Output:**

```cpp
true
```

**Explanation:**
Mapping:

- 'e' → 'a'
- 'g' → 'd'

#### Example 2

**Input:**

```cpp
s = "foo", t = "bar"
```

**Output:**

```cpp
false
```

**Explanation:**
The character 'o' would need to map to both 'a' and 'r', which is not allowed.

#### Example 3

**Input:**

```cpp
s = "paper", t = "title"
```

**Output:**

```cpp
true
```

**Explanation:**
Mapping:

- 'p' → 't'
- 'a' → 'i'
- 'p' → 't' (consistent mapping)
- 'e' → 'l'
- 'r' → 'e'

### Constraints

- `1 <= s.length <= 5 * 10^4`
- `t.length == s.length`
- `s` and `t` consist of any valid ASCII characters.

## Approach

### Hash Map Based Approach

1. Use two hash maps to store character mappings:
   - `mpp1` for mapping `s[i]` → `t[i]`
   - `mpp2` for mapping `t[i]` → `s[i]`
2. Iterate over both strings and check if:
   - A character in `s` is already mapped to a different character in `t`.
   - A character in `t` is already mapped to a different character in `s`.
3. If any of the above conditions fail, return `false`. Otherwise, return `true`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mpp1, mpp2;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            // Check if mappings are inconsistent
            if ((mpp1.find(ch1) != mpp1.end() && mpp1[ch1] != ch2) ||
                (mpp2.find(ch2) != mpp2.end() && mpp2[ch2] != ch1))
                return false;

            // Store the mapping
            mpp1[ch1] = ch2;
            mpp2[ch2] = ch1;
        }
        return true;
    }
};

// Driver Code
ing main() {
    Solution solution;
    string s = "egg";
    string t = "add";
    cout << (solution.isIsomorphic(s, t) ? "true" : "false") << endl;
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`, where `N` is the length of `s` (or `t`). We iterate over the strings once and perform constant-time operations.
- **Space Complexity:** `O(1)`, since the size of the hash maps is at most `O(256)`, which is a fixed bound.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `isomorphic_strings.cpp`.
2. Compile the code using a C++ compiler:

   ```sh
   g++ isomorphic_strings.cpp -o isomorphic_strings
   ```

3. Run the executable:

   ```sh
   ./isomorphic_strings
   ```
