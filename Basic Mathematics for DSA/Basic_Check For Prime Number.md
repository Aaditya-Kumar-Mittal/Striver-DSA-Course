# Check Prime

## Table of Contents

- [Check Prime](#check-prime)
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
    - [Brute Force](#brute-force)
    - [Optimized (√n)](#optimized-n)
    - [Sieve of Eratosthenes (for multiple queries)](#sieve-of-eratosthenes-for-multiple-queries)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
      - [Brute Force Code](#brute-force-code)
      - [Optimized Code](#optimized-code)
      - [Sieve of Eratosthenes Code](#sieve-of-eratosthenes-code)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

---

## Introduction

A **prime number** is a positive integer greater than 1 that is divisible by exactly **two distinct positive divisors**: 1 and itself. This problem requires checking whether a number `n` is prime or not.

---

## Problem Description

### Task

You are given a number `n`. Determine whether it is a **prime number**.

Return:

- `"YES"` if it's a prime number.
- `"NO"` otherwise.

---

### Examples

#### Example 1

```bash
Input: n = 5
Output: YES
Explanation: 5 is divisible by only 1 and 5.
```

#### Example 2

```bash
Input: n = 6
Output: NO
Explanation: 6 is divisible by 1, 2, 3, and 6.
```

#### Example 3

```bash
Input: n = 1
Output: NO
Explanation: 1 has only one divisor. It is not prime.
```

---

### Constraints

- 1 ≤ n ≤ 10⁹
- Time limit: 1 second

---

## Approach

### Brute Force

- Loop from 1 to `n`, counting how many numbers divide `n`.
- If the count is exactly 2, it’s a prime.
- Time Complexity: O(n)

### Optimized (√n)

- Loop from 2 to `√n`. If any number divides `n`, it's not prime.
- Significantly reduces runtime for large numbers.
- Time Complexity: O(√n)

### Sieve of Eratosthenes (for multiple queries)

- Precompute prime numbers up to a certain `MAXN` using the sieve.
- Answer each query in O(1) time.
- Ideal when checking primality for many numbers in range [1, MAXN].

---

## Detailed Explanation of Code

### C++ Implementation

---

#### Brute Force Code

```cpp
bool isPrimeBrute(int n) {
    if (n <= 1) return false;
    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) count++;
    }
    return (count == 2);
}
```

```cpp
bool isPrime(int n)
{

  /*

  // Brute Force Approach
  int counter = 0;

  for(int i = 1; i <= n; i++)
  {
    if(n % i == 0) counter++;
  }

  if(counter == 2) return true;

  return false;
  */

  int counter = 0;

  for (int i = 1; i <= sqrt(n); i++)
  {
    if (n % i == 0)
    {
      counter++;

      if (n / i != i)
      {
        // Count its reciprocal factor
        counter++;
      }
    }
  }

  if (counter == 2)
    return true;
  return false;
}
```

---

#### Optimized Code

```cpp
bool isPrimeOptimized(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}
```

---

#### Sieve of Eratosthenes Code

```cpp
const int MAXN = 1000001;
bool isPrime[MAXN];

void buildSieve() {
    fill(isPrime, isPrime + MAXN, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAXN; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAXN; j += i) {
                isPrime[j] = false;
            }
        }
    }
}
```

Use this to answer queries quickly:

```cpp
int main() {
    buildSieve();
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (isPrime[n]) cout << "YES\n";
        else cout << "NO\n";
        cout << "~\n";
    }
    return 0;
}
```

---

## Complexity Analysis

| Approach           | Time Complexity | Space Complexity |
| ------------------ | --------------- | ---------------- |
| Brute Force        | O(n)            | O(1)             |
| Optimized (√n)     | O(√n)           | O(1)             |
| Sieve (precompute) | O(n log log n)  | O(n)             |

- Use **Brute Force** only for small `n`.
- Use **Optimized √n** for single large `n`.
- Use **Sieve** for handling many queries up to 10⁶ efficiently.

---

## How to Run the Code

### For C++

1. Copy any of the provided implementations into a `.cpp` file.
2. Compile using:

   ```bash
   g++ -o check_prime check_prime.cpp
   ```

3. Run with:

   ```bash
   ./check_prime
   ```

---
