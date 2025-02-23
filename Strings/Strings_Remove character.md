# Remove Character

## Table of Contents

- [Remove Character](#remove-character)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)

## Introduction

The problem requires us to remove all occurrences of a given character from a given string while maintaining the order of the remaining characters. If the given character does not exist in the input string, the string remains unchanged.

## Problem Description

We are given:

- A string `str`.
- A character `X` that needs to be removed from `str`.

Our task is to return the string after removing all occurrences of `X`.

### Examples

#### Example 1

**Input:**

```sh
aabccbaa a
```

**Output:**

```sh
bccb
```

**Explanation:**
All occurrences of 'a' are removed from the string `aabccbaa`, resulting in `bccb`.

#### Example 2

**Input:**

```sh
xxyyzxx y
```

**Output:**

```sh
xxzxx
```

**Explanation:**
All occurrences of 'y' are removed from the string `xxyyzxx`, resulting in `xxzxx`.

### Constraints

- `0 <= N <= 10^6` (Where `N` is the length of the input string)
- Time Limit: `1 second`

## Approach

1. **Use Two Pointers:**
   - Maintain a pointer `i` to keep track of the position where the next valid character should be placed.
   - Iterate over the string using another pointer `j`.
   - If `input[j]` is equal to the character `c`, skip that character.
   - Otherwise, store `input[j]` at `input[i]` and increment `i`.
2. **Clear Remaining Characters:**
   - Since we are modifying the string in-place, set the remaining part of the string to `NULL` after `i`.

## Detailed Explanation of Code

### C Implementation

```c
#include <stdio.h>
#include <string.h>

void removeAllOccurrencesOfChar(char input[], char c) {
    int i = 0;
    for (int j = 0; j < strlen(input); j++) {
        if (input[j] == c) continue; // Skip occurrences of 'c'
        input[i] = input[j]; // Copy valid characters
        i++;
    }
    // Null terminate the remaining part of the string
    for (int j = i; j < strlen(input); j++) {
        input[j] = 0;
    }
}

int main() {
    char str[] = "aabccbaa";
    char ch = 'a';
    removeAllOccurrencesOfChar(str, ch);
    printf("%s\n", str);
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`, where `N` is the length of the input string, as we traverse the string once.
- **Space Complexity:** `O(1)`, as we modify the input string in-place without using extra space.

## How to Run the Code

1. Copy the above C code into a file, say `remove_char.c`.
2. Compile the code using:

   ```sh
   gcc remove_char.c -o remove_char
   ```

3. Run the executable:

   ```sh
   ./remove_char
   ```

4. The output will be displayed in the console.

This implementation efficiently removes all occurrences of the given character while maintaining the order of the remaining characters.
