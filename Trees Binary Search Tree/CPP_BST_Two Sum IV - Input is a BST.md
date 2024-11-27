# Two Sum IV - Input is a BST

## Table of Contents

- [Two Sum IV - Input is a BST](#two-sum-iv---input-is-a-bst)
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
  - [Other Solutions](#other-solutions)
    - [CPP Iterative Solution](#cpp-iterative-solution)

---

## Introduction

The **Two Sum IV - Input is a BST** problem requires determining whether there exist two elements in a Binary Search Tree (BST) whose sum equals a given target value `k`. The solution leverages the BST structure and in-order traversal to efficiently solve the problem.

---

## Problem Description

Given:

- A **root** node of a BST.
- An integer **k**.

Return:

- `true` if there are two nodes in the BST such that their sum equals `k`.
- `false` otherwise.

---

### Examples

#### Example 1

**Input:**

```plaintext
root = [5, 3, 6, 2, 4, null, 7], k = 9
```

**Output:**

```plaintext
true
```

#### Example 2

**Input:**

```plaintext
root = [5, 3, 6, 2, 4, null, 7], k = 28
```

**Output:**

```plaintext
false
```

---

### Constraints

- Number of nodes: `1 <= Number of nodes <= 10^4`
- Node values: `-10^4 <= Node.val <= 10^4`
- Target value: `-10^5 <= k <= 10^5`

---

## Approach

This problem uses **two-pointer traversal** on the BST:

1. **In-order Traversal (sorted order):**
   - Use a forward iterator to traverse the tree from the smallest to the largest value.
2. **Reverse In-order Traversal (reverse sorted order):**
   - Use a backward iterator to traverse the tree from the largest to the smallest value.
3. **Two-pointer Technique:**
   - Start with two pointers (smallest and largest).
   - Check the sum of their values:
     - If the sum equals `k`, return `true`.
     - If the sum is less than `k`, move the forward pointer.
     - If the sum is greater than `k`, move the backward pointer.

This approach leverages the BST's structure for efficient traversal and comparison.

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
    bool reverse;

    // Helper to push nodes in the desired direction
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            myStack.push(node);
            node = reverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }

    int next() {
        TreeNode* temp = myStack.top();
        myStack.pop();
        if (!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->val;
    }

    bool hasNext() {
        return !myStack.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator l(root, false);  // Forward iterator
        BSTIterator r(root, true);  // Reverse iterator

        int i = l.next();  // Smallest value
        int j = r.next();  // Largest value

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
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
        this.val = x;
        this.left = left;
        this.right = right;
    }
}

class BSTIterator {
    private Stack<TreeNode> stack = new Stack<>();
    private boolean reverse;

    // Constructor
    public BSTIterator(TreeNode root, boolean isReverse) {
        this.reverse = isReverse;
        pushAll(root);
    }

    // Helper to push nodes in desired direction
    private void pushAll(TreeNode node) {
        while (node != null) {
            stack.push(node);
            node = reverse ? node.right : node.left;
        }
    }

    public int next() {
        TreeNode temp = stack.pop();
        if (!reverse) pushAll(temp.right);
        else pushAll(temp.left);
        return temp.val;
    }

    public boolean hasNext() {
        return !stack.isEmpty();
    }
}

class Solution {
    public boolean findTarget(TreeNode root, int k) {
        if (root == null) return false;

        BSTIterator l = new BSTIterator(root, false);  // Forward iterator
        BSTIterator r = new BSTIterator(root, true);   // Reverse iterator

        int i = l.next();  // Smallest value
        int j = r.next();  // Largest value

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**
  - `O(n)` in the worst case (all nodes visited).
  - `O(h)` per iterator initialization (tree height).
- **Space Complexity:**
  - `O(h)` for the stack in both iterators.

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

### CPP Iterative Solution

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  void fillVector(TreeNode *root, vector<int> *nums)
  {
    if (root->left)
    {
      fillVector(root->left, nums);
    }
    nums->push_back(root->val);
    if (root->right)
    {
      fillVector(root->right, nums);
    }
  }
  bool findTarget(TreeNode *root, int k)
  {
    vector<int> nums;
    fillVector(root, &nums);
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
      if ((nums[i] + nums[j]) < k)
      {
        i++;
      }
      else if ((nums[i] + nums[j]) > k)
      {
        j--;
      }
      else
      {
        return true;
      }
    }
    return false;
  }
};
```
