# Course Schedule II

## Table of Contents

- [Course Schedule II](#course-schedule-ii)
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
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The **Course Schedule II** problem is a classic topological sorting problem where we are tasked with finding a valid ordering of courses to take, given a list of prerequisites. If no valid ordering exists (due to cycles in the graph), we return an empty array.

---

## Problem Description

You are given:

- `numCourses`: The total number of courses labeled from `0` to `numCourses - 1`.
- `prerequisites`: An array where `prerequisites[i] = [ai, bi]` indicates that course `bi` must be taken before course `ai`.

**Output:**

- A valid order of courses to finish all courses.
- If multiple valid orders exist, return any of them.
- If it's impossible to finish all courses, return an empty array.

---

### Examples

#### Example 1

**Input:**  

```plaintext
numCourses = 2, prerequisites = [[1, 0]]
```

**Output:**  

```plaintext
[0, 1]
```

**Explanation:**  
To take course 1, course 0 must be completed first.

---

#### Example 2

**Input:**  

```plaintext
numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
```

**Output:**  

```plaintext
[0, 1, 2, 3]
```

**Explanation:**  

- To take course 3, courses 1 and 2 must be completed.
- Courses 1 and 2 require course 0.

---

#### Example 3

**Input:**  

```plaintext
numCourses = 1, prerequisites = []
```

**Output:**  

```plaintext
[0]
```

**Explanation:**  
With only one course, the order is trivial.

---

### Constraints

- \( 1 \leq \text{numCourses} \leq 2000 \)
- \( 0 \leq \text{prerequisites.length} \leq \text{numCourses} \cdot (\text{numCourses} - 1) \)
- \( \text{prerequisites}[i].\text{length} = 2 \)
- \( 0 \leq a_i, b_i < \text{numCourses} \)
- \( a_i \neq b_i \)
- All pairs in `prerequisites` are distinct.

---

## Approach

We solve this problem using **Kahn's Algorithm** for topological sorting.

Steps:

1. Construct an adjacency list for the graph representation of courses.
2. Compute the in-degree for each course.
3. Use a queue to process courses with zero in-degree.
4. Perform a BFS to construct the topological order.
5. If the topological sort includes all courses, return it. Otherwise, return an empty array.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Adjacency list
        vector<int> indegree(numCourses, 0); // In-degree array
        
        // Build the graph and calculate in-degrees
        for (auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        queue<int> q; // Queue for BFS
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoSort;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            topoSort.push_back(course);
            
            for (auto next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if (topoSort.size() == numCourses) 
            return topoSort; // Valid order
        return {}; // No valid order
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        int[] indegree = new int[numCourses];
        
        // Initialize adjacency list and in-degree array
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] prereq : prerequisites) {
            adj.get(prereq[1]).add(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        
        int[] topoSort = new int[numCourses];
        int index = 0;
        
        while (!q.isEmpty()) {
            int course = q.poll();
            topoSort[index++] = course;
            
            for (int next : adj.get(course)) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
        
        return (index == numCourses) ? topoSort : new int[0];
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph construction:** \( O(V + E) \), where \( V \) is the number of courses and \( E \) is the number of prerequisites.
- **Topological sort:** \( O(V + E) \).
- **Overall:** \( O(V + E) \).

### Space Complexity

- **Adjacency list and in-degree array:** \( O(V + E) \).
- **Queue:** \( O(V) \).
- **Overall:** \( O(V + E) \).

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `solution.cpp`.
2. Compile using:

   ```bash
   g++ -o solution solution.cpp
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

### For Java

1. Save the code in a file, e.g., `Solution.java`.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
