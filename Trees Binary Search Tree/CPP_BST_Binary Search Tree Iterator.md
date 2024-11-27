# Binary Search Tree Iterator

## Table of Contents

- [Binary Search Tree Iterator](#binary-search-tree-iterator)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
    - [Constraints](#constraints)
    - [Follow-Up Requirements](#follow-up-requirements)
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

The **BSTIterator** class implements an in-order iterator for a Binary Search Tree (BST). It enables efficient traversal of the BST in sorted order with two operations:

1. **`next()`**: Retrieves the next smallest element.
2. **`hasNext()`**: Checks if there are more elements to process.

The iterator uses a stack to mimic the recursion of an in-order traversal.

---

## Problem Description

Implement the **BSTIterator** class with the following methods:

1. **`BSTIterator(TreeNode root)`**  
   Initializes the iterator object and prepares the in-order traversal starting from the given root.

2. **`int next()`**  
   Moves to the next element and returns its value.

3. **`boolean hasNext()`**  
   Returns `true` if there are more elements to process in the traversal; otherwise, returns `false`.

---

### Examples

#### Example 1

**Input:**  

```plaintext
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]  
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
```

**Output:**  

```plaintext
[null, 3, 7, true, 9, true, 15, true, 20, false]
```

**Explanation:**  

1. `BSTIterator([7, 3, 15, null, null, 9, 20])`: Initializes the BSTIterator.  
2. `next()`: Returns `3` (smallest value).  
3. `next()`: Returns `7`.  
4. `hasNext()`: Returns `true` (elements exist).  
5. `next()`: Returns `9`.  
6. `hasNext()`: Returns `true`.  
7. `next()`: Returns `15`.  
8. `hasNext()`: Returns `true`.  
9. `next()`: Returns `20`.  
10. `hasNext()`: Returns `false`.

---

### Constraints

- `1 <= Number of nodes <= 10^5`  
- `0 <= Node.val <= 10^6`  
- Up to `10^5` calls to `hasNext()` and `next()`.

---

### Follow-Up Requirements

- Implement **`next()`** and **`hasNext()`** with:  
  - **Time complexity:** Average `O(1)`.  
  - **Space complexity:** `O(h)`, where `h` is the height of the BST.

---

## Approach

The iterator is implemented using a **stack** to simulate the in-order traversal.  

1. Push all left nodes starting from the root onto the stack.
2. **`next()`**:
   - Pop the top of the stack (current smallest).
   - Push all left children of the popped node's right subtree onto the stack.
3. **`hasNext()`**:
   - Simply check if the stack is non-empty.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <stack>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
    stack<TreeNode*> myStack;

    // Helper to push all left nodes of a subtree
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAll(root); // Initialize stack with leftmost nodes
    }

    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        pushAll(temp->right); // Push left subtree of the right child
        return temp->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }
};
```

---

### Java Implementation

```java
import java.util.Stack;

// Definition for a binary tree node
class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode() { val = 0; left = null; right = null; }
    TreeNode(int x) { val = x; left = null; right = null; }
    TreeNode(int x, TreeNode left, TreeNode right) {
        val = x;
        this.left = left;
        this.right = right;
    }
}

class BSTIterator {
    private Stack<TreeNode> stack = new Stack<>();

    // Helper to push all left nodes of a subtree
    private void pushAll(TreeNode node) {
        while (node != null) {
            stack.push(node);
            node = node.left;
        }
    }

    public BSTIterator(TreeNode root) {
        pushAll(root); // Initialize stack with leftmost nodes
    }

    public int next() {
        TreeNode temp = stack.pop();
        pushAll(temp.right); // Push left subtree of the right child
        return temp.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**
  - `next()`: Average `O(1)` (each node is pushed/popped once).
  - `hasNext()`: `O(1)`.
- **Space Complexity:** `O(h)` where `h` is the height of the tree (stack size).

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
