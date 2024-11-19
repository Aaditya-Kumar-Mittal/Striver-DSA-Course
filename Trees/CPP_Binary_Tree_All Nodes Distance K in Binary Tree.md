<!-- markdownlint-disable MD024 -->

# All Nodes Distance K in Binary Tree

## Table of Contents

- [All Nodes Distance K in Binary Tree](#all-nodes-distance-k-in-binary-tree)
  - [Table of Contents](#table-of-contents)
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
  - [Additional Examples](#additional-examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
    - [Explanation for HashMap Approach](#explanation-for-hashmap-approach)
      - [1. **Find and Store Distances**](#1-find-and-store-distances)
      - [2. **DFS Traversal**](#2-dfs-traversal)
      - [**Time Complexity**](#time-complexity)
      - [**Space Complexity**](#space-complexity)
  - [2. Without HashMap](#2-without-hashmap)
    - [Key Steps](#key-steps-1)
    - [Code Implementation](#code-implementation)
    - [Explanation for No HashMap Approach](#explanation-for-no-hashmap-approach)
      - [1. **Single DFS Traversal**](#1-single-dfs-traversal)
      - [2. **Result Collection**](#2-result-collection)
      - [**Time Complexity**](#time-complexity-1)
      - [**Space Complexity**](#space-complexity-1)

---

## Problem Description

Given the `root` of a binary tree, the value of a target node `target`, and an integer `k`, return an array of the values of all nodes that are at a distance `k` from the target node.

### Input

- A binary tree of unique values.
- A target node value.
- An integer `k` indicating the distance.

### Output

- An array containing node values at distance `k` from the target node.

### Constraints

- The number of nodes in the tree is in the range \([1, 500]\).
- \(0 \leq \text{Node.val} \leq 500\).
- All the values of `Node.val` are unique.
- `target` is guaranteed to exist in the tree.
- \(0 \leq k \leq 1000\).

---

## Approach

### Key Steps

1. **Mark Parents**:
   - Use BFS to map each node to its parent.
2. **Find Nodes at Distance K**:
   - Use another BFS to traverse the tree starting from the `target` node.
   - Track the current level.
   - Once the level matches `k`, collect the nodes in that level.

---

## C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent_track) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if (current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track);

        unordered_map<TreeNode*, bool> isVisited;
        queue<TreeNode*> q;
        q.push(target);
        isVisited[target] = true;
        int current_level = 0;

        while (!q.empty()) {
            int size = q.size();
            if (current_level++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode* current = q.front();
                q.pop();

                if (current->left && !isVisited[current->left]) {
                    q.push(current->left);
                    isVisited[current->left] = true;
                }
                if (current->right && !isVisited[current->right]) {
                    q.push(current->right);
                    isVisited[current->right] = true;
                }
                if (parent_track[current] && !isVisited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    isVisited[parent_track[current]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};
```

---

## Java Implementation

```java
import java.util.*;

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Solution {
    public void markParents(TreeNode root, Map<TreeNode, TreeNode> parent_track) {
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        while (!queue.isEmpty()) {
            TreeNode current = queue.poll();
            if (current.left != null) {
                parent_track.put(current.left, current);
                queue.offer(current.left);
            }
            if (current.right != null) {
                parent_track.put(current.right, current);
                queue.offer(current.right);
            }
        }
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
        Map<TreeNode, TreeNode> parent_track = new HashMap<>();
        markParents(root, parent_track);

        Map<TreeNode, Boolean> isVisited = new HashMap<>();
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(target);
        isVisited.put(target, true);
        int current_level = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            if (current_level++ == k) break;
            for (int i = 0; i < size; i++) {
                TreeNode current = queue.poll();
                if (current.left != null && !isVisited.getOrDefault(current.left, false)) {
                    queue.offer(current.left);
                    isVisited.put(current.left, true);
                }
                if (current.right != null && !isVisited.getOrDefault(current.right, false)) {
                    queue.offer(current.right);
                    isVisited.put(current.right, true);
                }
                if (parent_track.containsKey(current) && !isVisited.getOrDefault(parent_track.get(current), false)) {
                    queue.offer(parent_track.get(current));
                    isVisited.put(parent_track.get(current), true);
                }
            }
        }

        List<Integer> result = new ArrayList<>();
        while (!queue.isEmpty()) {
            result.add(queue.poll().val);
        }
        return result;
    }
}
```

---

## Complexity Analysis

### Explanation

1. **Time Complexity**:  
   \(O(N)\), where \(N\) is the number of nodes. This includes marking parents and BFS traversal.
2. **Space Complexity**:  
   \(O(N)\) for storing parent pointers and BFS queue.

---

## Additional Examples

### Example 1

**Input**:

```bash
root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
```

**Output**:

```bash
[7,4,1]
```

### Example 2

**Input**:

```bash
root = [1], target = 1, k = 3
```

**Output**:

```bash
[]
```

### Explanation for HashMap Approach

```java
class Solution {

    Map<TreeNode, Integer> map = new HashMap<>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new LinkedList<>();
        find(root, target);
        dfs(root, target, K, map.get(root), res);
        return res;
    }

    // find target node first and store the distance in that path that we could use it later directly
    private int find(TreeNode root, TreeNode target) {
        if (root == null) return -1;
        if (root == target) {
            map.put(root, 0);
            return 0;
        }
        int left = find(root.left, target);
        if (left >= 0) {
            map.put(root, left + 1);
            return left + 1;
        }
  int right = find(root.right, target);
  if (right >= 0) {
            map.put(root, right + 1);
            return right + 1;
        }
        return -1;
    }

    private void dfs(TreeNode root, TreeNode target, int K, int length, List<Integer> res) {
        if (root == null) return;
        if (map.containsKey(root)) length = map.get(root);
        if (length == K) res.add(root.val);
        dfs(root.left, target, K, length + 1, res);
        dfs(root.right, target, K, length + 1, res);
    }
}
```

#### 1. **Find and Store Distances**

- The `find` function recursively traverses the tree to locate the target node.
- Once the target is found, it stores the distance from the target to all its ancestor nodes in a `HashMap`.
- This allows direct retrieval of distances from any ancestor node to the target during DFS.

#### 2. **DFS Traversal**

- The `dfs` function performs a depth-first search on the tree.
- At each node:
  - If the node exists in the `HashMap`, the stored distance is used.
  - If the distance equals `K`, the node's value is added to the result.
  - Otherwise, the DFS continues to the left and right children with updated distances.

#### **Time Complexity**

- **O(N)**: Each node is visited once during the `find` and once during the `dfs`.

#### **Space Complexity**

- **O(N)**: Space is required for the `HashMap` and recursive stack.

---

## 2. Without HashMap

### Key Steps

1. **DFS Without Precomputation**:
   - Combines finding distances and accumulating results in a single DFS function.
2. **Conditionally Compute Distance**:
   - Tracks the current depth relative to the target node.
   - Handles nodes based on whether the target node has already been found.

### Code Implementation

```java
import java.util.*;

class Solution {
    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        List<Integer> res = new LinkedList<>();
        if (K == 0) {
            res.add(target.val);
        } else {
            dfs(res, root, target.val, K, 0);
        }
        return res;
    }

    private int dfs(List<Integer> res, TreeNode node, int target, int K, int depth) {
        if (node == null) return 0;

        if (depth == K) {
            res.add(node.val);
            return 0;
        }

        int left, right;

        if (node.val == target || depth > 0) {
            left = dfs(res, node.left, target, K, depth + 1);
            right = dfs(res, node.right, target, K, depth + 1);
        } else {
            left = dfs(res, node.left, target, K, depth);
            right = dfs(res, node.right, target, K, depth);
        }

        if (node.val == target) return 1;

        if (left == K || right == K) {
            res.add(node.val);
            return 0;
        }

        if (left > 0) {
            dfs(res, node.right, target, K, left + 1);
            return left + 1;
        }

        if (right > 0) {
            dfs(res, node.left, target, K, right + 1);
            return right + 1;
        }

        return 0;
    }
}
```

---

### Explanation for No HashMap Approach

#### 1. **Single DFS Traversal**

- This approach avoids the extra space required for storing distances by combining all logic into a single DFS.
- If a node equals the target or is found in the subtree, distances from its ancestors are calculated during traversal.

#### 2. **Result Collection**

- At each node, the DFS checks if the current depth equals `K`.
- If yes, the node's value is added to the result.
- Otherwise, traversal continues while tracking depth.

#### **Time Complexity**

- **O(N)**: Each node is visited only once.

#### **Space Complexity**

- **O(H)**: Where `H` is the height of the tree, due to recursive stack usage.
