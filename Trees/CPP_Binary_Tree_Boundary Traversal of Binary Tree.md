# Boundary Traversal of Binary Tree

## Table of Contents

- [Boundary Traversal of Binary Tree](#boundary-traversal-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Identify the Parts of the Boundary](#identify-the-parts-of-the-boundary)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [C++](#c)
    - [Java](#java)

## Introduction

The **Boundary Traversal** of a binary tree is a traversal technique in which we traverse all the boundary nodes of the binary tree in an anti-clockwise direction, starting from the root node.

Boundary nodes include:

1. Left boundary nodes, excluding the leaf node at the end.
2. Leaf nodes from left to right.
3. Right boundary nodes in reverse order, excluding the leaf node at the start.

## Problem Description

You are given a binary tree with `n` nodes. Traverse the boundary nodes in an anti-clockwise direction starting from the root node.

### Examples

1. **Example 1**:

   - **Input:** Binary tree structured as follows:

     ```plaintext
           10
          /   \
         5     20
        / \    / \
       3   8  18  25
           /
          7
     ```

   - **Output:** `[10, 5, 3, 7, 18, 25, 20]`
   - **Explanation:** The nodes on the left boundary are `[10, 5, 3]`, the leaf nodes are `[3, 7, 18, 25]`, and the nodes on the right boundary (in reverse) are `[20]`.

2. **Example 2**:

   - **Input:** Binary tree structured as follows:

     ```plaintext
              100
             /    \
           50     150
          /  \    /   \
        25   75 140   200
          \   /
          30 70
            /
           35
     ```

   - **Output:** `[100, 50, 25, 30, 35, 70, 80, 140, 200, 150]`

### Constraints

- \(1 \leq n \leq 10000\), where \(n\) is the total number of nodes in the binary tree.
- **Time Limit:** 1 second.

## Approach

### Identify the Parts of the Boundary

To solve this problem, we divide the boundary into three parts:

1. **Left Boundary**: Traverse from the root to the leftmost node, excluding the leaf node.
2. **Leaf Nodes**: Traverse all leaf nodes from left to right.
3. **Right Boundary**: Traverse from the rightmost node up to the root, excluding the leaf node, in reverse order.

Here are the helper functions used in the approach:

- `isLeaf(TreeNode<int>* root)`: Checks if a node is a leaf node.
- `addLeftBoundary(TreeNode<int>* root, vector<int>& res)`: Adds nodes in the left boundary excluding the root and the last leaf.
- `addLeaves(TreeNode<int>* root, vector<int>& res)`: Adds all leaf nodes from left to right.
- `addRightBoundary(TreeNode<int>* root, vector<int>& res)`: Adds nodes in the right boundary in reverse order, excluding the root and the last leaf.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>

template <typename T>
class TreeNode {
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

    ~TreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

// Helper function to check if a node is a leaf node
bool isLeaf(TreeNode<int>* root) {
    return !root->left && !root->right;
}

// Helper function to add the left boundary (excluding leaves) to the result
void addLeftBoundary(TreeNode<int>* root, std::vector<int>& res) {
    TreeNode<int>* current = root->left;
    while (current) {
        if (!isLeaf(current)) {
            res.push_back(current->data);
        }
        if (current->left) {
            current = current->left;
        } else {
            current = current->right;
        }
    }
}

// Helper function to add all leaf nodes to the result
void addLeaves(TreeNode<int>* root, std::vector<int>& res) {
    if (isLeaf(root)) {
        res.push_back(root->data);
        return;
    }
    if (root->left) {
        addLeaves(root->left, res);
    }
    if (root->right) {
        addLeaves(root->right, res);
    }
}

// Helper function to add the right boundary (excluding leaves) to the result in reverse order
void addRightBoundary(TreeNode<int>* root, std::vector<int>& res) {
    TreeNode<int>* current = root->right;
    std::vector<int> temp;
    while (current) {
        if (!isLeaf(current)) {
            temp.push_back(current->data);
        }
        if (current->right) {
            current = current->right;
        } else {
            current = current->left;
        }
    }
    // Add the right boundary nodes in reverse order
    for (int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

// Main function for boundary traversal
std::vector<int> traverseBoundary(TreeNode<int>* root) {
    std::vector<int> res;
    if (!root) return res;

    // Start with the root node (if it's not a leaf)
    if (!isLeaf(root)) {
        res.push_back(root->data);
    }

    // Add the left boundary, leaf nodes, and the right boundary
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}
```

### Java Implementation

```java
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}

public class Solution {

    private boolean isLeaf(TreeNode root) {
        return root.left == null && root.right == null;
    }

    private void addLeftBoundary(TreeNode root, List<Integer> res) {
        TreeNode current = root.left;
        while (current != null) {
            if (!isLeaf(current)) {
                res.add(current.data);
            }
            if (current.left != null) {
                current = current.left;
            } else {
                current = current.right;
            }
        }
    }

    private void addLeaves(TreeNode root, List<Integer> res) {
        if (isLeaf(root)) {
            res.add(root.data);
            return;
        }
        if (root.left != null) addLeaves(root.left, res);
        if (root.right != null) addLeaves(root.right, res);
    }

    private void addRightBoundary(TreeNode root, List<Integer> res) {
        TreeNode current = root.right;
        List<Integer> temp = new ArrayList<>();
        while (current != null) {
            if (!isLeaf(current)) {
                temp.add(current.data);
            }
            if (current.right != null) {
                current = current.right;
            } else {
                current = current.left;
            }
        }
        Collections.reverse(temp);
        res.addAll(temp);
    }

    public List<Integer> traverseBoundary(TreeNode root) {
        List<Integer> res = new ArrayList<>();
        if (root == null) return res;

        if (!isLeaf(root)) {
            res.add(root.data);
        }

        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);

        return res;
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the tree. Each node is visited only once.
  - Adding the left boundary of the Binary Tree results in the traversal of the left side of the tree which is proportional to the the height of the three hence \(O(h)\) ie. \(O(log2n)\)). In the worst case that the tree is skewed the complexity would be \(O(n)\).
  - For the bottom traversal of the Binary Tree, traversing the leaves is proportional to \(O(n)\) as preorder traversal visits every node once.
  - Adding the right boundary of the Binary Tree results in the traversal of the right side of the tree which is proportional to the the height of the three hence \(O(h)\) ie. \(O(log2n)\)). In the worst case that the tree is skewed the complexity would be \(O(n)\).
- **Space Complexity**: \(O(n)\), for storing the boundary nodes in the result list.

## How to Run the Code

### C++

1. Copy the C++ code into your preferred C++ development environment.
2. Compile the code with a C++ compiler, e.g., `g++ -o boundary_traversal boundary_traversal.cpp`.
3. Run the compiled program with `./boundary_traversal`.

### Java

1. Copy the Java code into your preferred Java development environment.
2. Compile the Java file with `javac Solution.java`.
3. Run the compiled class with `java Solution`.

This code will give the boundary traversal of the binary tree as described.
