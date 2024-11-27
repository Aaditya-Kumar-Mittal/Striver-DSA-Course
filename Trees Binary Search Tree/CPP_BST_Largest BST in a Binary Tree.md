# Largest BST in a Binary Tree

## Table of Contents

- [Largest BST in a Binary Tree](#largest-bst-in-a-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
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

The task is to find the **size of the largest BST subtree** within a binary tree. The size is defined as the number of nodes in the subtree. A subtree is a valid BST if:

1. All nodes in the left subtree are smaller than the root.
2. All nodes in the right subtree are larger than the root.
3. There are no duplicate values in the subtree.

---

## Problem Description

### Input

- Root of a binary tree.

### Output

- An integer representing the size of the largest BST subtree.

---

### Examples

#### Example 1

**Input:**  

```plaintext
root = [5, 2, 4, 1, 3]
```

**Output:**  

```plaintext
3
```

**Explanation:**  
The subtree `[2, 1, 3]` is a valid BST of size 3.

---

#### Example 2

**Input:**  

```plaintext
root = [6, 7, 3, N, 2, 2, 4]
```

**Output:**  

```plaintext
3
```

**Explanation:**  
The subtree `[3, N, 4]` is a valid BST of size 3.

---

### Constraints

- `1 ≤ number of nodes ≤ 10^5`
- `1 ≤ node->data ≤ 10^5`

---

## Approach

The problem can be solved efficiently using a **bottom-up traversal**:

1. **Define Node Properties:**
   - `minNode`: Minimum value in the subtree.
   - `maxNode`: Maximum value in the subtree.
   - `maxSize`: Size of the largest BST in the subtree.

2. **Recursive Computation:**
   - For each node, recursively compute properties for left and right subtrees.
   - Check if the current subtree satisfies the BST conditions:
     - Left subtree's `maxNode < root->data`.
     - Right subtree's `minNode > root->data`.

3. **Update Node Values:**
   - If valid BST, update `maxSize` as the sum of sizes of left and right subtrees plus 1.
   - If not, propagate the larger `maxSize` from left or right subtree.

4. **Base Case:**
   - A null node is a valid BST with size 0, `minNode = INT_MAX`, and `maxNode = INT_MIN`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
struct Node {
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Helper class to store information for each node
class NodeValue {
public:
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtree(Node* root) {
        // Base case: null node
        if (!root) return NodeValue(INT_MAX, INT_MIN, 0);

        // Recursively find values for left and right subtrees
        NodeValue left = largestBSTSubtree(root->left);
        NodeValue right = largestBSTSubtree(root->right);

        // Check if current tree is a BST
        if (left.maxNode < root->data && root->data < right.minNode) {
            return NodeValue(
                min(root->data, left.minNode),
                max(root->data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // If not a BST, propagate maxSize without updating min/maxNode
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    int largestBst(Node* root) {
        return largestBSTSubtree(root).maxSize;
    }
};
```

---

### Java Implementation

```java
class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}

class NodeValue {
    int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize) {
        this.maxNode = maxNode;
        this.minNode = minNode;
        this.maxSize = maxSize;
    }
}

class Solution {
    private NodeValue largestBSTSubtree(Node root) {
        if (root == null) return new NodeValue(Integer.MAX_VALUE, Integer.MIN_VALUE, 0);

        NodeValue left = largestBSTSubtree(root.left);
        NodeValue right = largestBSTSubtree(root.right);

        if (left.maxNode < root.data && root.data < right.minNode) {
            return new NodeValue(
                Math.min(root.data, left.minNode),
                Math.max(root.data, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        return new NodeValue(Integer.MIN_VALUE, Integer.MAX_VALUE, Math.max(left.maxSize, right.maxSize));
    }

    public int largestBst(Node root) {
        return largestBSTSubtree(root).maxSize;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Traversal:** `O(n)` (each node is visited once).
- **Overall:** `O(n)`.

### Space Complexity

- **Recursive Call Stack:** `O(h)`, where `h` is the height of the tree.

---

## How to Run the Code

### For C++

1. **Compile:**

   ```bash
   g++ -o solution solution.cpp
   ```

2. **Run:**

   ```bash
   ./solution
   ```

### For Java

1. **Compile:**

   ```bash
   javac Solution.java
   ```

2. **Run:**

   ```bash
   java Solution
   ```
