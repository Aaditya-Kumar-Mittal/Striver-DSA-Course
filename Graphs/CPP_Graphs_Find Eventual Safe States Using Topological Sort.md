# Eventual Safe States

## Table of Contents

- [Eventual Safe States](#eventual-safe-states)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Expected Output](#expected-output)
    - [Definitions](#definitions)
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

The **Eventual Safe States** problem involves determining all "safe nodes" in a directed graph. A node is considered safe if all paths originating from it eventually lead to a terminal node (a node with no outgoing edges). The task is to return a list of safe nodes sorted in ascending order.

---

## Problem Description

Given:

- `V`: The number of vertices in the graph.
- `adj`: An adjacency list representing the directed graph.

### Expected Output

A sorted list of all safe nodes.

### Definitions

- **Terminal Node:** A node with no outgoing edges.
- **Safe Node:** A node from which all paths lead to a terminal node.

---

### Examples

#### Example 1

**Input:**

```bash
V = 7, E = 8
adj = {{}, {2, 3}, {5}, {5}, {1}, {}, {5}}
```

**Output:**

```bash
[2, 4, 5, 6]
```

**Explanation:**  
Nodes `5` and `6` are terminal nodes. Nodes `2` and `4` lead to terminal nodes.

---

#### Example 2

**Input:**

```bash
V = 4, E = 4
adj = {{1}, {2}, {3}, {}}
```

**Output:**

```bash
[3]
```

**Explanation:**  
Node `3` is a terminal node, and all paths from it are safe.

---

### Constraints

- \( 1 \leq V \leq 10^4 \)
- \( 0 \leq E \leq 10^4 \)
- No self-loops in the graph.
- Each node in the graph is uniquely labeled.

---

## Approach

The solution uses **Topological Sorting** with reversed edges:

1. Reverse the graph edges to create a new adjacency list.
2. Identify nodes with zero in-degrees and add them to a queue.
3. Process nodes in the queue, reducing in-degrees of their neighbors.
4. Nodes with zero in-degrees are added to the result as they are "safe."
5. Finally, sort the result.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjReverse[V];
        vector<int> indegree(V, 0);

        // Reverse edges
        for (int i = 0; i < V; i++) {
            for (auto it : adj[i]) {
                adjReverse[it].push_back(i);
                indegree[i]++;
            }
        }

        // Add terminal nodes (indegree 0) to the queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // Perform BFS
        vector<int> safeNodes;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (auto it : adjReverse[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Sort and return the result
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public List<Integer> eventualSafeNodes(int V, List<List<Integer>> adj) {
        List<List<Integer>> adjReverse = new ArrayList<>();
        int[] indegree = new int[V];

        // Initialize reverse adjacency list
        for (int i = 0; i < V; i++) {
            adjReverse.add(new ArrayList<>());
        }

        // Reverse edges and calculate in-degrees
        for (int i = 0; i < V; i++) {
            for (int neighbor : adj.get(i)) {
                adjReverse.get(neighbor).add(i);
                indegree[i]++;
            }
        }

        // Add terminal nodes (indegree 0) to the queue
        Queue<Integer> queue = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                queue.add(i);
            }
        }

        // Perform BFS
        List<Integer> safeNodes = new ArrayList<>();
        while (!queue.isEmpty()) {
            int node = queue.poll();
            safeNodes.add(node);

            for (int neighbor : adjReverse.get(node)) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    queue.add(neighbor);
                }
            }
        }

        // Sort and return the result
        Collections.sort(safeNodes);
        return safeNodes;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Reversing Edges:** \( O(V + E) \)
- **BFS Traversal:** \( O(V + E) \)

Overall: \( O(V + E) \)

### Space Complexity

- **Graph Representation:** \( O(V + E) \)
- **Auxiliary Structures (Queue, Indegree):** \( O(V) \)

Overall: \( O(V + E) \)

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile using a command like:

   ```bash
   g++ -std=c++17 -o output filename.cpp
   ```

3. Run the executable:

   ```bash
   ./output
   ```

### For Java

1. Save the code in a `.java` file.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
