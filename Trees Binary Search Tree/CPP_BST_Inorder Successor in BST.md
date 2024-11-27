# Inorder Successor in BST

## Table of Contents

- [Inorder Successor in BST](#inorder-successor-in-bst)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
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

The task is to find the **inorder successor** of a node `k` in a given **Binary Search Tree (BST)**.  
The **inorder successor** of a node is the node with the smallest key greater than `k`. If no such node exists, return `-1`.

---

## Problem Description

Given a BST, determine the **inorder successor** of a node `k`. The BST is represented as a tree structure, and the reference to the node `k` is provided.

---

### Examples

#### Example 1

**Input:**  
Tree:

```bash
    2
   / \
  1   3
```

`k = 2`

**Output:**  
`3`

**Explanation:**  
Inorder traversal: `1 -> 2 -> 3`.  
The successor of `2` is `3`.

---

#### Example 2

**Input:**  
Tree:

```bash
        20
       /  \
      8    22
     / \
    4   12
       /  \
      10   14
```

`k = 8`

**Output:**  
`10`

**Explanation:**  
Inorder traversal: `4 -> 8 -> 10 -> 12 -> 14 -> 20 -> 22`.  
The successor of `8` is `10`.

---

#### Example 3

**Input:**  
Tree:

```bash
    2
   / \
  1   3
```

`k = 3`

**Output:**  
`-1`

**Explanation:**  
Inorder traversal: `1 -> 2 -> 3`.  
Node `3` has no successor.

---

### Constraints

- `1 <= n <= 10^5`, where `n` is the number of nodes.
- Node values are unique.

---

## Approach

1. **If `k` has a right subtree:**  
   The successor is the smallest value in `k`'s right subtree.
2. **If `k` has no right subtree:**  
   Use the BST property to traverse the tree and find the first ancestor of `k` for which `k` is in its left subtree.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node structure
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // Function to find the inorder successor of the node x in BST
    Node* inOrderSuccessor(Node* root, Node* x) {
        Node* successor = nullptr;

        while (root != nullptr) {
            if (x->data >= root->data) {
                root = root->right; // Move right
            } else {
                successor = root; // Potential successor
                root = root->left; // Move left
            }
        }
        return successor;
    }
};
```

---

### Java Implementation

```java
// Tree Node structure
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        this.left = this.right = null;
    }
}

class Solution {
    // Function to find the inorder successor of a node in a BST
    public TreeNode inOrderSuccessor(TreeNode root, TreeNode x) {
        TreeNode successor = null;

        while (root != null) {
            if (x.val >= root.val) {
                root = root.right; // Move right
            } else {
                successor = root; // Potential successor
                root = root.left; // Move left
            }
        }
        return successor;
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**

  - In the worst case, traverse the height of the tree: `O(h)`.  
    For a balanced BST, `h = log(n)`; for a skewed BST, `h = n`.

- **Space Complexity:**
  - **Iterative solution:** `O(1)` (no extra space).
  - **Recursive solution (not implemented):** `O(h)` due to function call stack.

---

## How to Run the Code

### For C++

1. Compile the code using a C++ compiler:

   ```bash
   g++ -o solution solution.cpp
   ```

2. Run the executable:

   ```bash
   ./solution
   ```

### For Java

1. Compile the Java code:

   ```bash
   javac Solution.java
   ```

2. Run the program:

   ```bash
   java Solution
   ```
