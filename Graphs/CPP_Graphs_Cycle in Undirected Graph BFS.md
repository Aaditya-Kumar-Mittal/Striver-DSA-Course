# Detect Cycle in an Undirected Graph

## Table of Contents

- [Detect Cycle in an Undirected Graph](#detect-cycle-in-an-undirected-graph)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Statement](#problem-statement)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Algorithm](#algorithm)
    - [Breadth-First Search (BFS) Approach](#breadth-first-search-bfs-approach)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Using DSU in C++](#using-dsu-in-c)

---

## Introduction

The **Detect Cycle in an Undirected Graph** problem requires determining whether an undirected graph contains at least one cycle. A graph cycle exists if there is a path where the starting and ending vertices are the same.

---

## Problem Statement

Given an undirected graph represented as an adjacency list, where each vertex is labeled from `0` to `V-1`, determine if the graph contains any cycles. The adjacency list uses zero-based indexing.

---

## Examples

### Example 1

**Input:**  
`adj = [[1], [0,2,4], [1,3], [2,4], [1,3]]`

**Output:**  
`1`

**Explanation:**  
A cycle exists: \(1 \rightarrow 2 \rightarrow 3 \rightarrow 4 \rightarrow 1\).

---

### Example 2

**Input:**  
`adj = [[], [2], [1,3], [2]]`

**Output:**  
`0`

**Explanation:**  
No cycles exist in the graph.

---

## Constraints

- \(1 \leq \text{adj.size()} \leq 10^5\)

---

## Algorithm

### Breadth-First Search (BFS) Approach

1. Use a `visited` array to mark visited nodes.
2. Traverse all unvisited nodes using BFS:
   - If the current node connects back to a previously visited node that is not its parent, a cycle exists.
3. Return `true` if any cycle is detected; otherwise, return `false`.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool detectCycle(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1}); // {node, parent}

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto adjacentNode : adj[node]) {
                if (!vis[adjacentNode]) {
                    vis[adjacentNode] = 1;
                    q.push({adjacentNode, node});
                } else if (parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> vis(V, 0);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detectCycle(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }
};

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
        cout << obj.isCycle(adj) << "\n";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private boolean detectCycle(int src, List<List<Integer>> adj, int[] vis) {
        vis[src] = 1;
        Queue<int[]> q = new LinkedList<>();
        q.add(new int[]{src, -1}); // {node, parent}

        while (!q.isEmpty()) {
            int[] pair = q.poll();
            int node = pair[0];
            int parent = pair[1];

            for (int adjacentNode : adj.get(node)) {
                if (vis[adjacentNode] == 0) {
                    vis[adjacentNode] = 1;
                    q.add(new int[]{adjacentNode, node});
                } else if (parent != adjacentNode) {
                    return true;
                }
            }
        }
        return false;
    }

    public boolean isCycle(int V, List<List<Integer>> adj) {
        int[] vis = new int[V];

        for (int i = 0; i < V; i++) {
            if (vis[i] == 0) {
                if (detectCycle(i, adj, vis)) {
                    return true;
                }
            }
        }
        return false;
    }

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
            System.out.println(obj.isCycle(V, adj) ? "1" : "0");
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **BFS Traversal:** \( O(V + E) \), where \( V \) is the number of vertices and \( E \) is the number of edges.
- **Total:** \( O(V + E) \).

### Space Complexity

- **Visited Array:** \( O(V) \).
- **Queue Storage:** \( O(V) \) in the worst case.
- **Total:** \( O(V) \).

---

## How to Run the Code

### For C++

1. Copy the C++ implementation into a `.cpp` file.
2. Compile using a C++ compiler:

   ```bash
   g++ -o detectCycle detectCycle.cpp
   ```

3. Run the executable:

   ```bash
   ./detectCycle
   ```

### For Java

1. Copy the Java implementation into a file named `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```

## Other Solutions

### Using DSU in C++

```cpp
class DSU
{
public:
    vector<int> par, lvl;

    DSU(int n)
    {
        par.resize(n,-1);
        lvl.resize(n,0);
    }

    int find(int node)
    {
        if (par[node] == -1)
            return node;

        int leader = find(par[node]);
        par[node] = leader;
        return leader;
    }

    void union_by_lvl(int node1, int node2)
    {
        int leader1 = find(node1);
        int leader2 = find(node2);

        if (lvl[leader1] > lvl[leader2])
            par[leader2] = leader1;
        else if (lvl[leader1] < lvl[leader2])
            par[leader1] = leader2;
        else
        {
            par[leader2] = leader1;
            lvl[leader1]++;
        }
    }
};

class Solution
{
public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>> &adj)
    {
        // Code here
        int n = adj.size();
        DSU dsu(n);

        for (int u = 0; u < n; u++)
        {
            for (int v : adj[u])
            {
                if(v>u){
                    int leader1=dsu.find(u);
                    int leader2=dsu.find(v);
    
                    if(leader1 == leader2)
                        return 1;
                    else
                        dsu.union_by_lvl(u,v);
                }
            }
        }
        return false;
    }
};
```
