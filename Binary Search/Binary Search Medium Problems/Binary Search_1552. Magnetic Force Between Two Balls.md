# Magnetic Force Between Two Balls

## Table of Contents

- [Magnetic Force Between Two Balls](#magnetic-force-between-two-balls)
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
    - [For C++](#for-c)

---

## Introduction

In this problem, we are asked to distribute **m balls** into **n baskets** positioned at different locations to maximize the minimum magnetic force between any two balls.  
The magnetic force between two balls is defined as the absolute difference between their positions.  
We aim to **maximize** the **minimum** force among all ball pairs.

---

## Problem Description

Given:

- An array `position` where `position[i]` is the location of the i-th basket.
- An integer `m` representing the number of balls to be placed.

Return the maximum possible minimum magnetic force achievable.

### Examples

#### Example 1

**Input:**

```plaintext
position = [1,2,3,4,7]
m = 3
```

**Output:**

```plaintext
3
```

**Explanation:**  
Place the balls at positions 1, 4, and 7.  
The pairwise distances will be [3, 3, 6], and the minimum is 3.

#### Example 2

**Input:**

```plaintext
position = [5,4,3,2,1,1000000000]
m = 2
```

**Output:**

```plaintext
999999999
```

**Explanation:**  
Place balls at positions 1 and 1000000000.  
The magnetic force between them is 999999999.

---

### Constraints

- `n == position.length`
- `2 <= n <= 10^5`
- `1 <= position[i] <= 10^9`
- All positions are **distinct**.
- `2 <= m <= position.length`

---

## Approach

The key idea is **Binary Search on Answer**:

- Sort the basket positions.
- Apply binary search on the possible minimum distances:
  - **Low** = 1 (smallest minimum distance).
  - **High** = max(position) - min(position) (largest minimum distance possible).
- For a guessed minimum distance `mid`, use a greedy approach to check if placing `m` balls is possible:
  - Place the first ball at the first basket.
  - For every subsequent basket, if the distance from the last placed ball is at least `mid`, place a ball there.
- If we can place all `m` balls, try to maximize the distance.
- Otherwise, decrease the distance.

This strategy ensures finding the largest minimum distance efficiently.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Check if it's possible to place 'k' balls with at least 'distance' separation
    bool checkValidDistance(vector<int>& stalls, int n, int distance, int k) {
        int countCows = 1;  // First ball is placed at stalls[0]
        int lastCowAt = stalls[0];

        for (int stall = 1; stall < stalls.size(); stall++) {
            if (stalls[stall] - lastCowAt >= distance) {
                countCows++;
                lastCowAt = stalls[stall];
            }
            if (countCows >= k)
                return true; // Successfully placed all balls
        }

        return false; // Not enough balls placed
    }

    // Binary search to maximize the minimum distance
    int aggressiveCows(vector<int>& stalls, int k) {
        sort(stalls.begin(), stalls.end()); // Sort basket positions
        int n = stalls.size();
        int low = 1, high = stalls[n - 1] - stalls[0];
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkValidDistance(stalls, n, mid, k)) {
                ans = mid;        // Valid, try for bigger distance
                low = mid + 1;
            } else {
                high = mid - 1;   // Not valid, reduce distance
            }
        }

        return ans;
    }

    int maxDistance(vector<int>& position, int m) {
        return aggressiveCows(position, m);
    }
};
```

```cpp
class Solution {
public:
    // Check if we can place 'm' balls at 'position'
    // with each ball having at least 'x' gap.
    bool canPlaceBalls(int x, vector<int> &position, int m) {
        // Place the first ball at the first position.
        int prevBallPos = position[0];
        int ballsPlaced = 1;

        // Iterate on each 'position' and place a ball there if we can place it.
        for (int i = 1; i < position.size() && ballsPlaced < m; ++i) {
            int currPos = position[i];
            // Check if we can place the ball at the current position.
            if (currPos - prevBallPos >= x) {
                ballsPlaced += 1;
                prevBallPos = currPos;
            }
        }
        // If all 'm' balls are placed, return 'true'.
        return ballsPlaced == m;
    }

    int maxDistance(vector<int> &position, int m) {
        int answer = 0;
        int n = position.size();
        sort(position.begin(), position.end());

        // Initial search space.
        int low = 1;
        int high = ceil(position[n - 1] / (m - 1.0));
        while (low <= high) {
            int mid = low + (high - low) / 2;
            // If we can place all balls having a gap at least 'mid',
            if (canPlaceBalls(mid, position, m)) {
                // then 'mid' can be our answer,
                answer = mid;
                // and discard the left half search space.
                low = mid + 1;
            } else {
                // Discard the right half search space.
                high = mid - 1;
            }
        }
        return answer;
    }
};
```

---

## Complexity Analysis

| Complexity           | Value                           |
| :------------------- | :------------------------------ |
| **Time Complexity**  | `O(n log(max(position)))`       |
| **Space Complexity** | `O(1)` (ignoring input storage) |

- Sorting takes `O(n log n)`.
- The binary search loop runs `O(log(max position))` times.
- Each distance validation (`checkValidDistance`) runs in `O(n)` time.
- Thus, overall complexity is `O(n log(max position))`.

---

## How to Run the Code

### For C++

1. **Setup**: Make sure you have a C++ compiler like `g++` installed.
2. **Save the Code**: Save the code in a file named `solution.cpp`.
3. **Compile**:

   ```bash
   g++ solution.cpp -o solution
   ```

4. **Run**:

   ```bash
   ./solution
   ```

You can modify the `main()` function to pass different test cases to validate your solution.

---
