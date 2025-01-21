# Geek’s Training

## Table of Contents

- [Geek’s Training](#geeks-training)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
      - [Recursive Relation](#recursive-relation)
    - [Memoization Solution](#memoization-solution)
    - [Tabulation Solution](#tabulation-solution)
    - [Space-Optimized Tabulation](#space-optimized-tabulation)
  - [C++ Codes](#c-codes)
    - [Tabulation Function](#tabulation-function)
    - [Space-Optimized Tabulation Function](#space-optimized-tabulation-function)
  - [Complexity Analysis](#complexity-analysis)
    - [Recursive Solution Complexity](#recursive-solution-complexity)
    - [Memoization Solution Complexity](#memoization-solution-complexity)
    - [Tabulation solution](#tabulation-solution-1)
    - [Space-Optimized Tabulation Solution](#space-optimized-tabulation-solution)

---

## Introduction

Geek is attending a training program where he can perform any of the following activities each day:

- **Running**
- **Fighting Practice**
- **Learning New Skills**

Each activity provides a certain number of merit points. However, Geek cannot perform the same activity on two consecutive days. The goal is to maximize the total merit points Geek can earn over all the training days.

---

## Problem Description

You are given a 2D array `arr[][]`, where:

- `arr[i][0]` represents the merit points for **Running** on the `i-th` day.
- `arr[i][1]` represents the merit points for **Fighting Practice** on the `i-th` day.
- `arr[i][2]` represents the merit points for **Learning New Skills** on the `i-th` day.

Your task is to determine the maximum total merit points Geek can achieve, adhering to the rule of not performing the same activity on consecutive days.

---

## Examples

### Example 1

**Input:**

```bash
arr = [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
```

**Output:**

```bash
11
```

**Explanation:**

- Day 1: Geek learns new skills (5 points).
- Day 2: Geek runs (3 points).
- Day 3: Geek fights (3 points).
- Total merit points = `5 + 3 + 3 = 11`.

---

### Example 2

**Input:**

```bash
arr = [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
```

**Output:**

```bash
6
```

**Explanation:**

- Geek can perform any activity each day while adhering to the constraints, maximizing total merit points to `6`.

---

### Example 3

**Input:**

```bash
arr = [[4, 2, 6]]
```

**Output:**

```bash
6
```

**Explanation:**

- Day 1: Geek learns new skills (6 points).
- Total merit points = `6`.

---

## Constraints

- `1 ≤ arr.size ≤ 10^5`
- `1 ≤ arr[i][j] ≤ 100`
- Time limit: `1 sec`

---

## Approach

### Recursive Solution

The recursive approach involves calculating the maximum merit points for each day by trying all three activities while ensuring that no two consecutive days have the same activity.

#### Recursive Relation

Let `f(day, last)` represent the maximum merit points Geek can earn from day `0` to `day` if the last activity performed was `last`.

- If `last = 3` (no restriction on activity), consider all three activities.
- Otherwise, calculate the maximum merit points for activities other than `last`.

Base Case:

- If `day == 0`, return the maximum merit points for all activities except `last`.

---

### Memoization Solution

The recursive solution can be optimized using **memoization** to store intermediate results, avoiding redundant calculations.

**Steps:**

1. Use a 2D `dp` array where `dp[day][last]` stores the maximum merit points up to `day` if `last` was the last performed activity.
2. On each recursive call, check if the value is already computed in `dp`. If yes, return it.

---

### Tabulation Solution

Using a bottom-up approach:

1. Create a `dp` table where `dp[i][j]` represents the maximum points earned up to day `i` if activity `j` is performed on day `i`.
2. Initialize `dp[0][j]` with the values of the first day.
3. For each subsequent day, calculate the maximum merit points for each activity based on the points from the previous day, excluding the same activity.

---

### Space-Optimized Tabulation

To further optimize the tabulation approach, reduce the space complexity by using only a single array to store results for the previous day. This eliminates the need for the entire `dp` table.

**Steps:**

1. Use a `dp` array of size `4` to store results for the previous day.
2. For each day, compute the results for the current day using a temporary array, and update `dp` accordingly.

---

## C++ Codes

### Tabulation Function

```cpp
int tabulation(vector<vector<int>> &points) {
    int n = points.size();
    vector<vector<int>> dp(n, vector<int>(4, 0));

    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    dp[day][last] = max(dp[day][last], points[day][task] + dp[day - 1][task]);
                }
            }
        }
    }
    return dp[n - 1][3];
}
```

---

### Space-Optimized Tabulation Function

```cpp
int tabulation_spaceOptimized(vector<vector<int>> &points) {
    int n = points.size();
    vector<int> dp(4, 0);

    dp[0] = max(points[0][1], points[0][2]);
    dp[1] = max(points[0][0], points[0][2]);
    dp[2] = max(points[0][0], points[0][1]);
    dp[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; day++) {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++) {
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    temp[last] = max(temp[last], points[day][task] + dp[task]);
                }
            }
        }
        dp = temp;
    }
    return dp[3];
}
```

---

## Complexity Analysis

### Recursive Solution Complexity

- **Time Complexity:** \(O(3^n)\), due to exponential branching.
- **Space Complexity:** \(O(n)\), for the recursion stack.

### Memoization Solution Complexity

- **Time Complexity:** \(O(n \times 4)\), where \(n\) is the number of days and \(4\) is the number of possible `last` states.
- **Space Complexity:** \(O(n \times 4)\) for the `dp` table.
- **Auxiliary Space:** \(O(n \times 4)\) for the `dp` table.
- **Additional Space:** \(O(n \times 4)\) for the `dp` table.
- **Total Space:** \(O(n \times 4)\) for the `dp` table.
  
### Tabulation solution

- **Time Complexity:** \(O(n \times 4 \times 3)\), as we iterate over `n` days, `4` taskLast states, and `3` tasks.
- **Space Complexity:** \(O(n \times 4)\) for the `dp` table.

### Space-Optimized Tabulation Solution

- **Time Complexity:** \(O(n \times 4 \times 3)\), as we iterate over `n` days, `4` taskLast states, and `3` tasks.
- **Space Complexity:** \(O(4)\) for the `dp` array.
  
---
