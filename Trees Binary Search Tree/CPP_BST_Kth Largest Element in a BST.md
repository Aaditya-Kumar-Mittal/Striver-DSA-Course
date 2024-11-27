# Kth Largest Element in a BST

## Table of Contents

- [Kth Largest Element in a BST](#kth-largest-element-in-a-bst)
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

---

## Introduction

The goal is to find the **kth largest element** in a Binary Search Tree (BST) without modifying the structure of the tree. To solve this problem, we leverage the property of **reverse in-order traversal** of a BST, which produces a descending sequence of node values.

---

## Problem Description

Given:

- A BST represented by its root node.
- An integer `k`, representing the 1-indexed position of the desired largest element.

Return:

- The `kth` largest value in the BST.

---

### Examples

#### Example 1

**Input Tree:**

```bash
        4
       / \
      2   9
```

**k:** `2`  
**Output:** `4`  
**Explanation:** The sorted descending sequence is `[9, 4, 2]`. The 2nd largest element is `4`.

---

#### Example 2

**Input Tree:**

```bash
        9
         \
         10
```

**k:** `1`  
**Output:** `10`  
**Explanation:** The largest element is `10`.

---

#### Example 3

**Input Tree:**

```bash
        4
       / \
      2   9
```

**k:** `3`  
**Output:** `2`  
**Explanation:** The sorted descending sequence is `[9, 4, 2]`. The 3rd largest element is `2`.

---

### Constraints

1. `1 <= number of nodes <= 10⁵`.
2. `1 <= node->data <= 10⁵`.
3. `1 <= k <= number of nodes`.

---

## Approach

1. **Reverse In-order Traversal:** Perform a reverse in-order traversal (right, root, left) to traverse the tree in descending order.
2. **Count Nodes:** Use a counter to track the number of visited nodes.
3. **Stop Early:** Stop traversal as soon as the `kth` largest node is found.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Tree Node Structure
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Solution Class
class Solution {
private:
    void reverse_inorder(Node* node, int& counter, int k, int& kLargest) {
        if (!node || counter >= k) return;

        // Traverse the right subtree
        reverse_inorder(node->right, counter, k, kLargest);

        // Increment counter and check if the current node is the kth largest
        counter++;
        if (counter == k) {
            kLargest = node->data;
            return;
        }

        // Traverse the left subtree
        reverse_inorder(node->left, counter, k, kLargest);
    }

public:
    int kthLargest(Node* root, int k) {
        int counter = 0;
        int kLargest = INT_MIN;
        reverse_inorder(root, counter, k, kLargest);
        return kLargest;
    }
};
```

---

### Java Implementation

```java
// Tree Node Structure
class Node {
    int data;
    Node left, right;
    Node(int val) {
        data = val;
        left = right = null;
    }
}

// Solution Class
class Solution {
    private void reverseInorder(Node node, int[] counter, int k, int[] kLargest) {
        if (node == null || counter[0] >= k) return;

        // Traverse the right subtree
        reverseInorder(node.right, counter, k, kLargest);

        // Increment counter and check if the current node is the kth largest
        counter[0]++;
        if (counter[0] == k) {
            kLargest[0] = node.data;
            return;
        }

        // Traverse the left subtree
        reverseInorder(node.left, counter, k, kLargest);
    }

    public int kthLargest(Node root, int k) {
        int[] counter = new int[]{0};
        int[] kLargest = new int[]{Integer.MIN_VALUE};
        reverseInorder(root, counter, k, kLargest);
        return kLargest[0];
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**

  - Worst-case: `O(n)` if we traverse the entire tree.
  - Best-case: `O(k)` when `k` is much smaller than `n`.

- **Space Complexity:**
  - **Recursive Call Stack:** `O(h)`, where `h` is the height of the tree.
  - In a balanced BST, `h = log(n)`.

---

## How to Run the Code

### For C++

1. Include the `Solution` class and the `Node` structure in your file.
2. Use a helper function to construct the tree from input.
3. Call the `kthLargest()` function with the root and `k`.

### For Java

1. Include the `Solution` and `Node` classes.
2. Use a helper function to construct the tree from input.
3. Call the `kthLargest()` method with the root and `k`.
