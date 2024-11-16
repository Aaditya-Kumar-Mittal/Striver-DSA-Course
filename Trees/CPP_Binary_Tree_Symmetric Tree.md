# Symmetric Tree

## Table of Contents

- [Symmetric Tree](#symmetric-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Problem Statement](#problem-statement)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Observations](#key-observations)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

A **Symmetric Tree** is one where the left and right subtrees of every node are mirror images of each other. The problem asks you to check if a given binary tree is symmetric or not.

### Problem Statement

Given the root of a binary tree, determine whether it is symmetric around its center (i.e., whether the tree is a mirror of itself).

## Problem Description

You are given the root of a binary tree. The goal is to check whether the tree is symmetric around its center.

### Examples

1. **Input Tree**:

    ```plaintext
            1
           / \
          2   2
         / \ / \
        3  4 4  3
    ```

   **Output**: `true`
   **Explanation**: The tree is symmetric because the left and right subtrees are mirror images of each other.

2. **Input Tree**:

    ```plaintext
            1
           / \
          2   2
           \   \
            3   3
    ```

   **Output**: `false`
   **Explanation**: The tree is not symmetric because the left subtree has a right child (3), while the right subtree has a left child (3).

### Constraints

- The number of nodes in the tree is in the range \([1, 1000]\).
- \(-100 \leq \text{Node.val} \leq 100\).

## Approach

We can solve this problem using a **recursive approach** to compare the left and right subtrees of the binary tree.

### Key Observations

1. The tree is symmetric if and only if the left and right subtrees are mirror images of each other.
2. To check if two subtrees are mirror images, we need to check the following:
   - The root values of both subtrees must be equal.
   - The left subtree of the left node must be a mirror of the right subtree of the right node, and vice versa.

### Algorithm

1. First, check if the root is null. If it is, the tree is symmetric by definition.
2. Use a helper function to recursively check if the left and right subtrees are mirror images.
3. Compare the left child of the left subtree with the right child of the right subtree, and the right child of the left subtree with the left child of the right subtree.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Helper function to check if two trees are symmetric.
bool isSymmetrical(TreeNode* left, TreeNode* right) {
    // If both nodes are null, they are symmetric.
    if (!left && !right) return true;

    // If one of the nodes is null, the trees are not symmetric.
    if (!left || !right) return false;

    // If the values of the nodes don't match, they are not symmetric.
    if (left->val != right->val) return false;

    // Recursively check the left subtree and right subtree in mirror positions.
    return isSymmetrical(left->left, right->right) && 
           isSymmetrical(left->right, right->left);
}

// Main function to check if the tree is symmetric.
bool isSymmetric(TreeNode* root) {
    // If root is null, the tree is symmetric by definition.
    return root == nullptr || isSymmetrical(root->left, root->right);
}

int main() {
    // Example tree creation
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    bool result = isSymmetric(root);
    cout << (result ? "true" : "false") << endl;

    return 0;
}
```

### Java Implementation

```java
public class Solution {

    // Definition for a binary tree node.
    public static class TreeNode {
        int val;
        TreeNode left, right;

        TreeNode(int x) {
            val = x;
            left = right = null;
        }
    }

    // Helper function to check if two trees are symmetric.
    public boolean isSymmetrical(TreeNode left, TreeNode right) {
        // If both nodes are null, they are symmetric.
        if (left == null && right == null) return true;

        // If one of the nodes is null, the trees are not symmetric.
        if (left == null || right == null) return false;

        // If the values of the nodes don't match, they are not symmetric.
        if (left.val != right.val) return false;

        // Recursively check the left subtree and right subtree in mirror positions.
        return isSymmetrical(left.left, right.right) && 
               isSymmetrical(left.right, right.left);
    }

    // Main function to check if the tree is symmetric.
    public boolean isSymmetric(TreeNode root) {
        // If root is null, the tree is symmetric by definition.
        return root == null || isSymmetrical(root.left, root.right);
    }

    public static void main(String[] args) {
        // Example tree creation
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(2);
        root.left.left = new TreeNode(3);
        root.left.right = new TreeNode(4);
        root.right.left = new TreeNode(4);
        root.right.right = new TreeNode(3);

        Solution solution = new Solution();
        boolean result = solution.isSymmetric(root);
        System.out.println(result ? "true" : "false");
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the binary tree. We visit each node once during the recursion.
  
- **Space Complexity**: \(O(H)\), where \(H\) is the height of the tree. This space is used by the recursion stack.

---

## How to Run the Code

### For C++

1. Copy the C++ code into a file named `SymmetricTree.cpp`.
2. Compile the code using a C++ compiler:

   ```bash
   g++ -o symmetricTree SymmetricTree.cpp
   ```

3. Run the compiled program:

   ```bash
   ./symmetricTree
   ```

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler:

   ```bash
   javac Solution.java
   ```

3. Run the compiled program:

   ```bash
   java Solution
   ```

This documentation provides a complete guide for implementing the **Symmetric Tree** problem in both C++ and Java. It includes the problem description, approach, code, complexity analysis, and instructions on how to run the code.F
