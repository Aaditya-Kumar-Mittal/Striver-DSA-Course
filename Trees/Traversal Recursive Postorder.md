# Post-order Traversal of Binary Trees - README Documentation

## Table of Contents

- [Post-order Traversal of Binary Trees - README Documentation](#post-order-traversal-of-binary-trees---readme-documentation)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example](#example)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Additional Resources](#additional-resources)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Example Walkthrough](#example-walkthrough)
    - [Post-order Traversal Steps](#post-order-traversal-steps)
    - [Final Result](#final-result)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Running the C++ Code](#running-the-c-code)
    - [Running the Java Code](#running-the-java-code)
  - [Conclusion](#conclusion)

## Introduction

Post-order traversal is a method of visiting all the nodes in a binary tree where the nodes are recursively visited in the following order:

1. Traverse the left subtree.
2. Traverse the right subtree.
3. Visit the root node.

This README provides a comprehensive overview of post-order traversal and the corresponding implementations in C++ and Java.

## Problem Description

Given a binary tree, traverse it using the post-order traversal method and return the list of node values in the order they were visited.

### Example

For the binary tree:

```plaintext
      1
     / \
    2   3
   / \
  4   5
```

The post-order traversal should return `[4, 5, 2, 3, 1]`.

## Approach

Post-order traversal can be implemented recursively by following these steps:

- Recursively traverse the left subtree.
- Recursively traverse the right subtree.
- Visit the current node and add its value to the result list.

### Algorithm

1. Start at the root node.
2. Recursively traverse the left subtree.
3. Recursively traverse the right subtree.
4. Visit and record the current node's value.

## Additional Resources

For more information and an in-depth explanation, you can refer to the [LeetCode Editorial for Binary Tree Postorder Traversal](https://leetcode.com/problems/binary-tree-postorder-traversal/editorial).

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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }

private:
    void postorder(TreeNode* root, vector<int>& ans) {
        if (!root)
            return;

        postorder(root->left, ans); // Traverse the left subtree
        postorder(root->right, ans); // Traverse the right subtree
        ans.push_back(root->val); // Visit the root node
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
    // Function to perform post-order traversal of the tree and store values in 'arr'
    static void postorder(Node root, List<Integer> arr) {
        if (root == null) {
            return;
        }

        postorder(root.left, arr); // Traverse the left subtree
        postorder(root.right, arr); // Traverse the right subtree
        arr.add(root.data); // Visit the root node
    }

    // Function to initiate post-order traversal and return the resulting list
    static List<Integer> postOrder(Node root) {
        List<Integer> arr = new ArrayList<>();
        postorder(root, arr);
        return arr;
    }

    public static void main(String[] args) {
        // Creating a sample binary tree
        Node root = new Node(1);
        root.left = new Node(2);
        root.right = new Node(3);
        root.left.left = new Node(4);
        root.left.right = new Node(5);

        // Getting post-order traversal
        List<Integer> result = postOrder(root);

        // Displaying the post-order traversal result
        System.out.print("Post-order Traversal: ");
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

### Post-order Traversal Steps

1. Traverse the left subtree of `1`:
   - Traverse the left subtree of `2`:
     - Visit `4`, add `4` to the result.
   - Traverse the right subtree of `2`:
     - Visit `5`, add `5` to the result.
   - Visit `2`, add `2` to the result.
2. Traverse the right subtree of `1`:
   - Visit `3`, add `3` to the result.
3. Visit `1`, add `1` to the result.

### Final Result

The post-order traversal list is `[4, 5, 2, 3, 1]`.

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

Post-order traversal is an essential tree traversal method that visits nodes in a specific order. This documentation has provided you with a clear understanding of how to implement post-order traversal in both C++ and Java.
