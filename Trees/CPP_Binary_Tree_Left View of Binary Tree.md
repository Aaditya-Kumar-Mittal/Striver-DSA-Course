# Left View of Binary Tree

## Table of Contents

- [Left View of Binary Tree](#left-view-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Detailed Explanation](#detailed-explanation)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The **Left View** of a Binary Tree refers to the collection of nodes that are visible when the tree is viewed from the left side. In other words, it is the set of nodes that appear at the topmost position from every level when looking at the tree from left to right.

## Problem Description

Given the root of a binary tree, return the nodes visible from the left side of the tree, ordered from top to bottom.

### Examples

1. **Input Tree**:

   ```plaintext
           1
         /   \
        2     3
       / \   / \
      4   5 6   7
   ```

   **Output**: `1 2 4`
   **Explanation**: From the left side view, the visible nodes are 1, 2, and 4.

2. **Input Tree**:

   ```plaintext
           10
          /  \
         20   30
        /  \    \
       40   50   60
   ```

   **Output**: `10 20 40`
   **Explanation**: The visible nodes from the left side are 10, 20, and 40.

### Constraints

- \(1 \leq \text{Number of nodes} \leq 10^5\)
- \(1 \leq \text{Node value} \leq 10^5\)

## Approach

We will use a **Depth-First Search (DFS)** approach to solve the problem. The key idea is to traverse the tree level by level, and at each level, capture the first node encountered. We can use a recursive approach to achieve this.

### Detailed Explanation

1. We start at the root node with level 0.
2. For each node, we check if it is the first node we encounter at the current level. If it is, we add it to the result list.
3. We first explore the left child and then the right child for each node, ensuring that the leftmost node is encountered first.
4. The process continues until all levels of the tree are covered.

### Algorithm

1. Traverse the tree using a DFS approach.
2. Use a helper function to keep track of the current level.
3. At each level, add the first encountered node to the result list.
4. Continue the traversal until the entire tree is processed.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct BinaryTreeNode {
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Helper function to perform DFS and track left view nodes.
void leftRecursion(BinaryTreeNode* root, int level, vector<int>& ans) {
    if (root == nullptr) return;

    // Add the node's value to the result list if it's the first node at this level.
    if (level == ans.size()) {
        ans.push_back(root->data);
    }

    // Recursively visit left child first, then right child.
    if (root->left) leftRecursion(root->left, level + 1, ans);
    if (root->right) leftRecursion(root->right, level + 1, ans);
}

// Main function to return the left view of the binary tree.
vector<int> printLeftView(BinaryTreeNode* root) {
    vector<int> ans;
    leftRecursion(root, 0, ans);
    return ans;
}

int main() {
    // Example tree creation
    BinaryTreeNode* root = new BinaryTreeNode(1);
    root->left = new BinaryTreeNode(2);
    root->right = new BinaryTreeNode(3);
    root->left->left = new BinaryTreeNode(4);
    root->left->right = new BinaryTreeNode(5);
    root->right->left = new BinaryTreeNode(6);

    vector<int> leftView = printLeftView(root);

    // Output the result
    for (int val : leftView) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
```

### Java Implementation

```java
import java.util.*;

// Definition for a binary tree node.
class BinaryTreeNode {
    int data;
    BinaryTreeNode left, right;

    BinaryTreeNode(int val) {
        data = val;
        left = right = null;
    }
}

public class Solution {
    // Helper function to perform DFS and track left view nodes.
    public void leftRecursion(BinaryTreeNode root, int level, List<Integer> ans) {
        if (root == null) return;

        // Add the node's value to the result list if it's the first node at this level.
        if (level == ans.size()) {
            ans.add(root.data);
        }

        // Recursively visit left child first, then right child.
        if (root.left != null) leftRecursion(root.left, level + 1, ans);
        if (root.right != null) leftRecursion(root.right, level + 1, ans);
    }

    // Main function to return the left view of the binary tree.
    public List<Integer> printLeftView(BinaryTreeNode root) {
        List<Integer> ans = new ArrayList<>();
        leftRecursion(root, 0, ans);
        return ans;
    }

    public static void main(String[] args) {
        // Example tree creation
        BinaryTreeNode root = new BinaryTreeNode(1);
        root.left = new BinaryTreeNode(2);
        root.right = new BinaryTreeNode(3);
        root.left.left = new BinaryTreeNode(4);
        root.left.right = new BinaryTreeNode(5);
        root.right.left = new BinaryTreeNode(6);

        Solution solution = new Solution();
        List<Integer> leftView = solution.printLeftView(root);

        // Output the result
        for (int val : leftView) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the binary tree. We visit each node exactly once.
- **Space Complexity**: \(O(H)\), where \(H\) is the height of the tree. This space is used by the recursion stack during the DFS traversal.

---

## How to Run the Code

### For C++

1. Copy the C++ code into a file named `LeftViewBinaryTree.cpp`.
2. Compile the code using a C++ compiler:

   ```bash
   g++ -o leftview LeftViewBinaryTree.cpp
   ```

3. Run the compiled program:

   ```bash
   ./leftview
   ```

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler:

   ```bash
   javac Solution.java
   ```

3. Run the compiled program:

   ```bash
   java Solution
   ```

This documentation provides a complete guide for implementing the **Left View of Binary Tree** problem in both C++ and Java. It includes the problem description, approach, code, complexity analysis, and instructions on how to run the code.
