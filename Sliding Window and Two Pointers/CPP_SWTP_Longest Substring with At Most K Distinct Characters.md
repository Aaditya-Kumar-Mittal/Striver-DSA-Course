# Longest Substring with At Most K Distinct Characters

## Problem Statement

You are given a string `str` and an integer `K`. Your task is to find the length of the largest substring with at most `K` distinct characters.

### Example

For example:

- If you are given `str = "abbbbbbc"` and `K = 2`, the possible substrings are `["abbbbbb", "bbbbbbc"]`, hence the answer is `7`.

### Input/Output Format

**Input Format:**

- The first line contains an integer `T`, the number of test cases.
- Each test case consists of:
  - An integer `K`, the maximum number of distinct characters allowed.
  - A string `str`, the input string.

**Output Format:**

- For each test case, print the length of the longest substring that contains at most `K` distinct characters.

### Constraints

- `1 <= T <= 10`
- `1 <= K <= 26`
- `1 <= |str| <= 10^6`
- The string `str` will contain only lowercase alphabets.

### Time Limit

- 1 second

## Sample Input

```plaintext
2
2 abbbbbbc
3 abcddefg
```

### Sample Output

```plaintext
7
4
```

**Explanation:**

- For the first test case, `str = "abbbbbbc"` and `K = 2`, the longest substring is `7`.
- For the second test case, `str = "abcddefg"` and `K = 3`, the longest substring is `4`.

---

## Brute Force Solution

### Approach

1. Use nested loops to explore all possible substrings starting from each index.
2. Maintain a map to count the frequency of characters in the current substring.
3. If the number of distinct characters exceeds `K`, break the inner loop.
4. Update the maximum length found for valid substrings.

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    int n = str.size();
    int maxLen = -1; // Initialize to -1 to handle cases where no valid substring exists

    // Traverse all starting points of substrings
    for (int i = 0; i < n; i++) {
        unordered_map<char, int> mpp; // Map to store character frequencies

        // Traverse all ending points of substrings starting from i
        for (int j = i; j < n; j++) {
            mpp[str[j]]++;
            // If the number of unique characters is less than or equal to k
            if (mpp.size() <= k) {
                maxLen = max(maxLen, j - i + 1);
            }
            // If the number of unique characters exceeds k, stop expanding
            else {
                break;
            }
        }
    }
    return maxLen;
}
```

### Complexity Analysis

- **Time Complexity**: \(O(n^2)\) due to the nested loop structure.
- **Space Complexity**: \(O(1)\) since the map can store at most \(k\) characters.

---

## Better Solution

### Better Approach

1. Use a sliding window technique with two pointers (`left` and `right`).
2. Expand the window by including the character at the `right` pointer and update the character frequency map.
3. If the number of distinct characters exceeds `K`, shrink the window from the `left`.
4. Update the maximum length whenever the window has at most `K` distinct characters.

### Code for Better Approach

```cpp
#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    int n = str.size();
    int maxLen = 0; // Initialize to 0
    int left = 0, right = 0;
    unordered_map<char, int> mpp;

    while (right < n) {
        mpp[str[right]]++; // Expand the window by including the right character

        // Shrink the window from the left if the number of distinct characters exceeds k
        while (mpp.size() > k) {
            mpp[str[left]]--; // Decrease the count of the left character
            if (mpp[str[left]] == 0) {
                mpp.erase(str[left]); // Remove character if its count is zero
            }
            left++; // Move the left pointer to the right
        }

        // Update maxLen when the window has at most k distinct characters
        maxLen = max(maxLen, right - left + 1);
        right++; // Move the right pointer to expand the window
    }

    return maxLen > 0 ? maxLen : -1; // Return -1 if no valid substring was found
}
```

### Complexity Analysis of Better Approach

- **Time Complexity**: \(O(2n)\) since both `left` and `right` pointers traverse the array at most once. Left traverses once overall and not for every iteration of right pointer hence it is \(O(n)\) + \(O(n)\)
- **Space Complexity**: \(O(1)\) because the map can contain at most \(K\) characters.

---

## Most Optimized Solution

This solution uses the same sliding window technique but simplifies the logic by reducing the number of checks in the loop.

### Code for Optimized Sliding Window

```cpp
#include <bits/stdc++.h>
using namespace std;

int kDistinctChars(int k, string &str) {
    int n = str.size();
    int maxLen = 0; // Initialize to 0
    int left = 0, right = 0;
    unordered_map<char, int> mpp;

    while (right < n) {
        mpp[str[right]]++; // Expand the window by including the right character

        // Shrink the window from the left if the number of distinct characters exceeds k
        if (mpp.size() > k) {
            mpp[str[left]]--; // Decrease the count of the left character
            if (mpp[str[left]] == 0) {
                mpp.erase(str[left]); // Remove character if its count is zero
            }
            left++; // Move the left pointer to the right
        }

        // Update maxLen when the window has at most k distinct characters
        maxLen = max(maxLen, right - left + 1);
        right++; // Move the right pointer to expand the window
    }

    return maxLen > 0 ? maxLen : -1; // Return -1 if no valid substring was found
}
```

### Complexity Analysis of Optimized Sliding Window

- **Time Complexity**: \(O(n)\) since both pointers traverse the array at most once.
- **Space Complexity**: \(O(1)\) for maintaining the frequency map.

---

## Conclusion

- **Brute Force Approach**: Inefficient for large inputs due to its \(O(n^2)\) complexity.
- **Optimized Approach**: Sliding window technique is efficient with \(O(n)\) complexity, making it suitable for larger input sizes up to \(10^6\).
- **Key Concept**: Maintain a frequency map and a sliding window to efficiently track valid substrings with at most `K` distinct characters.

This detailed implementation covers all necessary aspects, including constraints, approaches, and analyses to solve the problem of finding the longest substring with at most `K` distinct characters.
