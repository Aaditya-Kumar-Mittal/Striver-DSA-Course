# N Meetings in One Room

## Table of Contents

- [N Meetings in One Room](#n-meetings-in-one-room)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Algorithm Explanation](#algorithm-explanation)
    - [C++ Implementation](#c-implementation)
    - [Explanation of the Code](#explanation-of-the-code)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)

---

## Introduction

The **N Meetings in One Room** problem asks for the maximum number of meetings that can be scheduled in a single meeting room, such that only one meeting is held at a time. Each meeting has a start time and an end time, and the goal is to choose as many meetings as possible without overlap.

---

## Problem Description

Given two arrays:

- `start[]` – an array where each element represents the start time of a meeting.
- `end[]` – an array where each element represents the end time of a meeting.

You need to find the maximum number of meetings that can be scheduled in a single meeting room such that no two meetings overlap.

### Examples

#### Example 1

**Input:**  
`start[] = [1, 3, 0, 5, 8, 5], end[] = [2, 4, 6, 7, 9, 9]`  
**Output:**  
`4`  
**Explanation:** The four meetings that can be held are (1, 2), (3, 4), (5, 7), and (8, 9).

#### Example 2

**Input:**  
`start[] = [10, 12, 20], end[] = [20, 25, 30]`  
**Output:**  
`1`  
**Explanation:** Only one meeting can be held with the given start and end timings.

#### Example 3

**Input:**  
`start[] = [1, 2], end[] = [100, 99]`  
**Output:**  
`1`  
**Explanation:** Only one meeting can be held since the first meeting ends later than the second meeting starts.

---

## Constraints

- `1 ≤ n ≤ 10^5`
- `0 ≤ start[i] < end[i] ≤ 10^6`
- The start times and end times are integers, where `start[i] < end[i]` for each meeting.

---

## Approach

### Algorithm Explanation

1. **Create Meetings Structure**: For each meeting, store its start time, end time, and its original position.
2. **Sort Meetings**: Sort the meetings based on their end times. This ensures that we always choose the meeting that finishes the earliest, allowing for the maximum number of subsequent meetings.
3. **Greedy Selection**: Start by selecting the first meeting (the one with the earliest finish time). For each subsequent meeting, select it only if its start time is greater than the end time of the previously selected meeting. This ensures no overlap between selected meetings.
4. **Track Selected Meetings**: Count how many meetings can be selected and return the count.

---

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;   // Start time of meeting
    int end;     // End time of meeting
    int position; // Original position of meeting
};

class Solution {
public:
    // Comparator function to sort meetings by their end time
    bool static comparator(Meeting a, Meeting b) {
        if (a.end < b.end) {
            return true;
        }
        else if (a.end > b.end) {
            return false;
        }
        else if (a.position < b.position) {
            return true;
        } else {
            return false;
        }
    }

    // Function to find the maximum number of meetings that can be held
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();

        // Create an array of Meeting objects
        struct Meeting meets[n];
        for (int i = 0; i < n; i++) {
            meets[i].start = start[i];
            meets[i].end = end[i];
            meets[i].position = i + 1; // Position of the meeting (1-based)
        }

        // Sort meetings based on their end time
        sort(meets, meets + n, comparator);

        // Count the number of meetings that can be scheduled
        vector<int> answer;
        int freeTime = meets[0].end;
        answer.push_back(meets[0].position);

        // Select meetings greedily
        for (int i = 1; i < n; i++) {
            if (meets[i].start > freeTime) {
                freeTime = meets[i].end;
                answer.push_back(meets[i].position);
            }
        }

        return answer.size(); // Return the number of selected meetings
    }
};
```

### Explanation of the Code

- **Meeting Structure**: Each meeting is represented by a `Meeting` structure containing its `start`, `end`, and `position`.
- **Sorting**: We sort the meetings by their `end` times in ascending order to ensure that we can pick the meeting that finishes the earliest and can accommodate more meetings.
- **Greedy Selection**: Starting with the first meeting, we select meetings where the start time is greater than the end time of the last selected meeting.

---

### Java Implementation

```java
import java.util.*;

class Meeting {
    int start, end, position;

    Meeting(int start, int end, int position) {
        this.start = start;
        this.end = end;
        this.position = position;
    }
}

class Solution {
    public int maxMeetings(int[] start, int[] end) {
        int n = start.length;
        Meeting[] meets = new Meeting[n];

        // Create meetings array with start, end and position
        for (int i = 0; i < n; i++) {
            meets[i] = new Meeting(start[i], end[i], i + 1); // Position is 1-based
        }

        // Sort meetings by their end time
        Arrays.sort(meets, (a, b) -> a.end - b.end);

        // Track the number of meetings
        int count = 1;
        int lastEndTime = meets[0].end;

        // Greedily select meetings
        for (int i = 1; i < n; i++) {
            if (meets[i].start > lastEndTime) {
                count++;
                lastEndTime = meets[i].end;
            }
        }

        return count; // Return the number of selected meetings
    }
}
```

---

## Complexity Analysis

| Approach         | Time Complexity | Space Complexity |
| ---------------- | --------------- | ---------------- |
| Sorting          | O(N log N)      | O(N)             |
| Greedy Selection | O(N)            | O(1)             |
| **Overall**      | O(N log N)      | O(N)             |

- **Time Complexity**: The time complexity is dominated by the sorting step, which takes `O(N log N)`.
- **Space Complexity**: The space complexity is `O(N)` due to the storage of the meetings array.

This approach is efficient enough given the constraints where `N` can go up to `10^5`.
