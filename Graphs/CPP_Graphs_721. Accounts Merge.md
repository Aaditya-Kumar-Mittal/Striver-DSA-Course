# Accounts Merge

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Accounts Merge](#accounts-merge)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The task is to merge user accounts based on email addresses. Each account is represented by a name followed by email addresses. If two accounts share a common email, they belong to the same person. The goal is to merge these accounts and return the result with sorted emails for each person.

## Problem Description

You are given a 2D list `accounts` where:

- `accounts[i][0]` is the name of the person.
- The rest of the elements in `accounts[i]` are the email addresses associated with that person.

The problem is to merge accounts that share common emails and return the result such that:

1. Each merged account starts with the person's name.
2. Emails in each account are sorted lexicographically.
3. Accounts can be returned in any order.

### Examples

#### Example 1

**Input:**

```cpp
accounts = [
    ["John","johnsmith@mail.com","john_newyork@mail.com"],
    ["John","johnsmith@mail.com","john00@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]
]
```

**Output:**

```cpp
[
    ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
    ["Mary","mary@mail.com"],
    ["John","johnnybravo@mail.com"]
]
```

**Explanation:**

- The first and second "John" are merged because they share the email `"johnsmith@mail.com"`.
- The third "John" and "Mary" are not merged as they have unique emails.

#### Example 2

**Input:**

```cpp
accounts = [
    ["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
    ["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
    ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
    ["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
    ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]
]
```

**Output:**

```cpp
[
    ["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
    ["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
    ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
    ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
    ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]
]
```

**Explanation:**
Each person's emails are distinct, so no merging is necessary.

### Constraints

- \(1 \leq \text{accounts.length} \leq 1000\)
- \(2 \leq \text{accounts}[i].\text{length} \leq 10\)
- \(1 \leq \text{accounts}[i][j].\text{length} \leq 30\)
- `accounts[i][0]` consists of English letters.
- `accounts[i][j]` (for \(j > 0\)) is a valid email address.

## Approach

1. **Disjoint Set (Union-Find):**
   - Use a disjoint set to group accounts sharing common emails.
   - Each email is mapped to an account index.

2. **Mapping and Merging:**
   - Traverse the accounts and map emails to their corresponding account index.
   - Use the union operation to group accounts with shared emails.

3. **Sorting and Structuring:**
   - Collect emails from each group and sort them lexicographically.
   - Prepare the final result by combining the name with sorted emails.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> parent, sizeArr;

    DisjointSet(int n) {
        parent.resize(n + 1);
        sizeArr.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int rootU = findParent(u);
        int rootV = findParent(v);
        if (rootU == rootV)
            return;
        if (sizeArr[rootU] < sizeArr[rootV]) {
            parent[rootU] = rootV;
            sizeArr[rootV] += sizeArr[rootU];
        } else {
            parent[rootV] = rootU;
            sizeArr[rootU] += sizeArr[rootV];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToNode;

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                if (emailToNode.find(email) == emailToNode.end()) {
                    emailToNode[email] = i;
                } else {
                    ds.unionBySize(emailToNode[email], i);
                }
            }
        }

        vector<vector<string>> mergedEmails(n);
        for (auto& [email, node] : emailToNode) {
            int root = ds.findParent(node);
            mergedEmails[root].push_back(email);
        }

        vector<vector<string>> result;
        for (int i = 0; i < n; i++) {
            if (mergedEmails[i].empty()) continue;
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> temp = {accounts[i][0]};
            temp.insert(temp.end(), mergedEmails[i].begin(), mergedEmails[i].end());
            result.push_back(temp);
        }

        return result;
    }
};
```

### Java Implementation

```java
import java.util.*;

class DisjointSet {
    int[] parent, size;

    public DisjointSet(int n) {
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    public int find(int node) {
        if (node == parent[node]) return node;
        return parent[node] = find(parent[node]);
    }

    public void union(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV) {
            if (size[rootU] < size[rootV]) {
                parent[rootU] = rootV;
                size[rootV] += size[rootU];
            } else {
                parent[rootV] = rootU;
                size[rootU] += size[rootV];
            }
        }
    }
}

class Solution {
    public List<List<String>> accountsMerge(List<List<String>> accounts) {
        int n = accounts.size();
        DisjointSet ds = new DisjointSet(n);
        Map<String, Integer> emailToNode = new HashMap<>();

        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts.get(i).size(); j++) {
                String email = accounts.get(i).get(j);
                if (!emailToNode.containsKey(email)) {
                    emailToNode.put(email, i);
                } else {
                    ds.union(emailToNode.get(email), i);
                }
            }
        }

        Map<Integer, List<String>> mergedEmails = new HashMap<>();
        for (Map.Entry<String, Integer> entry : emailToNode.entrySet()) {
            String email = entry.getKey();
            int root = ds.find(entry.getValue());
            mergedEmails.computeIfAbsent(root, k -> new ArrayList<>()).add(email);
        }

        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!mergedEmails.containsKey(i)) continue;
            List<String> emails = mergedEmails.get(i);
            Collections.sort(emails);
            List<String> temp = new ArrayList<>();
            temp.add(accounts.get(i).get(0));
            temp.addAll(emails);
            result.add(temp);
        }

        return result;
    }
}
```

## Complexity Analysis

1. **Time Complexity:**
   - Union-Find operations: \(O(\alpha(n) \cdot E)\), where \(E\) is the total number of emails.
   - Sorting emails: \(O(E \cdot \log(E))\).
   - Total: \(O(E \cdot \log(E))\).

2. **Space Complexity:**
   - \(O(E + N)\), where \(E\) is the total number of emails and \(N\) is the number of accounts.

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile using: `g++ -std=c++17 filename.cpp -o output`.
3. Run the executable: `./output`.

### For Java

1. Save the code in a `.java` file.
2. Compile using: `javac filename.java`.
3. Run the program: `java filename`.
