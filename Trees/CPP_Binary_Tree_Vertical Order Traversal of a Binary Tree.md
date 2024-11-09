# Vertical Order Traversal of Binary Tree

## Problem Description

Given the root of a binary tree, calculate the **vertical order traversal** of the binary tree. Each node at position `(row, col)` will have its:

- Left child at `(row + 1, col - 1)`
- Right child at `(row + 1, col + 1)`

Return a list of node values ordered by column indices (leftmost to rightmost). Nodes in the same row and column should be sorted by their values.

### Examples

1. **Input:** `root = [3,9,20,null,null,15,7]`

   - **Output:** `[[9],[3,15],[20],[7]]`

2. **Input:** `root = [1,2,3,4,5,6,7]`

   - **Output:** `[[4],[2],[1,5,6],[3],[7]]`

3. **Input:** `root = [1,2,3,4,6,5,7]`
   - **Output:** `[[4],[2],[1,5,6],[3],[7]]`

### Constraints

- The number of nodes is in the range `[1, 1000]`.
- Node values range between `0` and `1000`.

## Approach

### BFS Solution (Using a Queue)

1. Use a queue to store nodes along with their row and column indices.
2. For each node:
   - Update the `map<int, map<int, multiset<int>>>` data structure to store nodes by column and row.
   - Insert node values into a multiset for automatic sorting in case of ties in the same row and column.
3. Traverse the map and collect the results in vertical order.

### DFS Solution (Using Recursion)

1. Traverse the tree recursively, maintaining row and column indices.
2. For each node:
   - Update the `map<int, map<int, set<int>>>` structure similarly to the BFS approach.
3. After the recursion completes, traverse the map to collect the results.

---

## C++ Implementations

### BFS Solution in C++

```cpp
#include <vector>
#include <map>
#include <set>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        // Data structure to store nodes in the format map[col][row] -> multiset of values
        std::map<int, std::map<int, std::multiset<int>>> nodes;
        std::queue<std::pair<TreeNode*, std::pair<int, int>>> todo;

        todo.push({root, {0, 0}});

        while (!todo.empty()) {
            auto p = todo.front();
            todo.pop();
            TreeNode* node = p.first;
            int col = p.second.first, row = p.second.second;

            nodes[col][row].insert(node->val);

            if (node->left) todo.push({node->left, {col - 1, row + 1}});
            if (node->right) todo.push({node->right, {col + 1, row + 1}});
        }

        std::vector<std::vector<int>> result;
        for (auto colPair : nodes) {
            std::vector<int> col;
            for (auto rowPair : colPair.second) {
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            result.push_back(col);
        }

        return result;
    }
};
```

### DFS Solution in C++

```cpp
#include <vector>
#include <map>
#include <set>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
        std::map<int, std::map<int, std::set<int>>> nodes;
        traverse(root, 0, 0, nodes);

        std::vector<std::vector<int>> result;
        for (auto colPair : nodes) {
            std::vector<int> col;
            for (auto rowPair : colPair.second) {
                col.insert(col.end(), rowPair.second.begin(), rowPair.second.end());
            }
            result.push_back(col);
        }

        return result;
    }

private:
    void traverse(TreeNode* root, int col, int row, std::map<int, std::map<int, std::set<int>>>& nodes) {
        if (!root) return;
        nodes[col][row].insert(root->val);
        traverse(root->left, col - 1, row + 1, nodes);
        traverse(root->right, col + 1, row + 1, nodes);
    }
};
```

---

## Java Implementations

### BFS Solution in Java

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        Map<Integer, Map<Integer, PriorityQueue<Integer>>> nodes = new TreeMap<>();
        Queue<Pair<TreeNode, Pair<Integer, Integer>>> todo = new LinkedList<>();

        todo.offer(new Pair<>(root, new Pair<>(0, 0)));

        while (!todo.isEmpty()) {
            Pair<TreeNode, Pair<Integer, Integer>> p = todo.poll();
            TreeNode node = p.getKey();
            int col = p.getValue().getKey(), row = p.getValue().getValue();

            nodes.computeIfAbsent(col, k -> new TreeMap<>())
                .computeIfAbsent(row, k -> new PriorityQueue<>())
                .offer(node.val);

            if (node.left != null) todo.offer(new Pair<>(node.left, new Pair<>(col - 1, row + 1)));
            if (node.right != null) todo.offer(new Pair<>(node.right, new Pair<>(col + 1, row + 1)));
        }

        List<List<Integer>> result = new ArrayList<>();
        for (Map<Integer, PriorityQueue<Integer>> colMap : nodes.values()) {
            List<Integer> col = new ArrayList<>();
            for (PriorityQueue<Integer> nodesAtPosition : colMap.values()) {
                while (!nodesAtPosition.isEmpty()) {
                    col.add(nodesAtPosition.poll());
                }
            }
            result.add(col);
        }

        return result;
    }
}
```

### DFS Solution in Java

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class Solution {
    private Map<Integer, Map<Integer, PriorityQueue<Integer>>> nodes = new TreeMap<>();

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        traverse(root, 0, 0);

        List<List<Integer>> result = new ArrayList<>();
        for (Map<Integer, PriorityQueue<Integer>> colMap : nodes.values()) {
            List<Integer> col = new ArrayList<>();
            for (PriorityQueue<Integer> nodesAtPosition : colMap.values()) {
                while (!nodesAtPosition.isEmpty()) {
                    col.add(nodesAtPosition.poll());
                }
            }
            result.add(col);
        }

        return result;
    }

    private void traverse(TreeNode node, int col, int row) {
        if (node == null) return;

        nodes.computeIfAbsent(col, k -> new TreeMap<>())
             .computeIfAbsent(row, k -> new PriorityQueue<>())
             .offer(node.val);

        traverse(node.left, col - 1, row + 1);
        traverse(node.right, col + 1, row + 1);
    }
}
```

---

### Complexity Analysis

- **Time Complexity**: \(O(n \log n)\) where \(n\) is the number of nodes, mainly due to sorting based on the row and column values.
- **Space Complexity**: \(O(n)\) for storing the node values and coordinates in the data structure.

These implementations offer efficient and structured solutions for vertical traversal with both BFS and DFS approaches, ensuring proper ordering of nodes in each column.

## Other Approaches

### Java TreeMap Solution - 1

```java
class Solution {
    public List < List < Integer >> verticalTraversal(TreeNode root) {
        TreeMap < Integer, TreeMap < Integer, PriorityQueue < Integer >>> map = new TreeMap < > ();
        dfs(root, 0, 0, map);
        List < List < Integer >> list = new ArrayList < > ();
        for (TreeMap < Integer, PriorityQueue < Integer >> ys: map.values()) {
            list.add(new ArrayList < > ());
            for (PriorityQueue < Integer > nodes: ys.values()) {
                while (!nodes.isEmpty()) {
                    list.get(list.size() - 1).add(nodes.poll());
                }
            }
        }
        return list;
    }
    private void dfs(TreeNode root, int x, int y, TreeMap < Integer, TreeMap < Integer, PriorityQueue < Integer >>> map) {
        if (root == null) {
            return;
        }
        if (!map.containsKey(x)) {
            map.put(x, new TreeMap < > ());
        }
        if (!map.get(x).containsKey(y)) {
            map.get(x).put(y, new PriorityQueue < > ());
        }
        map.get(x).get(y).offer(root.val);
        dfs(root.left, x - 1, y + 1, map);
        dfs(root.right, x + 1, y + 1, map);
    }
}
```

---

### Java Solution using Only PriorityQueue

```java
class Point {
    int x, y, val;
    Point(int x, int y, int val) {
        this.x = x;
        this.y = y;
        this.val = val;
    }
}
public class Solution {
    public List < List < Integer >> verticalTraversal(TreeNode root) {
        List < List < Integer >> res = new ArrayList < List < Integer >> ();

        PriorityQueue < Point > pq = new PriorityQueue < Point > (1005, new Comparator < Point > () {
            public int compare(Point p1, Point p2) {
                if (p1.x < p2.x) return -1;
                if (p2.x < p1.x) return 1;
                if (p1.y > p2.y) return -1;
                if (p1.y < p2.y) return 1;
                return p1.val - p2.val;
            }
        });

        verticalTraversalHelper(root, 0, 0, pq);
        Point prev = null;
        List < Integer > l = new ArrayList < > ();
        while (!pq.isEmpty()) {
            Point p = pq.poll();
            if (prev == null || p.x != prev.x) {
                if (prev != null) res.add(l);
                l = new ArrayList < > ();
            }
            l.add(p.val)
            prev = p;
        }

        res.add(l);
        return res;
    }

    private void verticalTraversalHelper(TreeNode root, int x, int y, PriorityQueue < Point > pq) {
        if (root == null) return;
        pq.offer(new Point(x, y, root.val));
        verticalTraversalHelper(root.left, x - 1, y - 1, pq);
        verticalTraversalHelper(root.right, x + 1, y - 1, pq);
    }
}
```

---

### Java HashMap, TreeMap, and PriorityQueue Solution for Vertical Order Traversal

This solution uses a combination of `HashMap`, `TreeMap`, and `PriorityQueue` to solve the vertical order traversal problem efficiently. Below is a detailed explanation of how each data structure contributes to the solution.

#### **Key Concepts**

1. **HashMap for X-Coordinates**:  
   We use a `HashMap<Integer, TreeMap<Integer, PriorityQueue<Integer>>>` to store nodes according to their X-coordinates. The key is the X-coordinate of a node, and the value is a `TreeMap<Integer, PriorityQueue<Integer>>` that stores the Y-coordinate and a priority queue of node values for each (x, y) position. The reason for using a `HashMap` for X-coordinates is because it allows fast constant-time access to the nodes at any given X-coordinate. The range of X-coordinates is continuous and we can track the minimum and maximum X values efficiently.

2. **TreeMap for Y-Coordinates**:  
   For each X-coordinate, we use a `TreeMap<Integer, PriorityQueue<Integer>>` to store nodes by their Y-coordinates. The `TreeMap` ensures that Y-values (row values) are ordered in ascending order. This is important because the rows might not be continuous, and we need to process them in a top-down order for each X-coordinate.

3. **PriorityQueue for Sorting Node Values**:  
   For nodes at the same (X, Y) position, we use a `PriorityQueue` to store the node values in ascending order. The `PriorityQueue` automatically sorts the node values in ascending order, so if multiple nodes fall at the same (X, Y), they will be added in the correct order.

#### **Why This Approach?**

1. **Why use `HashMap` first, then `TreeMap`?**

   - **`HashMap`** provides **constant-time access** for storing and retrieving nodes based on their X-coordinate.
   - **`TreeMap`** is used to store nodes based on their Y-coordinate, as it ensures the keys (Y-values) are sorted in ascending order. This is crucial because we need to process nodes in a top-down order for each X-coordinate.

2. **Why use `PriorityQueue`?**  
   While it's possible to use a `List` to store nodes at each (X, Y) position, the advantage of using a `PriorityQueue` is that it automatically keeps nodes sorted in ascending order. This eliminates the need for additional sorting later, improving code simplicity and reducing time complexity.

#### **Algorithm Breakdown**

1. **Traverse the Tree (Helper Function)**:  
   We perform a **Depth-First Search (DFS)** traversal of the binary tree, starting from the root. During this traversal:

   - Track the current node's X and Y coordinates.
   - Update the global `minX` and `maxX` to track the range of X-coordinates.
   - For each node, add its value to the corresponding priority queue based on its X and Y coordinates.

2. **Building the Result**:  
   After the DFS traversal, the `map` contains all the nodes grouped by their X and Y coordinates. We iterate over the X-coordinates (from `minX` to `maxX`), and for each X, we retrieve the nodes at each Y-level, ensuring they are sorted using the `PriorityQueue`. The result is a list of lists containing the node values in vertical order.

#### **Java Code Implementation**

```java
import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int x) { val = x; }
}

class Solution {
    // Map to store nodes by X, Y coordinates: map[X][Y] -> PriorityQueue of node values
    Map<Integer, TreeMap<Integer, PriorityQueue<Integer>>> map = new HashMap<>();
    // Track the minimum and maximum X-coordinate
    int minX = 0, maxX = 0;

    public List<List<Integer>> verticalTraversal(TreeNode root) {
        // Helper function to perform DFS and populate the map
        helper(root, 0, 0);

        // Prepare the result list
        List<List<Integer>> vertical = new ArrayList<>();

        // Traverse through the range of X-coordinates from minX to maxX
        for (int i = minX; i <= maxX; i++) {
            List<Integer> level = new ArrayList<>();
            // For each X-coordinate, traverse through the sorted Y-coordinates
            for (int key : map.get(i).keySet()) {
                // Poll values from the priority queue for each Y-level
                while (!(map.get(i).get(key)).isEmpty()) {
                    level.add(map.get(i).get(key).poll());
                }
            }
            vertical.add(level);
        }

        return vertical;
    }

    private void helper(TreeNode node, int x, int y) {
        if (node == null) return;

        // Update the min and max X values
        minX = Math.min(minX, x);
        maxX = Math.max(maxX, x);

        // Initialize the map for this X-coordinate if not already present
        if (map.get(x) == null) {
            map.put(x, new TreeMap<Integer, PriorityQueue<Integer>>());
        }

        // Initialize the priority queue for this Y-coordinate if not already present
        if (map.get(x).get(y) == null) {
            map.get(x).put(y, new PriorityQueue<Integer>());
        }

        // Add the node value to the priority queue for the (x, y) coordinate
        map.get(x).get(y).add(node.val);

        // Recurse for left and right children, adjusting the x and y coordinates
        helper(node.left, x - 1, y + 1);
        helper(node.right, x + 1, y + 1);
    }
}
```

#### **Explanation of Code**

1. **Data Structures**:

   - **`map`**: This `HashMap` holds the `TreeMap` of Y-coordinates for each X-coordinate. The `TreeMap` ensures the Y-values are sorted in ascending order, and the `PriorityQueue` keeps node values in ascending order for each (X, Y) position.
   - **`minX` and `maxX`**: These variables are used to track the range of X-coordinates, so we can iterate over them in ascending order to generate the final output.

2. **`helper()` Method**:

   - This recursive method performs a DFS traversal of the tree. For each node, it updates the `minX` and `maxX` values and adds the node value to the correct position in the `map`. It recursively calls itself for the left and right children, adjusting the X and Y coordinates accordingly.

3. **`verticalTraversal()` Method**:
   - After the DFS traversal, we process the nodes from leftmost to rightmost column. For each X-coordinate (from `minX` to `maxX`), we extract the node values from the `map` and store them in the result.

#### **Time Complexity**

- **DFS Traversal**: The DFS traversal visits each node once, which takes \(O(n)\), where \(n\) is the number of nodes in the tree.
- **Processing the map**: For each X-coordinate, we need to traverse all the Y-levels and extract the values. Sorting values within the priority queue (for each (X, Y) position) takes \(O(\log k)\), where \(k\) is the number of nodes at that position. Given that the total number of nodes is \(n\), this results in a time complexity of \(O(n \log n)\) for processing the map.

Thus, the overall time complexity is \(O(n \log n)\).

#### **Space Complexity**

- The space complexity is \(O(n)\), as we store all the nodes in the `map` and maintain additional variables (`minX` and `maxX`).

#### **Conclusion**

This solution efficiently handles vertical order traversal using `HashMap`, `TreeMap`, and `PriorityQueue`, providing an optimized way to traverse and order the nodes by their coordinates while handling ties by sorting node values. This approach ensures that both the column and row traversal are performed correctly and in the required order.

---

### Java Level Order Traversal

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

// Create class tuple to store the node and coordinates.
class Tuple {
    TreeNode node;
    int row;
    int col;
    // Constructor for tuple.
    public Tuple(TreeNode _node, int _row, int _col) {
        node = _node;
        row = _row;
        col = _col;
    }
}
class Solution {

    // We perform Level order trversal to get the output....

    public List < List < Integer >> verticalTraversal(TreeNode root) {

        // We need a treemap to store the vertical values(columns) and PriorityQueue to store the node values in increasing order.
        // (x,y,node)
        TreeMap < Integer, TreeMap < Integer, PriorityQueue < Integer >>> map = new TreeMap < > ();

        // Create a queue for instering each node with respective row(x), column(y) values during iteration.
        // Initially coordinates of node are...(node,x->(0),y->(0))
        Queue < Tuple > q = new LinkedList < Tuple > ();

        // Insert the tuple
        q.add(new Tuple(root, 0, 0));

        // Loop untill queue is empty.
        while (!q.isEmpty()) {

            // Pop the tuple from stack.
            Tuple tuple = q.poll();

            // Initialize the values inside the tuple.
            TreeNode node = tuple.node;
            int x = tuple.row;
            int y = tuple.col;

            // Insert the values into the treemap.

            // x - > vertical coordinate --> check example test cases.
            if (!map.containsKey(x)) map.put(x, new TreeMap < > ());

            // y - > horizontal coordinate --> check example test cases.
            if (!map.get(x).containsKey(y)) map.get(x).put(y, new PriorityQueue < > ());

            // Finally insert node value (!!!not node!!!) into map inside PriorityQueue.
            map.get(x).get(y).add(node.val);

            // Check is there exists a left or right node to the node present in the queue.
            // If present, then add it to the queue.
            if (node.left != null) q.add(new Tuple(node.left, x - 1, y + 1));
            if (node.right != null) q.add(new Tuple(node.right, x + 1, y + 1));
        }

        // Create a List Of List to store the list of node values.
        List < List < Integer >> list = new ArrayList < > ();

        // Loop through the map and add the values.
        // x - > key, (y, nodes) -> values.
        for (TreeMap < Integer, PriorityQueue < Integer >> yn: map.values()) {
            // Create a sublist to store node values in each vertical.
            list.add(new ArrayList < > ());

            // Now iterate in the PriorityQueue.
            for (PriorityQueue < Integer > nodes: yn.values()) {
                // Add node into the sublist from
                while (!nodes.isEmpty()) {
                    list.get(list.size() - 1).add(nodes.poll());
                }
            }
        }
        return list;
    }
}
```

---
