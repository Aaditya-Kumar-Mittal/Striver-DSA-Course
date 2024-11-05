# Binary Tree Traversals

## Table of Contents

- [Binary Tree Traversals](#binary-tree-traversals)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Example](#example)
  - [Approach](#approach)
    - [Algorithm](#algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

This implementation performs pre-order, in-order, and post-order traversals of a binary tree iteratively using a stack. It returns a 2D vector (or array) containing the values of the nodes in the order they are visited for each type of traversal.

## Problem Description

Given a binary tree, return the values of the nodes in pre-order, in-order, and post-order traversal in a 2D vector (or array) format.

### Example

For the binary tree:

```plaintext
      1
     / \
    2   3
   / \
  4   5
```

The traversal results will be:

- **In-order**: `[4, 2, 5, 1, 3]`
- **Pre-order**: `[1, 2, 4, 5, 3]`
- **Post-order**: `[4, 5, 2, 3, 1]`

The output should be a 2D vector (or array):

```plaintext
[
  [4, 2, 5, 1, 3],  // In-order
  [1, 2, 4, 5, 3],  // Pre-order
  [4, 5, 2, 3, 1]   // Post-order
]
```

## Approach

This approach utilizes a stack to keep track of the nodes while traversing the binary tree. Each node is processed according to the traversal order:

1. **Pre-order**: Visit the root first, then the left subtree, followed by the right subtree.
2. **In-order**: Visit the left subtree first, then the root, followed by the right subtree.
3. **Post-order**: Visit the left subtree first, then the right subtree, and finally the root.

By using a stack to store nodes along with a state variable, we can manage the traversal iteratively without recursion.

### Algorithm

1. Initialize an empty stack and vectors (or lists) for pre-order, in-order, and post-order results.
2. If the root is null, return an empty vector (or array).
3. Push the root node and its state (1 for pre-order) onto the stack.
4. While the stack is not empty:
   - Pop the top element.
   - Depending on the state:
     - For state 1 (pre-order):
       - Process the node (add to pre-order list).
       - Push the node back onto the stack, incrementing its state to 2.
       - Push the left child (if it exists) with state 1.
     - For state 2 (in-order):
       - Process the node (add to in-order list).
       - Push the node back onto the stack, incrementing its state to 3.
       - Push the right child (if it exists) with state 1.
     - For state 3 (post-order):
       - Process the node (add to post-order list).
5. Store the traversal results in a 2D vector (or array) and return it.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <stack>
#include <vector>

using namespace std;

// Definition for a binary tree node.
class TreeNode {
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

vector<vector<int>> getTreeTraversal(TreeNode *root) {
    stack<pair<TreeNode *, int>> st;
    vector<int> preorder, inorder, postorder;
    vector<vector<int>> ans;

    if (!root)
        return {};

    st.push({root, 1}); // Start with the root node in pre-order

    while (!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) { // Pre-order
            preorder.push_back(it.first->data);
            it.second++; // Increment state to in-order
            st.push(it); // Push the node back with updated state
            if (it.first->left) {
                st.push({it.first->left, 1}); // Push left child
            }
        } else if (it.second == 2) { // In-order
            inorder.push_back(it.first->data);
            it.second++; // Increment state to post-order
            st.push(it); // Push the node back with updated state
            if (it.first->right) {
                st.push({it.first->right, 1}); // Push right child
            }
        } else { // Post-order
            postorder.push_back(it.first->data);
        }
    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}
```

### Java Implementation

```java
import java.util.*;

class TreeNode {
    int data;
    TreeNode left, right;

    TreeNode() {
        data = 0;
        left = null;
        right = null;
    }

    TreeNode(int x) {
        data = x;
        left = null;
        right = null;
    }

    TreeNode(int x, TreeNode left, TreeNode right) {
        this.data = x;
        this.left = left;
        this.right = right;
    }
}

public class Solution {
    public List<List<Integer>> getTreeTraversal(TreeNode root) {
        Stack<Pair<TreeNode, Integer>> st = new Stack<>();
        List<Integer> preorder = new ArrayList<>();
        List<Integer> inorder = new ArrayList<>();
        List<Integer> postorder = new ArrayList<>();
        List<List<Integer>> ans = new ArrayList<>();

        if (root == null)
            return ans;

        st.push(new Pair<>(root, 1)); // Start with the root node in pre-order

        while (!st.isEmpty()) {
            Pair<TreeNode, Integer> it = st.pop();

            if (it.getValue() == 1) { // Pre-order
                preorder.add(it.getKey().data);
                it = new Pair<>(it.getKey(), 2); // Increment state to in-order
                st.push(it); // Push the node back with updated state
                if (it.getKey().left != null) {
                    st.push(new Pair<>(it.getKey().left, 1)); // Push left child
                }
            } else if (it.getValue() == 2) { // In-order
                inorder.add(it.getKey().data);
                it = new Pair<>(it.getKey(), 3); // Increment state to post-order
                st.push(it); // Push the node back with updated state
                if (it.getKey().right != null) {
                    st.push(new Pair<>(it.getKey().right, 1)); // Push right child
                }
            } else { // Post-order
                postorder.add(it.getKey().data);
            }
        }

        ans.add(inorder);
        ans.add(preorder);
        ans.add(postorder);

        return ans;
    }

    class Pair<K, V> {
        private K key;
        private V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }
    }
}
```

## Complexity Analysis

- **Time Complexity**: \( O(n) \) where \( n \) is the number of nodes in the tree. Each node is processed a constant number of times.
- **Space Complexity**: \( O(h) \) where \( h \) is the height of the tree due to the stack. In the worst case of a skewed tree, this can be \( O(n) \).

## How to Run the Code

### For C++

1. Copy the C++ code into your preferred C++ IDE or text editor.
2. Compile the code using a C++ compiler, e.g., `g++ -o solution solution.cpp`.
3. Run the compiled program with `./solution`.

### For Java

1. Copy the Java code into a file named `Solution.java`.
2. Compile the code using a Java compiler: `javac Solution.java`.
3. Run the compiled program with `java Solution`.

This README provides a comprehensive guide to the binary tree traversal approach using iterative methods with stack-based implementations in both C++ and Java. You can use this for educational purposes or implement it in your projects.
