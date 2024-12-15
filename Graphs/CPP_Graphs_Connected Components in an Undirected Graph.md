# Connected Components in an Undirected Graph

## Table of Contents

- [Connected Components in an Undirected Graph](#connected-components-in-an-undirected-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Depth First Search (DFS) Approach](#depth-first-search-dfs-approach)
  - [Implementation](#implementation)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
    - [Python Implementation](#python-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
    - [For Python](#for-python)

---

## Introduction

The goal is to determine all the connected components in an undirected graph. A connected component is a subgraph where all vertices are connected to each other, either directly or indirectly. The graph is represented by `v` vertices and `e` edges, and the task is to return all connected components as lists of vertices.

---

## Problem Description

We are given:

1. `v`: Number of vertices.
2. `e`: Number of edges.
3. `edges`: A list of edge pairs representing the graph.

### Examples

#### Example 1

**Input:**  
`e = 3`, `v = 5`, `edges = [{0, 1}, {2, 1}, {3, 4}]`  
**Output:**  
`[[0, 1, 2], [3, 4]]`  
**Explanation:**  
There are two connected components:  

- Component 1: `0 → 1 → 2`
- Component 2: `3 → 4`

#### Example 2

**Input:**  
`e = 5`, `v = 7`, `edges = [{0, 1}, {6, 1}, {2, 4}, {2, 3}, {3, 4}]`  
**Output:**  
`[[0, 1, 6], [2, 3, 4], [5]]`  
**Explanation:**  
There are three connected components:

- Component 1: `0 → 1 → 6`
- Component 2: `2 → 3 → 4`
- Component 3: `5` (isolated)

---

## Constraints

- `0 <= edges[i][0], edges[i][1] < v`
- `1 <= v <= 10^5`
- `e <= 10^5`

---

## Approach

We will use a **Depth First Search (DFS)** approach to explore the graph and find all connected components.

### Depth First Search (DFS) Approach

- We treat the graph as an adjacency list.
- We iterate through all the nodes, and for each unvisited node, we perform a DFS traversal to find all nodes in its connected component.
- Once the connected component is found, we store it and mark all the nodes as visited.

---

## Implementation

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& component, vector<bool>& visited) {
        visited[node] = true;
        component.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, component, visited);
            }
        }
    }

public:
    vector<vector<int>> connectedComponents(int v, vector<vector<int>>& edges) {
        vector<vector<int>> adj(v);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(v, false);
        vector<vector<int>> result;

        for (int i = 0; i < v; ++i) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, adj, component, visited);
                sort(component.begin(), component.end());
                result.push_back(component);
            }
        }

        return result;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int e, v;
        cin >> e >> v;
        vector<vector<int>> edges(e, vector<int>(2));
        for (int i = 0; i < e; i++) {
            cin >> edges[i][0] >> edges[i][1];
        }

        Solution obj;
        vector<vector<int>> res = obj.connectedComponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto& component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int node, List<List<Integer>> adj, List<Integer> component, boolean[] visited) {
        visited[node] = true;
        component.add(node);
        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, component, visited);
            }
        }
    }

    public List<List<Integer>> connectedComponents(int v, List<List<Integer>> edges) {
        List<List<Integer>> adj = new ArrayList<>(v);
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }

        for (List<Integer> edge : edges) {
            adj.get(edge.get(0)).add(edge.get(1));
            adj.get(edge.get(1)).add(edge.get(0));
        }

        boolean[] visited = new boolean[v];
        List<List<Integer>> result = new ArrayList<>();

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                List<Integer> component = new ArrayList<>();
                dfs(i, adj, component, visited);
                Collections.sort(component);
                result.add(component);
            }
        }

        return result;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int e = sc.nextInt();
            int v = sc.nextInt();
            List<List<Integer>> edges = new ArrayList<>();
            for (int i = 0; i < e; i++) {
                List<Integer> edge = new ArrayList<>();
                edge.add(sc.nextInt());
                edge.add(sc.nextInt());
                edges.add(edge);
            }

            Solution obj = new Solution();
            List<List<Integer>> res = obj.connectedComponents(v, edges);
            Collections.sort(res, (a, b) -> Integer.compare(a.get(0), b.get(0)));
            for (List<Integer> component : res) {
                for (int node : component) {
                    System.out.print(node + " ");
                }
                System.out.println();
            }
            System.out.println("~");
        }
        sc.close();
    }
}
```

### Python Implementation

```python
class Solution:
    def dfs(self, node, adj, component, visited):
        visited[node] = True
        component.append(node)
        for neighbor in adj[node]:
            if not visited[neighbor]:
                self.dfs(neighbor, adj, component, visited)

    def connectedComponents(self, v, edges):
        adj = [[] for _ in range(v)]
        for edge in edges:
            adj[edge[0]].append(edge[1])
            adj[edge[1]].append(edge[0])

        visited = [False] * v
        result = []

        for i in range(v):
            if not visited[i]:
                component = []
                self.dfs(i, adj, component, visited)
                component.sort()
                result.append(component)

        return result

# Driver code
t = int(input())
for _ in range(t):
    e, v = map(int, input().split())
    edges = [list(map(int, input().split())) for _ in range(e)]
    
    obj = Solution()
    res = obj.connectedComponents(v, edges)
    res.sort(key=lambda x: x[0])  # Sort by the first element of each component
    for component in res:
        print(" ".join(map(str, component)))
    print("~")
```

---

## Complexity Analysis

### Time Complexity

- **C++/Java/Python**:  
  The time complexity is dominated by the DFS traversal. The DFS will visit each node exactly once, and for each node, we will check all its neighbors. This results in a time complexity of **O(V + E)**, where `V` is the number of vertices and `E` is the number of edges.
  
  Additionally, sorting the components adds a complexity of **O(V log V)** in the worst case, as we need to sort the list of nodes within each component.

Thus, the overall time complexity is:

- **O(V + E + V log V)**

### Space Complexity

- The space complexity is dominated by the space used for the adjacency list and the visited list. The adjacency list takes **O(V + E)** space, and the visited list takes **O(V)** space.

Thus, the overall space complexity is:

- **O(V + E)**

---

## How to Run the Code

### For C++

1. Compile the C++ code using:

   ```bash
   g++ -o connected_components connected_components.cpp
   ```

2. Run the program:

   ```bash
   ./connected_components
   ```

### For Java

1. Compile the Java code using:

   ```bash
   javac Main.java
   ```

2. Run the program:

   ```bash
   java Main
   ```

### For Python

1. Run the Python code directly:

   ```bash
   python3 connected_components.py
   ```
