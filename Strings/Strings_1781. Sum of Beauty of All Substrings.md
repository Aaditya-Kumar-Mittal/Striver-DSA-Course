# Sum of Beauty of All Substrings

## Table of Contents

- [Sum of Beauty of All Substrings](#sum-of-beauty-of-all-substrings)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Explanation](#explanation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In this problem, we are asked to compute the sum of the beauty of all substrings of a given string `s`. The beauty of a string is defined as the difference between the frequency of the most frequent character and the least frequent character in that string.

This task involves iterating over all possible substrings of `s` and calculating the beauty of each, then summing them up.

---

## Problem Description

You are given a string `s` consisting only of lowercase English letters. The beauty of a string is calculated as:

```sh
beauty = max_frequency - min_frequency
```

Where:

- `max_frequency` is the frequency of the most frequent character in the string.
- `min_frequency` is the frequency of the least frequent character in the string.

You need to return the sum of the beauty of all substrings of the given string.

### Examples

**Example 1:**

```bash
Input: s = "aabcb"
Output: 5
Explanation: The substrings with non-zero beauty are ["aab","aabc","aabcb","abcb","bcb"], each with beauty equal to 1.
```

**Example 2:**

```bash
Input: s = "aabcbaa"
Output: 17
```

### Constraints

- `1 <= s.length <= 500`
- `s` consists of only lowercase English letters.

---

## Approach

To solve this problem, the strategy involves the following steps:

1. **Iterate over all substrings**: We will generate all possible substrings of the given string `s`.
2. **Calculate the frequency of characters**: For each substring, we calculate the frequency of each character in that substring.
3. **Calculate the beauty**: For each substring, we compute the beauty as the difference between the highest and lowest non-zero character frequencies.
4. **Sum the beauties**: We accumulate the beauty for each substring into a total sum.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Function to find the minimum frequency of non-zero character occurrences
    int getMinCount(vector<int>& freq) {
        int minCount = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                minCount = min(minCount, freq[i]);
            }
        }
        return minCount;
    }

    // Function to find the maximum frequency of character occurrences
    int getMaxCount(vector<int>& freq) {
        int maxCount = INT_MIN;
        for (int i = 0; i < 26; i++) {
            maxCount = max(maxCount, freq[i]);
        }
        return maxCount;
    }

    // Function to calculate the sum of beauty of all substrings
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            vector<int> freq(26); // Array to store frequency of characters
            for (int j = i; j < n; j++) {
                freq[s[j] - 'a']++; // Update frequency of character at position j
                int beauty = getMaxCount(freq) - getMinCount(freq); // Calculate beauty of the current substring
                sum += beauty; // Add beauty to the sum
            }
        }
        return sum; // Return the total sum of beauties
    }
};
```

### Explanation

1. **`getMinCount` function**:
   - This function calculates the minimum frequency of characters in the `freq` array (which stores the frequency of each character from 'a' to 'z'). We ignore characters with zero frequency.

2. **`getMaxCount` function**:
   - This function calculates the maximum frequency of characters in the `freq` array.

3. **`beautySum` function**:
   - This function is the main driver of the algorithm. It iterates over all possible substrings of `s` by fixing the starting index `i` and iterating through the substring end at index `j`.
   - For each substring, it updates the frequency of characters in the `freq` array and calculates the beauty as the difference between the maximum and minimum frequencies.

---

## Complexity Analysis

### Time Complexity

- **O(n^2)**: The function iterates through all possible substrings. For each substring, it calculates the maximum and minimum frequencies in O(26) time, where 26 is the number of lowercase letters. Thus, the time complexity is O(n^2), where `n` is the length of the string `s`.

### Space Complexity

- **O(26)**: We use an array of size 26 (`freq` array) to store the frequency of characters. The space complexity is constant, i.e., O(1), because the size of the array does not depend on the input size but only on the fixed number of lowercase letters (26).

---

## How to Run the Code

### For C++

1. Include the necessary headers at the top of your code:

   ```cpp
   #include <iostream>
   #include <vector>
   #include <climits>
   ```

2. Define the `Solution` class and the methods as shown in the code above.

3. In the `main` function, create an object of the `Solution` class and call the `beautySum` method with a string input:

   ```cpp
   int main() {
       Solution solution;
       std::string s = "aabcb"; // Example input
       int result = solution.beautySum(s);
       std::cout << "Result: " << result << std::endl;
       return 0;
   }
   ```

4. Compile and run the program.

---
