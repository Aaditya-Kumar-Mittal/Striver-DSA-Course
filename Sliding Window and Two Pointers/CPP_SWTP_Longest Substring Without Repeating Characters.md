# Sliding Window and Two Pointers - Longest Substring Without Repeating Characters

## Problem Description

Given a string `s`, the task is to find the length of the longest substring without repeating characters.

A substring is a contiguous sequence of characters within a string. For example, in the string "abcabcbb", the longest substring without repeating characters is "abc", which has a length of `3`.

### Example Scenarios

1. **Example 1**:

   - **Input**: `s = "abcabcbb"`
   - **Output**: `3`
   - **Explanation**: The longest substring without repeating characters is `"abc"`, with a length of `3`.

2. **Example 2**:

   - **Input**: `s = "bbbbb"`
   - **Output**: `1`
   - **Explanation**: The longest substring without repeating characters is `"b"`, with a length of `1` because all characters are identical.

3. **Example 3**:
   - **Input**: `s = "pwwkew"`
   - **Output**: `3`
   - **Explanation**: The longest substring without repeating characters is `"wke"`, with a length of `3`.

### Constraints

- `0 <= s.length <= 5 * 10^4`
- `s` consists of English letters, digits, symbols, and spaces.

## Approach

To solve this problem, we use a **sliding window** approach with the help of a **hash array** to track the last seen position of each character. Here's how it works:

1. **Sliding Window**: Maintain two pointers, `left` and `right`, representing the current window of unique characters.
2. **Hash Array**: Use an array of size `256` to keep track of the last index of each character.
   - This array helps in determining if a character has been seen in the current window.
3. **Expanding and Shrinking Window**:
   - As we iterate over the string with the `right` pointer, if the character at `right` has already been seen (i.e., is in the current window), adjust the `left` pointer to move past the previous occurrence of that character.
   - This ensures that the substring between `left` and `right` remains unique.
4. **Track Maximum Length**:
   - For each step, compute the length of the current window and update the `maxLen` with the maximum length observed.

### Complexity Analysis

- **Time Complexity**: `O(n)`, where `n` is the length of the string. Each character is processed at most twice (once by the `right` pointer and once by the `left` pointer).
- **Space Complexity**: `O(1)`, as the `hashArr` has a fixed size of `256`, regardless of the input size.

### Code Implementation

```cpp
class Solution {
public:
    /**
     * @brief Finds the length of the longest substring without repeating characters.
     *
     * @param s The input string consisting of English letters, digits, symbols, and spaces.
     * @return int The length of the longest substring without repeating characters.
     */
    int lengthOfLongestSubstring(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        int n = s.size();          // Size of the input string
        int left = 0, right = 0;   // Pointers for the sliding window
        int maxLen = 0;            // Variable to store the maximum length of the substring
        int len = 0;               // Current length of the substring
        vector<int> hashArr(256, -1); // Array to store the last occurrence of each character

        // Iterate through the string with the `right` pointer
        while (right < n) {
            // Check if the character at `right` is already present in the window
            if (hashArr[s[right]] != -1) {
                // If present, update the `left` pointer to maintain a valid range
                if (hashArr[s[right]] >= left) {
                    left = hashArr[s[right]] + 1;
                }
            }

            // Calculate the length of the current substring
            len = right - left + 1;

            // Update `maxLen` with the maximum length found so far
            maxLen = max(len, maxLen);

            // Update the last occurrence of the character at `right`
            hashArr[s[right]] = right;

            // Move the `right` pointer to the next character
            right++;
        }

        // Return the length of the longest substring without repeating characters
        return maxLen;
    }
};
```

### Explanation of the Code

1. **Initial Setup**:

   - `left` and `right` are used to maintain the sliding window of the substring.
   - `maxLen` keeps track of the maximum length of a unique character substring found so far.
   - `hashArr` is a vector of size `256`, initialized with `-1` to represent the last seen positions of characters.

2. **Iterating with the `right` Pointer**:
   - For each character at `s[right]`, check if it has been seen before within the current window (i.e., if `hashArr[s[right]]` is not `-1` and is greater than or equal to `left`).
   - If so, update `left` to `hashArr[s[right]] + 1` to skip over the repeated character and maintain a valid substring.
3. **Updating the Window**:

   - Calculate the length of the current window using `right - left + 1`.
   - Update `maxLen` if the current length is greater than the previously recorded maximum.

4. **Storing Character Positions**:

   - Store the current position of `s[right]` in `hashArr` for future reference.

5. **Return the Result**:
   - After processing all characters, `maxLen` will contain the length of the longest substring without repeating characters.

### Example Walkthrough

For `s = "abcabcbb"`:

1. `left = 0`, `right = 0`, `hashArr` is initially `-1` for all characters.
2. Iterate through `s`:
   - `right = 0`, `s[right] = 'a'`, add `'a'` to `hashArr`, `maxLen = 1`.
   - `right = 1`, `s[right] = 'b'`, add `'b'` to `hashArr`, `maxLen = 2`.
   - `right = 2`, `s[right] = 'c'`, add `'c'` to `hashArr`, `maxLen = 3`.
   - `right = 3`, `s[right] = 'a'`, `'a'` is repeated, move `left` to `1`.
   - Continue until `right = 7`.
3. The longest substring without repeating characters is `"abc"` with a length of `3`.

### Edge Cases

1. **Empty String**: If `s` is empty (`s = ""`), the output should be `0`.
2. **String with All Identical Characters**: If `s = "aaaaa"`, the output should be `1` since the longest substring without repeating characters is any single character.
3. **String with No Repeats**: If `s = "abcdefg"`, the output should be the length of `s` as all characters are unique.

---

## Other Approaches

### Using Set

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_set<char> charSet;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (charSet.count(s[right]) == 0) {
                charSet.insert(s[right]);
                maxLength = max(maxLength, right - left + 1);
            } else {
                while (charSet.count(s[right])) {
                    charSet.erase(s[left]);
                    left++;
                }
                charSet.insert(s[right]);
            }
        }

        return maxLength;
    }
};
```

### Using Unordered Map

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        unordered_map<char, int> charMap;
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLength = max(maxLength, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }

        return maxLength;
    }
};
```

### Optimized Integer Array

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        vector<int> charIndex(128, -1);
        int left = 0;

        for (int right = 0; right < n; right++) {
            if (charIndex[s[right]] >= left) {
                left = charIndex[s[right]] + 1;
            }
            charIndex[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
```

```cpp
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }
```
