# Top View of Binary Tree

## Table of Contents

- [Top View of Binary Tree](#top-view-of-binary-tree)
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

The **Top View of a Binary Tree** problem requires you to display the set of nodes visible when looking at a binary tree from above. In other words, the "top view" is the collection of nodes that appear at each horizontal distance from the root node when viewed from above.

## Problem Description

Given the root of a binary tree, write a function to return the top view of the tree from leftmost to rightmost node.

### Examples

1. **Input Tree**:

   ```plaintext
       1
      / \
     2   3
   ```

   **Output**: `2 1 3`  
   **Explanation**: Nodes visible from the top are 2, 1, and 3.

2. **Input Tree**:

   ```plaintext
       10
      /  \
     20   30
    /  \    \
   40  60    100
   ```

   **Output**: `40 20 10 30 100`  
   **Explanation**: Nodes visible from the top are 40, 20, 10, 30, and 100.

### Constraints

- \(1 \leq \text{Number of nodes} \leq 10^5\)
- \(1 \leq \text{Node value} \leq 10^5\)

## Approach

To solve this problem, we use a **Breadth-First Search (BFS)** traversal. The following steps are used:

1. **Horizontal Distance Tracking**:

   - Each node in the tree is assigned a horizontal distance relative to the root node, which has a distance of 0.
   - For each left child, decrement the horizontal distance by 1.
   - For each right child, increment the horizontal distance by 1.

2. **Data Structures**:

   - **Map** (`mpp`): Stores the first node encountered at each horizontal distance.
   - **Queue** (`q`): Stores nodes alongside their horizontal distances for BFS traversal.

3. **Algorithm**:
   - Initialize the root node with a horizontal distance of 0.
   - For each node, add it to the map only if it is the first node encountered at that horizontal distance.
   - After traversal, output the map values in the order of their horizontal distances.

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
    vector<int> topView(Node* root) {
        vector<int> ans;
        if (root == nullptr) return ans;

        // Map to store the first node at each horizontal distance
        map<int, int> mpp;
        queue<pair<Node*, int>> q;
        q.push({root, 0});

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;

            // Only add the first node at each horizontal distance
            if (mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }

            // Add children nodes to queue with updated horizontal distances
            if (node->left) q.push({node->left, line - 1});
            if (node->right) q.push({node->right, line + 1});
        }

        // Collect the top view nodes in order of horizontal distance
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
    public List<Integer> topView(TreeNode root) {
        List<Integer> result = new ArrayList<>();
        if (root == null) return result;

        // Map to store the first node at each horizontal distance
        Map<Integer, Integer> map = new TreeMap<>();
        Queue<Pair<TreeNode, Integer>> queue = new LinkedList<>();
        queue.offer(new Pair<>(root, 0));

        while (!queue.isEmpty()) {
            Pair<TreeNode, Integer> pair = queue.poll();
            TreeNode node = pair.getKey();
            int line = pair.getValue();

            // Only add the first node at each horizontal distance
            map.putIfAbsent(line, node.val);

            // Add left and right children with updated horizontal distances
            if (node.left != null) queue.offer(new Pair<>(node.left, line - 1));
            if (node.right != null) queue.offer(new Pair<>(node.right, line + 1));
        }

        // Collect the top view nodes in order of horizontal distance
        for (int value : map.values()) {
            result.add(value);
        }
        return result;
    }
}
```

## Complexity Analysis

- **Time Complexity**: \(O(N \log N)\), where \(N\) is the number of nodes in the tree. The map insertion takes \(O(\log N)\) for each node.
- **Space Complexity**: \(O(N)\), for storing nodes in the map and queue.

## How to Run the Code

### For C++

1. Copy the C++ code into a file named `TopViewBinaryTree.cpp`.
2. Compile using a C++ compiler: `g++ -o topview TopViewBinaryTree.cpp`.
3. Run the compiled program with `./topview`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This documentation provides a complete guide for implementing the top view of a binary tree in C++ and Java. It includes a description of the problem, code, complexity analysis, and instructions for running the code.
