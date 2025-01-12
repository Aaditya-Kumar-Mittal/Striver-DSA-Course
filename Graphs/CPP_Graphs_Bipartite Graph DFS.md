# Bipartite Graph

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Bipartite Graph](#bipartite-graph)
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

A **bipartite graph** is a graph that can be divided into two disjoint sets such that:

1. All edges connect vertices from one set to the other.
2. No edges exist between vertices within the same set.

The task is to determine if a given graph (represented as an adjacency list) is bipartite or not using **DFS**.

---

## Problem Description

- **Input:**  
  An adjacency list of a graph `adj`, where `adj[i]` contains all the vertices adjacent to vertex `i`.

- **Output:**  
  Return `true` if the graph is bipartite, otherwise `false`.

---

## Examples

### Example 1

**Input:**  

```text
adj = [[1], [0, 2], [1]]
```

**Output:**  

```text
true
```

**Explanation:**  
The graph can be colored using two colors, so it is bipartite.

---

### Example 2

**Input:**  

```text
adj = [[2, 3], [2], [0, 1, 3], [0, 2]]
```

**Output:**  

```text
false
```

**Explanation:**  
The graph cannot be colored using two colors, so it is not bipartite.

---

## Constraints

- \(1 \leq \text{adj.size()} \leq 10^4\)
- \(1 \leq \text{adj}[i][j] \leq 10^4\)

---

## Approach

### Steps

1. **DFS Coloring:**  
   Use a **DFS** approach to color the graph.
   - Color the current node with color `0`.
   - Assign the opposite color to its adjacent nodes (`1` for `0` and `0` for `1`).
   - If a node is already colored and its color matches the current node's color, the graph is not bipartite.

2. **Iterate Through All Nodes:**  
   Since the graph may be disconnected, traverse each node to check for bipartiteness.

3. **Handle Disconnected Components:**  
   Ensure all connected components of the graph are bipartite.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool dfs(int node, int color, vector<vector<int>>& adj, vector<int>& colors) {
        colors[node] = color; // Color the current node

        for (auto neighbor : adj[node]) {
            // If the neighbor is uncolored, recursively color it with the opposite color
            if (colors[neighbor] == -1) {
                if (!dfs(neighbor, 1 - color, adj, colors)) {
                    return false;
                }
            } 
            // If the neighbor is already colored and has the same color, return false
            else if (colors[neighbor] == color) {
                return false;
            }
        }
        return true; // Successfully colored this component
    }

public:
    bool isBipartite(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> colors(n, -1); // Initialize all nodes as uncolored

        for (int i = 0; i < n; i++) {
            // If the node is uncolored, start DFS from it
            if (colors[i] == -1) {
                if (!dfs(i, 0, adj, colors)) {
                    return false;
                }
            }
        }
        return true;
    }
};

// Driver Code
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isBipartite(adj);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
```

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
  bool dfs(int node, int col, vector<vector<int>> &adj, vector<int> &color)
  {
    color[node] = col;

    for (auto it : adj[node])
    {
      if (color[it] == -1)
      {
        if (dfs(it, !col, adj, color) == false)
          return false;
      }
      else if (color[it] == col)
      {
        return false;
      }
    }

    return true;
  }

public:
  bool isBipartite(vector<vector<int>> &adj)
  {
    // Code here
    int n = adj.size();

    vector<int> color(n, -1);

    for (int i = 0; i < n; i++)
    {
      if (color[i] == -1)
      {
        if (dfs(i, 0, adj, color) == false)
          return false;
      }
    }

    return true;
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++)
    {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    Solution obj;
    bool ans = obj.isBipartite(adj);
    if (ans)
      cout << "true\n";
    else
      cout << "false\n";

    cout << "~"
         << "\n";
  }
  return 0;
}
// } Driver Code Ends
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private boolean dfs(int node, int color, List<List<Integer>> adj, int[] colors) {
        colors[node] = color; // Color the current node

        for (int neighbor : adj.get(node)) {
            // If the neighbor is uncolored, recursively color it with the opposite color
            if (colors[neighbor] == -1) {
                if (!dfs(neighbor, 1 - color, adj, colors)) {
                    return false;
                }
            } 
            // If the neighbor is already colored and has the same color, return false
            else if (colors[neighbor] == color) {
                return false;
            }
        }
        return true; // Successfully colored this component
    }

    public boolean isBipartite(List<List<Integer>> adj) {
        int n = adj.size();
        int[] colors = new int[n]; // Initialize all nodes as uncolored
        Arrays.fill(colors, -1);

        for (int i = 0; i < n; i++) {
            // If the node is uncolored, start DFS from it
            if (colors[i] == -1) {
                if (!dfs(i, 0, adj, colors)) {
                    return false;
                }
            }
        }
        return true;
    }

    // Driver Code
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
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
                adj.get(v).add(u);
            }
            Solution obj = new Solution();
            boolean ans = obj.isBipartite(adj);
            System.out.println(ans ? "true" : "false");
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DFS Traversal:** \(O(V + E)\), where \(V\) is the number of vertices and \(E\) is the number of edges.

### Space Complexity

- **DFS Stack/Colors Array:** \(O(V)\)

---

## How to Run the Code

### For C++

1. Compile the program:

   ```bash
   g++ -o solution solution.cpp
   ```

2. Run the program:

   ```bash
   ./solution
   ```

### For Java

1. Compile the program:

   ```bash
   javac Solution.java
   ```

2. Run the program:

   ```bash
   java Solution
   ```
