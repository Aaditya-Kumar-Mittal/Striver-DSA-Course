# Morris Inorder Traversal

## Table of Contents

- [Morris Inorder Traversal](#morris-inorder-traversal)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Inorder Traversal](#inorder-traversal)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)

## Introduction

**Morris Inorder Traversal** is a method of traversing a binary tree without using recursion or a stack. It modifies the tree structure temporarily to achieve an \(O(1)\) space complexity.

## Problem Description

Perform an **inorder traversal** of a binary tree using the **Morris Traversal** technique.

### Inorder Traversal

In an inorder traversal, we visit nodes in the following order:

1. Left subtree
2. Root node
3. Right subtree

## Approach

1. Start from the root node.
2. For each node:
   - If the left child is `null`, print the current node and move to the right child.
   - Otherwise, find the rightmost node in the left subtree:
     - If the rightmost node's right pointer is `null`, set it to the current node (create a temporary thread) and move to the left child.
     - If the rightmost node's right pointer is the current node, revert the changes, print the current node, and move to the right child.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> inorder;
    TreeNode *current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            inorder.push_back(current->data);
            current = current->right;
        } else {
            TreeNode *previous = current->left;

            // Find the rightmost node in the left subtree
            while (previous->right && previous->right != current) {
                previous = previous->right;
            }

            if (previous->right == nullptr) {
                // Create a thread (temporary link to the current node)
                previous->right = current;
                current = current->left;
            } else {
                // Revert the changes (remove the thread)
                previous->right = nullptr;
                inorder.push_back(current->data);
                current = current->right;
            }
        }
    }

    return inorder;
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of nodes in the tree. Each node is visited at most twice.
- **Space Complexity:**  
  \(O(1)\), as no additional space is used apart from the result vector.

## How to Run the Code

1. Save the implementation in a file, e.g., `MorrisInorder.cpp`.
2. Compile the file using:

   ```bash
   g++ -o MorrisInorder MorrisInorder.cpp
   ```

3. Run the executable:

   ```bash
   ./MorrisInorder
   ```
