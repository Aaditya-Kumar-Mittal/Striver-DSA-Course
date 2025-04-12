# Rotate Array According To Direction

<!-- markdownlint-disable MD029 -->

## Table of Contents

- [Rotate Array According To Direction](#rotate-array-according-to-direction)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Sample Input 1](#sample-input-1)
      - [Sample Output 1](#sample-output-1)
      - [Explanation](#explanation)
      - [Sample Input 2](#sample-input-2)
      - [Sample Output 2](#sample-output-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

This problem is a variation of array rotation, where you are given the direction and number of times an array needs to be rotated. You must implement the solution efficiently, considering both forward and backward directions with potentially large values of rotation.

---

## Problem Description

You are given:

- An array `num` of `n` integers.
- A direction character `d`:
  - `'f'` for **forward (right)** rotation
  - `'b'` for **backward (left)** rotation
- An integer `r` representing the number of times to rotate the array.

You must **rotate the array `r` times** in the given direction and output the modified array.

---

### Examples

#### Sample Input 1

```bash
2
3
2 4 7
f
1
3
3 2 1
b
2
```

#### Sample Output 1

```bash
7 2 4
1 3 2
```

#### Explanation

**Test Case 1:**

- Array: [2, 4, 7], Direction: forward ('f'), Rotations: 1
- After 1 forward rotation → [7, 2, 4]

**Test Case 2:**

- Array: [3, 2, 1], Direction: backward ('b'), Rotations: 2
- After 1 left rotation → [2, 1, 3]
- After 2nd left rotation → [1, 3, 2]

---

#### Sample Input 2

```bash
2
3
4 6 2
f
5
2
9 10
f
0
```

#### Sample Output 2

```bash
6 2 4
9 10
```

---

### Constraints

- `1 <= T <= 10`
- `1 <= N <= 100000`
- `1 <= num[i] <= 10^7`
- `D` ∈ `{ 'f', 'b' }`
- `0 <= R <= 10^7`
- The sum of all N over all test cases will not exceed 10^5
- Time limit: 1 second

---

## Approach

This problem uses the **Reversal Algorithm** for array rotation. The idea is to reverse parts of the array and then the whole array to simulate the rotation efficiently.

Instead of performing `R` separate shifts (which would be time-consuming for large `R`), we reduce the rotation count using modulo:

```cpp
r = r % n;
```

Based on the direction:

- For **left rotation (`b`)**:  
  `reverse(0, r)`, `reverse(r, n)`, then `reverse(0, n)`
- For **right rotation (`f`)**:  
  `reverse(0, n - r)`, `reverse(n - r, n)`, then `reverse(0, n)`

This gives us an optimal and in-place solution.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

void rotateArrayTwo(int n, char d, int r, vector<int> &num) {
    r = r % n;  // Normalize R to prevent unnecessary full rotations

    if (r == 0) return;

    if (d == 'b') {
        // Backward (left) rotation
        reverse(num.begin(), num.begin() + r);        // Step 1: Reverse first r elements
        reverse(num.begin() + r, num.end());          // Step 2: Reverse remaining elements
    }
    else if (d == 'f') {
        // Forward (right) rotation
        reverse(num.begin(), num.end() - r);          // Step 1: Reverse first n-r elements
        reverse(num.end() - r, num.end());            // Step 2: Reverse last r elements
    }

    reverse(num.begin(), num.end());                  // Final step: Reverse the entire array
}
```

---

## Complexity Analysis

| Metric           | Value |
| ---------------- | ----- |
| Time Complexity  | O(N)  |
| Space Complexity | O(1)  |

- Each `reverse()` operation is O(K), where K is the number of elements in that segment.
- Since at most three reversals are made on the array, the time complexity remains O(N).
- No extra space is used — all operations are performed in-place.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `rotate_array.cpp`.

2. Add a `main()` function to test:

  ```cpp
  int main() {
      int T;
      cin >> T;
      while (T--) {
          int N;
          cin >> N;
          vector<int> num(N);
          for (int i = 0; i < N; ++i) cin >> num[i];
          char D;
          cin >> D;
          int R;
          cin >> R;

          rotateArrayTwo(N, D, R, num);
          for (int x : num) cout << x << " ";
          cout << endl;
      }
      return 0;
  }
  ```

3. Compile and run:

  ```bash
  g++ rotate_array.cpp -o rotate_array
  ./rotate_array
  ```

4. Provide input as shown in the sample test cases.
