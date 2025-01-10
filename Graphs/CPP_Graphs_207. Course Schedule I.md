# Course Schedule

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Course Schedule](#course-schedule)
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
  - [Detecting a Cycle in a Directed Graph (Topological Sort)](#detecting-a-cycle-in-a-directed-graph-topological-sort)
    - [BFS Approach](#bfs-approach)
      - [Code](#code)
    - [DFS Approach](#dfs-approach)
      - [Code](#code-1)
    - [Comparison of BFS and DFS](#comparison-of-bfs-and-dfs)

---

## Introduction

The "Course Schedule" problem involves determining if all courses in a curriculum can be completed given a set of prerequisite relationships. The challenge is to identify whether there exists a cycle in the dependency graph of courses, which would make completing all courses impossible.

---

## Problem Description

You are given a total of `numCourses` labeled from `0` to `numCourses - 1`. A 2D array `prerequisites` represents prerequisite relationships such that `prerequisites[i] = [ai, bi]` means to take course `ai`, you must first take course `bi`.

Return `true` if all courses can be completed, otherwise return `false`.

---

### Examples

#### Example 1

**Input:**

```plaintext
numCourses = 2, prerequisites = [[1,0]]
```

**Output:**

```plaintext
true
```

**Explanation:**  
To take course `1`, you need to complete course `0`. It is possible to complete all courses.

---

#### Example 2

**Input:**

```plaintext
numCourses = 2, prerequisites = [[1,0],[0,1]]
```

**Output:**

```plaintext
false
```

**Explanation:**  
There is a cyclic dependency: course `1` requires course `0` and course `0` requires course `1`.

---

### Constraints

- \( 1 \leq \text{numCourses} \leq 2000 \)
- \( 0 \leq \text{prerequisites.length} \leq 5000 \)
- \( \text{prerequisites}[i].length == 2 \)
- \( 0 \leq a_i, b_i < \text{numCourses} \)
- All pairs in `prerequisites` are unique.

---

## Approach

To determine if all courses can be completed, we use **Kahn's Algorithm** for topological sorting. The algorithm identifies cycles in a directed graph by tracking in-degrees of each node. A zero in-degree indicates no prerequisites for that course.

Steps:

1. Represent the course dependencies using an adjacency list.
2. Calculate the in-degree for each course.
3. Use a queue to process courses with zero in-degree.
4. Attempt to generate a topological order. If the topological order includes all courses, return `true`. Otherwise, return `false`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); // Adjacency list
        vector<int> indegree(numCourses, 0); // In-degree array
        
        // Build graph and calculate in-degrees
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
        
        int count = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            count++;
            
            for (auto next : adj[course]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }
        
        return count == numCourses;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
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
        
        int count = 0;
        while (!q.isEmpty()) {
            int course = q.poll();
            count++;
            
            for (int next : adj.get(course)) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.add(next);
                }
            }
        }
        
        return count == numCourses;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Building the graph**: \( O(V + E) \), where \( V \) is the number of courses and \( E \) is the number of prerequisites.
- **Topological sorting**: \( O(V + E) \).
- **Overall**: \( O(V + E) \).

### Space Complexity

- Adjacency list: \( O(V + E) \).
- Queue and in-degree array: \( O(V) \).
- **Overall**: \( O(V + E) \).

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

## Detecting a Cycle in a Directed Graph (Topological Sort)

This problem is equivalent to detecting a cycle in the directed graph represented by prerequisites. Both BFS and DFS can be used to solve it using the idea of **topological sort**. Since `pair<int, int>` is inconvenient for implementing graph algorithms, we first transform it to the adjacency-list representation. If course `u` is a prerequisite of course `v`, then the adjacency list of `u` will contain `v`.

---

### BFS Approach

BFS uses the indegrees of each node. The algorithm proceeds as follows:

1. Identify nodes with an indegree of `0`.
2. If no such node exists, there must be a cycle in the graph, and we return `false`.
3. Otherwise, set the indegree of the current node to `-1` to prevent revisiting it, and reduce the indegrees of its neighbors by `1`.
4. Repeat this process for `n` (number of nodes) times.

#### Code

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }

private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }

    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};
```

---

### DFS Approach

For DFS, the algorithm performs the following steps:

1. Start from a node and keep visiting its neighbors.
2. If a visited node is encountered again, there is a cycle.
3. If no cycle is detected, start again from another unvisited node and repeat.
4. Use `todo` for nodes to visit and `done` for visited nodes.

#### Code

```cpp
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return false;
            }
        }
        return true;
    }

private:
    typedef vector<vector<int>> graph;

    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }

    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int v : g[node]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
};
```

---

### Comparison of BFS and DFS

| **Aspect**            | **BFS**                              | **DFS**                              |
|-----------------------|--------------------------------------|--------------------------------------|
| **Method**            | Uses indegrees of nodes             | Recursively traverses neighbors     |
| **Cycle Detection**   | Fails to find a node with `0` indegree | Revisits an already visited node     |
| **Space Complexity**  | `O(V + E)`                          | `O(V + E)`                          |
| **Use Case**          | Easier for topological sorting       | More natural for cycle detection    |
