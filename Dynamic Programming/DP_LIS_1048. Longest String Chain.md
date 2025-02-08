# Longest String Chain

## Table of Contents

- [Longest String Chain](#longest-string-chain)
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
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)

## Introduction

The problem requires us to find the length of the longest word chain that can be formed from a given list of words. A word chain is a sequence where each word is formed by inserting exactly one letter into the previous word without changing the order of the other characters.

## Problem Description

Given an array of words consisting of lowercase English letters, return the length of the longest possible word chain.

### Examples

#### Example 1

**Input:**

```cpp
words = ["a", "b", "ba", "bca", "bda", "bdca"]
```

**Output:**

```cpp
4
```

**Explanation:** One of the longest word chains is `["a", "ba", "bda", "bdca"]`.

#### Example 2

**Input:**

```cpp
words = ["xbc", "pcxbcf", "xb", "cxbc", "pcxbc"]
```

**Output:**

```cpp
5
```

**Explanation:** The longest word chain is `["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"]`.

#### Example 3

**Input:**

```cpp
words = ["abcd", "dbqca"]
```

**Output:**

```cpp
1
```

**Explanation:** The trivial word chain `["abcd"]` is the longest valid chain.

### Constraints

- `1 <= words.length <= 1000`
- `1 <= words[i].length <= 16`
- `words[i]` consists only of lowercase English letters.

## Approach

1. **Sorting:** Sort the words by their length to ensure that smaller words are considered first.
2. **Dynamic Programming:** Use a DP array where `dp[i]` stores the longest word chain ending at index `i`.
3. **Checking Valid Predecessors:** For each word, check if it can be formed by inserting a character into any shorter word.
4. **Updating the DP Array:** If a valid predecessor is found, update `dp[i]` accordingly.
5. **Finding the Maximum Chain Length:** Track the longest word chain found.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Function to check if string `a` can be formed by adding one character to `b`
    bool checkPossible(const string& a, const string& b) {
        if (a.size() != b.size() + 1)
            return false;

        int first = 0, second = 0;

        while (first < a.size() && second < b.size()) {
            if (a[first] == b[second]) {
                first++;
                second++;
            } else {
                first++;
            }
        }
        return (second == b.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        // Sort words by length
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 1; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (checkPossible(words[i], words[p]) && 1 + dp[p] > dp[i]) {
                    dp[i] = 1 + dp[p];
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};
```

## Complexity Analysis

- **Sorting the words:** `O(n log n)`
- **Checking predecessors:** `O(n^2 * m)`, where `m` is the maximum length of words
- **Overall Time Complexity:** `O(n^2 * m)`
- **Space Complexity:** `O(n)` (for the `dp` array)

## How to Run the Code

### For C++

1. Compile the code using:

   ```sh
   g++ solution.cpp -o solution
   ```

2. Run the executable:

   ```sh
   ./solution
   ```

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        sort(words.begin(), words.end(), [](const auto& a, const auto& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> mp;
        int res = 0;

        for (string& w: words) {
            mp[w] = 1;
            for (int i = 0; i < w.size(); i++) {
                string p = w.substr(0, i) + w.substr(i + 1);
                if (mp.find(p) != mp.end()) {
                    mp[w] = max(mp[w], mp[p] + 1);
                }
            }
        }

        for(auto& x: mp) {
            res = max(res, x.second);
        }

        return res;
    }
};
```
