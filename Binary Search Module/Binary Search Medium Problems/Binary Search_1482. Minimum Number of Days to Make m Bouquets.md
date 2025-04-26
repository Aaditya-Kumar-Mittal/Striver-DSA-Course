# Minimum Number of Days to Make m Bouquets

## Table of Contents

- [Minimum Number of Days to Make m Bouquets](#minimum-number-of-days-to-make-m-bouquets)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [1. Brute Force (minDaysBrute)](#1-brute-force-mindaysbrute)
      - [Why is this slow?](#why-is-this-slow)
    - [2. Binary Search Optimization (minDays)](#2-binary-search-optimization-mindays)
      - [Key Helper Function: `possibleDay`](#key-helper-function-possibleday)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

This document discusses the solution for LeetCode Problem **1482. Minimum Number of Days to Make m Bouquets**.

We are given the blooming days of flowers in a garden, and the task is to determine the minimum number of days needed to make exactly `m` bouquets, with each bouquet consisting of `k` adjacent bloomed flowers.

If it's impossible to make `m` bouquets, we return `-1`.

---

## Problem Description

Given:

- An integer array `bloomDay`, where `bloomDay[i]` represents the day the `i-th` flower blooms.
- Two integers `m` and `k`.

We must make `m` bouquets, and each bouquet must use exactly `k` **adjacent** bloomed flowers.

Return the **minimum day** needed to achieve this. If not possible, return `-1`.

### Examples

**Example 1:**

```plaintext
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1
Output: 3
Explanation:
After day 1: [x, _, _, _, _]  -> 1 bouquet
After day 2: [x, _, _, _, x]  -> 2 bouquets
After day 3: [x, _, x, _, x]  -> 3 bouquets (Enough)
Thus, minimum day is 3.
```

---

**Example 2:**

```plaintext
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2
Output: -1
Explanation:
We need 6 flowers (3 bouquets × 2 flowers), but only 5 flowers exist.
Hence, impossible.
```

---

**Example 3:**

```plaintext
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3
Output: 12
Explanation:
After day 7: [x, x, x, x, _, x, x]
We can only make 1 bouquet because we need 3 adjacent flowers.
After day 12: [x, x, x, x, x, x, x]
Now enough adjacent flowers to make 2 bouquets.
```

---

### Constraints

- `bloomDay.length == n`
- `1 <= n <= 10^5`
- `1 <= bloomDay[i] <= 10^9`
- `1 <= m <= 10^6`
- `1 <= k <= n`

---

## Approach

We solve the problem with two methods:

### 1. Brute Force (minDaysBrute)

- Try **every possible day** from the minimum bloom day to the maximum bloom day.
- For each day, check if it is possible to make the required number of bouquets.

#### Why is this slow?

- It may need to check up to `10^9` days individually.
- Hence, **Time Limit Exceeded (TLE)** on large inputs.

---

### 2. Binary Search Optimization (minDays)

- The number of days is in a **continuous range**. Thus, binary search can efficiently find the minimal day.
- We:
  - Set the initial range between the minimum and maximum bloom days.
  - Check for the mid-day: if possible, search for smaller days (`high = mid-1`), else search higher (`low = mid+1`).

#### Key Helper Function: `possibleDay`

- Simulate whether it is possible to make `m` bouquets on a given day.
- Count consecutive bloomed flowers.
- Each time we get `k` consecutive flowers, one bouquet is formed.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    // Helper function to check if m bouquets can be made by a specific day
    bool possibleDay(vector<int>& bloomDay, int n, int day, int m, int k) {
        int countDay = 0;    // consecutive bloomed flowers
        int countBouquet = 0; // total bouquets

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                countDay++;
                if (countDay == k) {
                    countBouquet++;
                    countDay = 0; // reset after forming one bouquet
                }
            } else {
                countDay = 0; // broken sequence
            }
        }

        return countBouquet >= m;
    }

    // Brute Force Approach: Check each day sequentially
    int minDaysBrute(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (n < m * k) return -1; // impossible if not enough flowers

        int minDay = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDay = *max_element(bloomDay.begin(), bloomDay.end());

        for (int day = minDay; day <= maxDay; day++) {
            if (possibleDay(bloomDay, n, day, m, k))
                return day;
        }
        return -1;
    }

    // Optimized Approach: Binary Search
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long requiredFlowers = 1LL * m * k;

        if (n < requiredFlowers) return -1; // impossible if not enough flowers

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possibleDay(bloomDay, n, mid, m, k)) {
                ans = mid;
                high = mid - 1; // look for earlier possibility
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

public class Solution {

    // Helper method to check if m bouquets can be made by a specific day
    private boolean possibleDay(int[] bloomDay, int day, int m, int k) {
        int countDay = 0;
        int countBouquet = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                countDay++;
                if (countDay == k) {
                    countBouquet++;
                    countDay = 0;
                }
            } else {
                countDay = 0;
            }
        }

        return countBouquet >= m;
    }

    // Brute Force Method
    public int minDaysBrute(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        if (n < m * k) return -1;

        int minDay = Arrays.stream(bloomDay).min().getAsInt();
        int maxDay = Arrays.stream(bloomDay).max().getAsInt();

        for (int day = minDay; day <= maxDay; day++) {
            if (possibleDay(bloomDay, day, m, k))
                return day;
        }
        return -1;
    }

    // Optimized Binary Search Method
    public int minDays(int[] bloomDay, int m, int k) {
        int n = bloomDay.length;
        long requiredFlowers = 1L * m * k;

        if (n < requiredFlowers) return -1;

        int low = Arrays.stream(bloomDay).min().getAsInt();
        int high = Arrays.stream(bloomDay).max().getAsInt();
        int ans = Integer.MAX_VALUE;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possibleDay(bloomDay, mid, m, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
}
```

---

## Complexity Analysis

| Approach                | Time Complexity              | Space Complexity |
| :---------------------- | :--------------------------- | :--------------- |
| Brute Force Approach    | O((maxDay - minDay) \* n)    | O(1)             |
| Optimized Binary Search | O(n \* log(maxDay - minDay)) | O(1)             |

- **Brute Force** checks every day, making it infeasible for large ranges.
- **Binary Search** cuts down the days' range logarithmically.

---

## How to Run the Code

### For C++

1. Save the code in a file named `solution.cpp`.
2. Compile using:

   ```bash
   g++ -std=c++17 solution.cpp -o solution
   ```

3. Run:

   ```bash
   ./solution
   ```

### For Java

1. Save the code in a file named `Solution.java`.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run:

   ```bash
   java Solution
   ```

---
