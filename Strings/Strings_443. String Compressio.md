# String Compression

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [String Compression](#string-compression)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Task](#task)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [Example Run](#example-run)
  - [Summary](#summary)
    - [Other Solution](#other-solution)
      - [Approach: In-Place Compression](#approach-in-place-compression)
      - [Complexity Analysis](#complexity-analysis-1)
      - [Key Points](#key-points)

## Introduction

The `compress` function modifies a given character array in-place by compressing consecutive duplicate characters and storing the count after each unique character. The function returns the new length of the compressed array.

## Problem Description

### Given

A vector of characters `chars` containing:

- Lowercase English letters (`a-z`).

### Task

- Modify the array by replacing consecutive duplicate characters with a single occurrence followed by the count.
- If a character appears once, it remains unchanged.
- Return the new length of the compressed array.

## Examples

### Example 1

**Input:**

```cpp
chars = ['a', 'a', 'b', 'b', 'c', 'c', 'c']
```

**Output:**

```cpp
6 (chars = ['a', '2', 'b', '2', 'c', '3'])
```

**Explanation:**

- 'a' appears twice → "a2".
- 'b' appears twice → "b2".
- 'c' appears three times → "c3".

### Example 2

**Input:**

```cpp
chars = ['a']
```

**Output:**

```cpp
1 (chars = ['a'])
```

**Explanation:**

- Only one character, no compression needed.

### Example 3

**Input:**

```cpp
chars = ['a', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'b', 'c']
```

**Output:**

```cpp
4 (chars = ['a', 'b', '1', '0', 'c'])
```

**Explanation:**

- 'a' appears once → "a".
- 'b' appears ten times → "b10".
- 'c' appears once → "c".

## Constraints

- `1 <= chars.length <= 2000`
- `chars[i]` is a lowercase English letter.

## Approach

1. Initialize an index `idx` to track the position of the compressed array.
2. Traverse the array while counting occurrences of each character.
3. If a character occurs more than once, append the count after it.
4. Convert multi-digit counts into characters and append them to the array.
5. Resize the array to match the compressed length and return the new size.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int idx = 0;
        int n = chars.size();

        for (int i = 0; i < n; i++) {
            char ch = chars[i];
            int count = 0;

            while (i < n && chars[i] == ch) {
                i++;
                count++;
            }

            chars[idx++] = ch;

            if (count > 1) {
                string str = to_string(count);
                for (char digit : str) {
                    chars[idx++] = digit;
                }
            }

            i--;
        }

        chars.resize(idx);
        return chars.size();
    }
};

// Driver Code
int main() {
    Solution solution;
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};

    int compressedLength = solution.compress(chars);

    cout << "Compressed Length: " << compressedLength << endl;
    cout << "Compressed Array: ";
    for (char c : chars) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
```

## Complexity Analysis

### Time Complexity

- **O(n):** We traverse the list once, processing each character in a single pass.

### Space Complexity

- **O(1):** Compression happens in-place, so no extra space is used apart from a few integer variables.

## How to Run the Code

### For C++

1. Save the code in a file named `compress.cpp`.
2. Compile the program:

   ```sh
   g++ -o compress compress.cpp
   ```

3. Run the executable:

   ```sh
   ./compress
   ```

### Example Run

**Input:**

```cpp
chars = ['a', 'a', 'b', 'b', 'c', 'c', 'c']
```

**Expected Output:**

```sh
Compressed Length: 6
Compressed Array: a 2 b 2 c 3
```

## Summary

| Step | Description                                            |
| ---- | ------------------------------------------------------ |
| 1    | Initialize an index for compressed array               |
| 2    | Traverse the array and count character occurrences     |
| 3    | Append the character and its count (if greater than 1) |
| 4    | Resize the array to the compressed length              |
| 5    | Return the new length                                  |

### Other Solution

Here is the detailed explanation and implementation of the **String Compression** problem using the in-place approach. The solution involves compressing the string by replacing consecutive repeating characters with the character followed by the count of repetitions.

---

#### Approach: In-Place Compression

Intuition:  
The problem requires compressing the string in-place, meaning we need to modify the input array `chars` directly. We can achieve this by iterating through the array, identifying groups of consecutive repeating characters, and replacing them with the character followed by the count of repetitions.

Algorithm:

1. Initialize two pointers: `res` (to track the position in the compressed array) and `i` (to iterate through the original array).
2. While `i` is within the bounds of the array:
   - Find the length of the current group of consecutive repeating characters (`groupLength`).
   - Write the character to the compressed array at position `res`.
   - If `groupLength > 1`, convert the count to a string and write each digit to the compressed array.
   - Move the `i` pointer to the start of the next group.
3. Return the length of the compressed array (`res`).

Implementation:

C++ Code:

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int res = 0, i = 0;

        while (i < n) {
            char currentChar = chars[i];
            int groupLength = 0;

            // Find the length of the current group
            while (i < n && chars[i] == currentChar) {
                groupLength++;
                i++;
            }

            // Write the character to the compressed array
            chars[res++] = currentChar;

            // Write the count if groupLength > 1
            if (groupLength > 1) {
                string countStr = to_string(groupLength);
                for (char c : countStr) {
                    chars[res++] = c;
                }
            }
        }

        return res;
    }
};
```

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, res = 0;
        while (i < chars.size()) {
            int groupLength = 1;
            while (i + groupLength < chars.size() && chars[i + groupLength] == chars[i]) {
                groupLength++;
            }
            chars[res++] = chars[i];
            if (groupLength > 1) {
                for (char c : to_string(groupLength)) {
                    chars[res++] = c;
                }
            }
            i += groupLength;
        }
        return res;
    }
};
```

Java Code:

```java
class Solution {
    public int compress(char[] chars) {
        int n = chars.length;
        int res = 0, i = 0;

        while (i < n) {
            char currentChar = chars[i];
            int groupLength = 0;

            // Find the length of the current group
            while (i < n && chars[i] == currentChar) {
                groupLength++;
                i++;
            }

            // Write the character to the compressed array
            chars[res++] = currentChar;

            // Write the count if groupLength > 1
            if (groupLength > 1) {
                String countStr = Integer.toString(groupLength);
                for (char c : countStr.toCharArray()) {
                    chars[res++] = c;
                }
            }
        }

        return res;
    }
}
```

Python Code:

```python
class Solution:
    def compress(self, chars: List[str]) -> int:
        n = len(chars)
        res = i = 0

        while i < n:
            current_char = chars[i]
            group_length = 0

            # Find the length of the current group
            while i < n and chars[i] == current_char:
                group_length += 1
                i += 1

            # Write the character to the compressed array
            chars[res] = current_char
            res += 1

            # Write the count if group_length > 1
            if group_length > 1:
                for digit in str(group_length):
                    chars[res] = digit
                    res += 1

        return res
```

---

#### Complexity Analysis

- **Time Complexity:** `O(n)`
  - We iterate through the array once to find groups of consecutive repeating characters and write the compressed result. Each character is processed at most twice (once for counting and once for writing).
- **Space Complexity:** `O(1)`
  - The algorithm uses constant extra space, as we are modifying the input array in-place.

---

#### Key Points

1. **In-Place Modification:** The solution modifies the input array directly, avoiding the use of additional space.
2. **Group Length Calculation:** The length of each group of consecutive repeating characters is calculated and written to the compressed array.
3. **Efficient Compression:** The algorithm ensures that the compressed string is always shorter than or equal to the original string.

---

This approach is efficient and meets the problem's requirements for in-place modification and optimal time complexity.
