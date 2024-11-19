# Construct Binary Tree from Preorder and Inorder Traversal

## Table of Contents

- [Construct Binary Tree from Preorder and Inorder Traversal](#construct-binary-tree-from-preorder-and-inorder-traversal)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
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

The problem is to construct a binary tree given its **preorder** and **inorder** traversals. Preorder traversal provides information about the root node and its left and right subtrees, while inorder traversal gives details about the left subtree, root, and right subtree.

## Problem Description

Given two integer arrays, `preorder` and `inorder`:

- `preorder` represents the preorder traversal of a binary tree.
- `inorder` represents the inorder traversal of the same tree.

Return the binary tree constructed from these arrays.

### Examples

#### Example 1

**Input:**  
`preorder = [3, 9, 20, 15, 7]`  
`inorder = [9, 3, 15, 20, 7]`

**Output:**  
`[3, 9, 20, null, null, 15, 7]`

#### Example 2

**Input:**  
`preorder = [-1]`  
`inorder = [-1]`

**Output:**  
`[-1]`

### Constraints

- \(1 \leq \text{preorder.length} \leq 3000\)
- \(\text{inorder.length} == \text{preorder.length}\)
- \(-3000 \leq \text{preorder[i]}, \text{inorder[i]} \leq 3000\)
- `preorder` and `inorder` consist of **unique** values.
- Each value of `inorder` also appears in `preorder`.
- `preorder` is guaranteed to be the preorder traversal of the tree.
- `inorder` is guaranteed to be the inorder traversal of the tree.

## Approach

1. **Preorder Traversal Insight:** The first element in `preorder` is always the root of the current subtree.
2. **Inorder Traversal Insight:** The position of the root in `inorder` splits the array into left and right subtrees.
3. **Recursive Construction:** Use a helper function to recursively build the left and right subtrees by determining their boundaries in both arrays.

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
private:
    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inorderMap) {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                               inorder, inStart, inRoot - 1, inorderMap);

        root->right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                                inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
    }
};
```

### Java Implementation

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

import java.util.HashMap;

class Solution {
    private TreeNode buildTree(int[] preorder, int preStart, int preEnd,
                               int[] inorder, int inStart, int inEnd,
                               HashMap<Integer, Integer> inorderMap) {
        if (preStart > preEnd || inStart > inEnd)
            return null;

        TreeNode root = new TreeNode(preorder[preStart]);
        int inRoot = inorderMap.get(root.val);
        int numsLeft = inRoot - inStart;

        root.left = buildTree(preorder, preStart + 1, preStart + numsLeft,
                              inorder, inStart, inRoot - 1, inorderMap);

        root.right = buildTree(preorder, preStart + numsLeft + 1, preEnd,
                               inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        HashMap<Integer, Integer> inorderMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }

        return buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, inorderMap);
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of nodes. Constructing the `inorderMap` takes \(O(n)\), and each node is processed once.

- **Space Complexity:**  
  \(O(n)\), due to the recursive stack and the `inorderMap`.

## How to Run the Code

### For C++

1. Save the implementation in a file, e.g., `Solution.cpp`.
2. Use a C++ compiler like `g++` to compile the code:

   ```bash
   g++ -o Solution Solution.cpp
   ```

3. Run the compiled code:

   ```bash
   ./Solution
   ```

### For Java

1. Save the implementation in a file, e.g., `Solution.java`.
2. Compile the file using:

   ```bash
   javac Solution.java
   ```

3. Run the code using:

   ```bash
   java Solution
   ```
