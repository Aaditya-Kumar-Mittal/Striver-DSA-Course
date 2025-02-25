# Longest Common Prefix

## Table of Contents

- [Longest Common Prefix](#longest-common-prefix)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Sorting-Based Approach](#sorting-based-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem requires us to find the **longest common prefix** among an array of strings. If no common prefix exists, we return an empty string.

## Problem Description

Given an array of strings `strs`, return the longest common prefix among all strings. If there is none, return `""`.

### Examples

#### Example 1

**Input:**

```cpp
strs = ["flower","flow","flight"]
```

**Output:**

```cpp
"fl"
```

#### Example 2

**Input:**

```cpp
strs = ["dog","racecar","car"]
```

**Output:**

```cpp
""
```

**Explanation:** There is no common prefix among the input strings.

### Constraints

- `1 <= strs.length <= 200`
- `0 <= strs[i].length <= 200`
- `strs[i]` consists of only lowercase English letters if it is non-empty.

## Approach

### Sorting-Based Approach

1. Sort the array of strings lexicographically.
2. Compare the first and last strings (as they are the most different after sorting).
3. Find the longest common prefix by comparing characters one by one.
4. Stop when a mismatch is found or the end of a string is reached.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string ans = "";
        int n = strs.size();

        for (int i = 0; i < strs[0].length(); i++) {
            if (strs[0][i] != strs[n - 1][i])
                break;
            else {
                ans += strs[0][i];
            }
        }
        return ans;
    }
};

// Driver Code
int main() {
    Solution solution;
    vector<string> strs = {"flower", "flow", "flight"};
    cout << "Longest Common Prefix: " << solution.longestCommonPrefix(strs) << endl;
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N log N + M)`, where `N` is the number of strings and `M` is the length of the shortest string.
  - Sorting takes `O(N log N)`.
  - The prefix comparison takes `O(M)`.
- **Space Complexity:** `O(1)`, as no additional space is used apart from a few variables.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `longest_common_prefix.cpp`.
2. Compile the code using a C++ compiler:

   ```sh
   g++ longest_common_prefix.cpp -o longest_common_prefix
   ```

3. Run the executable:

   ```sh
   ./longest_common_prefix
   ```
