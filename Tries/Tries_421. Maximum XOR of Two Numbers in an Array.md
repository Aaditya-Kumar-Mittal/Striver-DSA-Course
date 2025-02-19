# Maximum XOR of Two Numbers in an Array

## Table of Contents

- [Maximum XOR of Two Numbers in an Array](#maximum-xor-of-two-numbers-in-an-array)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Using Trie (Prefix Tree)](#using-trie-prefix-tree)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem requires us to find the maximum XOR value possible between any two numbers in a given integer array `nums`. XOR (Exclusive OR) operation returns `1` when the bits of operands are different and `0` otherwise. We need an efficient way to maximize this value.

## Problem Description

Given an integer array `nums`, return the maximum result of `nums[i] XOR nums[j]` where `0 <= i <= j < n`.

### Examples

#### Example 1

**Input:**

```cpp
nums = [3,10,5,25,2,8]
```

**Output:**

```cpp
28
```

**Explanation:**

- The maximum XOR is achieved by `5 XOR 25 = 28`.

#### Example 2

**Input:**

```cpp
nums = [14,70,53,83,49,91,36,80,92,51,66,70]
```

**Output:**

```cpp
127
```

### Constraints

- `1 <= nums.length <= 2 * 10^5`
- `0 <= nums[i] <= 2^31 - 1`

## Approach

### Using Trie (Prefix Tree)

1. **Insert Numbers into Trie:**
   - Each number is represented in its 32-bit binary form.
   - We construct a **Trie** where each bit of the number represents a node.
2. **Finding Maximum XOR:**
   - For each number, we try to find the number in the Trie that maximizes its XOR.
   - We always attempt to take the opposite bit (`1-bit`) to maximize the XOR result.
   - If the opposite bit is not present, we proceed with the same bit.

Using a Trie allows us to efficiently store and query binary numbers to find the maximum XOR.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Definition of TrieNode
struct TrieNode {
    TrieNode* links[2];

    bool containsKey(int bit) { return (links[bit] != nullptr); }

    TrieNode* get(int bit) { return links[bit]; }

    void put(int bit, TrieNode* node) { links[bit] = node; }
};

// Trie Data Structure
class Trie {
private:
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new TrieNode());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num) {
        TrieNode* node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxNum |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

// Solution Class
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        for (int num : nums) {
            trie.insert(num);
        }
        int maxXor = 0;
        for (int num : nums) {
            maxXor = max(maxXor, trie.getMax(num));
        }
        return maxXor;
    }
};
```

## Complexity Analysis

| Operation                   | Time Complexity    |
| --------------------------- | ------------------ |
| Insertion into Trie         | `O(32 * N) ≈ O(N)` |
| Query (Finding Maximum XOR) | `O(32 * N) ≈ O(N)` |
| Overall Complexity          | `O(N)`             |

- The Trie stores numbers in a 32-bit format.
- Each number insertion or lookup takes at most `32` operations.
- Given `N` numbers, the total complexity remains **O(N)**.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `max_xor_trie.cpp`.
2. Compile using:

   ```sh
   g++ -std=c++17 max_xor_trie.cpp -o max_xor
   ```

3. Run the executable:

   ```sh
   ./max_xor
   ```

This will compute the maximum XOR of an array using a Trie efficiently.

---

This documentation provides a structured explanation of the **Maximum XOR of Two Numbers in an Array** problem, including approach, implementation, and analysis.
