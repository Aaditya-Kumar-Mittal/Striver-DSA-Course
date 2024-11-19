# Construct Binary Tree from Inorder and Postorder Traversal

## Table of Contents

- [Construct Binary Tree from Inorder and Postorder Traversal](#construct-binary-tree-from-inorder-and-postorder-traversal)
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

This problem involves constructing a binary tree using its **inorder** and **postorder** traversals:

- **Inorder Traversal:** Visits nodes in the order: left subtree, root, right subtree.
- **Postorder Traversal:** Visits nodes in the order: left subtree, right subtree, root.

## Problem Description

Given two arrays, `inorder` and `postorder`, representing the inorder and postorder traversals of a binary tree, return the binary tree constructed from these arrays.

### Examples

#### Example 1

**Input:**  
`inorder = [9, 3, 15, 20, 7]`  
`postorder = [9, 15, 7, 20, 3]`

**Output:**  
`[3, 9, 20, null, null, 15, 7]`

#### Example 2

**Input:**  
`inorder = [-1]`  
`postorder = [-1]`

**Output:**  
`[-1]`

### Constraints

- \(1 \leq \text{inorder.length} \leq 3000\)
- \(\text{postorder.length} == \text{inorder.length}\)
- \(-3000 \leq \text{inorder[i]}, \text{postorder[i]} \leq 3000\)
- `inorder` and `postorder` consist of **unique** values.
- Each value of `postorder` also appears in `inorder`.
- `inorder` is guaranteed to be the inorder traversal of the tree.
- `postorder` is guaranteed to be the postorder traversal of the tree.

## Approach

1. **Postorder Traversal Insight:** The last element in `postorder` is always the root of the current subtree.
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
    TreeNode* buildTree(vector<int>& postorder, int postStart, int postEnd,
                        vector<int>& inorder, int inStart, int inEnd,
                        unordered_map<int, int>& inorderMap) {
        if (postStart > postEnd || inStart > inEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                               inorder, inStart, inRoot - 1, inorderMap);

        root->right = buildTree(postorder, postStart + numsLeft, postEnd - 1,
                                inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (postorder.size() != inorder.size())
            return nullptr;

        unordered_map<int, int> inorderMap;
        for (int i = 0; i < inorder.size(); i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, inorderMap);
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
    private TreeNode buildTree(int[] postorder, int postStart, int postEnd,
                               int[] inorder, int inStart, int inEnd,
                               HashMap<Integer, Integer> inorderMap) {
        if (postStart > postEnd || inStart > inEnd)
            return null;

        TreeNode root = new TreeNode(postorder[postEnd]);
        int inRoot = inorderMap.get(root.val);
        int numsLeft = inRoot - inStart;

        root.left = buildTree(postorder, postStart, postStart + numsLeft - 1,
                              inorder, inStart, inRoot - 1, inorderMap);

        root.right = buildTree(postorder, postStart + numsLeft, postEnd - 1,
                               inorder, inRoot + 1, inEnd, inorderMap);

        return root;
    }

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        if (postorder.length != inorder.length)
            return null;

        HashMap<Integer, Integer> inorderMap = new HashMap<>();
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }

        return buildTree(postorder, 0, postorder.length - 1, inorder, 0, inorder.length - 1, inorderMap);
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of nodes. Building the `inorderMap` takes \(O(n)\), and each node is processed once.

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
