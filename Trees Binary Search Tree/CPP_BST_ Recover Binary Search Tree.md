# Recover Binary Search Tree

## Table of Contents

- [Recover Binary Search Tree](#recover-binary-search-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Task](#task)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
    - [Follow-up](#follow-up)
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
  - [Other Solutions](#other-solutions)
    - [Java Morris Traversal](#java-morris-traversal)

---

## Introduction

This problem involves recovering a Binary Search Tree (BST) where two nodes were swapped by mistake. The objective is to restore the BST to its correct structure without altering its tree shape.

---

## Problem Description

### Task

- Recover a BST where **exactly two nodes** were swapped.

### Input

- The root of a BST.

### Output

- The root of the corrected BST.

---

### Examples

#### Example 1

**Input:**

```plaintext
root = [1, 3, null, null, 2]
```

**Output:**

```plaintext
[3, 1, null, null, 2]
```

#### Example 2

**Input:**

```plaintext
root = [3, 1, 4, null, null, 2]
```

**Output:**

```plaintext
[2, 1, 4, null, null, 3]
```

---

### Constraints

- The number of nodes in the tree: `2 ≤ Number of nodes ≤ 1000`.
- Node values: `-2^31 ≤ Node.val ≤ 2^31 - 1`.

### Follow-up

Optimize for **constant space** complexity (`O(1)`).

---

## Approach

The problem is solved using **in-order traversal** since the correct in-order sequence of a BST is sorted.

1. **Identify Swapped Nodes:**

   - Traverse the tree using in-order traversal.
   - Track the nodes that violate the sorted property:
     - First violation: Store `first` and `middle`.
     - Second violation: Store `last`.

2. **Swap Values:**

   - If there are two violations, swap `first` and `last`.
   - Otherwise, swap `first` and `middle`.

3. **Optimize Space:**
   - Morris Traversal is used to achieve `O(1)` space, but this implementation uses `O(n)` stack space.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    TreeNode *first, *middle, *last, *prev;

    // In-order traversal to find swapped nodes
    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // Detect violation of BST property
        if (prev && root->val < prev->val) {
            if (!first) {
                first = prev;      // First swapped node
                middle = root;     // Second swapped node (adjacent case)
            } else {
                last = root;       // Second swapped node (non-adjacent case)
            }
        }
        prev = root;

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        // Initialize pointers
        first = middle = last = nullptr;
        prev = new TreeNode(INT_MIN);

        // Perform in-order traversal
        inorder(root);

        // Recover the tree by swapping values
        if (first && last) {
            swap(first->val, last->val);
        } else if (first && middle) {
            swap(first->val, middle->val);
        }
    }
};
```

---

### Java Implementation

```java
class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode() {
        this.val = 0;
        this.left = null;
        this.right = null;
    }

    TreeNode(int x) {
        this.val = x;
        this.left = null;
        this.right = null;
    }

    TreeNode(int x, TreeNode left, TreeNode right) {
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    private TreeNode first = null, middle = null, last = null, prev = null;

    // Helper function to perform in-order traversal
    private void inorder(TreeNode root) {
        if (root == null) return;

        inorder(root.left);

        // Detect violation of BST property
        if (prev != null && root.val < prev.val) {
            if (first == null) {
                first = prev;
                middle = root;
            } else {
                last = root;
            }
        }
        prev = root;

        inorder(root.right);
    }

    public void recoverTree(TreeNode root) {
        // Initialize pointers
        first = middle = last = null;
        prev = new TreeNode(Integer.MIN_VALUE);

        // Perform in-order traversal
        inorder(root);

        // Recover the tree by swapping values
        if (first != null && last != null) {
            int temp = first.val;
            first.val = last.val;
            last.val = temp;
        } else if (first != null && middle != null) {
            int temp = first.val;
            first.val = middle.val;
            middle.val = temp;
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **In-order Traversal:** `O(n)` (all nodes are visited once).

### Space Complexity

- **Recursive Approach:** `O(h)` (call stack for recursion, where `h` is the height of the tree).
- **Optimized Solution:** `O(1)` (using Morris Traversal).

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

## Other Solutions

### Java Morris Traversal

````java
public void recoverTree(TreeNode root) {
        TreeNode pre = null;
        TreeNode first = null, second = null;
        // Morris Traversal
        TreeNode temp = null;
  while(root!=null){
   if(root.left!=null){
    // connect threading for root
    temp = root.left;
    while(temp.right!=null && temp.right != root)
     temp = temp.right;
    // the threading already exists
    if(temp.right!=null){
        if(pre!=null && pre.val > root.val){
            if(first==null){first = pre;second = root;}
            else{second = root;}
        }
        pre = root;

     temp.right = null;
     root = root.right;
    }else{
     // construct the threading
     temp.right = root;
     root = root.left;
    }
   }else{
    if(pre!=null && pre.val > root.val){
        if(first==null){first = pre;second = root;}
        else{second = root;}
    }
    pre = root;
    root = root.right;
   }
  }
  // swap two node values;
  if(first!= null && second != null){
      int t = first.val;
      first.val = second.val;
      second.val = t;
  }
    }
    ```
````
