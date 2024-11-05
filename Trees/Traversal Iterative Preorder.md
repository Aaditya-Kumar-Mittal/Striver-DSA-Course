# Pre-order Traversal of Binary Trees (Iterative Approach)

## Table of Contents

- [Pre-order Traversal of Binary Trees (Iterative Approach)](#pre-order-traversal-of-binary-trees-iterative-approach)
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

This README provides a comprehensive overview of pre-order traversal using an iterative approach and the corresponding implementations in C++ and Java.

## Problem Description

Given a binary tree, traverse it using the pre-order traversal method iteratively and return the list of node values in the order they were visited.

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

The iterative pre-order traversal can be implemented using a stack to simulate the recursive call stack. The steps are as follows:

1. Start at the root node and push it onto the stack.
2. While the stack is not empty, do the following:
   - Pop the top node from the stack.
   - Visit and record its value.
   - Push the right child onto the stack (if it exists).
   - Push the left child onto the stack (if it exists).
3. Repeat until the stack is empty.

### Algorithm

1. Initialize an empty vector (or list) to store the pre-order traversal.
2. If the root is `nullptr` (or `null`), return the empty vector (or list).
3. Push the root onto the stack.
4. While the stack is not empty:
   - Pop the top node.
   - Add its value to the traversal list.
   - Push its right child (if exists) and then its left child (if exists) onto the stack.
5. Return the traversal list.

## Detailed Explanation of Code

### C++ Implementation

```cpp
/************************************************************
      Following is the TreeNode class structure
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
    // Write your code here.
    vector<int> preorder;
    if (root == nullptr)
        return preorder;

    stack<TreeNode<int> *> st;
    st.push(root);

    while (!st.empty()) {
        TreeNode<int> *node = st.top();
        st.pop();
        preorder.push_back(node->data);

        // Push right child first so that left child is processed first.
        if (node->right)
            st.push(node->right);
        if (node->left)
            st.push(node->left);
    }

    return preorder;
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
    TreeNode left;
    TreeNode right;

    TreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class BinaryTreeTraversal {
    // Function to perform iterative pre-order traversal
    public static List<Integer> preOrder(TreeNode root) {
        List<Integer> preorder = new ArrayList<>();
        if (root == null) {
            return preorder;
        }

        Stack<TreeNode> stack = new Stack<>();
        stack.push(root);

        while (!stack.isEmpty()) {
            TreeNode node = stack.pop();
            preorder.add(node.data);

            // Push right child first so that left child is processed first.
            if (node.right != null) {
                stack.push(node.right);
            }
            if (node.left != null) {
                stack.push(node.left);
            }
        }

        return preorder;
    }

    public static void main(String[] args) {
        // Creating a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

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

1. Initialize stack and push `1`.
2. Pop `1`, add `1` to the result.
3. Push `3` (right child of `1`) and `2` (left child of `1`) onto the stack.
4. Pop `2`, add `2` to the result.
5. Push `5` (right child of `2`) and `4` (left child of `2`) onto the stack.
6. Pop `4`, add `4` to the result.
7. Pop `5`, add `5` to the result.
8. Pop `3`, add `3` to the result.

### Final Result

The pre-order traversal list is `[1, 2, 4, 5, 3]`.

## Complexity Analysis

- **Time Complexity**: \( O(n) \), where \( n \) is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**:
  - \( O(h) \) for the stack space, where \( h \) is the height of the tree. In the worst case (for a skewed tree), the height can be equal to \( n \).

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

Pre-order traversal using an iterative approach is an effective way to visit all nodes in a binary tree without recursion. This documentation has provided you with a clear understanding of how to implement this traversal in both C++ and Java.
