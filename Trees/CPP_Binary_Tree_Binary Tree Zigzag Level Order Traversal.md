# Binary Tree Zigzag Level Order Traversal

## Table of Contents

- [Binary Tree Zigzag Level Order Traversal](#binary-tree-zigzag-level-order-traversal)
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

The **zigzag level order traversal** of a binary tree involves traversing nodes at each level in an alternating order. The first level is traversed from left to right, the second from right to left, the third from left to right, and so on.

## Problem Description

Given the `root` of a binary tree, return the zigzag level order traversal of its nodes' values.

### Examples

1. **Input:** `root = [3,9,20,null,null,15,7]`  
   **Output:** `[[3],[20,9],[15,7]]`  
   **Explanation:** The first level is `[3]` (left to right), the second level is `[20, 9]` (right to left), and the third level is `[15, 7]` (left to right).

2. **Input:** `root = [1]`  
   **Output:** `[[1]]`  
   **Explanation:** There's only one node, so the output is a single level.

3. **Input:** `root = []`  
   **Output:** `[]`  
   **Explanation:** The tree is empty.

### Constraints

- The number of nodes in the tree is in the range \([0, 2000]\).
- \(-100 \leq \text{Node.val} \leq 100\).

## Approach

1. **Level Order Traversal**:
   - Use a queue to process nodes level by level.
   - For each level, keep track of the order in which nodes should be added (left-to-right or right-to-left).
2. **Tracking Direction**:
   - Use a `bool` variable `leftToRight` to toggle the order of traversal after each level.
   - If `leftToRight` is true, add node values in order; if false, add them in reverse order.
3. **Build Results**:
   - For each level, create a temporary vector `row` to store the values of nodes in that level.
   - Add `row` to the result list after processing each level, and toggle the direction.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <queue>

using namespace std;

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            vector<int> row(size);

            for (int i = 0; i < size; i++) {
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // Insert the node value at the appropriate index
                int index = leftToRight ? i : size - 1 - i;
                row[index] = node->val;

                // Add children for the next level
                if (node->left) nodesQueue.push(node->left);
                if (node->right) nodesQueue.push(node->right);
            }

            // Toggle the traversal direction
            leftToRight = !leftToRight;
            result.push_back(row);
        }

        return result;
    }
};
```

### Java Implementation

```java
import java.util.*;

// Definition for a binary tree node.
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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> result = new ArrayList<>();
        if (root == null) return result;

        Queue<TreeNode> nodesQueue = new LinkedList<>();
        nodesQueue.add(root);
        boolean leftToRight = true;

        while (!nodesQueue.isEmpty()) {
            int size = nodesQueue.size();
            List<Integer> row = new ArrayList<>(Collections.nCopies(size, 0));

            for (int i = 0; i < size; i++) {
                TreeNode node = nodesQueue.poll();

                // Find position to fill node's value
                int index = leftToRight ? i : size - 1 - i;
                row.set(index, node.val);

                // Add child nodes in the queue
                if (node.left != null) nodesQueue.add(node.left);
                if (node.right != null) nodesQueue.add(node.right);
            }

            // Toggle the traversal direction
            leftToRight = !leftToRight;
            result.add(row);
        }

        return result;
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(n)\), where \(n\) is the number of nodes in the tree, as each node is visited once.
- **Space Complexity**: \(O(n)\), for storing the nodes and results, and the queue.

## How to Run the Code

### For C++

1. Copy the C++ code into your preferred IDE or text editor.
2. Compile the code using a C++ compiler, e.g., `g++ -o solution solution.cpp`.
3. Run the compiled program with `./solution`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This documentation provides a detailed guide on how to implement and understand the zigzag level order traversal of a binary tree.
