# Critical Connections in a Network (Tarjan's Algorithm)

## Table of Contents

- [Critical Connections in a Network (Tarjan's Algorithm)](#critical-connections-in-a-network-tarjans-algorithm)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Tarjan's Algorithm for Bridges](#tarjans-algorithm-for-bridges)
    - [Steps](#steps)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [Input Format](#input-format)
    - [Example Input](#example-input)
    - [Example Output](#example-output)
  - [Other Solutions](#other-solutions)
    - [Python DFS Solution](#python-dfs-solution)
    - [Explanation of Key Questions in the Code](#explanation-of-key-questions-in-the-code)
      - [Why do we write a special case for `parent`?](#why-do-we-write-a-special-case-for-parent)
      - [Can we eliminate the `visited[]` array?](#can-we-eliminate-the-visited-array)
      - [Why is the `timer` an array with one value in it? Can we use an integer instead?](#why-is-the-timer-an-array-with-one-value-in-it-can-we-use-an-integer-instead)
      - [How do we maintain the order of input nodes in the result?](#how-do-we-maintain-the-order-of-input-nodes-in-the-result)
      - [Why use `if(currentTimeStamp < timeStampAtThatNode[oneNeighbour])` instead of `if(currentTimeStamp > timeStampAtThatNode[oneNeighbour])`?](#why-use-ifcurrenttimestamp--timestampatthatnodeoneneighbour-instead-of-ifcurrenttimestamp--timestampatthatnodeoneneighbour)

---

## Introduction

A **critical connection** in a network is an edge that, if removed, would disconnect the network into multiple components. These edges are also referred to as **bridges** in graph theory.

We solve this problem using **Tarjan's Algorithm**, which is based on **Depth-First Search (DFS)** and efficiently finds all bridges in a graph.

---

## Problem Description

You are given:

- An integer \(n\): the number of servers (vertices) in the network.
- A list of undirected edges \(connections\), where each edge connects two servers.

### Task

Return all **critical connections** (bridges) in the network in any order.

---

## Examples

### Example 1

**Input:**

```bash
n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
```

**Output:**

```bash
[[1,3]]
```

**Explanation:**
Removing the edge \([1,3]\) disconnects the network. Other edges are part of cycles and are not critical connections.

---

### Example 2

**Input:**

```bash
n = 2, connections = [[0,1]]
```

**Output:**

```bash
[[0,1]]
```

**Explanation:**
Removing the edge \([0,1]\) disconnects the network into two separate nodes.

---

## Constraints

- \(2 \leq n \leq 10^5\)
- \(n - 1 \leq \text{connections.length} \leq 10^5\)
- \(0 \leq a_i, b_i < n\)
- \(a_i \neq b_i\) (no self-loops)
- No repeated connections.

---

## Approach

### Tarjan's Algorithm for Bridges

Tarjan's Algorithm is an efficient method to find all **bridges** in an undirected graph. The algorithm relies on:

1. **Discovery Time (\(tin\))**: The time at which a node is first visited.
2. **Lowest Time (\(low\))**: The earliest visited vertex (by discovery time) that can be reached from the current node or its descendants.

### Steps

1. **Build the Graph**:
   - Represent the graph as an adjacency list.

2. **DFS Traversal**:
   - Maintain arrays for \(tin\), \(low\), and a visited list.
   - Use a recursive DFS to calculate \(tin\) and \(low\) for each vertex.
   - If \(low[neighbor] > tin[node]\), the edge \([node, neighbor]\) is a bridge.

3. **Store Results**:
   - Collect all bridges in a list and return them.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int timer = 1;

    void dfs(int node, int parent, vector<int>& visited, vector<vector<int>>& adj, 
             int tin[], int low[], vector<vector<int>>& bridges) {
        visited[node] = 1;
        tin[node] = low[node] = timer++;

        for (auto neighbor : adj[node]) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node, visited, adj, tin, low, bridges);
                low[node] = min(low[node], low[neighbor]);

                // Check if the edge is a bridge
                if (low[neighbor] > tin[node]) {
                    bridges.push_back({node, neighbor});
                }
            } else {
                // Back edge
                low[node] = min(low[node], tin[neighbor]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);

        // Build adjacency list
        for (auto& edge : connections) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> visited(n, 0);
        int tin[n], low[n];
        vector<vector<int>> bridges;

        // Start DFS from the first node
        dfs(0, -1, visited, adj, tin, low, bridges);

        return bridges;
    }
};

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {1, 2}, {2, 0}, {1, 3}};
    Solution sol;

    vector<vector<int>> bridges = sol.criticalConnections(n, connections);

    for (auto& bridge : bridges) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]" << endl;
    }

    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private int timer = 1;

    private void dfs(int node, int parent, boolean[] visited, List<List<Integer>> adj, 
                     int[] tin, int[] low, List<List<Integer>> bridges) {
        visited[node] = true;
        tin[node] = low[node] = timer++;

        for (int neighbor : adj.get(node)) {
            if (neighbor == parent) continue;

            if (!visited[neighbor]) {
                dfs(neighbor, node, visited, adj, tin, low, bridges);
                low[node] = Math.min(low[node], low[neighbor]);

                // Check if the edge is a bridge
                if (low[neighbor] > tin[node]) {
                    bridges.add(Arrays.asList(node, neighbor));
                }
            } else {
                // Back edge
                low[node] = Math.min(low[node], tin[neighbor]);
            }
        }
    }

    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < n; i++) adj.add(new ArrayList<>());

        // Build adjacency list
        for (List<Integer> edge : connections) {
            adj.get(edge.get(0)).add(edge.get(1));
            adj.get(edge.get(1)).add(edge.get(0));
        }

        boolean[] visited = new boolean[n];
        int[] tin = new int[n], low = new int[n];
        List<List<Integer>> bridges = new ArrayList<>();

        // Start DFS from the first node
        dfs(0, -1, visited, adj, tin, low, bridges);

        return bridges;
    }

    public static void main(String[] args) {
        int n = 4;
        List<List<Integer>> connections = Arrays.asList(
            Arrays.asList(0, 1), Arrays.asList(1, 2), Arrays.asList(2, 0), Arrays.asList(1, 3)
        );
        Solution sol = new Solution();

        List<List<Integer>> bridges = sol.criticalConnections(n, connections);
        for (List<Integer> bridge : bridges) {
            System.out.println(bridge);
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **Building the Graph**: \(O(V + E)\).
2. **DFS Traversal**: \(O(V + E)\).

**Total Time Complexity**: \(O(V + E)\).

---

### Space Complexity

1. **Graph Representation**: \(O(V + E)\).
2. **Visited Array, \(tin\), \(low\)**: \(O(V)\).

**Total Space Complexity**: \(O(V + E)\).

---

## How to Run the Code

### Input Format

- Enter \(n\), the number of nodes.
- Enter the list of connections.

### Example Input

```bash
n = 4
connections = [[0,1],[1,2],[2,0],[1,3]]
```

### Example Output

```bash
[[1,3]]
```

## Other Solutions

### Python DFS Solution

```python
class Solution:
    def criticalConnections(self, n: int, connections: List[List[int]]) -> List[List[int]]:
        graph=collections.defaultdict(set)
        for x,y in connections:
            graph[x].add(y)
            graph[y].add(x)
        
        def bridgeUtil(u, visited, parent, low, disc, time): 

            # Mark the current node as visited and print it 
            visited[u]= True

            # Initialize discovery time and low value 
            disc[u] = time[0]
            low[u] = time[0]
            time[0]+=1

            #Recur for all the vertices adjacent to this vertex 
            ans=[]
            for v in graph[u]: 
                # If v is not visited yet, then make it a child of u 
                # in DFS tree and recur for it 
                if visited[v] == False : 
                    parent[v] = u 
                    find = bridgeUtil(v, visited, parent, low, disc,time) 
                    ans.extend(find)

                    # Check if the subtree rooted with v has a connection to 
                    # one of the ancestors of u 
                    low[u] = min(low[u], low[v]) 


                    ''' If the lowest vertex reachable from subtree 
                    under v is below u in DFS tree, then u-v is 
                    a bridge'''
                    if low[v] > disc[u]: 
                        ans.append([u,v])


                elif v != parent[u]: # Update low value of u for parent function calls. 
                    low[u] = min(low[u], disc[v]) 
            return ans



        visited = [False] * (n) 
        disc = [float("Inf")] * (n) 
        low = [float("Inf")] * (n) 
        parent = [-1] * (n) 

        # Call the recursive helper function to find bridges 
        # in DFS tree rooted with vertex 'i' 
        ans=[]
        time=[0]
        for i in range(n): 
            if visited[i] == False: 
                ans.extend(bridgeUtil(i, visited, parent, low, disc,time))
        return ans
```

- Time Complexity: \(O(V + E)\)
- Space Complexity: \(O(V + E)\)

---

### Explanation of Key Questions in the Code

```java
class Solution {
    // We record the timestamp that we visit each node. For each node, we check every neighbor except its parent and return a smallest timestamp in all its neighbors. If this timestamp is strictly less than the node's timestamp, we know that this node is somehow in a cycle. Otherwise, this edge from the parent to this node is a critical connection
    public List<List<Integer>> criticalConnections(int n, List<List<Integer>> connections) {
        List<Integer>[] graph = new ArrayList[n];
        for (int i = 0; i < n; i++) graph[i] = new ArrayList<>();
        
        for(List<Integer> oneConnection :connections) {
            graph[oneConnection.get(0)].add(oneConnection.get(1));
            graph[oneConnection.get(1)].add(oneConnection.get(0));
        }
        int timer[] = new int[1];
        List<List<Integer>> results = new ArrayList<>();
        boolean[] visited = new boolean[n];
        int []timeStampAtThatNode = new int[n]; 
        criticalConnectionsUtil(graph, -1, 0, timer, visited, results, timeStampAtThatNode);
        return results;
    }
    
    
    public void criticalConnectionsUtil(List<Integer>[] graph, int parent, int node, int timer[], boolean[] visited, List<List<Integer>> results, int []timeStampAtThatNode) {
        visited[node] = true;
        timeStampAtThatNode[node] = timer[0]++;
        int currentTimeStamp = timeStampAtThatNode[node];
        
        for(int oneNeighbour : graph[node]) {
            if(oneNeighbour == parent) continue;
            if(!visited[oneNeighbour]) criticalConnectionsUtil(graph, node, oneNeighbour, timer, visited, results, timeStampAtThatNode);
            timeStampAtThatNode[node] = Math.min(timeStampAtThatNode[node], timeStampAtThatNode[oneNeighbour]);
            if(currentTimeStamp < timeStampAtThatNode[oneNeighbour]) results.add(Arrays.asList(node, oneNeighbour));
        }
        
        
    }
    
}
```

#### Why do we write a special case for `parent`?

The reason for handling the `parent` as a special case is to avoid updating the current node's timestamp with the parent's timestamp. If we don't exclude the parent, it would incorrectly update the timestamp of the current node to a smaller value, potentially marking all connections in the graph as critical.

**Example Explanation**:  
Consider a graph with nodes `A -> B -> C`, where `B` is the parent of `C` in the DFS traversal. Without excluding the parent, the timestamp of `C` could incorrectly propagate back to `B`, causing false identification of critical connections.

---

#### Can we eliminate the `visited[]` array?

Yes, it is possible to eliminate the `visited[]` array. Instead, we can check whether a node is visited by observing if its `timeStampAtThatNode[i]` is `0`. Since the `timer[]` starts with `1`, any unvisited node will have its timestamp as `0`.

**Benefit**:  
This saves memory by removing the need for an additional array.

---

#### Why is the `timer` an array with one value in it? Can we use an integer instead?

Using an integer for the timer works perfectly fine in this problem. However, in some graph-related problems, there might be multiple timers, and grouping them into an array makes the code more extensible and easier to manage. For this specific problem, using an integer is equally valid.

---

#### How do we maintain the order of input nodes in the result?

In undirected graphs, the order of edges doesn't inherently matter (e.g., `[1,3]` and `[3,1]` are considered equivalent). However, if preserving the input order is required, here are two approaches:

1. **Brute Force Check**:
   - Iterate through the input connections for every result connection to ensure the order matches. If it doesn't, reverse the connection.
   - **Time Complexity**: \(O(\text{input connections} \times \text{result connections})\).

2. **HashSet-based Solution**:
   - Store the input connections in a `HashSet` for fast lookup. When adding a result connection, check if it exists in the same order in the set. If not, reverse the connection before adding.
   - **Time Complexity**: \(O(\text{result connections})\).

---

#### Why use `if(currentTimeStamp < timeStampAtThatNode[oneNeighbour])` instead of `if(currentTimeStamp > timeStampAtThatNode[oneNeighbour])`?

The condition `currentTimeStamp < timeStampAtThatNode[oneNeighbour]` ensures that the current edge is a critical connection. This happens when the neighbor (`oneNeighbour`) cannot reach the current node (`node`) or any ancestor of the current node except through this edge.

**Key Reasoning**:  
If the neighbor's timestamp is less than or equal to the current node's timestamp, it means there exists another path to the neighbor that does not rely on the current edge. This indicates that removing the current edge will not disconnect the graph, and hence it is not a critical connection.

**Critical Connection**:  
A critical connection is identified only when the `oneNeighbour` cannot connect back to the current node through any alternate path, making the condition `currentTimeStamp < timeStampAtThatNode[oneNeighbour]` necessary.

---
