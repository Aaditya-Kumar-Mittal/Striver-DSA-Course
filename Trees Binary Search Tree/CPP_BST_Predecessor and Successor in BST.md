# Predecessor and Successor in BST

## Table of Contents

- [Predecessor and Successor in BST](#predecessor-and-successor-in-bst)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The task is to find both the **inorder predecessor** and **inorder successor** of a given key in a Binary Search Tree (BST).

- The **predecessor** is the largest value smaller than the given key.
- The **successor** is the smallest value larger than the given key.

If either does not exist, return `NULL`.

---

## Problem Description

Given a BST with integer values and a key, determine the **predecessor** and **successor**.  
If the key is not present, consider where it would fit in the tree for successor/predecessor calculations.

---

### Examples

#### Example 1

**Input:**  
Tree:

```bash
    8
   / \
  1   9
   \    \
    4    10
   /
  3
```

`key = 8`

**Output:**  
Predecessor: `4`  
Successor: `9`

**Explanation:**  
Inorder traversal: `1 -> 3 -> 4 -> 8 -> 9 -> 10`.

- Predecessor of `8`: `4`
- Successor of `8`: `9`.

---

#### Example 2

**Input:**  
Tree:

```bash
        10
       /  \
      2    11
     / \
    1   5
       / \
      3   6
       \
        4
```

`key = 11`

**Output:**  
Predecessor: `10`  
Successor: `-1`

**Explanation:**  
Inorder traversal: `1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 10 -> 11`.

- Predecessor of `11`: `10`
- Successor of `11`: none.

---

#### Example 3

**Input:**  
Tree:

```bash
    2
   / \
  1   3
```

`key = 3`

**Output:**  
Predecessor: `2`  
Successor: `-1`

**Explanation:**  
Inorder traversal: `1 -> 2 -> 3`.

- Predecessor of `3`: `2`
- Successor of `3`: none.

---

### Constraints

- `1 <= Number of nodes <= 10^5`
- `1 <= key <= 10^7`

---

## Approach

### Algorithm

1. **Search for the key in the BST.**

   - If key is found:
     - **Predecessor:** Largest value in the left subtree (rightmost node in left child).
     - **Successor:** Smallest value in the right subtree (leftmost node in right child).
   - If key is not found:
     - Use the BST property to keep track of potential predecessors/successors as you traverse the tree.

2. Use iterative or recursive traversal based on the key comparison.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Node structure for the BST
struct Node {
    int key;
    Node *left, *right;
    Node(int x) : key(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key) {
        if (root == nullptr) return;

        while (root != nullptr) {
            if (root->key == key) {
                // Successor: Leftmost node in right subtree
                if (root->right) {
                    suc = root->right;
                    while (suc->left) suc = suc->left;
                }

                // Predecessor: Rightmost node in left subtree
                if (root->left) {
                    pre = root->left;
                    while (pre->right) pre = pre->right;
                }
                return;
            } else if (root->key < key) {
                pre = root;  // Update predecessor
                root = root->right;
            } else {
                suc = root;  // Update successor
                root = root->left;
            }
        }
    }
};
```

---

### Java Implementation

```java
// Node structure for the BST
class Node {
    int key;
    Node left, right;
    Node(int x) {
        key = x;
        left = right = null;
    }
}

class Solution {
    public void findPreSuc(Node root, Node[] pre, Node[] suc, int key) {
        if (root == null) return;

        while (root != null) {
            if (root.key == key) {
                // Successor: Leftmost node in right subtree
                if (root.right != null) {
                    suc[0] = root.right;
                    while (suc[0].left != null) {
                        suc[0] = suc[0].left;
                    }
                }

                // Predecessor: Rightmost node in left subtree
                if (root.left != null) {
                    pre[0] = root.left;
                    while (pre[0].right != null) {
                        pre[0] = pre[0].right;
                    }
                }
                return;
            } else if (root.key < key) {
                pre[0] = root;  // Update predecessor
                root = root.right;
            } else {
                suc[0] = root;  // Update successor
                root = root.left;
            }
        }
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**

  - `O(h)` in the worst case (height of the tree).  
    For balanced BST, `h = log(n)`; for skewed BST, `h = n`.

- **Space Complexity:**
  - **Iterative Solution:** `O(1)` (no extra memory used).
  - **Recursive Solution:** `O(h)` due to the call stack.

---

## How to Run the Code

### For C++

1. Compile the code using:

   ```bash
   g++ -o solution solution.cpp
   ```

2. Execute the program:

   ```bash
   ./solution
   ```

### For Java

1. Compile the Java code:

   ```bash
   javac Solution.java
   ```

2. Run the program:

   ```bash
   java Solution
   ```
