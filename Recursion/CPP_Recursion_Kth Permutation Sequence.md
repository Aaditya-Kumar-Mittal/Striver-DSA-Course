# Kth Permutation Sequence Problem

## Table of Contents

- [Kth Permutation Sequence Problem](#kth-permutation-sequence-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Observations](#key-observations)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)

---

## Introduction

The problem involves finding the `k`-th permutation sequence of numbers `[1, 2, 3, ..., n]`. The solution avoids generating all permutations explicitly, instead directly determining the required permutation using mathematical properties.

---

## Problem Description

### Input

- `n`: Size of the sequence, where `1 ≤ n ≤ 9`.
- `k`: Index of the desired permutation (1-based).

### Output

- The `k`-th permutation sequence as a string.

---

### Examples

#### Example 1

**Input:**  

```plaintext
n = 3, k = 3
```

**Output:**  

```plaintext
"213"
```

---

#### Example 2

**Input:**  

```plaintext
n = 4, k = 9
```

**Output:**  

```plaintext
"2314"
```

---

#### Example 3

**Input:**  

```plaintext
n = 3, k = 1
```

**Output:**  

```plaintext
"123"
```

---

### Constraints

- `1 ≤ n ≤ 9`
- `1 ≤ k ≤ n!`

---

## Approach

### Key Observations

1. **Factorial Representation**:  
   Each permutation set for a digit is split into `(n-1)!` groups.  
   For example, for `n=4`:  
   - Group 1: `{1234, 1243, ...}`  
   - Group 2: `{2134, 2143, ...}`

2. **Direct Calculation**:  
   By identifying the group in which `k` falls, digits can be selected sequentially.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;

        // Calculate (n-1)! and initialize numbers
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k = k - 1; // Convert to 0-based index

        // Generate the permutation
        while (true) {
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);

            if (numbers.size() == 0)
                break;

            k %= fact;
            fact /= numbers.size();
        }

        return ans;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public String getPermutation(int n, int k) {
        int fact = 1;
        List<Integer> numbers = new ArrayList<>();

        // Calculate (n-1)! and initialize numbers
        for (int i = 1; i < n; i++) {
            fact *= i;
            numbers.add(i);
        }
        numbers.add(n);

        StringBuilder ans = new StringBuilder();
        k = k - 1; // Convert to 0-based index

        // Generate the permutation
        while (!numbers.isEmpty()) {
            ans.append(numbers.get(k / fact));
            numbers.remove(k / fact);

            if (numbers.isEmpty())
                break;

            k %= fact;
            fact /= numbers.size();
        }

        return ans.toString();
    }
}
```

---

## Complexity Analysis

1. **Time Complexity**:  
   - Generating the `k`-th permutation involves removing digits sequentially, resulting in `O(n)`.

2. **Space Complexity**:  
   - `O(n)` for storing the `numbers` list/vector.

---

This document provides both C++ and Java implementations to efficiently compute the `k`-th permutation sequence without generating all permutations explicitly.
