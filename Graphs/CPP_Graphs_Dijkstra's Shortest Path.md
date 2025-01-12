# Dijkstra's Shortest Path

## Table of Contents

- [Dijkstra's Shortest Path](#dijkstras-shortest-path)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Code](#code)
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

Dijkstra's algorithm is used to find the shortest path in a graph from a source vertex to all other vertices. It is particularly effective for graphs with non-negative edge weights. The algorithm employs a priority queue to iteratively select the closest vertex and update the shortest path to its neighbors.

---

## Problem Description

Given an undirected graph with `V` vertices labeled `0` through `V-1` and `E` edges, where each edge has a weight, determine the shortest path distances from the source vertex (`0`) to all other vertices.

---

## Examples

### Example 1

**Input:**  

```bash
V = 4, E = 5  
Edges:  
0 1 5  
0 2 8  
1 2 9  
1 3 2  
2 3 6
```

**Output:**  

```bash
Distances from source (0):  
0 5 8 7
```

**Explanation:**  
The shortest paths are:  

- 0 → 0: Distance = 0  
- 0 → 1: Distance = 5  
- 0 → 2: Distance = 8  
- 0 → 3: Distance = 7  

---

### Example 2

**Input:**  

```bash
V = 6, E = 9  
Edges:  
0 1 4  
0 2 1  
1 2 2  
1 3 7  
2 4 3  
3 5 1  
4 5 5  
4 3 2  
5 6 6
```

**Output:**  

```bash
Distances from source (0):  
0 4 1 10 4 9
```

---

## Constraints

1. \(1 \leq V, E \leq 10^5\)
2. Graph is connected.
3. Edge weights are non-negative.
4. No self-loops or multiple edges between the same pair of nodes.

---

## Approach

### Steps

1. Represent the graph using an adjacency list.
2. Use a priority queue (min-heap) to select the vertex with the smallest known distance.
3. Relax the edges of the current vertex, updating the shortest distances for its neighbors.
4. Repeat until all vertices are processed.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &edges, int vertices, int edgesCount, int source) {
    // Adjacency list representation of the graph
    vector<pair<int, int>> adj[vertices];
    for (auto &edge : edges) {
        adj[edge[0]].push_back({edge[1], edge[2]});
        adj[edge[1]].push_back({edge[0], edge[2]});
    }

    // Min-heap (priority queue) to store (distance, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance array initialized to INF
    vector<int> distance(vertices, INT_MAX);

    // Set source distance to 0 and push into the priority queue
    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto &adjNode : adj[node]) {
            int nextNode = adjNode.first;
            int weight = adjNode.second;

            if (dist + weight < distance[nextNode]) {
                distance[nextNode] = dist + weight;
                pq.push({distance[nextNode], nextNode});
            }
        }
    }

    return distance;
}
```

---

### Java Implementation

```java
import java.util.*;

class DijkstraShortestPath {
    static class Pair implements Comparable<Pair> {
        int node, distance;

        Pair(int node, int distance) {
            this.node = node;
            this.distance = distance;
        }

        @Override
        public int compareTo(Pair other) {
            return this.distance - other.distance;
        }
    }

    public static int[] dijkstra(int vertices, int edgesCount, int[][] edges, int source) {
        // Adjacency list representation of the graph
        ArrayList<ArrayList<int[]>> adj = new ArrayList<>();
        for (int i = 0; i < vertices; i++) {
            adj.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            adj.get(edge[0]).add(new int[] { edge[1], edge[2] });
            adj.get(edge[1]).add(new int[] { edge[0], edge[2] });
        }

        // Priority queue (min-heap) for (distance, node)
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        int[] distance = new int[vertices];
        Arrays.fill(distance, Integer.MAX_VALUE);

        // Initialize source distance
        distance[source] = 0;
        pq.add(new Pair(source, 0));

        while (!pq.isEmpty()) {
            Pair current = pq.poll();
            int node = current.node;
            int dist = current.distance;

            for (int[] neighbor : adj.get(node)) {
                int nextNode = neighbor[0];
                int weight = neighbor[1];

                if (dist + weight < distance[nextNode]) {
                    distance[nextNode] = dist + weight;
                    pq.add(new Pair(nextNode, distance[nextNode]));
                }
            }
        }

        return distance;
    }

    public static void main(String[] args) {
        int vertices = 4, edgesCount = 5;
        int[][] edges = { { 0, 1, 5 }, { 0, 2, 8 }, { 1, 2, 9 }, { 1, 3, 2 }, { 2, 3, 6 } };
        int source = 0;

        int[] result = dijkstra(vertices, edgesCount, edges, source);
        System.out.println("Shortest distances from source " + source + ": " + Arrays.toString(result));
    }
}
```

---

## Complexity Analysis

### Time Complexity

- Constructing the adjacency list: \(O(V + E)\)
- Processing vertices and edges in the priority queue: \(O((V + E) \log V)\)

**Overall:** \(O((V + E) \log V)\)

### Space Complexity

- Adjacency list: \(O(V + E)\)
- Priority queue and distance array: \(O(V)\)

**Overall:** \(O(V + E)\)

---

## How to Run the Code

### For C++

1. Compile the code using a C++ compiler:

   ```bash
   g++ -std=c++17 dijkstra.cpp -o dijkstra
   ```

2. Run the compiled program:

   ```bash
   ./dijkstra
   ```

### For Java

1. Compile the Java file:

   ```bash
   javac DijkstraShortestPath.java
   ```

2. Run the program:

   ```bash
   java DijkstraShortestPath
   ```
