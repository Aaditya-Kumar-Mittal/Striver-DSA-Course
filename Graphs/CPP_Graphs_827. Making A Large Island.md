# Making A Large Island

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Making A Large Island](#making-a-large-island)
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
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Solution 1: CPP](#solution-1-cpp)
    - [Solution 2: Naive Depth First Search](#solution-2-naive-depth-first-search)
    - [Solution 3: Component Sizes](#solution-3-component-sizes)

---

## Introduction

The **Making A Large Island** problem involves modifying a given \( n \times n \) binary grid. The goal is to change at most one `0` to `1` to maximize the size of the largest connected island in the grid. An **island** is defined as a group of `1`s connected in 4 directions (up, down, left, right).

---

## Problem Description

You are given:

- An \( n \times n \) binary matrix `grid` where:
  - `grid[i][j] = 1` indicates land.
  - `grid[i][j] = 0` indicates water.
  
You are allowed to change **at most one `0` to `1`**.

**Task**: Return the size of the largest island after this change.

---

### Examples

#### Example 1

**Input:**

```bash
grid = [[1, 0],
        [0, 1]]
```

**Output:** `3`

**Explanation:**

- Change one `0` to `1` and connect the two `1`s.
- The resulting grid:

  ```bash
  1 1
  0 1
  ```

- Largest island size = 3.

---

#### Example 2

**Input:**

```bash
grid = [[1, 1],
        [1, 0]]
```

**Output:** `4`

**Explanation:**

- Change the `0` to `1` to make the entire grid a single island.
- Resulting grid:

  ```bash
  1 1
  1 1
  ```

- Largest island size = 4.

---

#### Example 3

**Input:**

```bash
grid = [[1, 1],
        [1, 1]]
```

**Output:** `4`

**Explanation:**

- No `0` can be changed, so the largest island size is the size of the entire grid = 4.

---

### Constraints

- \( n == grid.length \)
- \( n == grid[i].length \)
- \( 1 \leq n \leq 500 \)
- \( grid[i][j] \in \{0, 1\} \)

---

## Approach

To solve this problem, the following approach is used:

1. **Union-Find (Disjoint Set Union - DSU):**
   - Use DSU to keep track of connected components (islands) in the grid.
   - Each cell in the grid is treated as a node in a graph.
   - If two cells are adjacent and contain `1`, they are part of the same island and are merged in DSU.

2. **Step 1: Process Existing Islands:**
   - Traverse the grid and use DSU to group all `1`s into connected components (islands).
   - Store the size of each island.

3. **Step 2: Simulate Changing `0` to `1`:**
   - For each `0` in the grid:
     - Find all unique neighboring islands.
     - Calculate the potential size of the new island if this `0` is changed to `1`.
   - Keep track of the maximum island size.

4. **Edge Case:**
   - If the grid has no `0`, the largest island is the entire grid.

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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        // Step 1: Process existing islands
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++) {
                    int nRow = row + delRow[ind];
                    int nCol = col + delCol[ind];

                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                        grid[nRow][nCol] == 1) {
                        int nodeNumber = row * n + col;
                        int adjNodeNumber = nRow * n + nCol;
                        ds.unionBySize(nodeNumber, adjNodeNumber);
                    }
                }
            }
        }

        int maxSize = 0;

        // Step 2: Try changing each 0 to 1
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;

                set<int> components;

                for (int ind = 0; ind < 4; ind++) {
                    int nRow = row + delRow[ind];
                    int nCol = col + delCol[ind];

                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                        grid[nRow][nCol] == 1) {
                        int adjNodeNumber = nRow * n + nCol;
                        components.insert(ds.findParent(adjNodeNumber));
                    }
                }

                int sizeTotal = 0;

                for (auto it : components) {
                    sizeTotal += ds.sizeArr[it];
                }

                maxSize = max(maxSize, sizeTotal + 1);
            }
        }

        // Step 3: Handle edge case of all 1s
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxSize = max(maxSize, ds.sizeArr[ds.findParent(cellNo)]);
        }

        return maxSize;
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
    public int largestIsland(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n * n);

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;

                for (int ind = 0; ind < 4; ind++) {
                    int nRow = row + del

Row[ind];
                    int nCol = col + delCol[ind];

                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                            grid[nRow][nCol] == 1) {
                        int nodeNumber = row * n + col;
                        int adjNodeNumber = nRow * n + nCol;
                        ds.unionBySize(nodeNumber, adjNodeNumber);
                    }
                }
            }
        }

        int maxSize = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1)
                    continue;

                Set<Integer> components = new HashSet<>();

                for (int ind = 0; ind < 4; ind++) {
                    int nRow = row + delRow[ind];
                    int nCol = col + delCol[ind];

                    if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n &&
                            grid[nRow][nCol] == 1) {
                        int adjNodeNumber = nRow * n + nCol;
                        components.add(ds.findParent(adjNodeNumber));
                    }
                }

                int sizeTotal = 0;

                for (int comp : components) {
                    sizeTotal += ds.sizeArr[comp];
                }

                maxSize = Math.max(maxSize, sizeTotal + 1);
            }
        }

        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            maxSize = Math.max(maxSize, ds.sizeArr[ds.findParent(cellNo)]);
        }

        return maxSize;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **DSU Operations:** \( O(\alpha(n^2)) \), where \( \alpha \) is the inverse Ackermann function.
- **Grid Traversal:** \( O(n^2) \) for processing the grid and calculating potential island sizes.
- **Total:** \( O(n^2 \cdot 4 \cdot \alpha(n^2)) \approx O(n^2) \).

### Space Complexity

- \( O(n^2) \) for DSU and auxiliary data structures.

---

## How to Run the Code

### For C++

1. **Input:** Prepare a grid as a 2D vector.
2. **Compilation:** `g++ -std=c++17 filename.cpp`.
3. **Execution:** Run the compiled program.

### For Java

1. **Input:** Prepare a grid as a 2D array.
2. **Compilation:** `javac Solution.java`.
3. **Execution:** Run the program using `java Solution`.

---

## Other Solutions

### Solution 1: CPP

```cpp
int get(int i, int j, vector<vector<int>>& g) {
  return (min(i, j) < 0 || i >= g.size() || j >= g[0].size()) ? 0 : g[i][j];
}
int paint(int i, int j, int clr, vector<vector<int>>& g) {
  if (get(i, j, g) != 1)
    return 0;
  g[i][j] = clr;
  return 1 + paint(i + 1, j, clr, g) + paint(i - 1, j, clr, g) +
             paint(i, j + 1, clr, g) + paint(i, j - 1, clr, g);
}
int largestIsland(vector<vector<int>>& g, int res = 0) {
  vector<int> sizes = {0, 0};  // sentinel values; colors start from 2.
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 1)
     sizes.push_back(paint(i, j, sizes.size(), g));
  for (auto i = 0; i < g.size(); ++i)
    for (auto j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 0) {
        unordered_set<int> s = { get(i + 1, j, g), get(i - 1, j, g),
                                 get(i, j + 1, g), get(i, j - 1, g) };
        res = max(res, accumulate(begin(s), end(s), 1, [&](int sum, int col) {
          return sum + sizes[col];
        }));
      }
  return res == 0 ? g.size() * g[0].size() : res;
}
```

```cpp
int paint(int i, int j, int c, vector<vector<int>>& g, bool flip = false) {
  if (!flip && (min(i, j) < 0 || i >= g.size() || j >= g[0].size() ||
                g[i][j] == 0 || g[i][j] == c))
    return 0;
  g[i][j] = g[i][j] == 0 ? 0 : c;
  return 1 + paint(i + 1, j, c, g) + paint(i - 1, j, c, g) +
         paint(i, j + 1, c, g) + paint(i, j - 1, c, g);
}
int largestIsland(vector<vector<int>>& g, int res = 0) {
  for (int i = 0; i < g.size(); ++i)
    for (int j = 0; j < g[i].size(); ++j)
      if (g[i][j] == 0) {
        res = max(res, paint(i, j, 2, g, true));
        paint(i, j, 1, g, true);
      }
  return res == 0 ? g.size() * g[0].size() : res;
}
```

### Solution 2: Naive Depth First Search

```java
class Solution {
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};

    public int largestIsland(int[][] grid) {
        int N = grid.length;

        int ans = 0;
        boolean hasZero = false;
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                if (grid[r][c] == 0) {
                    hasZero = true;
                    grid[r][c] = 1;
                    ans = Math.max(ans, check(grid, r, c));
                    grid[r][c] = 0;
                }

        return hasZero ? ans : N*N;
    }

    public int check(int[][] grid, int r0, int c0) {
        int N = grid.length;
        Stack<Integer> stack = new Stack();
        Set<Integer> seen = new HashSet();
        stack.push(r0 * N + c0);
        seen.add(r0 * N + c0);

        while (!stack.isEmpty()) {
            int code = stack.pop();
            int r = code / N, c = code % N;
            for (int k = 0; k < 4; ++k) {
                int nr = r + dr[k], nc = c + dc[k];
                if (!seen.contains(nr * N + nc) && 0 <= nr && nr < N &&
                        0 <= nc && nc < N && grid[nr][nc] == 1) {
                    stack.push(nr * N + nc);
                    seen.add(nr * N + nc);
                }
            }
        }

        return seen.size();
    }
}
```

- Time Complexity: O(N^4), where N is the length and width of the grid.
- Space Complexity: O(N^2), where N is the length and width of the grid.

### Solution 3: Component Sizes

```java
class Solution {
    int[] dr = new int[]{-1, 0, 1, 0};
    int[] dc = new int[]{0, -1, 0, 1};
    int[][] grid;
    int N;

    public int largestIsland(int[][] grid) {
        this.grid = grid;
        N = grid.length;

        int index = 2;
        int[] area = new int[N*N + 2];
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                if (grid[r][c] == 1)
                    area[index] = dfs(r, c, index++);

        int ans = 0;
        for (int x: area) ans = Math.max(ans, x);
        for (int r = 0; r < N; ++r)
            for (int c = 0; c < N; ++c)
                if (grid[r][c] == 0) {
                    Set<Integer> seen = new HashSet();
                    for (Integer move: neighbors(r, c))
                        if (grid[move / N][move % N] > 1)
                            seen.add(grid[move / N][move % N]);

                    int bns = 1;
                    for (int i: seen) bns += area[i];
                    ans = Math.max(ans, bns);
                }

        return ans;
    }

    public int dfs(int r, int c, int index) {
        int ans = 1;
        grid[r][c] = index;
        for (Integer move: neighbors(r, c)) {
            if (grid[move / N][move % N] == 1) {
                grid[move / N][move % N] = index;
                ans += dfs(move / N, move % N, index);
            }
        }

        return ans;
    }

    public List<Integer> neighbors(int r, int c) {
        List<Integer> ans = new ArrayList();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (0 <= nr && nr < N && 0 <= nc && nc < N)
                ans.add(nr * N + nc);
        }

        return ans;
    }
}
```

- Time Complexity: O(N^2), where N is the length and width of the grid.
- Space Complexity: O(N^2), where N is the length and width of the grid.
