# Morris Post-Order Traversal of a Binary Tree (No Stack or Recursion)

## Table of Contents

- [Morris Post-Order Traversal of a Binary Tree (No Stack or Recursion)](#morris-post-order-traversal-of-a-binary-tree-no-stack-or-recursion)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example](#example)
  - [Approach](#approach)
    - [Intuition](#intuition)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Running the C++ Code](#running-the-c-code)
    - [Running the Java Code](#running-the-java-code)

## Introduction

Morris traversal is an algorithm that performs tree traversal without using additional stack space or recursion. This approach involves temporarily modifying the tree's structure to simulate the behavior of a stack.

## Problem Description

Given a binary tree, traverse it using post-order traversal iteratively without using any extra space for stacks or recursion, and return a list of the node values in post-order sequence.

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

### Intuition

In Morris traversal, we:

- Introduce a `dummyNode` to simplify handling edge cases.
- Traverse the tree while creating and reversing temporary links from the in-order predecessor back to the current node.
- Perform a reverse traversal of the subtree when returning to the current node after processing its left subtree.

### Algorithm

1. Initialize an empty `result` list and create a `dummyNode` linked to `root`.
2. Traverse the tree starting from `dummyNode`:
   - If `root` has a left child, find the rightmost node in the left subtree.
   - Create a temporary link (thread) if it doesn’t exist and move `root` to the left child.
   - If a thread exists, process the subtree in reverse and collect node values in `result`.
   - Restore the original tree structure by reversing the thread back.
3. If `root` has no left child, move `root` to the right child.
4. Return the `result` list.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <iostream>

// Definition for binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        std::vector<int> result;
        if (!root) return result;

        TreeNode dummy(-1);
        dummy.left = root;
        TreeNode* current = &dummy;

        while (current != nullptr) {
            if (current->left != nullptr) {
                TreeNode* predecessor = current->left;
                while (predecessor->right != nullptr && predecessor->right != current) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right == nullptr) {
                    predecessor->right = current;
                    current = current->left;
                } else {
                    reverseAddNodes(current->left, predecessor, result);
                    predecessor->right = nullptr;
                    current = current->right;
                }
            } else {
                current = current->right;
            }
        }

        return result;
    }

private:
    void reverseAddNodes(TreeNode* from, TreeNode* to, std::vector<int>& result) {
        reverseNodes(from, to);
        TreeNode* node = to;
        while (node != from) {
            result.push_back(node->val);
            node = node->right;
        }
        result.push_back(from->val);
        reverseNodes(to, from);
    }

    void reverseNodes(TreeNode* start, TreeNode* end) {
        if (start == end) return;
        TreeNode *prev = nullptr, *current = start, *next = nullptr;
        while (current != end) {
            next = current->right;
            current->right = prev;
            prev = current;
            current = next;
        }
        end->right = prev;
    }
};
```

### Java Implementation

```java
import java.util.*;

// Definition for a binary tree node
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
    public List<Integer> postorderTraversal(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        TreeNode dummyNode = new TreeNode(-1);
        dummyNode.left = root;
        TreeNode current = dummyNode;

        while (current != null) {
            if (current.left != null) {
                TreeNode predecessor = current.left;
                while (predecessor.right != null && predecessor.right != current) {
                    predecessor = predecessor.right;
                }

                if (predecessor.right == null) {
                    predecessor.right = current;
                    current = current.left;
                } else {
                    reverseAddNodes(current.left, predecessor, result);
                    predecessor.right = null;
                    current = current.right;
                }
            } else {
                current = current.right;
            }
        }

        return result;
    }

    private void reverseAddNodes(TreeNode from, TreeNode to, List<Integer> result) {
        reverseNodes(from, to);
        TreeNode node = to;
        while (node != from) {
            result.add(node.val);
            node = node.right;
        }
        result.add(from.val);
        reverseNodes(to, from);
    }

    private void reverseNodes(TreeNode start, TreeNode end) {
        if (start == end) return;
        TreeNode prev = null;
        TreeNode current = start;
        TreeNode next = null;

        while (current != end) {
            next = current.right;
            current.right = prev;
            prev = current;
            current = next;
        }
        end.right = prev;
    }

    public static void main(String[] args) {
        // Sample test case to run and verify
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        Solution solution = new Solution();
        List<Integer> result = solution.postorderTraversal(root);
        System.out.println("Post-order Traversal: " + result);
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \)
  - Each node is visited a constant number of times, leading to linear traversal in terms of \( n \), where \( n \) is the number of nodes.
- **Space Complexity**: \( O(1) \)
  - The Morris Traversal modifies the tree temporarily without using extra space for a stack or recursion, making the space usage constant.

## How to Run the Code

### Running the C++ Code

1. Copy the C++ code into your preferred C++ IDE or editor.
2. Compile using `g++ -o solution solution.cpp`.
3. Run the executable with `./solution`.

### Running the Java Code

1. Copy the Java code into a file named `Solution.java`.
2. Compile using `javac Solution.java`.
3. Run using `java Solution`.

This concludes the explanation and implementation of the **Morris traversal** for post-order traversal using C++ and Java.
