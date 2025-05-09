# Aggressive Cows

## Table of Contents

- [Aggressive Cows](#aggressive-cows)
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

---

## Introduction

You are given a set of stalls located at different positions on a straight line and a number of cows.  
The goal is to place the cows in the stalls such that the **minimum distance** between any two cows is **as large as possible**.  
This is a **classic binary search on answer** problem and tests greedy placement combined with binary search skills.

---

## Problem Description

- Given an array `stalls[]` where each element represents the position of a stall.
- Given an integer `k` representing the number of cows.
- You must place the cows in the stalls such that:
  - No two cows are placed in the same stall.
  - The **minimum distance** between any two cows is **maximized**.

Return the largest minimum distance possible.

---

### Examples

#### Example 1

**Input:**

```plaintext
stalls = [1, 2, 4, 8, 9]
k = 3
```

**Output:**

```plaintext
3
```

**Explanation:**

- Place cows at stalls 1, 4, and 8.
- Distances between cows: 3 (4-1), 4 (8-4).
- Minimum distance = 3.

---

#### Example 2

**Input:**

```plaintext
stalls = [10, 1, 2, 7, 5]
k = 3
```

**Output:**

```plaintext
4
```

**Explanation:**

- After sorting: [1, 2, 5, 7, 10].
- Place cows at stalls 1, 5, and 10.
- Distances between cows: 4 (5-1), 5 (10-5).
- Minimum distance = 4.

---

#### Example 3

**Input:**

```plaintext
stalls = [2, 12, 11, 3, 26, 7]
k = 5
```

**Output:**

```plaintext
1
```

**Explanation:**

- There are exactly 5 stalls and 5 cows.
- Minimum distance will be small, possibly 1, and that’s the best achievable.

---

### Constraints

- `2 <= stalls.size() <= 10^6`
- `0 <= stalls[i] <= 10^8`
- `2 <= k <= stalls.size()`
- All stall positions are unique.

---

## Approach

There are two approaches mentioned:

1. **Brute Force Approach**:

   - Try every possible minimum distance from 1 to the maximum stall distance.
   - For each distance, check if it’s possible to place cows with at least that distance.
   - Very slow for large inputs (`O(n × max_distance)`), hence not optimal.

2. **Optimized Approach (Binary Search on Answer)**:
   - **Sort** the stall positions.
   - **Binary Search** over the distance between cows:
     - Try a middle distance.
     - Use a **greedy method** to check if it is possible to place all cows with that distance.
     - If possible, try larger distance; else, reduce distance.

**Why binary search?**

- The answer space (minimum possible distance) is **monotonic**:  
  If distance `d` is possible, any smaller distance `< d` is also possible.  
  If distance `d` is not possible, any larger distance `> d` is also not possible.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Function to check if we can place k cows with at least 'distance' gap
    bool checkValidDistance(vector<int> &stalls, int n, int distance, int k) {
        int countCows = 1;  // First cow placed at first stall
        int lastCowAt = stalls[0];

        for (int stall = 1; stall < stalls.size(); stall++) {
            if (stalls[stall] - lastCowAt >= distance) {
                countCows++;
                lastCowAt = stalls[stall];
            }
            if (countCows >= k)
                return true; // Able to place all cows
        }
        return false; // Not enough cows placed
    }

    // Brute force approach (for understanding, not for large inputs)
    int aggressiveCowsBrute(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int maxPossible = stalls[n-1] - stalls[0];

        for (int distance = 1; distance <= maxPossible; distance++) {
            if (checkValidDistance(stalls, n, distance, k))
                continue;
            return distance - 1;
        }

        return maxPossible;
    }

    // Optimized approach using Binary Search
    int aggressiveCows(vector<int> &stalls, int k) {
        sort(stalls.begin(), stalls.end());

        int n = stalls.size();
        int low = 1, high = stalls[n-1] - stalls[0];
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (checkValidDistance(stalls, n, mid, k)) {
                ans = mid;        // Try for bigger distance
                low = mid + 1;
            } else {
                high = mid - 1;   // Try smaller distances
            }
        }

        return ans;
    }
};
```

---

## Complexity Analysis

| Complexity           | Brute Force                     | Optimized (Binary Search)       |
| :------------------- | :------------------------------ | :------------------------------ |
| **Time Complexity**  | `O(n × maxPossibleDistance)`    | `O(n log(maxPossibleDistance))` |
| **Space Complexity** | `O(1)` (Ignoring input storage) | `O(1)` (Ignoring input storage) |

- Sorting: `O(n log n)`
- Each check: `O(n)`
- Binary search over `log(maxPossibleDistance)`, where max distance can be up to `10^8`.
- Hence, optimized solution is **much faster** for large inputs.

---

## How to Run the Code

### For C++

1. **Setup**: Ensure a C++ compiler like `g++` is installed.
2. **Save the Code**: Create a file `solution.cpp` with the above code.
3. **Compile the Code**:

   ```bash
   g++ solution.cpp -o solution
   ```

4. **Run the Executable**:

   ```bash
   ./solution
   ```

**Note:**  
You should write a `main()` function to create an object of `Solution` class and test with different examples.

Example `main()` function:

```cpp
int main() {
    Solution obj;
    vector<int> stalls = {1, 2, 4, 8, 9};
    int k = 3;
    cout << obj.aggressiveCows(stalls, k) << endl;
    return 0;
}
```

---
