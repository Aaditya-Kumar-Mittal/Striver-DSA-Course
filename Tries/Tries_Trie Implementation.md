# Trie Implementation

## Table of Contents

- [Trie Implementation](#trie-implementation)
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

## Introduction

Trie is a tree-like data structure that efficiently stores and retrieves keys in a dataset of strings. This data structure provides fast search, insert, and prefix checking operations.

## Problem Description

Implement a Trie Data Structure that supports the following three operations:

1. **insert(word)** - Inserts a string `word` into the Trie.
2. **search(word)** - Checks if the string `word` exists in the Trie.
3. **startsWith(prefix)** - Checks if there exists a word in the Trie that starts with `prefix`.

### Examples

#### Sample Input 1

```bash
5
insert coding
insert ninjas
search coding
search ninja
startWith ninja
```

#### Sample Output 1

```bash
null
null
true
false
true
```

#### Sample Input 2

```bash
3
insert book
search books
startWith b
```

#### Sample Output 2

```bash
null
false
true
```

### Constraints

- \(1 \leq Q \leq 10^4\)
- \(1 \leq \text{length of WORD} \leq 2000\)

## Approach

We implement the Trie using a **TrieNode** class. Each TrieNode has an array of 26 pointers, one for each lowercase English letter, and a boolean `isEnd` to mark the end of a word.

Operations are implemented as follows:

1. **Insert**: Traverse the Trie while inserting characters. If a character is missing, create a new TrieNode.
2. **Search**: Traverse the Trie and check if the word exists and ends correctly.
3. **StartsWith**: Traverse the Trie and verify if the prefix exists.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;
    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == NULL) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children[c - 'a'] == NULL) return false;
            node = node->children[c - 'a'];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children[c - 'a'] == NULL) return false;
            node = node->children[c - 'a'];
        }
        return true;
    }
};

```

```cpp
#include <bits/stdc++.h>

struct TrieNode {
    TrieNode* links[26];
    int countEndsWith = 0;
    int countPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    TrieNode* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, TrieNode* node) {
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
    TrieNode* root;

public:
    Trie() {
        // Initialize root to a new TrieNode
        root = new TrieNode();
    }

    void insert(string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new TrieNode());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getEndCount();
    }

    int countWordsStartingWith(string& word) {
        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (node->containsKey(word[i])) {
                node = node->get(word[i]);
            } else {
                return 0;
            }
        }
        return node->getPrefixCount();
    }

    void erase(string& word) {
        // Check if the word exists in the Trie
        if (countWordsEqualTo(word) == 0) {
            return; // Word does not exist, nothing to erase
        }

        TrieNode* node = root;
        for (int i = 0; i < word.length(); i++) {
            node = node->get(word[i]);
            node->reducePrefix();
        }
        node->reduceEnd();
    }
};
```

## Complexity Analysis

- **Insert Operation:** \(O(L)\), where `L` is the length of the word.
- **Search Operation:** \(O(L)\)
- **StartsWith Operation:** \(O(L)\)

Total space complexity is **O(N \* L)**, where `N` is the number of words inserted.

## How to Run the Code

- Compile the program using a C++ compiler:

  ```bash
  g++ -o trie trie.cpp
  ```

- Run the program:

  ```bash
  ./trie
  ```
