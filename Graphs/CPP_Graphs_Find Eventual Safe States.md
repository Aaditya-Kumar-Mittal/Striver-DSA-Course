# Find Eventual Safe States

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Find Eventual Safe States](#find-eventual-safe-states)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Approach 1: Topological Sort Using Kahn's Algorithm](#approach-1-topological-sort-using-kahns-algorithm)
      - [Intuition](#intuition)
      - [Steps](#steps)
    - [Approach 2: Depth First Search](#approach-2-depth-first-search)
      - [Intuition](#intuition-1)
      - [Steps](#steps-1)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Python Implementation](#python-implementation)
      - [Topological Sort Solution](#topological-sort-solution)
      - [Depth First Search Solution](#depth-first-search-solution)
  - [Complexity Analysis](#complexity-analysis)
    - [Topological Sort Solution](#topological-sort-solution-1)
    - [Depth First Search Solution](#depth-first-search-solution-1)
  - [How to Run the Code](#how-to-run-the-code)
    - [For Python](#for-python)

---

## Introduction

The problem requires identifying **safe nodes** in a directed graph. A **safe node** is defined as a node where every path starting from it leads to a terminal node or another safe node. Terminal nodes are those with no outgoing edges.

We must return a sorted list of all the safe nodes.

---

## Problem Description

Given a directed graph with `n` nodes labeled from `0` to `n-1`, represented as a 2D array `graph` where `graph[i]` contains all nodes directly reachable from node `i`.

**Goal:** Return a list of all safe nodes sorted in ascending order.

### Examples

#### Example 1

**Input:**

```python
graph = [[1,2],[2,3],[5],[0],[5],[],[]]
```

**Output:**

```python
[2, 4, 5, 6]
```

#### Example 2

**Input:**

```python
graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
```

**Output:**

```python
[4]
```

### Constraints

- `n == graph.length`
- `1 <= n <= 10^4`
- `0 <= graph[i].length <= n`
- `0 <= graph[i][j] < n`
- The graph may have self-loops and cycles.

---

## Approach

### Approach 1: Topological Sort Using Kahn's Algorithm

#### Intuition

- Safe nodes are nodes where no outgoing path leads to a cycle.
- Reverse the graph edges to traverse from terminal nodes towards their predecessors.
- Use **Kahn's Algorithm** for topological sorting to identify cycles. Nodes that are not part of a cycle are safe.

#### Steps

1. Reverse the graph to create an adjacency list for incoming edges.
2. Track incoming edges for all nodes in an `indegree` array.
3. Initialize a queue with all terminal nodes (nodes with `indegree = 0`).
4. Perform BFS:
   - Mark dequeued nodes as safe.
   - Decrease the `indegree` of neighboring nodes.
   - Add nodes with `indegree = 0` to the queue.
5. Return the sorted list of safe nodes.

---

### Approach 2: Depth First Search

#### Intuition

- Use DFS to detect cycles. If a node is part of a cycle or leads to one, it is unsafe.
- Maintain a recursion stack (`inStack`) to detect back edges during traversal.
- A node is safe if all its outgoing paths lead to terminal or safe nodes.

#### Steps

1. Initialize two arrays: `visit` to track visited nodes and `inStack` to detect back edges.
2. Perform DFS for each unvisited node:
   - Mark the current node as visited and add it to the stack.
   - Recur for all neighbors:
     - If any neighbor is part of the stack, mark the current node as unsafe.
     - If a neighbor is already unsafe, stop further exploration.
   - If no cycles are found, mark the node as safe and remove it from the stack.
3. Return all nodes marked as safe in ascending order.

---

## Detailed Explanation of Code

### Python Implementation

#### Topological Sort Solution

```python
from collections import deque, defaultdict

def eventualSafeNodes(graph):
    n = len(graph)
    indegree = [0] * n
    reverse_graph = defaultdict(list)
    
    # Build the reverse graph and compute indegrees
    for node in range(n):
        for neighbor in graph[node]:
            reverse_graph[neighbor].append(node)
            indegree[node] += 1

    # Start with terminal nodes
    queue = deque([i for i in range(n) if indegree[i] == 0])
    safe = [False] * n

    # Perform BFS
    while queue:
        current = queue.popleft()
        safe[current] = True
        for neighbor in reverse_graph[current]:
            indegree[neighbor] -= 1
            if indegree[neighbor] == 0:
                queue.append(neighbor)

    # Return sorted list of safe nodes
    return [i for i in range(n) if safe[i]]
```

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indegree(n);
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (auto node : graph[i]) {
                adj[node].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        // Push all the nodes with indegree zero in the queue.
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<bool> safe(n);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;

            for (auto& neighbor : adj[node]) {
                // Delete the edge "node -> neighbor".
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        vector<int> safeNodes;
        for(int i = 0; i < n; i++) {
            if(safe[i]) {
                safeNodes.push_back(i);
            }
        }
        return safeNodes;
    }
};
```

#### Depth First Search Solution

```python
def eventualSafeNodesDFS(graph):
    n = len(graph)
    visit = [False] * n
    inStack = [False] * n
    safe = [False] * n

    def dfs(node):
        if inStack[node]:  # Found a cycle
            return True
        if visit[node]:  # Already processed
            return False
        
        visit[node] = inStack[node] = True
        for neighbor in graph[node]:
            if dfs(neighbor):  # If neighbor leads to cycle
                return True
        
        inStack[node] = False
        safe[node] = True
        return False

    for i in range(n):
        if not visit[i]:
            dfs(i)

    return [i for i in range(n) if safe[i]]
```

```cpp
class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visit, vector<bool>& inStack) {
        // If the node is already in the stack, we have a cycle.
        if (inStack[node]) {
            return true;
        }
        if (visit[node]) {
            return false;
        }
        // Mark the current node as visited and part of current recursion stack.
        visit[node] = true;
        inStack[node] = true;
        for (auto neighbor : adj[node]) {
            if (dfs(neighbor, adj, visit, inStack)) {
                return true;
            }
        }
        // Remove the node from the stack.
        inStack[node] = false;
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> visit(n), inStack(n);

        for (int i = 0; i < n; i++) {
            dfs(i, graph, visit, inStack);
        }

        vector<int> safeNodes;
        for (int i = 0; i < n; i++) {
            if (!inStack[i]) {
                safeNodes.push_back(i);
            }
        }

        return safeNodes;
    }
};
```

---

## Complexity Analysis

### Topological Sort Solution

- **Time Complexity:** `O(m + n)`
  - `O(m)` to build the reversed graph.
  - `O(n)` for BFS traversal.
- **Space Complexity:** `O(m + n)`
  - `O(m)` for reversed graph adjacency list.
  - `O(n)` for `indegree` array and queue.

### Depth First Search Solution

- **Time Complexity:** `O(m + n)`
  - `O(n)` for visiting nodes.
  - `O(m)` for traversing all edges.
- **Space Complexity:** `O(n)`
  - `O(n)` for recursion stack.
  - `O(n)` for visited and inStack arrays.

---

## How to Run the Code

### For Python

1. Save the code in a file, e.g., `find_safe_states.py`.
2. Run the script in Python 3.x:

   ```bash
   python3 find_safe_states.py
   ```

3. Input the graph as a 2D array and call the desired function:

   ```python
   graph = [[1, 2], [2, 3], [5], [0], [5], [], []]
   print(eventualSafeNodes(graph))
   ```

---
