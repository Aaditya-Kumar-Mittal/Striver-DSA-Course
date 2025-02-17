# Cost to Cut a Chocolate

## Table of Contents

- [Cost to Cut a Chocolate](#cost-to-cut-a-chocolate)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Solution](#recursive-solution)
    - [Memoization](#memoization)
    - [Tabulation](#tabulation)
    - [Final Function](#final-function)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)

## Introduction

The problem requires us to determine the minimum cost to cut a chocolate of length `N` into smaller segments. Given an array of possible cut positions, we need to decide the optimal order of cuts to minimize the total cost, where the cost of each cut is the length of the segment being cut.

## Problem Description

We are given a chocolate of length `N`, labeled from `0` to `N`. Additionally, we have an array `CUTS` of size `C`, which specifies the positions where cuts can be made. The cost of a cut is the length of the chocolate piece that is being cut. The goal is to determine the minimum total cost to completely cut the chocolate at all specified positions.

### Examples

#### Example 1

**Input:**

```bash
N = 4
CUTS = [1, 3]
```

**Output:**

```bash
7
```

**Explanation:**

- Cut at `1` first (cost = `4`), resulting in two parts `[0,1]` and `[1,4]`.
- Cut at `3` (cost = `3`), resulting in final pieces `[0,1]`, `[1,3]`, and `[3,4]`.
- Total cost = `4 + 3 = 7`.

#### Example 2

**Input:**

```bash
N = 5
CUTS = [1, 3, 4]
```

**Output:**

```bash
10
```

**Explanation:**
The minimum cost is achieved with the cut order `[3,1,4]`, leading to a total cost of `10`.

### Constraints

- `1 <= T <= 10` (number of test cases)
- `2 <= N <= 10^5`
- `1 <= C <= 10^3`
- `1 <= CUTS[i] <= N - 1`
- All elements in `CUTS` are distinct.

## Approach

This problem follows a **Dynamic Programming (DP)** approach:

1. **Recursive Approach**: Try every possible cut recursively and compute the minimum cost.
2. **Memoization**: Store results in a DP table to avoid redundant calculations.
3. **Tabulation**: Use a bottom-up approach to fill the DP table efficiently.

## Detailed Explanation of Code

### Recursive Solution

The recursive function considers each cut position and recursively solves for left and right subproblems.

```cpp
int recursive_solution(int index, int jindex, vector<int> &cuts) {
    if (index > jindex) return 0;
    int mini = INT_MAX;
    for (int i = index; i <= jindex; i++) {
        int cost = (cuts[jindex + 1] - cuts[index - 1]) +
                   recursive_solution(index, i - 1, cuts) +
                   recursive_solution(i + 1, jindex, cuts);
        mini = min(mini, cost);
    }
    return mini;
}
```

- Tries every possible cut recursively.
- Computes the cost and finds the minimum possible cost.
- Exponential time complexity makes it inefficient for large `N`.

### Memoization

We use a `dp` table to store results of subproblems and avoid recomputation.

```cpp
int memoization(int index, int jindex, vector<int> &cuts, vector<vector<int>> &dp) {
    if (index > jindex) return 0;
    if (dp[index][jindex] != -1) return dp[index][jindex];
    int mini = INT_MAX;
    for (int i = index; i <= jindex; i++) {
        int cost = (cuts[jindex+1] - cuts[index-1]) +
                   memoization(index, i-1, cuts, dp) +
                   memoization(i+1, jindex, cuts, dp);
        mini = min(mini, cost);
    }
    return dp[index][jindex] = mini;
}
```

- Uses a `dp` table for storing previously computed values.
- Improves efficiency compared to plain recursion.
- Still has a high time complexity for large `N`.

### Tabulation

The most optimal approach using **bottom-up DP**.

```cpp
int tabulation(int c, vector<int> &cuts) {
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    for (int index = c; index >= 1; index--) {
        for (int jindex = 1; jindex <= c; jindex++) {
            if (index > jindex) continue;
            int mini = INT_MAX;
            for (int i = index; i <= jindex; i++) {
                int cost = (cuts[jindex+1] - cuts[index-1]) +
                           dp[index][i-1] + dp[i+1][jindex];
                mini = min(mini, cost);
            }
            dp[index][jindex] = mini;
        }
    }
    return dp[1][c];
}
```

- Uses **iterative** DP table filling.
- Runs in **O(C^2)** time, making it efficient for large values of `C`.

### Final Function

```cpp
int cost(int n, int c, vector<int> &cuts){
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    return tabulation(c, cuts);
}
```

- Prepares the `cuts` array by adding `0` and `N`.
- Uses **tabulation** for best performance.

## Complexity Analysis

| Approach    | Time Complexity | Space Complexity |
| ----------- | --------------- | ---------------- |
| Recursive   | O(2^C)          | O(C)             |
| Memoization | O(C^2)          | O(C^2)           |
| Tabulation  | O(C^2)          | O(C^2)           |

## How to Run the Code

1. Compile the C++ code using `g++`:

   ```sh
   g++ cost_to_cut_chocolate.cpp -o cost
   ```

2. Run the executable:

   ```sh
   ./cost
   ```

3. Provide input values as specified in the problem statement.

This implementation ensures efficient computation of the minimum cost to cut the chocolate while adhering to given constraints.
