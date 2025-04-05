# Sum 1 to n Divisors

## Table of Contents

- [Sum 1 to n Divisors](#sum-1-to-n-divisors)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Brute-force](#brute-force)
    - [Optimized](#optimized)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Brute-force Method](#brute-force-method)
      - [Optimized Method](#optimized-method)
    - [Driver Code](#driver-code)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

Given a number `n`, we are required to compute the sum of all divisors for each number from `1` to `n`. That is, we want to calculate:

\[
\sum\_{i=1}^{n} F(i)
\]

where `F(i)` is the **sum of all divisors** of the integer `i`.

---

## Problem Description

### Task

Given a number `n`, return the result of summing all divisors for every number from `1` to `n`.

### Examples

#### Example 1

**Input:**  
`n = 4`  
**Output:**  
`15`  
**Explanation:**

- F(1) = 1
- F(2) = 1 + 2 = 3
- F(3) = 1 + 3 = 4
- F(4) = 1 + 2 + 4 = 7
- Total = 1 + 3 + 4 + 7 = **15**

#### Example 2

**Input:**  
`n = 5`  
**Output:**  
`21`  
**Explanation:**

- F(1) = 1
- F(2) = 3
- F(3) = 4
- F(4) = 7
- F(5) = 6
- Total = 1 + 3 + 4 + 7 + 6 = **21**

#### Example 3

**Input:**  
`n = 1`  
**Output:**  
`1`  
**Explanation:**

- F(1) = 1

---

### Constraints

- 1 ≤ n ≤ 10^5

---

## Approach

### Brute-force

- For each number from `1` to `n`, calculate its divisors by checking every number `1` to `i`.
- Sum the divisors and accumulate them.

### Optimized

- For every possible divisor `i`, calculate how many times it is a divisor in the range `1` to `n`.
- For each divisor `i`, it contributes `i * ⌊n / i⌋` to the total sum.

\[
\sum\_{i=1}^{n} i \cdot \left\lfloor \frac{n}{i} \right\rfloor
\]

This approach dramatically reduces the time complexity.

---

## Detailed Explanation of Code

### C++ Implementation

#### Brute-force Method

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Returns all divisors of a number i
    set<int> getAllDivisors(int n) {
        set<int> divisors;
        for (int i = 1; i <= sqrt(n); i++) {
            if (n % i == 0) {
                divisors.insert(i);
                if (i != n / i) {
                    divisors.insert(n / i);
                }
            }
        }
        return divisors;
    }

    // Sum of divisors from 1 to n using brute-force
    int sumOfDivisorsBrute(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            set<int> divs = getAllDivisors(i);
            for (auto val : divs) {
                sum += val;
            }
        }
        return sum;
    }
};
```

---

#### Optimized Method

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Optimized sum using divisor contribution method
    int getDivisorSum1(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            sum += i * (n / i);
        }
        return sum;
    }

    // Main function
    int sumOfDivisors(int n) {
        return getDivisorSum1(n);
    }
};
```

---

### Driver Code

```cpp
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;

        // Choose method here:
        // int ans = ob.sumOfDivisorsBrute(N);  // For Brute-force
        int ans = ob.sumOfDivisors(N);         // For Optimized

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
```

---

## Complexity Analysis

| Method      | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Brute-force | O(n√n)          | O(n)             |
| Optimized   | O(n)            | O(1)             |

---

## How to Run the Code

### For C++

1. Save all the code in a file named `main.cpp`
2. Compile and Run:

   ```bash
   g++ main.cpp -o main
   ./main
   ```

3. **Sample Input:**

   ```bash
   2
   4
   5
   ```

4. **Sample Output:**

   ```bash
   15
   ~
   21
   ~
   ```
