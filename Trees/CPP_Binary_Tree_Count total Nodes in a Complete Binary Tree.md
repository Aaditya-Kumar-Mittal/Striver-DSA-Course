# Count Complete Tree Nodes

## Table of Contents

- [Count Complete Tree Nodes](#count-complete-tree-nodes)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
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

In this problem, given the root of a **complete binary tree**, we aim to count the total number of nodes efficiently. A complete binary tree is defined as a binary tree in which all levels are fully filled except possibly the last level, where all nodes are as far left as possible.

## Problem Description

Given the `root` of a complete binary tree, return the number of nodes in the tree. Design an algorithm that runs in less than **O(n)** time complexity.

### Examples

#### Example 1

**Input:**  
`root = [1, 2, 3, 4, 5, 6]`  
**Output:**  
`6`

#### Example 2

**Input:**  
`root = []`  
**Output:**  
`0`

#### Example 3

**Input:**  
`root = [1]`  
**Output:**  
`1`

### Constraints

- The number of nodes in the tree is in the range `[0, 5 * 10^4]`.
- `0 <= Node.val <= 5 * 10^4`.
- The tree is guaranteed to be **complete**.

## Approach

The problem can be solved efficiently by leveraging the properties of a complete binary tree.

- **Height Calculation:** Use the height of the leftmost and rightmost paths of the tree to determine if the tree is a perfect binary tree.
- **Divide and Conquer:** If the left and right heights are equal, the tree is a perfect binary tree, and the total nodes can be calculated directly using the formula \(2^{\text{height}} - 1\). Otherwise, recursively calculate the nodes in the left and right subtrees.

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
    int findHeightLeft(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->left;
        }
        return height;
    }

    int findHeightRight(TreeNode* root) {
        int height = 0;
        while (root) {
            height++;
            root = root->right;
        }
        return height;
    }

public:
    int countNodes(TreeNode* root) {
        if (!root)
            return 0;
        int leftHeight = findHeightLeft(root);
        int rightHeight = findHeightRight(root);
        if (rightHeight == leftHeight)
            return (1 << leftHeight) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
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
    private int findHeightLeft(TreeNode root) {
        int height = 0;
        while (root != null) {
            height++;
            root = root.left;
        }
        return height;
    }

    private int findHeightRight(TreeNode root) {
        int height = 0;
        while (root != null) {
            height++;
            root = root.right;
        }
        return height;
    }

    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        int leftHeight = findHeightLeft(root);
        int rightHeight = findHeightRight(root);
        if (leftHeight == rightHeight)
            return (1 << leftHeight) - 1;
        return 1 + countNodes(root.left) + countNodes(root.right);
    }
}
```

## Complexity Analysis

- **Time Complexity:**

  - In the worst case, the algorithm runs in \(O(\log^2 n)\), where \(n\) is the number of nodes. This is because computing the height of the tree takes \(O(\log n)\) and this is done recursively for each subtree.
  - Let n be the total number of the tree. It is likely that you will get a child tree as a perfect binary tree and a non-perfect binary tree (T(n/2)) at each level.
  
    ```bash
      T(n) = T(n/2) + c1 lgn
      = T(n/4) + c1 lgn + c2 (lgn - 1)
      = ...
      = T(1) + c [lgn + (lgn-1) + (lgn-2) + ... + 1]
      = O(lgn\*lgn)
    ```

- **Space Complexity:**
  - \(O(\log n)\) due to the recursive stack used in the function calls.

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
