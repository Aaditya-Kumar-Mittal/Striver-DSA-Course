# Finger Game

## Table of Contents

- [Finger Game](#finger-game)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Explanation](#explanation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

In this problem, you are required to simulate counting on your fingers in a particular pattern and determine on which finger a given number ends. This exercise is simple yet interesting, focusing on pattern recognition and modulo arithmetic.

---

## Problem Description

We start counting from the **thumb (1st finger)**, then proceed to:

- **Index finger (2nd)**
- **Middle finger (3rd)**
- **Ring finger (4th)**
- **Little finger (5th)**

![Finger Count](https://contribute.geeksforgeeks.org/wp-content/uploads/finger-game.jpg)

After reaching the little finger, the counting direction reverses:

- **6th count is on ring finger (4th)**
- **7th count is on middle finger (3rd)**
- **8th count is on index finger (2nd)**
- **9th count is on thumb again (1st)**

This repeating pattern follows a cycle of 8. The task is to determine the finger number (1 to 5) where a given number `N` ends.

### Examples

#### Example 1

**Input:**  
`N = 3`  
**Output:**  
`3`  
**Explanation:**  
The third count lands on the middle finger.

#### Example 2

**Input:**  
`N = 6`  
**Output:**  
`4`  
**Explanation:**  
The 6th count is on the ring finger due to reverse counting after the 5th count.

---

### Constraints

- 1 ≤ N ≤ 10⁶

---

## Approach

The counting follows a periodic pattern of 8 steps:

```plaintext
1 (Thumb)      → 1
2 (Index)      → 2
3 (Middle)     → 3
4 (Ring)       → 4
5 (Little)     → 5
6 (Ring)       → 4
7 (Middle)     → 3
8 (Index)      → 2
9 (Thumb)      → 1
... (Repeats)
```

Thus, this 8-count cycle can be used with `N % 8` to determine the finger:

- Remainder 1 → Thumb (1)
- Remainder 2 or 0 → Index (2)
- Remainder 3 or 7 → Middle (3)
- Remainder 4 or 6 → Ring (4)
- Remainder 5 → Little (5)

This means we can solve the problem in **O(1)** time using conditional checks.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    int fingerCount(int N) {
        // Determine the position in the 8-step cycle
        if (N % 8 == 1) return 1;           // Thumb
        else if (N % 8 == 2 || N % 8 == 0) return 2; // Index
        else if (N % 8 == 3 || N % 8 == 7) return 3; // Middle
        else if (N % 8 == 4 || N % 8 == 6) return 4; // Ring
        else return 5; // N % 8 == 5 -> Little
    }
};
```

```cpp

class Solution
{
public:
    int fingerCount(int N)
    {
        // Write Your Code here

        if(N % 8 == 1) return 1;

        else if(N % 4 == 3) return 3;

        else if(N % 8 == 5) return 5;

        else if(N % 8 == 2 || N % 8 == 0) return 2;

        else return 4;
    }
};
```

#### Explanation

- Uses modulo operation to find the remainder of N in the 8-step cycle.
- Returns the correct finger based on predefined mapping of each remainder.
- Covers all 8 cases using conditional checks.

---

## Complexity Analysis

- **Time Complexity:** `O(1)`  
  Uses only modulo and simple conditional logic.

- **Space Complexity:** `O(1)`  
  No extra space is used.

---

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file.
2. Include a `main()` function to take input and print output (for testing).
3. Compile and run using a C++ compiler like `g++`.

```cpp
#include <iostream>
using namespace std;

class Solution {
public:
    int fingerCount(int N) {
        if (N % 8 == 1) return 1;
        else if (N % 8 == 2 || N % 8 == 0) return 2;
        else if (N % 8 == 3 || N % 8 == 7) return 3;
        else if (N % 8 == 4 || N % 8 == 6) return 4;
        else return 5;
    }
};

int main() {
    Solution sol;
    int N;
    cout << "Enter a number: ";
    cin >> N;
    cout << "Finger number: " << sol.fingerCount(N) << endl;
    return 0;
}
```

Compile with:

```sh
g++ -o finger_game finger_game.cpp
./finger_game
```

---
