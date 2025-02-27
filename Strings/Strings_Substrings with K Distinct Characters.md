# Substrings with K Distinct Characters

## Table of Contents

- [Substrings with K Distinct Characters](#substrings-with-k-distinct-characters)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Task](#task)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
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

A substring is a contiguous sequence of characters within a string. In this problem, we need to count all substrings that contain exactly `k` distinct characters.

For example:

- Given `"aba"`, `k = 2`, the valid substrings are: `"ab"`, `"ba"`, and `"aba"`, so the output is `3`.
- Given `"abaaca"`, `k = 1`, the valid substrings are: `"a"`, `"b"`, `"a"`, `"aa"`, `"a"`, `"c"`, `"a"`, so the output is `7`.
- Given `"cdad"`, `k = 4`, no substring has exactly `4` distinct characters, so the output is `0`.

---

## Problem Description

### Given

A string `s` consisting of lowercase English letters.

### Task

Return the **count of substrings** that have exactly `k` distinct characters.

### Examples

**Example 1:**

```bash
Input: s = "aba", k = 2
Output: 3
Explanation: The substrings are: "ab", "ba", and "aba".
```

**Example 2:**

```bash
Input: s = "abaaca", k = 1
Output: 7
Explanation: The substrings are: "a", "b", "a", "aa", "a", "c", "a".
```

**Example 3:**

```bash
Input: s = "cdad", k = 4
Output: 0
```

### Constraints

- `1 ≤ s.size() ≤ 10^6`
- `1 ≤ k ≤ 26`

---

## Approach

To efficiently count substrings with exactly `k` distinct characters, we use the **Sliding Window (Two-Pointer) Technique**. Instead of directly counting substrings with exactly `k` distinct characters, we count substrings with **at most `k`** distinct characters and subtract the count of substrings with **at most `k-1`** distinct characters.

### Steps

1. **Define a helper function `atmostK(s, k)`**:
   - This function returns the count of substrings containing **at most** `k` distinct characters.
   - Maintain a frequency map for character counts.
   - Expand the right pointer (`right++`) to include new characters.
   - If the count of distinct characters exceeds `k`, move the left pointer (`left++`) to maintain the constraint.
   - The count of valid substrings is updated based on `right - left + 1`.

2. **Compute the required result**:
   - Use the formula:
     \[
     \text{countSubstr}(s, k) = \text{atmostK}(s, k) - \text{atmostK}(s, k-1)
     \]
   - This formula works because `atmostK(s, k)` counts substrings with up to `k` distinct characters, and `atmostK(s, k-1)` counts those with up to `k-1` distinct characters.
   - Their difference gives the exact count of substrings containing **exactly** `k` distinct characters.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Helper function to count substrings with at most k distinct characters
    long long int atmostK(string &s, int k) {
        int left = 0, right = 0, count = 0;
        long long int ans = 0;
        vector<int> mpp(26, 0); // Frequency map for characters

        while (right < s.length()) {
            // Expand window by including s[right]
            mpp[s[right] - 'a']++;
            if (mpp[s[right] - 'a'] == 1) count++; // New distinct character

            // Shrink window if distinct character count exceeds k
            while (count > k) {
                mpp[s[left] - 'a']--;
                if (mpp[s[left] - 'a'] == 0) count--; // Character removed
                left++;
            }

            // Count valid substrings within window
            ans += right - left + 1;
            right++;
        }

        return ans;
    }

    // Main function to count substrings with exactly k distinct characters
    long long int countSubstr(string& s, int k) {
        if (k == 0) return 0; // No valid substrings for k=0
        return atmostK(s, k) - atmostK(s, k - 1);
    }
};

// Driver Code
int main() {
    Solution solution;
    string s = "aba";
    int k = 2;
    cout << "Count of substrings with " << k << " distinct characters: " 
         << solution.countSubstr(s, k) << endl;
    return 0;
}
```

### Explanation

1. **`atmostK(s, k)` function**:
   - Uses a **sliding window** approach to count substrings with at most `k` distinct characters.
   - Expands the window by moving `right` and updates frequency counts.
   - Shrinks the window by moving `left` when distinct character count exceeds `k`.
   - Adds the count of substrings within the window to the result.

2. **`countSubstr(s, k)` function**:
   - Computes the difference between substrings with at most `k` and `k-1` distinct characters to get exactly `k` distinct characters.

---

## Complexity Analysis

### Time Complexity

- **O(n)** for `atmostK(s, k)`, since each character is processed once while expanding and once while contracting the window.
- **O(n) + O(n) = O(n)** for `countSubstr(s, k)`, as it calls `atmostK(s, k)` twice.
- **Overall Complexity: O(n)**, which is optimal given that a brute-force approach would take **O(n²)**.

### Space Complexity

- **O(1)**, since the frequency array has a fixed size of `26` for lowercase English letters.

---

## How to Run the Code

### For C++

1. Include necessary headers:

   ```cpp
   #include <iostream>
   #include <vector>
   #include <string>
   ```

2. Implement the `Solution` class.
3. Define a `main` function to test the implementation.
4. Compile and run the code:

   ```bash
   g++ -o solution solution.cpp
   ./solution
   ```

5. The output for `"aba", k = 2` should be:

   ```bash
   Count of substrings with 2 distinct characters: 3
   ```

---

This documentation provides a structured breakdown of the problem, solution approach, and implementation details for efficiently counting substrings with exactly `k` distinct characters.
