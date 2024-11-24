# Ceil in BST

## Table of Contents

- [Ceil in BST](#ceil-in-bst)
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

The problem involves finding the **ceil** of a given number `X` in a Binary Search Tree (BST). The **ceil** of `X` is the smallest value in the BST that is greater than or equal to `X`. If no such value exists, return `-1`.

## Problem Description

### Examples

**Example 1:**  
**Input:**

```bash
Tree:     5
         / \
        1   7
         \
          2
           \
            3
X = 3
```

**Output:**  
`3`  
**Explanation:** The number `3` exists in the BST, so the ceil is `3`.

---

**Example 2:**  
**Input:**

```bash
Tree:    10
         /  \
        5    11
       / \
      4   7
           \
            8
X = 6
```

**Output:**  
`7`  
**Explanation:** The number `6` does not exist, but the smallest number greater than `6` is `7`.

### Constraints

- \(1 \leq \text{Number of nodes} \leq 10^5\)
- \(1 \leq \text{Value of nodes} \leq 10^5\)

## Approach

- Use the properties of a BST to efficiently find the ceil:
  1. Traverse the tree starting from the root.
  2. If `X` equals the current node's value, return the value.
  3. If `X` is smaller than the current node's value, store the node's value as a potential ceil and move to the left subtree.
  4. If `X` is greater than the current node's value, move to the right subtree.
  5. If the traversal ends without finding a suitable value, return `-1`.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to return the ceil of a given number in BST.
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;

    int ceil = -1;

    while (root) {
        if (root->data == input) {
            ceil = root->data;
            return ceil;
        }

        if (input > root->data) {
            root = root->right;
        } else {
            ceil = root->data;
            root = root->left;
        }
    }

    return ceil;
}
```

---

### Java Implementation

```java
class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = null;
        right = null;
    }
}

class Solution {
    public static int findCeil(Node root, int input) {
        if (root == null) return -1;

        int ceil = -1;

        while (root != null) {
            if (root.data == input) {
                ceil = root.data;
                return ceil;
            }

            if (input > root.data) {
                root = root.right;
            } else {
                ceil = root.data;
                root = root.left;
            }
        }

        return ceil;
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(h)\), where \(h\) is the height of the tree. For a balanced BST, \(h = O(\log n)\). In the worst case (skewed tree), \(h = O(n)\).

- **Space Complexity:**  
  \(O(1)\), as the implementation uses constant space (iterative approach).

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `FindCeil.cpp`.
2. Compile the file:

   ```bash
   g++ -o FindCeil FindCeil.cpp
   ```

3. Run the executable:

   ```bash
   ./FindCeil
   ```

### For Java

1. Save the code in a file, e.g., `Solution.java`.
2. Compile the file:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
