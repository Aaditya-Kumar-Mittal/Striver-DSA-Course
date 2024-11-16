# Right Side View of Binary Tree

## Table of Contents

- [Right Side View of Binary Tree](#right-side-view-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Breadth-First Search (BFS)](#breadth-first-search-bfs)
    - [Depth-First Search (DFS)](#depth-first-search-dfs)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [BFS Implementation (C++)](#bfs-implementation-c)
    - [DFS Implementation (C++)](#dfs-implementation-c)
    - [Right Side View of Binary Tree (Java Implementation)](#right-side-view-of-binary-tree-java-implementation)
      - [BFS Implementation (Java)](#bfs-implementation-java)
      - [DFS Implementation (Java)](#dfs-implementation-java)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Conclusion](#conclusion)

## Introduction

The **Right Side View of a Binary Tree** problem requires you to determine which nodes are visible when the tree is viewed from the right side. The solution involves traversing the binary tree and selecting the rightmost node at each level.

## Problem Description

Given the root of a binary tree, return the right side view of the tree, which consists of the rightmost node at each level from top to bottom.

### Examples

1. **Input**:

   ```plaintext
   root = [1, 2, 3, null, 5, null, 4]
   ```

   **Output**: `[1, 3, 4]`

   **Explanation**:

   - At level 0, you see node `1`.
   - At level 1, you see node `3`.
   - At level 2, you see node `4`.

2. **Input**:

   ```plaintext
   root = [1, null, 3]
   ```

   **Output**: `[1, 3]`

3. **Input**:

   ```plaintext
   root = []
   ```

   **Output**: `[]`

### Constraints

- \(0 \leq \text{Number of nodes} \leq 100\)
- \(-100 \leq \text{Node value} \leq 100\)

## Approach

### Breadth-First Search (BFS)

In BFS, we traverse the tree level by level using a queue. At each level, the rightmost node is the last node visited.

1. Use a queue to store nodes at each level.
2. For each level, iterate through all nodes and store the last visited node.
3. Append the last node of each level to the result.

### Depth-First Search (DFS)

DFS explores each branch as deeply as possible. By prioritizing the right subtree, we can collect the rightmost node at each level.

1. Start with the root node and track the current level.
2. If visiting a new level for the first time, store the node value.
3. Recursively visit the right child before the left child to prioritize the rightmost view.

## Detailed Explanation of Code

### BFS Implementation (C++)

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            int lastValue = 0;

            for (int i = 0; i < size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                lastValue = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            res.push_back(lastValue);
        }

        return res;
    }
};
```

### DFS Implementation (C++)

```cpp
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

private:
    void dfs(TreeNode* node, int level, vector<int>& res) {
        if (!node) return;

        if (res.size() == level) {
            res.push_back(node->val);
        }

        dfs(node->right, level + 1, res);
        dfs(node->left, level + 1, res);
    }
};
```

### Right Side View of Binary Tree (Java Implementation)

#### BFS Implementation (Java)

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(root);

        while (!queue.isEmpty()) {
            int size = queue.size();
            int lastValue = 0;

            for (int i = 0; i < size; i++) {
                TreeNode node = queue.poll();
                lastValue = node.val;

                if (node.left != null) queue.add(node.left);
                if (node.right != null) queue.add(node.right);
            }

            res.add(lastValue);
        }

        return res;
    }
}

```

#### DFS Implementation (Java)

```java
import java.util.*;

class Solution {
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        dfs(root, 0, res);
        return res;
    }

    private void dfs(TreeNode node, int level, List<Integer> res) {
        if (node == null) return;

        // If visiting this level for the first time, add the node's value
        if (res.size() == level) {
            res.add(node.val);
        }

        // Recur for right subtree first to ensure right side view
        dfs(node.right, level + 1, res);
        dfs(node.left, level + 1, res);
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the tree.
  - Each node is visited exactly once.
- **Space Complexity**:
  - BFS: \(O(W)\), where \(W\) is the maximum width of the tree (nodes at the widest level).
  - DFS: \(O(H)\), where \(H\) is the height of the tree due to the recursion stack.

## How to Run the Code

### For C++

1. **Copy the code** into a file named `RightSideView.cpp`.
2. **Compile the code**:

   ```bash
   g++ -o rightview RightSideView.cpp
   ```

3. **Run the executable**:

   ```bash
   ./rightview
   ```

### For Java

1. Save the Java code in a file, e.g., `RightSideView.java`.
2. Compile the file:

   ```bash
   javac RightSideView.java
   ```

3. Run the program:

   ```bash
   java RightSideView
   ```

## Conclusion

The **Right Side View of a Binary Tree** problem can be efficiently solved using either BFS or DFS. The BFS solution iterates level by level, ensuring that the rightmost node is captured at each level. The DFS solution provides a recursive approach, prioritizing the right subtree to capture the correct node for each level.
