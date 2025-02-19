# Count Distinct Substrings

## Table of Contents

- [Count Distinct Substrings](#count-distinct-substrings)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Sample Input 1](#sample-input-1)
      - [Sample Output 1](#sample-output-1)
      - [Sample Input 2](#sample-input-2)
      - [Sample Output 2](#sample-output-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

Given a string `S`, we need to determine the number of distinct substrings (including the empty substring) of `S` using a Trie data structure.

## Problem Description

### Examples

#### Sample Input 1

```bash
2
sds
abc
```

#### Sample Output 1

```bash
6
7
```

**Explanation:**

- For `"sds"`, the distinct substrings are: `{ "s", "d", "sd", "ds", "sds", "" }` (6 substrings)
- For `"abc"`, the distinct substrings are: `{ "a", "b", "c", "ab", "bc", "abc", "" }` (7 substrings)

#### Sample Input 2

```bash
2
aa
abab
```

#### Sample Output 2

```bash
3
8
```

**Explanation:**

- For `"aa"`, the distinct substrings are: `{ "a", "aa", "" }` (3 substrings)
- For `"abab"`, the distinct substrings are: `{ "a", "b", "ab", "ba", "aba", "bab", "abab", "" }` (8 substrings)

### Constraints

- `1 <= T <= 5`
- `1 <= |S| <= 10^3`
- `S` consists only of lowercase English letters.
- **Time Limit:** 1 sec

## Approach

1. Use a **Trie (prefix tree)** to store all distinct substrings.
2. Iterate over each suffix of the string and insert all of its prefixes into the Trie.
3. Each time we insert a new character that does not exist in the Trie, it contributes to a new distinct substring.
4. Count all unique insertions and return the result.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Trie Node Structure
struct Node {
    Node* links[26];

    // Check if the character exists in the trie node
    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    // Insert a new character into the trie node
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    // Retrieve the next node for the given character
    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

// Function to count distinct substrings using Trie
int countDistinctSubstrings(string &s) {
    int count = 0;
    Node* root = new Node();

    // Iterate over each suffix of the string
    for (int i = 0; i < s.length(); i++) {
        Node* node = root;

        // Insert all prefixes of the suffix into the Trie
        for (int j = i; j < s.length(); j++) {
            if (!node->containsKey(s[j])) {
                count++; // Increment count for each new substring
                node->put(s[j], new Node());
            }
            node = node->get(s[j]);
        }
    }

    return count + 1; // Adding 1 for the empty substring
}

// Driver function
int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << countDistinctSubstrings(S) << endl;
    }
    return 0;
}
```

## Complexity Analysis

- **Trie Construction:** \(O(N^2)\) (Each suffix contributes to inserting all its prefixes)
- **Trie Insertions:** \(O(1)\) per node (26 characters max)
- **Overall Complexity:** **\(O(N^2)\)**, where `N` is the length of the string.
- **Space Complexity:** **\(O(N^2)\)** (In the worst case, all substrings are distinct, requiring separate nodes).

## How to Run the Code

### For C++

1. Copy the C++ implementation into a `.cpp` file.
2. Compile using:

   ```sh
   g++ filename.cpp -o output
   ```

3. Run the program:

   ```sh
   ./output
   ```

4. Provide input in the specified format.

This solution effectively finds the number of distinct substrings using a Trie with an optimal approach.
