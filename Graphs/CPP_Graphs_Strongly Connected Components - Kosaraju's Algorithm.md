# Strongly Connected Components - Kosaraju's Algorithm

## Table of Contents

- [Strongly Connected Components - Kosaraju's Algorithm](#strongly-connected-components---kosarajus-algorithm)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Features of Kosaraju's Algorithm](#features-of-kosarajus-algorithm)
  - [Problem Description](#problem-description)
    - [Task](#task)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps in Kosaraju's Algorithm](#steps-in-kosarajus-algorithm)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [Input Format](#input-format)
    - [Steps](#steps)
    - [Example Input](#example-input)
    - [Example Output](#example-output)

---

## Introduction

A **Strongly Connected Component (SCC)** in a directed graph is a maximal subset of vertices such that every vertex is reachable from any other vertex in the subset. **Kosaraju's Algorithm** is an efficient method to find SCCs using Depth First Search (DFS).

### Features of Kosaraju's Algorithm

1. Runs in **\(O(V + E)\)** time, where \(V\) is the number of vertices and \(E\) is the number of edges.
2. Uses the concept of the **transpose of a graph** and **two passes of DFS**.

---

## Problem Description

You are given:

- A directed graph represented as an adjacency list `adj`.

### Task

Find the number of **Strongly Connected Components** (SCCs) in the graph.

---

## Examples

### Example 1

**Input:**

```bash
adj = [[2, 3], [0], [1], [4], []]
```

**Output:**

``` bash
3
```

**Explanation:**
The SCCs are `{0, 1, 2}`, `{3}`, and `{4}`.

---

### Example 2

**Input:**

```bash
adj = [[1], [2], [0]]
```

**Output:**

```bash
1
```

**Explanation:**
All vertices are part of a single SCC.

---

### Example 3

**Input:**

```bash
adj = [[1], []]
```

**Output:**

```bash
2
```

**Explanation:**
The SCCs are `{0}` and `{1}`.

---

## Constraints

- \( 2 \leq \text{adj.size()} \leq 10^6 \)
- \( 0 \leq \text{edges} \leq \text{adj.size()} - 1 \)

---

## Approach

Kosaraju's algorithm identifies SCCs using **two passes of DFS** and the **transpose of the graph**.

---

### Steps in Kosaraju's Algorithm

1. **First Pass (DFS to Fill Stack):**
   - Perform a DFS on the original graph.
   - Push vertices onto a stack in the order of their finishing times (when DFS completes for a vertex).

2. **Transpose the Graph:**
   - Reverse all edges in the graph to create the transposed graph.

3. **Second Pass (DFS on Transposed Graph):**
   - Perform a DFS on the transposed graph in the order defined by the stack.
   - Count the number of DFS calls made during this process; each call corresponds to one SCC.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int>& visited, vector<vector<int>>& adj, stack<int>& st) {
        visited[node] = 1;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, st);
            }
        }
        st.push(node);
    }

    void dfsRev(int node, vector<int>& visited, vector<vector<int>>& adjRev) {
        visited[node] = 1;
        for (auto neighbor : adjRev[node]) {
            if (!visited[neighbor]) {
                dfsRev(neighbor, visited, adjRev);
            }
        }
    }

public:
    int kosaraju(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, st);
            }
        }

        vector<vector<int>> adjRev(V);
        for (int i = 0; i < V; i++) {
            for (auto neighbor : adj[i]) {
                adjRev[neighbor].push_back(i);
            }
        }

        fill(visited.begin(), visited.end(), 0);
        int sccCount = 0;

        while (!st.empty()) {
            int node = st.top();
            st.pop();

            if (!visited[node]) {
                sccCount++;
                dfsRev(node, visited, adjRev);
            }
        }

        return sccCount;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int node, boolean[] visited, List<List<Integer>> adj, Stack<Integer> stack) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited, adj, stack);
            }
        }
        stack.push(node);
    }

    private void dfsRev(int node, boolean[] visited, List<List<Integer>> adjRev) {
        visited[node] = true;
        for (int neighbor : adjRev.get(node)) {
            if (!visited[neighbor]) {
                dfsRev(neighbor, visited, adjRev);
            }
        }
    }

    public int kosaraju(int V, List<List<Integer>> adj) {
        boolean[] visited = new boolean[V];
        Stack<Integer> stack = new Stack<>();

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, visited, adj, stack);
            }
        }

        List<List<Integer>> adjRev = new ArrayList<>();
        for (int i = 0; i < V; i++) {
            adjRev.add(new ArrayList<>());
        }

        for (int i = 0; i < V; i++) {
            for (int neighbor : adj.get(i)) {
                adjRev.get(neighbor).add(i);
            }
        }

        Arrays.fill(visited, false);
        int sccCount = 0;

        while (!stack.isEmpty()) {
            int node = stack.pop();

            if (!visited[node]) {
                sccCount++;
                dfsRev(node, visited, adjRev);
            }
        }

        return sccCount;
    }
}

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int V = sc.nextInt();
            int E = sc.nextInt();
            List<List<Integer>> adj = new ArrayList<>();

            for (int i = 0; i < V; i++) {
                adj.add(new ArrayList<>());
            }

            for (int i = 0; i < E; i++) {
                int u = sc.nextInt();
                int v = sc.nextInt();
                adj.get(u).add(v);
            }

            Solution sol = new Solution();
            System.out.println(sol.kosaraju(V, adj));
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **First DFS (Filling Stack):** \(O(V + E)\).
2. **Transpose Creation:** \(O(V + E)\).
3. **Second DFS (Finding SCCs):** \(O(V + E)\).

**Total Time Complexity:** \(O(V + E)\).

---

### Space Complexity

1. **Visited Array:** \(O(V)\).
2. **Stack for DFS Order:** \(O(V)\).
3. **Transposed Graph:** \(O(V + E)\).

**Total Space Complexity:** \(O(V + E)\).

---

## How to Run the Code

### Input Format

1. Enter the number of test cases, \(t\).
2. For each test case:
   - Enter the number of vertices \(V\) and edges \(E\).
   - Provide \(E\) pairs of integers \(u, v\), representing directed edges.

### Steps

1. **C++**
   - Compile the code: `g++ -std=c++17 filename.cpp`.
   - Run the program: `./a.out`.

2. **Java**
   - Compile the code: `javac Main.java`.
   -

 Run the program: `java Main`.

### Example Input

```bash
1
5 5
0 1
1 2
2 0
3 4
4 3
```

### Example Output

```bash
2
```
