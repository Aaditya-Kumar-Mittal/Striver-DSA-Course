# Maximum Width of Binary Tree

## Table of Contents

- [Maximum Width of Binary Tree](#maximum-width-of-binary-tree)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Steps](#key-steps)
  - [C++ Implementation](#c-implementation)
  - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Explanation](#explanation)
  - [Explanation of the Approach](#explanation-of-the-approach)
  - [Other Solutions](#other-solutions)
    - [Java DFS Solution](#java-dfs-solution)
    - [C++ DFS Solution](#c-dfs-solution)

---

## Introduction

The problem requires finding the **maximum width** of a binary tree. The width of a tree is the number of nodes at its widest level, and **null nodes between two nodes** also need to be counted. This can be represented by assigning indexes to each node according to the binary heap property.

## Problem Description

### Input

1. A binary tree \(A\) containing \(N\) nodes.
2. A binary tree where the root node is provided and subsequent nodes are connected with left and right child pointers.

### Output

- The maximum width of the binary tree at any level, including null nodes.

### Constraints

- \(1 \leq N \leq 3000\)
- \(-100 \leq \text{Node Value} \leq 100\)
- Nodes have unique values.

---

## Approach

We use a **breadth-first search (BFS)** to traverse the binary tree level by level. A queue helps us store nodes and their indices, where we count the width at each level, including null nodes. We normalize indices to avoid overflow and ensure we accurately compute the width.

### Key Steps

1. **Indexing**: Every node is assigned an index, starting from 0 for the root. The left child has index \(2 \times \text{index} + 1\), and the right child has index \(2 \times \text{index} + 2\).
2. **Null Nodes**: We also consider the null nodes between the left and right children.
3. **Level Width Calculation**: At each level, compute the difference between the indices of the first and last nodes, adjusting for any null nodes.
4. **BFS Traversal**: Use a queue to traverse each level and process its nodes and indices.

---

## C++ Implementation

```cpp
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;

        long long res = 1;
        queue<pair<TreeNode*, long long>> q;

        q.push({root, 0});  // Initializing with the root node

        while (!q.empty()) {
            long long cnt = q.size();
            long long start = q.front().second;  // The index of the first node at this level
            long long end = q.back().second;    // The index of the last node at this level

            res = max(res, end - start + 1);  // Update the result with the current width

            for (int i = 0; i < cnt; ++i) {
                pair<TreeNode*, long long> p = q.front();
                long long idx = p.second - start;  // Normalize the index to avoid overflow
                q.pop();

                // If left child exists, push to the queue
                if (p.first->left != NULL)
                    q.push({p.first->left, (long long)2 * idx + 1});

                // If right child exists, push to the queue
                if (p.first->right != NULL)
                    q.push({p.first->right, (long long) 2 * idx + 2});
            }
        }

        return res;
    }
};
```

---

## Java Implementation

```java
import java.util.LinkedList;
import java.util.Queue;

class TreeNode {
    int val;
    TreeNode left, right;

    TreeNode(int x) {
        val = x;
        left = right = null;
    }
}

public class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;

        int maxWidth = 0;
        Queue<Pair<TreeNode, Long>> q = new LinkedList<>();
        q.add(new Pair<>(root, 0L));  // Initialize with root and index 0

        while (!q.isEmpty()) {
            int size = q.size();
            long minIndex = q.peek().getValue();  // The minimum index at this level
            long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                Pair<TreeNode, Long> current = q.poll();
                long currentIndex = current.getValue() - minIndex;  // Normalize the index

                if (i == 0) first = currentIndex;  // First node's index
                if (i == size - 1) last = currentIndex;  // Last node's index

                if (current.getKey().left != null) q.add(new Pair<>(current.getKey().left, currentIndex * 2 + 1));
                if (current.getKey().right != null) q.add(new Pair<>(current.getKey().right, currentIndex * 2 + 2));
            }

            maxWidth = Math.max(maxWidth, (int)(last - first + 1));  // Update max width
        }

        return maxWidth;
    }
}
```

---

## Complexity Analysis

- **Time Complexity**: \(O(N)\), where \(N\) is the number of nodes in the tree. Each node is visited exactly once during the BFS traversal.
- **Space Complexity**: \(O(N)\), where \(N\) is the number of nodes. This space is used by the queue to store nodes at each level.

### Explanation

1. **Time Complexity**: Each node is processed once, and the width calculation at each level takes constant time. Therefore, the time complexity is proportional to the number of nodes in the tree.
2. **Space Complexity**: The space complexity is dominated by the queue, which holds the nodes at each level. In the worst case, the queue will hold all the nodes of the tree, so space complexity is \(O(N)\).

---

## Explanation of the Approach

1. **Including Null Nodes**: According to the problem, we must include null nodes when calculating the width. For example, consider the tree:

   ```bash
           5
         /   \
       3     6
       / \   / \
     2   NULL  4
   ```

   - At level 2, the right child of node 3 is `NULL`. This must be counted, so the width of the second level is 3, not 2. This is crucial for correctly calculating the maximum width, as shown in the example with levels 2 and 3.

2. **Indexing Nodes**: Every node in the tree is assigned an index to help calculate the width at each level. The index for each node follows the binary heap formula:

   - Left child index: \(2 \times \text{index} + 1\)
   - Right child index: \(2 \times \text{index} + 2\)

   By tracking the node's index, we can calculate the width by subtracting the index of the first node from the index of the last node in each level.

3. **Preventing Overflow**: As the tree grows exponentially, we may encounter signed integer overflow due to the large index values. To prevent this:

   - We subtract the starting index of the current level from all indices to avoid overflow.
   - We use `long long` (in C++) or `long` (in Java) for indices to handle large values.

4. **Dry Run**: For the tree example above, we would:

   - Begin with the root (index 0).
   - For the second level, calculate the difference between the indices of the first and last nodes, which results in the width.
   - Repeat this process until all levels are processed.

   By following this approach, we can efficiently compute the maximum width of a binary tree, considering null nodes and preventing integer overflow.

## Other Solutions

### Java DFS Solution

```java
public int widthOfBinaryTree(TreeNode root) {
  return dfs(root, 0, 1, new ArrayList < Integer > (), new ArrayList < Integer > ());
}

public int dfs(TreeNode root, int level, int order, List < Integer > start, List < Integer > end) {
  if (root == null) return 0;
  if (start.size() == level) {
    start.add(order);
    end.add(order);
  }
  else end.set(level, order);
  int cur = end.get(level) - start.get(level) + 1;
  int left = dfs(root.left, level + 1, 2 * order, start, end);
  int right = dfs(root.right, level + 1, 2 * order + 1, start, end);
  return Math.max(cur, Math.max(left, right));
}
```

### C++ DFS Solution

```cpp
int widthOfBinaryTree(TreeNode *root)
{
  return dfs(root, 0, 1, vector<pair<int, int>>() = {});
}

int dfs(TreeNode *root, int level, int order, vector<pair<int, int>> &vec)
{
  if (root == NULL)
    return 0;
  if (vec.size() == level)
    vec.push_back({order, order});
  else
    vec[level].second = order;
  return max({vec[level].second - vec[level].first + 1, dfs(root->left, level + 1, 2 * order, vec), dfs(root->right, level + 1, 2 * order + 1, vec)});
}
```
