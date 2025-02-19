# Complete String

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Complete String](#complete-string)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
        - [Input](#input)
        - [Output](#output)
        - [Explanation](#explanation)
      - [Example 2](#example-2)
        - [Input](#input-1)
        - [Output](#output-1)
        - [Explanation](#explanation-1)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Compilation \& Execution](#compilation--execution)
    - [Sample Input](#sample-input)
    - [Sample Output](#sample-output)

## Introduction

The problem requires us to determine the longest string in a given list of strings such that every prefix of that string is also present in the list. If multiple strings meet this condition, we return the lexicographically smallest one. If no such string exists, we return "None".

## Problem Description

Given an array `A` of `N` strings, each element is a lowercase English letter string. We need to determine the longest valid "complete string" from the array.

A string is considered a complete string if **all its prefixes exist in the given array**.

If multiple strings have the same length, we return the lexicographically smallest one.

If no such string exists, return "None".

### Examples

#### Example 1

##### Input

```bash
N = 4
A = ["ab", "abc", "a", "bp"]
```

##### Output

```bash
abc
```

##### Explanation

- The prefixes of "abc" (`"a"`, `"ab"`, `"abc"`) exist in `A`, so it is a complete string.
- The longest valid complete string is "abc".

#### Example 2

##### Input

```bash
N = 2
A = ["ab", "bc"]
```

##### Output

```bash
None
```

##### Explanation

- The prefix "a" of "ab" is missing, and "b" of "bc" is missing.
- No valid complete string exists.

### Constraints

- `1 <= T <= 10`
- `1 <= N <= 10^5`
- `1 <= A[i].length <= 10^5`
- `A[i]` consists only of lowercase English letters.
- The sum of all string lengths across test cases does not exceed `10^5`.
- **Time Limit:** `1 sec`

## Approach

1. **Use a Trie Data Structure:**

   - Insert all words into a Trie.
   - Each node represents a character, and we store whether it marks the end of a valid word.

2. **Check Each String for Validity:**
   - A string is valid if all its prefixes exist as complete words in the Trie.
   - Keep track of the longest valid string.
   - If two strings are of the same length, choose the lexicographically smaller one.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch) {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node) {
        links[ch - 'a'] = node;
    }

    Node *get(char ch) {
        return links[ch - 'a'];
    }

    void setEnd() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

class Trie {
private:
    Node *root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node *node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }

    bool checkIfPrefixExists(string word) {
        Node *node = root;
        for (char ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->get(ch);
            if (!node->isEnd()) {
                return false;
            }
        }
        return true;
    }
};

string completeString(int n, vector<string> &a) {
    Trie trie;
    for (string &s : a) {
        trie.insert(s);
    }

    string longestStr = "";
    for (string &s : a) {
        if (trie.checkIfPrefixExists(s)) {
            if (s.length() > longestStr.length() || (s.length() == longestStr.length() && s < longestStr)) {
                longestStr = s;
            }
        }
    }

    return longestStr.empty() ? "None" : longestStr;
}
```

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  Node *links[26];
  bool flag = false;

  bool containsKey(char ch)
  {
    return (links[ch - 'a'] != NULL);
  }

  void put(char ch, Node *node)
  {
    links[ch - 'a'] = node;
  }

  Node *get(char ch)
  {
    return links[ch - 'a'];
  }

  void setEnd()
  {
    flag = true;
  }

  bool isEnd()
  {
    return flag;
  }
};

class Trie
{
private:
  Node *root;

public:
  /** Initialize your data structure here. */
  Trie()
  {
    root = new Node();
  }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        node->put(word[i], new Node());
      }
      node = node->get(word[i]);
    }
    node->setEnd();
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return false;
      }
      node = node->get(word[i]);
    }
    return node->isEnd();
  }

  /** Returns if there is any word in the trie that starts with the given prefix. */
  bool startsWith(string prefix)
  {
    Node *node = root;
    for (int i = 0; i < prefix.length(); i++)
    {
      if (!node->containsKey(prefix[i]))
      {
        return false;
      }
      node = node->get(prefix[i]);
    }
    return true;
  }

  /** Checks if all prefixes of a word exist in the trie. */
  bool checkIfPrefixExists(string word)
  {
    Node *node = root;
    for (int i = 0; i < word.length(); i++)
    {
      if (!node->containsKey(word[i]))
      {
        return false;
      }
      node = node->get(word[i]);
      if (!node->isEnd())
      {
        return false;
      }
    }
    return true;
  }
};

string completeString(int n, vector<string> &a)
{
  Trie trie;

  // Insert all words into the trie
  for (string &s : a)
  {
    trie.insert(s);
  }

  string longestStr = "";

  // Check each word to see if all its prefixes exist
  for (string &s : a)
  {
    if (trie.checkIfPrefixExists(s))
    {
      if (s.length() > longestStr.length())
      {
        longestStr = s;
      }
      else if (s.length() == longestStr.length() && s < longestStr)
      {
        longestStr = s;
      }
    }
  }

  if (longestStr.empty())
  {
    return "None";
  }
  return longestStr;
}
```

## Complexity Analysis

- **Trie Insertion:** `O(M)`, where `M` is the length of the word.
- **Checking Prefixes:** `O(M)`, where `M` is the length of the longest string.
- **Overall Complexity:** `O(N * M)`, which is efficient for the given constraints.

## How to Run the Code

### Compilation & Execution

```sh
g++ -std=c++17 complete_string.cpp -o complete_string
./complete_string
```

### Sample Input

```bash
2
6
n ni nin ninj ninja ninga
2
ab bc
```

### Sample Output

```bash
ninja
None
```
