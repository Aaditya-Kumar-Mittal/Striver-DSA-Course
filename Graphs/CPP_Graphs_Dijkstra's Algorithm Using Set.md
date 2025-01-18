# Dijkstra's Algorithm Using Set

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Dijkstra's Algorithm Using Set](#dijkstras-algorithm-using-set)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Objective](#objective)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [1. Use of `set` for Distance Tracking](#1-use-of-set-for-distance-tracking)
    - [2. Relaxation and Distance Update](#2-relaxation-and-distance-update)
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

Dijkstra's Algorithm can also be implemented using a `set` data structure instead of a priority queue. This approach uses a `set` to keep track of the vertices and their current shortest distances, allowing efficient retrieval and updates.

---

## Problem Description

### Objective

Given:

1. A weighted, undirected, and connected graph represented as an adjacency list `adj`.
2. A source vertex `src`.

Find the shortest distance from `src` to all other vertices using a `set` for distance updates.

---

### Examples

#### Example 1

**Input:**

```plaintext
adj = [[[1, 9]], [[0, 9]]], src = 0
```

**Output:**

```plaintext
[0, 9]
```

**Explanation:**  

- Distance from source `0` to `0` is `0`.
- Distance from source `0` to `1` is `9`.

---

#### Example 2

**Input:**

```plaintext
adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
```

**Output:**

```plaintext
[4, 3, 0]
```

**Explanation:**  

- Distance from `2` to `0` is `4` via path `2 -> 1 -> 0`.
- Distance from `2` to `1` is `3` directly.
- Distance from `2` to itself is `0`.

---

### Constraints

- \( 1 \leq \text{Number of vertices} \leq 1000 \)
- \( 0 \leq \text{adj}[i][j] \leq 1000 \)
- \( 0 \leq \text{src} < \text{Number of vertices} \)

---

## Approach

### 1. Use of `set` for Distance Tracking

- A `set` maintains the current shortest distance for all vertices.
- It automatically retrieves the vertex with the smallest distance.

### 2. Relaxation and Distance Update

- Update the shortest distance for adjacent vertices if a shorter path is found.
- Remove the vertex from the `set` before updating and reinsert it with the updated distance.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to find the shortest distance of all the vertices from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int V = adj.size(); // Number of vertices
        
        // Set to store (distance, vertex)
        set<pair<int, int>> st;
        
        // Initialize distances to all vertices as infinity
        vector<int> distance(V, INT_MAX);
        
        // Distance to source is 0
        distance[src] = 0;
        st.insert({0, src});
        
        while (!st.empty()) {
            // Get the vertex with the smallest distance
            auto it = *(st.begin());
            int currDist = it.first;
            int currNode = it.second;
            st.erase(it);
            
            // Traverse all adjacent nodes
            for (auto &neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;
                
                // Relaxation step: update the shortest distance
                if (currDist + edgeWeight < distance[nextNode]) {
                    // Remove the existing distance entry if present
                    if (distance[nextNode] != INT_MAX) {
                        st.erase({distance[nextNode], nextNode});
                    }
                    distance[nextNode] = currDist + edgeWeight;
                    st.insert({distance[nextNode], nextNode});
                }
            }
        }
        
        return distance;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int[] dijkstra(int V, ArrayList<ArrayList<ArrayList<Integer>>> adj, int src) {
        // Set to store (distance, node)
        TreeSet<int[]> st = new TreeSet<>((a, b) -> a[0] == b[0] ? Integer.compare(a[1], b[1]) : Integer.compare(a[0], b[0]));

        // Initialize distances to all vertices as infinity
        int[] distance = new int[V];
        Arrays.fill(distance, Integer.MAX_VALUE);

        // Distance to source is 0
        distance[src] = 0;
        st.add(new int[] {0, src});

        while (!st.isEmpty()) {
            // Get the current node and distance
            int[] current = st.pollFirst();
            int currDist = current[0];
            int currNode = current[1];

            // Traverse all adjacent nodes
            for (ArrayList<Integer> neighbor : adj.get(currNode)) {
                int nextNode = neighbor.get(0);
                int edgeWeight = neighbor.get(1);

                // Relaxation step: update the shortest distance
                if (currDist + edgeWeight < distance[nextNode]) {
                    st.remove(new int[] {distance[nextNode], nextNode});
                    distance[nextNode] = currDist + edgeWeight;
                    st.add(new int[] {distance[nextNode], nextNode});
                }
            }
        }

        return distance;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            ArrayList<ArrayList<ArrayList<Integer>>> adj = new ArrayList<>();
            for (int i = 0; i < V; i++)
                adj.add(new ArrayList<>());

            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                int w = sc.nextInt();
                adj.get(u).add(new ArrayList<>(Arrays.asList(v, w)));
                adj.get(v).add(new ArrayList<>(Arrays.asList(u, w)));
            }

            int src = sc.nextInt();

            Solution obj = new Solution();
            int[] res = obj.dijkstra(V, adj, src);

            for (int dist : res)
                System.out.print(dist + " ");
            System.out.println();
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Set Operations:** \( O((V + E) \log V) \)
- **Relaxation:** \( O(E) \)

### Space Complexity

- \( O(V + E) \) for adjacency list and set.

---

## How to Run the Code

### For C++

1. Compile using `g++`.
2. Run the compiled binary and input the test cases.

### For Java

1. Compile using `javac`.
2. Run the program using `java`.