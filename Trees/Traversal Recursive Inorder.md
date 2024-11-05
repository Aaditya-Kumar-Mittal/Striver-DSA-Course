# In-order Traversal of Binary Trees - README Documentation

## Table of Contents

- [In-order Traversal of Binary Trees - README Documentation](#in-order-traversal-of-binary-trees---readme-documentation)
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
    - [In-order Traversal Steps](#in-order-traversal-steps)
    - [Final Result](#final-result)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Running the C++ Code](#running-the-c-code)
    - [Running the Java Code](#running-the-java-code)
  - [Additional Resources](#additional-resources)
  - [Conclusion](#conclusion)

## Introduction

In-order traversal is a method of visiting all the nodes in a binary tree where the nodes are recursively visited in the following order:

1. Traverse the left subtree.
2. Visit the root node.
3. Traverse the right subtree.

This README provides a comprehensive overview of in-order traversal and the corresponding implementations in C++ and Java.

## Problem Description

Given a binary tree, traverse it using the in-order traversal method and return the list of node values in the order they were visited.

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

In-order traversal can be implemented recursively by following these steps:

- Recursively traverse the left subtree.
- Visit the current node and add its value to the result list.
- Recursively traverse the right subtree.

### Algorithm

1. Start at the root node.
2. Recursively traverse the left subtree.
3. Visit and record the current node's value.
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

private:
    void inorder(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;

        inorder(root->left, ans); // Traverse the left subtree
        ans.push_back(root->val); // Visit the root node
        inorder(root->right, ans); // Traverse the right subtree
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
    // Function to perform in-order traversal of the tree and store values in 'arr'
    static void inorder(Node root, List<Integer> arr) {
        if (root == null) {
            return;
        }

        inorder(root.left, arr); // Traverse the left subtree
        arr.add(root.data); // Visit the root node
        inorder(root.right, arr); // Traverse the right subtree
    }

    // Function to initiate in-order traversal and return the resulting list
    static List<Integer> inOrder(Node root) {
        List<Integer> arr = new ArrayList<>();
        inorder(root, arr);
        return arr;
    }

    public static void main(String[] args) {
        // Creating a sample binary tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Getting in-order traversal
        List<Integer> result = inOrder(root);

        // Displaying the in-order traversal result
        System.out.print("In-order Traversal: ");
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

### In-order Traversal Steps

1. Traverse the left subtree of `1`:
   - Traverse the left subtree of `2`:
     - Visit `4`, add `4` to the result.
   - Visit `2`, add `2` to the result.
   - Traverse the right subtree of `2`:
     - Visit `5`, add `5` to the result.
2. Visit `1`, add `1` to the result.
3. Traverse the right subtree of `1`:
   - Visit `3`, add `3` to the result.

### Final Result

The in-order traversal list is `[4, 2, 5, 1, 3]`.

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

## Additional Resources

For more information and an in-depth explanation, you can refer to the [LeetCode Editorial for Binary Tree Inorder Traversal](https://leetcode.com/problems/binary-tree-inorder-traversal/editorial).

## Conclusion

In-order traversal is an essential tree traversal method that visits nodes in a specific order. This documentation has provided you with a clear understanding of how to implement in-order traversal in both C++ and Java.
