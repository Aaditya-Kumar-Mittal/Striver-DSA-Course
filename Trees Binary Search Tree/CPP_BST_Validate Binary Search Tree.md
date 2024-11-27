# Validate Binary Search Tree

## Table of Contents

- [Validate Binary Search Tree](#validate-binary-search-tree)
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
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The problem involves determining whether a binary tree is a valid Binary Search Tree (BST). A valid BST satisfies the following:

- The left subtree contains nodes with values **less than** the root's value.
- The right subtree contains nodes with values **greater than** the root's value.
- Both left and right subtrees must themselves be valid BSTs.

---

## Problem Description

You are given the root of a binary tree. Determine if it is a valid BST.

### Examples

#### Example 1

**Input:**

```bash
    2
   / \
  1   3
```

**Output:**  
`true`

#### Example 2

**Input:**

```bash
    5
   / \
  1   4
     / \
    3   6
```

**Output:**  
`false`  
**Explanation:** The right subtree of the root contains a value `4`, which violates the BST property.

### Constraints

- The number of nodes in the tree is in the range `[1, 10^4]`.
- `-2^31 <= Node.val <= 2^31 - 1`.

---

## Approach

We use a **recursive approach** with the following steps:

1. Pass the minimum (`minVal`) and maximum (`maxVal`) permissible values for the current node.
2. For each node:
   - If its value is outside the range `[minVal, maxVal]`, return `false`.
   - Recursively check the left and right subtrees with updated bounds.
3. A `nullptr` node is valid by definition.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <climits>
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // Helper function to validate the BST
    bool isValidBST(TreeNode* root, long minVal, long maxVal) {
        if (root == nullptr) return true;

        // Check if the current node's value violates BST properties
        if (root->val <= minVal || root->val >= maxVal) return false;

        // Recursively validate the left and right subtrees
        return isValidBST(root->left, minVal, root->val) &&
               isValidBST(root->right, root->val, maxVal);
    }

public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};
```

---

### Java Implementation

```java
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private boolean isValidBST(TreeNode root, long minVal, long maxVal) {
        if (root == null) return true;

        // Check if the current node's value violates BST properties
        if (root.val <= minVal || root.val >= maxVal) return false;

        // Recursively validate the left and right subtrees
        return isValidBST(root.left, minVal, root.val) &&
               isValidBST(root.right, root.val, maxVal);
    }

    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, Long.MIN_VALUE, Long.MAX_VALUE);
    }
}
```

---

## Complexity Analysis

1. **Time Complexity:**

   - Each node is visited exactly once, so the time complexity is **O(n)**, where `n` is the number of nodes.

2. **Space Complexity:**
   - The recursive stack may go up to a depth equal to the height of the tree. In the worst case (skewed tree), this is **O(n)**. For a balanced tree, it is **O(log n)**.

---

## How to Run the Code

### For C++

1. Compile the code using `g++` or any modern C++ compiler.
2. Provide the binary tree structure and call the `isValidBST` function with the root node.

### For Java

1. Compile the code using `javac`.
2. Create a `TreeNode` structure, and pass the root to the `isValidBST` method.
