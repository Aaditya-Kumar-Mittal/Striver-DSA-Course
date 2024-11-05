# In-order Traversal of Binary Trees (Iterative Approach)

## Table of Contents

- [In-order Traversal of Binary Trees (Iterative Approach)](#in-order-traversal-of-binary-trees-iterative-approach)
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
  - [Conclusion](#conclusion)

## Introduction

In-order traversal is a method of visiting all the nodes in a binary tree in a left-root-right sequence. This README provides a comprehensive overview of in-order traversal using an iterative approach, including implementations in both C++ and Java.

## Problem Description

Given a binary tree, traverse it using the in-order traversal method iteratively and return the list of node values in the order they were visited.

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

The iterative in-order traversal can be implemented using a stack to simulate the recursive call stack. The steps are as follows:

1. Start at the root node.
2. Push all left children of the current node onto the stack until the current node becomes `nullptr` (or `null`).
3. If the stack is not empty, pop the top node, visit it, and then set the current node to its right child.
4. Repeat the above two steps until both the stack is empty and the current node is `nullptr`.

### Algorithm

1. Initialize an empty vector (or list) to store the in-order traversal.
2. If the root is `nullptr`, return the empty vector.
3. Use a stack to keep track of nodes.
4. While the current node is not `nullptr` or the stack is not empty:
   - Push the current node onto the stack and move to its left child.
   - If the current node is `nullptr` and the stack is not empty, pop the top node, add its value to the traversal list, and set the current node to its right child.
5. Return the traversal list.

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
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left),
    right(right) {}
}; */

#include <bits/stdc++.h>
using namespace std;

vector<int> getInOrderTraversal(TreeNode *root) {
    vector<int> inorder;
    if (!root)
        return inorder;

    stack<TreeNode *> st;
    TreeNode *node = root;

    while (true) {
        // Reach the leftmost node
        if (node) {
            st.push(node);
            node = node->left;
        } else {
            // Backtrack
            if (st.empty())
                break;
            node = st.top();
            st.pop();
            inorder.push_back(node->data);
            node = node->right;  // Visit the right subtree
        }
    }
    return inorder;
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
    // Function to perform iterative in-order traversal
    public static List<Integer> getInOrderTraversal(TreeNode root) {
        List<Integer> inorder = new ArrayList<>();
        if (root == null) {
            return inorder;
        }

        Stack<TreeNode> stack = new Stack<>();
        TreeNode node = root;

        while (true) {
            // Reach the leftmost node
            if (node != null) {
                stack.push(node);
                node = node.left;
            } else {
                // Backtrack
                if (stack.isEmpty()) {
                    break;
                }
                node = stack.pop();
                inorder.add(node.data);
                node = node.right;  // Visit the right subtree
            }
        }

        return inorder;
    }

    public static void main(String[] args) {
        // Creating a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        // Getting in-order traversal
        List<Integer> result = getInOrderTraversal(root);

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

1. Initialize the stack and push `1`.
2. Move to the left child and push `2`.
3. Move to the left child and push `4`.
4. Since `4` has no left child, pop `4` and add `4` to the result.
5. Move to the right child of `4` (which is `nullptr`), backtrack and pop `2`, add `2` to the result.
6. Move to the right child of `2` and push `5`.
7. Since `5` has no left child, pop `5` and add `5` to the result.
8. Backtrack to `1`, pop `1`, and add `1` to the result.
9. Move to the right child of `1`, which is `3`, pop `3`, and add `3` to the result.

### Final Result

The in-order traversal list is `[4, 2, 5, 1, 3]`.

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

In-order traversal using an iterative approach is a powerful way to visit all nodes in a binary tree in sorted order without recursion. This documentation has provided you with a clear understanding of how to implement this traversal in both C++ and Java.
