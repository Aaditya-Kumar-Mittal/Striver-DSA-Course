# Pre-order Traversal of Binary Trees

## Table of Contents

- [Pre-order Traversal of Binary Trees](#pre-order-traversal-of-binary-trees)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example](#example)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Example Walkthrough](#example-walkthrough)
    - [Pre-order Traversal Steps](#pre-order-traversal-steps)
    - [Final Result](#final-result)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Running the C++ Code](#running-the-c-code)
    - [Running the Java Code](#running-the-java-code)
  - [Conclusion](#conclusion)

## Introduction

Pre-order traversal is a method of visiting all the nodes in a binary tree where the nodes are recursively visited in the following order:

1. Visit the root node.
2. Traverse the left subtree.
3. Traverse the right subtree.

This README provides a comprehensive overview of pre-order traversal and the corresponding implementations in C++ and Java.

## Problem Description

Given a binary tree, traverse it using the pre-order traversal method and return the list of node values in the order they were visited.

### Example

For the binary tree:

```plaintext
      1
     / \
    2   3
   / \
  4   5
```

The pre-order traversal should return `[1, 2, 4, 5, 3]`.

## Approach

Pre-order traversal can be implemented recursively by following these steps:

- Visit the current node and add its value to the result list.
- Recursively traverse the left subtree.
- Recursively traverse the right subtree.

### Algorithm

1. Start at the root node.
2. Visit and record the current node's value.
3. Recursively traverse the left subtree.
4. Recursively traverse the right subtree.

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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }

private:
    void preorder(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;

        ans.push_back(root->val); // Visit the root node
        preorder(root->left, ans); // Traverse the left subtree
        preorder(root->right, ans); // Traverse the right subtree
    }
};
```

### Java Implementation

```java
import java.util.ArrayList;
import java.util.List;

// Node class for the binary tree
class Node {
    int data;
    Node left;
    Node right;

    // Constructor to initialize the node with a value
    Node(int val) {
        data = val;
        left = null;
        right = null;
    }
}

public class BinaryTreeTraversal {
    // Function to perform pre-order traversal of the tree and store values in 'arr'
    static void preorder(Node root, List<Integer> arr) {
        if (root == null) {
            return;
        }

        arr.add(root.data); // Visit the root node
        preorder(root.left, arr); // Traverse the left subtree
        preorder(root.right, arr); // Traverse the right subtree
    }

    // Function to initiate pre-order traversal and return the resulting list
    static List<Integer> preOrder(Node root) {
        List<Integer> arr = new ArrayList<>();
        preorder(root, arr);
        return arr;
    }

    public static void main(String[] args) {
        // Creating a sample binary tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Getting pre-order traversal
        List<Integer> result = preOrder(root);

        // Displaying the pre-order traversal result
        System.out.print("Preorder Traversal: ");
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}
```

## Example Walkthrough

Consider the following binary tree:

```plaintext
      1
     / \
    2   3
   / \
  4   5
```

### Pre-order Traversal Steps

1. Visit `1`, add `1` to the result.
2. Traverse the left subtree:
   - Visit `2`, add `2` to the result.
   - Traverse the left subtree of `2`:
     - Visit `4`, add `4` to the result.
   - Traverse the right subtree of `2`:
     - Visit `5`, add `5` to the result.
3. Traverse the right subtree:
   - Visit `3`, add `3` to the result.

### Final Result

The pre-order traversal list is `[1, 2, 4, 5, 3]`.

## Complexity Analysis

- **Time Complexity**: \( O(n) \), where \( n \) is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**:
  - **C++**: \( O(h) \), where \( h \) is the height of the tree, due to recursive call stack.
  - **Java**: \( O(h) \) for the same reason.

## How to Run the Code

### Running the C++ Code

1. Copy the C++ code into your preferred C++ IDE or editor.
2. Compile using `g++ -o solution solution.cpp`.
3. Run the executable with `./solution`.

### Running the Java Code

1. Copy the Java code into a file named `BinaryTreeTraversal.java`.
2. Compile using `javac BinaryTreeTraversal.java`.
3. Run using `java BinaryTreeTraversal`.

## Conclusion

Pre-order traversal is a simple and effective way to visit all nodes in a binary tree. This documentation has provided you with a clear understanding of how to implement this traversal in both C++ and Java.
