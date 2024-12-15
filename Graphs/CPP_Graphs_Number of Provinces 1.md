# Number of Provinces

<!-- markdownlint-disable MD052 -->
<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Number of Provinces](#number-of-provinces)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Statement](#problem-statement)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Algorithm](#algorithm)
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
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Java Solution Using Union-Find](#java-solution-using-union-find)
      - [Explanation](#explanation)
      - [Implementation](#implementation)
      - [Example Walkthrough](#example-walkthrough)
      - [Complexity Analysis](#complexity-analysis-1)
      - [How to Run the Code](#how-to-run-the-code-1)
    - [C++ Union Find](#c-union-find)

---

## Introduction

A **province** is a group of cities that are either directly or indirectly connected, meaning there is a path between every pair of cities within the group. The task is to determine the number of such provinces in a given set of cities, represented as an adjacency matrix.

---

## Problem Statement

Given an \(n \times n\) adjacency matrix `isConnected`, where:

- `isConnected[i][j] = 1` if city \(i\) is directly connected to city \(j\),
- `isConnected[i][j] = 0` otherwise,
  
return the total number of provinces.

---

## Examples

### Example 1

**Input:**  
`isConnected = [[1,1,0],[1,1,0],[0,0,1]]`  

**Output:**  
`2`  

**Explanation:**  

- Cities 0 and 1 are connected directly.  
- City 2 is not connected to any other city.  
Thus, there are two provinces.

---

### Example 2

**Input:**  
`isConnected = [[1,0,0],[0,1,0],[0,0,1]]`  

**Output:**  
`3`  

**Explanation:**  
Each city is isolated, forming three separate provinces.

---

## Constraints

- \(1 \leq n \leq 200\)
- \(n == \text{isConnected.length}\)
- \(n == \text{isConnected}[i].\text{length}\)
- \( \text{isConnected}[i][j] \) is \(0\) or \(1\).
- \( \text{isConnected}[i][i] = 1\)
- \( \text{isConnected}[i][j] = \text{isConnected}[j][i]\)

---

## Algorithm

### Steps

1. Convert the adjacency matrix `isConnected` into an adjacency list.
   - Iterate through the matrix to build an adjacency list where each city points to its directly connected cities.
2. Use a Depth First Search (DFS) to explore all connected components in the graph.
   - For each unvisited city, start a DFS and mark all reachable cities as visited.
   - Increment the province count for each DFS initiation.
3. Return the total count of provinces.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> adj[], vector<int>& visited) {
        visited[node] = 1; // Mark the current node as visited
        
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited); // Recursively visit all unvisited neighbors
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size(); // Number of cities
        vector<int> adj[V]; // Adjacency list

        // Build the adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i); // Since the graph is undirected
                }
            }
        }

        vector<int> visited(V, 0); // Visited array
        int provinces = 0; // Province counter

        // Traverse all cities
        for (int i = 0; i < V; i++) {
            if (!visited[i]) { // If city is not visited
                provinces++;  // Increment province count
                dfs(i, adj, visited); // Perform DFS to visit all connected cities
            }
        }

        return provinces; // Return the total number of provinces
    }
};

// Driver Code
int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    Solution obj;
    cout << "Number of Provinces: " << obj.findCircleNum(isConnected) << endl;

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int node, List<List<Integer>> adj, boolean[] visited) {
        visited[node] = true; // Mark the current node as visited

        for (int neighbor : adj.get(node)) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited); // Recursively visit all unvisited neighbors
            }
        }
    }

    public int findCircleNum(int[][] isConnected) {
        int V = isConnected.length; // Number of cities
        List<List<Integer>> adj = new ArrayList<>(); // Adjacency list

        // Build the adjacency list
        for (int i = 0; i < V; i++) {
            adj.add(new ArrayList<>());
        }
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adj.get(i).add(j);
                    adj.get(j).add(i); // Since the graph is undirected
                }
            }
        }

        boolean[] visited = new boolean[V]; // Visited array
        int provinces = 0; // Province counter

        // Traverse all cities
        for (int i = 0; i < V; i++) {
            if (!visited[i]) { // If city is not visited
                provinces++;  // Increment province count
                dfs(i, adj, visited); // Perform DFS to visit all connected cities
            }
        }

        return provinces; // Return the total number of provinces
    }

    // Driver Code
    public static void main(String[] args) {
        int[][] isConnected = {
            {1, 1, 0},
            {1, 1, 0},
            {0, 0, 1}
        };

        Solution obj = new Solution();
        System.out.println("Number of Provinces: " + obj.findCircleNum(isConnected));
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Construction:** \(O(V^2)\), where \(V\) is the number of cities (matrix size).
- **DFS Traversal:** \(O(V + E)\), where \(E\) is the number of edges.

### Space Complexity

- **Adjacency List:** \(O(V + E)\)
- **Visited Array:** \(O(V)\)
- **Recursive Stack Space:** \(O(V)\) in the worst case.

---

## How to Run the Code

### For C++

1. Copy the code into a file, e.g., `provinces.cpp`.
2. Compile the code:

   ```bash
   g++ -o provinces provinces.cpp
   ```

3. Run the program:

   ```bash
   ./provinces
   ```

### For Java

1. Copy the code into a file named `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[node] = true; // Mark the node as visited
        for (int neighbor = 0; neighbor < isConnected.size(); ++neighbor) {
            if (isConnected[node][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited); // Visit all connected neighbors
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(); // Number of nodes (cities)
        vector<bool> visited(n, false); // Track visited nodes
        int provinces = 0; // Count of connected components

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                ++provinces; // Found a new province
                dfs(i, isConnected, visited); // Traverse all nodes in this province
            }
        }

        return provinces;
    }
};
```

### Java Solution Using Union-Find

#### Explanation

The Union-Find (Disjoint Set Union) algorithm is used to find connected components in a graph efficiently. This approach leverages two key techniques:

1. **Path Compression**: Reduces the tree height during the `find` operation by pointing a node directly to its root.
2. **Union by Rank**: Ensures smaller trees are merged under larger trees to maintain balance.

In the problem, each city is a node, and direct connections are edges. Using Union-Find, we group all connected nodes into the same component and count the total number of components (provinces).

---

#### Implementation

```java
public class Solution {
    // Union-Find class
    class UnionFind {
        private int count;           // Number of connected components
        private int[] parent;        // Parent array
        private int[] rank;          // Rank array to maintain tree height

        public UnionFind(int n) {
            count = n;               // Initially, all nodes are separate components
            parent = new int[n];
            rank = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;       // Each node is its own parent initially
            }
        }

        // Find operation with path compression
        public int find(int p) {
            while (p != parent[p]) {
                parent[p] = parent[parent[p]];  // Path compression by halving
                p = parent[p];
            }
            return p;
        }

        // Union operation with union by rank
        public void union(int p, int q) {
            int rootP = find(p);
            int rootQ = find(q);

            if (rootP == rootQ) return;  // Already in the same component

            if (rank[rootQ] > rank[rootP]) {
                parent[rootP] = rootQ;   // Attach smaller rank tree under larger rank tree
            } else {
                parent[rootQ] = rootP;
                if (rank[rootP] == rank[rootQ]) {
                    rank[rootP]++;      // Increment rank if both ranks are equal
                }
            }
            count--;                     // Reduce the number of components
        }

        // Return the number of components
        public int count() {
            return count;
        }
    }

    // Function to find the number of provinces
    public int findCircleNum(int[][] M) {
        int n = M.length;                  // Number of cities
        UnionFind uf = new UnionFind(n);   // Initialize Union-Find

        // Iterate through the upper triangular matrix to avoid duplicate processing
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (M[i][j] == 1) {        // If there's a direct connection
                    uf.union(i, j);        // Merge the components
                }
            }
        }

        return uf.count();                 // Return the total number of provinces
    }
}
```

---

#### Example Walkthrough

**Input:**  
`M = [[1,1,0],[1,1,0],[0,0,1]]`

1. Initialize Union-Find for \( n = 3 \).
   - `parent = [0, 1, 2]`, `rank = [0, 0, 0]`, `count = 3`.

2. Process connections:
   - For \( (0, 1) \): Union \( 0 \) and \( 1 \).
     - `parent = [0, 0, 2]`, `rank = [1, 0, 0]`, `count = 2`.
   - For \( (1, 2) \): No connection, skip.
   - For \( (2, 3) \): No connection, skip.

3. Final `count = 2`.

**Output:**  
`2`

---

#### Complexity Analysis

**Time Complexity:**

- Building the adjacency relationships: \(O(n^2)\), where \(n\) is the number of cities.
- Union-Find operations: Nearly \(O(1)\) per operation due to path compression and union by rank. Total \(O(n^2)\).

**Space Complexity:**

- Parent and rank arrays: \(O(n)\).

---

#### How to Run the Code

1. Copy the code into a file named `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program (assuming a test class is added to run examples):

   ```bash
   java Solution
   ```

---

### C++ Union Find

- In union we just make any element leader of any group and make other elements as a group member.

```cpp
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};
```

```cpp
class Solution {
public:
    
    //It will be use to store groups
    vector<int> v;
    
    //Find the leader of any group in which x lies
    //if not lie in any group then it is self leader
    int parent(int x)
    {
        //self leader
        if(v[x]==-1) return x; 
        //find the leader of self parent
        return v[x]=parent(v[x]);
    }
    
    //Adding 2 friends in a group
    void _union(int a,int b)
    {
        //find the leader of both a and b
        int p_a=parent(a),p_b=parent(b);
        
        //if already in same group, i.e leader of both of them are same then return
        if(p_a==p_b) return; 
        /*
         if both of them are from different group then add both the groups 
         and make a single common group
         We can do this by -> leader of 1st group is member of 2nd group 
         and now main leader of whole group is leader of 2nd member
        */ 
        v[p_a]=p_b; //v[p_a] will store the index of leader of whole group
    }
    
    int findCircleNum(vector<vector<int>>& M) { 
        int n=M.size();
        v=vector<int> (n,-1);//there will be maximum n group, mark all as a leader
        
        //making group
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(M[i][j])  //if i is friend of j, add them in a group
                { 
                    //if i is in any group then add j in that group
                    //or vice-versa
                    _union(i,j);  //Add them in a group
                }
            }
        }
        int c=0; 
        
        //counting group
        for(int i=0;i<n;i++)
        {
            if(v[i]==-1) c++; //counting total number of parents
        }
        return c; 
    }
};
```
