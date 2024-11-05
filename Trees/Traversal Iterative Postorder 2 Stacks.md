# Post-order Traversal of Binary Trees Using 2 Stacks(Iterative Approach)

## Table of Contents

- [Post-order Traversal of Binary Trees Using 2 Stacks(Iterative Approach)](#post-order-traversal-of-binary-trees-using-2-stacksiterative-approach)
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

Post-order traversal is a tree traversal method where the nodes are visited in the order of **left subtree, right subtree, root**. This documentation explains an iterative approach for post-order traversal using two stacks and provides implementations in both C++ and Java.

## Problem Description

Given a binary tree, traverse it using the post-order traversal method iteratively and return a list of the node values in the order they were visited.

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

The iterative approach for post-order traversal uses two stacks:

1. **Stack 1** is used for processing nodes.
2. **Stack 2** is used for collecting nodes in the reverse post-order sequence.

### Algorithm

1. Push the root node onto **stack 1**.
2. While **stack 1** is not empty:
   - Pop the top node from **stack 1** and push it onto **stack 2**.
   - Push the left child (if present) of the popped node onto **stack 1**.
   - Push the right child (if present) of the popped node onto **stack 1**.
3. After the loop, **stack 2** will contain nodes in the reversed post-order.
4. Pop all nodes from **stack 2** and append their values to the result list.

## Detailed Explanation of Code

### C++ Implementation

```cpp
/* Following is Binary Tree Node structure:
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
}; */

#include <bits/stdc++.h>
using namespace std;

vector<int> postorderTraversal(TreeNode *root) {
    vector<int> postorder;
    if (!root)
        return postorder;

    stack<TreeNode *> stk1, stk2;
    stk1.push(root);

    while (!stk1.empty()) {
        root = stk1.top();
        stk1.pop();
        stk2.push(root);

        if (root->left)
            stk1.push(root->left);
        if (root->right)
            stk1.push(root->right);
    }

    while (!stk2.empty()) {
        postorder.push_back(stk2.top()->data);
        stk2.pop();
    }

    return postorder;
}
```

### Java Implementation

```java
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

// Definition for a binary tree node
class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTreeTraversal {
    public static List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> postorder = new ArrayList<>();
        if (root == null) {
            return postorder;
        }

        Stack<TreeNode> stk1 = new Stack<>();
        Stack<TreeNode> stk2 = new Stack<>();
        stk1.push(root);

        while (!stk1.isEmpty()) {
            TreeNode node = stk1.pop();
            stk2.push(node);

            if (node.left != null) {
                stk1.push(node.left);
            }
            if (node.right != null) {
                stk1.push(node.right);
            }
        }

        while (!stk2.isEmpty()) {
            postorder.add(stk2.pop().data);
        }

        return postorder;
    }

    public static void main(String[] args) {
        // Creating a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // Getting post-order traversal
        List<Integer> result = postorderTraversal(root);

        // Displaying the post-order traversal result
        System.out.print("Post-order Traversal: ");
        for (int val : result) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \), where \( n \) is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**: \( O(n) \) for the two stacks used in the worst case (e.g., a completely unbalanced tree).

## How to Run the Code

### Running the C++ Code

1. Copy the C++ code into your preferred C++ IDE or editor.
2. Compile using `g++ -o solution solution.cpp`.
3. Run the executable with `./solution`.

### Running the Java Code

1. Copy the Java code into a file named `BinaryTreeTraversal.java`.
2. Compile using `javac BinaryTreeTraversal.java`.
3. Run using `java BinaryTreeTraversal`.

This completes the explanation and implementation of the iterative post-order traversal in C++ and Java.
