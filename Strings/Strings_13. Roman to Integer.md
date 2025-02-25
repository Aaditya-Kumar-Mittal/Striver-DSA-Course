# Roman to Integer

## Table of Contents

- [Roman to Integer](#roman-to-integer)
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
    - [Solution - 2](#solution---2)

---

## Introduction

Roman numerals are represented using seven symbols:

| Symbol | Value |
| ------ | ----- |
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

Numbers are generally written from largest to smallest. However, for certain numbers like 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD), and 900 (CM), subtraction is used.

Given a valid Roman numeral (1 ≤ value ≤ 3999), the goal is to convert it into an integer.

---

## Problem Description

### Examples

#### Example 1

🔹 Input: `s = "III"`  
🔹 Output: `3`  
🔹 Explanation: `III = 1 + 1 + 1 = 3`

#### Example 2

🔹 Input: `s = "LVIII"`  
🔹 Output: `58`  
🔹 Explanation: `L = 50, V = 5, III = 3 → 50 + 5 + 3 = 58`

#### Example 3

🔹 Input: `s = "MCMXCIV"`  
🔹 Output: `1994`  
🔹 Explanation: `M = 1000, CM = 900, XC = 90, IV = 4 → 1000 + 900 + 90 + 4 = 1994`

---

## Constraints

- `1 <= s.length <= 15`
- `s` contains only the characters `('I', 'V', 'X', 'L', 'C', 'D', 'M')`.
- It is guaranteed that `s` is a valid Roman numeral in the range `[1, 3999]`.

---

## Approach

1. Use a Hash Map (`unordered_map`)

   - Store the values of each Roman numeral.

2. Traverse the String (`s`)

   - If current numeral is smaller than the next numeral → subtract its value.
   - Otherwise, add its value to the total sum.

3. Return the computed integer.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> romans{
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int value = 0;

        for (int i = 0; i < s.length(); i++) {
            // If current numeral is smaller than the next one, subtract it
            if (i < s.length() - 1 && romans[s[i]] < romans[s[i + 1]]) {
                value -= romans[s[i]];
            } else {
                value += romans[s[i]];
            }
        }

        return value;
    }
};

// Driver code
int main() {
    Solution sol;
    cout << sol.romanToInt("III") << endl;      // Output: 3
    cout << sol.romanToInt("LVIII") << endl;    // Output: 58
    cout << sol.romanToInt("MCMXCIV") << endl;  // Output: 1994
    return 0;
}
```

---

## Complexity Analysis

- Time Complexity: `O(n)`, where `n` is the length of the Roman numeral string.
  - Each character is processed once in a single pass.
- Space Complexity: `O(1)`, since only a fixed hash map is used for numeral mappings.

---

## How to Run the Code

### For C++

1️⃣ Compile the code:

```bash
g++ -o roman_to_integer roman_to_integer.cpp
```

2️⃣ Run the executable:

```bash
./roman_to_integer
```

## Other Solutions

### Solution - 1

```cpp
class Solution
{
public:
  int romanToInt(string s)
  {
    int value[26] = {0}; // Initialize the array with zeros
    value['I' - 'A'] = 1;
    value['V' - 'A'] = 5;
    value['X' - 'A'] = 10;
    value['L' - 'A'] = 50;
    value['C' - 'A'] = 100;
    value['D' - 'A'] = 500;
    value['M' - 'A'] = 1000;

    int result = 0;

    for (int i = 0; i < s.length(); i++)
    {
      int curr = value[s[i] - 'A'];
      int next = (i + 1 < s.length()) ? value[s[i + 1] - 'A'] : 0;

      if (curr < next)
      {
        result -= curr; // Subtract if next numeral is larger (e.g., IV, IX)
      }
      else
      {
        result += curr; // Otherwise, add
      }
    }
    return result;
  }
};
```

### Solution - 2

```cpp
class Solution
{
public:
  int char2num(char a)
  {
    switch (a)
    {
    case 'I':
      return 1;
    case 'V':
      return 5;
    case 'X':
      return 10;
    case 'L':
      return 50;
    case 'C':
      return 100;
    case 'D':
      return 500;
    case 'M':
      return 1000;
    default:
      return 0;
    }
  }

  int romanToInt(string s)
  {
    int result = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (i + 1 < s.length() && char2num(s[i]) < char2num(s[i + 1]))
      {
        result -= char2num(s[i]);
      }
      else
      {
        result += char2num(s[i]);
      }
    }
    return result;
  }
};
```
