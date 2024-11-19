# Time To Burn Tree

## Table of Contents

- [Time To Burn Tree](#time-to-burn-tree)
  - [Table of Contents](#table-of-contents)
  - [Problem Statement](#problem-statement)
  - [Constraints](#constraints)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Approach](#approach)
  - [Complexity Analysis](#complexity-analysis)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)

---

## Problem Statement

You are given a binary tree with `N` unique nodes, and a `Start` node from which the fire starts to spread. Each minute, the fire spreads from a burning node to its adjacent nodes (parent or children), and it takes exactly 1 minute to burn each adjacent node. The objective is to calculate the total time in minutes required to burn the entire tree, starting from the specified `Start` node.

## Constraints

- `1 <= N <= 10^5`
- `1 <= Value of Tree Node <= 10^9`
- `1 <= Value of Start Node <= 10^9`
- Time Limit: 1 second

## Examples

### Example 1

**Input:**

```plaintext
Tree: [1, 2, 3, 4, -1, -1, 5, -1, -1, -1, -1]  
Start Node: 3
```

**Output:**

```plaintext
2
```

**Explanation:**

- **Minute 0:** Node 3 starts burning.
- **Minute 1:** Nodes 1, 4, and 5 adjacent to 3 burn completely.
- **Minute 2:** Node 2, the remaining node, burns.

Thus, the entire tree burns in **2 minutes**.

### Example 2

**Input:**

```plaintext
Tree: [3, 1, 2, 5, 6, -1, -1, -1, -1, -1, -1]  
Start Node: 3
```

**Output:**

```plaintext
2
```

---

## Approach

1. **Mapping Parent Nodes:**
   Use a BFS traversal to create a mapping of each node to its parent. This will help identify all nodes adjacent to any given node (i.e., left child, right child, and parent).

2. **Burning the Tree:**
   - Start a BFS from the `Start` node.
   - Use a queue to keep track of burning nodes and a `visited` map to avoid reprocessing nodes.
   - Each level of BFS represents one minute of burn time.
   - For each node, burn its left child, right child, and parent if they haven't burned yet.

3. **Time Calculation:**
   The BFS level depth gives the total time taken to burn the entire tree.

---

## Complexity Analysis

- **Time Complexity:** `O(N)`, as each node and its connections (edges) are processed once.
- **Space Complexity:** `O(N)`, due to the queue, the parent mapping, and the `visited` map.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

// Definition for Binary Tree Node
class BinaryTreeNode {
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Function to map each node to its parent and locate the start node
BinaryTreeNode* BFSMapNodesToParents(BinaryTreeNode *root, unordered_map<BinaryTreeNode*, BinaryTreeNode*> &parentMap, int start) {
    queue<BinaryTreeNode*> q;
    q.push(root);
    BinaryTreeNode* startNode = nullptr;

    while (!q.empty()) {
        BinaryTreeNode *node = q.front(); q.pop();

        // Find the start node
        if (node->data == start) startNode = node;

        // Map the children to their parent node
        if (node->left) {
            parentMap[node->left] = node;
            q.push(node->left);
        }
        if (node->right) {
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }
    return startNode;
}

// Function to find the total burn time from the start node
int findBurnTime(unordered_map<BinaryTreeNode*, BinaryTreeNode*> &parentMap, BinaryTreeNode* startNode) {
    queue<BinaryTreeNode*> q;
    q.push(startNode);
    unordered_map<BinaryTreeNode*, bool> visited;
    visited[startNode] = true;
    int minutes = 0;

    while (!q.empty()) {
        int size = q.size();
        bool burnProgress = false;

        for (int i = 0; i < size; ++i) {
            BinaryTreeNode *node = q.front(); q.pop();

            // Burn left child
            if (node->left && !visited[node->left]) {
                burnProgress = true;
                visited[node->left] = true;
                q.push(node->left);
            }
            // Burn right child
            if (node->right && !visited[node->right]) {
                burnProgress = true;
                visited[node->right] = true;
                q.push(node->right);
            }
            // Burn parent node
            if (parentMap[node] && !visited[parentMap[node]]) {
                burnProgress = true;
                visited[parentMap[node]] = true;
                q.push(parentMap[node]);
            }
        }
        if (burnProgress) ++minutes;
    }
    return minutes;
}

// Wrapper function to calculate time to burn the entire tree
int timeToBurnTree(BinaryTreeNode* root, int start) {
    unordered_map<BinaryTreeNode*, BinaryTreeNode*> parentMap;
    BinaryTreeNode* startNode = BFSMapNodesToParents(root, parentMap, start);
    return findBurnTime(parentMap, startNode);
}
```

---

## Java Implementation

```java
import java.util.*;

class BinaryTreeNode {
    int data;
    BinaryTreeNode left, right;
    BinaryTreeNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}

public class Solution {

    // Helper function to map each node to its parent and locate the start node
    private BinaryTreeNode mapParents(BinaryTreeNode root, Map<BinaryTreeNode, BinaryTreeNode> parentMap, int start) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        queue.add(root);
        BinaryTreeNode startNode = null;

        while (!queue.isEmpty()) {
            BinaryTreeNode node = queue.poll();

            if (node.data == start) startNode = node;

            if (node.left != null) {
                parentMap.put(node.left, node);
                queue.add(node.left);
            }
            if (node.right != null) {
                parentMap.put(node.right, node);
                queue.add(node.right);
            }
        }
        return startNode;
    }

    // Function to find the total burn time from the start node
    private int calculateBurnTime(Map<BinaryTreeNode, BinaryTreeNode> parentMap, BinaryTreeNode startNode) {
        Queue<BinaryTreeNode> queue = new LinkedList<>();
        queue.add(startNode);
        Set<BinaryTreeNode> visited = new HashSet<>();
        visited.add(startNode);
        int minutes = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            boolean burnProgress = false;

            for (int i = 0; i < size; i++) {
                BinaryTreeNode node = queue.poll();

                if (node.left != null && !visited.contains(node.left)) {
                    burnProgress = true;
                    visited.add(node.left);
                    queue.add(node.left);
                }
                if (node.right != null && !visited.contains(node.right)) {
                    burnProgress = true;
                    visited.add(node.right);
                    queue.add(node.right);
                }
                if (parentMap.containsKey(node) && !visited.contains(parentMap.get(node))) {
                    burnProgress = true;
                    visited.add(parentMap.get(node));
                    queue.add(parentMap.get(node));
                }
            }
            if (burnProgress) minutes++;
        }
        return minutes;
    }

    // Wrapper function to calculate time to burn the entire tree
    public int timeToBurnTree(BinaryTreeNode root, int start) {
        Map<BinaryTreeNode, BinaryTreeNode> parentMap = new HashMap<>();
        BinaryTreeNode startNode = mapParents(root, parentMap, start);
        return calculateBurnTime(parentMap, startNode);
    }
}
```
