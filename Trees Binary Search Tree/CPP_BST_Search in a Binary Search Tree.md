# Search in a Binary Search Tree

## Table of Contents

- [Search in a Binary Search Tree](#search-in-a-binary-search-tree)
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

The problem involves searching for a node in a Binary Search Tree (BST) with a given value and returning the subtree rooted at that node. If the value does not exist in the BST, return `null`.

## Problem Description

### Examples

**Example 1:**  
**Input:**  
`root = [4,2,7,1,3], val = 2`  
**Output:**  
`[2,1,3]`

**Example 2:**  
**Input:**  
`root = [4,2,7,1,3], val = 5`  
**Output:**  
`[]`

### Constraints

- The number of nodes in the tree is in the range `[1, 5000]`.
- \(1 \leq \text{Node.val} \leq 10^7\).
- The `root` is a valid Binary Search Tree.
- \(1 \leq \text{val} \leq 10^7\).

## Approach

- Start at the root node.
- Use the BST property:
  - If the value matches the node, return the node.
  - If the value is smaller, search in the left subtree.
  - If the value is larger, search in the right subtree.
- Return `null` if the value is not found.

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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        // Traverse the tree until the value is found or root is null
        while (root != nullptr && root->val != val) {
            root = val < root->val ? root->left : root->right;
        }
        return root;  // Return the node or null if not found
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

class Solution {
    public TreeNode searchBST(TreeNode root, int val) {
        // Traverse the tree until the value is found or root is null
        while (root != null && root.val != val) {
            root = val < root.val ? root.left : root.right;
        }
        return root;  // Return the node or null if not found
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(h)\), where \(h\) is the height of the tree. In the worst case, \(h = O(n)\) for a skewed tree, and in the best case, \(h = O(\log n)\) for a balanced tree.

- **Space Complexity:**  
  \(O(1)\), as the solution uses constant space (no recursion or auxiliary data structures).

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `SearchBST.cpp`.
2. Compile the file:

   ```bash
   g++ -o SearchBST SearchBST.cpp
   ```

3. Run the executable:

   ```bash
   ./SearchBST
   ```

### For Java

1. Save the code in a file, e.g., `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
