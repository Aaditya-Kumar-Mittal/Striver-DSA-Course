# Largest Sum Cycle

## Table of Contents

- [Largest Sum Cycle](#largest-sum-cycle)
  - [Table of Contents](#table-of-contents)
    - [Introduction](#introduction)
    - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
    - [Approach](#approach)
    - [Code Implementations](#code-implementations)
      - [C++ Implementation](#c-implementation)
      - [Java Implementation](#java-implementation)
    - [Complexity Analysis](#complexity-analysis)
    - [How to Run the Code](#how-to-run-the-code)
      - [C++](#c)
      - [Java](#java)
  - [Other Solutions](#other-solutions)

---

### Introduction

This problem involves finding the largest sum of a cycle in a maze of `N` cells. Each cell has a unidirectional exit, represented as a directed graph. If there are multiple cycles, return the largest sum among them. If no cycle exists, return `-1`.

---

### Problem Description

- Input:

  - `N`: Number of cells.
  - `Edge[]`: Array where `Edge[i]` represents the cell reachable from cell `i`. If `Edge[i] = -1`, cell `i` has no exit.

- Output:  
  The sum of the cell indices of the largest cycle. Return `-1` if no cycle exists.

- Definitions:
  - A cycle is a sequence of nodes such that the last node points back to a node in the sequence.

---

### Examples

#### Example 1

Input:  
`N = 4, Edge[] = {1, 2, 0, -1}`  
Output:  
`3`

Explanation:

- The graph contains one cycle: `0 -> 1 -> 2 -> 0`.
- Sum of indices in the cycle = `0 + 1 + 2 = 3`.

---

#### Example 2

Input:  
`N = 4, Edge[] = {2, 0, -1, 2}`  
Output:  
`-1`

Explanation:

- No cycles exist in the graph.

---

### Constraints

1. \( 1 \leq N \leq 10^5 \)
2. \( -1 < \text{Edge}[i] < N \)
3. \( \text{Edge}[i] \neq i \) (no self-loops).

---

### Approach

1. Graph Representation:

   - The graph is represented as a directed adjacency list using the `Edge[]` array.

2. Cycle Detection and Sum Calculation:

   - Use a Depth First Search (DFS) approach to detect cycles and compute their sums.
   - Use a `visited` array to track visited nodes.
   - Use a `path` array to identify nodes that are part of the current DFS path. This helps detect cycles.

3. Steps:
   - For each unvisited node, perform a DFS.
   - When a back-edge (pointing to a node in the current path) is detected, compute the cycle's sum.
   - Track the maximum sum among all cycles.

---

### Code Implementations

#### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long largestSumCycle(int N, vector<int>& Edge) {
        vector<int> visited(N, 0);
        vector<int> path(N, -1);
        long long maxSum = -1;

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                unordered_map<int, int> cycleMap;
                int curr = i, step = 0;

                // Follow the path using DFS
                while (curr != -1 && !visited[curr]) {
                    visited[curr] = 1;
                    cycleMap[curr] = step++;
                    curr = Edge[curr];
                }

                // If a cycle is found
                if (curr != -1 && cycleMap.count(curr)) {
                    long long cycleSum = 0;
                    for (auto& [node, _] : cycleMap) {
                        if (cycleMap[node] >= cycleMap[curr]) {
                            cycleSum += node;
                        }
                    }
                    maxSum = max(maxSum, cycleSum);
                }
            }
        }

        return maxSum;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> Edge(N);
        for (int i = 0; i < N; i++) {
            cin >> Edge[i];
        }

        Solution obj;
        cout << obj.largestSumCycle(N, Edge) << endl;
    }
    return 0;
}
```

---

#### Java Implementation

```java
import java.util.*;

class Solution {
    public long largestSumCycle(int N, int[] Edge) {
        boolean[] visited = new boolean[N];
        long maxSum = -1;

        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                Map<Integer, Integer> cycleMap = new HashMap<>();
                int curr = i, step = 0;

                // Follow the path using DFS
                while (curr != -1 && !visited[curr]) {
                    visited[curr] = true;
                    cycleMap.put(curr, step++);
                    curr = Edge[curr];
                }

                // If a cycle is found
                if (curr != -1 && cycleMap.containsKey(curr)) {
                    long cycleSum = 0;
                    for (int node : cycleMap.keySet()) {
                        if (cycleMap.get(node) >= cycleMap.get(curr)) {
                            cycleSum += node;
                        }
                    }
                    maxSum = Math.max(maxSum, cycleSum);
                }
            }
        }

        return maxSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int N = sc.nextInt();
            int[] Edge = new int[N];
            for (int i = 0; i < N; i++) {
                Edge[i] = sc.nextInt();
            }

            Solution obj = new Solution();
            System.out.println(obj.largestSumCycle(N, Edge));
        }
    }
}
```

---

### Complexity Analysis

- Time Complexity: \( O(N) \)
  - Each node is visited once.
  - Cycle detection is efficient with the use of `cycleMap`.
- Space Complexity: \( O(N) \)
  - For `visited`, `cycleMap`, and recursion stack.

---

### How to Run the Code

#### C++

1. Save the code in a file named `LargestSumCycle.cpp`.
2. Compile using `g++ LargestSumCycle.cpp -o LargestSumCycle`.
3. Run using `./LargestSumCycle`.

#### Java

1. Save the code in a file named `LargestSumCycle.java`.
2. Compile using `javac LargestSumCycle.java`.
3. Run using `java LargestSumCycle`.

---

## Other Solutions

```cpp
//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:

  long long dfs(int node, vector<int>& visited, vector<vector<int>>& adj, vector<int>& path, long long sum) {
        visited[node] = 1;
        path[node] = sum;

        long long maxCycleSum = LLONG_MIN;

        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // Recurse for unvisited neighbors
                long long cycleSum = dfs(neighbor, visited, adj, path, sum + neighbor);
                maxCycleSum = max(maxCycleSum, cycleSum);
            } else if (path[neighbor] != -1) {
                // Cycle detected, calculate its sum
                long long cycleSum = sum - path[neighbor] + neighbor;
                maxCycleSum = max(maxCycleSum, cycleSum);
            }
        }

        // Backtrack: mark the path value as -1
        path[node] = -1;
        return maxCycleSum;
    }

    long long largestSumCycle(int N, vector<int> Edge) {
        vector<int> visited(N, 0);
        vector<int> path(N, -1);
        vector<vector<int>> adj(N);

        // Build adjacency list
        for (int i = 0; i < N; i++) {
            if (Edge[i] != -1) {
                adj[i].push_back(Edge[i]);
            }
        }

        long long maxSum = -1;

        // Run DFS for each unvisited node
        for (int i = 0; i < N; i++) {
            if (!visited[i]) {
                long long cycleSum = dfs(i, visited, adj, path, i);
                maxSum = max(maxSum, cycleSum);
            }
        }

        return maxSum == LLONG_MIN ? -1 : maxSum;
    }
};

//{ Driver Code Starts.
signed main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      long long ans=obj.largestSumCycle(N, Edge);
      cout<<ans<<endl;

cout << "~" << "\n";
}
   return 0;
}
// } Driver Code Ends
```
