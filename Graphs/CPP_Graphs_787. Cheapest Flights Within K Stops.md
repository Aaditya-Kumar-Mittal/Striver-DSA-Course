# Cheapest Flights Within K Stops

## Table of Contents

- [Cheapest Flights Within K Stops](#cheapest-flights-within-k-stops)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Breadth-First Search with Priority Queue (Modified Dijkstra)](#breadth-first-search-with-priority-queue-modified-dijkstra)
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

The objective of this problem is to determine the cheapest price for a flight from a source city to a destination city within at most \(k\) stops. The input is represented as a directed graph where nodes represent cities and edges represent flights with associated costs.

---

## Problem Description

### Input

- **`n`**: Number of cities.
- **`flights`**: A list where each element is a triplet `[from, to, price]` indicating a flight from city `from` to city `to` with a price of `price`.
- **`src`**: Source city.
- **`dst`**: Destination city.
- **`k`**: Maximum allowed stops.

### Output

- The minimum cost to travel from `src` to `dst` with at most `k` stops. Return `-1` if no such route exists.

---

## Examples

### Example 1

**Input:**

```plaintext
n = 4
flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
src = 0
dst = 3
k = 1
```

![Example 1](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-3drawio.png)

**Output:**

```plaintext
700
```

**Explanation:**  
The optimal path is `0 → 1 → 3` with a total cost of \(100 + 600 = 700\).

### Example 2

**Input:**

```plaintext
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0
dst = 2
k = 1
```

![Example 2](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-1drawio.png)
**Output:**

```plaintext
200
```

**Explanation:**  
The optimal path is `0 → 1 → 2` with a total cost of \(100 + 100 = 200\).

### Example 3

**Input:**

```plaintext
n = 3
flights = [[0,1,100],[1,2,100],[0,2,500]]
src = 0
dst = 2
k = 0
```

![Example 3](https://assets.leetcode.com/uploads/2022/03/18/cheapest-flights-within-k-stops-2drawio.png)

**Output:**

```plaintext
500
```

**Explanation:**  
The optimal path is `0 → 2` with a total cost of \(500\).

---

## Constraints

- \(1 \leq n \leq 100\)
- \(0 \leq \text{flights.length} \leq n \times (n-1) / 2\)
- Each flight is represented as `[from, to, price]`.
- \(1 \leq \text{price} \leq 10^4\)
- \(0 \leq \text{src}, \text{dst}, k < n\)
- \(src \neq dst\)

---

## Approach

### Breadth-First Search with Priority Queue (Modified Dijkstra)

1. **Graph Representation**:
   - Use an adjacency list to represent the graph.
   - Each node connects to its neighbors with a specific cost.

2. **Queue Initialization**:
   - Use a queue to store nodes with the format `(stops, currentNode, currentCost)`.
   - Start with the source node at cost \(0\) and \(0\) stops.

3. **Breadth-First Traversal**:
   - For the current node, process all its neighbors.
   - Calculate the total cost to reach the neighbor and update the cost if it’s cheaper.
   - Push the neighbor into the queue with an incremented stop count.

4. **Conditions**:
   - Ignore nodes if the stop count exceeds \(k\).
   - Return the minimum cost to the destination if found; otherwise, return \(-1\).

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create adjacency list
        vector<pair<int, int>> adj[n];
        for (auto flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        // Queue: {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        // Distance array to store the minimum cost to each node
        vector<int> distance(n, INT_MAX);
        distance[src] = 0;

        // BFS traversal
        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            if (stops > k) continue;

            for (auto neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int price = neighbor.second;

                if (cost + price < distance[nextNode] && stops <= k) {
                    distance[nextNode] = cost + price;
                    q.push({stops + 1, {nextNode, distance[nextNode]}});
                }
            }
        }

        return (distance[dst] == INT_MAX) ? -1 : distance[dst];
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        // Create adjacency list
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int[] flight : flights) {
            adj.computeIfAbsent(flight[0], x -> new ArrayList<>()).add(new int[]{flight[1], flight[2]});
        }

        // Queue: {stops, currentNode, currentCost}
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{0, src, 0});

        // Distance array to store the minimum cost to each node
        int[] distance = new int[n];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[src] = 0;

        // BFS traversal
        while (!q.isEmpty()) {
            int[] current = q.poll();
            int stops = current[0];
            int node = current[1];
            int cost = current[2];

            if (stops > k) continue;

            if (adj.containsKey(node)) {
                for (int[] neighbor : adj.get(node)) {
                    int nextNode = neighbor[0];
                    int price = neighbor[1];

                    if (cost + price < distance[nextNode] && stops <= k) {
                        distance[nextNode] = cost + price;
                        q.add(new int[]{stops + 1, nextNode, distance[nextNode]});
                    }
                }
            }
        }

        return distance[dst] == Integer.MAX_VALUE ? -1 : distance[dst];
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Construction:** \(O(f)\), where \(f\) is the number of flights.
  - Time Complexity of Dijkstra was O(E log V).
  - Since we are not using any priority queue, hence we can ignore log V.
  - E is basically number of edges = number of flights.
- **BFS Traversal:** \(O(k \cdot (n + f))\), as each node and edge can be processed at most \(k+1\) times.
- **Total:** \(O(k \cdot (n + f))\).

### Space Complexity

- **Graph Storage:** \(O(f)\).
- **Queue and Distance Array:** \(O(n)\).
- **Total:** \(O(f + n)\).

---

## How to Run the Code

### For C++

1. Copy the code into a `.cpp` file.
2. Compile using `g++ filename.cpp`.
3. Run the executable and provide input.

### For Java

1. Copy the code into a `.java` file.
2. Compile using `javac filename.java`.
3. Run the program using `java filename`.
