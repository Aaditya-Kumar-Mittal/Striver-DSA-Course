# Remove Outermost Parentheses

## Table of Contents

- [Remove Outermost Parentheses](#remove-outermost-parentheses)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Counting Approach](#counting-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem requires us to remove the **outermost parentheses** from each **primitive valid parentheses string** in a given valid parentheses string.

## Problem Description

Given a valid parentheses string `s`, return `s` after removing the outermost parentheses of every primitive string in its primitive decomposition.

### Examples

#### Example 1

**Input:**

```cpp
s = "(()())(())"
```

**Output:**

```cpp
"()()()"
```

**Explanation:** The input string is `"(()())(())"`, with primitive decomposition `"(()())" + "(())"`. After removing outer parentheses of each part, this results in `"()()" + "()" = "()()()"`.

#### Example 2

**Input:**

```cpp
s = "(()())(())(()(()))"
```

**Output:**

```cpp
"()()()()(())"
```

**Explanation:** The input string is `"(()())(())(()(()))"`, with primitive decomposition `"(()())" + "(())" + "(()(()))"`. After removing outer parentheses, this results in `"()()" + "()" + "()(())" = "()()()()(())"`.

#### Example 3

**Input:**

```cpp
s = "()()"
```

**Output:**

```cpp
""
```

**Explanation:** The input string is `"()()"`, with primitive decomposition `"()" + "()"`. After removing outer parentheses, this results in `"" + "" = ""`.

### Constraints

- `1 <= s.length <= 10^5`
- `s[i]` is either `'('` or `')'`.
- `s` is a valid parentheses string.

## Approach

### Counting Approach

1. Initialize a `count` variable to track the balance of parentheses.
2. Iterate through the string:
   - If encountering `')'`, decrement `count`.
   - If `count` is not zero, append the character to the result.
   - If encountering `'('`, increment `count`.
3. Return the final result string.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count = 0;
        string ans = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ')')
                count--;
            if (count != 0)
                ans.push_back(s[i]);
            if (s[i] == '(')
                count++;
        }

        return ans;
    }
};

// Driver Code
int main() {
    Solution solution;
    string s = "(()())(())";
    cout << "Output: " << solution.removeOuterParentheses(s) << endl;
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(N)`, where `N` is the length of the string. We iterate through `s` once.
- **Space Complexity:** `O(N)`, as we store the result string.

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `remove_outer_parentheses.cpp`.
2. Compile the code using a C++ compiler:

   ```sh
   g++ remove_outer_parentheses.cpp -o remove_outer_parentheses
   ```

3. Run the executable:

   ```sh
   ./remove_outer_parentheses
   ```
