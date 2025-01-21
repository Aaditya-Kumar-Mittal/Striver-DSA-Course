# Ninja’s Training

## Table of Contents

- [Ninja’s Training](#ninjas-training)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
      - [Recursive Relation](#recursive-relation)
    - [Memoization Solution](#memoization-solution)
    - [Tabulation Solution](#tabulation-solution)
  - [C++ Codes](#c-codes)
    - [Recursive Function](#recursive-function)
    - [Recursive Function with Memoization](#recursive-function-with-memoization)
    - [Tabulation Function](#tabulation-function)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Code Explanation](#code-explanation)

---

## Introduction

Ninja is planning a training schedule for `N` days. Each day, Ninja can perform one of three activities: **Running**, **Fighting Practice**, or **Learning New Moves**. Each activity yields a certain number of merit points. However, Ninja cannot perform the same activity on two consecutive days. The goal is to determine the maximum merit points Ninja can earn over the training period.

---

## Problem Description

You are given a 2D array `POINTS` of size `N x 3`, where:

- `POINTS[i][0]` represents the merit points earned for **Running** on day `i`.
- `POINTS[i][1]` represents the merit points earned for **Fighting Practice** on day `i`.
- `POINTS[i][2]` represents the merit points earned for **Learning New Moves** on day `i`.

Your task is to calculate the maximum number of merit points that Ninja can earn over `N` days while following the restriction of not repeating the same activity on two consecutive days.

---

## Examples

### Example 1

**Input:**  

```bash

2
3
1 2 5
3 1 1
3 3 3
3
10 40 70
20 50 80
30 60 90

```

**Output:**  

```bash

11
210

```

**Explanation:**  

- **First Test Case:**
  - On Day 1, Ninja learns new moves (5 points).  
  - On Day 2, Ninja does running (3 points).  
  - On Day 3, Ninja does fighting (3 points).  
  Total = `5 + 3 + 3 = 11`.

- **Second Test Case:**
  - On Day 1, Ninja learns new moves (70 points).  
  - On Day 2, Ninja does fighting (50 points).  
  - On Day 3, Ninja learns new moves again (90 points).  
  Total = `70 + 50 + 90 = 210`.

### Example 2

**Input:**  

```bash

2
3
18 11 19
4 13 7
1 8 13
3
2 10 50
1 5 100
11 10 5

```

**Output:**  

```bash

45
110

```

**Explanation:**  

- **First Test Case:** Total = `19 + 13 + 13 = 45`.  
- **Second Test Case:** Total = `50 + 5 + 55 = 110`.

---

## Constraints

- `1 <= T <= 10`
- `1 <= N <= 100,000`
- `1 <= values of POINTS arrays <= 100`
- Time limit: `1 sec`

---

## Approach

### Recursive Solution

A simple recursive solution involves calculating the maximum merit points for each day by trying all three activities while ensuring no two consecutive days have the same activity.

#### Recursive Relation

Let `f(day, taskLast)` represent the maximum merit points Ninja can earn from day `0` to `day` if the last task performed was `taskLast`.  

- If `taskLast = 3` (no restrictions), consider all three tasks.
- Otherwise, calculate the maximum merit points for tasks that are not equal to `taskLast`.

Base Case:  

- If `day == 0`, return the maximum merit points for all tasks except `taskLast`.

### Memoization Solution

The recursive solution can be optimized using **memoization** to store intermediate results, avoiding redundant calculations.

**Steps:**

1. Use a 2D `dp` array where `dp[day][taskLast]` stores the maximum merit points up to `day` if `taskLast` was the last performed task.
2. On each recursive call, check if the value is already computed in `dp`. If yes, return it.

### Tabulation Solution

Using a bottom-up approach:

1. Create a `dp` table where `dp[i][j]` represents the maximum points earned up to day `i` if activity `j` is performed on day `i`.
2. Initialize `dp[0][j]` with the values of the first day.
3. For each subsequent day, calculate the maximum merit points for each activity based on the points from the previous day, excluding the same activity.

---

## C++ Codes

```cpp
#include <bits/stdc++.h>
using namespace std;

// Recursive function with memoization
int recursive_memoization(int day, int taskLast, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (dp[day][taskLast] != -1) // Return cached result if available
        return dp[day][taskLast];
    
    // Base Case
    if (day == 0) {
        int maxPoint = INT_MIN;
        for (int i = 0; i < 3; i++) { // Iterate over all 3 tasks
            if (i != taskLast) {
                maxPoint = max(maxPoint, points[0][i]);
            }
        }
        return dp[day][taskLast] = maxPoint;
    }

    int maxPoint = INT_MIN;

    // Try all tasks except the one performed on the previous day
    for (int i = 0; i < 3; i++) {
        if (i != taskLast) {
            int merits = points[day][i] + recursive_memoization(day - 1, i, points, dp);
            maxPoint = max(maxPoint, merits);
        }
    }

    return dp[day][taskLast] = maxPoint; // Store result in dp array
}

// Main function to calculate the maximum points for ninja training
int ninjaTraining(int n, vector<vector<int>> &points) {
    // Memoization table with -1 indicating uncomputed states
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return recursive_memoization(n - 1, 3, points, dp); // taskLast = 3 (no task restricted initially)
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> points(N, vector<int>(3));
        for (int i = 0; i < N; i++) {
            cin >> points[i][0] >> points[i][1] >> points[i][2];
        }
        cout << ninjaTraining(N, points) << endl;
    }
    return 0;
}
```

---

### Recursive Function

```cpp
int recursive(int day, int taskLast, vector<vector<int>> &points) {
    if (day == 0) {
        int maxPoint = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (i != taskLast) {
                maxPoint = max(maxPoint, points[0][i]);
            }
        }
        return maxPoint;
    }

    int maxPoint = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != taskLast) {
            int merits = points[day][i] + recursive(day - 1, i, points);
            maxPoint = max(maxPoint, merits);
        }
    }
    return maxPoint;
}
```

---

### Recursive Function with Memoization

```cpp
int recursive_memoization(int day, int taskLast, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if (dp[day][taskLast] != -1) {
        return dp[day][taskLast];
    }

    if (day == 0) {
        int maxPoint = INT_MIN;
        for (int i = 0; i < 3; i++) {
            if (i != taskLast) {
                maxPoint = max(maxPoint, points[0][i]);
            }
        }
        return dp[day][taskLast] = maxPoint;
    }

    int maxPoint = INT_MIN;
    for (int i = 0; i < 3; i++) {
        if (i != taskLast) {
            int merits = points[day][i] + recursive_memoization(day - 1, i, points, dp);
            maxPoint = max(maxPoint, merits);
        }
    }
    return dp[day][taskLast] = maxPoint;
}
```

**Key Improvements:**

- Stores results in `dp[day][taskLast]` to prevent redundant computations.

---

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

**Key Features:**

- Iteratively fills the `dp` table using the previous day's results.
- Ensures constraints by skipping the task equal to `last`.

---

## Complexity Analysis

- **Recursive Approach:**
  - **Time Complexity:** \(O(3^n)\) due to exponential branching.
  - **Space Complexity:** \(O(n)\) for the recursion stack.

- **Memoization Approach:**
  - **Time Complexity:** \(O(n \times 4)\), where \(n\) is the number of days and 4 is the number of possible `taskLast`.
  - **Space Complexity:** \(O(n \times 4)\) for the `dp` table and recursion stack.

- **Tabulation Approach:**
  - **Time Complexity:** \(O(n \times 4 \times 3)\), as we iterate over `n` days, `4` taskLast states, and `3` tasks.
  - **Space Complexity:** \(O(n \times 4)\) for the `dp` table.

---

## How to Run the Code

1. Compile the code using a C++ compiler, e.g., `g++ solution.cpp -o solution`.
2. Run the program: `./solution`.
3. Input the number of test cases `T` followed by `N` and the `POINTS` array for each test case.
4. View the output, which is the maximum merit points for each test case.

## Code Explanation

This function computes the maximum points recursively:

- **Base Case:** For day 0, return the maximum points for tasks not equal to `taskLast`.
- **Recursive Case:** For each task, compute the points and make a recursive call for previous days.

---
