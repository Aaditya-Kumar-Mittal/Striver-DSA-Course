# Morris In-order Traversal of Binary Trees

## Table of Contents

- [Morris In-order Traversal of Binary Trees](#morris-in-order-traversal-of-binary-trees)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example](#example)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Running the C++ Code](#running-the-c-code)
    - [Running the Java Code](#running-the-java-code)

## Introduction

Morris in-order traversal is an efficient way to traverse a binary tree without using additional space for a stack or recursion. This method temporarily modifies the tree structure, allowing traversal in **O(n)** time with **O(1)** space complexity.

## Problem Description

Given a binary tree, perform an in-order traversal iteratively using the Morris traversal technique and return a list of the node values in the order they were visited.

### Example

For the binary tree:

```plaintext
      1
     / \
    2   3
   / \
  4   5
```

The in-order traversal should return `[4, 2, 5, 1, 3]`.

## Approach

Morris traversal for in-order involves modifying the tree temporarily to create links between nodes that allow for traversal without a stack. The traversal starts with a dummy node linked to the root of the tree, ensuring we can always return to the root.

### Algorithm

1. Create a dummy node and link it to the root of the tree.
2. Initialize an empty result list to store the traversal order.
3. While the current node is not null:
   - If the current node has a left child:
     - Find the rightmost node in the left subtree (the predecessor).
     - If the predecessor’s right child is null, set it to the current node (creating a temporary link) and move to the left child.
   - If the predecessor’s right child points to the current node (indicating the left subtree has been visited):
     - Process the current node (add its value to the result list).
     - Restore the original tree structure by breaking the temporary link and move to the right child.
4. Continue until all nodes are processed, and return the result list.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        TreeNode* current = root;

        while (current != NULL) {
            if (current->left == NULL) {
                result.push_back(current->val); // Process current node
                current = current->right; // Move to right child
            } else {
                // Find the predecessor
                TreeNode* predecessor = current->left;
                while (predecessor->right != NULL && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                // Make a temporary link
                if (predecessor->right == NULL) {
                    predecessor->right = current;
                    current = current->left; // Move to left child
                } else {
                    // Process current node
                    predecessor->right = NULL; // Restore the tree structure
                    result.push_back(current->val);
                    current = current->right; // Move to right child
                }
            }
        }

        return result;
    }
};
```

### Java Implementation

```java
import java.util.ArrayList;
import java.util.List;

// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }
}

public class Solution {
    public List<Integer> inorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        TreeNode current = root;

        while (current != null) {
            if (current.left == null) {
                result.add(current.val); // Process current node
                current = current.right; // Move to right child
            } else {
                // Find the predecessor
                TreeNode predecessor = current.left;
                while (predecessor.right != null && predecessor.right != current) {
                    predecessor = predecessor.right;
                }

                // Make a temporary link
                if (predecessor.right == null) {
                    predecessor.right = current;
                    current = current.left; // Move to left child
                } else {
                    // Process current node
                    predecessor.right = null; // Restore the tree structure
                    result.add(current.val);
                    current = current.right; // Move to right child
                }
            }
        }

        return result;
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \) where \( n \) is the number of nodes in the tree. Each node is visited a constant number of times.
- **Space Complexity**: \( O(1) \) as the traversal does not use any additional data structures beyond pointers.

## How to Run the Code

### Running the C++ Code

1. Copy the C++ code into your preferred C++ IDE or editor.
2. Compile using `g++ -o solution solution.cpp`.
3. Run the executable with `./solution`.

### Running the Java Code

1. Copy the Java code into a file named `Solution.java`.
2. Compile using `javac Solution.java`.
3. Run using `java Solution`.

This completes the explanation and implementation of Morris in-order traversal in C++ and Java. This method is efficient for traversing binary trees while minimizing space usage.
