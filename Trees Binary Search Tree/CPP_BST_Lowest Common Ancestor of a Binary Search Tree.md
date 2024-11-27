# Lowest Common Ancestor of a Binary Search Tree

## Table of Contents

- [Lowest Common Ancestor of a Binary Search Tree](#lowest-common-ancestor-of-a-binary-search-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Python Implementation](#python-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Python](#for-python)
  - [Other Solution](#other-solution)
    - [Java Iterative Solution](#java-iterative-solution)

---

## Introduction

The problem involves finding the **Lowest Common Ancestor (LCA)** of two nodes `p` and `q` in a Binary Search Tree (BST). The **LCA** of two nodes is the lowest node in the BST that has both `p` and `q` as descendants (a node can also be a descendant of itself).

---

## Problem Description

You are given the root of a Binary Search Tree and two nodes `p` and `q`. Your task is to determine their Lowest Common Ancestor.

---

### Examples

#### Example 1

**Tree Representation:**

```bash
       6
      / \
     2   8
    / \   / \
   0   4 7   9
      / \
     3   5
```

**Input:** `root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 8`  
**Output:** `6`  
**Explanation:**  
The LCA of nodes `2` and `8` is `6`, as `6` is the lowest node that is an ancestor of both.

---

#### Example 2

**Tree Representation:**

```bash
       6
      / \
     2   8
    / \   / \
   0   4 7   9
      / \
     3   5
```

**Input:** `root = [6,2,8,0,4,7,9,null,null,3,5], p = 2, q = 4`  
**Output:** `2`  
**Explanation:**  
The LCA of nodes `2` and `4` is `2`, as `2` is an ancestor of itself and its descendant `4`.

---

#### Example 3

**Tree Representation:**

```bash
       2
      /
     1
```

**Input:** `root = [2,1], p = 2, q = 1`  
**Output:** `2`  
**Explanation:**  
The LCA of nodes `2` and `1` is `2`, as `2` is the ancestor of itself and `1`.

---

### Constraints

1. The number of nodes in the tree is in the range `[2, 10^5]`.
2. `-10^9 <= Node.val <= 10^9`.
3. All `Node.val` values are unique.
4. `p != q`.
5. `p` and `q` are guaranteed to exist in the BST.

---

## Approach

We utilize the properties of a BST:

1. **Left Subtree:** Contains values smaller than the root.
2. **Right Subtree:** Contains values greater than the root.

### Algorithm

- Start from the root node.
- Compare the root's value with `p` and `q`:
  1. If both `p` and `q` are smaller than the root, move to the left subtree.
  2. If both `p` and `q` are greater than the root, move to the right subtree.
  3. If `p` and `q` split (i.e., one is smaller and the other is larger), or if the root is equal to one of `p` or `q`, the current node is the LCA.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base condition: if root is NULL
        if (root == nullptr)
            return nullptr;

        // Current node's value
        int current = root->val;

        // If both p and q are greater than the current node
        if (current < p->val && current < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        // If both p and q are smaller than the current node
        if (current > p->val && current > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If split happens here, this is the LCA
        return root;
    }
};
```

---

### Python Implementation

```python
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        # Base condition: if root is None
        if not root:
            return None

        # Current node's value
        current = root.val

        # If both p and q are greater than the current node
        if current < p.val and current < q.val:
            return self.lowestCommonAncestor(root.right, p, q)

        # If both p and q are smaller than the current node
        if current > p.val and current > q.val:
            return self.lowestCommonAncestor(root.left, p, q)

        # If split happens here, this is the LCA
        return root
```

---

## Complexity Analysis

### Time Complexity

- The algorithm traverses the height of the tree:
  - For a balanced BST, height = **O(log n)**.
  - For a skewed BST, height = **O(n)**.

### Space Complexity

- **Recursive Approach:** The recursion stack depth is equal to the height of the tree, which is **O(h)**.
- **Iterative Approach (Alternative):** Uses constant space, **O(1)**.

---

## How to Run the Code

### For C++

1. Create a BST using the `TreeNode` structure.
2. Instantiate the `Solution` class and call the `lowestCommonAncestor` method with the `root`, `p`, and `q` nodes.

### For Python

1. Create a BST using the `TreeNode` class.
2. Instantiate the `Solution` class and call the `lowestCommonAncestor` method with the `root`, `p`, and `q` nodes.

## Other Solution

### Java Iterative Solution

```java
public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
    while ((root.val - p.val) * (root.val - q.val) > 0)
        root = p.val < root.val ? root.left : root.right;
    return root;
}
```
