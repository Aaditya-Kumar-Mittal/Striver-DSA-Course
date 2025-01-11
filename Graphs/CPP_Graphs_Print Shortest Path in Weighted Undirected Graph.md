# Shortest Path in Weighted Undirected Graph

## Table of Contents

- [Shortest Path in Weighted Undirected Graph](#shortest-path-in-weighted-undirected-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

Given a weighted undirected graph with `n` vertices and `m` edges, this problem involves finding the shortest weighted path between vertex `1` and vertex `n`. If no such path exists, the output should indicate this with `-1`.

The graph's edges are provided as a list of triples, `{a, b, w}`, where `a` and `b` are vertices connected by an edge with weight `w`.

## Problem Description

### Examples

#### Example 1

Input:

```bash
n = 5, m = 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
```

Output:

```bash
5
```

Explanation:
The shortest path from vertex `1` to vertex `5` is through `1 -> 4 -> 3 -> 5` with a total weight of `5`.

#### Example 2

Input:

```bash
n = 2, m = 1, edges = [[1, 2, 2]]
```

Output:

```bash
2
```

Explanation:
The shortest path from vertex `1` to vertex `2` is `1 -> 2` with weight `2`.

#### Example 3

Input:

```bash
n = 2, m = 0, edges = []
```

Output:

```bash
-1
```

Explanation:
Since there are no edges, no path exists between vertex `1` and vertex `2`.

### Constraints

- \( 2 \leq n \leq 10^6 \)
- \( 0 \leq m \leq 10^6 \)
- \( 1 \leq a, b \leq n \)
- \( 1 \leq w \leq 10^5 \)

## Approach

The problem is solved using **Dijkstra's algorithm**, which is well-suited for finding the shortest path in graphs with non-negative edge weights. The main steps include:

1. Representing the graph using an adjacency list.
2. Using a min-heap (priority queue) to efficiently retrieve the next vertex with the smallest distance.
3. Maintaining a distance array to store the shortest known distance to each vertex.
4. Backtracking using a parent array to reconstruct the shortest path once the destination vertex is reached.

If the destination vertex is unreachable, return `-1`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Adjacency list
        vector<pair<int, int>> adj[n + 1];
        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        // Min-heap to store (distance, node)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Distance and parent arrays
        vector<int> distance(n + 1, INT_MAX), parent(n + 1);
        for (int i = 1; i <= n; i++) parent[i] = i;

        distance[1] = 0;
        pq.push({0, 1});

        // Dijkstra's algorithm
        while (!pq.empty()) {
            auto [dist, node] = pq.top();
            pq.pop();

            for (auto [nextNode, edgeWeight] : adj[node]) {
                if (dist + edgeWeight < distance[nextNode]) {
                    distance[nextNode] = dist + edgeWeight;
                    pq.push({distance[nextNode], nextNode});
                    parent[nextNode] = node; // Update parent
                }
            }
        }

        // If destination node is unreachable
        if (distance[n] == INT_MAX) return {-1};

        // Reconstruct the shortest path
        vector<int> path;
        int node = n;
        while (parent[node] != node) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());

        // Prepend total weight to the path
        path.insert(path.begin(), distance[n]);
        return path;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(m, vector<int>(3));
        for (int i = 0; i < m; i++) {
            cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
        }

        Solution obj;
        vector<int> result = obj.shortestPath(n, m, edges);

        for (int val : result) cout << val << " ";
        cout << endl;
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public List<Integer> shortestPath(int n, int m, int[][] edges) {
        // Adjacency list
        List<List<int[]>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) adj.add(new ArrayList<>());
        for (int[] edge : edges) {
            adj.get(edge[0]).add(new int[]{edge[1], edge[2]});
            adj.get(edge[1]).add(new int[]{edge[0], edge[2]});
        }

        // Min-heap to store (distance, node)
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);

        // Distance and parent arrays
        int[] distance = new int[n + 1];
        int[] parent = new int[n + 1];
        Arrays.fill(distance, Integer.MAX_VALUE);
        for (int i = 1; i <= n; i++) parent[i] = i;

        distance[1] = 0;
        pq.offer(new int[]{0, 1});

        // Dijkstra's algorithm
        while (!pq.isEmpty()) {
            int[] current = pq.poll();
            int dist = current[0], node = current[1];

            for (int[] edge : adj.get(node)) {
                int nextNode = edge[0], weight = edge[1];

                if (dist + weight < distance[nextNode]) {
                    distance[nextNode] = dist + weight;
                    pq.offer(new int[]{distance[nextNode], nextNode});
                    parent[nextNode] = node; // Update parent
                }
            }
        }

        // If destination node is unreachable
        if (distance[n] == Integer.MAX_VALUE) return Collections.singletonList(-1);

        // Reconstruct the shortest path
        List<Integer> path = new ArrayList<>();
        int node = n;
        while (parent[node] != node) {
            path.add(node);
            node = parent[node];
        }
        path.add(1);
        Collections.reverse(path);

        // Prepend total weight to the path
        path.add(0, distance[n]);
        return path;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] edges = new int[m][3];

            for (int i = 0; i < m; i++) {
                edges[i][0] = sc.nextInt();
                edges[i][1] = sc.nextInt();
                edges[i][2] = sc.nextInt();
            }

            Solution solution = new Solution();
            List<Integer> result = solution.shortestPath(n, m, edges);

            for (int val : result) System.out.print(val + " ");
            System.out.println();
        }

        sc.close();
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(m \log n)\)
  - Each edge is processed once, and updating the priority queue takes \(\log n\).
- **Space Complexity**: \(O(n + m)\)
  - Space for adjacency list, distance array, and priority queue.

## How to Run the Code

### For C++

1. Copy the C++ implementation into a `.cpp` file.
2. Compile using `g++ -o shortest_path shortest_path.cpp`.
3. Run with `./shortest_path`.

### For Java

1. Copy the Java implementation into a `.java` file.
2. Compile using `javac Solution.java`.
3. Run with `java Solution`.
