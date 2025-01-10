# Task Ordering Problem

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Task Ordering Problem](#task-ordering-problem)
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
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The **Task Ordering Problem** is a variant of the topological sorting problem. Given tasks with dependencies, the goal is to find an order to complete all tasks, if possible. If a valid ordering is not feasible due to cyclic dependencies, the function should return an empty array.

---

## Problem Description

You are tasked with finding an ordering of tasks that satisfies all dependencies.  
Each task is represented as a pair `[ai, bi]`, where task `ai` depends on task `bi`. The function must return:

- A valid order to complete all tasks.
- An empty array if no valid order exists.

---

### Examples

#### Example 1

**Input:**  

```plaintext
n = 2, m = 1, prerequisites = {{1, 0}}
```

**Output:**  

```plaintext
1
```

**Explanation:**  
The output `1` signifies that a valid order exists. One such order is `[0, 1]`.

---

#### Example 2

**Input:**  

```plaintext
n = 4, m = 4, prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}}
```

**Output:**  

```plaintext
1
```

**Explanation:**  
A valid order could be `[0, 1, 2, 3]` or `[0, 2, 1, 3]`.

---

### Constraints

- \( 1 \leq n \leq 10^5 \)
- \( 0 \leq m \leq \min(n \cdot (n-1), 10^5) \)
- \( 0 \leq \text{prerequisites}[i][0], \text{prerequisites}[i][1] < n \)
- All prerequisite pairs are unique.
- \( \text{prerequisites}[i][0] \neq \text{prerequisites}[i][1] \)

---

## Approach

We solve this problem using **Kahn's Algorithm**, which is a BFS-based method for topological sorting.

Steps:

1. Represent dependencies using an adjacency list.
2. Compute the in-degree of all tasks.
3. Use a queue to process tasks with zero in-degree.
4. Gradually construct the task order by processing the queue.
5. If all tasks are processed, return the order. Otherwise, return an empty array.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
        vector<vector<int>> adj(n); // Adjacency list
        vector<int> indegree(n, 0); // In-degree array
        
        // Build the graph and calculate in-degrees
        for (auto& prereq : prerequisites) {
            adj[prereq[1]].push_back(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        queue<int> q; // Queue for tasks with zero in-degree
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> topoSort; // To store the task order
        
        while (!q.empty()) {
            int task = q.front();
            q.pop();
            topoSort.push_back(task);
            
            for (auto next : adj[task]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        if (topoSort.size() == n) 
            return topoSort; // Valid order found
        else 
            return {}; // No valid order exists
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[] findOrder(int n, int m, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        int[] indegree = new int[n];
        
        // Initialize adjacency list and in-degree array
        for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] prereq : prerequisites) {
            adj.get(prereq[1]).add(prereq[0]);
            indegree[prereq[0]]++;
        }
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }
        
        int[] topoSort = new int[n];
        int index = 0;
        
        while (!q.isEmpty()) {
            int task = q.poll();
            topoSort[index++] = task;
            
            for (int next : adj.get(task)) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
        
        return (index == n) ? topoSort : new int[0];
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph construction:** \( O(n + m) \), where \( n \) is the number of tasks and \( m \) is the number of dependencies.
- **Topological sort:** \( O(n + m) \).
- **Overall:** \( O(n + m) \).

### Space Complexity

- **Adjacency list and in-degree array:** \( O(n + m) \).
- **Queue:** \( O(n) \).
- **Overall:** \( O(n + m) \).

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
