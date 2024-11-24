# Max and Min Element in Binary Tree

## Table of Contents

- [Max and Min Element in Binary Tree](#max-and-min-element-in-binary-tree)
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

---

## Introduction

The task is to find both the **maximum** and **minimum** elements in a given Binary Tree. Unlike Binary Search Trees (BSTs), Binary Trees do not follow any specific structure, so every node in the tree must be traversed to determine the maximum and minimum values.

---

## Problem Description

### Examples

**Example 1:**  
**Input:**

```bash
Tree:
    11
```

**Output:**  
`11 11`  
**Explanation:** The maximum and minimum element is `11`.

---

**Example 2:**  
**Input:**

```bash
Tree:
      6
     / \
    5   8
   /
  2
```

**Output:**  
`8 2`  
**Explanation:** The maximum value in the tree is `8`, and the minimum value is `2`.

---

### Constraints

- \(1 \leq \text{number of nodes} \leq 10^5\)
- \(1 \leq \text{node->data} \leq 10^5\)

---

## Approach

1. **Traversal Method**:  
   Perform a recursive or iterative traversal (DFS or BFS) of the tree.

2. **Track Min and Max**:  
   Maintain two variables to store the **maximum** and **minimum** values. Update these variables as you visit each node.

3. **Return Result**:  
   After traversing the entire tree, return the stored minimum and maximum values.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to find maximum and minimum elements in a Binary Tree.
class Solution {
public:
    int findMax(Node* root) {
        if (root == nullptr) return INT_MIN; // Base case for empty tree

        int maxLeft = findMax(root->left);  // Max in left subtree
        int maxRight = findMax(root->right); // Max in right subtree

        return max(root->data, max(maxLeft, maxRight)); // Return the max
    }

    int findMin(Node* root) {
        if (root == nullptr) return INT_MAX; // Base case for empty tree

        int minLeft = findMin(root->left);  // Min in left subtree
        int minRight = findMin(root->right); // Min in right subtree

        return min(root->data, min(minLeft, minRight)); // Return the min
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline after test cases input
    while (t--) {
        string treeString;
        getline(cin, treeString);
        Node* root = buildTree(treeString); // Build tree from input
        Solution obj;
        int mx = obj.findMax(root);
        int mn = obj.findMin(root);
        cout << mx << " " << mn << "\n";
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Node {
    int data;
    Node left, right;

    Node(int value) {
        data = value;
        left = right = null;
    }
}

class Solution {
    public int findMax(Node root) {
        if (root == null) return Integer.MIN_VALUE; // Base case for empty tree

        int maxLeft = findMax(root.left);  // Max in left subtree
        int maxRight = findMax(root.right); // Max in right subtree

        return Math.max(root.data, Math.max(maxLeft, maxRight)); // Return the max
    }

    public int findMin(Node root) {
        if (root == null) return Integer.MAX_VALUE; // Base case for empty tree

        int minLeft = findMin(root.left);  // Min in left subtree
        int minRight = findMin(root.right); // Min in right subtree

        return Math.min(root.data, Math.min(minLeft, minRight)); // Return the min
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // Consume the newline
        while (t-- > 0) {
            String treeString = sc.nextLine();
            Node root = buildTree(treeString); // Build tree from input
            Solution sol = new Solution();
            int mx = sol.findMax(root);
            int mn = sol.findMin(root);
            System.out.println(mx + " " + mn);
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**  
  \(O(n)\), where \(n\) is the number of nodes. Every node is visited once.

- **Space Complexity:**
  - **Recursive Approach:** \(O(h)\), where \(h\) is the height of the tree (stack space).
  - **Iterative Approach:** \(O(n)\) in case of BFS, due to queue storage.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `FindMinMaxBinaryTree.cpp`.
2. Compile the file:

   ```bash
   g++ -o FindMinMaxBinaryTree FindMinMaxBinaryTree.cpp
   ```

3. Run the executable:

   ```bash
   ./FindMinMaxBinaryTree
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
