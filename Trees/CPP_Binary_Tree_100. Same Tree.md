# Same Tree in Binary Trees

## Table of Contents

- [Same Tree in Binary Trees](#same-tree-in-binary-trees)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The **same tree** problem is a classic binary tree problem. Two binary trees are considered the same if they have identical structures, and each corresponding node has the same value. We need to determine whether two given binary trees meet these conditions.

## Problem Description

Given the roots of two binary trees `p` and `q`, write a function to check if they are the same.

### Examples

1. **Input:** `p = [1,2,3]`, `q = [1,2,3]`  
   **Output:** `true`  
   **Explanation:** The two trees are identical in structure and node values.

2. **Input:** `p = [1,2]`, `q = [1,null,2]`  
   **Output:** `false`  
   **Explanation:** The two trees have different structures.

3. **Input:** `p = [1,2,1]`, `q = [1,1,2]`  
   **Output:** `false`  
   **Explanation:** The node values differ.

### Constraints

- The number of nodes in both trees is in the range \([0, 100]\).
- \(-10^4 \leq \text{Node.val} \leq 10^4\).

## Approach

1. **Base Cases**:

   - If both nodes are `null`, the trees are the same up to this point.
   - If one of the nodes is `null` and the other is not, the trees are different.

2. **Recursive Comparison**:
   - For each pair of nodes from `p` and `q`, check if their values are the same.
   - Recursively compare their left and right children.

If both the left and right subtrees of every node match, then the two trees are identical.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // If both nodes are null, they are the same at this level
        if (!p && !q) return true;
        // If one is null and the other is not, trees differ
        if (!p || !q) return false;
        // Check if values are the same and recursively compare children
        return (p->val == q->val) &&
               isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
```

### Java Implementation

```java
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode() { this.val = 0; this.left = this.right = null; }
    TreeNode(int val) { this.val = val; this.left = this.right = null; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        // If both nodes are null, they are the same at this level
        if (p == null && q == null) return true;
        // If one is null and the other is not, trees differ
        if (p == null || q == null) return false;
        // Check if values are the same and recursively compare children
        return (p.val == q.val) &&
               isSameTree(p.left, q.left) &&
               isSameTree(p.right, q.right);
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the minimum number of nodes in the two trees, as each node is visited once.
- **Space Complexity**: \(O(h)\), where \(h\) is the height of the tree, due to the recursion stack.

## How to Run the Code

### For C++

1. Copy the C++ code into your preferred C++ IDE or text editor.
2. Compile the code using a C++ compiler, e.g., `g++ -o solution solution.cpp`.
3. Run the compiled program with `./solution`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This documentation provides a step-by-step guide to checking if two binary trees are the same, with implementations in both C++ and Java.
