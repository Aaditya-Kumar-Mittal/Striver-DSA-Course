# Number of Ways to Arrive at Destination

## Table of Contents

- [Number of Ways to Arrive at Destination](#number-of-ways-to-arrive-at-destination)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Graph Representation](#graph-representation)
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
    - [Solution - 1](#solution---1)

---

## Introduction

The goal is to find the number of ways to travel from intersection `0` to intersection `n-1` using the shortest possible time. The problem can be solved using **Dijkstra's algorithm** with a slight modification to count the number of ways paths achieve the shortest time.

---

## Problem Description

### Input

- **`n`**: An integer representing the number of intersections (\(0\) to \(n-1\)).
- **`roads`**: A 2D array where each row represents a road between intersections, with the format `[u, v, time]`, meaning there is a road between `u` and `v` taking `time` minutes.

### Output

- The number of ways to reach intersection \(n-1\) from intersection \(0\) in the shortest possible time. The result should be returned modulo \(10^9 + 7\).

---

## Examples

### Example 1

**Input:**

```plaintext
n = 7
roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
```

**Output:**

```plaintext
4
```

**Explanation:**

- The shortest time to go from intersection \(0\) to \(6\) is \(7\) minutes.
- The four ways to achieve this are:
  1. \(0 \to 6\)
  2. \(0 \to 4 \to 6\)
  3. \(0 \to 1 \to 2 \to 5 \to 6\)
  4. \(0 \to 1 \to 3 \to 5 \to 6\)

### Example 2

**Input:**

```plaintext
n = 2
roads = [[1,0,10]]
```

**Output:**

```plaintext
1
```

**Explanation:**

- There is only one road, so there is only one way to travel from \(0\) to \(1\).

---

## Constraints

- \(1 \leq n \leq 200\)
- \(n - 1 \leq \text{roads.length} \leq \frac{n(n-1)}{2}\)
- \(\text{roads}[i].length = 3\)
- \(0 \leq u_i, v_i \leq n-1\)
- \(1 \leq \text{time}_i \leq 10^9\)
- \(u_i \neq v_i\)
- There is at most one road between any two intersections.
- You can reach any intersection from any other intersection.

---

## Approach

### Graph Representation

- Represent the intersections and roads using an **adjacency list**, where each node points to its neighbors along with the weight (travel time) of the edges.

### Dijkstra's Algorithm

1. **Initialize Data Structures**:
   - A **priority queue** to process nodes based on the shortest distance.
   - A **distance array** to store the minimum time to reach each node.
   - A **ways array** to store the number of ways to achieve the shortest time for each node.

2. **Algorithm**:
   - Start at node \(0\) with distance \(0\).
   - For each node processed, update its neighbors:
     - If a shorter path is found, update the neighbor's distance and inherit the number of ways from the current node.
     - If another path with the same shortest distance is found, add the number of ways from the current node to the neighbor's count.

3. **Output**:
   - The number of ways to reach node \(n-1\) modulo \(10^9 + 7\).

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // Modulo value as per problem statement
        int mod = 1e9 + 7;

        // Adjacency list representation
        vector<vector<pair<int, int>>> adj(n);
        for (auto& road : roads) {
            adj[road[0]].emplace_back(road[1], road[2]);
            adj[road[1]].emplace_back(road[0], road[2]);
        }

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        // Distance and ways arrays
        vector<long long> distance(n, LLONG_MAX);
        vector<int> ways(n, 0);

        // Initialization
        distance[0] = 0;
        ways[0] = 1;
        pq.push({0, 0}); // {current_distance, node}

        // Dijkstra's algorithm
        while (!pq.empty()) {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (dist > distance[node]) continue;

            for (auto& neighbor : adj[node]) {
                int adjNode = neighbor.first;
                long long adjWeight = neighbor.second;

                // Shorter path found
                if (dist + adjWeight < distance[adjNode]) {
                    distance[adjNode] = dist + adjWeight;
                    pq.push({distance[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                }
                // Another way with the same shortest distance
                else if (dist + adjWeight == distance[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};

// Driver Code
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> roads(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        cin >> roads[i][0] >> roads[i][1] >> roads[i][2];
    }
    Solution obj;
    cout << obj.countPaths(n, roads) << endl;
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int countPaths(int n, int[][] roads) {
        int mod = 1_000_000_007;

        // Build graph
        List<int[]>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] road : roads) {
            graph[road[0]].add(new int[]{road[1], road[2]});
            graph[road[1]].add(new int[]{road[0], road[2]});
        }

        // Priority queue and data structures
        PriorityQueue<long[]> pq = new PriorityQueue<>(Comparator.comparingLong(a -> a[0]));
        long[] dist = new long[n];
        int[] ways = new int[n];
        Arrays.fill(dist, Long.MAX_VALUE);
        dist[0] = 0;
        ways[0] = 1;

        pq.add(new long[]{0, 0}); // {distance, node}

        while (!pq.isEmpty()) {
            long[] curr = pq.poll();
            long d = curr[0];
            int node = (int) curr[1];

            if (d > dist[node]) continue;

            for (int[] neighbor : graph[node]) {
                int adjNode = neighbor[0];
                long weight = neighbor[1];

                if (d + weight < dist[adjNode]) {
                    dist[adjNode] = d + weight;
                    pq.add(new long[]{dist[adjNode], adjNode});
                    ways[adjNode] = ways[node];
                } else if (d + weight == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Building the Graph**: \(O(E)\), where \(E\) is the number of edges.
- **Dijkstra's Algorithm**: \(O((E + V) \cdot \log V)\), where \(V\) is the number of nodes.

### Space Complexity

- **Graph Storage**: \(O(E)\).
- **Distance and Ways Arrays**: \(O(V)\).
- **Priority Queue**: \(O(V)\).

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

### Solution - 1

```cpp
#define ll long long
#define pll pair<ll, ll>
class Solution {
public:
    int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>> graph(n);
        for(auto& road: roads) {
            ll u = road[0], v = road[1], time = road[2];
            graph[u].push_back({v, time});
            graph[v].push_back({u, time});
        }
        return dijkstra(graph, n, 0);
    }
    int dijkstra(const vector<vector<pll>>& graph, int n, int src) {
        vector<ll> dist(n, LONG_MAX);
        vector<ll> ways(n);
        ways[src] = 1;
        dist[src] = 0;
        priority_queue<pll, vector<pll>, greater<>> minHeap;
        minHeap.push({0, 0}); // dist, src
        while (!minHeap.empty()) {
            auto[d, u] = minHeap.top(); minHeap.pop();
            if (d > dist[u]) continue; // Skip if `d` is not updated to latest version!
            for(auto [v, time] : graph[u]) {
                if (dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    minHeap.push({dist[v], v});
                } else if (dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % MOD;
                }
            }
        }
        return ways[n-1];
    }
};
```

- Time: **O(M*logN + N), where M <= N*(N-1)/2** is number of roads, N <= 200 is number of intersections.
- Space: **O(N + M)**
