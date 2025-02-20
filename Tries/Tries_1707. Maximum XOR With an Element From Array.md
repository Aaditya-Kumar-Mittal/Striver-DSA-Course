# Maximum XOR With an Element From Array

## Table of Contents

- [Maximum XOR With an Element From Array](#maximum-xor-with-an-element-from-array)
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
    - [Compilation and Execution](#compilation-and-execution)
    - [Input Example](#input-example)
    - [Output Example](#output-example)

## Introduction

The problem requires finding the maximum bitwise XOR of a given `xi` from the query list and an element from an array `nums` such that the selected element does not exceed `mi`.

## Problem Description

Given:

- An array `nums` of non-negative integers.
- A query list `queries`, where `queries[i] = [xi, mi]`.

For each query, find the maximum XOR value of `xi` with any element in `nums` that is `≤ mi`. If no such element exists, return `-1`.

### Examples

#### Example 1

**Input:**

```cpp
nums = [0,1,2,3,4];
queries = [[3,1],[1,3],[5,6]];
```

**Output:**

```cpp
[3,3,7]
```

#### Example 2

**Input:**

```cpp
nums = [5,2,4,6,6,3];
queries = [[12,4],[8,1],[6,3]];
```

**Output:**

```cpp
[15,-1,5]
```

### Constraints

- `1 <= nums.length, queries.length <= 10^5`
- `queries[i].length == 2`
- `0 <= nums[j], xi, mi <= 10^9`

## Approach

1. **Sorting:**
   - Sort `nums` in ascending order.
   - Process queries in increasing order of `mi`.
2. **Trie Data Structure:**

   - Insert numbers from `nums` into a binary trie as long as they satisfy `nums[j] ≤ mi`.
   - Use a Trie-based approach to find the maximum XOR for `xi`.

3. **Offline Query Processing:**
   - Sort the queries based on `mi`.
   - Maintain a pointer to track elements inserted into the Trie.
   - Process each query by finding the maximum XOR value using the Trie.

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

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> oQ;
        int q = queries.size();

        for (int i = 0; i < q; i++) {
            oQ.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(oQ.begin(), oQ.end());

        vector<int> ans(q, -1);
        Trie trie;
        int index = 0;
        int n = nums.size();

        for (int i = 0; i < q; i++) {
            int ai = oQ[i].first;
            int xi = oQ[i].second.first;
            int qInd = oQ[i].second.second;

            while (index < n && nums[index] <= ai) {
                trie.insert(nums[index]);
                index++;
            }

            if (index == 0) {
                ans[qInd] = -1;
            } else {
                ans[qInd] = trie.getMax(xi);
            }
        }
        return ans;
    }
};
```

## Complexity Analysis

| Operation              | Complexity                           |
| ---------------------- | ------------------------------------ |
| Sorting `nums`         | O(N log N)                           |
| Sorting `queries`      | O(Q log Q)                           |
| Trie insertion         | O(N log M) (M = max value in `nums`) |
| Trie query             | O(Q log M)                           |
| **Overall Complexity** | O((N + Q) log M)                     |

## How to Run the Code

### Compilation and Execution

```sh
g++ -std=c++17 filename.cpp -o output
./output
```

### Input Example

```cpp
vector<int> nums = {5,2,4,6,6,3};
vector<vector<int>> queries = {{12,4},{8,1},{6,3}};
Solution sol;
vector<int> result = sol.maximizeXor(nums, queries);
```

### Output Example

```cpp
[15,-1,5]
```

This solution efficiently handles the problem using sorting and Trie data structures while maintaining an optimal time complexity.
