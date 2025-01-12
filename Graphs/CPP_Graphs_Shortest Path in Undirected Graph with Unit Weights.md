# Shortest Path in Undirected Graph with Unit Weights

## Table of Contents

- [Shortest Path in Undirected Graph with Unit Weights](#shortest-path-in-undirected-graph-with-unit-weights)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Expected Output](#expected-output)
    - [Definitions](#definitions)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
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

The **Shortest Path in Undirected Graph with Unit Weights** problem is a graph traversal problem where each edge in the graph has the same unit weight (1). You are given an undirected graph represented as an adjacency list, and the goal is to find the shortest path from a source vertex to all other vertices.

Since the graph has unit weights, a simple **Breadth-First Search (BFS)** is an efficient way to compute the shortest paths from the source. If any vertex is unreachable, it should be marked with `-1`.

---

## Problem Description

You are given:

- `adj`: A 2D list of integers representing the adjacency list of the graph. Each `adj[i]` contains the vertices adjacent to vertex `i`.
- `src`: The source vertex from which we need to calculate the shortest paths.

### Expected Output

- A list of shortest distances from the source vertex to all other vertices. If a vertex is unreachable, the distance for that vertex should be `-1`.

### Definitions

- **Unit Weight**: All edges in the graph have a weight of 1.
- **Undirected Graph**: The edges are bidirectional.

---

### Examples

#### Example 1

**Input:**

```text
adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
```

**Output:**

```text
0 1 2 1 2 3 3 4 4
```

**Explanation:**

- The shortest path from 0 to 1 is `0 -> 1` with distance 1.
- The shortest path from 0 to 2 is `0 -> 1 -> 2` with distance 2.
- The shortest path from 0 to 3 is `0 -> 3` with distance 1.
- And so on.

---

#### Example 2

**Input:**

```text
adj[][]= [[3], [3], [0, 1]], src=3
```

**Output:**

```text
1 1 -1 0
```

**Explanation:**

- The shortest path from 3 to 0 is `3 -> 0` with distance 1.
- The shortest path from 3 to 1 is `3 -> 1` with distance 1.
- The vertex 2 is unreachable from vertex 3, so the output is `-1` for vertex 2.

---

#### Example 3

**Input:**

```text
adj[][]= [[], [], [], [4], [3], [], []], src=1
```

**Output:**

```text
-1 0 -1 -1 -1 -1 -1
```

**Explanation:**

- Vertex 1 is the source, so the distance to itself is 0.
- All other vertices are unreachable from vertex 1, so the distance for all of them is `-1`.

---

### Constraints

- \( 1 \leq \text{adj.size()} \leq 1000 \)
- \( 0 \leq \text{edges} \leq \text{adj.size()} - 1 \)

---

## Approach

To solve the problem efficiently, we can use **Breadth-First Search (BFS)** since the graph has unit edge weights. BFS explores all vertices at the current level before moving to the next level, ensuring the shortest path is found.

### Steps

1. **Initialization**:
   - Create a distance array initialized to `INT_MAX` (or a large number). Set the source vertex distance to 0.
   - Use a queue to perform BFS.

2. **BFS Traversal**:
   - Dequeue a vertex and explore its neighbors.
   - If a neighbor has not been visited (distance is still `INT_MAX`), update its distance and enqueue it.

3. **Final Adjustments**:
   - After BFS, if any vertex still has a distance of `INT_MAX`, it means that vertex is unreachable from the source. Set its distance to `-1`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int N = adj.size(); // Number of nodes
        
        // Distance vector initialized to INT_MAX
        vector<int> distance(N, INT_MAX);
        distance[src] = 0;
        
        // BFS using a queue
        queue<int> q;
        q.push(src);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Explore neighbors of the current node
            for (auto neighbor : adj[node]) {
                if (distance[node] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[node] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // Prepare the answer vector
        vector<int> ans(N, -1);
        for (int i = 0; i < N; i++) {
            if (distance[i] != INT_MAX) {
                ans[i] = distance[i];
            }
        }
        
        return ans;
    }
};
```

### Java Implementation

```java
import java.util.*;

class Solution {
    // Function to find the shortest path from source to all other nodes
    public int[] shortestPath(List<List<Integer>> adj, int src) {
        int N = adj.size(); // Number of nodes
        
        // Distance array initialized to Integer.MAX_VALUE
        int[] distance = new int[N];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[src] = 0;
        
        // BFS using a queue
        Queue<Integer> q = new LinkedList<>();
        q.offer(src);
        
        while (!q.isEmpty()) {
            int node = q.poll();
            
            // Explore neighbors of the current node
            for (int neighbor : adj.get(node)) {
                if (distance[node] + 1 < distance[neighbor]) {
                    distance[neighbor] = distance[node] + 1;
                    q.offer(neighbor);
                }
            }
        }
        
        // Prepare the answer array
        for (int i = 0; i < N; i++) {
            if (distance[i] == Integer.MAX_VALUE) {
                distance[i] = -1;
            }
        }
        
        return distance;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Traversal (BFS):** \( O(V + E) \), where \( V \) is the number of vertices and \( E \) is the number of edges.
  - BFS visits each vertex and edge at most once.
- **Overall:** \( O(V + E) \)

### Space Complexity

- **Queue and Distance Array:** \( O(V) \) for the BFS queue and distance array.
- **Graph Representation:** \( O(V + E) \) for the adjacency list.

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
