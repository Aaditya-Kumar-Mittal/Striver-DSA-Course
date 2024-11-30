# Palindrome Partitioning

## Table of Contents

- [Palindrome Partitioning](#palindrome-partitioning)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Backtracking Algorithm](#backtracking-algorithm)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [Other Solutions](#other-solutions)
    - [CPP Solution](#cpp-solution)

---

## Introduction

The goal is to partition a string into substrings such that every substring is a palindrome and return all possible partitioning results.

---

## Problem Description

### Input

- A string `s`.

### Output

- A list of all possible partitions, where each partition consists of palindromic substrings.

---

### Examples

#### Example 1

**Input:**

```plaintext
s = "aab"
```

**Output:**

```plaintext
[["a", "a", "b"], ["aa", "b"]]
```

#### Example 2

**Input:**

```plaintext
s = "a"
```

**Output:**

```plaintext
[["a"]]
```

---

### Constraints

- `1 <= s.length <= 16`
- `s` consists of only lowercase English letters.

---

## Approach

### Backtracking Algorithm

1. **Partitioning**:

   - For every substring starting from the current index, check if it is a palindrome.
   - If true, add it to the current path and recurse on the remaining string.
   - When the end of the string is reached, store the path in the result.

2. **Palindrome Check**:

   - Use a two-pointer approach to verify if a substring is a palindrome.

3. **Backtracking**:
   - After exploring one path, backtrack by removing the last substring to explore other possibilities.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Function to check if a substring is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }

    // Backtracking function to find all partitions
    void partitionString(int index, string &s, vector<string> &path, vector<vector<string>> &res) {
        if (index == s.size()) {
            res.push_back(path);
            return;
        }

        for (int i = index; i < s.size(); i++) {
            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                partitionString(i + 1, s, path, res);
                path.pop_back(); // Backtrack
            }
        }
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        partitionString(0, s, path, res);
        return res;
    }
};
```

---

### Java Implementation

```java
import java.util.ArrayList;
import java.util.List;

class Solution {
    // Helper method to check if a substring is a palindrome
    private boolean isPalindrome(String s, int start, int end) {
        while (start <= end) {
            if (s.charAt(start++) != s.charAt(end--)) {
                return false;
            }
        }
        return true;
    }

    // Backtracking method to partition the string
    private void partitionString(int index, String s, List<String> path, List<List<String>> result) {
        if (index == s.length()) {
            result.add(new ArrayList<>(path));
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (isPalindrome(s, index, i)) {
                path.add(s.substring(index, i + 1));
                partitionString(i + 1, s, path, result);
                path.remove(path.size() - 1); // Backtrack
            }
        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> result = new ArrayList<>();
        List<String> path = new ArrayList<>();
        partitionString(0, s, path, result);
        return result;
    }
}
```

---

## Complexity Analysis

1. **Time Complexity**:

   - Exploring all possible partitions involves `O(2^n)` combinations.
   - Palindrome checking for each substring takes `O(n)`.

   **Overall Time Complexity**: `O(n * 2^n)`.

2. **Space Complexity**:

   - Recursive stack space: `O(n)`, where `n` is the length of the string.
   - Space used for storing results and paths: `O(2^n)`.

   **Overall Space Complexity**: `O(n * 2^n)`.

## Other Solutions

### CPP Solution

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
private:
  void moveInMaze(int i, int j, vector<vector<int>> &maze, int n, vector<string> &ans, string move, vector<vector<int>> &visited)
  {

    if (i == n - 1 && j == n - 1)
    {
      ans.push_back(move);
      return;
    }

    // Downward
    if (i + 1 < n && !visited[i + 1][j] && maze[i + 1][j] == 1)
    {
      visited[i][j] = 1;
      moveInMaze(i + 1, j, maze, n, ans, move + 'D', visited);
      visited[i][j] = 0;
    }

    // Left
    if (j - 1 >= 0 && !visited[i][j - 1] && maze[i][j - 1] == 1)
    {
      visited[i][j] = 1;
      moveInMaze(i, j - 1, maze, n, ans, move + 'L', visited);
      visited[i][j] = 0;
    }

    // Right
    if (j + 1 < n && !visited[i][j + 1] && maze[i][j + 1] == 1)
    {
      visited[i][j] = 1;
      moveInMaze(i, j + 1, maze, n, ans, move + 'R', visited);
      visited[i][j] = 0;
    }
    // Upward
    if (i - 1 >= 0 && !visited[i - 1][j] && maze[i - 1][j] == 1)
    {
      visited[i][j] = 1;
      moveInMaze(i - 1, j, maze, n, ans, move + 'U', visited);
      visited[i][j] = 0;
    }
  }

public:
  vector<string> findPath(vector<vector<int>> &mat)
  {

    int n = mat.size();

    vector<string> ans;

    vector<vector<int>> visited(n, vector<int>(n, 0));

    if (mat[0][0] == 1)
      moveInMaze(0, 0, mat, n, ans, "", visited);

    return ans;
  }
};

//{ Driver Code Starts.

int main()
{
  int t;
  cin >> t;
  cin.ignore();
  while (t--)
  {
    string input;
    getline(cin, input);
    vector<vector<int>> mat;
    string innerArray;
    bool isInsideArray = false;

    for (char c : input)
    {
      if (c == '[')
      {
        if (isInsideArray)
        {
          innerArray.clear();
        }
        isInsideArray = true;
      }
      else if (c == ']')
      {
        if (isInsideArray && !innerArray.empty())
        {
          vector<int> row;
          stringstream ss(innerArray);
          int num;

          while (ss >> num)
          {
            row.push_back(num);
            if (ss.peek() == ',')
              ss.ignore();
            while (isspace(ss.peek()))
              ss.ignore();
          }

          mat.push_back(row);
          innerArray.clear();
        }
        isInsideArray = false;
      }
      else if (isInsideArray)
      {
        if (!isspace(c))
        {
          innerArray += c;
        }
      }
    }

    Solution obj;
    vector<string> result = obj.findPath(mat);
    sort(result.begin(), result.end());

    if (result.empty())
      cout << "[]";
    else
      for (int i = 0; i < result.size(); i++)
        cout << result[i] << " ";
    cout << endl;
    cout << "~" << endl;
  }
  return 0;
}

// } Driver Code Ends
```
