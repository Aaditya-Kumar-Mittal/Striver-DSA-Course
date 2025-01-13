# Bellman-Ford Algorithm

## Table of Contents

- [Bellman-Ford Algorithm](#bellman-ford-algorithm)
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

---

## Introduction

The **Bellman-Ford Algorithm** is a graph traversal algorithm that computes the shortest paths from a single source vertex to all other vertices in a weighted and directed graph. It can handle graphs with negative edge weights, making it more versatile than Dijkstra's algorithm. However, it is slower, with a time complexity of \(O(V \cdot E)\).

If a negative weight cycle exists in the graph, the algorithm detects it and returns an indicator, as shortest paths are undefined for such graphs.

---

## Problem Description

### Input

- **`edges`**: A list of edges, where each edge is represented as `[u, v, weight]`. This indicates a directed edge from vertex `u` to vertex `v` with the given weight.
- **`V`**: The number of vertices in the graph.
- **`src`**: The source vertex.

### Output

- An array where the \(i^{th}\) value denotes the shortest distance from the source vertex to vertex \(i\). If a vertex is not reachable, the distance is set to \(10^8\).
- If a negative weight cycle exists, return `[-1]`.

---

## Examples

### Example 1

**Input:**

```plaintext
edges = [[0, 1, 9]]
src = 0
V = 2
```

**Output:**

```plaintext
[0, 9]
```

**Explanation:**

- Shortest distance from vertex \(0\) to itself is \(0\).
- Shortest distance from \(0\) to \(1\) is \(9\).

---

### Example 2

**Input:**

```plaintext
edges = [[0, 1, 5], [1, 0, 3], [1, 2, -1], [2, 0, 1]]
src = 2
V = 3
```

**Output:**

```plaintext
[1, 6, 0]
```

**Explanation:**

- \(2 \to 0\): Path cost is \(1\).
- \(2 \to 1\): Path cost is \(2 \to 0 \to 1 = 1 + 5 = 6\).
- Distance to \(2\) from itself is \(0\).

---

### Constraints

- \(1 \leq V \leq 5000\)
- \(1 \leq E \leq V \cdot (V-1)\)
- \(-1000 \leq \text{weight of edges} \leq 1000\)
- \(0 \leq \text{src} < V\)

---

## Approach

### Algorithm

1. **Initialization**:
   - Create a `distance` array and initialize all distances to \(10^8\), except for the source vertex, which is set to \(0\).

2. **Relaxation**:
   - Iterate \(V-1\) times over all edges. For each edge \((u, v, w)\):
     - If the current distance to \(u\) is not \(10^8\) and can be improved, update \(v\)'s distance.

3. **Negative Cycle Detection**:
   - Perform one additional iteration over all edges to check if a further relaxation is possible. If yes, a negative weight cycle exists.

4. **Output**:
   - If a negative cycle exists, return `[-1]`.
   - Otherwise, return the `distance` array.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Initialize distances with a large value
        vector<int> distance(V, 1e8);
        distance[src] = 0;

        // Relax all edges (V-1) times
        for (int i = 0; i < V - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (distance[u] != 1e8 && distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (distance[u] != 1e8 && distance[u] + wt < distance[v]) {
                return {-1}; // Negative weight cycle detected
            }
        }

        return distance;
    }
};

// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> edges(E, vector<int>(3));
        for (int i = 0; i < E; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> result = obj.bellmanFord(V, edges, src);

        for (int dist : result) {
            cout << dist << " ";
        }
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
    public int[] bellmanFord(int V, int[][] edges, int src) {
        // Initialize distances
        int[] distance = new int[V];
        Arrays.fill(distance, (int) 1e8);
        distance[src] = 0;

        // Relax edges V-1 times
        for (int i = 0; i < V - 1; i++) {
            for (int[] edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if (distance[u] != (int) 1e8 && distance[u] + wt < distance[v]) {
                    distance[v] = distance[u] + wt;
                }
            }
        }

        // Check for negative weight cycles
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            if (distance[u] != (int) 1e8 && distance[u] + wt < distance[v]) {
                return new int[]{-1}; // Negative weight cycle detected
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

            int[][] edges = new int[E][3];
            for (int i = 0; i < E; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                edges[i][2] = sc.nextInt();
            }

            int src = sc.nextInt();

            Solution obj = new Solution();
            int[] result = obj.bellmanFord(V, edges, src);

            for (int dist : result) {
                System.out.print(dist + " ");
            }
            System.out.println();
        }

        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Relaxation**: \(O(V \cdot E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

### Space Complexity

- \(O(V)\) for the `distance` array.

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
