# 76. Minimum Window Substring

<!-- markdownlint-disable MD024 -->

## Problem Description

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the **minimum window substring** of `s` such that every character in `t` (including duplicates) is included in the window. If there is no such substring, return the empty string `""`.

The test cases are generated such that the answer is **unique**.

### Example 1

- **Input**: `s = "ADOBECODEBANC"`, `t = "ABC"`
- **Output**: `"BANC"`
- **Explanation**: The minimum window substring `"BANC"` includes `'A'`, `'B'`, and `'C'` from string `t`.

### Example 2

- **Input**: `s = "a"`, `t = "a"`
- **Output**: `"a"`
- **Explanation**: The entire string `s` is the minimum window.

### Example 3

- **Input**: `s = "a"`, `t = "aa"`
- **Output**: `""`
- **Explanation**: Both `'a'`s from `t` must be included in the window. Since the largest window of `s` only has one `'a'`, return an empty string.

### Constraints

- `m == s.length`
- `n == t.length`
- `1 <= m, n <= 10^5`
- `s` and `t` consist of uppercase and lowercase English letters.

---

## Approach

### Brute Force Approach

The brute force approach involves checking all possible substrings of `s` to see if they contain all characters from `t` and then determining the minimum length of such substrings.

#### Code

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int minLen = INT_MAX;
        int startIndex = -1;
        int n = s.size(), m = t.size();

        // If the size of s is less than t, return an empty string
        if (n < m)
            return "";

        // Traverse the string `s` with a starting index `i`
        for (int i = 0; i < n; i++) {
            // Create a frequency map for `t`
            vector<int> hashArr(256, 0);
            for (int j = 0; j < m; j++) {
                hashArr[t[j]]++;
            }

            int count = 0;

            // Traverse starting from `i` to the end of `s`
            for (int j = i; j < n; j++) {
                // If the current character is in `t` and needed in the window
                if (hashArr[s[j]] > 0) {
                    count++;
                }

                // Decrease the frequency of the character in the window
                hashArr[s[j]]--;

                // If the count matches `m`, we've found a valid window
                if (count == m) {
                    if (j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        startIndex = i;
                    }
                    break;
                }
            }
        }

        // Return the minimum window substring or an empty string if no valid window was found
        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
```

#### Complexity Analysis

- **Time Complexity**: `O(n^2 * m)`, where `n` is the length of `s` and `m` is the length of `t`. This is due to iterating over `s` for each possible starting index and checking for the presence of all characters of `t` for each substring.
- **Space Complexity**: `O(1)` if we ignore the space used for the output string.

This approach is not suitable for large inputs due to its high time complexity.

---

### Optimized Approach: Sliding Window with Two Pointers

The sliding window technique combined with two pointers allows for an optimal solution. This method involves expanding the window until all characters of `t` are included and then contracting it to find the smallest possible window.

#### Code

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0, minLen = INT_MAX, startIndex = -1;
        unordered_map<char, int> mpp;
        int m = t.size(), n = s.size(), count = 0;

        // Store the frequency of each character in `t`
        for (char c : t)
            mpp[c]++;

        // Expand the window using the `right` pointer
        while (right < n) {
            if (mpp[s[right]] > 0)
                count++;

            mpp[s[right]]--;

            // When a valid window is found, try to contract it
            while (count == m) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;
                    startIndex = left;
                }

                mpp[s[left]]++;
                if (mpp[s[left]] > 0) {
                    count--;
                }

                left++;
            }

            right++;
        }

        // Return the minimum window substring or an empty string if no valid window was found
        return (startIndex == -1) ? "" : s.substr(startIndex, minLen);
    }
};
```

#### Complexity Analysis

- **Time Complexity**: `O(m + 2n)`, where `n` is the length of `s` and `m` is the length of `t`. The sliding window is moved over `s` in a linear fashion, and the `mpp` map is updated efficiently.
- **Space Complexity**: `O(m)`, where `m` is the size of `t` due to storing character frequencies in `mpp`.

This solution is efficient and suitable for large inputs.

---

## Summary

The problem of finding the minimum window substring containing all characters of another string is solved using two approaches:

- **Brute Force Approach**: Iterates over all possible substrings, resulting in a high time complexity.
- **Optimized Sliding Window Approach**: Uses two pointers and a hashmap to dynamically adjust the window size, leading to a much more efficient solution.

The sliding window approach is recommended for practical use due to its linear complexity and ability to handle large inputs efficiently.

## Little More Optimized

- The code above costs 76ms. If we change the first line `unordered_map<char, int> m;` to `vector<int> m(128, 0);` , it costs 12ms.

```cpp
class Solution {
public:
    string minWindow(string s, string t) {

        if (s.empty() || t.empty()) {
            return "";
        }

        int left = 0, right = 0, minLen = INT_MAX, startIndex = -1;

        // unordered_map<char, int> mpp;

        vector<int> hash(128, 0);

        int m = t.size(), n = s.size(), count = 0;

        for (char c : t)
            hash[c]++;

        while (right < n) {

            if (hash[s[right]] > 0)
                count++;

            hash[s[right]]--;

            while (count == m) {
                if ((right - left + 1) < minLen) {
                    minLen = right - left + 1;

                    startIndex = left;
                }

                hash[s[left]]++;

                if (hash[s[left]] > 0) {
                    count--;
                }

                left++;
            }

            right++;
        }

        return startIndex == -1 ? "" : s.substr(startIndex, minLen);
    }
};
```

## Solution - 3

```cpp
string minWindow(string s, string t)
{
  vector<int> map(128, 0);
  for (auto c : t)
    map[c]++;
  int counter = t.size(), begin = 0, end = 0, d = INT_MAX, head = 0;
  while (end < s.size())
  {
    if (map[s[end++]]-- > 0)
      counter--; // in t
    while (counter == 0)
    { // valid
      if (end - begin < d)
        d = end - (head = begin);
      if (map[s[begin++]]++ == 0)
        counter++; // make it invalid
    }
  }
  return d == INT_MAX ? "" : s.substr(head, d);
}
```
