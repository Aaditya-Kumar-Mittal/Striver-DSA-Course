# Floyd-Warshall Algorithm

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Floyd-Warshall Algorithm](#floyd-warshall-algorithm)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The **Floyd-Warshall Algorithm** is a graph algorithm used to find the shortest paths between all pairs of vertices in a weighted and directed graph. It works even if the graph contains negative edge weights, as long as there are no negative weight cycles.

This algorithm is implemented using a dynamic programming approach and uses a **distance matrix** where \( \text{mat}[i][j] \) denotes the shortest distance from vertex \(i\) to vertex \(j\).

---

## Problem Description

### Input

- **`mat`**: An \(n \times n\) adjacency matrix representing the graph:
  - **\( \text{mat}[i][j] \): The weight of the edge from vertex \(i\) to vertex \(j\).**
  - **If \( \text{mat}[i][j] = -1 \), it indicates no direct edge between \(i\) and \(j\).**

### Output

- The modified matrix where \( \text{mat}[i][j] \) contains the shortest distance between vertices \(i\) and \(j\). If no path exists, \( \text{mat}[i][j] = -1 \).

---

## Examples

### Example 1

**Input:**

```plaintext
mat = [[0, 25], [-1, 0]]
```

**Output:**

```plaintext
[[0, 25], [-1, 0]]
```

**Explanation:**
The shortest distance between all pairs is already given.

---

### Example 2

**Input:**

```plaintext
mat = [[0, 1, 43], [1, 0, 6], [-1, -1, 0]]
```

**Output:**

```plaintext
[[0, 1, 7], [1, 0, 6], [-1, -1, 0]]
```

**Explanation:**

- Path from \(0 \to 2\): \(0 \to 1 \to 2\), cost = \(1 + 6 = 7\), which is less than \(43\).

---

### Constraints

- \(1 \leq \text{mat.size()} \leq 100\)
- \(-1 \leq \text{mat}[i][j] \leq 1000\)

---

## Approach

### Algorithm

1. **Initialization**:
   - Replace \( \text{mat}[i][j] = -1 \) with a large number (e.g., \(10^9\)) to indicate no path.
   - Set \( \text{mat}[i][i] = 0 \) for all \(i\).

2. **Iterative Updates**:
   - For each vertex \(k\), consider it as an intermediate vertex.
   - For every pair of vertices \(i\) and \(j\):
     - Update \( \text{mat}[i][j] = \min(\text{mat}[i][j], \text{mat}[i][k] + \text{mat}[k][j]) \).

3. **Restoration**:
   - Replace all \( \text{mat}[i][j] = 10^9 \) back to \(-1\) to indicate no path.

4. **Output**:
   - Return the modified distance matrix.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();

        // Step 1: Replace -1 with a large number and initialize diagonal to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1)
                    mat[i][j] = 1e9;
                if (i == j)
                    mat[i][j] = 0;
            }
        }

        // Step 2: Floyd-Warshall main loop
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        // Step 3: Restore unreachable paths to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1e9)
                    mat[i][j] = -1;
            }
        }
    }
};

// Driver Code
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution obj;
        obj.shortestDistance(matrix);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "~\n";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public void shortestDistance(int[][] mat) {
        int n = mat.length;

        // Step 1: Replace -1 with a large number and initialize diagonal to 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1)
                    mat[i][j] = (int) 1e9;
                if (i == j)
                    mat[i][j] = 0;
            }
        }

        // Step 2: Floyd-Warshall main loop
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = Math.min(mat[i][j], mat[i][via] + mat[via][j]);
                }
            }
        }

        // Step 3: Restore unreachable paths to -1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == (int) 1e9)
                    mat[i][j] = -1;
            }
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[][] matrix = new int[n][n];

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    matrix[i][j] = sc.nextInt();
                }
            }

            Solution obj = new Solution();
            obj.shortestDistance(matrix);

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    System.out.print(matrix[i][j] + " ");
                }
                System.out.println();
            }
            System.out.println("~");
        }

        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Overall**: \(O(V^3)\), where \(V\) is the number of vertices.

### Space Complexity

- \(O(1)\), as the matrix is updated in place.

---

## How to Run the Code

### For C++

1. Save the code to a `.cpp` file.
2. Compile using `g++ filename.cpp`.
3. Run the compiled executable and provide input as specified.

### For Java

1. Save the code to a `.java` file.
2. Compile using `javac filename.java`.
3. Run the program using `java filename`.
