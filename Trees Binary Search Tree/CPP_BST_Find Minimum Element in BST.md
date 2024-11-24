# Find Minimum Element in BST

## Table of Contents

- [Find Minimum Element in BST](#find-minimum-element-in-bst)
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

The task is to find the **minimum valued element** in a given Binary Search Tree (BST).  
In a BST, the minimum value node is located at the **leftmost node** of the tree.

---

## Problem Description

### Examples

**Example 1:**  
**Input:**  
`root = [5, 4, 6, 3, N, N, 7, 1]`  
**Output:**  
`1`  
**Explanation:** The minimum value in the tree is `1`.

---

**Example 2:**  
**Input:**  
`root = [10, 5, 20, 2]`  
**Output:**  
`2`  
**Explanation:** The leftmost node contains the minimum value `2`.

---

**Example 3:**  
**Input:**  

```plaintext
root = [10, N, 10, N, 11]
          10  
            \
             10  
               \
                11
```  

**Output:**  
`10`  
**Explanation:** The root node itself is the minimum value.

---

### Constraints

- \(0 \leq \text{number of nodes} \leq 10^5\)
- \(0 \leq \text{node->data} \leq 10^5\)

---

## Approach

- If the root is `null`, return `-1` (indicating the tree is empty).
- Start at the root and traverse to the **leftmost node** since the minimum value in a BST resides there.
- Once the leftmost node is reached, return its value.

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
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to find the minimum element in the given BST.
class Solution {
public:
    int minValue(Node* root) {
        if (root == nullptr) return -1; // Tree is empty

        Node* temp = root;
        while (temp->left != nullptr) {
            temp = temp->left; // Move to the leftmost node
        }
        return temp->data; // Return the leftmost node's value
    }
};

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s); // Build tree from input
        Solution ob;
        cout << ob.minValue(root) << endl;
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
    public int minValue(Node root) {
        if (root == null) return -1; // Tree is empty

        Node temp = root;
        while (temp.left != null) {
            temp = temp.left; // Move to the leftmost node
        }
        return temp.data; // Return the leftmost node's value
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String s = sc.next();
            Node root = buildTree(s); // Build tree from input
            Solution sol = new Solution();
            System.out.println(sol.minValue(root));
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

- **Time Complexity:**  
  \(O(h)\), where \(h\) is the height of the tree. In the worst case, \(h = O(n)\) for a skewed tree.

- **Space Complexity:**  
  \(O(1)\), as no additional space is used.

---

## How to Run the Code

### For C++

1. Save the code in a file, e.g., `FindMinBST.cpp`.
2. Compile the file:

   ```bash
   g++ -o FindMinBST FindMinBST.cpp
   ```

3. Run the executable:

   ```bash
   ./FindMinBST
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
