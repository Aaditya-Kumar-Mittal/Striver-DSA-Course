# Find the City With the Smallest Number of Neighbors at a Threshold Distance

<!-- markdownlint-disable MD052 -->
<!-- markdownlint-disable MD024  -->

## Table of Contents

- [Find the City With the Smallest Number of Neighbors at a Threshold Distance](#find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance)
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
    - [Algorithm](#algorithm)
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
    - [Java Multi-Solution](#java-multi-solution)
    - [Approach 1: Dijkstra Algorithm](#approach-1-dijkstra-algorithm)
      - [Intuition](#intuition)
      - [Steps](#steps)
      - [Algorithm](#algorithm-1)
        - [Steps to Solve the Problem](#steps-to-solve-the-problem)
      - [Code Implementation (C++)](#code-implementation-c)
      - [Complexity Analysis](#complexity-analysis-1)
        - [Time Complexity](#time-complexity-1)
        - [Space Complexity](#space-complexity-1)
    - [Approach 2: Bellman-Ford Algorithm](#approach-2-bellman-ford-algorithm)
      - [**Intuition**](#intuition-1)
      - [**Algorithm**](#algorithm-2)
      - [**Functions**](#functions)
      - [**Implementation**](#implementation)
      - [**Complexity Analysis**](#complexity-analysis-2)
    - [Approach 3: Shortest Path First Algorithm (SPFA)](#approach-3-shortest-path-first-algorithm-spfa)
      - [**Intuition**](#intuition-2)
      - [**Algorithm**](#algorithm-3)
      - [**Implementation**](#implementation-1)
      - [**Complexity Analysis**](#complexity-analysis-3)
      - [**Key Takeaways**](#key-takeaways)
    - [Approach 4: Floyd-Warshall Algorithm](#approach-4-floyd-warshall-algorithm)
      - [**Intuition**](#intuition-3)
      - [**Advantages**](#advantages)
      - [**Algorithm**](#algorithm-4)
      - [**Implementation**](#implementation-2)
      - [**Complexity Analysis**](#complexity-analysis-4)
      - [**Advantages and Limitations**](#advantages-and-limitations)

---

## Introduction

Given a graph represented as an adjacency list of edges, this problem requires finding the city with the **smallest number of reachable neighboring cities** such that the distance to any reachable city is at most a given `distanceThreshold`. If there are multiple cities satisfying the condition, the city with the **largest index** among them is returned. The problem uses the **Floyd-Warshall Algorithm** to compute shortest paths between all pairs of cities.

---

## Problem Description

### Input

1. An integer `n` representing the number of cities, numbered from `0` to `n-1`.
2. A 2D list of `edges`, where each `edges[i] = [fromi, toi, weighti]` denotes a bidirectional edge with weight `weighti` between cities `fromi` and `toi`.
3. An integer `distanceThreshold` specifying the maximum distance to consider when determining reachable neighboring cities.

### Output

- The city with the smallest number of reachable neighboring cities. If there is a tie, return the city with the largest index.

---

## Examples

### Example 1

**Input:**

```plaintext
n = 4
edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]]
distanceThreshold = 4
```

**Output:**

```plaintext
3
```

**Explanation:**

- Reachable cities for each city:
  - City 0: [City 1, City 2]
  - City 1: [City 0, City 2, City 3]
  - City 2: [City 0, City 1, City 3]
  - City 3: [City 1, City 2]
- Cities 0 and 3 have 2 neighboring cities each, but city 3 has the largest index.

---

### Example 2

**Input:**

```plaintext
n = 5
edges = [[0, 1, 2], [0, 4, 8], [1, 2, 3], [1, 4, 2], [2, 3, 1], [3, 4, 1]]
distanceThreshold = 2
```

**Output:**

```plaintext
0
```

**Explanation:**

- Reachable cities for each city:
  - City 0: [City 1]
  - City 1: [City 0, City 4]
  - City 2: [City 3, City 4]
  - City 3: [City 2, City 4]
  - City 4: [City 1, City 2, City 3]
- City 0 has only 1 neighboring city and satisfies the condition.

---

### Constraints

- \(2 \leq n \leq 100\)
- \(1 \leq \text{edges.length} \leq n \cdot (n - 1) / 2\)
- Each `edges[i]` contains exactly 3 integers: `[fromi, toi, weighti]`.
- \(0 \leq \text{fromi}, \text{toi} < n\)
- \(1 \leq \text{weighti}, \text{distanceThreshold} \leq 10^4\)
- All pairs `(fromi, toi)` are distinct.

---

## Approach

### Algorithm

1. **Initialize the Distance Matrix**:
   - Create an \(n \times n\) matrix, `distance`, and set all values to \(+\infty\) (or `INT_MAX`).
   - For each edge, update the matrix with the edge's weight for both directions.
   - Set `distance[i][i] = 0` for all \(i\).

2. **Run Floyd-Warshall Algorithm**:
   - For every intermediate city \(k\), update the shortest paths between all pairs \(i, j\) using:
     \[
     \text{distance}[i][j] = \min(\text{distance}[i][j], \text{distance}[i][k] + \text{distance}[k][j])
     \]

3. **Count Reachable Neighbors**:
   - For each city, count the number of neighboring cities reachable within the `distanceThreshold`.

4. **Find the Desired City**:
   - Track the city with the smallest count of reachable neighbors. In case of a tie, choose the city with the largest index.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix
        vector<vector<int>> distance(n, vector<int>(n, INT_MAX));
        for (auto edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }

        // Step 2: Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX) {
                        distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }

        // Step 3: Find the city with the smallest reachable neighbors
        int cityNumber = -1, minReachable = n + 1;
        for (int city = 0; city < n; city++) {
            int reachable = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (distance[city][adjCity] <= distanceThreshold) {
                    reachable++;
                }
            }
            if (reachable < minReachable || (reachable == minReachable && city > cityNumber)) {
                minReachable = reachable;
                cityNumber = city;
            }
        }

        return cityNumber;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        // Step 1: Initialize the distance matrix
        int[][] distance = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(distance[i], Integer.MAX_VALUE);
            distance[i][i] = 0;
        }
        for (int[] edge : edges) {
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }

        // Step 2: Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (distance[i][k] != Integer.MAX_VALUE && distance[k][j] != Integer.MAX_VALUE) {
                        distance[i][j] = Math.min(distance[i][j], distance[i][k] + distance[k][j]);
                    }
                }
            }
        }

        // Step 3: Find the city with the smallest reachable neighbors
        int cityNumber = -1, minReachable = n + 1;
        for (int city = 0; city < n; city++) {
            int reachable = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
                if (distance[city][adjCity] <= distanceThreshold) {
                    reachable++;
                }
            }
            if (reachable < minReachable || (reachable == minReachable && city > cityNumber)) {
                minReachable = reachable;
                cityNumber = city;
            }
        }

        return cityNumber;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Floyd-Warshall Algorithm**: \(O(n^3)\), where \(n\) is the number of cities.
- **Counting Reachable Cities**: \(O(n^2)\).
- **Overall**: \(O(n^3)\).

### Space Complexity

- **Distance Matrix**: \(O(n^2)\).
- **Overall**: \(O(n^2)\).

---

## How to Run the Code

### For C++

1. Save the code to a `.cpp` file.
2. Compile using `g++ filename.cpp`.
3. Run the compiled executable and provide input as specified.

### For Java

1. Save the code to a `.java` file.
2. Compile using `javac filename.java`.
3. Run the program using `java filename`.

## Other Solutions

### Java Multi-Solution

```java
class Solution {
    public int findTheCity(int n, int[][] edges, int distanceThreshold) {
        int INF = (int) 1e9 + 7;
        List<int[]>[] adj = new List[n];
        int[][] dist = new int[n][n];
        for (int i = 0; i < n; i++) {
            Arrays.fill(dist[i], INF);
            dist[i][i] = 0;
        }
        for (int i = 0; i < n; i++) {adj[i] = new ArrayList<>();}
        for (int[] e : edges) {
            int u = e[0];
            int v = e[1];
            int d = e[2];
            
            adj[u].add(new int[]{v, d});
            adj[v].add(new int[]{u, d});
            // dist[u][v] = d;
            // dist[v][u] = d;
        }
        
        // floyd(n, adj, dist);
        for (int i = 0; i < n; i++) {
            // dijkstra(n, adj, dist[i], i);
            // bellman(n, edges, dist[i], i);
            spfa(n, adj, dist[i], i);
        }
        
        int minCity = -1;
        int minCount = n;
        
        for (int i = 0; i < n; i++) {
            int curCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {continue;}
                if (dist[i][j] <= distanceThreshold) {curCount++;}
            }
            if (curCount <= minCount) {
                minCount = curCount;
                minCity = i;
            }
        }
        
        return minCity;
    }
    
    void spfa(int n, List<int[]>[] adj, int[] dist, int src) {
        Deque<Integer> q = new ArrayDeque<>();
        int[] updateTimes = new int[n];
        q.add(src);
        
        while (!q.isEmpty()) {
            int u = q.removeFirst();
            for (int[] next : adj[u]) {
                int v = next[0];
                int duv = next[1];
                
                if (dist[v] > dist[u] + duv) {
                    dist[v] = dist[u] + duv;
                    updateTimes[v]++;
                    q.add(v);
                    if (updateTimes[v] > n) {System.out.println("wrong");}
                }
            }
        }
    }
    
    void bellman(int n, int[][] edges, int[] dist, int src) {
        for (int k = 1; k < n; k++) {
            for (int[] e : edges) {
                int u = e[0];
                int v = e[1];
                int duv = e[2];
                
                if (dist[u] > dist[v] + duv) {
                    dist[u] = dist[v] + duv;
                }
                
                if (dist[v] > dist[u] + duv) {
                    dist[v] = dist[u] + duv;
                }
            }
        }
    }
    
    void dijkstra(int n, List<int[]>[] adj, int[] dist, int src) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> (a[1] - b[1]));
        pq.add(new int[]{src, 0});
        while (!pq.isEmpty()) {
            int[] cur = pq.remove();
            int u = cur[0];
            int du = cur[1];
            if (du > dist[u]) {continue;}
            
            for (int[] nb : adj[u]) {
                int v = nb[0];
                int duv = nb[1];
                if (dist[v] > du + duv) {
                    dist[v] = du + duv;
                    pq.add(new int[]{v, dist[v]});
                }
            }
        }
    }
    
    void floyd(int n, List<int[]>[] adj, int[][] dist) {
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        } 
    }
}
```

The time complexity of this Java Multi-Solution is

- Floyd-Warshall Algorithm: \(O(n^3)\), where \(n\) is the number of cities.
- Counting Reachable Cities: \(O(n^2)\).
- Bellman-Ford Algorithm: \(O(n^2)\), where \(n\) is the number of cities.
- Dijkstra's Algorithm: \(O(n^2)\), where \(n\) is the number of cities.
- SPFA Algorithm: \(O(n^2)\), where \(n\) is the number of cities.
- Overall: \(O(n^3)\).

- Floyd: 14ms
- Dijkstra: 32ms
- SPFA: 64ms
- Bellman: 251ms

---

### Approach 1: Dijkstra Algorithm

#### Intuition

Dijkstra's algorithm is a graph search algorithm that finds the shortest paths between nodes in a graph. It is particularly effective for finding the shortest path from a single source node to all other nodes in graphs with non-negative edge weights.

The algorithm uses a **greedy strategy**, maintaining a set of vertices whose shortest distance from the source is known. At each step, it selects the vertex with the **minimum distance value** from the set of unvisited vertices.

- **Initialization**: Distances to all vertices are initialized as infinity, except for the source vertex, which is set to zero.
- **Priority Queue**: A priority queue is used to efficiently select the vertex with the minimum distance in each iteration. This ensures that the most promising paths are processed first, saving unnecessary computations.
- **Relaxation**: For each neighbor of the current vertex, the algorithm calculates the distance through the current vertex. If this calculated distance is less than the previously known distance to that neighbor, the distance is updated (a process called relaxation). Dijkstra's algorithm performs relaxation efficiently by always processing the most promising vertex next.

After computing all shortest paths, reachable cities are counted, and the city with the fewest reachable cities within the given distance threshold is selected.

#### Steps

1. **Initialization**: Set the distance to the source city as zero and all others as infinity. Use a priority queue to process cities based on their shortest distance.
2. **Relaxation**: Extract the city with the smallest distance from the priority queue. Update the distances to its neighboring cities and add them back to the queue if their distances are updated.
3. **Result Computation**: Compute the shortest paths from each city. Count the number of reachable cities within the distance threshold. Choose the city with the fewest reachable cities or, in case of ties, the city with the greatest number.
4. **Return**: Return the index of the chosen city.

#### Algorithm

##### Steps to Solve the Problem

1. **Graph Representation**:
   - Create an adjacency list `adjacencyList` to store the graph.
   - Create a 2D array `shortestPathMatrix` with dimensions `n x n` to store shortest path distances between all pairs of cities.

2. **Initialization**:
   - Set all distances in `shortestPathMatrix[i]` to the maximum integer value (`INT_MAX`).
   - Set the distance from city `i` to itself (`shortestPathMatrix[i][i]`) to `0`.
   - Initialize `adjacencyList[i]` as an empty list.

3. **Populate Adjacency List**:
   - Iterate through each edge in `edges`:
     - Extract `start`, `end`, and `weight` from each edge.
     - Add `(end, weight)` to `adjacencyList[start]`.
     - Add `(start, weight)` to `adjacencyList[end]` for an undirected graph.

4. **Compute Shortest Paths**:
   - For each city `i`, call `dijkstra(n, adjacencyList, shortestPathMatrix[i], i)`, where `i` is the source city. This function updates `shortestPathMatrix[i]` to hold the shortest path distances from city `i`.

5. **Find the Result**:
   - Call `getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold)` to determine the city with the fewest reachable cities within the given distance threshold.

#### Code Implementation (C++)

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adjacencyList(n);
        // Matrix to store shortest path distances from each city
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        // Initialize adjacency list and shortest path matrix
        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        // Populate the adjacency list with edges
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].emplace_back(end, weight);
            adjacencyList[end].emplace_back(start, weight);  // For undirected graph
        }

        // Compute shortest paths from each city using Dijkstra's algorithm
        for (int i = 0; i < n; i++) {
            dijkstra(n, adjacencyList, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }

    // Dijkstra's algorithm to find shortest paths from a source city
    void dijkstra(int n, const vector<vector<pair<int, int>>>& adjacencyList,
                  vector<int>& shortestPathDistances, int source) {
        // Priority queue to process nodes with the smallest distance first
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> priorityQueue;
        priorityQueue.emplace(0, source);
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INT_MAX);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Process nodes in priority order
        while (!priorityQueue.empty()) {
            auto [currentDistance, currentCity] = priorityQueue.top();
            priorityQueue.pop();
            if (currentDistance > shortestPathDistances[currentCity]) {
                continue;
            }

            // Update distances to neighboring cities
            for (const auto& [neighborCity, edgeWeight] : adjacencyList[currentCity]) {
                if (shortestPathDistances[neighborCity] > currentDistance + edgeWeight) {
                    shortestPathDistances[neighborCity] = currentDistance + edgeWeight;
                    priorityQueue.emplace(shortestPathDistances[neighborCity], neighborCity);
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;  // Skip self
                }
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

#### Complexity Analysis

##### Time Complexity

- **Dijkstra's Algorithm**: For one source, Dijkstra's algorithm using a priority queue runs in \(O(m \cdot \log n)\), where \(m\) is the number of edges.
- **Worst Case**: With \(m = O(n \cdot (n - 1) / 2)\), the time complexity becomes \(O(n^2 \cdot \log n)\).
- **Total for All Sources**: Running Dijkstra's algorithm for \(n\) cities results in \(O(n \cdot n^2 \cdot \log n) = O(n^3 \cdot \log n)\).

##### Space Complexity

- **Adjacency List**: \(O(m + n)\), where \(m = O(n^2)\) in the worst case.
- **Shortest Path Matrix**: \(O(n^2)\).
- **Total Space Complexity**: \(O(n^2)\).

---

### Approach 2: Bellman-Ford Algorithm

#### **Intuition**

The Bellman-Ford algorithm is a graph search algorithm that finds the shortest paths from a single source vertex to all other vertices in a weighted graph. Unlike Dijkstra's algorithm, Bellman-Ford can handle graphs with negative edge weights, making it more versatile but potentially slower.

1. **Initialization**:  
   - All distances are initialized to infinity (`INF`), except for the source vertex, which is set to zero. This represents our initial state of knowledge — no known paths, so we assume they're infinitely long, except for the trivial path from a vertex to itself.

2. **Relaxation**:  
   - For each edge in the graph, we check if the distance to the destination vertex can be improved by going through the source vertex of that edge.  
   - This relaxation step is repeated `V-1` times (where `V` is the number of vertices). In the worst-case scenario (e.g., vertices form a line), it might take `V-1` steps for changes to propagate from one end to the other.

3. **Application**:  
   - We apply Bellman-Ford from each city as a source to compute the shortest paths from every city to every other city.
   - While we could have used a single source and repeated Bellman-Ford for other sources, running it independently for each source simplifies the code structure.

4. **Result**:  
   - After computing all shortest paths, we count how many cities are reachable from each city within the given distance threshold.
   - Finally, we select the city that can reach the fewest others. In case of ties, the city with the higher number is chosen.

This approach ensures correctness even with negative edge weights (though our problem does not involve them). Its simplicity makes Bellman-Ford a good choice, despite being less efficient than other algorithms for this specific problem. Early termination and cycle detection are not implemented here, keeping the code straightforward.

#### **Algorithm**

1. **Create a 2D Array**:  
   - Use a `shortestPathMatrix` of dimensions `n x n` to store the shortest path distances between all pairs of cities.

2. **Run Bellman-Ford**:
   - For each city `i`, call `bellmanFord(n, edges, shortestPathMatrix[i], i)`, where:
     - `i` is the source city.
     - `shortestPathMatrix[i]` is the array holding the shortest path distances from city `i`.

3. **Identify the City with Fewest Reachable Cities**:
   - Call `getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold)` to identify the city with the fewest reachable cities within the given distance threshold.

#### **Functions**

1. **`bellmanFord(n, edges, shortestPathDistances, source)`**:
   - **Initialize Distances**:
     - Set all distances in `shortestPathDistances` to a large value (`INF`), representing unknown shortest distances initially.
     - Set `shortestPathDistances[source] = 0`.
   - **Relax Edges**:
     - Iterate through all edges in the graph up to `n-1` times:
       - For each edge `(start, end, weight)`:
         - If a shorter path to `end` is found through `start`, update `shortestPathDistances[end]`.
         - Similarly, update `shortestPathDistances[start]` if a shorter path is found through `end`.

2. **`getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold)`**:
   - **Initialization**:
     - Set `cityWithFewestReachable = -1` and `fewestReachableCount = n`.
   - **Count Reachable Cities**:
     - For each city `i`, count how many cities `j` are reachable within the `distanceThreshold` (excluding self-loops).
   - **Update Result**:
     - If the current city `i` has fewer reachable cities than the previously identified city, update `cityWithFewestReachable`.
     - In case of ties, choose the city with the higher number.

#### **Implementation**

```cpp
class Solution {
public:
    // Large value to represent infinity
    const int INF = 1e9 + 7;

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Matrix to store shortest path distances from each city
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INF));

        // Compute shortest paths from each city using Bellman-Ford algorithm
        for (int i = 0; i < n; i++) {
            bellmanFord(n, edges, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }

private:
    // Bellman-Ford algorithm to find shortest paths from a source city
    void bellmanFord(int n, const vector<vector<int>>& edges, vector<int>& shortestPathDistances, int source) {
        // Initialize distances from the source
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INF);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Relax edges up to n-1 times
        for (int i = 1; i < n; i++) {
            for (const auto& edge : edges) {
                int start = edge[0];
                int end = edge[1];
                int weight = edge[2];
                // Update shortest path distances if a shorter path is found
                if (shortestPathDistances[start] != INF &&
                    shortestPathDistances[start] + weight < shortestPathDistances[end]) {
                    shortestPathDistances[end] = shortestPathDistances[start] + weight;
                }
                if (shortestPathDistances[end] != INF &&
                    shortestPathDistances[end] + weight < shortestPathDistances[start]) {
                    shortestPathDistances[start] = shortestPathDistances[end] + weight;
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;  // Skip self
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

#### **Complexity Analysis**

1. **Time Complexity**:  
   - For one source, Bellman-Ford runs in \(O(n \cdot m)\), where \(m\) is the number of edges.
   - In the worst case, \(m = n \cdot (n-1) / 2\) (complete graph). So, the complexity for one source becomes \(O(n \cdot (n \cdot (n-1) / 2)) = O(n^3)\).  
   - Since Bellman-Ford runs for all \(n\) cities, the total complexity is \(O(n \cdot n^3) = O(n^4)\).

2. **Space Complexity**:  
   - The space complexity is \(O(n^2)\), dominated by the `shortestPathMatrix` that stores shortest path distances between every pair of cities.

---

### Approach 3: Shortest Path First Algorithm (SPFA)

#### **Intuition**

The Shortest Path Faster Algorithm (SPFA) is an optimization of the Bellman-Ford algorithm. It works faster on average, particularly for sparse graphs, while still handling negative edge weights. Unlike Bellman-Ford, SPFA uses a queue to process vertices selectively, focusing on parts of the graph where updates are still possible. This often results in significant performance improvements.

1. **Initialization**:
   - All distances are initialized to infinity, except for the source vertex, which is set to zero.
   - A queue is used to track vertices whose shortest paths might be updated.

2. **Relaxation**:
   - Vertices are processed from the queue, and their neighbors are relaxed.
   - If a shorter path is found to a neighbor, it is added to the queue (if not already present).

3. **Cycle Detection**:
   - The algorithm tracks the number of times each vertex is processed. If any vertex is processed more than `V` times (where `V` is the number of vertices), it indicates a negative weight cycle.

While SPFA shares the same worst-case time complexity as Bellman-Ford, its practical performance is often much better due to its selective processing.

#### **Algorithm**

1. **Graph Representation**:
   - Create an adjacency list, `adjacencyList`, to store the graph.
   - Create a 2D array, `shortestPathMatrix`, with dimensions `n x n` to store shortest path distances between all pairs of cities.

2. **Initialization**:
   - For each city `i`, initialize the distance to itself as `0` and all other distances as `∞`.

3. **Populate Adjacency List**:
   - Iterate through each edge and populate the adjacency list with the start, end, and weight of each edge.

4. **Run SPFA for Each City**:
   - For each city `i`, call `spfa(n, adjacencyList, shortestPathMatrix[i], i)` to compute the shortest path distances from city `i`.

5. **Identify the Desired City**:
   - Use `getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold)` to find the city with the fewest reachable cities within the given distance threshold.

#### **Implementation**

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Adjacency list to store the graph
        vector<vector<pair<int, int>>> adjacencyList(n);
        // Matrix to store shortest path distances from each city
        vector<vector<int>> shortestPathMatrix(n, vector<int>(n, INT_MAX));

        // Initialize adjacency list and shortest path matrix
        for (int i = 0; i < n; i++) {
            shortestPathMatrix[i][i] = 0;  // Distance to itself is zero
        }

        // Populate the adjacency list with edges
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            adjacencyList[start].emplace_back(end, weight);
            adjacencyList[end].emplace_back(start, weight);  // For undirected graph
        }

        // Compute shortest paths from each city using SPFA algorithm
        for (int i = 0; i < n; i++) {
            spfa(n, adjacencyList, shortestPathMatrix[i], i);
        }

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(n, shortestPathMatrix, distanceThreshold);
    }

private:
    // SPFA algorithm to find shortest paths from a source city
    void spfa(int n, const vector<vector<pair<int, int>>>& adjacencyList, 
              vector<int>& shortestPathDistances, int source) {
        // Queue to process nodes with updated shortest path distances
        deque<int> queue;
        vector<int> updateCount(n, 0);
        queue.push_back(source);
        fill(shortestPathDistances.begin(), shortestPathDistances.end(), INT_MAX);
        shortestPathDistances[source] = 0;  // Distance to source itself is zero

        // Process nodes in queue
        while (!queue.empty()) {
            int currentCity = queue.front();
            queue.pop_front();
            for (const auto& [neighborCity, edgeWeight] : adjacencyList[currentCity]) {
                if (shortestPathDistances[neighborCity] > 
                    shortestPathDistances[currentCity] + edgeWeight) {
                    shortestPathDistances[neighborCity] = 
                        shortestPathDistances[currentCity] + edgeWeight;
                    updateCount[neighborCity]++;
                    queue.push_back(neighborCity);

                    // Detect negative weight cycles (not expected in this problem)
                    if (updateCount[neighborCity] > n) {
                        cerr << "Negative weight cycle detected" << endl;
                    }
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(
        int n, const vector<vector<int>>& shortestPathMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;  // Skip self
                }
                if (shortestPathMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

#### **Complexity Analysis**

1. **Time Complexity**:
   - **SPFA per Source**: On average, the time complexity is \(Θ(m)\) (where \(m\) is the number of edges). In the worst case, it is \(O(n^2)\) (as \(m \leq n^2\)).
   - **Running for All Cities**: Since SPFA runs for each city, the overall average time complexity is \(Θ(n \cdot m) = Θ(n^3)\). In the worst case, it is \(O(n \cdot n^2) = O(n^4)\).

2. **Space Complexity**:
   - **Shortest Path Matrix**: Requires \(O(n^2)\) space.
   - **Adjacency List**: Requires \(O(m)\) space.
   - **Auxiliary Structures**: The queue and update count array require \(O(n)\) space.
   - **Total**: In the worst case, the space complexity is \(O(n^2)\).

#### **Key Takeaways**

- SPFA is an efficient and practical algorithm for finding shortest paths in sparse graphs.
- Its ability to handle negative edge weights makes it versatile.
- Although its worst-case complexity is similar to Bellman-Ford, SPFA often performs significantly better in practice.

---

### Approach 4: Floyd-Warshall Algorithm

#### **Intuition**

The Floyd-Warshall algorithm is used to find the shortest paths in a weighted graph with positive or negative edge weights, as long as there are no negative weight cycles. Unlike single-source algorithms like Dijkstra’s or Bellman-Ford, Floyd-Warshall computes shortest paths between all pairs of vertices simultaneously.

The algorithm starts by initializing a distance matrix where:

- Direct connections between cities are filled with their edge weights.
- Other distances are set to infinity.
- The distance from a city to itself is set to zero.

The algorithm iteratively refines the shortest paths by considering each vertex as an intermediate point. For every pair of vertices \(i\) and \(j\), it checks whether the path through an intermediate vertex \(k\) is shorter than the current known path. If it is, the distance is updated.

This process ensures that by the end of the algorithm, the shortest paths for all pairs are computed. After running Floyd-Warshall, we can directly count reachable cities for each source and select the city with the fewest reachable neighbors within the distance threshold.

#### **Advantages**

- Solves the all-pairs shortest path problem in one pass with a simple and elegant implementation.
- Efficient for dense graphs due to its \(O(n^3)\) time complexity.
- Handles both positive and negative edge weights (but no negative cycles).

#### **Algorithm**

1. **Initialization**:
   - Define \(INF\) as a large constant (e.g., \(10^9 + 7\)) to represent infinite distance.
   - Create a 2D array `distanceMatrix` with dimensions \(n \times n\) to store shortest path distances.
   - For each city \(i\):
     - Set `distanceMatrix[i][j]` to \(INF\) for all \(j\), except `distanceMatrix[i][i]`, which is set to 0.
   - Populate the matrix with edge weights from the given graph.

2. **Floyd-Warshall Algorithm**:
   - Use three nested loops to update `distanceMatrix`:
     - The outer loop iterates over each vertex \(k\) (intermediate vertex).
     - The middle loop iterates over each vertex \(i\) (source).
     - The inner loop iterates over each vertex \(j\) (destination).
     - Update the shortest path from \(i\) to \(j\) using \(k\) as an intermediate vertex:
       \[
       \text{distanceMatrix[i][j]} = \min(\text{distanceMatrix[i][j]}, \text{distanceMatrix[i][k]} + \text{distanceMatrix[k][j]})
       \]

3. **Finding the Desired City**:
   - Count the number of reachable cities within the distance threshold for each city.
   - Select the city with the fewest reachable cities. If there is a tie, choose the city with the larger index.

---

#### **Implementation**

```cpp
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Large value to represent infinity
        const int INF = 1e9 + 7;
        // Distance matrix to store shortest paths between all pairs of cities
        vector<vector<int>> distanceMatrix(n, vector<int>(n, INF));

        // Initialize distance matrix
        for (int i = 0; i < n; i++) {
            distanceMatrix[i][i] = 0;  // Distance to itself is zero
        }

        // Populate the distance matrix with initial edge weights
        for (const auto& edge : edges) {
            int start = edge[0];
            int end = edge[1];
            int weight = edge[2];
            distanceMatrix[start][end] = weight;
            distanceMatrix[end][start] = weight;  // For undirected graph
        }

        // Compute shortest paths using Floyd-Warshall algorithm
        floyd(n, distanceMatrix);

        // Find the city with the fewest number of reachable cities within the distance threshold
        return getCityWithFewestReachable(n, distanceMatrix, distanceThreshold);
    }

    // Floyd-Warshall algorithm to compute shortest paths between all pairs of cities
    void floyd(int n, vector<vector<int>>& distanceMatrix) {
        // Update distances for each intermediate city
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Update shortest path from i to j through k
                    distanceMatrix[i][j] = min(distanceMatrix[i][j], distanceMatrix[i][k] + distanceMatrix[k][j]);
                }
            }
        }
    }

    // Determine the city with the fewest number of reachable cities within the distance threshold
    int getCityWithFewestReachable(int n, const vector<vector<int>>& distanceMatrix, int distanceThreshold) {
        int cityWithFewestReachable = -1;
        int fewestReachableCount = n;

        // Count number of cities reachable within the distance threshold for each city
        for (int i = 0; i < n; i++) {
            int reachableCount = 0;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;  // Skip self
                if (distanceMatrix[i][j] <= distanceThreshold) {
                    reachableCount++;
                }
            }
            // Update the city with the fewest reachable cities
            if (reachableCount <= fewestReachableCount) {
                fewestReachableCount = reachableCount;
                cityWithFewestReachable = i;
            }
        }
        return cityWithFewestReachable;
    }
};
```

#### **Complexity Analysis**

- **Time Complexity**: \(O(n^3)\)
  - The Floyd-Warshall algorithm has three nested loops, each iterating \(n\) times. Hence, the time complexity is \(O(n^3)\).

- **Space Complexity**: \(O(n^2)\)
  - The space complexity is dominated by the `distanceMatrix`, which requires \(O(n^2)\) space to store distances for all pairs of cities.

#### **Advantages and Limitations**

- **Advantages**:
  - Efficient for dense graphs with many edges.
  - Handles both positive and negative weights (but no negative cycles).
  - Simple and straightforward implementation.

- **Limitations**:
  - Not optimal for sparse graphs due to \(O(n^3)\) time complexity.
  - Requires \(O(n^2)\) space, which can be memory-intensive for large graphs.

---

> **Resources**:
>
> - [Floyd-Warshall Algorithm](https://en.wikipedia.org/wiki/Floyd-Warshall_algorithm)
> - [Minimum Spanning Tree](https://en.wikipedia.org/wiki/Minimum_spanning_tree)  
> - [Bellman-Ford Algorithm](https://en.wikipedia.org/wiki/Bellman%E2%80%93Ford_algorithm)

---

> **Related Questions**:
>
> - [Find the City With the Smallest Number of Neighbors at a Threshold Distance](https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/)
> - [Network Delay Time](https://leetcode.com/problems/network-delay-time/)
