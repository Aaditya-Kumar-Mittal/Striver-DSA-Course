# Floor in BST

## Table of Contents

- [Floor in BST](#floor-in-bst)
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

The problem is to find the **floor value** of a given integer \( x \) in a Binary Search Tree (BST). The **floor** of \( x \) is defined as the largest value in the BST that is less than or equal to \( x \). If no such value exists, return `-1`.

---

## Problem Description

### Examples

**Example 1:**  
**Input:**

```bash
n = 7
Tree:
      2
       \
        81
       /  \
     42   87
       \      \
       66     90
       /
      45
x = 87
```

**Output:**  
`87`  
**Explanation:** \( x \) is present in the tree, so the floor is \( 87 \).

---

**Example 2:**  
**Input:**

```bash
n = 4
Tree:
      6
       \
        8
       / \
      7   9
x = 11
```

**Output:**  
`9`  
**Explanation:** The largest value smaller than or equal to \( x = 11 \) is \( 9 \).

---

### Constraints

- \(1 \leq \text{Node data} \leq 10^9\)
- \(1 \leq n \leq 10^5\)

---

## Approach

1. **BST Properties:**

   - Values in the left subtree are smaller than the root.
   - Values in the right subtree are greater than the root.

2. **Iterative Search:**

   - Initialize `floor` as `-1`.
   - Traverse the BST:
     - If \( x \) equals the current node's value, return the value.
     - If \( x > \text{current node value} \), update `floor` and move to the right subtree.
     - If \( x < \text{current node value} \), move to the left subtree.

3. **Return Result:**
   - If the traversal completes without finding a valid floor, return `-1`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Structure of the Node
struct Node {
    int data;
    Node* right;
    Node* left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

class Solution {
public:
    int floor(Node* root, int x) {
        int Floor = -1; // Initialize floor as -1

        while (root) {
            if (root->data == x) {
                // If we find the exact value, it is the floor
                return root->data;
            }

            if (x > root->data) {
                // Update floor and move to the right
                Floor = root->data;
                root = root->right;
            } else {
                // Move to the left
                root = root->left;
            }
        }

        return Floor; // Return the final floor value
    }
};

// Function to insert a node in BST
Node* insert(Node* tree, int val) {
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node* root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int x;
        cin >> x;

        Solution obj;
        cout << obj.floor(root, x) << "\n";
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

    Node(int x) {
        data = x;
        left = right = null;
    }
}

class Solution {
    public int floor(Node root, int x) {
        int Floor = -1; // Initialize floor as -1

        while (root != null) {
            if (root.data == x) {
                // If we find the exact value, it is the floor
                return root.data;
            }

            if (x > root.data) {
                // Update floor and move to the right
                Floor = root.data;
                root = root.right;
            } else {
                // Move to the left
                root = root.left;
            }
        }

        return Floor; // Return the final floor value
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        while (T-- > 0) {
            int n = sc.nextInt();
            Node root = null;
            Solution sol = new Solution();

            for (int i = 0; i < n; i++) {
                int val = sc.nextInt();
                root = insert(root, val);
            }

            int x = sc.nextInt();
            System.out.println(sol.floor(root, x));
        }
        sc.close();
    }

    private static Node insert(Node root, int x) {
        if (root == null) return new Node(x);

        if (x < root.data) root.left = insert(root.left, x);
        else root.right = insert(root.right, x);

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

1. Save the code in a file, e.g., `FloorInBST.cpp`.
2. Compile the file:

   ```bash
   g++ -o FloorInBST FloorInBST.cpp
   ```

3. Run the executable:

   ```bash
   ./FloorInBST
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
