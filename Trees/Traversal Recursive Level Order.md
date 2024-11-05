# Level Order Traversal of Binary Trees

## Table of Contents

- [Level Order Traversal of Binary Trees](#level-order-traversal-of-binary-trees)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example](#example)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Example Walkthrough](#example-walkthrough)
    - [Level Order Traversal Steps](#level-order-traversal-steps)
    - [Final Result](#final-result)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [Running the C++ Code](#running-the-c-code)
    - [Running the Java Code](#running-the-java-code)
  - [Conclusion](#conclusion)

## Introduction

Level order traversal is a method of visiting all the nodes of a binary tree level by level, starting from the root and moving left to right. This is also known as **Breadth-First Traversal**.

## Problem Description

Given a binary tree, return its level order traversal as a 2D list, where each inner list contains the values of the nodes at that level.

### Example

For the binary tree:

```plaintext
    1
   / \
  2   3
 / \
4   5
```

The level order traversal should return `[[1], [2, 3], [4, 5]]`.

## Approach

To traverse the binary tree level by level, we can use a **queue** data structure. The algorithm involves processing each level of the tree, adding the node values to a list, and enqueuing their children for subsequent processing.

### Algorithm

1. Start with the root node and add it to the queue.
2. While the queue is not empty:
   - Determine the number of nodes at the current level (`size`).
   - For each node at this level:
     - Dequeue the node, add its value to the current level list.
     - Enqueue its left and right children if they exist.
3. Append the current level list to the result list.
4. Repeat until all levels are processed.

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);

                level.push_back(node->val);
            }
            ans.push_back(level);
        }

        return ans;
    }
};
```

### Java Implementation

```java
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val) {
        this.val = val;
        left = null;
        right = null;
    }
}

public class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if (root == null) {
            return ans;
        }

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            int size = q.size();
            List<Integer> level = new ArrayList<>();

            for (int i = 0; i < size; i++) {
                TreeNode node = q.poll();

                if (node.left != null) {
                    q.add(node.left);
                }
                if (node.right != null) {
                    q.add(node.right);
                }

                level.add(node.val);
            }
            ans.add(level);
        }

        return ans;
    }

    public static void main(String[] args) {
        // Create a sample binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);

        Solution solution = new Solution();
        List<List<Integer>> result = solution.levelOrder(root);

        // Print the result
        System.out.println("Level Order Traversal:");
        for (List<Integer> level : result) {
            System.out.println(level);
        }
    }
}
```

## Example Walkthrough

Consider the following binary tree:

```plaintext
    1
   / \
  2   3
 / \
4   5
```

### Level Order Traversal Steps

1. **Level 1**:
   - Queue: `[1]`
   - Process `1`, add its children (`2`, `3`) to the queue.
   - Result: `[[1]]`
2. **Level 2**:
   - Queue: `[2, 3]`
   - Process `2`, add its children (`4`, `5`) to the queue.
   - Process `3`, no children to add.
   - Result: `[[1], [2, 3]]`
3. **Level 3**:
   - Queue: `[4, 5]`
   - Process `4`, no children.
   - Process `5`, no children.
   - Result: `[[1], [2, 3], [4, 5]]`

### Final Result

The level order traversal list is `[[1], [2, 3], [4, 5]]`.

## Complexity Analysis

- **Time Complexity**: \( O(n) \), where \( n \) is the number of nodes in the tree. Each node is visited exactly once.
- **Space Complexity**: \( O(m) \), where \( m \) is the maximum number of nodes at any level (width of the tree).

## How to Run the Code

### Running the C++ Code

1. Copy the C++ code into your preferred C++ IDE or editor.
2. Compile using `g++ -o solution solution.cpp`.
3. Run the executable with `./solution`.

### Running the Java Code

1. Copy the Java code into a file named `Solution.java`.
2. Compile using `javac Solution.java`.
3. Run using `java Solution`.

## Conclusion

Level order traversal is an essential technique for visiting all nodes in a binary tree, ensuring nodes at each level are processed systematically. This approach leverages a queue, making it efficient and straightforward to implement.
