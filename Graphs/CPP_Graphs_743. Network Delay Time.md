# Network Delay Time

## Table of Contents

- [Network Delay Time](#network-delay-time)
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
    - [Dijkstra's Algorithm](#dijkstras-algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Using Bellman - Ford Algorithm](#using-bellman---ford-algorithm)
    - [Floyd–Warshall Algorithm](#floydwarshall-algorithm)

---

## Introduction

The objective of this problem is to determine the minimum time it takes for all nodes in a network to receive a signal from a given source node. If any node is unreachable, return \(-1\). The input is represented as a directed weighted graph.

---

## Problem Description

### Input

- **`times`**: A list of edges where each element is \((u, v, w)\), indicating a directed edge from node \(u\) to node \(v\) with weight \(w\).
- **`n`**: The number of nodes, labeled from \(1\) to \(n\).
- **`k`**: The source node where the signal starts.

### Output

- The minimum time for all nodes to receive the signal. If any node is unreachable, return \(-1\).

---

## Examples

### Example 1

**Input:**

```plaintext
times = [[2,1,1],[2,3,1],[3,4,1]]
n = 4
k = 2
```

**Output:**

```plaintext
2
```

**Explanation:**  
The signal starts at node \(2\). The time to reach all nodes is:

- Node \(1\): \(2 \rightarrow 1\), time \(1\).
- Node \(3\): \(2 \rightarrow 3\), time \(1\).
- Node \(4\): \(2 \rightarrow 3 \rightarrow 4\), time \(2\).

The maximum time to reach any node is \(2\).

### Example 2

**Input:**

```plaintext
times = [[1,2,1]]
n = 2
k = 1
```

**Output:**

```plaintext
1
```

**Explanation:**  
The signal starts at node \(1\). The time to reach all nodes is:

- Node \(2\): \(1 \rightarrow 2\), time \(1\).

The maximum time to reach any node is \(1\).

### Example 3

**Input:**

```plaintext
times = [[1,2,1]]
n = 2
k = 2
```

**Output:**

```plaintext
-1
```

**Explanation:**  
The signal starts at node \(2\). Node \(1\) is unreachable, so the result is \(-1\).

---

## Constraints

- \(1 \leq k \leq n \leq 100\)
- \(1 \leq \text{times.length} \leq 6000\)
- Each edge is represented as \((u, v, w)\).
- \(1 \leq u, v \leq n\)
- \(u \neq v\)
- \(0 \leq w \leq 100\)
- All edges \((u, v)\) are unique.

---

## Approach

### Dijkstra's Algorithm

1. **Graph Representation**:
   - Use an adjacency list to represent the graph.
   - Each node connects to its neighbors with a specific weight.

2. **Priority Queue Initialization**:
   - Use a min-heap (priority queue) to store the nodes with the format \((time, node)\).
   - Start with the source node \(k\) at time \(0\).

3. **Relaxation**:
   - For the current node, process all its neighbors.
   - Update the minimum time to reach each neighbor if a shorter path is found.
   - Push the neighbor into the priority queue with the updated time.

4. **Final Result**:
   - Calculate the maximum time among all reachable nodes.
   - If any node is unreachable, return \(-1\).

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create adjacency list
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        // Min-heap for Dijkstra's algorithm: {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        vector<int> signalTime(n + 1, INT_MAX);

        // Initialize the source node
        signalTime[k] = 0;
        pq.push({0, k});

        // Dijkstra's algorithm
        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                int weight = neighbor.second;

                if (time + weight < signalTime[adjNode]) {
                    signalTime[adjNode] = time + weight;
                    pq.push({signalTime[adjNode], adjNode});
                }
            }
        }

        // Find the maximum time to reach any node
        int maxTime = *max_element(signalTime.begin() + 1, signalTime.end());
        return maxTime == INT_MAX ? -1 : maxTime;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        // Create adjacency list
        Map<Integer, List<int[]>> adj = new HashMap<>();
        for (int[] time : times) {
            adj.computeIfAbsent(time[0], x -> new ArrayList<>()).add(new int[]{time[1], time[2]});
        }

        // Min-heap for Dijkstra's algorithm: {time, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        int[] signalTime = new int[n + 1];
        Arrays.fill(signalTime, Integer.MAX_VALUE);

        // Initialize the source node
        signalTime[k] = 0;
        pq.add(new int[]{0, k});

        // Dijkstra's algorithm
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int time = current[0];
            int node = current[1];

            if (!adj.containsKey(node)) continue;

            for (int[] neighbor : adj.get(node)) {
                int adjNode = neighbor[0];
                int weight = neighbor[1];

                if (time + weight < signalTime[adjNode]) {
                    signalTime[adjNode] = time + weight;
                    pq.add(new int[]{signalTime[adjNode], adjNode});
                }
            }
        }

        // Find the maximum time to reach any node
        int maxTime = Arrays.stream(signalTime).skip(1).max().getAsInt();
        return maxTime == Integer.MAX_VALUE ? -1 : maxTime;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Construction:** \(O(\text{times.length})\).
- **Dijkstra’s Algorithm:** \(O((n + \text{times.length}) \cdot \log(n))\), as each node and edge is processed once.
- **Total:** \(O((n + \text{times.length}) \cdot \log(n))\).

### Space Complexity

- **Graph Storage:** \(O(\text{times.length})\).
- **Priority Queue and Signal Time Array:** \(O(n)\).
- **Total:** \(O(n + \text{times.length})\).

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

## Other Solutions

### Using Bellman - Ford Algorithm

- Time complexity: O(N*E), Space complexity: O(N)

```cpp
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<int> dist(N + 1, INT_MAX);
        dist[K] = 0;
        for (int i = 0; i < N; i++) {
            for (vector<int> e : times) {
                int u = e[0], v = e[1], w = e[2];
                if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        int maxwait = 0;
        for (int i = 1; i <= N; i++)
            maxwait = max(maxwait, dist[i]);
        return maxwait == INT_MAX ? -1 : maxwait;
    }
};
```

```java
public int networkDelayTime_BF(int[][] times, int N, int K) {
    double[] disTo = new double[N];
    Arrays.fill(disTo, Double.POSITIVE_INFINITY);
    disTo[K - 1] = 0;
    for (int i = 1; i < N; i++) {
        for (int[] edge : times) {
            int u = edge[0] - 1, v = edge[1] - 1, w = edge[2];
            disTo[v] = Math.min(disTo[v], disTo[u] + w);
        }
    }
    double res = Double.MIN_VALUE;
    for (double i: disTo) {
        res = Math.max(i, res);
    }
    return res == Double.POSITIVE_INFINITY ? -1 : (int) res;
}
```

### Floyd–Warshall Algorithm

- Time complexity: O(N^3), Space complexity: O(N^2)
  
```java
public int networkDelayTime_FW(int[][] times, int N, int K) {
    double[][] disTo = new double[N][N];
    for (int i = 0; i < N; i++) {
        Arrays.fill(disTo[i], Double.POSITIVE_INFINITY);
    }
    for (int i = 0; i < N; i++) {
        disTo[i][i] = 0;
    }
    for (int[] edge: times) {
        disTo[edge[0] - 1][edge[1] - 1] = edge[2];
    }
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (disTo[i][j] > disTo[i][k] + disTo[k][j])
                    disTo[i][j] = disTo[i][k] + disTo[k][j];
            }
        }
    }
    double max = Double.MIN_VALUE;
    for (int i = 0; i < N; i++) {
        if (disTo[K - 1][i] == Double.POSITIVE_INFINITY) return -1;
        max = Math.max(max, disTo[K - 1][i]);
    }
    return (int) max;
}
```
