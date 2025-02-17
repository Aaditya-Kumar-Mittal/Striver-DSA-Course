# Boolean Parenthesization

## Table of Contents

- [Boolean Parenthesization](#boolean-parenthesization)
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
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [Tabulation Solution](#tabulation-solution)
    - [My Coding Ninjas Solution](#my-coding-ninjas-solution)

## Introduction

The **Boolean Parenthesization** problem requires us to find the number of ways in which a given Boolean expression can be parenthesized such that it evaluates to `True`. The expression contains the symbols:

- `'T'` (True)
- `'F'` (False)
  and the operators:
- `&` (AND)
- `|` (OR)
- `^` (XOR)

## Problem Description

Given a boolean expression as a string, we need to determine the number of ways to insert parentheses such that the expression evaluates to `True`. The result should fit within a 32-bit integer.

### Examples

#### Example 1

**Input:**

```cpp
s = "T|T&F^T"
```

**Output:**

```cpp
4
```

**Explanation:**
The expression evaluates to `True` in 4 ways:

1. `((T|T)&(F^T))`
2. `(T|(T&(F^T)))`
3. `(((T|T)&F)^T)`
4. `(T|((T&F)^T))`

#### Example 2

**Input:**

```cpp
s = "T^F|F"
```

**Output:**

```cpp
2
```

**Explanation:**
The expression evaluates to `True` in 2 ways:

1. `((T^F)|F)`
2. `(T^(F|F))`

### Constraints

- `1 ≤ |s| ≤ 100`
- The string consists of characters `'T'`, `'F'`, `&`, `|`, and `^` only.

## Approach

The problem can be solved using **Dynamic Programming** with **Memoization** to avoid redundant computations. The key idea is:

1. Consider different places to split the expression at an operator.
2. Recursively evaluate the number of ways to obtain `True` and `False` from the left and right subexpressions.
3. Use the given Boolean operator to combine the left and right subexpressions based on whether we are computing `True` or `False`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#define ll long long
class Solution {
public:
    int mod = 1e9;  // Modulo to prevent overflow

    // Recursive function without memoization
    ll recursive_solution(int i, int j, int isTrue, string &exp) {
        if (i > j) return 0;
        if (i == j) return isTrue ? exp[i] == 'T' : exp[i] == 'F';

        ll ways = 0;
        for (int index = i + 1; index <= j - 1; index += 2) {
            ll leftT = recursive_solution(i, index - 1, 1, exp);
            ll leftF = recursive_solution(i, index - 1, 0, exp);
            ll rightT = recursive_solution(index + 1, j, 1, exp);
            ll rightF = recursive_solution(index + 1, j, 0, exp);

            if (exp[index] == '&') {
                ways += isTrue ? (leftT * rightT) : (leftT * rightF + leftF * rightT + leftF * rightF);
            } else if (exp[index] == '|') {
                ways += isTrue ? (leftT * rightF + leftF * rightT + leftT * rightT) : (leftF * rightF);
            } else if (exp[index] == '^') {
                ways += isTrue ? (leftT * rightF + leftF * rightT) : (leftF * rightF + leftT * rightT);
            }
        }
        return ways;
    }

    // Memoized recursive solution
    ll recursive_solution_memoized(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>>& dp) {
        if (i > j) return 0;
        if (i == j) return isTrue ? exp[i] == 'T' : exp[i] == 'F';

        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        ll ways = 0;
        for (int index = i + 1; index <= j - 1; index += 2) {
            ll leftT = recursive_solution_memoized(i, index - 1, 1, exp, dp);
            ll leftF = recursive_solution_memoized(i, index - 1, 0, exp, dp);
            ll rightT = recursive_solution_memoized(index + 1, j, 1, exp, dp);
            ll rightF = recursive_solution_memoized(index + 1, j, 0, exp, dp);

            if (exp[index] == '&') {
                ways += isTrue ? (leftT * rightT) : (leftT * rightF + leftF * rightT + leftF * rightF);
            } else if (exp[index] == '|') {
                ways += isTrue ? (leftT * rightF + leftF * rightT + leftT * rightT) : (leftF * rightF);
            } else if (exp[index] == '^') {
                ways += isTrue ? (leftT * rightF + leftF * rightT) : (leftF * rightF + leftT * rightT);
            }
        }
        return dp[i][j][isTrue] = ways;
    }

    // Main function
    int countWays(string s) {
        int n = s.size();
        vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
        return recursive_solution_memoized(0, n - 1, 1, s, dp);
    }
};
```

## Complexity Analysis

- **Recursive Solution:** Exponential `O(2^N)`, as each operator introduces multiple subproblems.
- **Memoized Solution:** `O(N^3)`, since we use `dp[i][j][isTrue]` to store computed results, avoiding redundant calls.

## How to Run the Code

1. Compile the C++ program using:

   ```sh
   g++ -o boolean_parenthesization boolean_parenthesization.cpp
   ```

2. Run the executable:

   ```sh
   ./boolean_parenthesization
   ```

3. Provide an input string in the function call and observe the output.

---

## Other Solutions

### Tabulation Solution

```cpp

#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 0)));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j <= n - 1; j++) {
            // Base case 1: i > j is an invalid case, so continue.
            if (i > j) continue;

            for (int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character.
                if (i == j) {
                    if (isTrue == 1) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // Recurrence logic:
                ll ways = 0;
                for (int ind = i + 1; ind <= j - 1; ind += 2) {
                    ll lT = dp[i][ind - 1][1];
                    ll lF = dp[i][ind - 1][0];
                    ll rT = dp[ind + 1][j][1];
                    ll rF = dp[ind + 1][j][0];

                    if (exp[ind] == '&') {
                        if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
                    }
                    else if (exp[ind] == '|') {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod) % mod;
                    }
                    else {
                        if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
                        else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
                    }
                }
                dp[i][j][isTrue] = ways;
            }
        }
    }
    return dp[0][n - 1][1];
}

int main() {
    string exp = "F|T^F";
    int ways = evaluateExp(exp);
    cout << "The total number of ways: " << ways << "\n";
    return 0;
}

```

### My Coding Ninjas Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int mod = 1e9 + 7; // Corrected modulo value

ll recursive_solution_memoized(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp)
{
  if (i > j)
    return 0;

  if (i == j)
  {
    if (isTrue)
      return exp[i] == 'T';
    else
      return exp[i] == 'F';
  }

  if (dp[i][j][isTrue] != -1)
    return dp[i][j][isTrue];

  ll ways = 0;

  for (int index = i + 1; index <= j - 1; index += 2)
  {
    ll leftT = recursive_solution_memoized(i, index - 1, 1, exp, dp);
    ll leftF = recursive_solution_memoized(i, index - 1, 0, exp, dp);
    ll rightT = recursive_solution_memoized(index + 1, j, 1, exp, dp);
    ll rightF = recursive_solution_memoized(index + 1, j, 0, exp, dp);

    if (exp[index] == '&')
    {
      if (isTrue)
        ways = (ways + (leftT * rightT) % mod) % mod;
      else
        ways = (ways + (leftT * rightF) % mod + (leftF * rightT) % mod + (leftF * rightF) % mod) % mod;
    }
    else if (exp[index] == '|')
    {
      if (isTrue)
        ways = (ways + (leftT * rightF) % mod + (leftF * rightT) % mod + (leftT * rightT) % mod) % mod;
      else
        ways = (ways + (leftF * rightF) % mod) % mod;
    }
    else if (exp[index] == '^')
    {
      if (isTrue)
        ways = (ways + (leftT * rightF) % mod + (leftF * rightT) % mod) % mod;
      else
        ways = (ways + (leftF * rightF) % mod + (leftT * rightT) % mod) % mod;
    }
  }

  return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp)
{
  int n = exp.size();
  // Initialize DP table with -1
  vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
  ll result = recursive_solution_memoized(0, n - 1, 1, exp, dp);

  return (int)result;
}
```
