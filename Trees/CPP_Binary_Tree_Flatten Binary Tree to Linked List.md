# Flatten Binary Tree to Linked List

## Table of Contents

- [Flatten Binary Tree to Linked List](#flatten-binary-tree-to-linked-list)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)
    - [Constraints](#constraints)
    - [Follow-Up](#follow-up)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The task is to flatten a binary tree into a "linked list" in-place, following the preorder traversal order.

## Problem Description

Given the root of a binary tree:

- Flatten the tree into a "linked list."
- The right child pointer should point to the next node in the preorder traversal.
- The left child pointer should always be `null`.

### Example 1

**Input:**  
`root = [1,2,5,3,4,null,6]`  
**Output:**  
`[1,null,2,null,3,null,4,null,5,null,6]`

### Example 2

**Input:**  
`root = []`  
**Output:**  
`[]`

### Example 3

**Input:**  
`root = [0]`  
**Output:**  
`[0]`

### Constraints

- \(0 \leq \text{Number of Nodes} \leq 2000\)
- \(-100 \leq \text{Node Value} \leq 100\)

### Follow-Up

Can this be done **in-place** with \(O(1)\) extra space?

## Approach

1. Start from the root node.
2. For each node:
   - If it has a left child:
     - Find the rightmost node of the left subtree.
     - Link the right subtree of the current node to the right of this rightmost node.
     - Move the left subtree to the right and set the left pointer to `null`.
   - Move to the right child.

## Detailed Explanation of Code

### C++ Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode *current = root;
        
        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode *previous = current->left;

                // Find the rightmost node of the left subtree
                while (previous->right != nullptr) {
                    previous = previous->right;
                }

                // Connect the right subtree to the rightmost node
                previous->right = current->right;

                // Move the left subtree to the right
                current->right = current->left;
                current->left = nullptr;
            }

            // Move to the next node (right)
            current = current->right;
        }
    }
};
```

### Java Implementation

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    public void flatten(TreeNode root) {
        TreeNode current = root;

        while (current != null) {
            if (current.left != null) {
                TreeNode previous = current.left;

                // Find the rightmost node of the left subtree
                while (previous.right != null) {
                    previous = previous.right;
                }

                // Connect the right subtree to the rightmost node
                previous.right = current.right;

                // Move the left subtree to the right
                current.right = current.left;
                current.left = null;
            }

            // Move to the next node (right)
            current = current.right;
        }
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of nodes. Each node is visited once.

- **Space Complexity:**  
  \(O(1)\), as the solution is done in-place without using extra space for recursion or stacks.

## How to Run the Code

### For C++

1. Save the implementation in a file, e.g., `FlattenBinaryTree.cpp`.
2. Compile the file:

   ```bash
   g++ -o FlattenBinaryTree FlattenBinaryTree.cpp
   ```

3. Run the executable:

   ```bash
   ./FlattenBinaryTree
   ```

### For Java

1. Save the implementation in a file, e.g., `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
