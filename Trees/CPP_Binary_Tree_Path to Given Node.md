# Path to Given Node

## Table of Contents

- [Path to Given Node](#path-to-given-node)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Steps](#key-steps)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Explanation](#explanation)

---

## Introduction

The problem requires finding the path from the **root** node to a given node \( B \) in a binary tree. The path is represented as a list of node values.

## Problem Description

### Input

1. A binary tree \( A \) containing \( N \) nodes.
2. An integer \( B \) representing the target node's value.

### Output

An array containing the path from the root node to node \( B \) in order.

### Constraints

- \( 1 \leq N \leq 10^5 \)
- \( 1 \leq \text{Data Values of Each Node} \leq N \)
- \( 1 \leq B \leq N \)
- No two nodes in the tree have the same data values.
- Node \( B \) is guaranteed to exist.

---

## Approach

The task can be solved using a **depth-first search (DFS)** approach. Starting from the root:

1. Traverse the tree.
2. Keep track of the current path using a list.
3. When the target node \( B \) is found, return the path.

### Key Steps

- If the current node matches \( B \), we store the path.
- If the target node is found in either the left or right subtree, propagate the result upwards.
- If neither subtree contains the target node, backtrack.

---

## C++ Implementation

```cpp
#include <vector>
using namespace std;

// Definition for binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool getPath(TreeNode* root, vector<int>& path, int target) {
        if (!root) return false;

        // Add current node to path
        path.push_back(root->val);

        // Check if current node is the target node
        if (root->val == target) return true;

        // Recurse to left and right subtrees
        if (getPath(root->left, path, target) || getPath(root->right, path, target))
            return true;

        // Backtrack if target is not found in either subtree
        path.pop_back();
        return false;
    }

    vector<int> solve(TreeNode* root, int B) {
        vector<int> path;
        if (!root) return path;

        getPath(root, path, B);
        return path;
    }
};
```

---

## Java Implementation

```java
import java.util.ArrayList;
import java.util.List;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class Solution {
    public boolean getPath(TreeNode root, List<Integer> path, int target) {
        if (root == null) return false;

        // Add current node to path
        path.add(root.val);

        // Check if current node is the target node
        if (root.val == target) return true;

        // Recurse to left and right subtrees
        if (getPath(root.left, path, target) || getPath(root.right, path, target))
            return true;

        // Backtrack if target is not found in either subtree
        path.remove(path.size() - 1);
        return false;
    }

    public List<Integer> solve(TreeNode root, int B) {
        List<Integer> path = new ArrayList<>();
        if (root == null) return path;

        getPath(root, path, B);
        return path;
    }

    public static void main(String[] args) {
        // Example usage
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(7);

        Solution solution = new Solution();
        List<Integer> path = solution.solve(root, 5);
        System.out.println(path);  // Output: [1, 2, 5]
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the tree. In the worst case, we might need to traverse the entire tree.
- **Space Complexity**: \(O(H)\), where \(H\) is the height of the tree. This space is required for the recursion stack and storing the path.

### Explanation

1. **Time**: Each node is visited once.
2. **Space**: In a balanced tree, \(H = O(\log N)\); in a skewed tree, \(H = O(N)\).

This documentation provides a step-by-step explanation along with complete code implementations in **C++** and **Java** for solving the problem of finding the path to a given node in a binary tree.
