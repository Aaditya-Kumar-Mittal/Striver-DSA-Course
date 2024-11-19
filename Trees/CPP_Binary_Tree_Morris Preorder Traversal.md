# Morris Preorder Traversal

## Table of Contents

- [Morris Preorder Traversal](#morris-preorder-traversal)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Preorder Traversal](#preorder-traversal)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

**Morris Preorder Traversal** is a tree traversal technique that avoids recursion and stack usage by temporarily modifying the tree structure, ensuring \(O(1)\) space complexity.

## Problem Description

Perform a **preorder traversal** of a binary tree using the **Morris Traversal** technique.

### Preorder Traversal

In a preorder traversal, we visit nodes in the following order:

1. Root node
2. Left subtree
3. Right subtree

## Approach

1. Start from the root node.
2. For each node:
   - If the left child is `null`, process the current node and move to the right child.
   - Otherwise, find the rightmost node in the left subtree:
     - If the rightmost node's right pointer is `null`, create a temporary thread to the current node, process the current node, and move to the left child.
     - If the rightmost node's right pointer is the current node, revert the changes and move to the right child.

## Detailed Explanation of Code

### C++ Implementation

```cpp
/************************************************************
    Following is the TreeNode class structure:
    template <typename T>
    class TreeNode {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/

#include <bits/stdc++.h>
using namespace std;

vector<int> preOrder(TreeNode<int> *root) {
    vector<int> preorder;
    TreeNode<int> *current = root;

    while (current != nullptr) {
        if (current->left == nullptr) {
            preorder.push_back(current->data);
            current = current->right;
        } else {
            TreeNode<int> *previous = current->left;

            // Find the rightmost node in the left subtree
            while (previous->right && previous->right != current) {
                previous = previous->right;
            }

            if (previous->right == nullptr) {
                // Create a thread (temporary link to the current node)
                previous->right = current;
                preorder.push_back(current->data);
                current = current->left;
            } else {
                // Revert the changes (remove the thread)
                previous->right = nullptr;
                current = current->right;
            }
        }
    }

    return preorder;
}
```

### Java Implementation

```java
/************************************************************
    Following is the TreeNode class structure:
    class TreeNode<T> {
        T data;
        TreeNode<T> left, right;

        TreeNode(T data) {
            this.data = data;
            this.left = null;
            this.right = null;
        }
    }
************************************************************/

import java.util.*;

public class Solution {
    public static List<Integer> preOrder(TreeNode<Integer> root) {
        List<Integer> preorder = new ArrayList<>();
        TreeNode<Integer> current = root;

        while (current != null) {
            if (current.left == null) {
                preorder.add(current.data);
                current = current.right;
            } else {
                TreeNode<Integer> previous = current.left;

                // Find the rightmost node in the left subtree
                while (previous.right != null && previous.right != current) {
                    previous = previous.right;
                }

                if (previous.right == null) {
                    // Create a thread (temporary link to the current node)
                    previous.right = current;
                    preorder.add(current.data);
                    current = current.left;
                } else {
                    // Revert the changes (remove the thread)
                    previous.right = null;
                    current = current.right;
                }
            }
        }

        return preorder;
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of nodes in the tree. Each node is visited at most twice.

- **Space Complexity:**  
  \(O(1)\), excluding the output list, as no additional space is used.

## How to Run the Code

### For C++

1. Save the implementation in a file, e.g., `MorrisPreorder.cpp`.
2. Compile the file:

   ```bash
   g++ -o MorrisPreorder MorrisPreorder.cpp
   ```

3. Run the executable:

   ```bash
   ./MorrisPreorder
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
