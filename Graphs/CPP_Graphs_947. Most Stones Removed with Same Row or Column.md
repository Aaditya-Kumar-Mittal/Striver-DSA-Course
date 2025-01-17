# Most Stones Removed with Same Row or Column

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Most Stones Removed with Same Row or Column](#most-stones-removed-with-same-row-or-column)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [C++](#c)
    - [Java](#java)
  - [Other Solutions](#other-solutions)
    - [Approach 1: Depth First Search](#approach-1-depth-first-search)
      - [Intuition](#intuition)
      - [Proof that in a connected component of stones, we can remove all but one stone](#proof-that-in-a-connected-component-of-stones-we-can-remove-all-but-one-stone)
      - [Conclusion](#conclusion)
      - [Detailed Algorithm](#detailed-algorithm)
        - [Step 1: Represent the Stones as a Graph](#step-1-represent-the-stones-as-a-graph)
        - [Step 2: Count the Number of Connected Components](#step-2-count-the-number-of-connected-components)
        - [Algorithm](#algorithm)
          - [Main method `removeStones`](#main-method-removestones)
          - [Helper method `depthFirstSearch`](#helper-method-depthfirstsearch)
      - [Complexity Analysis](#complexity-analysis-1)
        - [Time Complexity: ( O(n^2) )](#time-complexity--on2-)
        - [Space Complexity: ( O(n^2) )](#space-complexity--on2-)
    - [Approach 2: Disjoint Set Union](#approach-2-disjoint-set-union)
      - [Intuition](#intuition-1)
      - [Algorithm](#algorithm-1)
        - [Main method `removeStones`](#main-method-removestones-1)
        - [Helper class `UnionFind`](#helper-class-unionfind)
        - [Code Example](#code-example)
      - [Complexity Analysis](#complexity-analysis-2)
      - [Conclusion](#conclusion-1)
    - [Approach 3: Disjoint Set Union (Optimized)](#approach-3-disjoint-set-union-optimized)
      - [Intuition](#intuition-2)
      - [Algorithm](#algorithm-2)
        - [Main method `removeStones`](#main-method-removestones-2)
        - [Helper class `UnionFind`](#helper-class-unionfind-1)
      - [Complexity Analysis](#complexity-analysis-3)
        - [Time Complexity: O(n)](#time-complexity-on)
        - [Space Complexity: O(n + 20002)](#space-complexity-on--20002)

---

## Introduction

The **Most Stones Removed with Same Row or Column** problem is a graph problem involving stones placed on a 2D plane. You can remove a stone if it shares the same row or column as another stone that hasn't been removed. The task is to calculate the maximum number of stones that can be removed while leaving at least one stone in each connected group.

---

## Problem Description

You are given:

- An array `stones` of length \( n \), where `stones[i] = [xi, yi]` represents the position of the \( i \)-th stone on the 2D plane.

**Task**: Return the maximum number of stones that can be removed while ensuring at least one stone remains in each connected group.

---

### Examples

#### Example 1

**Input:**

```bash
stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
```

**Output:** `5`

**Explanation:**

- Remove stones in the following order:
  1. Remove [2,2] (shares the same row as [2,1]).
  2. Remove [2,1] (shares the same column as [0,1]).
  3. Remove [1,2] (shares the same row as [1,0]).
  4. Remove [1,0] (shares the same column as [0,0]).
  5. Remove [0,1] (shares the same row as [0,0]).
- The remaining stone is [0,0].

---

#### Example 2

**Input:**

```bash
stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
```

**Output:** `3`

**Explanation:**

- Remove stones in the following order:
  1. Remove [2,2] (shares the same row as [2,0]).
  2. Remove [2,0] (shares the same column as [0,0]).
  3. Remove [0,2] (shares the same row as [0,0]).
- The remaining stones are [0,0] and [1,1].

---

#### Example 3

**Input:**

```bash
stones = [[0,0]]
```

**Output:** `0`

**Explanation:** Only one stone exists, so it cannot be removed.

---

### Constraints

- \( 1 \leq \text{stones.length} \leq 1000 \)
- \( 0 \leq x_i, y_i \leq 10^4 \)
- No two stones are placed at the same coordinate.

---

## Approach

This problem can be visualized as finding the number of connected components in a graph where:

- Nodes represent stones.
- Edges exist between nodes if the corresponding stones share a row or column.

To solve the problem:

1. **Union-Find (Disjoint Set Union - DSU):**
   - Use DSU to group stones that are in the same row or column into connected components.
   - Treat rows and columns as separate dimensions, combining them into a single union-find structure.

2. **Steps:**
   - Assign each row and column a unique identifier.
   - For each stone at `(xi, yi)`:
     - Map the row \( x_i \) and column \( y_i \) to unique nodes.
     - Use the union operation to group them in the DSU.
   - Count the number of connected components in the graph.

3. **Result Calculation:**
   - The maximum number of stones that can be removed is:
     \[
     \text{stones.length} - \text{number of connected components}.
     \]

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

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
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0, maxCol = 0;

        // Find maximum row and column indices
        for (auto& stone : stones) {
            maxRow = max(maxRow, stone[0]);
            maxCol = max(maxCol, stone[1]);
        }

        // Initialize Disjoint Set
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        // Group stones in the same row or column
        for (auto& stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;
            ds.unionBySize(rowNode, colNode);
            stoneNodes[rowNode] = 1;
            stoneNodes[colNode] = 1;
        }

        // Count connected components
        int connectedComponents = 0;
        for (auto& [node, _] : stoneNodes) {
            if (ds.findParent(node) == node)
                connectedComponents++;
        }

        // Maximum stones removed = total stones - connected components
        return n - connectedComponents;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class DisjointSet {
    int[] parent, sizeArr;

    public DisjointSet(int n) {
        parent = new int[n + 1];
        sizeArr = new int[n + 1];
        Arrays.fill(sizeArr, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    public int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    public void unionBySize(int u, int v) {
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
}

class Solution {
    public int removeStones(int[][] stones) {
        int n = stones.length;
        int maxRow = 0, maxCol = 0;

        // Find maximum row and column indices
        for (int[] stone : stones) {
            maxRow = Math.max(maxRow, stone[0]);
            maxCol = Math.max(maxCol, stone[1]);
        }

        // Initialize Disjoint Set
        DisjointSet ds = new DisjointSet(maxRow + maxCol + 1);
        Map<Integer, Integer> stoneNodes = new HashMap<>();

        // Group stones in the same row or column
        for (int[] stone : stones) {
            int rowNode = stone[0];
            int colNode = stone[1] + maxRow + 1;
            ds.unionBySize(rowNode, colNode);
            stoneNodes.put(rowNode, 1);
            stoneNodes.put(colNode, 1);
        }

        // Count connected components
        int connectedComponents = 0;
        for (int node : stoneNodes.keySet()) {
            if (ds.findParent(node) == node)
                connectedComponents++;
        }

        // Maximum stones removed = total stones - connected components
        return n - connectedComponents;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DSU Operations:** \( O(\alpha(n)) \), where \( \alpha \) is the inverse Ackermann function.
- **Total Stones:** \( O(n \cdot \alpha(n)) \), as we process all \(

 n \) stones.

### Space Complexity

- \( O(n) \) for DSU data structures.

---

## How to Run the Code

### C++

1. **Input:** Prepare a vector of stones.
2. **Compilation:** `g++ -std=c++17 filename.cpp`.
3. **Execution:** Run the compiled program.

### Java

1. **Input:** Prepare a 2D array for stones.
2. **Compilation:** `javac Solution.java`.
3. **Execution:** Run using `java Solution`.

---

## Other Solutions

### Approach 1: Depth First Search

#### Intuition

Two stones are considered "connected" if they share a row or column, but this connection extends beyond just pairs of stones. If stone A is connected to stone B, and stone B is connected to stone C, then all three stones form part of the same group, even if A and C don’t directly share a row or column. This concept is akin to **connected components** in graph theory, where a connected component is a group of nodes where you can reach any node from any other node in the group.

Take a look at the illustration below to visualize the components:

![Number of connected components](https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/solutions/5679850/Figures/947_re/components.png)

Since every stone in a connected component shares a row or column with at least one other stone, we can remove all but one stone. The remaining stone cannot be removed as it no longer shares coordinates with any other stone, having eliminated all others in its component.

Therefore, if our 2-D plane contains multiple connected components, each can be reduced to a single stone. The maximum number of stones that can be removed can be mathematically expressed as:

```bash
Max removable stones = Total stones - Number of connected components
```

#### Proof that in a connected component of stones, we can remove all but one stone

1. **Base case:** For `n ≤ 2`, the statement is trivially true.
   - For `n = 1`, we can't remove any stones.
   - For `n = 2`, we can remove one stone, leaving the other.

2. **Inductive hypothesis:** Assume the statement holds for all connected components of size `k` or less, where `k ≥ 2`.

3. **Inductive step:** Consider a connected component `C` of size `k + 1`.
   - Choose an arbitrary stone `S` to keep.
   - The remaining `k` stones form `m` connected sub-components `C1, C2, ..., Cm`, where `1 ≤ m ≤ k`.
   - Let `s1, s2, ..., sm` be the sizes of these sub-components. We know that: `s1 + s2 + ... + sm = k`.

   For each sub-component `Ci`:
   - By the inductive hypothesis, we can remove all but one stone from `Ci`.
   - Choose to keep the stone in `Ci` that is connected to `S` in the original component `C`.

   After applying this process to all sub-components, we have removed:

   ```bash
   (s1 - 1) + (s2 - 1) + ... + (sm - 1) = (s1 + s2 + ... + sm) - m = k - m stones
   ```

   We are now left with `m + 1` stones: the `m` stones we kept from each sub-component, plus our original chosen stone `S`.

   Each of these `m` stones shares either a row or column with `S` (by our choice in step 4(ii)). Therefore, we can remove these `m` stones one by one.

   In total, we have removed `(k - m) + m = k` stones, leaving only the originally chosen stone `S`.

#### Conclusion

By the principle of mathematical induction, we've proved that for any connected component of size `n`, we can remove `n - 1` stones, leaving just one stone.

#### Detailed Algorithm

The implementation boils down to two parts:

1. **Represent the stones as a graph.**
2. **Count the number of connected components in this graph.**

##### Step 1: Represent the Stones as a Graph

We can use an adjacency list, where for each stone, we maintain a list of all other stones it's connected to (i.e., shares a row or column with).

##### Step 2: Count the Number of Connected Components

To count the number of connected components, we can apply a graph traversal algorithm, such as Depth-First Search (DFS). We start a DFS from an unvisited stone, marking all reachable stones as visited, and count this as one connected component. We repeat this process until all stones are visited. The number of DFS executions will give us the total number of connected components in the grid.

Finally, we can apply the formula to determine the maximum number of stones that can be removed.

Note: While we've discussed using Depth-First Search to explore each connected component, **Breadth-First Search** is an equally valid alternative, offering similar time and space complexities.

##### Algorithm

###### Main method `removeStones`

1. **Set `n`** as the length of the input array `stones`.
2. **Initialize a list of lists** `adjacencyList` with `n` empty lists.
3. **Iterate over each stone `i`:**
   - For each stone `i`, iterate over stones `j` from `i+1` to `n-1`.
   - If `stone[i]` shares the same row (`stones[i][0] == stones[j][0]`) or column (`stones[i][1] == stones[j][1]`) as `stone[j]`, add `j` to the adjacency list of `i` and `i` to the adjacency list of `j`.
4. **Initialize a variable `numOfConnectedComponents`** to `0` to keep track of the number of connected components in the graph.
5. **Create a boolean array `visited`** of length `n`, initialized to `false`, to track which stones have been visited during the DFS.
6. **Iterate over each stone `i`:**
   - If stone `i` has not been visited, perform a DFS starting from stone `i` to visit all stones in the same connected component.
   - After the DFS completes, increment `numOfConnectedComponents` by 1.
7. **Return `n - numOfConnectedComponents`** as our answer.

###### Helper method `depthFirstSearch`

1. Define a method `depthFirstSearch` with parameters: `adjacencyList`, `visited`, and the current `stone`.
2. Mark the current `stone` as visited by setting `visited[stone]` to `true`.
3. For each **neighbor** of `stone` in the `adjacencyList`:
   - If the neighbor has not been visited, recursively call `depthFirstSearch` on the neighbor to visit all stones in the connected component.

This approach ensures that we correctly explore all connected stones, and after counting the connected components, we can compute the maximum number of removable stones.

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        // Adjacency list to store graph connections
        vector<vector<int>> adjacencyList(n);

        // Build the graph: Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    adjacencyList[i].push_back(j);
                    adjacencyList[j].push_back(i);
                }
            }
        }

        int numOfConnectedComponents = 0;
        vector<bool> visited(n, false);

        // Traverse all stones using DFS to count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                depthFirstSearch(adjacencyList, visited, i);
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus number of
        // connected components
        return n - numOfConnectedComponents;
    }

private:
    // DFS to visit all stones in a connected component
    void depthFirstSearch(vector<vector<int>>& adjacencyList,
                          vector<bool>& visited, int stone) {
        visited[stone] = true;

        for (int neighbor : adjacencyList[stone]) {
            if (!visited[neighbor]) {
                depthFirstSearch(adjacencyList, visited, neighbor);
            }
        }
    }
};
```

```java
class Solution {

    public int removeStones(int[][] stones) {
        int n = stones.length;

        // Adjacency list to store graph connections
        List<Integer>[] adjacencyList = new List[n];
        for (int i = 0; i < n; i++) {
            adjacencyList[i] = new ArrayList<>();
        }

        // Build the graph: Connect stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (
                    stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]
                ) {
                    adjacencyList[i].add(j);
                    adjacencyList[j].add(i);
                }
            }
        }

        int numOfConnectedComponents = 0;
        boolean[] visited = new boolean[n];

        // Traverse all stones using DFS to count connected components
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                depthFirstSearch(adjacencyList, visited, i);
                numOfConnectedComponents++;
            }
        }

        // Maximum stones that can be removed is total stones minus number of connected components
        return n - numOfConnectedComponents;
    }

    // DFS to visit all stones in a connected component
    private void depthFirstSearch(
        List<Integer>[] adjacencyList,
        boolean[] visited,
        int stone
    ) {
        visited[stone] = true;

        for (int neighbor : adjacencyList[stone]) {
            if (!visited[neighbor]) {
                depthFirstSearch(adjacencyList, visited, neighbor);
            }
        }
    }
}
```

#### Complexity Analysis

Let \( n \) be the length of the stones array.

##### Time Complexity: \( O(n^2) \)

The graph is built by iterating over all pairs of stones \((i, j)\) to check if they share the same row or column, resulting in \( O(n^2) \) time complexity.

In the worst case, the depth-first search will traverse all nodes and edges. Since each stone can be connected to every other stone, the algorithm can visit all \( O(n^2) \) edges across all DFS calls.

Thus, the overall time complexity of the algorithm is \( 2 \cdot O(n^2) = O(n^2) \).

##### Space Complexity: \( O(n^2) \)

In the worst case, any two stones could share the same row or column. So, the adjacency list could store up to \( n^2 \) edges, taking \( O(n^2) \) space.

The visited array takes an additional linear space.

The recursive DFS call stack can go as deep as the number of stones in a single connected component. In the worst case, this depth could be \( n \), leading to \( O(n) \) additional space for the stack.

Thus, the space complexity of the algorithm is \( 2 \cdot O(n) + O(n^2) = O(n^2) \).

---

### Approach 2: Disjoint Set Union

#### Intuition

A **Disjoint Set Union (DSU)**, also known as **Union-Find**, is an efficient data structure used to identify and manage connected components in a graph. This structure supports two main operations: **find** and **union**. The find operation determines which set an element belongs to, and the union operation merges two sets into one. This is particularly useful for solving problems like the one at hand, where we need to group stones that are connected by a row or column.

The process begins by treating each stone as a separate connected component. If two stones share a row or column, they are merged into the same component. After processing all possible pairs of stones, the total number of connected components is reduced, and we can calculate the maximum number of stones that can be removed based on the number of remaining components.

The value of **n - count** gives the number of stones that can be removed, where **n** is the total number of stones, and **count** is the number of remaining connected components.

#### Algorithm

##### Main method `removeStones`

1. **Input**: `stones`, an array of size `n` representing the stones' positions in a 2D plane.
2. Initialize a `UnionFind` object `uf` with size `n`.
3. Iterate over each stone `i`:
   - For each stone `i`, iterate over stones `j` from `i + 1` to `n - 1`.
   - If stone `i` shares the same row (i.e., `stones[i][0] == stones[j][0]`) or column (i.e., `stones[i][1] == stones[j][1]`) with stone `j`, perform a union operation on `i` and `j`.
4. After processing all pairs of stones, return `n - uf.count`, where `count` represents the total number of connected components in the graph.

##### Helper class `UnionFind`

Define a class `UnionFind` with the following fields:

- `parent`: an integer array that tracks the parent (or root) of each stone.
- `count`: an integer representing the number of connected components in the graph.

**UnionFind Constructor**:

- Initialize the `parent` array with size `n`, setting each element to `-1`, meaning each stone is its own parent initially.
- Set `count` to `n`, representing the total number of connected components.

**Helper method `find(node)`**:

- This method finds the root of the set that the given node belongs to. If the parent of `node` is `-1`, return `node` as it is its own root.
- Otherwise, recursively call `find` on `parent[node]`, set the result as `parent[node]`, and return it.

**Helper method `union(n1, n2)`**:

- This method merges the sets containing `n1` and `n2`.
- First, find the roots of `n1` and `n2` using the `find` method and store them as `root1` and `root2`.
- If `root1 == root2`, the two stones are already in the same connected component, so no further action is needed.
- If the roots are different, merge the two components by setting `parent[root1]` to `root2` and decrement the `count`.

##### Code Example

```java
class UnionFind {
    int[] parent;
    int count;

    public UnionFind(int n) {
        parent = new int[n];
        count = n;
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
        }
    }

    public int find(int node) {
        if (parent[node] == -1) {
            return node;
        }
        parent[node] = find(parent[node]); // Path compression
        return parent[node];
    }

    public void union(int n1, int n2) {
        int root1 = find(n1);
        int root2 = find(n2);

        if (root1 == root2) {
            return; // Already in the same component
        }

        parent[root1] = root2; // Merge the two sets
        count--; // Decrease the count of separate components
    }
}

public int removeStones(int[][] stones) {
    int n = stones.length;
    UnionFind uf = new UnionFind(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                uf.union(i, j);
            }
        }
    }

    return n - uf.count;
}
```

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(n);

        // Populate uf by connecting stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {
                    uf.unionNodes(i, j);
                }
            }
        }

        return n - uf.count;
    }

private:
    // Union-Find data structure for tracking connected components
    class UnionFind {
    public:
        vector<int> parent;  // Array to track the parent of each node
        int count;           // Number of connected components

        UnionFind(int n) {
            parent.resize(n, -1);  // Initialize all nodes as their own parent
            count = n;  // Initially, each stone is its own connected component
        }

        // Find the root of a node with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void unionNodes(int n1, int n2) {
            int root1 = find(n1);
            int root2 = find(n2);

            if (root1 == root2) {
                return;  // If they are already in the same component, do
                         // nothing
            }

            // Merge the components and reduce the count of connected components
            count--;
            parent[root1] = root2;
        }
    };
};
```

```java
class Solution {

    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind uf = new UnionFind(n);

        // Populate uf by connecting stones that share the same row or column
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (
                    stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]
                ) {
                    uf.union(i, j);
                }
            }
        }

        return n - uf.count;
    }

    // Union-Find data structure for tracking connected components
    private class UnionFind {

        int[] parent; // Array to track the parent of each node
        int count; // Number of connected components

        UnionFind(int n) {
            parent = new int[n];
            Arrays.fill(parent, -1); // Initialize all nodes as their own parent
            count = n; // Initially, each stone is its own connected component
        }

        // Find the root of a node with path compression
        int find(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void union(int n1, int n2) {
            int root1 = find(n1);
            int root2 = find(n2);

            if (root1 == root2) {
                return; // If they are already in the same component, do nothing
            }

            // Merge the components and reduce the count of connected components
            count--;
            parent[root1] = root2;
        }
    }
}
```

#### Complexity Analysis

- **Time Complexity**: `O(n^2 * α(n))`
  - Initializing the `parent` array takes `O(n)` time.
  - The nested loops iterate over each pair of stones `(i, j)` resulting in `O(n^2)` comparisons.
  - For each pair, the `union` and `find` operations are invoked. The `find` operation has a time complexity of `O(α(n))`, where `α(n)` is the inverse Ackermann function (which grows very slowly).
  - Hence, the overall time complexity is `O(n^2 * α(n))`.

- **Space Complexity**: `O(n)`
  - The only additional space used is the `parent` array, which takes `O(n)` space.
  - The algorithm does not use any auxiliary data structures that scale with the input size.

#### Conclusion

This approach leverages the efficient **Union-Find** data structure to group stones into connected components. By using **union** and **find** operations, we can efficiently track and merge connected components based on shared rows or columns. The maximum number of stones that can be removed is determined by the number of connected components left after processing all possible stone pairs.

---

### Approach 3: Disjoint Set Union (Optimized)

#### Intuition

The most time-consuming part of our previous algorithms has been iterating through every possible pair of stones, but can we do better?

In our earlier approach, each stone was treated as a distinct entity. In this improved method, we’ll break each stone down into two entities: a row index and a column index. Although this effectively doubles the total number of nodes in the graph, it doesn't affect our solution since our goal is to find the number of connected components, not the number of nodes within each component.

When we treat the row and column indices as separate entities, all stones that share the same row or column index become implicitly connected, eliminating the need to manually connect these stones. However, we do need to connect the row and column indices of a stone since they were originally part of the same element.

This optimization condenses our algorithm into a single step: looping through the input array `stones` and unioning the row and column indices of each element. However, this approach introduces two challenges:

1. **Differentiating Between Row and Column Elements**:  
   If a row and column share the same value, how do we distinguish between them? For instance, consider two stones positioned at `(x, y)` and `(y, z)`. If we union `x` with `y`, and `y` with `z`, the Disjoint Set Union (DSU) might incorrectly consider the two stones as connected, which is not necessarily true. To address this, we differentiate between row and column elements by offsetting the column value by a large constant that places it beyond the range of valid row values. We use `10,001` for this purpose, as the range of row indices is `[0, 10,000]`.

2. **Counting the Number of Connected Components**:  
   Initially, we assumed the number of connected components was `n` since each stone was treated as a separate node. However, in this approach, a stone is no longer the basic unit in the graph. While it might seem logical to consider the number of nodes as twice the number of stones, this assumption is incorrect because row and column indices are likely to be repeated among stones and thus will not form separate nodes in the graph.

To accurately track the number of nodes, we maintain a set called `uniqueNodes`. Before performing a union operation, we check if the nodes (row and column) have been encountered before. If not, these are new nodes in the graph and can initially be considered separate components, so we increment our count. If the union operation is successful, we subsequently decrease the count.

After all operations are complete, the count will store the number of connected components in the graph.

#### Algorithm

##### Main method `removeStones`

```python
def removeStones(stones):
    n = len(stones)
    uf = UnionFind(20002)  # create the union-find object with a size large enough to handle both row and column indices
    
    for stone in stones:
        # union the row index and column index (offset by 10001 to differentiate between them)
        uf.union(stone[0], stone[1] + 10001)
    
    return n - uf.componentCount  # the number of stones that can be removed
```

##### Helper class `UnionFind`

```python
class UnionFind:
    def __init__(self, n):
        self.parent = [-1] * n
        self.componentCount = 0
        self.uniqueNodes = set()
    
    def find(self, node):
        if node not in self.uniqueNodes:
            self.componentCount += 1
            self.uniqueNodes.add(node)
        
        if self.parent[node] == -1:
            return node
        else:
            self.parent[node] = self.find(self.parent[node])
            return self.parent[node]
    
    def union(self, n1, n2):
        root1 = self.find(n1)
        root2 = self.find(n2)
        
        if root1 != root2:
            self.parent[root1] = root2
            self.componentCount -= 1
```

#### Complexity Analysis

##### Time Complexity: O(n)

- The initialization of the `parent` array takes constant time, as the size is fixed at `20002`.
- The union operation is called `n` times, once for each stone. All `union` and `find` operations take `O(1)` time due to path compression in the `find` function. The operations are efficient as they rely on the inverse Ackermann function, which grows extremely slowly.
- Thus, the overall time complexity is `O(n)`.

##### Space Complexity: O(n + 20002)

- The `parent` array takes constant space of `20002` to handle both row and column indices.
- The `uniqueNodes` set can have at most `2 * n` elements, corresponding to all unique row and column coordinates. The space complexity of this set is `O(n)`.
- Thus, the overall space complexity of the approach is `O(n + 20002)`, though the `20002` term is constant and typically excluded from complexity analysis.

This approach optimizes the space complexity by using a single Union-Find structure to handle both row and column indices, making it much more efficient for large inputs compared to previous methods.

```cpp
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        UnionFind uf(20002);  // Initialize UnionFind with a large enough range
                              // to handle coordinates

        // Union stones that share the same row or column
        for (int i = 0; i < n; i++) {
            uf.unionNodes(
                stones[i][0],
                stones[i][1] + 10001);  // Offset y-coordinates to avoid
                                        // conflict with x-coordinates
        }

        return n - uf.componentCount;
    }

private:
    // Union-Find data structure for tracking connected components
    class UnionFind {
    public:
        vector<int> parent;  // Array to track the parent of each node
        int componentCount;  // Number of connected components
        unordered_set<int> uniqueNodes;  // Set to track unique nodes

        UnionFind(int n) {
            parent.resize(n, -1);  // Initialize all nodes as their own parent
            componentCount = 0;
        }

        // Find the root of a node with path compression
        int find(int node) {
            // If node is not marked, increase the component count
            if (uniqueNodes.find(node) == uniqueNodes.end()) {
                componentCount++;
                uniqueNodes.insert(node);
            }

            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void unionNodes(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return;  // If they are already in the same component, do
                         // nothing
            }

            // Merge the components and reduce the component count
            parent[root1] = root2;
            componentCount--;
        }
    };
};
```

```java
class Solution {

    public int removeStones(int[][] stones) {
        int n = stones.length;
        UnionFind uf = new UnionFind(20002); // Initialize UnionFind with a large enough range to handle coordinates

        // Union stones that share the same row or column
        for (int i = 0; i < n; i++) {
            uf.union(stones[i][0], stones[i][1] + 10001); // Offset y-coordinates to avoid conflict with x-coordinates
        }

        return n - uf.componentCount;
    }

    // Union-Find data structure for tracking connected components
    class UnionFind {

        int[] parent; // Array to track the parent of each node
        int componentCount; // Number of connected components
        Set<Integer> uniqueNodes; // Set to track unique nodes

        UnionFind(int n) {
            parent = new int[n];
            Arrays.fill(parent, -1); // Initialize all nodes as their own parent
            componentCount = 0;
            uniqueNodes = new HashSet<>();
        }

        // Find the root of a node with path compression
        int find(int node) {
            // If node is not marked, increase the component count
            if (!uniqueNodes.contains(node)) {
                componentCount++;
                uniqueNodes.add(node);
            }

            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find(parent[node]);
        }

        // Union two nodes, reducing the number of connected components
        void union(int node1, int node2) {
            int root1 = find(node1);
            int root2 = find(node2);

            if (root1 == root2) {
                return; // If they are already in the same component, do nothing
            }

            // Merge the components and reduce the component count
            parent[root1] = root2;
            componentCount--;
        }
    }
}
```

---
