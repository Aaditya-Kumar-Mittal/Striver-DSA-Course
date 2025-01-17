# Number of Operations to Make Network Connected

## Table of Contents

- [Number of Operations to Make Network Connected](#number-of-operations-to-make-network-connected)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
    - [Key Observations](#key-observations)
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
    - [C++](#c)
    - [Java](#java)
  - [Other Solutions](#other-solutions)
    - [CPP DFS](#cpp-dfs)
    - [Naive Union-Find ~ 23ms](#naive-union-find--23ms)
    - [Union-Find with Path Compression ~ 3ms](#union-find-with-path-compression--3ms)
    - [Union-Find with Path Compression and Union by Size ~ 3ms](#union-find-with-path-compression-and-union-by-size--3ms)
    - [BFS Java](#bfs-java)
    - [Union - Find Java](#union---find-java)

---

## Introduction

The problem involves connecting all computers in a network with the minimum number of operations. Each operation consists of taking an extra cable and using it to connect two disconnected computers. The task is to determine the minimum operations required or return `-1` if it's impossible to connect all computers.

---

## Problem Description

You are given:

- An integer \( n \), representing the number of computers labeled from \( 0 \) to \( n-1 \).
- A list of connections, where each connection is a pair \([a, b]\), indicating a cable between computer \( a \) and computer \( b \).

### Task

- Return the minimum number of operations required to make all computers connected.
- If it is not possible, return `-1`.

### Key Observations

- The network must have at least \( n-1 \) cables to connect \( n \) computers.
- Cables already forming redundant connections (cycles) can be reused to connect other computers.

---

### Examples

#### Example 1

**Input:**

```plaintext
n = 4, connections = [[0, 1], [0, 2], [1, 2]]
```

**Output:**

```plaintext
1
```

**Explanation:**

- Remove the redundant cable between computers \(1\) and \(2\) and use it to connect computer \(3\) to the network.

---

#### Example 2

**Input:**

```plaintext
n = 6, connections = [[0, 1], [0, 2], [0, 3], [1, 2], [1, 3]]
```

**Output:**

```plaintext
2
```

**Explanation:**

- Two operations are needed to connect the remaining computers.

---

#### Example 3

**Input:**

```plaintext
n = 6, connections = [[0, 1], [0, 2], [0, 3], [1, 2]]
```

**Output:**

```plaintext
-1
```

**Explanation:**

- There are not enough cables to connect all computers, even with optimal reuse.

---

### Constraints

- \( 1 \leq n \leq 10^5 \)
- \( 1 \leq \text{connections.length} \leq \min\left(\frac{n \cdot (n-1)}{2}, 10^5\right) \)
- \( \text{connections[i].length} = 2 \)
- \( 0 \leq a_i, b_i < n \)
- \( a_i \neq b_i \)
- No repeated connections or self-loops.

---

## Approach

1. **Validate Basic Requirements**:
   - Ensure the number of cables is at least \( n-1 \). If not, return `-1`.

2. **Disjoint Set Union (DSU)**:
   - Use DSU to group connected components.
   - Count redundant cables that can be reused.

3. **Count Components**:
   - After processing all connections, count the number of connected components.
   - The number of operations required is \( \text{components} - 1 \), if sufficient redundant cables exist.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, sizeArr;

    DisjointSet(int n) {
        parent.resize(n + 1);
        sizeArr.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV) return;

        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) return -1;

        DisjointSet ds(n);
        int countExtras = 0;

        for (auto& it : connections) {
            int u = it[0], v = it[1];
            if (ds.findParent(u) == ds.findParent(v)) {
                countExtras++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int countConnected = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                countConnected++;
            }
        }

        return (countExtras >= countConnected - 1) ? countConnected - 1 : -1;
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> connections(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> connections[i][0] >> connections[i][1];
    }

    Solution obj;
    cout << obj.makeConnected(n, connections) << endl;

    return 0;
}
```

```cpp
class Solution {
public:
    int find(int x, int parent[]){
        while(parent[x]!=x){
            x = parent[parent[x]];
        }
        return x;
    }

    void makeUnion(int x, int y, int parent[], int rank[]){
        int parX = find(x, parent);
        int parY = find(y, parent);
        if(parX == parY){
            return;
        }
        else if(rank[parX]<rank[parY]){
            parent[parX] = parY;
        }
        else if(rank[parX]>rank[parY]){
            parent[parY] = parX;
        }
        else{
            parent[parY] = parX;
            rank[parX]++;
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1){
            return -1;
        }
        int parent[n];
        int rank[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(auto con : connections){
            makeUnion(con[0], con[1], parent, rank);
        }
        set<int> groups;
        for(int i=0; i<n; i++){
            int par = find(i, parent);
            groups.insert(par);
        }
        int unions = groups.size();
        return unions-1;
    }
};
```

```cpp
class Solution {
public:
    int find(int x, int parent[]){
        while(parent[x]!=x){
            x = parent[parent[x]];
        }
        return x;
    }

    int makeUnion(int x, int y, int parent[], int rank[]){
        int parX = find(x, parent);
        int parY = find(y, parent);
        if(parX == parY){
            return 0;
        }
        else if(rank[parX]<rank[parY]){
            parent[parX] = parY;
        }
        else if(rank[parX]>rank[parY]){
            parent[parY] = parX;
        }
        else{
            parent[parY] = parX;
            rank[parX]++;
        }
        return 1;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges<n-1){
            return -1;
        }
        int parent[n];
        int rank[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int components = n;
        for(auto con : connections){
            components -= makeUnion(con[0], con[1], parent, rank);
        }
        return components-1;
    }
};
```

```cpp
class DisjointSet {
public:
    vector<int> parent, sizeArr;

    // Constructor to initialize parent and size arrays
    DisjointSet(int n) {
        parent.resize(n + 1);
        sizeArr.resize(n + 1, 1);

        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // Find function with path compression
    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    // Union function by size
    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV)
            return;

        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);

        int countExtras = 0;

        for (auto it : connections) {

            int u = it[0];
            int v = it[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                // They are already connected, having the same parent
                countExtras++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int countConnected = 0;

        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                countConnected++;
            }
        }

        if (countExtras >= (countConnected - 1)) {
            return countConnected - 1;
        }
        return -1;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class DisjointSet {
    private int[] parent, sizeArr;

    public DisjointSet(int n) {
        parent = new int[n];
        sizeArr = new int[n];
        Arrays.fill(sizeArr, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    public int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    public void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);

        if (rootU == rootV) return;

        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
}

class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1;

        DisjointSet ds = new DisjointSet(n);
        int countExtras = 0;

        for (int[] connection : connections) {
            int u = connection[0];
            int v = connection[1];

            if (ds.findParent(u) == ds.findParent(v)) {
                countExtras++;
            } else {
                ds.unionBySize(u, v);
            }
        }

        int countConnected = 0;
        for (int i = 0; i < n; i++) {
            if (ds.findParent(i) == i) {
                countConnected++;
            }
        }

        return (countExtras >= countConnected - 1) ? countConnected - 1 : -1;
    }
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - DSU operations: \(O(E \cdot \alpha(N))\), where \(\alpha\) is the inverse Ackermann function.
  - Counting components: \(O(N)\).
  - Total: \(O(E + N)\).

- **Space Complexity**:
  - DSU arrays: \(O(N)\).

---

## How to Run the Code

### C++

1. Save the code as `network_connected.cpp`.
2. Compile:

   ```bash
   g++ -std=c++17 network_connected.cpp -o network_connected
   ```

3. Run:

   ```bash
   ./network_connected
   ```

### Java

1. Save the code as `Solution.java`.
2. Compile:

   ```bash
   javac Solution.java
   ```

3. Run:

   ```bash
   java Solution
   ```

## Other Solutions

### CPP DFS

```cpp
class Solution {
private:
    void dfs(vector<vector<int>> &adj, vector<bool> &visited, int src)
    {
        visited[src] = true;
        for(int i : adj[src])
            if(!visited[i])
                dfs(adj, visited, i);
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        vector<vector<int>> adj(n);
        for(auto v : connections)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n, false);
        int components = 0;
        for(int i=0; i<n; i++)
            if(!visited[i])
            {
                dfs(adj, visited, i);
                components++;
            }
        return components - 1;
    }
};
```

### Naive Union-Find ~ 23ms

```java
class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1; // To connect all nodes need at least n-1 edges
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        int components = n;
        for (int[] c : connections) {
            int p1 = findParent(parent, c[0]);
            int p2 = findParent(parent, c[1]);
            if (p1 != p2) {
                parent[p1] = p2; // Union 2 component
                components--;
            }
        }
        return components - 1; // Need (components-1) cables to connect components together
    }
    private int findParent(int[] parent, int i) {
        while (i != parent[i]) i = parent[i];
        return i; // Without Path Compression
    }
}
```

### Union-Find with Path Compression ~ 3ms

```java
class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1; // To connect all nodes need at least n-1 edges
        int[] parent = new int[n];
        for (int i = 0; i < n; i++) parent[i] = i;
        int components = n;
        for (int[] c : connections) {
            int p1 = findParent(parent, c[0]);
            int p2 = findParent(parent, c[1]);
            if (p1 != p2) {
                parent[p1] = p2; // Union 2 component
                components--;
            }
        }
        return components - 1; // Need (components-1) cables to connect components together
    }
    private int findParent(int[] parent, int i) {
        if (i == parent[i]) return i;
        return parent[i] = findParent(parent, parent[i]); // Path compression
    }
}
```

- Time: O(n+mlogn), m is the length of connections
- Space: O(n)

### Union-Find with Path Compression and Union by Size ~ 3ms

```java
class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1; // To connect all nodes need at least n-1 edges
        int[] parent = new int[n];
        int[] size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        int components = n;
        for (int[] c : connections) {
            int p1 = findParent(parent, c[0]);
            int p2 = findParent(parent, c[1]);
            if (p1 != p2) {
                if (size[p1] < size[p2]) { // Merge small size to large size
                    size[p2] += size[p1];
                    parent[p1] = p2;
                } else {
                    size[p1] += size[p2];
                    parent[p2] = p1;
                }
                components--;
            }
        }
        return components - 1; // Need (components-1) cables to connect components together
    }
    private int findParent(int[] parent, int i) {
        if (i == parent[i]) return i;
        return parent[i] = findParent(parent, parent[i]); // Path compression
    }
}
```

- Time: O(n + m*α(n)) ≈ O(n + m), m is the length of connections (union operations).
- Explanation: Using both path compression and union by size ensures that the amortized time per operation is only α(n), which is optimal, where α(n) is the inverse Ackermann function. This function has a value α(n) < 5 for any value of n that can be written in this physical universe, so the disjoint-set operations take place in essentially constant time.
- <https://www.slideshare.net/WeiLi73/time-complexity-of-union-find-55858534>
- Space: O(n)

### BFS Java

```java
class Solution {
    public int makeConnected(int n, int[][] connections) {
        if (connections.length < n - 1) return -1; // To connect all nodes need at least n-1 edges
        List<Integer>[] graph = new List[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        for (int[] c : connections) {
            graph[c[0]].add(c[1]);
            graph[c[1]].add(c[0]);
        }
        int components = 0;
        boolean[] visited = new boolean[n];
        for (int v = 0; v < n; v++) components += bfs(v, graph, visited);
        return components - 1; // Need (components-1) cables to connect components together
    }
    int bfs(int src, List<Integer>[] graph, boolean[] visited) {
        if (visited[src]) return 0;
        visited[src] = true;
        Queue<Integer> q = new LinkedList<>();
        q.offer(src);
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : graph[u]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.offer(v);
                }
            }
        }
        return 1;
    }
}
```

- Time: O(n + m), m is the length of connections
- Space: O(n + m)

### Union - Find Java

```java
class Solution {
    int[] parent;
    int[] rank;
    int find(int x){
        while(parent[x]!=x){
            x = parent[parent[x]];
        }
        return x;
    }
    void makeUnion(int x, int y){
        int parX = find(x);
        int parY = find(y);
        if(parX == parY){
            return;
        }
        else if(rank[parX]<rank[parY]){
            parent[parX] = parY;
        }
        else if(rank[parX]>rank[parY]){
            parent[parY] = parX;
        }
        else{
            parent[parY] = parX;
            rank[parX]++;
        }
    }
    public int makeConnected(int n, int[][] connections) {
        int edges = connections.length;
        if(edges<n-1){
            return -1;
        }
        parent = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        for(int[] con : connections){
            makeUnion(con[0], con[1]);
        }
        Set<Integer> set = new HashSet<>();
        for(int i=0; i<n; i++){
            int par = find(i);
            set.add(par);
        }
        int unions = set.size();
        return unions-1;
    }
}
```

```java
class Solution {
    int[] parent;
    int[] rank;
    int find(int x){
        while(parent[x]!=x){
            x = parent[parent[x]];
        }
        return x;
    }
    int makeUnion(int x, int y){
        int parX = find(x);
        int parY = find(y);
        if(parX == parY){
            return 0;
        }
        else if(rank[parX]<rank[parY]){
            parent[parX] = parY;
        }
        else if(rank[parX]>rank[parY]){
            parent[parY] = parX;
        }
        else{
            parent[parY] = parX;
            rank[parX]++;
        }
        return 1;
    }
    public int makeConnected(int n, int[][] connections) {
        int edges = connections.length;
        if(edges<n-1){
            return -1;
        }
        parent = new int[n];
        rank = new int[n];
        for(int i=0; i<n; i++){
            parent[i] = i;
        }
        int components = n;
        for(int[] con : connections){
            components -= makeUnion(con[0], con[1]);
        }
        return components-1;
    }
}
```

---

>Resources:

1. <https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/717403/c-dfs-number-of-islands-detailed-explanation>
2. <https://leetcode.com/problems/number-of-operations-to-make-network-connected/solutions/477660/java-count-number-of-connected-components-clean-code>
