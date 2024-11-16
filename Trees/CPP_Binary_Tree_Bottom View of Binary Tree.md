# Bottom View of Binary Tree

## Table of Contents

- [Bottom View of Binary Tree](#bottom-view-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Steps](#steps)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The **Bottom View of a Binary Tree** problem requires displaying the set of nodes that are visible when looking at the binary tree from below. The "bottom view" contains nodes that appear at each horizontal distance from the root, capturing the last visible node at each position when traversed level-by-level from top to bottom.

## Problem Description

Given the root of a binary tree, return the bottom view of the tree from leftmost to rightmost node. If there are multiple bottom-most nodes at the same horizontal distance, the latter one in the level traversal order is considered.

### Examples

1. **Input Tree**:

   ```plaintext
          20
        /    \
      8      22
    /   \   /   \
   5     3 4     25
        /    \
      10      14
   ```

   **Output**: `5 10 4 14 25`

   **Explanation**: Nodes visible from the bottom are 5, 10, 4, 14, and 25.

2. **Input Tree**:

   ```plaintext
      1
    /   \
   3     2
   ```

   **Output**: `3 1 2`

   **Explanation**: Nodes visible from the bottom are 3, 1, and 2.

### Constraints

- \(1 \leq \text{Number of nodes} \leq 10^5\)
- \(1 \leq \text{Node value} \leq 10^5\)

## Approach

To solve this problem, we use a **Breadth-First Search (BFS)** traversal, keeping track of each node's horizontal distance from the root.

### Steps

1. **Horizontal Distance Tracking**:

   - Assign a horizontal distance to each node, with the root at 0.
   - Left child decreases the distance by 1; right child increases it by 1.

2. **Data Structures**:

   - **Map (`mpp`)**: Stores the most recent node encountered at each horizontal distance, ensuring that only the bottom-most node is kept.
   - **Queue (`q`)**: Used for BFS traversal, storing each node and its horizontal distance.

3. **Algorithm**:
   - Initialize the root node with a horizontal distance of 0 and traverse using BFS.
   - For each node, update the map with the current node as the most recent node at that distance.
   - After traversal, output the values in the map, ordered by horizontal distance.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
#include <map>
#include <queue>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<int> bottomView(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        // Map to store the last node at each horizontal distance
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            // Update the map with the current node at each horizontal distance
            mpp[line] = node->data;

            // Add children nodes to queue with updated horizontal distances
            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        // Collect the bottom view nodes in order of horizontal distance
        for (auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
```

### Java Implementation

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

public class Solution {
    public List<Integer> bottomView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // Map to store the last node at each horizontal distance
        Map<Integer, Integer> map = new TreeMap<>();
        Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        queue.offer(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.poll();
            TreeNode node = pair.getKey();
            int line = pair.getValue();

            // Update the map with the current node at each horizontal distance
            map.put(line, node.val);

            // Add left and right children with updated horizontal distances
            if (node.left != null) queue.offer(new Pair<>(node.left, line - 1));
            if (node.right != null) queue.offer(new Pair<>(node.right, line + 1));
        }

        // Collect the bottom view nodes in order of horizontal distance
        for (int value : map.values()) {
            result.add(value);
        }
        return result;
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(N \log N)\), where \(N\) is the number of nodes in the tree. This accounts for map insertion, which takes \(O(\log N)\) for each node.
- **Space Complexity**: \(O(N)\), for storing nodes in the map and queue.

## How to Run the Code

### For C++

1. Copy the C++ code into a file named `BottomViewBinaryTree.cpp`.
2. Compile using a C++ compiler: `g++ -o bottomview BottomViewBinaryTree.cpp`.
3. Run the compiled program with `./bottomview`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This documentation provides a comprehensive guide for implementing the bottom view of a binary tree in C++ and Java, including problem description, code explanation, complexity analysis, and instructions for running the code.
