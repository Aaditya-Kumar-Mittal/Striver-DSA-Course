# Insert into a Binary Search Tree

## Table of Contents

- [Insert into a Binary Search Tree](#insert-into-a-binary-search-tree)
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
  - [Other Solutions](#other-solutions)
    - [CPP Recursive Solution](#cpp-recursive-solution)

---

## Introduction

The problem is to insert a new value into a Binary Search Tree (BST) while maintaining its BST properties. The function should return the root of the modified BST.

---

## Problem Description

### Examples

**Example 1:**  
**Input:**

```bash
root = [4,2,7,1,3], val = 5
```

**Output:**

```bash
[4,2,7,1,3,5]
```

---

**Example 2:**  
**Input:**

```bash
root = [40,20,60,10,30,50,70], val = 25
```

**Output:**

```bash
[40,20,60,10,30,50,70,null,null,25]
```

---

**Example 3:**  
**Input:**

```bash
root = [4,2,7,1,3,null,null,null,null,null,null], val = 5
```

**Output:**

```bash
[4,2,7,1,3,5]
```

---

### Constraints

- The number of nodes in the tree is in the range \([0, 10^4]\).
- \(-10^8 \leq \text{Node.val}, \text{val} \leq 10^8\).
- All node values in the BST are **unique**.
- It is guaranteed that `val` does not exist in the original BST.

---

## Approach

1. **BST Insertion Properties**:

   - If the `val` is less than the current node value, move to the left subtree.
   - If the `val` is greater than the current node value, move to the right subtree.

2. **Iterative Solution**:

   - Traverse the tree iteratively until the correct position is found.
   - Insert the new value as a left or right child as appropriate.

3. **Recursive Solution**:
   - Recursively find the position to insert the value.
   - Insert the new node and return the modified subtree.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
            return new TreeNode(val);

        TreeNode* current = root;

        while (true) {
            if (val > current->val) {
                if (current->right != nullptr) {
                    current = current->right;
                } else {
                    current->right = new TreeNode(val);
                    break;
                }
            } else {
                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    current->left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
};
```

---

### Java Implementation

```java
// Definition for a binary tree node.
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {}
    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public TreeNode insertIntoBST(TreeNode root, int val) {
        if (root == null) {
            return new TreeNode(val);
        }

        TreeNode current = root;

        while (true) {
            if (val > current.val) {
                if (current.right != null) {
                    current = current.right;
                } else {
                    current.right = new TreeNode(val);
                    break;
                }
            } else {
                if (current.left != null) {
                    current = current.left;
                } else {
                    current.left = new TreeNode(val);
                    break;
                }
            }
        }

        return root;
    }
}
```

---

## Complexity Analysis

- **Time Complexity:** \(O(h)\), where \(h\) is the height of the tree. In the worst case, \(h = \log(n)\) for a balanced BST and \(h = n\) for a skewed BST.
- **Space Complexity:**
  - **Iterative Approach:** \(O(1)\), as no extra space is used.
  - **Recursive Approach:** \(O(h)\) due to recursion stack.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `InsertBST.cpp`.
2. Compile the file:

   ```bash
   g++ -o InsertBST InsertBST.cpp
   ```

3. Run the executable:

   ```bash
   ./InsertBST
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

## Other Solutions

### CPP Recursive Solution

```cpp
class Solution
{
public:
  TreeNode *insertIntoBST(TreeNode *root, int val)
  {
    if (!root)
      return new TreeNode(val);
    if (root->val > val)
      root->left = insertIntoBST(root->left, val);
    else
      root->right = insertIntoBST(root->right, val);
    return root;
  }
};
```
