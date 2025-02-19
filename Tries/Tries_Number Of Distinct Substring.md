# Number of Distinct Substrings

## Table of Contents

- [Number of Distinct Substrings](#number-of-distinct-substrings)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Brute-force Solution](#brute-force-solution)

## Introduction

The problem requires us to determine the number of distinct substrings present in a given string. The substrings should be unique, and we must find an efficient way to count them.

## Problem Description

Given a string **WORD** of length **N** consisting of lowercase English letters, find the number of distinct substrings.

### Examples

#### Example 1

**Input:**

```bash
2
3
aaa
4
abab
```

**Output:**

```bash
3
7
```

**Explanation:**
For the first test case, the distinct substrings are: `"aaa"`, `"aa"`, `"a"` (Total: **3**).
For the second test case, the distinct substrings are: `"abab"`, `"aba"`, `"ab"`, `"a"`, `"bab"`, `"ba"`, `"b"` (Total: **7**).

#### Example 2

**Input:**

```bash
2
1
z
3
abc
```

**Output:**

```bash
1
6
```

**Explanation:**
For the first test case, only `"z"` is a substring (Total: **1**).
For the second test case, distinct substrings are: `"abc"`, `"ab"`, `"a"`, `"bc"`, `"b"`, `"c"` (Total: **6**).

### Constraints

- **1 ≤ T ≤ 100**
- **1 ≤ N ≤ 10^3**
- **‘a’ ≤ WORD[i] ≤ ‘z’** (Lowercase English letters)
- **Time Limit: 1 sec**

## Approach

A **Trie (Prefix Tree)** is used to efficiently count distinct substrings. By inserting all suffixes of the given string into a Trie, each unique node encountered represents a distinct substring.

### Steps

1. Initialize a **Trie (Prefix Tree)**.
2. Iterate over each starting position in the string.
3. For each suffix starting from that position, insert characters into the Trie.
4. Keep a count of unique insertions.
5. Return the count as the number of distinct substrings.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

int countDistinctSubstrings(string &s) {
    int count = 0;
    Node* root = new Node();

    for (int i = 0; i < s.length(); i++) {
        Node* node = root;

        for (int j = i; j < s.length(); j++) {
            if (!node->containsKey(s[j])) {
                count++; // Increment count for each new substring
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }
    return count;
}

int distinctSubstring(string &word) {
    return countDistinctSubstrings(word);
}
```

## Complexity Analysis

- **Insertion in Trie:** `O(N^2)`, since each suffix is inserted in the Trie.
- **Space Complexity:** `O(N^2)`, because in the worst case, all substrings are unique.
- **Overall Complexity:** `O(N^2)`, which is efficient given the constraints.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `distinct_substrings.cpp`.
2. Compile the file:

   ```sh
   g++ distinct_substrings.cpp -o distinct_substrings
   ```

3. Run the program:

   ```sh
   ./distinct_substrings
   ```

## Other Solutions

### Brute-force Solution

```cpp
#include <bits/stdc++.h>

int distinctSubstring(string &word)
{

  //  Write your code here.

  set<string> st;

  int size = word.length();

  for (int i = 0; i < size; i++)
  {

    string str = "";

    for (int j = i; j < size; j++)
    {

      str = str + word[j];

      st.insert(str);
    }
  }

  return st.size();
}
```

This implementation efficiently finds the number of distinct substrings using Trie data structure. 🚀
