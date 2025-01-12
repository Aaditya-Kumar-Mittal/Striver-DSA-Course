# Word Ladder II

## Table of Contents

- [Word Ladder II](#word-ladder-ii)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Objective](#objective)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [1. BFS to Generate Levels](#1-bfs-to-generate-levels)
    - [2. DFS for Path Construction](#2-dfs-for-path-construction)
    - [3. Pruning](#3-pruning)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Solution -1](#solution--1)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)

---

## Introduction

The **Word Ladder II** problem requires finding all the shortest transformation sequences from a `beginWord` to an `endWord` by changing only one letter at a time. Each transformed word must exist in the given `wordList`. If no valid transformation sequence exists, return an empty list.

---

## Problem Description

### Objective

Given:

1. A `beginWord`, `endWord`, and `wordList`.
2. Find all the shortest transformation sequences such that:
   - Each word in the sequence differs by exactly one letter.
   - Each word is present in the `wordList`.

---

### Examples

#### Example 1

**Input:**

```plaintext
beginWord = "hit", endWord = "cog", wordList = ["hot", "dot", "dog", "lot", "log", "cog"]
```

**Output:**

```plaintext
[["hit", "hot", "dot", "dog", "cog"], ["hit", "hot", "lot", "log", "cog"]]
```

**Explanation:**  
There are two shortest transformation sequences:

1. "hit" -> "hot" -> "dot" -> "dog" -> "cog"
2. "hit" -> "hot" -> "lot" -> "log" -> "cog"

---

#### Example 2

**Input:**

```plaintext
beginWord = "hit", endWord = "cog", wordList = ["hot", "dot", "dog", "lot", "log"]
```

**Output:**

```plaintext
[]
```

**Explanation:**  
Since the `endWord` "cog" is not in the word list, no valid transformation sequence exists.

---

### Constraints

- \(1 \leq \text{beginWord.length} \leq 5\)
- \(\text{endWord.length} = \text{beginWord.length}\)
- \(1 \leq \text{wordList.length} \leq 500\)
- \(\text{wordList[i].length} = \text{beginWord.length}\)
- All words consist of lowercase English letters.
- `beginWord != endWord`
- All words in `wordList` are unique.

---

## Approach

### 1. BFS to Generate Levels

- Use BFS to calculate the shortest distance (steps) to each word from the `beginWord`.
- Store the level of each word in a `map` for reference.

### 2. DFS for Path Construction

- Use a recursive DFS starting from the `endWord` to backtrack along the shortest path based on the level map.
- Construct all valid paths.

### 3. Pruning

- Use a `set` to efficiently remove visited words and prevent cycles.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<string, int> levelMap; // Map to store levels of words
    vector<vector<string>> result;      // To store all shortest paths
    string beginWord;

    void dfs(string word, vector<string>& path) {
        if (word == beginWord) {
            reverse(path.begin(), path.end());
            result.push_back(path);
            reverse(path.begin(), path.end());
            return;
        }

        int steps = levelMap[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (levelMap.find(word) != levelMap.end() && levelMap[word] + 1 == steps) {
                    path.push_back(word);
                    dfs(word, path);
                    path.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        queue<string> q;
        this->beginWord = beginWord;

        q.push(beginWord);
        levelMap[beginWord] = 1;
        wordSet.erase(beginWord);

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = levelMap[word];

            if (word == endWord)
                break;

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (wordSet.find(word) != wordSet.end()) {
                        q.push(word);
                        wordSet.erase(word);
                        levelMap[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }

        if (levelMap.find(endWord) != levelMap.end()) {
            vector<string> path = {endWord};
            dfs(endWord, path);
        }

        return result;
    }
};

int main() {
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string beginWord = "hit", endWord = "cog";
    Solution sol;
    vector<vector<string>> result = sol.findLadders(beginWord, endWord, wordList);
    for (auto path : result) {
        for (string word : path) {
            cout << word << " ";
        }
        cout << endl;
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    Map<String, Integer> levelMap = new HashMap<>();
    List<List<String>> result = new ArrayList<>();
    String beginWord;

    private void dfs(String word, List<String> path) {
        if (word.equals(beginWord)) {
            Collections.reverse(path);
            result.add(new ArrayList<>(path));
            Collections.reverse(path);
            return;
        }

        int steps = levelMap.get(word);
        for (int i = 0; i < word.length(); i++) {
            char original = word.charAt(i);
            for (char ch = 'a'; ch <= 'z'; ch++) {
                char[] wordArray = word.toCharArray();
                wordArray[i] = ch;
                String transformedWord = new String(wordArray);

                if (levelMap.containsKey(transformedWord) && levelMap.get(transformedWord) + 1 == steps) {
                    path.add(transformedWord);
                    dfs(transformedWord, path);
                    path.remove(path.size() - 1);
                }
            }
        }
    }

    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        Queue<String> queue = new LinkedList<>();
        this.beginWord = beginWord;

        queue.add(beginWord);
        levelMap.put(beginWord, 1);
        wordSet.remove(beginWord);

        while (!queue.isEmpty()) {
            String word = queue.poll();
            int steps = levelMap.get(word);

            if (word.equals(endWord))
                break;

            for (int i = 0; i < word.length(); i++) {
                char original = word.charAt(i);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    char[] wordArray = word.toCharArray();
                    wordArray[i] = ch;
                    String transformedWord = new String(wordArray);

                    if (wordSet.contains(transformedWord)) {
                        queue.add(transformedWord);
                        wordSet.remove(transformedWord);
                        levelMap.put(transformedWord, steps + 1);
                    }
                }
            }
        }

        if (levelMap.containsKey(endWord)) {
            List<String> path = new ArrayList<>();
            path.add(endWord);
            dfs(endWord, path);
        }

        return result;
    }

    public static void main(String[] args) {
        List<String> wordList = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");
        String beginWord = "hit", endWord = "cog";
        Solution sol = new Solution();
        List<List<String>> result = sol.findLadders(beginWord, endWord, wordList);
        for (List<String> path : result) {
            System.out.println(path);
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **BFS Traversal:** \(O(N \cdot M \cdot 26)\)
- **DFS Traversal:** \(O(\text{Number of shortest paths})\)

### Space Complexity

- \(O(N \cdot M)\) for BFS and DFS.

---

## How to Run the Code

### For C++

1. Compile using `g++`.
2. Run the compiled binary and input the test cases.

### For Java

1. Compile using `javac`.
2. Run the program using `java`.

## Other Solutions

### Solution -1

```cpp
class Solution {
public:
    bool isConnected(const string& s1, const string& s2){
        // assume s1 always has the same length with s2
        int diff = 0;
        for (int i = 0; i < s1.length(); ++i) {
            diff += static_cast<int>(s1[i] != s2[i]);
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        } else if (beginWord == endWord) {
            return {{beginWord, endWord}};
        }
        dict.erase(beginWord);

        deque<vector<string>> result;        
        vector<vector<string>> level_nodes;   
        
        bool reached = false;
        level_nodes.push_back({beginWord});
        
        while (dict.size() && !reached) {
            vector<string> curr_level;

            for (const string& from : level_nodes.back()) {
                for (auto iter = dict.begin(); iter != dict.end(); ) {
                    if (!isConnected(from, *iter)) {
                        ++iter;
                        continue;
                    }
                    if (*iter == endWord) {
                        reached = true;
                        break;
                    }
                    curr_level.push_back(*iter);
                    iter = dict.erase(iter);
                }               
            }
            
            // found endWord this level
            if (reached || curr_level.empty()) {
                break;
            }

            // otherwise, record all nodes for the current level
            level_nodes.push_back(move(curr_level));            
        }
        
        // try but not find
        if (!reached) {
            return {};
        }
        
        // move backward
        result.push_back({endWord});          
        for (int level = level_nodes.size() - 1; level >= 0; --level) {                        
            int level_size = result.size();
            while (level_size--) {
                vector<string> path = move(result.front());
                result.pop_front();
                for (const string &to : level_nodes[level]) {                    
                    if (!isConnected(path.front(), to)) {
                        continue;
                    }
                   
                    result.push_back({to});
                    result.back().insert(result.back().end(), path.begin(), path.end());
                }    
            }             
        }
        return {result.begin(), result.end()};
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
    bool isPossible(string str1, string str2){
        int n = str1.length();
        int diff=0;
        for (int i=0;i<n;i++){
            if (str1[i] != str2[i]) diff++;
            if (diff > 1) return false;
        }
         return true;
    }


     void dfs(string str, vector<pair<string, int>> &levels, vector<vector<string>> &ans,
            vector<string> &vec, vector<pair<string,int>>::reverse_iterator it,int count,string &beginWord)
            {
                 if (str == beginWord){
                    vec.push_back(str);
                    reverse(vec.begin(), vec.end());
                    ans.push_back(vec);
                    reverse(vec.begin(), vec.end());
                    vec.pop_back();
                    return ;
                 }

                 while (it!=levels.rend() && it->second==count) it++;
                 while (it!=levels.rend() && it->second==count-1) {
                    if (isPossible(str, it->first)){
                        vec.push_back(str);
                        dfs(it->first, levels, ans, vec, it, count-1, beginWord);
                        vec.pop_back();
                    }
                    it++;
                 }
            }
  
     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
       int n = wordList.size();
       unordered_set<string> dict;
       for (auto &x: wordList){
        if (x != beginWord) dict.insert(x);
       }

       queue<string> q;
       q.push(beginWord);
       vector<pair<string, int>> levels;
       int count = 0;
       bool flag = false;

       while(!q.empty()){
          int size = q.size();
          while (size--){
              string node = q.front();
              q.pop();

              levels.push_back({node, count});
              if (node == endWord){
                flag = true;
                break;
              }

              for (int i=0;i<node.length();i++){
                char original = node[i];
                for (char ch='a';ch<='z';ch++){
                     if (original == ch) continue;
                     node[i] = ch;

                     if (dict.find(node) != dict.end()){
                        q.push(node);
                        dict.erase(node);
                     }
                }
                node[i] = original;
              }
          }
          if (flag) break;
          count++;
       }
       
        vector<pair<string,int>>::reverse_iterator it=levels.rbegin();
        vector<vector<string>> ans;
        vector<string> vec;
        if (!flag) return ans;

        dfs(endWord, levels, ans, vec, it, count, beginWord);
        return ans;
    }
};
```

### Solution - 3

```cpp
class Solution {
public:
    bool isConnected(const string& s1, const string& s2){
        // assume s1 always has the same length with s2
        int diff = 0;
        for (int i = 0; i < s1.length(); ++i) {
            diff += static_cast<int>(s1[i] != s2[i]);
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        } else if (beginWord == endWord) {
            return {{beginWord, endWord}};
        }
        dict.erase(beginWord);

        deque<vector<string>> result;        
        vector<vector<string>> level_nodes;   
        
        bool reached = false;
        level_nodes.push_back({beginWord});
        
        while (dict.size() && !reached) {
            vector<string> curr_level;

            for (const string& from : level_nodes.back()) {
                for (auto iter = dict.begin(); iter != dict.end(); ) {
                    if (!isConnected(from, *iter)) {
                        ++iter;
                        continue;
                    }
                    if (*iter == endWord) {
                        reached = true;
                        break;
                    }
                    curr_level.push_back(*iter);
                    iter = dict.erase(iter);
                }               
            }
            
            // found endWord this level
            if (reached || curr_level.empty()) {
                break;
            }

            // otherwise, record all nodes for the current level
            level_nodes.push_back(move(curr_level));            
        }
        
        // try but not find
        if (!reached) {
            return {};
        }
        
        // move backward
        result.push_back({endWord});          
        for (int level = level_nodes.size() - 1; level >= 0; --level) {                        
            int level_size = result.size();
            while (level_size--) {
                vector<string> path = move(result.front());
                result.pop_front();
                for (const string &to : level_nodes[level]) {                    
                    if (!isConnected(path.front(), to)) {
                        continue;
                    }
                   
                    result.push_back({to});
                    result.back().insert(result.back().end(), path.begin(), path.end());
                }    
            }             
        }
        return {result.begin(), result.end()};
    }
};
```

### Solution - 4

```cpp
class Solution
{
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        const auto graph = buildGraph(wordList);
        const int n = graph.size();

        auto shortest = std::vector<int>(n, std::numeric_limits<int>::max());
        auto prevs = std::vector<std::unordered_set<int>>(n);

        auto queue = std::unordered_set<int>{};
        int target = -1;
        for (int i = 0; i < n; ++i)
        {
            if (endWord == wordList[i])
                target = i;

            if (areNeighbours(beginWord, wordList[i]))
            {
                if (i == target)
                {
                    return {{beginWord, wordList[i]}};
                }
                else
                {
                    shortest[i] = 1;
                    queue.insert(i);
                }
            }
        }
        if (target == -1) return {};

        int length = 1;
        while (!queue.empty())
        {
            auto nextQueue = std::unordered_set<int>{};
            bool finished = false;
            for (const auto& node : queue)
            {
                for (const auto nextId : graph[node])
                {
                    if (shortest[nextId] < length + 1)
                        continue;
                    if (shortest[nextId] > length + 1)
                        prevs[nextId].clear();

                    if (nextId == target)
                        finished = true;
                    if (!finished)
                        nextQueue.insert(nextId);

                    shortest[nextId] = length + 1;
                    prevs[nextId].insert(node);
                }
            }
            ++length;
            if (finished) queue.clear();
            else queue.swap(nextQueue);
        }

        if (prevs[target].empty()) return {};

        auto result = restorePaths(prevs, target);
        return convert(result, beginWord, wordList);
    }

private:
    bool areNeighbours(const std::string& w1, const std::string& w2)
    {
        const int n = w1.size();
        int diff = 0;
        for (int i = 0; i < n; ++i)
        {
            if (w1[i] != w2[i])
            {
                if (++diff > 1) return false;
            }
        }
        return true;
    }

    std::vector<std::vector<int>> buildGraph(const std::vector<std::string>& words)
    {
        const int n = words.size();

        auto result = std::vector<std::vector<int>>(n);
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                if (areNeighbours(words[i], words[j]))
                {
                    result[i].push_back(j);
                    result[j].push_back(i);
                }
            }
        }
        return result;
    }

    std::vector<std::vector<std::string>> convert(const std::vector<std::vector<int>>& paths,
                                                  const std::string& source,
                                                  const std::vector<std::string>& words)
    {
        auto result = std::vector<std::vector<std::string>>{};

        for (const auto& path : paths)
        {
            result.emplace_back();
            result.back().push_back(source);
            for (int i = 0; i < path.size(); ++i)
            {
                result.back().push_back(words[path[i]]);
            }
        }
        return result;
    }

    std::vector<std::vector<int>> restorePaths(const std::vector<std::unordered_set<int>>& prevs, const int node)
    {
        auto result = std::vector<std::vector<int>>{};
        for (const int prev : prevs.at(node))
        {
            auto subResult = restorePaths(prevs, prev);
            for (auto& path : subResult)
            {
                result.emplace_back(std::move(path));
            }
        }
        if (result.empty()) result.emplace_back();
        for (auto& path : result)
            path.push_back(node);
        return result;
    }
};
```
