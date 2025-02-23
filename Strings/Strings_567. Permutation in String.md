# Permutation in String

## Table of Contents

- [Permutation in String](#permutation-in-string)
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
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)

## Introduction

Given two strings `s1` and `s2`, we need to determine whether `s2` contains any permutation of `s1`. In other words, we need to check if any permutation of `s1` is a substring of `s2`.

## Problem Description

### Examples

#### Example 1

**Input:**  
`s1 = "ab"`, `s2 = "eidbaooo"`

**Output:**  
`true`

**Explanation:**  
One permutation of "ab" is "ba", which appears as a substring in "eidbaooo".

#### Example 2

**Input:**  
`s1 = "ab"`, `s2 = "eidboaoo"`

**Output:**  
`false`

**Explanation:**  
No permutation of "ab" is present as a contiguous substring in "eidboaoo".

### Constraints

- `1 <= s1.length, s2.length <= 10^4`
- `s1` and `s2` consist of lowercase English letters only.

## Approach

1. **Use Frequency Count:** Create a frequency array of characters in `s1`.
2. **Sliding Window Technique:** Maintain a window in `s2` of the same size as `s1` and update its frequency dynamically.
3. **Compare Frequencies:** If the frequency distribution in the current window matches `s1`, return `true`.
4. **Move Window:** If no permutation is found, slide the window one step ahead and update the frequency accordingly.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Helper function to compare two frequency vectors
    bool vectorsEqual(vector<int> a, vector<int> b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;

        // Find frequency of characters in s1
        vector<int> freqS1(26, 0);
        for (char c : s1)
            freqS1[c - 'a']++;

        vector<int> freqS2(26, 0);
        int i = 0, j = 0;

        while (j < s2.size()) {
            freqS2[s2[j] - 'a']++;

            if (j - i + 1 == s1.size()) { // Window size matches s1
                if (vectorsEqual(freqS1, freqS2))
                    return true;
            }

            if (j - i + 1 < s1.size())
                j++;
            else {
                freqS2[s2[i] - 'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};

// Optimization for faster I/O
inline const auto optimize = [](){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    return 0;
}();
```

## Complexity Analysis

- **Time Complexity:** `O(n)`, where `n` is the length of `s2`. Each character is processed at most twice (once when entering the window and once when leaving).
- **Space Complexity:** `O(1)`, since we use only two frequency arrays of size 26 (constant space).

## How to Run the Code

1. Compile the code using `g++`:

   ```sh
   g++ -std=c++11 filename.cpp -o output
   ```

2. Run the compiled program:

   ```sh
   ./output
   ```

3. Provide inputs and check the results.

This implementation efficiently checks for the existence of a permutation of `s1` in `s2` using the sliding window technique and frequency matching.

## Other Solutions

### Solution - 1

```cpp

bool isFreqSame(int freq1[], int freq2[])
{
  for (int i = 0; i < 26; i++)
  {
    if (freq1[i] != freq2[i])
      return false;
  }

  return true;
}

string permutationExist(string str1, string str2, int n, int m)
{
  // Write your code here.

  int freq[26] = {0};

  for (int i = 0; i < n; i++)
    freq[str1[i] - 'a']++;

  int windowSize = n;

  for (int i = 0; i < m; i++)
  {
    int windowIndex = 0, index = i;

    int windowFreq[26] = {0};

    while (windowIndex < windowSize && index < m)
    {
      windowFreq[str2[index] - 'a']++;
      windowIndex++;
      index++;
    }

    if (isFreqSame(freq, windowFreq))
      return "Yes";
  }

  return "No";
}
```
