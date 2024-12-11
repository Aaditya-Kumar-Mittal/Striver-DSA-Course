# Merge Intervals

## Table of Contents

- [Merge Intervals](#merge-intervals)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Introduction

The **Merge Intervals** problem involves merging overlapping intervals from a given list of intervals. Each interval is represented as `[start, end]`, where `start` is the starting time and `end` is the ending time.

---

## Problem Description

### Input

- A list of intervals where `intervals[i] = [starti, endi]`.

### Output

- A list of non-overlapping intervals covering all input intervals.

---

## Examples

### Example 1

**Input:**  
`intervals = [[1,3],[2,6],[8,10],[15,18]]`  
**Output:**  
`[[1,6],[8,10],[15,18]]`  
**Explanation:**  
Intervals `[1,3]` and `[2,6]` overlap, so they are merged into `[1,6]`.

### Example 2

**Input:**  
`intervals = [[1,4],[4,5]]`  
**Output:**  
`[[1,5]]`  
**Explanation:**  
Intervals `[1,4]` and `[4,5]` are considered overlapping and merged into `[1,5]`.

---

## Constraints

- \( 1 \leq \text{intervals.length} \leq 10^4 \)
- \( \text{intervals}[i].\text{length} == 2 \)
- \( 0 \leq \text{starti} \leq \text{endi} \leq 10^4 \)

---

## Approach

1. Sort the intervals by their starting times.
2. Use a temporary interval to merge overlapping intervals.
3. Traverse through the sorted intervals:
   - If the current interval overlaps with the temporary interval, update the temporary interval's end time.
   - If the current interval does not overlap, add the temporary interval to the result list and update the temporary interval to the current interval.
4. Add the last temporary interval to the result list.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;

        if (intervals.empty()) {
            return merged;
        }

        // Sort intervals by start time
        sort(intervals.begin(), intervals.end());

        // Initialize with the first interval
        vector<int> temp = intervals[0];

        // Traverse intervals
        for (auto it : intervals) {
            if (it[0] <= temp[1]) {
                // Overlap detected; merge intervals
                temp[1] = max(it[1], temp[1]);
            } else {
                // No overlap; push current interval to merged list
                merged.push_back(temp);
                temp = it;
            }
        }

        // Add the last interval
        merged.push_back(temp);
        return merged;
    }
};

// Driver Code
int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution obj;
    vector<vector<int>> result = obj.merge(intervals);

    for (auto interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[][] merge(int[][] intervals) {
        List<int[]> merged = new ArrayList<>();

        if (intervals.length == 0) {
            return new int[0][];
        }

        // Sort intervals by start time
        Arrays.sort(intervals, (a, b) -> Integer.compare(a[0], b[0]));

        // Initialize with the first interval
        int[] temp = intervals[0];

        // Traverse intervals
        for (int[] it : intervals) {
            if (it[0] <= temp[1]) {
                // Overlap detected; merge intervals
                temp[1] = Math.max(it[1], temp[1]);
            } else {
                // No overlap; push current interval to merged list
                merged.add(temp);
                temp = it;
            }
        }

        // Add the last interval
        merged.add(temp);
        return merged.toArray(new int[merged.size()][]);
    }

    // Driver Code
    public static void main(String[] args) {
        int[][] intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        Solution obj = new Solution();
        int[][] result = obj.merge(intervals);

        for (int[] interval : result) {
            System.out.println("[" + interval[0] + ", " + interval[1] + "]");
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- Sorting the intervals: \( O(n \log n) \), where \( n \) is the number of intervals.
- Merging intervals: \( O(n) \).
- **Overall Time Complexity:** \( O(n \log n) \).

### Space Complexity

- \( O(n) \) for storing the merged intervals.
