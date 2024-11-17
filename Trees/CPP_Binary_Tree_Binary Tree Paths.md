# Binary Tree Paths

## Table of Contents

- [Binary Tree Paths](#binary-tree-paths)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Depth-First Search (DFS)](#depth-first-search-dfs)
    - [Steps](#steps)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [Summary](#summary)
  - [Other Solutions](#other-solutions)
    - [CPP Non - Recursive Solution](#cpp-non---recursive-solution)
    - [Java BFS Queue](#java-bfs-queue)
    - [Java DFS Stack](#java-dfs-stack)

---

## Problem Description

Given the root of a binary tree, the task is to find all root-to-leaf paths. A **leaf** is a node with no children. The paths should be represented as strings in the format:

- `"root->child1->child2->...->leaf"`

### Examples

#### Example 1

- **Input**: `root = [1,2,3,null,5]`

  ```bash
      1
     / \
    2   3
     \
      5
  ```

- **Output**: `["1->2->5", "1->3"]`

#### Example 2

- **Input**: `root = [1]`

  ```bash
      1
  ```

- **Output**: `["1"]`

### Constraints

- The number of nodes is in the range `[1, 100]`.
- Node values range from `-100` to `100`.

---

## Approach

### Depth-First Search (DFS)

The problem can be solved using a **Depth-First Search (DFS)** traversal of the binary tree.

### Steps

1. **Recursive Traversal**:

   - Start from the root node.
   - Maintain a string to keep track of the current path.
   - At each node, append its value to the current path.
   - If a **leaf node** is reached (both left and right children are `null`), add the current path to the result list.

2. **Recursive Calls**:

   - Recursively visit the left and right subtrees, passing the updated path.

3. **Edge Case**:
   - If the root is `null`, return an empty result list.

---

## C++ Implementation

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

class Solution {
private:
    void dfs(TreeNode* root, string path, vector<string>& res) {
        // Base case: if we reach a leaf node
        if (!root->left && !root->right) {
            res.push_back(path);
            return;
        }
        // Recurse on the left child if it exists
        if (root->left)
            dfs(root->left, path + "->" + to_string(root->left->val), res);
        // Recurse on the right child if it exists
        if (root->right)
            dfs(root->right, path + "->" + to_string(root->right->val), res);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result; // Edge case: empty tree
        dfs(root, to_string(root->val), result);
        return result;
    }
};
```

---

## Java Implementation

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */

class Solution {
    private void dfs(TreeNode root, String path, List<String> res) {
        // Base case: if we reach a leaf node
        if (root.left == null && root.right == null) {
            res.add(path);
            return;
        }
        // Recurse on the left child if it exists
        if (root.left != null)
            dfs(root.left, path + "->" + root.left.val, res);
        // Recurse on the right child if it exists
        if (root.right != null)
            dfs(root.right, path + "->" + root.right.val, res);
    }

    public List<String> binaryTreePaths(TreeNode root) {
        List<String> result = new ArrayList<>();
        if (root == null) return result; // Edge case: empty tree
        dfs(root, String.valueOf(root.val), result);
        return result;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **O(N)**: Each node in the tree is visited exactly once, where `N` is the number of nodes.

### Space Complexity

- **O(H)**: The maximum depth of the recursion stack is the height of the tree, where `H` is the height of the tree.
- **O(N)**: For storing the result paths, since there could be up to `N` leaf nodes.

---

## Summary

The solution uses **DFS** to traverse the binary tree and construct paths from the root to each leaf node. Both the **C++** and **Java** implementations follow a similar recursive strategy to build and collect paths efficiently.

## Other Solutions

### CPP Non - Recursive Solution

```cpp
class Solution
{
public:
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> res;
    if (root == NULL)
      return res;
    stack<TreeNode *> s;
    stack<string> pathStack;
    s.push(root);
    pathStack.push(to_string(root->val));

    while (!s.empty())
    {
      TreeNode *curNode = s.top();
      s.pop();
      string tmpPath = pathStack.top();
      pathStack.pop();

      if (curNode->left == NULL && curNode->right == NULL)
      {
        res.push_back(tmpPath);
        continue;
      }

      if (curNode->left != NULL)
      {
        s.push(curNode->left);
        pathStack.push(tmpPath + "->" + to_string(curNode->left->val));
      }

      if (curNode->right != NULL)
      {
        s.push(curNode->right);
        pathStack.push(tmpPath + "->" + to_string(curNode->right->val));
      }
    }

    return res;
  }
};
```

### Java BFS Queue

```java
public class Solution {
  //BFS - Queue
  public List < String > binaryTreePaths(TreeNode root) {
    List < String > list = new ArrayList < String > ();
    Queue < TreeNode > qNode = new LinkedList < TreeNode > ();
    Queue < String > qStr = new LinkedList < String > ();

    if (root == null) return list;
    qNode.add(root);
    qStr.add("");
    while (!qNode.isEmpty()) {
      TreeNode curNode = qNode.remove();
      String curStr = qStr.remove();

      if (curNode.left == null && curNode.right == null) list.add(curStr + curNode.val);
      if (curNode.left != null) {
        qNode.add(curNode.left);
        qStr.add(curStr + curNode.val + "->");
      }
      if (curNode.right != null) {
        qNode.add(curNode.right);
        qStr.add(curStr + curNode.val + "->");
      }
    }
    return list;
  }
```

### Java DFS Stack

```java
public class Solution {
  //DFS - Stack
  public List < String > binaryTreePaths(TreeNode root) {
    List < String > list = new ArrayList < String > ();
    Stack < TreeNode > sNode = new Stack < TreeNode > ();
    Stack < String > sStr = new Stack < String > ();

    if (root == null) return list;
    sNode.push(root);
    sStr.push("");
    while (!sNode.isEmpty()) {
      TreeNode curNode = sNode.pop();
      String curStr = sStr.pop();

      if (curNode.left == null && curNode.right == null) list.add(curStr + curNode.val);
      if (curNode.left != null) {
        sNode.push(curNode.left);
        sStr.push(curStr + curNode.val + "->");
      }
      if (curNode.right != null) {
        sNode.push(curNode.right);
        sStr.push(curStr + curNode.val + "->");
      }
    }
    return list;
  }
```
