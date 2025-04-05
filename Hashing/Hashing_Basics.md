# Number and Character Hashing in C++ (Using Arrays, `map`, and `unordered_map`)

## Table of Contents

- [Number and Character Hashing in C++ (Using Arrays, `map`, and `unordered_map`)](#number-and-character-hashing-in-c-using-arrays-map-and-unordered_map)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Number Hashing](#number-hashing)
      - [Using Arrays](#using-arrays)
      - [Using `map` / `unordered_map`](#using-map--unordered_map)
    - [Character Hashing](#character-hashing)
      - [Lowercase Characters](#lowercase-characters)
      - [Uppercase Characters](#uppercase-characters)
      - [All ASCII Characters](#all-ascii-characters)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

Hashing is a method used to quickly access data through a key. In competitive programming and real-world software systems, hashing is essential for problems involving frequency counting, lookups, and set-like behavior. This guide will explore number and character hashing using:

- Arrays for small range keys
- `map` and `unordered_map` from STL for large or dynamic key ranges

---

## Problem Description

- Use hashing to store and retrieve frequency of elements or characters.
- Handle constraints for large inputs.
- Apply optimal time complexity approaches for insertion and lookup.

### Examples

**Example 1:** Number Hashing using `unordered_map`

```cpp
unordered_map<int, int> mpp;
mpp[10] = 1;
mpp[20] += 2;
cout << mpp[20]; // Output: 2
```

**Example 2:** Character Hashing using ASCII mapping

```cpp
char ch = 'd';
int hash[26] = {0};
hash[ch - 'a']++;
cout << hash['d' - 'a']; // Output: 1
```

### Constraints

- `int arr[10^6];` → Valid inside `main()`
- Arrays larger than `10^6` → Declare globally
- For `10^9` or higher → Use `map` or `unordered_map`
- Use ASCII-based indexing for characters

---

## Approach

- Use arrays when key range is small and continuous.
- Use `map` for sorted access and log(N) complexity.
- Use `unordered_map` for O(1) average time and better performance under typical scenarios.
- Use character ASCII manipulation for hashing lowercase/uppercase characters.

---

## Detailed Explanation of Code

### Number Hashing

#### Using Arrays

```cpp
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int hashArray[N] = {0}; // Declare globally for large size

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        hashArray[num]++;
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << hashArray[x] << endl;
    }
    return 0;
}
```

#### Using `map` / `unordered_map`

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    unordered_map<int, int> mpp; // O(1) average case
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        mpp[num]++;
    }

    int q; cin >> q;
    while (q--) {
        int x; cin >> x;
        cout << mpp[x] << endl;  // returns 0 if key doesn't exist
    }
    return 0;
}
```

> ⚠️ Use `map<int, int>` for log(N) operations in sorted order.

---

### Character Hashing

#### Lowercase Characters

```cpp
char ch = 'd';
int hashLower[26] = {0};
hashLower[ch - 'a']++;
```

#### Uppercase Characters

```cpp
char ch = 'B';
int hashUpper[26] = {0};
hashUpper[ch - 'A']++;
```

#### All ASCII Characters

```cpp
int hashAll[256] = {0};
char ch = '@';
hashAll[ch]++;
```

---

## Complexity Analysis

| Operation          | `map`       | `unordered_map` | Array       |
|--------------------|-------------|------------------|-------------|
| Insertion          | O(log N)    | O(1) avg, O(N) worst | O(1) |
| Lookup             | O(log N)    | O(1) avg, O(N) worst | O(1) |
| Deletion           | O(log N)    | O(1) avg, O(N) worst | O(1) |
| Traversal          | O(N) (sorted) | O(N) (unsorted) | O(N) |

- **Space Complexity:** O(N), depending on the number of keys

> **Note:** Use `unordered_map` for speed, but prefer `map` when order matters or when TLE occurs due to worst-case behavior from hash collisions.

---

## How to Run the Code

### For C++

1. Save code in a `.cpp` file, e.g., `hashing.cpp`
2. Compile using:

   ```bash
   g++ -o hashing hashing.cpp
   ```

3. Run the executable:

   ```bash
   ./hashing
   ```

**Sample Input:**

```bash
5
1 2 2 3 1
3
1
2
3
```

**Sample Output:**

```bash
2
2
1
```

---
