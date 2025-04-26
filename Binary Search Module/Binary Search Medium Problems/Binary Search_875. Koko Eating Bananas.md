# Koko Eating Bananas

## Table of Contents

- [Koko Eating Bananas](#koko-eating-bananas)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [📈 Visual Diagram for Binary Search Process](#-visual-diagram-for-binary-search-process)
    - [Initial State](#initial-state)
    - [Step-by-Step Binary Search](#step-by-step-binary-search)
    - [Final](#final)
  - [Quick Flowchart Overview](#quick-flowchart-overview)

---

## Introduction

Koko loves to eat bananas and wants to finish all piles of bananas within a given number of hours, `h`. However, she eats at a steady but slow speed, picking a speed `k` (bananas/hour).  
The challenge is to **determine the minimum eating speed `k`** such that Koko can eat all the bananas before the guards return.

---

## Problem Description

You are given:

- An array `piles[]`, where `piles[i]` denotes the number of bananas in the i-th pile.
- An integer `h`, the number of hours Koko has to finish all the bananas.

Each hour:

- Koko eats exactly `k` bananas from a pile (she chooses any pile).
- If a pile has fewer than `k` bananas left, she eats the entire pile in that hour.

You must find the **smallest integer `k`** such that Koko can eat all bananas within `h` hours.

---

### Examples

#### Example 1

**Input:**  
`piles = [3,6,7,11]`  
`h = 8`  
**Output:**  
`4`  
**Explanation:**  
At eating speed 4, she finishes:

- Pile 3 → 1 hour,
- Pile 6 → 2 hours,
- Pile 7 → 2 hours,
- Pile 11 → 3 hours,
  Total = 1+2+2+3 = 8 hours.

---

#### Example 2

**Input:**  
`piles = [30,11,23,4,20]`  
`h = 5`  
**Output:**  
`30`

---

#### Example 3

**Input:**  
`piles = [30,11,23,4,20]`  
`h = 6`  
**Output:**  
`23`

---

### Constraints

- `1 <= piles.length <= 10^4`
- `piles.length <= h <= 10^9`
- `1 <= piles[i] <= 10^9`

---

## Approach

The task requires us to find the **minimum value of `k`** such that the **total hours** taken is **≤ h**.

Since a **higher `k`** results in **fewer hours** (and vice-versa), the relationship between `k` and hours is **monotonically decreasing**, making it a **perfect candidate for Binary Search**.

Thus, we:

- Search the speed `k` using binary search between 1 and the maximum bananas in any pile.
- For each mid-value `k`, calculate total hours required using a helper function.
- If total hours <= h, search on the left half for a potentially smaller `k`.
- Otherwise, search on the right half for a bigger `k`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Helper function to calculate total hours needed at speed k
    long long totalHours(vector<int>& piles, int k) {
        long long tH = 0;
        for (int i = 0; i < piles.size(); i++) {
            tH += ceil((double)piles[i] / (double)k);
        }
        return tH;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end()); // Max bananas in a pile
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2; // Mid-speed
            long long totalTime = totalHours(piles, mid);

            if (totalTime <= h) {
                ans = mid;          // Found a possible answer
                high = mid - 1;     // Try to find smaller k
            } else {
                low = mid + 1;      // Need faster speed
            }
        }

        return low;
    }
};
```

---

## Complexity Analysis

| Type             | Complexity              |
| ---------------- | ----------------------- |
| Time Complexity  | O(n \* log(max(piles))) |
| Space Complexity | O(1) (excluding input)  |

**Explanation:**

- `n` = number of piles
- `max(piles)` = maximum value inside piles
- For each binary search iteration, we traverse the entire `piles` array → O(n)
- Binary search runs for log(max(piles)) iterations

---

## How to Run the Code

### For C++

1. **Copy** the provided C++ code into a file named `solution.cpp`.
2. **Compile** the code:

   ```bash
   g++ solution.cpp -o solution
   ```

3. **Run** the executable:

   ```bash
   ./solution
   ```

4. Make sure you prepare a `main()` function to pass `piles` and `h` values for testing.

---

## 📈 Visual Diagram for Binary Search Process

Let's visualize how Binary Search narrows down:

Suppose:

```plaintext
piles = [3,6,7,11]
h = 8
```

---

### Initial State

| Variable | Value |
| -------- | ----- |
| low      | 1     |
| high     | 11    |

---

### Step-by-Step Binary Search

1. **mid = (1+11)//2 = 6**

   - Total hours at speed 6:

     ```plaintext
     3/6 = 1, 6/6 = 1, 7/6 = 2, 11/6 = 2
     Sum = 6 hours
     ```

   - 6 ≤ 8 ✅ → try smaller k → high = 5

2. **mid = (1+5)//2 = 3**

   - Total hours at speed 3:

     ```plaintext
     3/3 = 1, 6/3 = 2, 7/3 = 3, 11/3 = 4
     Sum = 10 hours
     ```

   - 10 > 8 ❌ → need faster speed → low = 4

3. **mid = (4+5)//2 = 4**

   - Total hours at speed 4:

     ```plaintext
     3/4 = 1, 6/4 = 2, 7/4 = 2, 11/4 = 3
     Sum = 8 hours
     ```

   - 8 ≤ 8 ✅ → try smaller k → high = 3

---

### Final

- `low = 4`, `high = 3`
- Exiting loop → Return `4`

✅ Final Answer = 4

---

## Quick Flowchart Overview

```plaintext
Start: low=1, high=max(piles)

While low <= high:
    mid = (low + high)/2
    if totalHours(mid) <= h:
        ans = mid
        high = mid-1
    else:
        low = mid+1

Return low
```

---
