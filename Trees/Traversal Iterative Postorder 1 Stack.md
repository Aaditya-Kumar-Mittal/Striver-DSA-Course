# Iterative Post-Order Traversal of a Binary Tree (Single Stack Approach)

## Table of Contents

- [Iterative Post-Order Traversal of a Binary Tree (Single Stack Approach)](#iterative-post-order-traversal-of-a-binary-tree-single-stack-approach)
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

Post-order traversal is a tree traversal method where the nodes are visited in the order of **left subtree, right subtree, root**. This documentation explains an iterative approach for post-order traversal using a single stack and provides implementations in both C++ and Java.

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

This solution uses a single stack for an iterative post-order traversal. The basic idea is to traverse to the leftmost node using the stack and keep track of the right child to manage visiting order.

### Algorithm

1. Initialize an empty stack and set `current` to the root node.
2. Traverse the tree:
   - Push nodes onto the stack and move to the left child until `current` is `null`.
   - If the current node's right child is `null` or has already been visited, visit the node, add its value to the result, and pop it from the stack.
   - Otherwise, set `current` to the right child.
3. Repeat until the stack is empty.
4. Return the post-order traversal result.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Definition for binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postOrder(Node* node) {
        vector<int> postorder;
        if (!node) return postorder;

        stack<Node*> st;
        Node* current = node;

        while (current != nullptr || !st.empty()) {
            while (current != nullptr) {
                st.push(current);
                current = current->left;
            }

            Node* temp = st.top()->right;
            if (temp == nullptr) {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);

                while (!st.empty() && temp == st.top()->right) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            } else {
                current = temp;
            }
        }

        return postorder;
    }
};

// Function to build tree and main driver code...
```

### Java Implementation

```java
import java.util.*;

// Definition for binary tree node
class TreeNode {
    int data;
    TreeNode left, right;
    TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Solution {
    public List<Integer> postOrder(TreeNode node) {
        List<Integer> postorder = new ArrayList<>();
        if (node == null) return postorder;

        Stack<TreeNode> stack = new Stack<>();
        TreeNode current = node;

        while (current != null || !stack.isEmpty()) {
            while (current != null) {
                stack.push(current);
                current = current.left;
            }

            TreeNode temp = stack.peek().right;
            if (temp == null) {
                temp = stack.pop();
                postorder.add(temp.data);

                while (!stack.isEmpty() && temp == stack.peek().right) {
                    temp = stack.pop();
                    postorder.add(temp.data);
                }
            } else {
                current = temp;
            }
        }

        return postorder;
    }

    public static void main(String[] args) {
        // Sample test code for creating and testing the tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        Solution sol = new Solution();
        List<Integer> result = sol.postOrder(root);
        System.out.println("Post-order Traversal: " + result);
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \), where \( n \) is the number of nodes in the tree. Each node is visited once.
- **Space Complexity**: \( O(n) \), in the worst case (e.g., a completely unbalanced tree), for the stack.

## How to Run the Code

### Running the C++ Code

1. Copy the C++ code into your preferred C++ IDE or editor.
2. Compile using `g++ -o solution solution.cpp`.
3. Run the executable with `./solution`.

### Running the Java Code

1. Copy the Java code into a file named `Solution.java`.
2. Compile using `javac Solution.java`.
3. Run using `java Solution`.

This completes the explanation and implementation of the iterative post-order traversal using a single stack in C++ and Java.
