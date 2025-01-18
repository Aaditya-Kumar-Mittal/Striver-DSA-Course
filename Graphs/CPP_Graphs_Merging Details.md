# Merging Details

<!-- markdownlint-disable MD052 -->

## Table of Contents

- [Merging Details](#merging-details)
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

---

## Introduction

The task is to merge student details, where each detail includes a name and a list of email addresses. If two details share a common email, they belong to the same student. The goal is to group and return the details of students, ensuring:

1. Emails are sorted lexicographically within each student group.
2. The output is sorted alphabetically by student names.

---

## Problem Description

You are given a 2D list `details` where each element is a list of strings:

- `details[i][0]` is the student's name.
- The subsequent strings in `details[i]` are the student's email addresses.

### Examples

#### Example 1

**Input:**

```bash
n = 4
details = [
  ["John","johnsmith@mail.com","john_newyork@mail.com"],
  ["John","johnsmith@mail.com","john00@mail.com"],
  ["Mary","mary@mail.com"],
  ["John","johnnybravo@mail.com"]
]
```

**Output:**

```bash
[
  ["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
  ["Mary","mary@mail.com"],
  ["John","johnnybravo@mail.com"]
]
```

**Explanation:**

- The first and second John's emails overlap (`"johnsmith@mail.com"`), so they are grouped.
- The third John and Mary are independent.

#### Example 2

**Input:**

```bash
n = 5
details = [
  ["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
  ["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
  ["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
  ["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
  ["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]
]
```

**Output:**

```bash
[
  ["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
  ["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
  ["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
  ["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
  ["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]
]
```

**Explanation:**

- No shared emails exist between users. Each user is independent.

### Constraints

- \(1 \leq \text{details.length} \leq 1000\)
- \(2 \leq \text{details}[i].\text{length} \leq 10\)
- \(1 \leq \text{details}[i][j].\text{length} \leq 30\)
- \(details[i][0]\) consists of English letters.
- \(details[i][j]\) (for \(j > 0\)) is a valid email.

---

## Approach

1. **Disjoint Set (Union-Find):**
   - Use a disjoint set data structure to group emails belonging to the same student.
   - Each email maps to a parent node representing the group it belongs to.

2. **Mapping Emails to Groups:**
   - Use a hash map to associate each email with its group (node index).

3. **Sorting and Structuring:**
   - Sort emails within each group.
   - Structure the result such that it is sorted alphabetically by student names.

---

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

        if (rootU == rootV) return;
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
    vector<vector<string>> mergeDetails(vector<vector<string>> &details) {
        int n = details.size();
        DisjointSet ds(n);
        unordered_map<string, int> emailToNode;

        // Map emails to nodes and perform unions
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details[i].size(); j++) {
                string email = details[i][j];
                if (emailToNode.find(email) == emailToNode.end()) {
                    emailToNode[email] = i;
                } else {
                    ds.unionBySize(emailToNode[email], i);
                }
            }
        }

        // Group emails by parent
        vector<vector<string>> mergedEmails(n);
        for (auto &it : emailToNode) {
            string email = it.first;
            int parent = ds.findParent(it.second);
            mergedEmails[parent].push_back(email);
        }

        // Construct the final result
        vector<vector<string>> result;
        for (int i = 0; i < n; i++) {
            if (mergedEmails[i].empty()) continue;
            sort(mergedEmails[i].begin(), mergedEmails[i].end());
            vector<string> temp = {details[i][0]};
            temp.insert(temp.end(), mergedEmails[i].begin(), mergedEmails[i].end());
            result.push_back(temp);
        }

        sort(result.begin(), result.end());
        return result;
    }
};
```

```cpp
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class DisjointSet
{
public:
  vector<int> parent, sizeArr;

  // Constructor to initialize parent and size arrays
  DisjointSet(int n)
  {
    parent.resize(n + 1);
    sizeArr.resize(n + 1, 1);

    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  // Find function with path compression
  int findParent(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findParent(parent[node]);
  }

  // Union function by size
  void unionBySize(int u, int v)
  {
    int rootU = findParent(u);
    int rootV = findParent(v);

    if (rootU == rootV)
      return;

    if (sizeArr[rootU] < sizeArr[rootV])
    {
      parent[rootU] = rootV;
      sizeArr[rootV] += sizeArr[rootU];
    }
    else
    {
      parent[rootV] = rootU;
      sizeArr[rootU] += sizeArr[rootV];
    }
  }
};

class Solution
{
public:
  vector<vector<string>> mergeDetails(vector<vector<string>> &details)
  {
    // code here

    // Iterated through the details and mapped the mails to the node they belonged
    // If there was overlap, unioned those nodes and first is the name.
    // Starting map from index 1

    int n = details.size();
    DisjointSet ds(n);

    unordered_map<string, int> mppMailNode;

    for (int i = 0; i < n; i++)
    {
      for (int j = 1; j < details[i].size(); j++)
      {
        string mail = details[i][j];
        if (mppMailNode.find(mail) == mppMailNode.end())
        {
          mppMailNode[mail] = i;
        }
        else
        {
          ds.unionBySize(mppMailNode[mail], i);
        }
      }
    }

    // Put these mails in a list of merged strings, remembering whose the ultimate parent

    vector<vector<string>> mergedMail(n);

    for (auto it : mppMailNode)
    {
      string mail = it.first;
      int node = ds.findParent(it.second);
      mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i = 0; i < n; i++)
    {
      if (mergedMail[i].empty())
        continue;

      // Sort emails and add the name at the beginning
      sort(mergedMail[i].begin(), mergedMail[i].end());
      vector<string> temp;
      temp.push_back(details[i][0]); // Add the name
      for (auto mail : mergedMail[i])
      {
        temp.push_back(mail);
      }
      ans.push_back(temp);
    }

    reverse(ans.begin(), ans.end());

    return ans;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<vector<string>> adj;

    for (int i = 0; i < n; i++)
    {
      vector<string> temp;
      string s;
      cin >> s;
      temp.push_back(s);
      int x;
      cin >> x;

      for (int j = 0; j < x; j++)
      {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      adj.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.mergeDetails(adj);
    sort(res.begin(), res.end(), [](const vector<string> &a, const vector<string> &b)
         { return a[0] <= b[0]; });
    cout << "[";
    for (int i = 0; i < res.size(); ++i)
    {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++)
      {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], ";
      else
        cout << "]";
    }
    cout << "]"
         << "\n";

    cout << "~" << "\n";
  }
}

// } Driver Code Ends
```

---

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
    public List<List<String>> mergeDetails(List<List<String>> details) {
        int n = details.size();
        DisjointSet ds = new DisjointSet(n);
        Map<String, Integer> emailToNode = new HashMap<>();

        // Map emails to nodes and perform unions
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < details.get(i).size(); j++) {
                String email = details.get(i).get(j);
                if (!emailToNode.containsKey(email)) {
                    emailToNode.put(email, i);
                } else {
                    ds.union(emailToNode.get(email), i);
                }
            }
        }

        // Group emails by parent
        Map<Integer, List<String>> mergedEmails = new HashMap<>();
        for (Map.Entry<String, Integer> entry : emailToNode.entrySet()) {
            String email = entry.getKey();
            int parent = ds.find(entry.getValue());
            mergedEmails.computeIfAbsent(parent, k -> new ArrayList<>()).add(email);
        }

        // Construct the final result
        List<List<String>> result = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            if (!mergedEmails.containsKey(i)) continue;
            List<String> emails = mergedEmails.get(i);
            Collections.sort(emails);
            List<String> temp = new ArrayList<>();
            temp.add(details.get(i).get(0));
            temp.addAll(emails);
            result.add(temp);
        }

        result.sort((a, b) -> a.get(0).compareTo(b.get(0)));
        return result;
    }
}
```

---

## Complexity Analysis

1. **Time Complexity:**
   - Union-Find operations: \(O(\alpha(N))\) per operation.
   - Sorting emails: \(O(E \log E)\), where \(E\) is the total number of emails.
   - Final sorting: \(O(G \log G)\), where \(G\) is the number of groups.

   Overall: \(O(N \cdot M \cdot \alpha(N) + E \log E + G \log G)\), where \(M\) is the average number of emails per student.

2. **Space Complexity:**
   - Disjoint set storage: \(O(N)\).
   - Email mappings: \(O(E)\).

---

## How to Run the Code

### For C++

1. Compile the code using a C++ compiler:

   ```bash
   g++ -o mergeDetails mergeDetails.cpp
   ```

2. Run the executable:

   ```bash
   ./mergeDetails
   ```

### For Java

1. Compile the code using a Java compiler:

   ```bash
   javac Solution.java
   ```

2. Run the program:

   ```bash
   java Solution
   ```
