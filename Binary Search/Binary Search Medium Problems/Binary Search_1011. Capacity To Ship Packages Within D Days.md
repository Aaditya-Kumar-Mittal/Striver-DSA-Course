# Capacity To Ship Packages Within D Days

## Table of Contents

- [Capacity To Ship Packages Within D Days](#capacity-to-ship-packages-within-d-days)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)

## Introduction

The problem involves finding the **minimum ship capacity** required to ship all packages within a given number of days while maintaining the **order** of packages.  
The ship cannot carry packages exceeding its maximum weight capacity on any day, and the packages must be loaded in the given order without skipping.

## Problem Description

Given:

- An array `weights` where `weights[i]` represents the weight of the `i-th` package.
- An integer `days`, the number of days within which all packages must be shipped.

You must determine the **least weight capacity** the ship must have to transport all the packages within `days`.

### Examples

**Example 1:**

> Input: `weights = [1,2,3,4,5,6,7,8,9,10]`, `days = 5`  
> Output: `15`  
> Explanation:  
> 1st day: `[1,2,3,4,5]`  
> 2nd day: `[6,7]`  
> 3rd day: `[8]`  
> 4th day: `[9]`  
> 5th day: `[10]`

---

**Example 2:**

> Input: `weights = [3,2,2,4,1,4]`, `days = 3`  
> Output: `6`  
> Explanation:  
> 1st day: `[3,2]`  
> 2nd day: `[2,4]`  
> 3rd day: `[1,4]`

---

**Example 3:**

> Input: `weights = [1,2,3,1,1]`, `days = 4`  
> Output: `3`  
> Explanation:  
> 1st day: `[1]`  
> 2nd day: `[2]`  
> 3rd day: `[3]`  
> 4th day: `[1,1]`

---

### Constraints

- `1 <= days <= weights.length <= 5 * 10^4`
- `1 <= weights[i] <= 500`

## Approach

We have two approaches:

1. **Brute-force Approach**:

   - Start from the maximum individual weight (since the ship must at least carry the heaviest package).
   - Incrementally try every possible ship capacity.
   - Check if all packages can be shipped within the given number of days for each capacity.
   - Stop at the first valid capacity.

2. **Optimized Approach (Binary Search)**:
   - Apply binary search between the maximum weight and the sum of all weights.
   - For a mid-value (candidate capacity), simulate shipping and count required days.
   - If the number of days is less than or equal to given days, try a smaller capacity.
   - Else, try a larger capacity.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    // Helper function to check how many days are required for a given ship capacity
    int checkDays(vector<int>& weights, int capacity) {
        int countDays = 1;
        int totalLoad = 0;

        for (int i = 0; i < weights.size(); i++) {
            if (totalLoad + weights[i] > capacity) {
                countDays++;
                totalLoad = weights[i];
            } else {
                totalLoad += weights[i];
            }
        }

        return countDays;
    }

    // Brute Force Approach
    int leastWeightCapacityBrute(vector<int>& weights, int d) {
        int minPossible = *max_element(weights.begin(), weights.end());
        int maxPossible = accumulate(weights.begin(), weights.end(), 0);

        for (int capacity = minPossible; capacity <= maxPossible; capacity++) {
            if (checkDays(weights, capacity) <= d)
                return capacity;
        }

        return -1;
    }

    // Optimized Binary Search Approach
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = INT_MAX;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int getDays = checkDays(weights, mid);

            if (getDays <= days) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (ans != INT_MAX) ? ans : -1;
    }
};
```

```java
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int maxWeight = 0, totalWeight = 0;
        for (int weight : weights) {
            maxWeight = Math.max(maxWeight, weight);
            totalWeight += weight;
        }
        
        int low = maxWeight, high = totalWeight;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (canShip(weights, days, mid)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    
    private boolean canShip(int[] weights, int days, int capacity) {
        int currentLoad = 0;
        int requiredDays = 1;
        for (int weight : weights) {
            if (currentLoad + weight > capacity) {
                requiredDays++;
                currentLoad = 0;
            }
            currentLoad += weight;
        }
        return requiredDays <= days;
    }
}
```

---

## Complexity Analysis

| Approach      |             Time Complexity              | Space Complexity | Explanation                                                                               |
| :------------ | :--------------------------------------: | :--------------: | :---------------------------------------------------------------------------------------- |
| Brute Force   |  O((sum(weights) - max(weights)) \* n)   |       O(1)       | For each capacity, check in O(n) time. Very inefficient for large inputs.                 |
| Binary Search | O(n \* log(sum(weights) - max(weights))) |       O(1)       | Binary search over the capacity range and O(n) for each check. Much faster and efficient. |

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `solution.cpp`.
2. Compile the code:

   ```bash
   g++ solution.cpp -o solution
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

---
