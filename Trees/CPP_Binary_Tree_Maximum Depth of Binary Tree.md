# Maximum Depth of Binary Tree

## Table of Contents

- [Maximum Depth of Binary Tree](#maximum-depth-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Approach 1: Recursive Depth-First Search](#approach-1-recursive-depth-first-search)
    - [Approach 2: Iterative Breadth-First Search](#approach-2-iterative-breadth-first-search)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The goal of this problem is to find the maximum depth of a binary tree. The maximum depth is defined as the number of nodes along the longest path from the root node down to the farthest leaf node.

## Problem Description

Given the root of a binary tree, return its maximum depth.

### Examples

1. **Input:** `root = [3,9,20,null,null,15,7]`  
   **Output:** `3`
2. **Input:** `root = [1,null,2]`  
   **Output:** `2`

### Constraints

- The number of nodes in the tree is in the range \([0, 10^4]\).
- \(-100 \leq \text{Node.val} \leq 100\)

## Approach

### Approach 1: Recursive Depth-First Search

In this approach, we use recursion to explore the binary tree. The maximum depth is determined by recursively visiting each node's left and right children and calculating the maximum depth from both subtrees. The base case for the recursion is when the node is null, in which case the depth is zero.

### Approach 2: Iterative Breadth-First Search

In this approach, we use a queue to perform a level-order traversal of the tree. We count the number of levels traversed to determine the maximum depth. Each time we process a level, we increase the depth count.

## Detailed Explanation of Code

### C++ Implementation

```cpp
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Approach 1: Recursive Depth-First Search
    int maxDepth(TreeNode* root) {
        if (!root)
            return 0;
        int lh = maxDepth(root->left);  // Depth of left subtree
        int rh = maxDepth(root->right); // Depth of right subtree
        return 1 + max(lh, rh);         // Return max depth
    }
};

// Approach 2: Iterative Breadth-First Search
int maxDepth(TreeNode *root) {
    if (root == NULL)
        return 0;

    int res = 0;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
        ++res; // Increment depth for each level
        for (int i = 0, n = q.size(); i < n; ++i) {
            TreeNode *p = q.front();
            q.pop();

            if (p->left != NULL)
                q.push(p->left);   // Push left child
            if (p->right != NULL)
                q.push(p->right);  // Push right child
        }
    }

    return res; // Return the max depth
}
```

### Java Implementation

```java
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode() {
        val = 0;
        left = null;
        right = null;
    }

    TreeNode(int x) {
        val = x;
        left = null;
        right = null;
    }

    TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    // Approach 1: Recursive Depth-First Search
    public int maxDepth(TreeNode root) {
        if (root == null)
            return 0;
        int lh = maxDepth(root.left);  // Depth of left subtree
        int rh = maxDepth(root.right); // Depth of right subtree
        return 1 + Math.max(lh, rh);  // Return max depth
    }

    // Approach 2: Iterative Breadth-First Search
    public int maxDepthIterative(TreeNode root) {
        if (root == null)
            return 0;

        int res = 0;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        while (!q.isEmpty()) {
            res++; // Increment depth for each level
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode p = q.poll();

                if (p.left != null)
                    q.offer(p.left);   // Push left child
                if (p.right != null)
                    q.offer(p.right);  // Push right child
            }
        }

        return res; // Return the max depth
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \) where \( n \) is the number of nodes in the tree. Each node is visited once in both approaches.
- **Space Complexity**:
  - For the recursive approach, the space complexity is \( O(h) \) where \( h \) is the height of the tree due to the call stack.
  - For the iterative approach, the space complexity is \( O(w) \) where \( w \) is the maximum width of the tree (number of nodes at the last level).

## How to Run the Code

### For C++

1. Copy the C++ code into your preferred C++ IDE or text editor.
2. Compile the code using a C++ compiler, e.g., `g++ -o solution solution.cpp`.
3. Run the compiled program with `./solution`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This README provides a comprehensive guide to solving the maximum depth of a binary tree problem using both recursive and iterative methods in C++ and Java. You can use this for educational purposes or implement it in your projects.
