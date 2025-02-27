# Longest Palindromic Substring

## Table of Contents

- [Longest Palindromic Substring](#longest-palindromic-substring)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Task](#task)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
    - [Why Expand Around Center?](#why-expand-around-center)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Explanation](#explanation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Other Solutions](#other-solutions)
      - [Approach 1: Check All Substrings](#approach-1-check-all-substrings)
      - [Approach 2: Dynamic Programming](#approach-2-dynamic-programming)
      - [Approach 3: Expand Around Centers](#approach-3-expand-around-centers)
      - [Approach 4: Manacher's Algorithm](#approach-4-manachers-algorithm)
    - [Time and Space Complexity Comparison](#time-and-space-complexity-comparison)

---

## Introduction

A **palindromic substring** is a sequence of characters within a string that reads the same forward and backward. The task is to **find the longest palindromic substring** within a given string `s`.

For example:

- Given `"babad"`, the longest palindromic substring could be `"bab"` or `"aba"`.
- Given `"cbbd"`, the longest palindromic substring is `"bb"`.

We need to efficiently determine the longest palindromic substring for any given string.

---

## Problem Description

### Given

A string `s` consisting of English letters and digits.

### Task

Return the **longest palindromic substring** in `s`.

### Examples

**Example 1:**

```bash
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
```

**Example 2:**

```bash
Input: s = "cbbd"
Output: "bb"
```

### Constraints

- `1 <= s.length <= 1000`
- `s` consists of only digits and English letters.

---

## Approach

To solve this problem, we will use the **Expand Around Center** approach, which takes advantage of the fact that a palindrome mirrors around its center.

### Steps

1. **Iterate through each character** in the string, treating it as the center of a potential palindrome.
2. **Expand from the center**:
   - Consider two cases:
     - **Odd-length palindromes**: Expand around a single center (`i`).
     - **Even-length palindromes**: Expand around two adjacent centers (`i, i+1`).
3. **Compare the found palindromes** and update the longest one encountered.

### Why Expand Around Center?

- Instead of checking all substrings (`O(n²)`) or using dynamic programming (`O(n²)`), this approach finds palindromes in `O(n²)` but with significantly less overhead.
- It efficiently finds palindromes by only expanding from valid centers.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1)
            return s; // Single character or empty string is itself a palindrome

        // Lambda function to expand around the center and return longest palindrome
        auto expand_from_center = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return s.substr(left + 1, right - left - 1);
        };

        string max_str = s.substr(0, 1); // Start with the first character as the longest palindrome

        for (int i = 0; i < n - 1; i++) {
            // Find longest odd-length palindrome centered at i
            string odd = expand_from_center(i, i);
            // Find longest even-length palindrome centered at i and i+1
            string even = expand_from_center(i, i + 1);

            // Update max_str with the longest found palindrome
            if (odd.length() > max_str.length())
                max_str = odd;
            if (even.length() > max_str.length())
                max_str = even;
        }

        return max_str;
    }
};
```

### Explanation

1. **Edge Case Handling**:

   - If `s` has only one character or is empty, return `s` immediately.

2. **Expand Around Center (`expand_from_center` function)**:

   - This function expands from a given center index (`left, right`).
   - If characters match, it continues expanding.
   - When expansion stops, it returns the palindromic substring found.

3. **Iterating Over the String**:

   - For each character in `s`, two checks are performed:
     - Odd-length palindromes (centered at `i`).
     - Even-length palindromes (centered at `i, i+1`).
   - The longest palindrome found is stored in `max_str`.

4. **Returning the Result**:
   - The longest palindromic substring found is returned.

---

## Complexity Analysis

### Time Complexity

- **O(n²)**: For each character in `s`, we attempt to expand in both directions (`O(n)`). Since we repeat this for every character, the worst case is `O(n²)`.

### Space Complexity

- **O(1)**: The function uses only a few variables and does not require extra storage beyond the input string.

---

## How to Run the Code

### For C++

1. Include the necessary headers at the top of your code:

   ```cpp
   #include <iostream>
   #include <string>
   ```

2. Define the `Solution` class and implement the methods as shown in the code above.

3. In the `main` function, create an object of the `Solution` class and call the `longestPalindrome` method with a string input:

   ```cpp
   int main() {
       Solution solution;
       std::string s = "babad"; // Example input
       std::string result = solution.longestPalindrome(s);
       std::cout << "Longest Palindromic Substring: " << result << std::endl;
       return 0;
   }
   ```

4. Compile and run the program.

---

### Other Solutions

Here are the detailed explanations and implementations of the four approaches to solve the **Longest Palindromic Substring** problem. Each approach is explained with its intuition, algorithm, implementation, and complexity analysis.

---

#### Approach 1: Check All Substrings

Intuition:  
The brute-force approach involves checking every possible substring to determine if it is a palindrome. We use two pointers to check if a substring is a palindrome by comparing characters from the start and end, moving inward.

Algorithm:

1. Create a helper method `check(i, j)` to determine if a substring is a palindrome.
2. Use two pointers (`left` and `right`) to compare characters.
3. Iterate over all possible substrings, starting with the longest ones.
4. Return the first palindrome found (since we start with the longest).

Implementation:

C++ Code:

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        for (int len = n; len > 0; len--) {
            for (int start = 0; start <= n - len; start++) {
                if (check(s, start, start + len - 1)) {
                    return s.substr(start, len);
                }
            }
        }
        return "";
    }

private:
    bool check(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
};
```

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        for (int length = s.size(); length > 0; length--) {
            for (int start = 0; start <= s.size() - length; start++) {
                if (check(s, start, start + length)) {
                    return s.substr(start, length);
                }
            }
        }

        return "";
    }

private:
    bool check(string s, int i, int j) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
```

Java Code:

```java
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        for (int len = n; len > 0; len--) {
            for (int start = 0; start <= n - len; start++) {
                if (check(s, start, start + len - 1)) {
                    return s.substring(start, start + len);
                }
            }
        }
        return "";
    }

    private boolean check(String s, int left, int right) {
        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) return false;
            left++;
            right--;
        }
        return true;
    }
}
```

```java
class Solution {
    public String longestPalindrome(String s) {
        for (int length = s.length(); length > 0; length--) {
            for (int start = 0; start <= s.length() - length; start++) {
                if (check(start, start + length, s)) {
                    return s.substring(start, start + length);
                }
            }
        }

        return "";
    }

    private boolean check(int i, int j, String s) {
        int left = i;
        int right = j - 1;

        while (left < right) {
            if (s.charAt(left) != s.charAt(right)) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
}
```

Complexity Analysis:

- Time Complexity: `O(n³)`
  - Two nested loops iterate `O(n²)` times, and each palindrome check takes `O(n)`.
- Space Complexity: `O(1)`
  - No extra space is used.

---

#### Approach 2: Dynamic Programming

Intuition:  
Use a 2D DP table to store whether a substring is a palindrome. If `s[i] == s[j]` and the substring `s[i+1:j-1]` is a palindrome, then `s[i:j]` is also a palindrome.

Algorithm:

1. Initialize a DP table `dp[i][j]` where `dp[i][j]` is `true` if `s[i:j]` is a palindrome.
2. Fill the table for substrings of length 1 and 2.
3. Use the table to check longer substrings.

Implementation:

C++ Code:

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for substrings of length > 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
```

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n));
        array<int, 2> ans = {0, 0};

        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                ans = {i, i + 1};
            }
        }

        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans = {i, j};
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substr(i, j - i + 1);
    }
};
```

Java Code:

```java
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int start = 0, maxLen = 1;

        // All substrings of length 1 are palindromes
        for (int i = 0; i < n; i++) dp[i][i] = true;

        // Check for substrings of length 2
        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                start = i;
                maxLen = 2;
            }
        }

        // Check for substrings of length > 2
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }

        return s.substring(start, start + maxLen);
    }
}
```

```java
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int[] ans = new int[] { 0, 0 };

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                dp[i][i + 1] = true;
                ans[0] = i;
                ans[1] = i + 1;
            }
        }

        for (int diff = 2; diff < n; diff++) {
            for (int i = 0; i < n - diff; i++) {
                int j = i + diff;
                if (s.charAt(i) == s.charAt(j) && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    ans[0] = i;
                    ans[1] = j;
                }
            }
        }

        int i = ans[0];
        int j = ans[1];
        return s.substring(i, j + 1);
    }
}
```

Complexity Analysis:

- Time Complexity: `O(n²)`
  - Filling the DP table takes `O(n²)` time.
- Space Complexity: `O(n²)`
  - The DP table uses `O(n²)` space.

---

#### Approach 3: Expand Around Centers

Intuition:  
A palindrome mirrors around its center. We can expand around each character (for odd-length palindromes) and each pair of characters (for even-length palindromes).

Algorithm:

1. Use a helper method `expand(i, j)` to find the length of the longest palindrome centered at `i` and `j`.
2. Iterate over all centers and keep track of the longest palindrome found.

Implementation:

C++ Code:

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            int len1 = expand(s, i, i); // Odd-length palindrome
            int len2 = expand(s, i, i + 1); // Even-length palindrome
            int len = max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substr(start, end - start + 1);
    }

private:
    int expand(string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }
};
```

Java Code:

```java
class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        int start = 0, end = 0;

        for (int i = 0; i < n; i++) {
            int len1 = expand(s, i, i); // Odd-length palindrome
            int len2 = expand(s, i, i + 1); // Even-length palindrome
            int len = Math.max(len1, len2);
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        return s.substring(start, end + 1);
    }

    private int expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}
```

Complexity Analysis:

- Time Complexity: `O(n²)`
  - There are `2n - 1` centers, and each expansion takes `O(n)`.
- Space Complexity: `O(1)`
  - No extra space is used.

---

#### Approach 4: Manacher's Algorithm

Intuition:  
Manacher's algorithm finds the longest palindromic substring in linear time by exploiting the symmetry of palindromes.

Algorithm:

1. Transform the string to handle even-length palindromes.
2. Use a table to store the lengths of palindromes centered at each character.
3. Iterate over the string, using previously computed values to avoid redundant checks.

Implementation:

C++ Code:

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "#";
        for (char c : s) {
            t += c;
            t += '#';
        }

        int n = t.length();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int maxLen = 0, maxCenter = 0;

        for (int i = 0; i < n; i++) {
            if (i < right) {
                p[i] = min(right - i, p[2 * center - i]);
            }

            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
                p[i]++;
            }

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }

        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
```

```cpp
class Solution {
public:
    string longestPalindrome(string s) {
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.length();
        vector<int> palindrome_radii(n, 0);
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
            }

            while (i + 1 + palindrome_radii[i] < n &&
                   i - 1 - palindrome_radii[i] >= 0 &&
                   s_prime[i + 1 + palindrome_radii[i]] ==
                       s_prime[i - 1 - palindrome_radii[i]]) {
                palindrome_radii[i]++;
            }

            if (i + palindrome_radii[i] > radius) {
                center = i;
                radius = i + palindrome_radii[i];
            }
        }

        int max_length = 0;
        int center_index = 0;
        for (int i = 0; i < n; i++) {
            if (palindrome_radii[i] > max_length) {
                max_length = palindrome_radii[i];
                center_index = i;
            }
        }

        int start_index = (center_index - max_length) / 2;
        string longest_palindrome = s.substr(start_index, max_length);

        return longest_palindrome;
    }
};
```

Java Code:

```java
class Solution {
    public String longestPalindrome(String s) {
        String t = "#";
        for (char c : s.toCharArray()) {
            t += c;
            t += '#';
        }

        int n = t.length();
        int[] p = new int[n];
        int center = 0, right = 0;
        int maxLen = 0, maxCenter = 0;

        for (int i = 0; i < n; i++) {
            if (i < right) {
                p[i] = Math.min(right - i, p[2 * center - i]);
            }

            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t.charAt(i - p[i] - 1) == t.charAt(i + p[i] + 1)) {
                p[i]++;
            }

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }

        int start = (maxCenter - maxLen) / 2;
        return s.substring(start, start + maxLen);
    }
}
```

```java
class Solution {
    public String longestPalindrome(String s) {
        StringBuilder sPrime = new StringBuilder("#");
        for (char c : s.toCharArray()) {
            sPrime.append(c).append("#");
        }

        int n = sPrime.length();
        int[] palindromeRadii = new int[n];
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindromeRadii[i] = Math.min(
                    radius - i,
                    palindromeRadii[mirror]
                );
            }

            while (
                i + 1 + palindromeRadii[i] < n &&
                i - 1 - palindromeRadii[i] >= 0 &&
                sPrime.charAt(i + 1 + palindromeRadii[i]) ==
                    sPrime.charAt(i - 1 - palindromeRadii[i])
            ) {
                palindromeRadii[i]++;
            }

            if (i + palindromeRadii[i] > radius) {
                center = i;
                radius = i + palindromeRadii[i];
            }
        }

        int maxLength = 0;
        int centerIndex = 0;
        for (int i = 0; i < n; i++) {
            if (palindromeRadii[i] > maxLength) {
                maxLength = palindromeRadii[i];
                centerIndex = i;
            }
        }

        int startIndex = (centerIndex - maxLength) / 2;
        String longestPalindrome = s.substring(
            startIndex,
            startIndex + maxLength
        );

        return longestPalindrome;
    }
}
```

Complexity Analysis:

- Time Complexity: `O(n)`
  - The algorithm processes each character once.
- Space Complexity: `O(n)`
  - The transformed string and palindrome lengths table use `O(n)` space.

---

### Time and Space Complexity Comparison

| Approach              | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Check All Substrings  | O(n³)           | O(1)             |
| Dynamic Programming   | O(n²)           | O(n²)            |
| Expand Around Centers | O(n²)           | O(1)             |
| Manacher's Algorithm  | O(n)            | O(n)             |

---

Choose the approach based on the problem constraints and requirements!
