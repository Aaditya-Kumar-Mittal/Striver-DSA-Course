# Chocolate Pickup

<!--  markdownlint-disable MD052 -->

## Table of Contents

- [Chocolate Pickup](#chocolate-pickup)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
      - [Base Cases](#base-cases)
    - [Memoization Solution](#memoization-solution)
    - [Tabulation Solution](#tabulation-solution)
    - [Space-Optimized Tabulation Solution](#space-optimized-tabulation-solution)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Key Notes](#key-notes)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solution](#other-solution)
  - [My Submission](#my-submission)

---

## Introduction

Ninja has a grid containing chocolates. He wants to collect as many chocolates as possible with the help of his two friends, Alice and Bob. The task is to find the maximum number of chocolates that can be collected by Alice and Bob following specific movement rules.

---

## Problem Description

Given a grid `GRID` of size `R x C`, Alice starts at the top-left corner `(0, 0)` and Bob starts at the top-right corner `(0, C-1)`. Both can move to cells in the next row: straight down, diagonally left, or diagonally right. If both end up in the same cell, they pick chocolates together, but only one of them collects the chocolates. The goal is to maximize the total number of chocolates collected.

---

## Examples

### Example 1

**Input**:

```plaintext
R = 3, C = 4
GRID = [
    [2, 3, 1, 2],
    [3, 4, 2, 2],
    [5, 6, 3, 5]
]
```

**Output**:

```plaintext
21
```

**Explanation**:

- Alice's path: `(0, 0) -> (1, 1) -> (2, 1)` (Chocolates: `2 + 4 + 6 = 12`)
- Bob's path: `(0, 3) -> (1, 3) -> (2, 3)` (Chocolates: `2 + 2 + 5 = 9`)
- Total: `12 + 9 = 21`.

### Example 2

**Input**:

```plaintext
R = 2, C = 2
GRID = [
    [1, 1],
    [1, 2]
]
```

**Output**:

```plaintext
5
```

**Explanation**:

- Alice's path: `(0, 0) -> (1, 0)` (Chocolates: `1 + 1 = 2`)
- Bob's path: `(0, 1) -> (1, 1)` (Chocolates: `1 + 2 = 3`)
- Total: `2 + 3 = 5`.

---

## Constraints

- \( 1 \leq T \leq 10 \)
- \( 2 \leq R, C \leq 50 \)
- \( 0 \leq GRID[i][j] \leq 10^2 \)
- Time Limit: 1 second

---

## Approach

### Recursive Solution

We compute the maximum chocolates collected by Alice and Bob for all valid movements.

#### Base Cases

1. If Alice or Bob moves out of bounds, return \(-\infty\).
2. If they reach the last row, return the chocolates in their respective cells.

### Memoization Solution

We store the results of states \( dp[i][j1][j2] \), where:

- \( i \) is the row,
- \( j1 \) is Alice's column,
- \( j2 \) is Bob's column.

### Tabulation Solution

We build the solution iteratively using a 3D DP table starting from the last row to the first.

### Space-Optimized Tabulation Solution

We use only two 2D tables (current row and next row) to reduce space complexity.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int recursive_solution(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid) {
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    if (i == n - 1) return (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

    int maxChoco = -1e8;
    for (int d1 = -1; d1 <= 1; d1++) {
        for (int d2 = -1; d2 <= 1; d2++) {
            int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
            value += recursive_solution(i + 1, j1 + d1, j2 + d2, n, m, grid);
            maxChoco = max(maxChoco, value);
        }
    }
    return maxChoco;
}

int tabulation_solution(int r, int c, vector<vector<int>> &grid) {
    vector<vector<int>> dp(c, vector<int>(c, 0)), prev(c, vector<int>(c, 0));

    for (int j1 = 0; j1 < c; j1++) {
        for (int j2 = 0; j2 < c; j2++) {
            prev[j1][j2] = (j1 == j2) ? grid[r - 1][j1] : grid[r - 1][j1] + grid[r - 1][j2];
        }
    }

    for (int i = r - 2; i >= 0; i--) {
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                int maxChoco = -1e8;
                for (int d1 = -1; d1 <= 1; d1++) {
                    for (int d2 = -1; d2 <= 1; d2++) {
                        int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                        if (j1 + d1 >= 0 && j1 + d1 < c && j2 + d2 >= 0 && j2 + d2 < c) {
                            value += prev[j1 + d1][j2 + d2];
                        }
                        maxChoco = max(maxChoco, value);
                    }
                }
                dp[j1][j2] = maxChoco;
            }
        }
        prev = dp;
    }
    return prev[0][c - 1];
}

int main() {
    vector<vector<int>> grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    int r = grid.size(), c = grid[0].size();
    cout << "Maximum Chocolates: " << tabulation_solution(r, c, grid) << endl;
    return 0;
}
```

### Java Implementation

```java
import java.util.Arrays;

public class ChocolatePickup {
    public static int maximumChocolates(int r, int c, int[][] grid) {
        int[][] prev = new int[c][c];
        for (int j1 = 0; j1 < c; j1++) {
            for (int j2 = 0; j2 < c; j2++) {
                prev[j1][j2] = (j1 == j2) ? grid[r - 1][j1] : grid[r - 1][j1] + grid[r - 1][j2];
            }
        }

        for (int i = r - 2; i >= 0; i--) {
            int[][] curr = new int[c][c];
            for (int j1 = 0; j1 < c; j1++) {
                for (int j2 = 0; j2 < c; j2++) {
                    int maxChoco = Integer.MIN_VALUE;
                    for (int d1 = -1; d1 <= 1; d1++) {
                        for (int d2 = -1; d2 <= 1; d2++) {
                            int value = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                            if (j1 + d1 >= 0 && j1 + d1 < c && j2 + d2 >= 0 && j2 + d2 < c) {
                                value += prev[j1 + d1][j2 + d2];
                            }
                            maxChoco = Math.max(maxChoco, value);
                        }
                    }
                    curr[j1][j2] = maxChoco;
                }
            }
            prev = curr;
        }
        return prev[0][c - 1];
    }

    public static void main(String[] args) {
        int[][] grid = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
        int r = grid.length, c = grid[0].length;
        System.out.println("Maximum Chocolates: " + maximumChocolates(r, c

, grid));
    }
}
```

---

## Complexity Analysis

**Recursive Solution**:

- **Time Complexity**: \(O(3^{2C} \times R)\)
- **Space Complexity**: \(O(R)\) (stack space).

**Memoization**:

- **Time Complexity**: \(O(R \times C \times C \times 9)\)
- **Space Complexity**: \(O(R \times C \times C)\).

**Tabulation**:

- **Time Complexity**: \(O(R \times C \times C \times 9)\)
- **Space Complexity**: \(O(R \times C \times C)\).

**Space-Optimized Tabulation**:

- **Time Complexity**: \(O(R \times C \times C \times 9)\)
- **Space Complexity**: \(O(C \times C)\).

| **Approach**                   | **Time Complexity**                 | **Space Complexity**       | **Explanation**                                                                                                                                                                                                                                               |
| ------------------------------ | ----------------------------------- | -------------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **Recursive Solution**         | \(O(3^{2C} \times R)\)              | \(O(R)\)                   | The recursion explores all possible combinations of movements for Alice and Bob at each row. There are 3 movements for each, leading to \(3 \times 3 = 9\) combinations. Over \(R\) rows, this grows exponentially. The stack depth is proportional to \(R\). |
| **Memoization**                | \(O(R \times C \times C \times 9)\) | \(O(R \times C \times C)\) | By caching intermediate results using a 3D DP table \(dp[i][j1][j2]\), redundant calculations are avoided. Time complexity accounts for \(R\) rows, \(C \times C\) states, and 9 combinations of movements. Space is used for the 3D DP table.                |
| **Tabulation**                 | \(O(R \times C \times C \times 9)\) | \(O(R \times C \times C)\) | Similar to memoization, but the 3D DP table is filled iteratively instead of recursively. It eliminates stack space but requires a full table in memory, with \(R \times C \times C\) cells.                                                                  |
| **Space-Optimized Tabulation** | \(O(R \times C \times C \times 9)\) | \(O(C \times C)\)          | Instead of maintaining a 3D DP table for all rows, only the current row and the previous row are stored, reducing space usage to \(C \times C\). The time complexity remains the same.                                                                        |

---

### Key Notes

1. **Recursive Solution**: Simple to implement but impractical for large \(R\) and \(C\) due to exponential time growth.
2. **Memoization**: Significantly reduces redundant calculations but has high space requirements.
3. **Tabulation**: Iterative approach avoids recursion, making it less prone to stack overflow issues.
4. **Space-Optimized Tabulation**: Best approach for large grids, as it minimizes memory usage while maintaining the same time efficiency.

---

## How to Run the Code

### For C++

1. Save the code in a file named `ChocolatePickup.cpp`.
2. Compile using `g++ -o ChocolatePickup ChocolatePickup.cpp`.
3. Run the executable with `./ChocolatePickup`.

### For Java

1. Save the code in a file named `ChocolatePickup.java`.
2. Compile using `javac ChocolatePickup.java`.
3. Run the program with `java ChocolatePickup`.

---

## Other Solution

### My Submission

```cpp
#include <bits/stdc++.h>

using namespace std;

// Recusive Solution
// Recursive Solution
int recursive_solution(int i, int j1, int j2, int n, int m,
                       vector<vector<int>> &a) {
  // Boundary Case
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e8;

  // Destination Base Case
  if (i == n - 1) {
    // If both reach the same column
    if (j1 == j2)
      return a[i][j1];
    else
      return a[i][j1] + a[i][j2];
  }

  int maxChoco = -1e8;

  for (int d1 = -1; d1 <= 1; d1++) {
    for (int d2 = -1; d2 <= 1; d2++) {
      int value;
      if (j1 == j2) {
        value = a[i][j1] + recursive_solution(i + 1, j1 + d1, j2 + d2, n, m, a);
      } else {
        value = a[i][j1] + a[i][j2] +
                recursive_solution(i + 1, j1 + d1, j2 + d2, n, m, a);
      }
      maxChoco = max(maxChoco, value);
    }
  }

  return maxChoco;
}

// Recursive Memoization
int recursive_memoizaton(int i, int j1, int j2, int n, int m,
                         vector<vector<int>> &a,
                         vector<vector<vector<int>>> &dp) {
  // Boundary Case
  if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
    return -1e8;

  // Destination Base Case
  if (i == n - 1) {
    // If both reach the same column
    if (j1 == j2)
      return a[i][j1];
    else
      return a[i][j1] + a[i][j2];
  }

  if (dp[i][j1][j2] != -1)
    return dp[i][j1][j2];

  int maxChoco = -1e8;

  for (int d1 = -1; d1 <= 1; d1++) {
    for (int d2 = -1; d2 <= 1; d2++) {
      int value;
      if (j1 == j2) {
        value = a[i][j1] +
                recursive_memoizaton(i + 1, j1 + d1, j2 + d2, n, m, a, dp);
      } else {
        value = a[i][j1] + a[i][j2] +
                recursive_memoizaton(i + 1, j1 + d1, j2 + d2, n, m, a, dp);
      }
      maxChoco = max(maxChoco, value);
    }
  }

  return dp[i][j1][j2] = maxChoco;
}

// Tabulation Solution
int tabulation_solution(int r, int c, vector<vector<int>> &a) {
  // Create a 3D DP table
  vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));

  // Base case: Fill the last row
  for (int j1 = 0; j1 < c; j1++) {
    for (int j2 = 0; j2 < c; j2++) {
      if (j1 == j2) {
        dp[r - 1][j1][j2] = a[r - 1][j1];
      } else {
        dp[r - 1][j1][j2] = a[r - 1][j1] + a[r - 1][j2];
      }
    }
  }

  // Fill the DP table for remaining rows (from bottom to top)
  for (int i = r - 2; i >= 0; i--) { // Start from second last row
    for (int j1 = 0; j1 < c; j1++) {
      for (int j2 = 0; j2 < c; j2++) {

        int maxChoco = -1e8; // Initialize maximum chocolates for this state

        for (int d1 = -1; d1 <= 1; d1++) {   // Movements for robot 1
          for (int d2 = -1; d2 <= 1; d2++) { // Movements for robot 2
            int value = 0;

            if (j1 == j2) {
              value = a[i][j1]; // Both robots are at the same cell
            } else {
              value = a[i][j1] + a[i][j2]; // Different cells
            }

            if (j1 + d1 >= 0 && j1 + d1 < c && j2 + d2 >= 0 && j2 + d2 < c) {
              value += dp[i + 1][j1 + d1][j2 + d2]; // Valid moves
            } else {
              value += -1e8; // Invalid moves
            }

            maxChoco = max(maxChoco, value);
          }
        }

        dp[i][j1][j2] = maxChoco; // Update DP table for current state
      }
    }
  }

  // Final answer: Maximum chocolates starting from (0, 0) to (c-1, c-1)
  return dp[0][0][c - 1];
}

// Tabulation Solution Space Optimized
int tabulation_solution_optimized(int r, int c, vector<vector<int>> &a) {
  // Create a 2D DP table
  vector<vector<int>> dp(c, vector<int>(c, -1));

  // Base case: Fill the last row
  for (int j1 = 0; j1 < c; j1++) {
    for (int j2 = 0; j2 < c; j2++) {
      if (j1 == j2) {
        dp[j1][j2] = a[r - 1][j1];
      } else {
        dp[j1][j2] = a[r - 1][j1] + a[r - 1][j2];
      }
    }
  }

  // Fill the DP table for remaining rows (from bottom to top)
  for (int i = r - 2; i >= 0; i--) { // Start from second last row
    vector<vector<int>> temp(c, vector<int>(c, 0));
    for (int j1 = 0; j1 < c; j1++) {
      for (int j2 = 0; j2 < c; j2++) {

        int maxChoco = -1e8; // Initialize maximum chocolates for this state

        for (int d1 = -1; d1 <= 1; d1++) {   // Movements for robot 1
          for (int d2 = -1; d2 <= 1; d2++) { // Movements for robot 2
            int value = 0;

            if (j1 == j2) {
              value = a[i][j1]; // Both robots are at the same cell
            } else {
              value = a[i][j1] + a[i][j2]; // Different cells
            }

            if (j1 + d1 >= 0 && j1 + d1 < c && j2 + d2 >= 0 && j2 + d2 < c) {
              value += dp[j1 + d1][j2 + d2]; // Valid moves
            } else {
              value += -1e8; // Invalid moves
            }

            maxChoco = max(maxChoco, value);
          }
        }

        temp[j1][j2] = maxChoco; // Update DP table for current state
      }
    }
    dp = temp;
  }

  // Final answer: Maximum chocolates starting from (0, 0) to (c-1, c-1)
  return dp[0][c - 1];
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
  // Call the recursive solution
  // return recursive_solution(0, 0, c - 1, r, c, grid);

  // DP Memoization
  // vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c,
  // -1))); return recursive_memoizaton(0, 0, c - 1, r, c, grid, dp);

  // return tabulation_solution(r, c, grid);
  return tabulation_solution_optimized(r, c, grid);
}
```
