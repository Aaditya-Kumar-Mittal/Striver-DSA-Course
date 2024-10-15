# Sliding Window and Two Pointers Template for Substring-based Problems

## Overview

In many substring-based problems, we need to find a contiguous part of a string `s` that satisfies certain conditions or restrictions. A commonly used technique for solving such problems is the **sliding window** method with **two pointers**. This method is often paired with a hashmap or frequency array to efficiently track characters within the window.

## When to Use Sliding Window Technique

The sliding window technique is particularly useful when:

- We are asked to find a substring (contiguous subarray) that satisfies certain properties.
- We need to efficiently adjust the window size as we iterate over the input.
- The problem requires checking the number or frequency of characters within the current window.

### Common Problems Solved Using This Approach

- Finding the smallest or largest window that satisfies a condition.
- Counting the number of substrings that satisfy a given condition.
- Finding a window that contains all characters of another string.

## Template

Below is a general template for solving substring problems using the sliding window approach with two pointers.

```cpp
int findSubstring(string s) {
    // Map to store the frequency of characters.
    vector<int> map(128, 0);
    int counter; // Tracks whether the current window is valid.
    int begin = 0, end = 0; // Two pointers: begin for the start of the window, end for the end.
    int d; // The length of the desired substring, e.g., minimum length or count.

    // Initialize the hash map with the required character frequencies.
    for() {
        /* Initialize the hash map here, e.g., store the frequency of each character from the required string. */
    }

    // Iterate over the string `s` using the `end` pointer.
    while (end < s.size()) {
        // Move `end` forward and adjust the character count in the map.
        if (map[s[end++]]-- ? /* condition */) {
            /* Modify the counter here, e.g., decrease it when a character from `t` is matched. */
        }

        // When the counter condition is met, try to contract the window from the left.
        while (/* counter condition */) {
            /* Update `d` here if finding the minimum length or counting valid substrings. */

            // Increase `begin` to make the window invalid/valid again.
            if (map[s[begin++]]++ ? /* condition */) {
                /* Modify the counter here, e.g., increase it when a character is removed from the window. */
            }
        }

        /* Update `d` here if finding the maximum length. */
    }

    return d;
}
```

## Explanation of the Template

- **Map Initialization**: A frequency array or hashmap (`map`) is used to store the count of each character. The size is 128 to account for all ASCII characters.
- **Counter**: `counter` is used to determine if the current window meets the required condition. It often represents how many characters from the target substring are still needed.
- **Pointers**:
  - `begin`: Points to the start of the current window.
  - `end`: Points to the end of the current window.
- **Adjusting the `end` Pointer**: The `end` pointer is used to expand the window by including characters. Each time `end` is moved, the character count in the hashmap is adjusted.
- **Valid Window Check**: When the window satisfies the condition (`counter` condition), the `begin` pointer is moved to shrink the window until the condition is no longer met.
- **Adjusting the `begin` Pointer**: Moving `begin` helps in finding the smallest window or counting all valid windows.
- **Updating `d`**: The value of `d` can represent different things depending on the problem:
  - For finding the **minimum window** length, update `d` whenever a valid window is found.
  - For counting **all valid substrings**, increment `d` every time the `begin` pointer moves while the condition holds.

## Use Case Example: Minimum Window Substring

Let's look at how this template is applied to solve a specific problem, like finding the **minimum window substring**:

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128, 0);
        int counter = t.size(); // Number of characters from `t` we need to match.
        int begin = 0, end = 0, minLen = INT_MAX, startIndex = 0;

        // Initialize the hashmap with characters from `t`.
        for (char c : t) {
            map[c]++;
        }

        // Expand the window using the `end` pointer.
        while (end < s.size()) {
            if (map[s[end]] > 0) {
                counter--;
            }

            map[s[end]]--;
            end++;

            // When a valid window is found (all characters matched).
            while (counter == 0) {
                if (end - begin < minLen) {
                    minLen = end - begin;
                    startIndex = begin;
                }

                map[s[begin]]++;
                if (map[s[begin]] > 0) {
                    counter++;
                }

                begin++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};
```

### Explanation

- **Initialization**: The hashmap is initialized with the character counts of `t`. The `counter` tracks the number of characters still needed to form a valid window.
- **Expanding the Window**: We expand the window by moving `end` and adjusting the count in `map`.
- **Valid Window**: When `counter` becomes `0`, it means all characters of `t` are within the window.
- **Contracting the Window**: Move `begin` to find the smallest window. If removing a character makes the window invalid, increase `counter`.
- **Update the Result**: Keep track of the minimum window length and starting index.
- **Return the Result**: Return the substring with the recorded minimum length.

## Summary

This template is a powerful tool for solving substring problems, allowing for efficient searching with time complexity often close to `O(n)`:

- **Two Pointers** help dynamically adjust the window size.
- A **Hashmap or Frequency Array** tracks character counts within the window.
- **Sliding Window** helps efficiently move across the input string.

Understanding this template can help solve various problems like finding the longest or shortest substring, counting the number of substrings, and more.
