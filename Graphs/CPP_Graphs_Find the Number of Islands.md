# Find the Number of Islands

## Table of Contents

- [Find the Number of Islands](#find-the-number-of-islands)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
    - [Python Implementation](#python-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
    - [For Python](#for-python)
  - [Other Solutions](#other-solutions)
    - [C++ Solution - 1](#c-solution---1)
    - [C++ Solution - 2](#c-solution---2)

---

## Introduction

This problem involves identifying "islands" in a grid. An island is a group of connected cells with value `'1'` (representing land), surrounded by `'0'` (representing water) or the grid boundary. Connectivity includes horizontal, vertical, and diagonal connections.

---

## Problem Description

Given a 2D grid of size \( n \times m \), find the number of islands.

### Examples

#### Example 1

**Input:**  
`grid = [[0,1],[1,0],[1,1],[1,0]]`  
**Output:**  
`1`  

**Explanation:**  
All land cells are connected, forming a single island.

#### Example 2

**Input:**  
`grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]`  
**Output:**  
`2`  

**Explanation:**  
There are two islands: one in blue and one in red.

### Constraints

- \( 1 \leq n, m \leq 500 \)
- `grid[i][j]` is either `'0'` or `'1'`.
- Time Complexity: \( O(n \times m) \)  
- Space Complexity: \( O(n \times m) \)  

---

## Approach

1. **Traversal Method**:  
   Use **BFS (Breadth-First Search)** or **DFS (Depth-First Search)** to explore the grid.
2. **Visited Array**:  
   Maintain a `visited` array to ensure each cell is processed only once.
3. **Island Counting**:  
   Each BFS/DFS starting from an unvisited land cell increments the island count.

Steps:

- Traverse the grid.
- For each unvisited `'1'`, initiate a BFS/DFS to mark all connected land cells as visited.
- Increment the island count for each BFS/DFS call.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid, int n, int m) {
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        // Directions for 8 neighbors
        int directions[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (auto dir : directions) {
                int neighRow = row + dir[0];
                int neighCol = col + dir[1];
                if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m &&
                    grid[neighRow][neighCol] == '1' && !visited[neighRow][neighCol]) {
                    visited[neighRow][neighCol] = 1;
                    q.push({neighRow, neighCol});
                }
            }
        }
    }

public:
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        
        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid, n, m);
                }
            }
        }
        return count;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private void bfs(int i, int j, boolean[][] visited, char[][] grid, int n, int m) {
        visited[i][j] = true;
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[] {i, j});
        
        int[][] directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
        
        while (!queue.isEmpty()) {
            int[] cell = queue.poll();
            int row = cell[0], col = cell[1];
            for (int[] dir : directions) {
                int neighRow = row + dir[0];
                int neighCol = col + dir[1];
                if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m &&
                    grid[neighRow][neighCol] == '1' && !visited[neighRow][neighCol]) {
                    visited[neighRow][neighCol] = true;
                    queue.offer(new int[] {neighRow, neighCol});
                }
            }
        }
    }
    
    public int numIslands(char[][] grid) {
        int n = grid.length;
        if (n == 0) return 0;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        int count = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid, n, m);
                }
            }
        }
        return count;
    }
}
```

---

### Python Implementation

```python
from collections import deque

class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        def bfs(i, j):
            queue = deque([(i, j)])
            visited[i][j] = True

            while queue:
                row, col = queue.popleft()
                for dr, dc in directions:
                    neigh_row, neigh_col = row + dr, col + dc
                    if 0 <= neigh_row < n and 0 <= neigh_col < m and \
                            grid[neigh_row][neigh_col] == '1' and not visited[neigh_row][neigh_col]:
                        visited[neigh_row][neigh_col] = True
                        queue.append((neigh_row, neigh_col))

        n, m = len(grid), len(grid[0])
        visited = [[False] * m for _ in range(n)]
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1), (-1, -1), (-1, 1), (1, -1), (1, 1)]

        count = 0
        for row in range(n):
            for col in range(m):
                if not visited[row][col] and grid[row][col] == '1':
                    count += 1
                    bfs(row, col)

        return count
```

---

## Complexity Analysis

1. **Time Complexity**: \( O(n \times m) \)  
   Every cell is processed at most once.

2. **Space Complexity**: \( O(n \times m) \)  
   Space used for the visited array and the queue in BFS.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `num_islands.cpp`.
2. Compile using:  
   `g++ num_islands.cpp -o num_islands`
3. Run the executable:  
   `./num_islands`

### For Java

1. Save the code in a file, e.g., `Solution.java`.
2. Compile using:  
   `javac Solution.java`
3. Run using:  
   `java Solution`

### For Python

1. Save the code in a file, e.g., `num_islands.py`.
2. Run using:  
   `python num_islands.py`

## Other Solutions

### C++ Solution - 1

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
private:
  void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid, int n, int m)
  {

    visited[i][j] = 1;
    queue<pair<int, int>> q;
    q.push({i, j});

    while (!q.empty())
    {
      int row = q.front().first;
      int col = q.front().second;
      q.pop();

      for (int delRow = -1; delRow <= 1; delRow++)
      {
        for (int delCol = -1; delCol <= 1; delCol++)
        {
          int neighRow = row + delRow;

          int neighCol = col + delCol;

          if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m &&
              grid[neighRow][neighCol] == '1' && !visited[neighRow][neighCol])
          {
            visited[neighRow][neighCol] = 1;
            q.push({neighRow, neighCol});
          }
        }
      }
    }
  }

public:
  // Function to find the number of islands.
  int numIslands(vector<vector<char>> &grid)
  {

    int n = grid.size();
    if (n == 0)
      return 0; // Edge case: empty grid
    int m = grid[0].size();

    // Create a visited array
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int count = 0;

    // Traverse the grid
    for (int row = 0; row < n; row++)
    {
      for (int col = 0; col < m; col++)
      {
        // If the cell is unvisited and is land, perform BFS
        if (!visited[row][col] && grid[row][col] == '1')
        {
          count++;
          bfs(row, col, visited, grid, n, m);
        }
      }
    }

    return count;
  }
};

//{ Driver Code Starts.
int main()
{
  int tc;
  cin >> tc;
  while (tc--)
  {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, '#'));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> grid[i][j];
      }
    }
    Solution obj;
    int ans = obj.numIslands(grid);
    cout << ans << '\n';

    cout << "~" << "\n";
  }
  return 0;
}
// } Driver Code Ends
```

### C++ Solution - 2

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void bfs(int i, int j, vector<vector<int>> &visited, vector<vector<char>> &grid, int n, int m) {
        visited[i][j] = 1;
        queue<pair<int, int>> q;
        q.push({i, j});

        // Directions for 8-connected neighbors
        int dRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int dCol[] = {-1, 0, 1, 1, 1, 0, -1, -1};

        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            // Check all 8 possible neighbors
            for (int k = 0; k < 8; k++) {
                int neighRow = row + dRow[k];
                int neighCol = col + dCol[k];

                // Check boundary conditions and if the neighbor is land and unvisited
                if (neighRow >= 0 && neighRow < n && neighCol >= 0 && neighCol < m &&
                    grid[neighRow][neighCol] == '1' && !visited[neighRow][neighCol]) {
                    visited[neighRow][neighCol] = 1;
                    q.push({neighRow, neighCol});
                }
            }
        }
    }

public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>> &grid) {
        int n = grid.size();
        if (n == 0) return 0; // Edge case: empty grid
        int m = grid[0].size();

        // Create a visited array
        vector<vector<int>> visited(n, vector<int>(m, 0));

        int count = 0;

        // Traverse the grid
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If the cell is unvisited and is land, perform BFS
                if (!visited[row][col] && grid[row][col] == '1') {
                    count++;
                    bfs(row, col, visited, grid, n, m);
                }
            }
        }

        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
```
