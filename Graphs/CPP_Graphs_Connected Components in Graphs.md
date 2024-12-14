# Connected Components in Graphs

## Table of Contents

- [Connected Components in Graphs](#connected-components-in-graphs)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Example Graph](#example-graph)
  - [Understanding Connected Components](#understanding-connected-components)
    - [Visualization](#visualization)
  - [Graph Traversal for Connected Components](#graph-traversal-for-connected-components)
    - [Key Insight](#key-insight)
  - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Python Implementation](#python-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Introduction

Graphs can be connected or disconnected. A **connected graph** has a path between every pair of vertices. A **disconnected graph** can have multiple connected subgraphs, called **connected components**.  

### Example Graph

Given an undirected graph with 10 nodes and 8 edges:

- Edges: (1,2), (1,3), (2,4), (4,3), (5,6), (5,7), (6,7), (8,9)

This graph consists of **4 connected components**:

1. Component 1: Nodes {1, 2, 3, 4}
2. Component 2: Nodes {5, 6, 7}
3. Component 3: Nodes {8, 9}
4. Component 4: Node {10}

---

## Understanding Connected Components

A **connected component** is a subset of the graph such that:

- Every pair of vertices in the subset has a path connecting them.
- Adding any other vertex to the subset breaks the connectivity property.

### Visualization

In the example above:

- Nodes {1, 2, 3, 4} form one connected component.
- Nodes {5, 6, 7} form another component, and so on.

Even if the graph is in multiple pieces, it is still considered one graph when described in terms of connected components.

---

## Graph Traversal for Connected Components

Graph traversal algorithms like **Depth First Search (DFS)** or **Breadth First Search (BFS)** can explore a graph. These algorithms typically use a **visited array** to track which nodes have already been visited.

### Key Insight

- If we call `traversal(1)`, it will visit only nodes in the connected component containing node 1 (e.g., {1, 2, 3, 4}).
- To explore the entire graph, including disconnected components, we must iterate over all nodes and start a new traversal from any unvisited node.

---

## Algorithm

1. **Initialize Data Structures**:
   - A `visited` array of size \( n+1 \) (for \( n \) nodes), initialized to 0.
   - An adjacency list or adjacency matrix for the graph representation.

2. **Traverse All Nodes**:
   - For every node \( u \):
     - If \( u \) is not visited, start a new traversal (DFS or BFS).
     - Mark all nodes in the connected component of \( u \) as visited.

3. **Count Connected Components**:
   - Increment a counter every time a new traversal starts.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    Graph(int V) {
        this->V = V;
        adj.resize(V + 1);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // Undirected graph
    }

    void DFS(int node, vector<bool>& visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFS(neighbor, visited);
            }
        }
    }

    int countConnectedComponents() {
        vector<bool> visited(V + 1, false);
        int components = 0;

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                components++;
                DFS(i, visited);
            }
        }

        return components;
    }
};

int main() {
    int V = 10; // Number of vertices
    int E = 8;  // Number of edges
    vector<pair<int, int>> edges = {{1, 2}, {1, 3}, {2, 4}, {4, 3}, {5, 6}, {5, 7}, {6, 7}, {8, 9}};

    Graph g(V);

    for (auto edge : edges) {
        g.addEdge(edge.first, edge.second);
    }

    cout << "Number of connected components: " << g.countConnectedComponents() << endl;
    return 0;
}
```

---

### Python Implementation

```python
class Graph:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V + 1)]

    def add_edge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)  # Undirected graph

    def dfs(self, node, visited):
        visited[node] = True
        for neighbor in self.adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, visited)

    def count_connected_components(self):
        visited = [False] * (self.V + 1)
        components = 0

        for i in range(1, self.V + 1):
            if not visited[i]:
                components += 1
                self.dfs(i, visited)

        return components


# Driver Code
V = 10  # Number of vertices
E = 8   # Number of edges
edges = [(1, 2), (1, 3), (2, 4), (4, 3), (5, 6), (5, 7), (6, 7), (8, 9)]

g = Graph(V)
for u, v in edges:
    g.add_edge(u, v)

print("Number of connected components:", g.count_connected_components())
```

---

### Java Implementation

```java
import java.util.*;

class Graph {
    private int V; // Number of vertices
    private List<List<Integer>> adj; // Adjacency list

    // Constructor
    public Graph(int V) {
        this.V = V;
        adj = new ArrayList<>();
        for (int i = 0; i <= V; i++) {
            adj.add(new ArrayList<>());
        }
    }

    // Method to add an edge to the graph
    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u); // Undirected graph
    }

    // DFS helper method
    private void dfs(int node, boolean[] visited) {
        visited[node] = true;
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, visited);
            }
        }
    }

    // Method to count connected components
    public int countConnectedComponents() {
        boolean[] visited = new boolean[V + 1];
        int components = 0;

        for (int i = 1; i <= V; i++) {
            if (!visited[i]) {
                components++;
                dfs(i, visited);
            }
        }

        return components;
    }

    public static void main(String[] args) {
        int V = 10; // Number of vertices
        int E = 8;  // Number of edges

        int[][] edges = {
            {1, 2}, {1, 3}, {2, 4}, {4, 3},
            {5, 6}, {5, 7}, {6, 7}, {8, 9}
        };

        Graph g = new Graph(V);

        for (int[] edge : edges) {
            g.addEdge(edge[0], edge[1]);
        }

        System.out.println("Number of connected components: " + g.countConnectedComponents());
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **Graph Construction**:
   - Adjacency List: \( O(E + V) \)
2. **DFS Traversal**:
   - \( O(E + V) \), since each edge and vertex is processed once.

### Space Complexity

- **Adjacency List**: \( O(E + V) \)
- **Visited Array**: \( O(V) \)
- **Call Stack (DFS)**: \( O(V) \) in the worst case for a linear graph.

---

This approach ensures that all connected components in a graph are correctly identified, even for disconnected or sparse graphs.
