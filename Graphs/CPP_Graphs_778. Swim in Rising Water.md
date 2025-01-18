# Swim in Rising Water

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Swim in Rising Water](#swim-in-rising-water)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Concepts](#key-concepts)
    - [Steps](#steps)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [Using Priority Queue](#using-priority-queue)
    - [Binary Search + DFS](#binary-search--dfs)
    - [Dijkstra using Priority Queue](#dijkstra-using-priority-queue)
    - [Dijkstra with BFS optimization](#dijkstra-with-bfs-optimization)

---

## Introduction

The **Swim in Rising Water** problem involves finding the least time \( t \) required to travel from the top-left corner to the bottom-right corner of a grid. The grid's values represent elevation, and at time \( t \), you can only swim in cells with elevation \( \leq t \).

The solution leverages either a **priority queue with BFS/Dijkstra’s Algorithm** or **Disjoint Set Union (DSU)** to efficiently determine connectivity as water rises.

---

## Problem Description

**Input:**

- \( n \times n \) grid (\( grid[i][j] \) is the elevation at position \( (i, j) \)).

**Output:**

- The minimum time \( t \) required to swim from \( (0, 0) \) to \( (n - 1, n - 1) \).

---

## Examples

### Example 1

**Input:**

```bash
grid = [[0,2],
        [1,3]]
```

![enter image description here](https://assets.leetcode.com/uploads/2021/06/29/swim1-grid.jpg)

**Output:**

```bash
3
```

**Explanation:**

- At \( t = 0 \): Only \( (0, 0) \) is accessible.
- At \( t = 3 \): \( (0, 0) \) connects to \( (1, 1) \).

---

### Example 2

**Input:**

```bash
grid = [[0,  1,  2,  3,  4],
        [24, 23, 22, 21, 5],
        [12, 13, 14, 15, 16],
        [11, 17, 18, 19, 20],
        [10, 9,  8,  7,  6]]
```

![enter image description here](https://assets.leetcode.com/uploads/2021/06/29/swim2-grid-1.jpg)

**Output:**

```bash
16
```

**Explanation:**

- At \( t = 16 \), all cells from \( (0, 0) \) to \( (4, 4) \) are connected.

---

## Constraints

- \( 1 \leq n \leq 50 \)
- \( 0 \leq grid[i][j] < n^2 \)
- Each value in \( grid[i][j] \) is unique.

---

## Approach

### Key Concepts

1. **Disjoint Set Union (DSU):**
   - Track connectivity of cells using union-find with path compression and union by size.
   - Cells become connected as water rises.

2. **Sorting by Elevation:**
   - Process cells in increasing order of elevation to simulate rising water.

3. **Union of Adjacent Cells:**
   - For each cell, union it with its valid neighbors if their elevation \( \leq t \).

4. **Early Exit Condition:**
   - If \( (0, 0) \) and \( (n - 1, n - 1) \) are connected, return the current time \( t \).

---

### Steps

1. **Initialize DSU**:
   - Create a DSU structure for \( n \times n \) cells.

2. **Sort Cells**:
   - Sort all grid cells based on their elevation.

3. **Process Cells**:
   - For each cell, connect it with its valid neighbors.

4. **Check Connectivity**:
   - After processing each cell, check if the start and end cells are connected.

5. **Return Result**:
   - Return the time \( t \) when \( (0, 0) \) and \( (n - 1, n - 1) \) are connected.

---

## Code

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
        for (int i = 0; i <= n; i++) parent[i] = i;
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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        vector<pair<int, int>> cells;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.push_back({grid[i][j], i * n + j});
            }
        }
        sort(cells.begin(), cells.end());

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for (auto& cell : cells) {
            int t = cell.first;
            int idx = cell.second;
            int row = idx / n, col = idx % n;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] <= t) {
                    int neighborIdx = nRow * n + nCol;
                    ds.unionBySize(idx, neighborIdx);
                }
            }

            if (ds.findParent(0) == ds.findParent(n * n - 1)) {
                return t;
            }
        }
        return n * n - 1;
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
        for (int i = 0; i <= n; i++) parent[i] = i;
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
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        DisjointSet ds = new DisjointSet(n * n);

        List<int[]> cells = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cells.add(new int[] {grid[i][j], i * n + j});
            }
        }
        cells.sort(Comparator.comparingInt(a -> a[0]));

        int[] delRow = {-1, 0, 1, 0};
        int[] delCol = {0, 1, 0, -1};

        for (int[] cell : cells) {
            int t = cell[0];
            int idx = cell[1];
            int row = idx / n, col = idx % n;

            for (int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];
                if (nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && grid[nRow][nCol] <= t) {
                    int neighborIdx = nRow * n + nCol;
                    ds.unionBySize(idx, neighborIdx);
                }
            }

            if (ds.findParent(0) == ds.findParent(n * n - 1)) {
                return t;
            }
        }
        return n * n - 1;
   

 }
}
```

---

## Complexity Analysis

- **Time Complexity**:
  - Sorting cells: \( O(n^2 \log n^2) = O(n^2 \log n) \).
  - DSU operations: \( O(n^2 \alpha(n^2)) \), where \( \alpha \) is the inverse Ackermann function.
  - Overall: \( O(n^2 \log n) \).

- **Space Complexity**: \( O(n^2) \).

---

## How to Run the Code

1. **C++**:
   - Compile using `g++ -std=c++17 -o solution solution.cpp`.
   - Run with `./solution`.

2. **Java**:
   - Compile using `javac Solution.java`.
   - Run with `java Solution`.

---

## Other Solutions

### Using Priority Queue

```cpp
class Solution {
public:

    struct T {
        int t, x, y;
        T(int a, int b, int c) : t (a), x (b), y (c){}
        bool operator< (const T &d) const {return t > d.t;}
    };

    int swimInWater(vector<vector<int>>& grid) {
        int N = grid.size (), res = 0;
        priority_queue<T> pq;
        pq.push(T(grid[0][0], 0, 0));
        vector<vector<int>> seen(N, vector<int>(N, 0));
        seen[0][0] = 1;
        static int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

        while (true) {
            auto p = pq.top ();
            pq.pop ();
            res = max(res, p.t);
            if (p.x == N - 1 && p.y == N - 1) return res;
            for (auto& d : dir) {
                int i = p.x + d[0], j = p.y + d[1];
                if (i >= 0 && i < N && j >= 0 && j < N && !seen[i][j]) {
                    seen[i][j] = 1;
                    pq.push (T(grid[i][j], i, j));
                }
            }
        }
    }
};
```

```java
// 7 ms. 80.91%
class Solution {
    private static final int[][] dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        boolean[][] visited = new boolean[n][n];
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[2] - b[2]);
        pq.add(new int[] {0, 0, grid[0][0]});
        visited[0][0] = true;
        while(!pq.isEmpty()) {
            int[] a = pq.poll();
            for(int[] d: dir) {
                int x = a[0] + d[0], y = a[1] + d[1];
                if(x < 0 || x >= n || y < 0 || y >= n) continue;
                if(!visited[x][y]) {
                    visited[x][y] = true;
                    int t = Math.max(a[2], grid[x][y]);
                    if(x == n-1 && y == n-1) return t;
                    pq.add(new int[] {x, y, t});
                }
            }
        }
        return 0;
    }
}
```

```python
    def swimInWater(self, grid):
        N, pq, seen, res = len(grid), [(grid[0][0], 0, 0)], set([(0, 0)]), 0
        while True:
            T, x, y = heapq.heappop(pq)
            res = max(res, T)
            if x == y == N - 1:
                return res
            for i, j in [(x + 1, y), (x, y + 1), (x - 1, y), (x, y - 1)]:
                if 0 <= i < N and 0 <= j < N and (i, j) not in seen:
                    seen.add((i, j))
                    heapq.heappush(pq, (grid[i][j], i, j))

```

### Binary Search + DFS

```cpp
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = grid[0][0], hi = n*n-1;
        while (low < hi) {
            int mid = low + (hi-low)/2;
            if (valid(grid, mid)) 
               hi = mid;
            else
               low = mid+1;
        }
        return low;
    }
private:
    bool valid(vector<vector<int>>& grid, int waterHeight) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        vector<int> dir({-1, 0, 1, 0, -1});
        return dfs(grid, visited, dir, waterHeight, 0, 0, n);
    }
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, vector<int>& dir, int waterHeight, int row, int col, int n) {
        visited[row][col] = 1;
        for (int i = 0; i < 4; ++i) {
            int r = row + dir[i], c = col + dir[i+1];
            if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0 && grid[r][c] <= waterHeight) {
                if (r == n-1 && c == n-1) return true;
                if (dfs(grid, visited, dir, waterHeight, r, c, n)) return true;
            }
        }
        return false;
    }
};
```

```java
// 2 ms. 99.20%
class Solution {
    int n;
    private boolean dfs(int[][] grid, int i, int j, int T, boolean[][] visited) {
        if(i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > T) return false;
        visited[i][j] = true;
        if(i == n-1 && j == n-1) return true;
        return dfs(grid, i-1, j, T, visited) || dfs(grid, i+1, j, T, visited) || dfs(grid, i, j-1, T, visited) || dfs(grid, i, j+1, T, visited);
    }
    public int swimInWater(int[][] grid) {
        this.n = grid.length;
        int l = grid[0][0], r = n*n - 1;
        while(l < r) {
            int m = l + ((r-l) >> 1);
            if(dfs(grid, 0, 0, m, new boolean[n][n])) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
}
```

- **Time Complexity**: \( O(n^2 \log n) \), 14ms.
- **Space Complexity**: \( O(n^2) \), 10.2MB.
- Binary Search range [0, n*n-1] to find the minimum feasible water level. For each water level, verification using DFS or BFS is O(n^2). DFS is slightly faster in practice.

---

### Dijkstra using Priority Queue

```cpp
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            for (int i = 0; i < 4; ++i) {
                int r = cur[1] + dir[i], c = cur[2] + dir[i+1];
                if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                    if (r == n-1 && c == n-1) return ans;
                    pq.push({grid[r][c], r, c});
                    visited[r][c] = 1;
                }
            }
        }
        return -1;
    }
};
```

- **Time Complexity**: \( O(n^2 \log n) \), 12ms.
- **Space Complexity**: \( O(n^2) \), 10.2MB.
- In every step, find lowest water level to move forward, so using PQ rather than queue.

### Dijkstra with BFS optimization

```cpp
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size(), ans = max(grid[0][0], grid[n-1][n-1]);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        visited[0][0] = 1;
        vector<int> dir({-1, 0, 1, 0, -1});
        pq.push({ans, 0, 0});
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            ans = max(ans, cur[0]);
            queue<pair<int, int>> myq;
            myq.push({cur[1], cur[2]});
            while (!myq.empty()) {
                auto p = myq.front();
                myq.pop();
                if (p.first == n-1 && p.second == n-1) return ans;
                for (int i = 0; i < 4; ++i) {
                    int r = p.first + dir[i], c = p.second + dir[i+1];
                    if (r >= 0 && r < n && c >= 0 && c < n && visited[r][c] == 0) {
                        visited[r][c] = 1;
                        if (grid[r][c] <= ans) 
                           myq.push({r, c});
                        else
                           pq.push({grid[r][c], r, c});
                    }
                }
            }
        }
        return -1;
    }
};
```

```java
// 14 ms. 41.35%
class Solution {
    private static final int[][] dir = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    public int swimInWater(int[][] grid) {
        int n = grid.length;
        int[][] dist = new int[n][n];
        for(int i = 0; i < n; i++) Arrays.fill(dist[i], n * n);
        dist[0][0] = grid[0][0];
        TreeSet<int[]> set = new TreeSet<>((a, b) -> a[2] == b[2] ? (a[0] == b[0] ? a[1] - b[1] : a[0] - b[0]) : a[2] - b[2]);
        set.add(new int[] {0, 0, grid[0][0]});
        while(!set.isEmpty()) {
            int[] p = set.pollFirst();
            int i = p[0], j = p[1], time = p[2];
            if(i == n-1 && j == n-1) break;
            for(int[] d: dir) {
                int x = i + d[0], y = j + d[1];
                if(x < 0 || x >= n || y < 0 || y >= n) continue;
                int alt = time + Math.max(0, grid[x][y] - time);
                if(alt < dist[x][y]) {
                    int[] key = {x, y, dist[x][y]};
                    set.remove(key);
                    key[2] = dist[x][y] = alt;
                    set.add(key);
                }
            }
        }
        return dist[n-1][n-1];
    }
}
```

- **Time Complexity**: \( O(n^2 \log n) \), 12ms.
- **Space Complexity**: \( O(n^2) \), 10.2MB.

---
