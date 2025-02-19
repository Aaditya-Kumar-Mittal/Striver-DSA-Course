# Implement Trie II

## Table of Contents

- [Implement Trie II](#implement-trie-ii)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Sample Input 1](#sample-input-1)
      - [Sample Output 1](#sample-output-1)
      - [Explanation](#explanation)
      - [Sample Input 2](#sample-input-2)
      - [Sample Output 2](#sample-output-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)

## Introduction

Trie (pronounced as "try") is a tree-based data structure used for storing strings efficiently. Unlike other data structures like hash tables and binary search trees, Trie provides fast retrieval and insertion of words, making it useful for applications like autocomplete, dictionary word searches, and spell checkers.

In this implementation, we enhance the basic Trie structure by adding functionalities to count the occurrences of words and prefixes, as well as efficiently erase words from the Trie.

## Problem Description

We need to implement a Trie data structure that supports the following operations:

1. **Trie()** - Initialize an empty Trie.
2. **insert("WORD")** - Insert the string `WORD` into the Trie.
3. **countWordsEqualTo("WORD")** - Return the number of times `WORD` is present in the Trie.
4. **countWordsStartingWith("PREFIX")** - Return the number of words in the Trie that start with `PREFIX`.
5. **erase("WORD")** - Remove one occurrence of `WORD` from the Trie.

### Examples

#### Sample Input 1

```bash
1
5
insert coding
insert ninja
countWordsEqualTo coding
countWordsStartingWith nin
erase coding
```

#### Sample Output 1

```bash
1
1
```

#### Explanation

- "coding" is inserted.
- "ninja" is inserted.
- "coding" appears once, so output is 1.
- Words starting with "nin" ("ninja") exist, so output is 1.
- "coding" is erased.

#### Sample Input 2

```bash
1
6
insert samsung
insert samsung
insert vivo
erase vivo
countWordsEqualTo samsung
countWordsStartingWith vi
```

#### Sample Output 2

```bash
2
0
```

### Constraints

- `1 ≤ T ≤ 50` (Number of test cases)
- `1 ≤ N ≤ 10^4` (Number of operations per test case)
- `1 ≤ |WORD| ≤ 1000` (Length of each word)
- All words contain lowercase English letters (`a-z`).
- `erase("WORD")` is only called if `WORD` is guaranteed to be present in the Trie.

## Approach

We use a **TrieNode** structure to represent each character node in the Trie. Each node contains:

- An array `links[26]` to store pointers to child nodes.
- An integer `countEndsWith` to track how many times a word ends at that node.
- An integer `countPrefix` to track how many words pass through that node.

For each operation:

- **Insert**: Traverse the Trie, create missing nodes, and update `countPrefix` and `countEndsWith`.
- **Search for exact words**: Traverse the Trie and check `countEndsWith` at the last character.
- **Search for words with a given prefix**: Traverse the Trie and return `countPrefix` at the last prefix character.
- **Erase**: Traverse the Trie, decrement `countPrefix`, and finally reduce `countEndsWith` to remove one instance of the word.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *links[26];
    int countEndsWith = 0;
    int countPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode *get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode *node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        countEndsWith++;
    }

    void increasePrefix() {
        countPrefix++;
    }

    void reduceEnd() {
        countEndsWith--;
    }

    void reducePrefix() {
        countPrefix--;
    }

    int getEndCount() {
        return countEndsWith;
    }

    int getPrefixCount() {
        return countPrefix;
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new TrieNode());
            }
            node = node->get(ch);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getEndCount();
    }

    int countWordsStartingWith(string &prefix) {
        TrieNode *node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return 0;
            node = node->get(ch);
        }
        return node->getPrefixCount();
    }

    void erase(string &word) {
        TrieNode *node = root;
        for (char ch : word) {
            node = node->get(ch);
            node->reducePrefix();
        }
        node->reduceEnd();
    }
};
```

## Complexity Analysis

| Operation                 | Time Complexity |
| ------------------------- | --------------- |
| Insert a word             | O (WORD)        |
| Count words equal to WORD | O (WORD)        |
| Count words with PREFIX   | O (PREFIX)      |
| Erase a word              | O (WORD)        |

Each operation runs in **O(n)** time complexity, where **n** is the length of the word or prefix. Since we process at most 10,000 operations, our approach is efficient for large datasets.

## How to Run the Code

1. Copy the provided C++ code into a file (e.g., `trie.cpp`).
2. Compile the code using:

   ```sh
   g++ -o trie trie.cpp
   ```

3. Run the compiled executable:

   ```sh
   ./trie
   ```

4. Provide the input as per the given format.

---

This documentation provides a structured breakdown of the problem, solution, implementation, and complexity analysis. Let me know if you need any modifications! 🚀
