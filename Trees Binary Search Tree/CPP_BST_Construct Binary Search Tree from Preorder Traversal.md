# Construct Binary Search Tree from Preorder Traversal

## Table of Contents

- [Construct Binary Search Tree from Preorder Traversal](#construct-binary-search-tree-from-preorder-traversal)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The task is to construct a **Binary Search Tree (BST)** from the preorder traversal array and return its root. Preorder traversal visits a node first, then recursively visits its left subtree, followed by its right subtree. The BST follows the property where all left descendants are smaller, and all right descendants are larger than the root.

---

## Problem Description

You are given an array of integers `preorder` which represents the preorder traversal of a BST. Construct the BST and return its root.

---

### Examples

#### Example 1

**Input:**  
`preorder = [8,5,1,7,10,12]`

**Tree Representation:**

```bash
       8
      / \
     5   10
    / \     \
   1   7     12
```

**Output:** `[8,5,10,1,7,null,12]`

---

#### Example 2

**Input:**  
`preorder = [1,3]`

**Tree Representation:**

```bash
   1
    \
     3
```

**Output:** `[1,null,3]`

---

### Constraints

1. `1 <= preorder.length <= 100`
2. `1 <= preorder[i] <= 1000`
3. All values in `preorder` are unique.

---

## Approach

### Algorithm

1. **Recursive Construction:**

   - Use the preorder traversal to construct the tree.
   - Use an index `i` to iterate through the array.
   - Maintain a `bound` to restrict the values for the current subtree:
     - Values smaller than `bound` go to the left subtree.
     - Values larger than `bound` go to the right subtree.
   - Construct the left subtree first, then the right subtree recursively.

2. **Base Case:**
   - If the index exceeds the array size or the current value is greater than the bound, return `null`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    TreeNode* build(vector<int>& preorder, int& i, int bound) {
        if (i == preorder.size() || preorder[i] > bound)
            return nullptr;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = build(preorder, i, root->val);
        root->right = build(preorder, i, bound);

        return root;
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return build(preorder, i, INT_MAX);
    }
};
```

---

### Java Implementation

```java
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int val) {
        this.val = val;
        this.left = null;
        this.right = null;
    }
}

class Solution {
    private TreeNode build(int[] preorder, int[] index, int bound) {
        // Base case: if index exceeds the array size or value exceeds bound
        if (index[0] == preorder.length || preorder[index[0]] > bound) {
            return null;
        }

        // Construct the current node
        TreeNode root = new TreeNode(preorder[index[0]++]);

        // Construct left and right subtrees
        root.left = build(preorder, index, root.val);
        root.right = build(preorder, index, bound);

        return root;
    }

    public TreeNode bstFromPreorder(int[] preorder) {
        int[] index = {0}; // Mutable index to track current position
        return build(preorder, index, Integer.MAX_VALUE);
    }
}
```

---

## Complexity Analysis

### Time Complexity

- Each node is visited exactly once during the recursion.  
  **Time Complexity:** **O(n)**, where `n` is the number of nodes in the tree.

### Space Complexity

- Space required for the recursion stack depends on the height of the tree:
  - **Best case (balanced tree):** **O(log n)**.
  - **Worst case (skewed tree):** **O(n)**.

---

## How to Run the Code

### For C++

1. Create a `vector<int>` to hold the preorder traversal.
2. Instantiate the `Solution` class.
3. Call the `bstFromPreorder` function with the preorder array.

### For Java

1. Prepare an integer array for the preorder traversal.
2. Instantiate the `Solution` class.
3. Call the `bstFromPreorder` method with the array to get the root of the constructed tree.

---

This implementation ensures efficient construction of the BST while adhering to the constraints and properties of preorder traversal.
