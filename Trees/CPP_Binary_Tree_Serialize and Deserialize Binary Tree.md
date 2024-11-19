# Serialize and Deserialize Binary Tree

## Table of Contents

- [Serialize and Deserialize Binary Tree](#serialize-and-deserialize-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Serialization](#serialization)
    - [Deserialization](#deserialization)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Recursive Preorder](#recursive-preorder)
    - [Java Preorder Approach](#java-preorder-approach)

## Introduction

Serialization involves converting a data structure, like a binary tree, into a format (e.g., a string) for storage or transmission. Deserialization is the reverse process, reconstructing the original structure from the serialized data.

## Problem Description

Design an algorithm to **serialize** and **deserialize** a binary tree. The solution must ensure that a tree can be serialized to a string and deserialized back to its original structure.

### Examples

#### Example 1

**Input:**  
`root = [1,2,3,null,null,4,5]`  
**Output:**  
`[1,2,3,null,null,4,5]`

#### Example 2

**Input:**  
`root = []`  
**Output:**  
`[]`

### Constraints

- The number of nodes in the tree is in the range \([0, 10^4]\).
- \(-1000 \leq \text{Node.val} \leq 1000\).

## Approach

### Serialization

- Use **level-order traversal** (BFS) to encode the tree.
- Store `null` for missing nodes to preserve the tree structure.

### Deserialization

- Use a queue to rebuild the tree by processing the serialized string.

## Detailed Explanation of Code

### C++ Implementation

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "";

        string result = "";
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            if (current == nullptr) {
                result += "null,";
            } else {
                result += to_string(current->val) + ",";
                q.push(current->left);
                q.push(current->right);
            }
        }

        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        stringstream ss(data);
        string str;
        getline(ss, str, ',');

        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();

            getline(ss, str, ',');
            if (str != "null") {
                current->left = new TreeNode(stoi(str));
                q.push(current->left);
            }

            getline(ss, str, ',');
            if (str != "null") {
                current->right = new TreeNode(stoi(str));
                q.push(current->right);
            }
        }

        return root;
    }
};
```

### Java Implementation

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

import java.util.*;

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if (root == null) return "";

        StringBuilder sb = new StringBuilder();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            if (current == null) {
                sb.append("null,");
            } else {
                sb.append(current.val).append(",");
                queue.offer(current.left);
                queue.offer(current.right);
            }
        }

        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if (data.isEmpty()) return null;

        String[] values = data.split(",");
        TreeNode root = new TreeNode(Integer.parseInt(values[0]));
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);

        int i = 1;
        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();

            if (!values[i].equals("null")) {
                current.left = new TreeNode(Integer.parseInt(values[i]));
                queue.offer(current.left);
            }
            i++;

            if (!values[i].equals("null")) {
                current.right = new TreeNode(Integer.parseInt(values[i]));
                queue.offer(current.right);
            }
            i++;
        }

        return root;
    }
}
```

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\) for both serialization and deserialization, where \(n\) is the number of nodes.
- **Space Complexity:**  
  \(O(n)\), due to the storage requirements for the queue and the resulting string.

## How to Run the Code

### For C++

1. Save the implementation in a file, e.g., `Codec.cpp`.
2. Use a C++ compiler like `g++`:

   ```bash
   g++ -o Codec Codec.cpp
   ```

3. Run the compiled program:

   ```bash
   ./Codec
   ```

### For Java

1. Save the implementation in a file, e.g., `Codec.java`.
2. Compile the file using:

   ```bash
   javac Codec.java
   ```

3. Run the code using:

   ```bash
   java Codec
   ```

## Other Solutions

### Recursive Preorder

```cpp
class Codec
{
public:
  string serialize(TreeNode *root)
  {
    ostringstream out;
    serialize(root, out);
    return out.str();
  }

  TreeNode *deserialize(string data)
  {
    istringstream in(data);
    return deserialize(in);
  }

private:
  void serialize(TreeNode *root, ostringstream &out)
  {
    if (root)
    {
      out << root->val << ' ';
      serialize(root->left, out);
      serialize(root->right, out);
    }
    else
    {
      out << "# ";
    }
  }

  TreeNode *deserialize(istringstream &in)
  {
    string val;
    in >> val;
    if (val == "#")
      return nullptr;
    TreeNode *root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
  }
};
```

### Java Preorder Approach

```java
public class Codec {
    private static final String spliter = ",";
    private static final String NN = "X";

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        buildString(root, sb);
        return sb.toString();
    }

    private void buildString(TreeNode node, StringBuilder sb) {
        if (node == null) {
            sb.append(NN).append(spliter);
        } else {
            sb.append(node.val).append(spliter);
            buildString(node.left, sb);
            buildString(node.right,sb);
        }
    }
    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Deque<String> nodes = new LinkedList<>();
        nodes.addAll(Arrays.asList(data.split(spliter)));
        return buildTree(nodes);
    }

    private TreeNode buildTree(Deque<String> nodes) {
        String val = nodes.remove();
        if (val.equals(NN)) return null;
        else {
            TreeNode node = new TreeNode(Integer.valueOf(val));
            node.left = buildTree(nodes);
            node.right = buildTree(nodes);
            return node;
        }
    }
}
```
