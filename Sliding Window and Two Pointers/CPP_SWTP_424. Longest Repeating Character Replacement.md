# 424. Longest Repeating Character Replacement

## Problem Statement

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

**Objective:** Return the length of the longest substring containing the same letter you can get after performing the above operations.

### Examples

1. **Example 1:**

   - **Input:** `s = "ABAB", k = 2`
   - **Output:** `4`
   - **Explanation:** Replace the two 'A's with two 'B's or vice versa.

2. **Example 2:**
   - **Input:** `s = "AABABBA", k = 1`
   - **Output:** `4`
   - **Explanation:** Replace the one 'A' in the middle with 'B' and form "AABBBBA". The substring "BBBB" has the longest repeating letters, which is 4. Other ways might also achieve this answer.

### Constraints

- \(1 \leq s.length \leq 10^5\)
- `s` consists of only uppercase English letters.
- \(0 \leq k \leq s.length\)

---

## Solutions

### 1. Brute Force Solution

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size();
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            vector<int> hashArr(26, 0);
            int maxFreq = 0;

            for (int j = i; j < n; j++) {
                hashArr[s[j] - 'A']++;
                maxFreq = max(maxFreq, hashArr[s[j] - 'A']);
                int changes = (j - i + 1) - maxFreq;

                if (changes <= k) {
                    maxLen = max(maxLen, j - i + 1);
                } else {
                    break;
                }
            }
        }

        return maxLen;
    }
};

/*
Analysis:
- Time Complexity: O(n^2), where n is the length of the string. The outer loop runs for each character, and the inner loop runs for each substring starting from that character, leading to O(n^2) total checks.
- Space Complexity: O(1), since the frequency array has a fixed size of 26.
- This brute force approach can be inefficient for larger strings, as it checks all possible substrings.
*/
```

### 2. Better Solution - 1 (Sliding Window with Frequency Count)

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size(); // Length of the input string
        int maxLen = 0;   // Variable to store the maximum length of substring
        vector<int> freq(26, 0); // Frequency array for each character (A-Z)

        for (int right = 0; right < n; right++) {
            freq[s[right] - 'A']++; // Increment the count of the current character
            int maxFreq = *max_element(freq.begin(), freq.end()); // Find the most frequent character in the current window

            // Calculate the number of characters that need to be replaced
            int changes = (right - left + 1) - maxFreq;

            // If changes exceed k, shrink the window from the left
            if (changes > k) {
                freq[s[left] - 'A']--; // Decrement the count of the character at the left pointer
                left++; // Move the left pointer to the right
            }

            // Update the maximum length found
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen; // Return the maximum length of substring found
    }
};

/*
Analysis:
- Time Complexity: O(n), where n is the length of the string. Each character is processed at most twice (once by the right pointer and once by the left).
- Space Complexity: O(1), since the frequency array has a fixed size of 26.
- This approach significantly reduces the number of operations by only maintaining a sliding window, making it efficient for larger strings.
*/
```

### 3. Better Solution - 2 (Optimized Sliding Window)

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0}; // Frequency array for characters
        int l = 0; // Left pointer
        int r = 0; // Right pointer
        int maxlen = 0; // Maximum length of the substring
        int mmf = 0; // Most frequent character count

        while (r < s.length()) {
            hash[s[r] - 'A']++; // Increment the frequency of the current character
            mmf = max(mmf, hash[s[r] - 'A']); // Update the most frequent character count

            // Shrink the window if needed
            while ((r - l + 1) - mmf > k) {
                hash[s[l] - 'A']--; // Decrement the frequency of the left character
                l++; // Move the left pointer to the right
            }

            // Update the maximum length of the valid substring
            maxlen = max(maxlen, (r - l + 1));
            r++; // Move the right pointer to expand the window
        }

        return maxlen; // Return the maximum length of substring found
    }
};

/*
Analysis:
- Time Complexity: O(n), where n is the length of the string. The pointers traverse the string once, ensuring efficient processing.
- Space Complexity: O(1), as the hash array is of fixed size (26).
- This approach improves upon previous methods by not recalculating the maximum frequency from scratch each time, leading to faster performance.
*/
```

### 4. Optimized Solution

```cpp
class Solution {
public:
    int characterReplacement(string s, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size();
        int maxLen = 0; // Variable to store the maximum length of substring
        int left = 0, right = 0, maxFreq = 0; // Initialize pointers and max frequency
        vector<int> hashArr(26, 0); // Frequency array for characters

        while (right < n) {
            hashArr[s[right] - 'A']++; // Increment frequency of the current character
            maxFreq = max(maxFreq, hashArr[s[right] - 'A']); // Update the maximum frequency

            // Check if the number of changes exceeds k
            if ((right - left + 1) - maxFreq > k) {
                hashArr[s[left] - 'A']--; // Decrement frequency of the left character
                left++; // Move the left pointer to the right
            }

            // Update the maximum length found
            maxLen = max(maxLen, (right - left + 1));
            right++; // Move the right pointer to expand the window
        }

        return maxLen; // Return the maximum length of substring found
    }
};

/*
Analysis:
- Time Complexity: O(n), where n is the length of the string. The algorithm processes each character at most twice, ensuring linear complexity.
- Space Complexity: O(1), as the hash array is of fixed size (26).
- This solution is efficient and maintains simplicity by directly tracking the maximum frequency, ensuring it works effectively for larger input sizes.
*/
```

---

## Conclusion

The analysis sections provide insight into the efficiency of each solution, discussing time and space complexity, and highlighting the improvements made in each approach. This structure should facilitate a clearer understanding of the methods used to solve the **Longest Repeating Character Replacement** problem.
