# Kth Smallest Element in a BST

## Table of Contents

- [Kth Smallest Element in a BST](#kth-smallest-element-in-a-bst)
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

---

## Introduction

The goal is to find the **kth smallest element** in a Binary Search Tree (BST). In a BST, an in-order traversal produces a sorted sequence of node values. We can leverage this property to efficiently find the kth smallest element.

---

## Problem Description

Given:

- A BST represented by its root node.
- An integer `k`, representing the 1-indexed position of the desired smallest element.

Return:

- The `kth` smallest value in the BST.

---

### Examples

#### Example 1

**Input Tree:**

```bash
        3
       / \
      1   4
       \
        2
```

**k:** `1`  
**Output:** `1`  
**Explanation:** The smallest element is `1`.

---

#### Example 2

**Input Tree:**

```bash
        5
       / \
      3   6
     / \
    2   4
   /
  1
```

**k:** `3`  
**Output:** `3`  
**Explanation:** The sorted sequence is `[1, 2, 3, 4, 5, 6]`. The 3rd smallest element is `3`.

---

### Constraints

1. The number of nodes in the BST is `n`.
2. `1 <= k <= n <= 10⁴`.
3. `0 <= Node.val <= 10⁴`.

---

## Approach

1. **In-order Traversal:** Perform an in-order traversal of the BST. This will give a sorted sequence of node values.
2. **Count Nodes:** Maintain a counter to keep track of the number of visited nodes.
3. **Stop Early:** Stop the traversal as soon as the `kth` node is reached.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
private:
    void inorder(TreeNode* node, int& counter, int k, int& kthSmallest) {
        if (!node || counter >= k) return;

        // Traverse the left subtree
        inorder(node->left, counter, k, kthSmallest);

        // Increment counter and check if current node is the kth smallest
        counter++;
        if (counter == k) {
            kthSmallest = node->val;
            return;
        }

        // Traverse the right subtree
        inorder(node->right, counter, k, kthSmallest);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        int kthSmallest = INT_MIN;
        inorder(root, counter, k, kthSmallest);
        return kthSmallest;
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
    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

class Solution {
    private void inorder(TreeNode node, int[] counter, int k, int[] kthSmallest) {
        if (node == null || counter[0] >= k) return;

        // Traverse the left subtree
        inorder(node.left, counter, k, kthSmallest);

        // Increment counter and check if current node is the kth smallest
        counter[0]++;
        if (counter[0] == k) {
            kthSmallest[0] = node.val;
            return;
        }

        // Traverse the right subtree
        inorder(node.right, counter, k, kthSmallest);
    }

    public int kthSmallest(TreeNode root, int k) {
        int[] counter = new int[]{0};
        int[] kthSmallest = new int[]{Integer.MIN_VALUE};
        inorder(root, counter, k, kthSmallest);
        return kthSmallest[0];
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**

  - In the worst case, we traverse all nodes of the BST, which takes `O(n)`, where `n` is the number of nodes.
  - In a balanced BST, the complexity is `O(k)` since we stop as soon as the kth node is found.

- **Space Complexity:**
  - The space complexity is `O(h)`, where `h` is the height of the BST. This is due to the recursive call stack.
  - In a balanced BST, `h = log(n)`.

---

## How to Run the Code

### For C++

1. Include the above implementation in your IDE.
2. Construct a BST by manually linking nodes or using a helper function.
3. Call the `kthSmallest()` function with the root and value of `k`.

### For Java

1. Include the Java implementation in a class file.
2. Construct the BST using the `TreeNode` class.
3. Call the `kthSmallest()` method with the root node and `k`.
