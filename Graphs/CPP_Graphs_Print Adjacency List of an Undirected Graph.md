# Print Adjacency List of an Undirected Graph

## Table of Contents

- [Print Adjacency List of an Undirected Graph](#print-adjacency-list-of-an-undirected-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Approach](#approach)
    - [Steps to Create the Adjacency List](#steps-to-create-the-adjacency-list)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Introduction

An **adjacency list** is a common way to represent graphs. For each vertex, it lists the vertices that are directly connected to it. This problem involves constructing the adjacency list for an **undirected graph** given its vertices and edges.

---

## Problem Description

### Input

- An integer `V` (1 ≤ V ≤ 10⁵), the number of vertices.
- An integer `E` (1 ≤ E ≤ 10⁵), the number of edges.
- A list of edges, where each edge is represented as a pair of integers `[u, v]`.

### Output

- A list of lists where the `i`th list contains all the vertices connected to vertex `i`, sorted in ascending order.

---

## Examples

### Example 1

**Input:**  

```bash
V = 5, E = 7  
edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]
```

**Output:**  

```bash
[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
```

**Explanation:**  

- Node 0 is connected to 1 and 4.  
- Node 1 is connected to 0, 2, 3, and 4.  
- Node 2 is connected to 1 and 3.  
- Node 3 is connected to 1, 2, and 4.  
- Node 4 is connected to 0, 1, and 3.

---

### Example 2

**Input:**  

```bash
V = 4, E = 3  
edges = [[0,3], [0,2], [2,1]]
```

**Output:**  

```bash
[[2,3], [2], [0,1], [0]]
```

**Explanation:**  

- Node 0 is connected to 2 and 3.  
- Node 1 is connected to 2.  
- Node 2 is connected to 0 and 1.  
- Node 3 is connected to 0.

---

## Approach

### Steps to Create the Adjacency List

1. Initialize an empty list of lists for `V` vertices.
2. Iterate through each edge `[u, v]`:
   - Add `v` to the adjacency list of `u`.
   - Add `u` to the adjacency list of `v` (because the graph is undirected).
3. Sort each vertex's adjacency list to ensure the output is in ascending order.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj_list(V);

        // Populate the adjacency list
        for (auto edge : edges) {
            int u = edge.first;
            int v = edge.second;

            adj_list[u].push_back(v);
            adj_list[v].push_back(u); // Undirected graph
        }

        // Sort adjacency lists
        for (int i = 0; i < V; i++) {
            sort(adj_list[i].begin(), adj_list[i].end());
        }

        return adj_list;
    }
};

int main() {
    int tc; // Number of test cases
    cin >> tc;

    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<pair<int, int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.emplace_back(u, v);
        }

        Solution obj;
        vector<vector<int>> adj = obj.printGraph(V, edges);

        for (int i = 0; i < V; i++) {
            cout << "[";
            for (int j = 0; j < adj[i].size(); j++) {
                cout << adj[i][j];
                if (j != adj[i].size() - 1) cout << " ";
            }
            cout << "]\n";
        }
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public List<List<Integer>> printGraph(int V, List<int[]> edges) {
        List<List<Integer>> adj_list = new ArrayList<>();

        // Initialize adjacency list
        for (int i = 0; i < V; i++) {
            adj_list.add(new ArrayList<>());
        }

        // Populate adjacency list
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj_list.get(u).add(v);
            adj_list.get(v).add(u); // Undirected graph
        }

        // Sort adjacency lists
        for (List<Integer> adj : adj_list) {
            Collections.sort(adj);
        }

        return adj_list;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt(); // Number of test cases

        while (tc-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();

            List<int[]> edges = new ArrayList<>();
            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                edges.add(new int[] { u, v });
            }

            Solution obj = new Solution();
            List<List<Integer>> adj = obj.printGraph(V, edges);

            for (List<Integer> list : adj) {
                System.out.print("[");
                for (int i = 0; i < list.size(); i++) {
                    System.out.print(list.get(i));
                    if (i != list.size() - 1) System.out.print(" ");
                }
                System.out.println("]");
            }
        }

        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **Adjacency List Construction:** \( O(E) \), where \( E \) is the number of edges.
2. **Sorting Adjacency Lists:** \( O(V \cdot d \log d) \), where \( d \) is the average degree of the vertices.

   For sparse graphs (\( E \approx V \)):  
   \( O(V \log V) \).

   For dense graphs (\( E \approx V^2 \)):  
   \( O(V^2 \log V) \).

### Space Complexity

- **Adjacency List Storage:** \( O(V + 2E) \), as we store all vertices and edges.

---

This solution efficiently constructs the adjacency list and ensures sorted order for easy use in graph algorithms.
