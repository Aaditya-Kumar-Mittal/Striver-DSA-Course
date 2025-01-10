# Alien Dictionary

## Table of Contents

- [Alien Dictionary](#alien-dictionary)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Expected Output](#expected-output)
    - [Definitions](#definitions)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

---

## Introduction

The **Alien Dictionary** problem asks to determine the order of characters in an alien language. You are provided with a sorted dictionary in the alien language, and your task is to figure out the order of the characters. Multiple valid solutions are possible, and you need to return any one of them. If no valid order exists, return an empty string.

---

## Problem Description

You are given:

- `dict`: An array of words sorted lexicographically in an alien language.
- `k`: The number of characters in the alien language.

### Expected Output

- Return a string containing the characters in the correct order in the alien language, or return an empty string if no valid ordering exists.

### Definitions

- **Valid Ordering:** A correct order of characters, such that each word appears in lexicographical order based on the provided dictionary.

---

### Examples

#### Example 1

**Input:**

```text
dict = ["baa", "abcd", "abca", "cab", "cad"]
k = 4
```

**Output:**

```text
"bdac"
```

**Explanation:**
By comparing consecutive words in the dictionary, we deduce the order of the characters. For example, 'b' comes before 'a' (from "baa" and "abcd"). The solution can have multiple valid answers.

---

#### Example 2

**Input:**

```text
dict = ["caa", "aaa", "aab"]
k = 3
```

**Output:**

```text
"cab"
```

**Explanation:**
The order derived from comparing words shows that 'c' comes before 'a' and 'b'.

---

#### Example 3

**Input:**

```text
dict = ["dhhid", "dahi", "cedg", "fg", "gdah", "i", "gbdei", "hbgf", "e", "ddde"]
k = 9
```

**Output:**

```text
""
```

**Explanation:**
No valid order exists because of conflicting requirements from the dictionary.

---

### Constraints

- \( 1 \leq \text{dict.size()} \leq 10^4 \)
- \( 1 \leq k \leq 26 \)
- \( 1 \leq \text{Length of words} \leq 50 \)

---

## Approach

We will use **Topological Sort** to solve this problem:

1. Construct a directed graph based on the word list:
   - If word[i] differs from word[i+1] at some position, create an edge between the respective characters.
2. Perform **Topological Sort** to determine the order of characters:
   - Use Depth-First Search (DFS) to perform topological sorting.
   - The order of traversal from DFS will give us the order of characters.
3. Return the topologically sorted result.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &visited, stack<int> &stk) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, adj, visited, stk);
            }
        }
        stk.push(node);
    }

public:
    string findOrder(vector<string> dict, int k) {
        vector<vector<int>> adj(k);
        int n = dict.size();

        // Create the graph
        for (int i = 0; i < n - 1; i++) {
            string s1 = dict[i], s2 = dict[i + 1];
            int len = min(s1.size(), s2.size());

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1[ptr] != s2[ptr]) {
                    adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                    break;
                }
            }
        }

        // Perform Topological Sort
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> stk;
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, stk);
            }
        }

        vector<int> topoSort;
        while (!stk.empty()) {
            topoSort.push_back(stk.top());
            stk.pop();
        }

        // Convert topologically sorted result to a string
        string ans = "";
        for (auto it : topoSort) {
            ans += char(it + 'a');
        }

        return ans;
    }
};
```

### Java Implementation

```java
import java.util.*;

class Solution {
    private void dfs(int node, List<List<Integer>> adj, int[] visited, Stack<Integer> stk) {
        visited[node] = 1;
        for (int neighbor : adj.get(node)) {
            if (visited[neighbor] == 0) {
                dfs(neighbor, adj, visited, stk);
            }
        }
        stk.push(node);
    }

    public String findOrder(String[] dict, int k) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < k; i++) {
            adj.add(new ArrayList<>());
        }

        // Create the graph
        for (int i = 0; i < dict.length - 1; i++) {
            String s1 = dict[i], s2 = dict[i + 1];
            int len = Math.min(s1.length(), s2.length());

            for (int ptr = 0; ptr < len; ptr++) {
                if (s1.charAt(ptr) != s2.charAt(ptr)) {
                    adj.get(s1.charAt(ptr) - 'a').add(s2.charAt(ptr) - 'a');
                    break;
                }
            }
        }

        // Perform Topological Sort
        int[] visited = new int[k];
        Stack<Integer> stk = new Stack<>();
        for (int i = 0; i < k; i++) {
            if (visited[i] == 0) {
                dfs(i, adj, visited, stk);
            }
        }

        // Construct the result
        StringBuilder ans = new StringBuilder();
        while (!stk.isEmpty()) {
            ans.append((char) (stk.pop() + 'a'));
        }

        return ans.toString();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Graph Construction:** \( O(E) \), where \( E \) is the total number of edges.
- **Topological Sort (DFS):** \( O(V + E) \), where \( V \) is the number of vertices (characters) and \( E \) is the number of edges.
  
Overall: \( O(V + E) \)

### Space Complexity

- **Graph Representation:** \( O(V + E) \)
- **Auxiliary Structures (Visited, Stack):** \( O(V) \)

Overall: \( O(V + E) \)

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile using a command like:

   ```bash
   g++ -std=c++17 -o output filename.cpp
   ```

3. Run the executable:

   ```bash
   ./output
   ```

### For Java

1. Save the code in a `.java` file.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the program:

   ```bash
   java Solution
   ```
