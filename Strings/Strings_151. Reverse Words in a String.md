# Reverse Words in a String

## Table of Contents

- [Reverse Words in a String](#reverse-words-in-a-string)
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
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

Given an input string `s`, the goal is to reverse the order of the words while ensuring that there is only a single space separating words, and no leading or trailing spaces.

## Problem Description

A **word** is defined as a sequence of non-space characters. The words in `s` will be separated by at least one space. The task is to return a string of the words in reverse order, concatenated by a single space.

### Examples

#### Example 1

**Input:**  
`s = "the sky is blue"`  
**Output:**  
`"blue is sky the"`

#### Example 2

**Input:**  
`s = "  hello world  "`  
**Output:**  
`"world hello"`  
**Explanation:** The reversed string should not contain leading or trailing spaces.

#### Example 3

**Input:**  
`s = "a good   example"`  
**Output:**  
`"example good a"`  
**Explanation:** Multiple spaces between words should be reduced to a single space.

### Constraints

- `1 <= s.length <= 10^4`
- `s` contains English letters (both uppercase and lowercase), digits, and spaces `' '`.
- There is at least one word in `s`.

## Approach

1. **Reverse the entire string**: This brings words to their respective reversed positions but also reverses the characters.
2. **Extract words and reverse them individually**: Traverse through the string and reverse words one by one.
3. **Concatenate words with single space**: Ensure that multiple spaces are removed and only one space is used between words.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";

        // Reverse the entire string
        reverse(s.begin(), s.end());

        for (int i = 0; i < s.length(); i++) {
            string word = "";

            // Extract words by skipping spaces
            while (i < s.length() && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Reverse each individual word
            reverse(word.begin(), word.end());

            // Add word to answer if it's non-empty
            if (word.length() > 0) {
                ans += (" " + word);
            }
        }

        // Remove leading space by returning substring from index 1
        return ans.substr(1);
    }
};
```

## Complexity Analysis

- **Reversing the entire string**: `O(n)`
- **Extracting and reversing words**: `O(n)`
- **Concatenating words**: `O(n)`
- **Total Time Complexity**: `O(n)`
- **Space Complexity**: `O(n)` (for storing the reversed words)

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file.
2. Compile using `g++ filename.cpp -o output`.
3. Run the executable `./output`.
4. Provide the string input in the main function for testing.
