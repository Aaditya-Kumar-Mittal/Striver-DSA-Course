# 1358. Number of Substrings Containing All Three Characters

<!-- markdownlint-disable MD024 -->

## Problem Statement

You are given a string `s` consisting only of characters `a`, `b`, and `c`. Your task is to return the number of substrings containing at least one occurrence of all these characters: `a`, `b`, and `c`.

### Examples

- **Example 1:**

  - **Input:** `s = "abcabc"`
  - **Output:** `10`
  - **Explanation:** The substrings containing at least one occurrence of characters `a`, `b`, and `c` are:
    - "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc", and "abc" (again).

- **Example 2:**

  - **Input:** `s = "aaacb"`
  - **Output:** `3`
  - **Explanation:** The valid substrings are "aaacb", "aacb", and "acb".

- **Example 3:**
  - **Input:** `s = "abc"`
  - **Output:** `1`

### Constraints

- \(3 \leq s.length \leq 5 \times 10^4\)
- `s` only consists of characters `a`, `b`, or `c`.

## Brute Force Solution

### Approach

1. Use nested loops to explore all possible substrings starting from each index.
2. Maintain a hash array to check if all characters `a`, `b`, and `c` are present in the current substring.
3. Increment the count for each valid substring found.

### Code

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            vector<int> hashArr(3, 0);

            for (int j = i; j < n; j++) {
                hashArr[s[j] - 'a'] = 1;

                if (hashArr[0] + hashArr[1] + hashArr[2] == 3) {
                    count++;
                }
            }
        }

        return count;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(n^2)\) due to the nested loop structure.
- **Space Complexity:** \(O(1)\) since the hash array has a fixed size of 3.

---

## Brute Force Optimized Solution

### Approach

1. The same approach as the brute force method but optimize by breaking the inner loop early once a valid substring is found.
2. Count all valid substrings that can be formed from the current starting index to the end of the string.

### Code

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            vector<int> hashArr(3, 0);

            for (int j = i; j < n; j++) {
                hashArr[s[j] - 'a'] = 1;

                if (hashArr[0] + hashArr[1] + hashArr[2] == 3) {
                    count += (n - j); // Count all remaining substrings starting from this point
                    break;
                }
            }
        }

        return count;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(n^2)\), but with fewer checks due to the early break.
- **Space Complexity:** \(O(1)\).

---

## Optimized Solution

### Approach

1. Use a single loop to track the last seen indices of `a`, `b`, and `c`.
2. Whenever all characters have been seen at least once, count how many valid substrings can be formed from the minimum index to the current index.

### Code

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        int n = s.size();
        int count = 0;
        vector<int> lastSeen(3, -1); // To track last seen indices of a, b, c

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;

            if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1) {
                count += (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
            }
        }

        return count;
    }
};
```

### Complexity Analysis

- **Time Complexity:** \(O(n)\) since we iterate through the string once.
- **Space Complexity:** \(O(1)\) since the array for last seen indices has a fixed size of 3.

---

## Other Solutions

### Alternative Approaches

The following alternative solutions further optimize the method of counting valid substrings. Each utilizes different techniques, such as bit manipulation and sliding window approaches.

#### Solution 4: Bit Manipulation

```cpp
#pragma GCC target("avx, mmx, sse2, sse3, sse4")

static const int disableSync = [](void) noexcept -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

class Solution final
{
public:
    int numberOfSubstrings(const std::string& string) const noexcept
    {
        int nbSubstrings = 0;
        for (size_t i = string.length() - 1, j = i; j != -1 && (j = i) != -1; --i)
            for (int abc = 0; j != -1; --j)
                if ((abc |= (1 << (string[j] - 'a'))) == 7)
                {
                    nbSubstrings += j + 1;
                    break;
                }
        return nbSubstrings;
    }
};
```

#### Solution 5: Tracking Last Indices

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        int a = -1, b = -1, c = -1, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'a') a = i;
            if (s[i] == 'b') b = i;
            if (s[i] == 'c') c = i;

            if (a >= 0 && b >= 0 && c >= 0) {
                ans += min(a, min(b, c)) + 1;
            }
        }
        return ans;
    }
};
```

#### Solution 6: Using `std::min_element`

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> temp(3, -1);
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            temp[s[i] - 'a'] = i;
            res += 1 + *min_element(temp.begin(), temp.end());
        }
        return res;
    }
};
```

#### Solution 7: Sliding Window Approach

```cpp
class Solution {
public:
    int helper(string s, int k) {
        int i = 0, j = 0;
        unordered_map<char, int> mp;
        int count = 0;

        while (j < s.length()) {
            mp[s[j]]++;

            while (mp.size() > k) {
                mp[s[i]]--;
                if (mp[s[i]] == 0) {
                    mp.erase(s[i]);
                }
                i++;
            }

            count += (j - i + 1);
            j++;
        }

        return count;
    }

    int numberOfSubstrings(string s) {
        return helper(s, 3) - helper(s, 2);
    }
};
```

### Complexity Analysis

- **Time Complexity:** Most of these optimized solutions operate in \(O(n)\), ensuring they handle the upper limits of input size efficiently.
- **Space Complexity:** Most solutions use constant space \(O(1)\) or space proportional to the character set (which is fixed for this problem).

---

## Conclusion

- **Brute Force Approach**: Easy to understand but inefficient for larger inputs due to its \(O(n^2)\) complexity.
- **Optimized Approach**: The use of last seen indices and sliding window techniques allows the problem to be solved in linear time.
- **Key Concept**: Maintaining a dynamic count of the last seen indices of the required characters enables efficient counting of valid substrings.

This implementation provides a comprehensive overview of the various methods to solve the problem of counting substrings containing all three characters `a`, `b`, and `c`. Each solution demonstrates a different technique, illustrating how optimizations can significantly reduce time complexity.
