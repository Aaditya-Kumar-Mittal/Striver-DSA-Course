# Letter Combinations of a Phone Number

## Table of Contents

- [Letter Combinations of a Phone Number](#letter-combinations-of-a-phone-number)
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

This problem involves generating all possible letter combinations of a given digit sequence based on a standard phone keypad mapping. Each digit (2-9) is mapped to a set of letters, and we need to find all possible letter combinations that can be formed from the given digits.

## Problem Description

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. The answer can be returned in any order.

A mapping of digits to letters (just like on telephone buttons) is provided below:

```cpp
2 -> "abc"
3 -> "def"
4 -> "ghi"
5 -> "jkl"
6 -> "mno"
7 -> "pqrs"
8 -> "tuv"
9 -> "wxyz"
```

### Examples

#### Example 1

**Input:**

```cpp
string digits = "23";
```

**Output:**

```cpp
["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"]
```

#### Example 2

**Input:**

```cpp
string digits = "";
```

**Output:**

```cpp
[]
```

#### Example 3

**Input:**

```cpp
string digits = "2";
```

**Output:**

```cpp
["a", "b", "c"]
```

### Constraints

- `0 <= digits.length <= 4`
- `digits[i]` is a digit in the range `['2', '9']`.

## Approach

1. We use a **backtracking approach** to generate all possible letter combinations.
2. We first store the digit-to-letter mappings in an unordered map.
3. We recursively build all possible strings by selecting one letter at a time from each digit's corresponding letter set.
4. If the input is empty, we return an empty list.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<char, string> mpp;

    // Constructor to initialize the digit-letter mapping
    Solution() {
        mpp['2'] = "abc";
        mpp['3'] = "def";
        mpp['4'] = "ghi";
        mpp['5'] = "jkl";
        mpp['6'] = "mno";
        mpp['7'] = "pqrs";
        mpp['8'] = "tuv";
        mpp['9'] = "wxyz";
    }

    void solve(int index, string& s, string& temp, vector<string>& result) {
        if (index >= s.length()) {
            result.push_back(temp);
            return;
        }

        char ch = s[index];
        string str = mpp[ch];
        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);
            solve(index + 1, s, temp, result);
            temp.pop_back(); // Backtracking
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0)
            return {};

        vector<string> result;
        string temp;
        solve(0, digits, temp, result);
        return result;
    }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> combinations = sol.letterCombinations(digits);

    for (string s : combinations) {
        cout << s << " ";
    }
    return 0;
}
```

## Complexity Analysis

- **Time Complexity:** `O(4^N)`, where `N` is the length of `digits`.
  - Each digit can map to at most 4 letters (e.g., '7' and '9').
  - Since there are `N` digits, the worst-case scenario results in `4^N` combinations.
- **Space Complexity:** `O(N)`, due to recursion depth and temporary storage.

## How to Run the Code

### For C++

1. Copy the code into a file, e.g., `main.cpp`.
2. Compile the code using g++:

   ```sh
   g++ main.cpp -o main
   ```

3. Run the executable:

   ```sh
   ./main
   ```

This program will output all possible letter combinations for the given input digits.

---

## Other Solutions

### Solution - 1

```java
public List<String> letterCombinations(String digits) {
  LinkedList<String> ans = new LinkedList<String>();
  if(digits.isEmpty()) return ans;
  String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  ans.add("");
  for(int i =0; i<digits.length();i++){
   int x = Character.getNumericValue(digits.charAt(i));
   while(ans.peek().length()==i){
    String t = ans.remove();
    for(char s : mapping[x].toCharArray())
     ans.add(t+s);
   }
  }
  return ans;
 }
```

```java
public List<String> letterCombinations(String digits) {
  LinkedList<String> ans = new LinkedList<String>();
  if(digits.isEmpty()) return ans;
  String[] mapping = new String[] {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
  ans.add("");
  while(ans.peek().length()!=digits.length()){
   String remove = ans.remove();
   String map = mapping[digits.charAt(remove.length())-'0'];
   for(char c: map.toCharArray()){
    ans.addLast(remove+c);
   }
  }
  return ans;
 }
```
