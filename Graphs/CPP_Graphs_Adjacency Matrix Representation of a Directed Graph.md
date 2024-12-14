# Adjacency Matrix Representation of a Directed Graph

## Table of Contents

- [Adjacency Matrix Representation of a Directed Graph](#adjacency-matrix-representation-of-a-directed-graph)
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

This program demonstrates how to represent a **directed graph** using an adjacency matrix. An adjacency matrix is a 2D array where the value at position `(i, j)` indicates whether there is a directed edge from vertex `i` to vertex `j`.

---

## Problem Description

### Input

1. Number of vertices `n`.
2. Number of edges `m`.
3. `m` pairs of integers `(u, v)` indicating a directed edge from `u` to `v`.

### Output

- The adjacency matrix representation of the graph.

---

## Examples

### Example Input

```bash
n = 4, m = 3
Edges: (1 -> 2), (2 -> 3), (4 -> 1)
```

### Example Output

```bash
Adjacency Matrix:
0 1 0 0
0 0 1 0
0 0 0 0
1 0 0 0
```

---

## Approach

1. **Initialization:**
   - Create a 2D array (matrix) of size \( n \times n \), initialized to zero.

2. **Input Reading:**
   - Read the number of vertices `n` and edges `m`.
   - For each directed edge `(u, v)`, set `matrix[u][v] = 1`.

3. **Graph Representation:**
   - Print the matrix row by row.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; // n = number of vertices, m = number of edges
    cin >> n >> m;

    // Initialize adjacency matrix
    vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));

    // Read the edges and populate the adjacency matrix
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // Mark the edge from u to v
    }

    // Display the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Input number of vertices and edges
        int n = sc.nextInt();
        int m = sc.nextInt();

        // Initialize adjacency matrix
        int[][] adj = new int[n + 1][n + 1];

        // Read edges and populate the adjacency matrix
        for (int i = 0; i < m; i++) {
            int u = sc.nextInt();
            int v = sc.nextInt();
            adj[u][v] = 1; // Mark the edge from u to v
        }

        // Display the adjacency matrix
        System.out.println("Adjacency Matrix:");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                System.out.print(adj[i][j] + " ");
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
- **Adjacency Matrix Construction:** \( O(m) \), as each edge is processed once.
- **Overall:** \( O(m) \).

### Space Complexity

- **Adjacency Matrix Storage:** \( O(n^2) \), where \( n \) is the number of vertices, as we store all possible connections.

---

This approach is efficient for dense graphs but might consume significant memory for sparse graphs.
