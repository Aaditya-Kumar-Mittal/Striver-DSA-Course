# Number of Provinces

<!-- markdownlint-disable MD052 -->
<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Number of Provinces](#number-of-provinces)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach 1: Depth First Search (DFS)](#approach-1-depth-first-search-dfs)
    - [Intuition](#intuition)
    - [Algorithm](#algorithm)
    - [Implementation](#implementation)
    - [Complexity Analysis](#complexity-analysis)
  - [Approach 2: Breadth First Search (BFS)](#approach-2-breadth-first-search-bfs)
    - [Intuition](#intuition-1)
    - [Algorithm](#algorithm-1)
    - [Implementation](#implementation-1)
    - [Complexity Analysis](#complexity-analysis-1)
  - [Approach 3: Union-Find](#approach-3-union-find)
    - [Intuition](#intuition-2)
    - [Algorithm](#algorithm-2)
    - [Implementation](#implementation-2)
    - [Complexity Analysis](#complexity-analysis-2)

---

## Introduction

We are given `n` cities, represented as nodes in a graph, and their direct connections are represented by an `n x n` adjacency matrix `isConnected`. A "province" is defined as a group of directly or indirectly connected cities. The goal is to find the number of provinces, which corresponds to the number of connected components in the graph.

---

## Problem Description

### Examples

#### Example 1

**Input:**  

```plaintext
isConnected = [[1, 1, 0], [1, 1, 0], [0, 0, 1]]
```

**Output:**  

```plaintext
2
```

**Explanation:**  
There are two provinces:

1. Cities 0 and 1 are directly connected.
2. City 2 is isolated.

#### Example 2

**Input:**  

```plaintext
isConnected = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
```

**Output:**  

```plaintext
3
```

**Explanation:**  
Each city is isolated, forming three separate provinces.

### Constraints

- \( 1 \leq n \leq 200 \)
- \( isConnected[i][j] = 1 \) if there is a direct connection between cities \( i \) and \( j \), else \( isConnected[i][j] = 0 \).
- \( isConnected[i][i] = 1 \) (each city is connected to itself).
- \( isConnected[i][j] = isConnected[j][i] \) (undirected graph).

---

## Approach 1: Depth First Search (DFS)

### Intuition

Cities that belong to the same province are part of the same connected component in the graph. Using DFS, we can explore all nodes reachable from a given city. Whenever we encounter an unvisited node, it means we have found a new province.

### Algorithm

1. Initialize:
   - `n` as the number of cities.
   - A `visited` array to track visited nodes.
   - `numberOfComponents` to count the provinces, initialized to 0.
2. Iterate through each city `i`. If it hasn't been visited, start a DFS:
   - Mark city `i` and all its reachable cities as visited.
   - Increment `numberOfComponents` by 1.
3. Return `numberOfComponents`.

### Implementation

```python
def findCircleNum(isConnected):
    def dfs(node):
        visited[node] = True
        for neighbor in range(len(isConnected)):
            if isConnected[node][neighbor] == 1 and not visited[neighbor]:
                dfs(neighbor)

    n = len(isConnected)
    visited = [False] * n
    numberOfComponents = 0

    for i in range(n):
        if not visited[i]:
            numberOfComponents += 1
            dfs(i)
    
    return numberOfComponents
```

### Complexity Analysis

- **Time Complexity:** \( O(n^2) \)  
  - We iterate over the \( n \times n \) matrix once.
  - DFS visits each node and its neighbors, taking \( O(n) \) per node in the worst case.
- **Space Complexity:** \( O(n) \)  
  - The recursion stack for DFS can grow up to \( n \).
  - The `visited` array requires \( O(n) \) space.

---

## Approach 2: Breadth First Search (BFS)

### Intuition

Instead of exploring nodes recursively as in DFS, BFS uses a queue to explore nodes level by level. This approach is equally suitable for counting connected components in an undirected graph.

### Algorithm

1. Initialize:
   - `n` as the number of cities.
   - A `visited` array to track visited nodes.
   - `numberOfComponents` to count the provinces, initialized to 0.
2. Iterate through each city `i`. If it hasn't been visited, start a BFS:
   - Mark city `i` and all its reachable cities as visited.
   - Increment `numberOfComponents` by 1.
3. Return `numberOfComponents`.

### Implementation

```python
from collections import deque

def findCircleNum(isConnected):
    def bfs(node):
        queue = deque([node])
        while queue:
            current = queue.popleft()
            for neighbor in range(len(isConnected)):
                if isConnected[current][neighbor] == 1 and not visited[neighbor]:
                    visited[neighbor] = True
                    queue.append(neighbor)

    n = len(isConnected)
    visited = [False] * n
    numberOfComponents = 0

    for i in range(n):
        if not visited[i]:
            numberOfComponents += 1
            bfs(i)
    
    return numberOfComponents
```

### Complexity Analysis

- **Time Complexity:** \( O(n^2) \)  
  - Similar to DFS, each node and its neighbors are visited once.
- **Space Complexity:** \( O(n) \)  
  - The BFS queue can contain up to \( n \) nodes at a time.
  - The `visited` array requires \( O(n) \) space.

---

## Approach 3: Union-Find

### Intuition

Union-Find is a data structure that efficiently handles connected components. Initially, each city is its own component. As we process connections, we merge components using union operations. The number of remaining components is the number of provinces.

### Algorithm

1. Initialize:
   - A `parent` array where `parent[i]` represents the root of city \( i \).
   - A `rank` array to optimize the union operation.
   - `numberOfComponents` as \( n \).
2. Define helper functions:
   - `find(x)` to find the root of city \( x \) with path compression.
   - `union(x, y)` to merge two components if they have different roots.
3. Iterate through all connections in `isConnected`. For each connection, perform a union operation if the cities belong to different components.
4. Return `numberOfComponents`.

### Implementation

```python
class UnionFind:
    def __init__(self, size):
        self.parent = list(range(size))
        self.rank = [1] * size
        self.components = size

    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        rootX = self.find(x)
        rootY = self.find(y)
        if rootX != rootY:
            if self.rank[rootX] > self.rank[rootY]:
                self.parent[rootY] = rootX
            elif self.rank[rootX] < self.rank[rootY]:
                self.parent[rootX] = rootY
            else:
                self.parent[rootY] = rootX
                self.rank[rootX] += 1
            self.components -= 1

def findCircleNum(isConnected):
    n = len(isConnected)
    uf = UnionFind(n)

    for i in range(n):
        for j in range(i + 1, n):
            if isConnected[i][j] == 1:
                uf.union(i, j)
    
    return uf.components
```

### Complexity Analysis

- **Time Complexity:** \( O(n^2) \)  
  - Processing all connections in the \( n \times n \) matrix.
  - Union and find operations are nearly \( O(1) \) due to path compression.
- **Space Complexity:** \( O(n) \)  
  - The `parent` and `rank` arrays require \( O(n) \) space.

---

These approaches provide flexible options to solve the problem based on your requirements for recursion, iteration, or optimized data structures.
