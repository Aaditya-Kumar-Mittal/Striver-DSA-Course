# Maximum Path Sum in a Binary Tree

## Table of Contents

- [Maximum Path Sum in a Binary Tree](#maximum-path-sum-in-a-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Optimized Approach](#optimized-approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The **maximum path sum** in a binary tree is the largest sum of values along any path in the tree. A path can start and end at any node, and each node can appear at most once in the path. The path does not need to pass through the root.

## Problem Description

Given the root of a binary tree, return the maximum path sum of any **non-empty** path.

### Examples

1. **Input:** `root = [1,2,3]`  
   **Output:** `6`  
   **Explanation:** The optimal path is `2 -> 1 -> 3` with a path sum of `2 + 1 + 3 = 6`.

2. **Input:** `root = [-10,9,20,null,null,15,7]`  
   **Output:** `42`  
   **Explanation:** The optimal path is `15 -> 20 -> 7` with a path sum of `15 + 20 + 7 = 42`.

### Constraints

- The number of nodes in the tree is in the range \([1, 3 \times 10^4]\).
- \(-1000 \leq \text{Node.val} \leq 1000\).

## Approach

To solve this problem, we need to calculate the maximum path sum, considering any possible path between nodes. This involves exploring each node’s left and right subtrees and updating the maximum sum dynamically based on the calculated values.

### Optimized Approach

1. **Recursive Traversal**:

   - Use a helper function `maxSumPath` that recursively calculates the maximum path sum that can be extended upwards from each node.

2. **Dynamic Update of Max Sum**:

   - At each node, calculate the maximum path sum from the node to any of its children.
   - Use the left and right subtree sums, and ignore negative sums (which would reduce the overall path sum).

3. **Return the Maximum Extensible Path**:
   - For each node, update the `maxSum` variable with the highest sum seen so far, based on `node's value + left subtree sum + right subtree sum`.
   - Return `node’s value + max(leftSum, rightSum)` as the maximum path sum that can extend upwards to the parent node.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <climits> // for INT_MIN
#include <algorithm> // for max

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
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxSumPath(root, maxSum);
        return maxSum;
    }

private:
    int maxSumPath(TreeNode* root, int& maxSum) {
        if (root == nullptr) return 0;

        // Compute the maximum path sums of left and right subtrees, ignoring negative sums
        int leftSum = std::max(0, maxSumPath(root->left, maxSum));
        int rightSum = std::max(0, maxSumPath(root->right, maxSum));

        // Update maxSum with the best option found at this node
        maxSum = std::max(maxSum, root->val + leftSum + rightSum);

        // Return the maximum path sum that can extend upwards
        return root->val + std::max(leftSum, rightSum);
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
    public int maxPathSum(TreeNode root) {
        int[] maxSum = new int[]{Integer.MIN_VALUE};
        maxSumPath(root, maxSum);
        return maxSum[0];
    }

    private int maxSumPath(TreeNode root, int[] maxSum) {
        if (root == null) return 0;

        // Compute maximum path sums of left and right subtrees, ignoring negative sums
        int leftSum = Math.max(0, maxSumPath(root.left, maxSum));
        int rightSum = Math.max(0, maxSumPath(root.right, maxSum));

        // Update maxSum with the best option found at this node
        maxSum[0] = Math.max(maxSum[0], root.val + leftSum + rightSum);

        // Return the maximum path sum that can extend upwards
        return root.val + Math.max(leftSum, rightSum);
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the tree, since each node is visited once.
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

This documentation provides a comprehensive guide on solving the Maximum Path Sum problem in a binary tree, along with the code implementation and step-by-step explanations.
