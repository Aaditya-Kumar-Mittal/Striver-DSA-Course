# Reverse String

## Table of Contents

- [Reverse String](#reverse-string)
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
    - [For C++](#for-c)

## Introduction

The problem requires reversing a given string, which is provided as an array of characters. The reversal must be done **in-place** with **O(1) extra memory**.

## Problem Description

Given an array of characters `s`, reverse the order of the characters in place.

### Examples

#### Example 1

**Input:**  
`s = ['h','e','l','l','o']`

**Output:**  
`['o','l','l','e','h']`

#### Example 2

**Input:**  
`s = ['H','a','n','n','a','h']`

**Output:**  
`['h','a','n','n','a','H']`

### Constraints

- `1 <= s.length <= 10^5`
- `s[i]` is a printable ASCII character.

## Approach

1. **Two-Pointer Technique**:

   - Use two pointers: one at the beginning (`start`) and one at the end (`end`).
   - Swap the elements at `start` and `end` and move the pointers towards each other.
   - Continue until `start` crosses `end`.

2. **In-Place Modification**:
   - The reversal must be done without using extra space (`O(1) space complexity`).
3. **Iterative Swapping**:
   - Instead of using an auxiliary array, elements are swapped directly within the given input array.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size() - 1;
        while (start < end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

// Driver Code
int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    Solution sol;
    sol.reverseString(s);

    // Output the reversed string
    for (char c : s) {
        cout << c << " ";
    }
    return 0;
}
```

## Complexity Analysis

- **Time Complexity**: `O(N)` - Since we traverse the array once, performing `N/2` swaps.
- **Space Complexity**: `O(1)` - No extra space is used; modifications happen in place.

## How to Run the Code

### For C++

1. Copy the provided C++ code into a file (e.g., `reverse_string.cpp`).
2. Compile using `g++ reverse_string.cpp -o reverse_string`.
3. Run the executable: `./reverse_string`.
4. Observe the reversed character array output.

This method efficiently reverses a string in **O(N) time** with **O(1) space** using the **two-pointer technique**.
