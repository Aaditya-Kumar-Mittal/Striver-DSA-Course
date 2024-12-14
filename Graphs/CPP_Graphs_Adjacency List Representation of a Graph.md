# Adjacency List Representation of a Graph

## Table of Contents

- [Adjacency List Representation of a Graph](#adjacency-list-representation-of-a-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example Input](#example-input)
    - [Example Output](#example-output)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Introduction

This program demonstrates the representation of an **undirected graph** using an adjacency list. The adjacency list is a collection of lists where each list represents the neighbors of a vertex.

---

## Problem Description

### Input

1. Number of vertices `n`.
2. Number of edges `m`.
3. `m` pairs of integers representing edges between vertices.

### Output

- The adjacency list representation of the graph.

---

## Examples

### Example Input

```bash
n = 4, m = 3
Edges: (1, 2), (2, 3), (4, 1)
```

### Example Output

```bash
Adjacency List:
1 -> 2 4
2 -> 1 3
3 -> 2
4 -> 1
```

---

## Approach

1. **Initialization:**
   - Create a vector of lists (or vectors) `adj` of size `n+1` to hold the adjacency list.

2. **Input Reading:**
   - Read the number of vertices `n` and edges `m`.
   - For each edge, add both vertices to each other's list since the graph is undirected.

3. **Graph Representation:**
   - Use a loop to print each vertex along with its neighbors.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    // Initialize the adjacency list
    vector<int> adj[n + 1];

    // Read the edges and populate the adjacency list
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // Add edge from u to v
        adj[v].push_back(u); // Add edge from v to u (because it's undirected)
    }

    // Display the adjacency list
    cout << "Adjacency List:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << " -> ";
        for (int neighbor : adj[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of vertices and edges
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initialize adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        // Read edges and populate the adjacency list
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj.get(u).add(v); // Add edge from u to v
            adj.get(v).add(u); // Add edge from v to u (because it's undirected)
        }

        // Display the adjacency list
        System.out.println("Adjacency List:");
        for (int i = 1; i <= n; i++) {
            System.out.print(i + " -> ");
            for (int neighbor : adj.get(i)) {
                System.out.print(neighbor + " ");
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

- **Input Reading:** \( O(m) \), where \( m \) is the number of edges.
- **Adjacency List Construction:** \( O(m) \), as each edge is added twice (for undirected graph).
- **Overall:** \( O(m) \).

### Space Complexity

- **Adjacency List Storage:** \( O(n + 2m) \), where \( n \) is the number of vertices and \( 2m \) accounts for all edges (each stored twice in the list for undirected graphs).
