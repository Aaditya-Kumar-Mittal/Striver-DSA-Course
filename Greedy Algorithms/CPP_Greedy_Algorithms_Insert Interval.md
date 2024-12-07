# 57. Insert Interval

## Table of Contents

- [57. Insert Interval](#57-insert-interval)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps to Solve](#steps-to-solve)
    - [Key Observations](#key-observations)
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

The task is to insert a new interval into a list of non-overlapping intervals, merge any overlapping intervals, and return the updated list. The input intervals are already sorted by their start times.

---

## Problem Description

You are given:

1. An array of non-overlapping intervals `intervals`, sorted in ascending order by start time.
2. A `newInterval` that needs to be inserted into `intervals`.

Return the modified list after inserting `newInterval` and merging any overlapping intervals.

---

### Examples

#### Example 1

**Input**:  
`intervals = [[1,3],[6,9]], newInterval = [2,5]`  
**Output**:  
`[[1,5],[6,9]]`

---

#### Example 2

**Input**:  
`intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]`  
**Output**:  
`[[1,2],[3,10],[12,16]]`

**Explanation**: The new interval `[4,8]` overlaps with `[3,5], [6,7], [8,10]`.

---

### Constraints

1. \( 0 \leq \text{intervals.length} \leq 10^4 \)
2. \( \text{intervals}[i].\text{length} == 2 \)
3. \( 0 \leq \text{start}\_i \leq \text{end}\_i \leq 10^5 \)
4. \( \text{intervals} \) is sorted by start time.
5. \( \text{newInterval.length} == 2 \)
6. \( 0 \leq \text{start} \leq \text{end} \leq 10^5 \)

---

## Approach

### Steps to Solve

1. **Identify Non-overlapping Intervals**:
   - Add intervals that end before the start of `newInterval` to the result.
2. **Merge Overlapping Intervals**:
   - While there are overlaps between the current interval and `newInterval`, merge them into one.
3. **Add Remaining Intervals**:
   - Add intervals that start after the end of `newInterval` to the result.

### Key Observations

- Use the fact that the intervals are already sorted to simplify the merging process.
- A single pass through the intervals is sufficient.

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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int i = 0, n = intervals.size();

        // Add all intervals that end before the start of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.push_back(intervals[i]);
            i++;
        }

        // Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.push_back(newInterval);

        // Add remaining intervals
        while (i < n) {
            result.push_back(intervals[i]);
            i++;
        }

        return result;
    }
};

int main() {
    vector<vector<int>> intervals = {{1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};
    Solution sol;

    vector<vector<int>> result = sol.insert(intervals, newInterval);

    cout << "Modified intervals: " << endl;
    for (auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

public class Solution {
    public int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> result = new ArrayList<>();
        int i = 0, n = intervals.length;

        // Add all intervals that end before the start of newInterval
        while (i < n && intervals[i][1] < newInterval[0]) {
            result.add(intervals[i]);
            i++;
        }

        // Merge overlapping intervals with newInterval
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        result.add(newInterval);

        // Add remaining intervals
        while (i < n) {
            result.add(intervals[i]);
            i++;
        }

        return result.toArray(new int[result.size()][]);
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[][] intervals = {{1, 3}, {6, 9}};
        int[] newInterval = {2, 5};

        int[][] result = sol.insert(intervals, newInterval);

        System.out.println("Modified intervals:");
        for (int[] interval : result) {
            System.out.println(Arrays.toString(interval));
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **Traversal**: \( O(n) \), where \( n \) is the number of intervals.
2. **Merging**: Constant work per interval.

Total: \( O(n) \)

### Space Complexity

- **C++**: \( O(n) \) for the result vector.
- **Java**: \( O(n) \) for the result list.

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
