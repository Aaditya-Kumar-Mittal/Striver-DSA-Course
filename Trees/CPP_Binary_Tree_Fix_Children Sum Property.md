# Children Sum Property

## Table of Contents

- [Children Sum Property](#children-sum-property)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Steps](#key-steps)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Explanation](#explanation)
  - [Additional Examples](#additional-examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Example 3](#example-3)

---

## Problem Description

Given a binary tree, modify it such that it adheres to the **Children Sum Property**. This property states that the value of every node should equal the sum of the values of its left and right child nodes. If the sum of the child nodes is less than the node value, increase the child node values to satisfy this property.

### Input

- A binary tree with `N` nodes.
- Each node has a value between `1` and `10^6`.
- An empty tree is allowed.

### Output

- The tree modified to satisfy the **Children Sum Property**.

### Constraints

- \(1 \leq T \leq 100\) (Test cases)
- \(0 \leq N \leq 100\)
- \(1 \leq \text{Node Value} \leq 10^6\)
- Time Limit: \(1\) second

---

## Approach

This problem uses **depth-first traversal** to adjust node values recursively.

### Key Steps

1. Start from the root node.
2. For each node:
   - Calculate the sum of its left and right child nodes.
   - If the sum is greater than or equal to the node’s value, update the node’s value.
   - If the sum is less than the node’s value, increment the children’s values to match the node’s value.
3. Recursively ensure the Children Sum Property for child nodes.
4. On backtracking, adjust parent nodes to the sum of updated child nodes.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

/*************************************************************
    Following is the Binary Tree node structure

    template <typename T>
    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };
*************************************************************/

void changeTree(BinaryTreeNode<int>* root) {
    if (root == nullptr) return;

    int childSum = 0;
    if (root->left) childSum += root->left->data;
    if (root->right) childSum += root->right->data;

    if (childSum >= root->data) {
        root->data = childSum;
    } else {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    changeTree(root->left);
    changeTree(root->right);

    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;

    if (root->left || root->right) root->data = total;
}
```

---

## Java Implementation

```java
/*************************************************************
    Following is the Binary Tree node structure

    class BinaryTreeNode<T> {
        public T data;
        public BinaryTreeNode<T> left;
        public BinaryTreeNode<T> right;

        public BinaryTreeNode(T data) {
            this.data = data;
            left = null;
            right = null;
        }
    };
*************************************************************/

public class Solution {
    public static void changeTree(BinaryTreeNode<Integer> root) {
        if (root == null) return;

        int childSum = 0;
        if (root.left != null) childSum += root.left.data;
        if (root.right != null) childSum += root.right.data;

        if (childSum >= root.data) {
            root.data = childSum;
        } else {
            if (root.left != null) root.left.data = root.data;
            if (root.right != null) root.right.data = root.data;
        }

        changeTree(root.left);
        changeTree(root.right);

        int total = 0;
        if (root.left != null) total += root.left.data;
        if (root.right != null) total += root.right.data;

        if (root.left != null || root.right != null) root.data = total;
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the binary tree. Each node is visited once.
- **Space Complexity**: \(O(H)\), where \(H\) is the height of the tree. This is due to the recursion stack.

### Explanation

1. **Time Complexity**: The function recursively traverses each node once, performing constant-time operations at each node.
2. **Space Complexity**: In the worst case (skewed tree), the recursion stack will store \(N\) calls, resulting in \(O(N)\). In a balanced tree, \(O(\log N)\) space is used.

---

## Additional Examples

### Example 1

**Input Tree**:

```bash
       2
      / \
     35  10
    /  \
   2    3
```

**Modified Tree**:

```bash
       45
      /  \
     35   10
    /  \
   30   5
```

### Example 2

**Input Tree**:

```bash
       10
      /  \
     5    5
```

**Modified Tree**:

```bash
       10
      /  \
     5    5
```

Both children already satisfy the property. No change needed.

### Example 3

**Input Tree**:

```bash
       8
      / \
     3   4
```

**Modified Tree**:

```bash
       8
      / \
     3   5
```

In this example, the right child is incremented to make the sum equal to 8.
