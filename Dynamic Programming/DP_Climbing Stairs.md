# Climbing Stairs

## Table of Contents

- [Climbing Stairs](#climbing-stairs)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Approach](#recursive-approach)
    - [Dynamic Programming Approach](#dynamic-programming-approach)
    - [Optimized Space Approach](#optimized-space-approach)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [C++](#c)
    - [Java](#java)
  - [Other Solutions](#other-solutions)
    - [Approach 1: Recursion](#approach-1-recursion)
    - [Approach 2: Memoization](#approach-2-memoization)
    - [Approach 3: Tabulation](#approach-3-tabulation)
    - [Approach 4: Space Optimization](#approach-4-space-optimization)

---

## Introduction

The **Climbing Stairs** problem is a classic example of solving using dynamic programming. The task is to find the number of distinct ways to climb a staircase with \( n \) steps, where you can either climb 1 or 2 steps at a time.

---

## Problem Description

**Input:**

- An integer \( n \) representing the total number of steps.

**Output:**

- An integer representing the number of distinct ways to reach the top.

---

## Examples

### Example 1

**Input:**

```bash
n = 2
```

**Output:**

```bash
2
```

**Explanation:**

- Possible ways:
  1. 1 step + 1 step
  2. 2 steps

---

### Example 2

**Input:**

```bash
n = 3
```

**Output:**

```bash
3
```

**Explanation:**

- Possible ways:
  1. 1 step + 1 step + 1 step
  2. 1 step + 2 steps
  3. 2 steps + 1 step

---

## Constraints

- \( 1 \leq n \leq 45 \)

---

## Approach

### Recursive Approach

The problem can be solved using recursion:

- At each step, you can either take 1 step or 2 steps.
- The total ways to reach \( n \) is the sum of ways to reach \( n-1 \) and \( n-2 \).

**Formula:**
\[
f(n) = f(n-1) + f(n-2)
\]

### Dynamic Programming Approach

Use an array to store results of subproblems:

1. Define \( dp[i] \) as the number of ways to reach the \( i \)-th step.
2. Base cases:
   - \( dp[0] = 1 \) (1 way to stay at the start).
   - \( dp[1] = 1 \) (1 way to take 1 step).
3. Transition:
   - \( dp[i] = dp[i-1] + dp[i-2] \).

### Optimized Space Approach

Instead of using an array, store only the last two results, as they are sufficient for calculation:

1. Use two variables, `last1` and `last2`, to store the previous two results.
2. Iterate from 2 to \( n \), updating the variables.

---

## Code

### C++ Implementation

```cpp
class Solution {
public:
    // Recursive approach (inefficient for large n)
    int countWays(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        return countWays(n - 1) + countWays(n - 2);
    }

    // Optimized DP approach
    int climbStairs(int n) {
        if (n <= 1) return 1;

        int last1 = 1;  // Ways to climb 1 step
        int last2 = 1;  // Ways to climb 0 steps
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            ans = last1 + last2;  // Current ways
            last2 = last1;       // Update last2 to last1
            last1 = ans;         // Update last1 to current ways
        }

        return last1;
    }
};
```

---

### Java Implementation

```java
class Solution {
    // Recursive approach (inefficient for large n)
    public int countWays(int n) {
        if (n == 0) return 1;
        if (n == 1) return 1;
        return countWays(n - 1) + countWays(n - 2);
    }

    // Optimized DP approach
    public int climbStairs(int n) {
        if (n <= 1) return 1;

        int last1 = 1;  // Ways to climb 1 step
        int last2 = 1;  // Ways to climb 0 steps
        int ans = 0;

        for (int i = 2; i <= n; i++) {
            ans = last1 + last2;  // Current ways
            last2 = last1;       // Update last2 to last1
            last1 = ans;         // Update last1 to current ways
        }

        return last1;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- Recursive approach: \( O(2^n) \) (Exponential).
- Dynamic programming approach: \( O(n) \) (Linear).
- Optimized space approach: \( O(n) \) (Linear).

### Space Complexity

- Recursive approach: \( O(n) \) (Call stack depth).
- Dynamic programming approach: \( O(n) \) (Array storage).
- Optimized space approach: \( O(1) \) (Only two variables).

---

## How to Run the Code

### C++

1. Save the code to `solution.cpp`.
2. Compile using:

   ```bash
   g++ -std=c++17 -o solution solution.cpp
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

### Java

1. Save the code to `Solution.java`.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the class:

   ```bash
   java Solution
   ```

## Other Solutions

### Approach 1: Recursion

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
```

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
}
```

- Time Complexity: \( O(2^n) \) (Exponential). Gives Time Limit Exceeded.
- Space Complexity: \( O(n) \) (Call stack depth).

### Approach 2: Memoization

```cpp
class Solution {
public:
    int climbStairs(int n, unordered_map<int, int>& memo) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (memo.find(n) == memo.end()) {
            memo[n] = climbStairs(n-1, memo) + climbStairs(n-2, memo);
        }
        return memo[n];
    }

    int climbStairs(int n) {
        unordered_map<int, int> memo;
        return climbStairs(n, memo);
    }
};
```

```java
class Solution {
    public int climbStairs(int n) {
        Map<Integer, Integer> memo = new HashMap<>();
        return climbStairs(n, memo);
    }
    
    private int climbStairs(int n, Map<Integer, Integer> memo) {
        if (n == 0 || n == 1) {
            return 1;
        }
        if (!memo.containsKey(n)) {
            memo.put(n, climbStairs(n-1, memo) + climbStairs(n-2, memo));
        }
        return memo.get(n);
    }
}
```

- Time Complexity: \( O(n) \) (Linear).
- Space Complexity: \( O(n) \) (Dictionary storage).

---

### Approach 3: Tabulation

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};
```

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }

        int[] dp = new int[n+1];
        dp[0] = dp[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
}
```

- Time Complexity: \( O(n) \) (Linear).
- Space Complexity: \( O(n) \) (Array storage).

---

### Approach 4: Space Optimization

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
};
```

```java
class Solution {
    public int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }
}
```

- Time Complexity: \( O(n) \) (Linear).
- Space Complexity: \( O(1) \) (Only two variables).
