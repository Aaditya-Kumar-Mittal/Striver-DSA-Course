# Implement Trie (Prefix Tree)

## Table of Contents

- [Implement Trie (Prefix Tree)](#implement-trie-prefix-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Usage Example](#usage-example)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Leetcode Submission](#my-leetcode-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)

## Introduction

A **Trie** (pronounced "try") or **Prefix Tree** is a tree-based data structure that is primarily used for efficiently storing and retrieving keys in a dataset of strings. It is widely used for applications such as autocomplete and spell checkers.

## Problem Description

Implement the **Trie** class with the following functions:

- `Trie()`: Initializes the trie.
- `void insert(string word)`: Inserts the string `word` into the trie.
- `bool search(string word)`: Returns `true` if the string `word` is present in the trie.
- `bool startsWith(string prefix)`: Returns `true` if there is any word in the trie that starts with the given prefix.

### Examples

#### Example 1

**Input:**

```cpp
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
```

**Output:**

```cpp
[null, null, true, false, true, null, true]
```

**Explanation:**

```cpp
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
```

### Constraints

- `1 <= word.length, prefix.length <= 2000`
- `word` and `prefix` consist only of lowercase English letters.
- At most `3 * 10^4` calls will be made in total to `insert`, `search`, and `startsWith`.

## Approach

The Trie is implemented using a **linked structure**, where each node contains:

1. An array of 26 pointers (for lowercase English letters `a-z`).
2. A flag `isEnd` to mark the end of a word.
3. Functions to check, insert, retrieve, and mark nodes.

Operations are performed using traversal of the Trie, following these steps:

- **Insertion**: Traverse each character and insert if missing.
- **Search**: Check if all characters exist and if the final node is marked as a word.
- **Prefix Check**: Similar to search but does not require checking `isEnd`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->containsKey(ch)) return false;
            node = node->get(ch);
        }
        return true;
    }
};
```

### Usage Example

```cpp
Trie* obj = new Trie();
obj->insert("apple");
bool param_2 = obj->search("apple");
bool param_3 = obj->startsWith("app");
```

## Complexity Analysis

| Operation  | Time Complexity |
| ---------- | --------------- |
| Insert     | O(N)            |
| Search     | O(N)            |
| StartsWith | O(N)            |

Where `N` is the length of the word being inserted, searched, or checked as a prefix.

## How to Run the Code

1. Compile the code using a C++ compiler (g++ recommended):

   ```sh
   g++ trie.cpp -o trie
   ```

2. Run the compiled executable:

   ```sh
   ./trie
   ```

## Other Solutions

### My Leetcode Submission

```cpp
struct Node {
    Node* links[26];
    bool flag = false;

    bool containsKey(char ch) { return (links[ch - 'a'] != NULL); }
    void put(char ch, Node* node) { links[ch - 'a'] = node; }
    Node* get(char ch) { return links[ch - 'a']; }
    void setEnd() { flag = true; }
    bool isEnd() { return flag; }
};

class Trie {
private:
    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            // Move to the next node in the Trie
            node = node->get(word[i]);
        }
        // Mark the end of the word
        node->setEnd();
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            if (!node->containsKey(word[i]))
                return false;
            node = node->get(word[i]);
        }
        // Check if the current node marks the end of a word
        return node->isEnd();
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            if (!node->containsKey(prefix[i]))
                return false;
            node = node->get(prefix[i]);
        }
        // If we reach here, the prefix exists in the Trie
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

### Solution - 2

```cpp
class TrieNode {
public:
    TrieNode* children[26];
    bool endOfWord;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
        endOfWord = false;
    }
};

class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) {
                curr->children[i] = new TrieNode();
            }
            curr = curr->children[i];
        }
        curr->endOfWord = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char c : word) {
            int i = c - 'a';
            if (!curr->children[i]) {
                return false;
            }
            curr = curr->children[i];
        }
        return curr->endOfWord;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char c : prefix) {
            int i = c - 'a';
            if (!curr->children[i]) {
                return false;
            }
            curr = curr->children[i];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
```

### Solution - 3

```cpp
class TrieNode {
public:
    TrieNode *child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (auto &a : child) a = nullptr;
    }
};
class Trie {
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s) {
        TrieNode *p = root;
        for (auto &a : s) {
            int i = a - 'a';
            if (!p->child[i]) p->child[i] = new TrieNode();
            p = p->child[i];
        }
        p->isWord = true;
    }
    bool search(string key, bool prefix=false) {
        TrieNode *p = root;
        for (auto &a : key) {
            int i = a - 'a';
            if (!p->child[i]) return false;
            p = p->child[i];
        }
        if (prefix==false) return p->isWord;
        return true;
    }
    bool startsWith(string prefix) {
        return search(prefix, true);
    }
};
```
