# Diameter of Binary Tree

## Table of Contents

- [Diameter of Binary Tree](#diameter-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Optimized Approach](#optimized-approach)
    - [Brute-force Approach](#brute-force-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The **diameter** of a binary tree is defined as the length of the longest path between any two nodes in the tree. This path may or may not pass through the root, and its length is represented by the number of edges between the nodes.

## Problem Description

Given the root of a binary tree, return the length of the diameter of the tree.

### Examples

1. **Input:** `root = [1,2,3,4,5]`  
   **Output:** `3`  
   **Explanation:** The longest path goes through nodes [4,2,1,3] or [5,2,1,3] with 3 edges.

2. **Input:** `root = [1,2]`  
   **Output:** `1`  
   **Explanation:** The longest path has only one edge.

### Constraints

- The number of nodes in the tree is in the range \([1, 10^4]\).
- \(-100 \leq \text{Node.val} \leq 100\)

## Approach

To find the diameter of the tree, we calculate the height of each node's left and right subtrees and use that information to track the longest path found.

### Optimized Approach

1. Use a helper function `findHeightOptimized` that calculates the height of a node’s subtrees while updating a `diameter` variable.
2. For each node, we calculate the height of its left and right subtrees.
3. Update the `diameter` if the sum of the left and right heights is greater than the current maximum.
4. Return the height of the current node, which is `1 + max(left height, right height)`.

### Brute-force Approach

1. Use a helper function `findHeightBrute` that calculates the diameter at each node.
2. For each node, compute the height of its left and right subtrees and update the `diameter` if the path through that node is longer.
3. Recursively calculate the diameter for the left and right subtrees.

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
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findHeightOptimized(root, diameter); // Call optimized helper
        return diameter;
    }

private:
    // Optimized helper function
    int findHeightOptimized(TreeNode* root, int& diameter) {
        if (root == nullptr) {
            return 0;
        }

        int lh = findHeightOptimized(root->left, diameter);  // Left subtree height
        int rh = findHeightOptimized(root->right, diameter); // Right subtree height

        diameter = max(diameter, lh + rh); // Update diameter
        return 1 + max(lh, rh);            // Return height of subtree
    }

    // Brute-force approach (alternative method)
    int findHeightBrute(TreeNode* root, int& diameter) {
        if (!root) {
            return 0;
        }

        int lh = findHeight(root->left); // Left subtree height
        int rh = findHeight(root->right); // Right subtree height

        diameter = max(diameter, lh + rh); // Update diameter

        // Recursively find the diameter in left and right subtrees
        findHeightBrute(root->left, diameter);
        findHeightBrute(root->right, diameter);

        return diameter;
    }

    // Helper to find height (for brute-force approach)
    int findHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1 + max(lh, rh); // Return height
    }
};
```

### Java Implementation

```java
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode() { val = 0; left = null; right = null; }
    TreeNode(int x) { val = x; left = null; right = null; }
    TreeNode(int x, TreeNode left, TreeNode right) { this.val = x; this.left = left; this.right = right; }
}

public class Solution {
    public int diameterOfBinaryTree(TreeNode root) {
        int[] diameter = new int[1];
        findHeightOptimized(root, diameter);
        return diameter[0];
    }

    // Optimized helper function
    private int findHeightOptimized(TreeNode root, int[] diameter) {
        if (root == null) {
            return 0;
        }

        int lh = findHeightOptimized(root.left, diameter); // Left subtree height
        int rh = findHeightOptimized(root.right, diameter); // Right subtree height

        diameter[0] = Math.max(diameter[0], lh + rh); // Update diameter
        return 1 + Math.max(lh, rh); // Return height of subtree
    }

    // Brute-force helper function (alternative method)
    private int findHeightBrute(TreeNode root, int[] diameter) {
        if (root == null) {
            return 0;
        }

        int lh = findHeight(root.left); // Left subtree height
        int rh = findHeight(root.right); // Right subtree height

        diameter[0] = Math.max(diameter[0], lh + rh); // Update diameter

        findHeightBrute(root.left, diameter); // Diameter for left subtree
        findHeightBrute(root.right, diameter); // Diameter for right subtree

        return diameter[0];
    }

    // Helper to find height (for brute-force approach)
    private int findHeight(TreeNode root) {
        if (root == null) {
            return 0;
        }
        int lh = findHeight(root.left);
        int rh = findHeight(root.right);
        return 1 + Math.max(lh, rh);
    }
}
```

## Complexity Analysis

- **Time Complexity**:

  - Optimized Approach: \(O(n)\), where \(n\) is the number of nodes in the tree, since each node is visited once.
  - Brute-force Approach: \(O(n^2)\), as it repeatedly calculates the height for each subtree.

- **Space Complexity**: \(O(h)\), where \(h\) is the height of the tree, due to the recursion stack.

## How to Run the Code

### For C++

1. Copy the C++ code into your preferred C++ IDE or text editor.
2. Compile the code using a C++ compiler, e.g., `g++ -o solution solution.cpp`.
3. Run the compiled program with `./solution`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This README provides an in-depth explanation and code examples for finding the diameter of a binary tree in C++ and Java. You can use this as a reference for understanding and implementing the solution efficiently.
