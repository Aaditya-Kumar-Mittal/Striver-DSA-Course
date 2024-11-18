# Lowest Common Ancestor of a Binary Tree

## Table of Contents

- [Lowest Common Ancestor of a Binary Tree](#lowest-common-ancestor-of-a-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Definition](#definition)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [Summary](#summary)

---

## Problem Description

Given a binary tree, find the **lowest common ancestor (LCA)** of two given nodes `p` and `q`.

### Definition

The **lowest common ancestor** is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants (where we allow a node to be a descendant of itself).

### Examples

#### Example 1

- **Input**: `root = [3,5,1,6,2,0,8,null,null,7,4]`, `p = 5`, `q = 1`

  ```bash
        3
       / \
      5   1
     / \  / \
    6  2 0  8
       / \
      7   4
  ```

- **Output**: `3`
- **Explanation**: The LCA of nodes `5` and `1` is `3`.

#### Example 2

- **Input**: `root = [3,5,1,6,2,0,8,null,null,7,4]`, `p = 5`, `q = 4`
- **Output**: `5`
- **Explanation**: The LCA of nodes `5` and `4` is `5` because a node can be a descendant of itself.

#### Example 3

- **Input**: `root = [1,2]`, `p = 1`, `q = 2`

  ```bash
      1
     /
    2
  ```

- **Output**: `1`

### Constraints

- The number of nodes is in the range `[2, 10⁵]`.
- `-10⁹ <= Node.val <= 10⁹`.
- All `Node.val` are unique.
- `p != q`.
- Both `p` and `q` exist in the tree.

---

## Approach

The problem can be solved using a **recursive Depth-First Search (DFS)** approach. Here's how:

1. **Base Cases**:

   - If `root` is `null`, return `null`.
   - If `root` is either `p` or `q`, return `root`.

2. **Recursive Search**:

   - Search for `p` and `q` in the left subtree.
   - Search for `p` and `q` in the right subtree.

3. **Result Evaluation**:
   - If both left and right recursive calls return non-null values, the current node (`root`) is the LCA.
   - If only one of the calls returns a non-null value, propagate that value upwards as the LCA.

---

## C++ Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q)
            return root;  // Base case: found either p, q, or null

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;  // Both p and q found in different subtrees

        return left ? left : right;  // Either one node found or propagate null
    }
};
```

---

## Java Implementation

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null || root == p || root == q)
            return root;  // Base case: found either p, q, or null

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null)
            return root;  // Both p and q found in different subtrees

        return left != null ? left : right;  // Either one node found or propagate null
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **O(N)**: Each node in the tree is visited once, where `N` is the number of nodes.

### Space Complexity

- **O(H)**: The recursion stack can go as deep as the height of the tree `H`. In the worst case, this is `O(N)` for a skewed tree, and `O(log N)` for a balanced tree.

---

## Summary

This solution efficiently finds the **Lowest Common Ancestor** using recursion. The algorithm leverages the properties of a binary tree to perform a single pass through the tree, ensuring optimal time complexity. Both the **C++** and **Java** implementations follow the same recursive approach.
