# Balanced Binary Tree

## Table of Contents

- [Balanced Binary Tree](#balanced-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The goal of this problem is to determine if a binary tree is height-balanced. A height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differs by more than one.

## Problem Description

Given a binary tree, determine if it is height-balanced.

### Examples

1. **Input:** `root = [3,9,20,null,null,15,7]`  
   **Output:** `true`
2. **Input:** `root = [1,2,2,3,3,null,null,4,4]`  
   **Output:** `false`
3. **Input:** `root = []`  
   **Output:** `true`

### Constraints

- The number of nodes in the tree is in the range \([0, 5000]\).
- \(-10^4 \leq \text{Node.val} \leq 10^4\)

## Approach

We can use a depth-first search (DFS) approach to traverse the tree and calculate the height of each subtree while checking for balance. If at any point we find that a subtree is not balanced (the height difference between the left and right subtree is greater than 1), we can immediately return false.

1. We create a helper function, `dfsHeight`, which calculates the height of a subtree.
2. If a subtree is unbalanced, we return -1.
3. If both subtrees are balanced, we return the height of the tree.

## Detailed Explanation of Code

### C++ Implementation

```cpp
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
public:
    bool isBalanced(TreeNode* root) {
        return dfsHeight(root) != -1; // Check if tree is balanced
    }

private:
    int dfsHeight(TreeNode* root) {
        if (!root) {
            return 0; // Base case: height of an empty subtree
        }

        int lh = dfsHeight(root->left); // Height of left subtree
        if (lh == -1) { // Left subtree is unbalanced
            return -1;
        }

        int rh = dfsHeight(root->right); // Height of right subtree
        if (rh == -1) { // Right subtree is unbalanced
            return -1;
        }

        // Check if current node is balanced
        if (abs(lh - rh) > 1) {
            return -1; // Current subtree is unbalanced
        }

        return max(lh, rh) + 1; // Return height of current subtree
    }
};
```

### Java Implementation

```java
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode() {
        val = 0;
        left = null;
        right = null;
    }

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }

    TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public boolean isBalanced(TreeNode root) {
        return dfsHeight(root) != -1; // Check if tree is balanced
    }

    private int dfsHeight(TreeNode root) {
        if (root == null) {
            return 0; // Base case: height of an empty subtree
        }

        int lh = dfsHeight(root.left); // Height of left subtree
        if (lh == -1) { // Left subtree is unbalanced
            return -1;
        }

        int rh = dfsHeight(root.right); // Height of right subtree
        if (rh == -1) { // Right subtree is unbalanced
            return -1;
        }

        // Check if current node is balanced
        if (Math.abs(lh - rh) > 1) {
            return -1; // Current subtree is unbalanced
        }

        return Math.max(lh, rh) + 1; // Return height of current subtree
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \) where \( n \) is the number of nodes in the tree. Each node is visited once.
- **Space Complexity**: \( O(h) \) where \( h \) is the height of the tree due to the recursion stack.

## How to Run the Code

### For C++

1. Copy the C++ code into your preferred C++ IDE or text editor.
2. Compile the code using a C++ compiler, e.g., `g++ -o solution solution.cpp`.
3. Run the compiled program with `./solution`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This README provides a comprehensive guide to solving the balanced binary tree problem using a depth-first search approach in both C++ and Java. You can use this documentation for educational purposes or to implement the solution in your projects.
