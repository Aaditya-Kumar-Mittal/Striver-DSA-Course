# 435. Non-overlapping Intervals

## Table of Contents

- [435. Non-overlapping Intervals](#435-non-overlapping-intervals)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Steps](#key-steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The problem involves identifying and removing the minimum number of overlapping intervals from a given array so that the rest are non-overlapping. This is achieved by sorting the intervals based on their end times and iterating through the list to count the non-overlapping intervals.

---

## Problem Description

Given an array of intervals where each interval is represented as `[start, end]`, return the **minimum number of intervals** to remove to make the rest non-overlapping.

### Examples

#### Example 1

**Input**: `intervals = [[1,2],[2,3],[3,4],[1,3]]`  
**Output**: `1`  
**Explanation**: Removing `[1,3]` makes the remaining intervals non-overlapping.

#### Example 2

**Input**: `intervals = [[1,2],[1,2],[1,2]]`  
**Output**: `2`  
**Explanation**: Removing two `[1,2]` intervals makes the rest non-overlapping.

#### Example 3

**Input**: `intervals = [[1,2],[2,3]]`  
**Output**: `0`  
**Explanation**: The intervals are already non-overlapping.

---

### Constraints

1. \( 1 \leq \text{intervals.length} \leq 10^5 \)
2. \( \text{intervals}[i].\text{length} == 2 \)
3. \( -5 \times 10^4 \leq \text{start}\_i < \text{end}\_i \leq 5 \times 10^4 \)

---

## Approach

The optimal way to minimize removals is to maximize the number of non-overlapping intervals. This can be done by:

1. Sorting the intervals by their end times.
2. Iterating through the sorted intervals, selecting the first interval, and skipping overlapping intervals.

### Key Steps

1. **Sorting**: Sort intervals by their end times.
2. **Tracking Non-overlapping Intervals**:
   - Use a variable `lastEndTime` to track the end time of the last added interval.
   - Increment a `count` for each non-overlapping interval found.
3. **Calculate Removals**:
   - Total removals = Total intervals - Count of non-overlapping intervals.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // Comparator to sort intervals based on end time
    static bool comparator(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // Sort intervals by their end times
        sort(intervals.begin(), intervals.end(), comparator);

        int lastEndTime = intervals[0][1];
        int count = 1; // Count of non-overlapping intervals

        for (int i = 1; i < n; i++) {
            if (intervals[i][0] >= lastEndTime) {
                count += 1;
                lastEndTime = intervals[i][1];
            }
        }

        // Total intervals to remove
        return n - count;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    Solution sol;
    cout << "Minimum intervals to remove: " << sol.eraseOverlapIntervals(intervals) << endl;
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

public class Solution {
    public int eraseOverlapIntervals(int[][] intervals) {
        // Sort intervals by their end times
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[1], b[1]));

        int lastEndTime = intervals[0][1];
        int count = 1; // Count of non-overlapping intervals

        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= lastEndTime) {
                count++;
                lastEndTime = intervals[i][1];
            }
        }

        // Total intervals to remove
        return intervals.length - count;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
        System.out.println("Minimum intervals to remove: " + sol.eraseOverlapIntervals(intervals));
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **Sorting**: \( O(n \log n) \), where \( n \) is the number of intervals.
2. **Iteration**: \( O(n) \).

Total: \( O(n \log n) \)

### Space Complexity

- Sorting requires \( O(\log n) \) for the sorting algorithm's stack space.
- Total: \( O(\log n) \)

---

## How to Run the Code

### For C++

1. Save the code in a file named `main.cpp`.
2. Compile the code:

   ```bash
   g++ -o main main.cpp
   ```

3. Run the program:

   ```bash
   ./main
   ```

### For Java

1. Save the code in a file named `Solution.java`.
2. Compile the code:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
