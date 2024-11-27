# Delete Node in a Binary Search Tree

## Table of Contents

- [Delete Node in a Binary Search Tree](#delete-node-in-a-binary-search-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Rules](#rules)
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

The task is to delete a node with a specific key from a **Binary Search Tree (BST)**. After the deletion, the resultant tree should remain a valid BST.

---

## Problem Description

Given:

- A BST represented by its root node.
- A key value to delete.

### Rules

1. Locate the node with the given key.
2. If the key exists, remove it while maintaining the BST structure.
3. If the key does not exist, return the tree as is.

---

### Examples

#### Example 1

**Input Tree:**

```bash
        5
       / \
      3   6
     / \    \
    2   4    7
```

**Key to Delete:** `3`  
**Output Tree:**

```bash
        5
       / \
      4   6
     /      \
    2        7
```

---

#### Example 2

**Input Tree:**

```bash
        5
       / \
      3   6
     / \    \
    2   4    7
```

**Key to Delete:** `0`  
**Output Tree:**

```bash
        5
       / \
      3   6
     / \    \
    2   4    7
```

**Explanation:** The key `0` does not exist in the tree, so the tree remains unchanged.

---

#### Example 3

**Input Tree:**

```bash
        5
       / \
      3   6
     / \    \
    2   4    7
```

**Key to Delete:** `5`  
**Output Tree:**

```bash
        6
       / \
      3   7
     / \
    2   4
```

---

## Constraints

1. The number of nodes is in the range `[0, 10⁴]`.
2. `-10⁵ <= Node.val <= 10⁵`.
3. All node values are **unique**.
4. `root` is a valid BST.
5. `-10⁵ <= key <= 10⁵`.

---

## Approach

1. **Search for the Node:** Traverse the BST to find the node matching the key.
2. **Handle Deletion Cases:**
   - If the node has no children, simply remove it.
   - If the node has one child, replace the node with its child.
   - If the node has two children, replace it with the rightmost node of its left subtree (or leftmost node of its right subtree) and adjust links accordingly.
3. Return the modified root node.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    // Helper function to find the rightmost node in the left subtree
    TreeNode* findLastRight(TreeNode* root) {
        while (root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    // Helper function to handle node deletion
    TreeNode* deleteHelper(TreeNode* root) {
        if (root->left == nullptr) {
            return root->right;
        } else if (root->right == nullptr) {
            return root->left;
        }

        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;

        return root->left;
    }

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;

        if (root->val == key) {
            return deleteHelper(root);
        }

        TreeNode* current = root;
        while (current != nullptr) {
            if (key < current->val) {
                if (current->left != nullptr && current->left->val == key) {
                    current->left = deleteHelper(current->left);
                    break;
                } else {
                    current = current->left;
                }
            } else {
                if (current->right != nullptr && current->right->val == key) {
                    current->right = deleteHelper(current->right);
                    break;
                } else {
                    current = current->right;
                }
            }
        }

        return root;
    }
};
```

---

### Java Implementation

```java
// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class Solution {
    // Helper function to find the rightmost node in the left subtree
    private TreeNode findLastRight(TreeNode root) {
        while (root.right != null) {
            root = root.right;
        }
        return root;
    }

    // Helper function to handle node deletion
    private TreeNode deleteHelper(TreeNode root) {
        if (root.left == null) {
            return root.right;
        } else if (root.right == null) {
            return root.left;
        }

        TreeNode rightChild = root.right;
        TreeNode lastRight = findLastRight(root.left);
        lastRight.right = rightChild;

        return root.left;
    }

    // Function to delete the node with the given key
    public TreeNode deleteNode(TreeNode root, int key) {
        if (root == null) return null;

        if (root.val == key) {
            return deleteHelper(root);
        }

        TreeNode current = root;

        while (current != null) {
            if (key < current.val) {
                if (current.left != null && current.left.val == key) {
                    current.left = deleteHelper(current.left);
                    break;
                } else {
                    current = current.left;
                }
            } else {
                if (current.right != null && current.right.val == key) {
                    current.right = deleteHelper(current.right);
                    break;
                } else {
                    current = current.right;
                }
            }
        }

        return root;
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**  
  The time complexity is `O(h)`, where `h` is the height of the tree. In the worst case (unbalanced tree), `h = n`, making the complexity `O(n)`. In a balanced tree, `h = log(n)`.

- **Space Complexity:**  
  The space complexity is `O(h)` due to the recursive stack for finding the rightmost node.

---

## How to Run the Code

### For C++

1. Include the above C++ implementation in your code editor or IDE.
2. Create a test case with the BST structure.
3. Call the `deleteNode()` function with the root node and key.

### For Java

1. Include the Java implementation in a class file.
2. Create test cases using the `TreeNode` structure.
3. Call the `deleteNode()` method with the root node and key.
