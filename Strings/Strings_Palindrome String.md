# Palindrome String

## Table of Contents

- [Palindrome String](#palindrome-string)
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

## Introduction

A **palindrome** is a word, phrase, or sequence that reads the same forward and backward, ignoring spaces, punctuation, and capitalization. In this problem, we need to determine if a given string is a palindrome.

## Problem Description

Given a string, determine if it is a palindrome by considering only alphanumeric characters and ignoring case sensitivity. Return `1` if the string is a palindrome and `0` otherwise.

### Examples

#### Example 1

**Input:**

```sh
A man, a plan, a canal: Panama
```

**Output:**

```sh
1
```

**Explanation:**
After removing non-alphanumeric characters and ignoring case, the string becomes `AmanaplanacanalPanama`, which is a palindrome.

#### Example 2

**Input:**

```sh
race a car
```

**Output:**

```sh
0
```

**Explanation:**
After removing non-alphanumeric characters and ignoring case, the string becomes `raceacar`, which is not a palindrome.

### Constraints

- `1 <= |A| <= 10^6`
- The input string consists of printable ASCII characters.

## Approach

1. Use two pointers (`start` and `end`) to traverse the string from both ends.
2. Ignore spaces and special characters using `std::isalnum()`.
3. Convert characters to lowercase using `tolower()`.
4. Compare corresponding characters from the start and end.
5. If a mismatch is found, return `0`.
6. If all characters match, return `1`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
int Solution::isPalindrome(string A) {
    int n = A.length();
    int start = 0, end = n - 1;

    while (start < end) {
        // Ignore non-alphanumeric characters
        if (!std::isalnum(A[start])) {
            start++;
            continue;
        }
        if (!std::isalnum(A[end])) {
            end--;
            continue;
        }

        // Compare lowercase versions of characters
        if (tolower(A[start]) != tolower(A[end]))
            return 0;

        start++;
        end--;
    }
    return 1;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`, where `N` is the length of the string. Each character is processed at most once.
- **Space Complexity:** `O(1)`, as no extra space is used apart from variables.

## How to Run the Code

1. Compile the code using a C++ compiler:

   ```sh
   g++ palindrome.cpp -o palindrome
   ```

2. Run the executable:

   ```sh
   ./palindrome
   ```

3. Provide the input string and check the output.

This solution efficiently checks for a palindrome while handling spaces, special characters, and case insensitivity. 🚀
