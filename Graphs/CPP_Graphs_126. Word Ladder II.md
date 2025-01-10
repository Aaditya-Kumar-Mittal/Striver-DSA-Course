# Word Ladder II

## Table of Contents

- [Word Ladder II](#word-ladder-ii)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Objective](#objective)
    - [Conditions](#conditions)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
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

The **Word Ladder II** problem is a variation of the original Word Ladder problem. Instead of returning the length of the shortest transformation sequence, this problem requires finding **all shortest transformation sequences** from the `startWord` to the `targetWord`. Each transformation must differ by exactly one letter, and all intermediate words must exist in the `wordList`.

---

## Problem Description

### Objective

Find all shortest transformation sequences from `startWord` to `targetWord` under the given constraints.

### Conditions

1. Each transformed word must exist in the `wordList`.
2. Only one letter can be changed in each transformation.
3. Return an empty list if no transformation sequence exists.

---

### Examples

#### Example 1

**Input:**

```plaintext
startWord = "der", targetWord = "dfs", wordList = {"des","der","dfr","dgt","dfs"}
```

**Output:**

```plaintext
[["der", "dfr", "dfs"], ["der", "des", "dfs"]]
```

**Explanation:**  
The length of the smallest transformation is 3. The sequences are:

- "der" -> "dfr" -> "dfs"
- "der" -> "des" -> "dfs"

---

#### Example 2

**Input:**

```plaintext
startWord = "gedk", targetWord = "geek", wordList = {"geek", "gefk"}
```

**Output:**

```plaintext
[["gedk", "geek"]]
```

**Explanation:**  
The sequence is "gedk" -> "geek".

---

### Constraints

- \(1 \leq N \leq 100\)
- \(1 \leq M \leq 10\) where \(N = \text{wordList size}\) and \(M = \text{word length}\).

---

## Approach

1. **Breadth-First Search (BFS):**
   - Start from `startWord` and explore all possible transformations level by level.
   - Use a queue to track paths being built.
   - Keep track of words used at each level to avoid revisiting.

2. **Pruning:**
   - Erase words from the `wordList` after exploring them at a level to ensure no cycles or redundant paths.

3. **Path Tracking:**
   - Store paths in the BFS queue and return them when reaching the `targetWord`.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> findSequences(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<vector<string>> q;
        q.push({startWord});
        vector<string> usedOnLevel;
        usedOnLevel.push_back(startWord);
        int level = 0;
        vector<vector<string>> ladderList;

        while (!q.empty()) {
            vector<string> vec = q.front();
            q.pop();

            if (vec.size() > level) {
                level++;
                for (auto it : usedOnLevel) {
                    st.erase(it);
                }
            }

            string word = vec.back();
            if (word == targetWord) {
                if (ladderList.size() == 0) {
                    ladderList.push_back(vec);
                } else if (ladderList[0].size() == vec.size()) {
                    ladderList.push_back(vec);
                }
            }

            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word) > 0) {
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }

        return ladderList;
    }
};

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<string> wordList(n);
        for (int i = 0; i < n; i++) cin >> wordList[i];
        string startWord, targetWord;
        cin >> startWord >> targetWord;
        Solution obj;
        vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
        if (ans.size() == 0)
            cout << -1 << endl;
        else {
            for (auto path : ans) {
                for (string word : path) {
                    cout << word << " ";
                }
                cout << endl;
            }
        }
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public List<List<String>> findSequences(String startWord, String targetWord, List<String> wordList) {
        Set<String> wordSet = new HashSet<>(wordList);
        Queue<List<String>> queue = new LinkedList<>();
        queue.add(Arrays.asList(startWord));

        List<String> usedOnLevel = new ArrayList<>();
        usedOnLevel.add(startWord);

        int level = 0;
        List<List<String>> result = new ArrayList<>();

        while (!queue.isEmpty()) {
            List<String> currentPath = queue.poll();
            if (currentPath.size() > level) {
                level++;
                for (String word : usedOnLevel) {
                    wordSet.remove(word);
                }
            }

            String currentWord = currentPath.get(currentPath.size() - 1);
            if (currentWord.equals(targetWord)) {
                if (result.isEmpty() || result.get(0).size() == currentPath.size()) {
                    result.add(new ArrayList<>(currentPath));
                }
            }

            for (int i = 0; i < currentWord.length(); i++) {
                char originalChar = currentWord.charAt(i);
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    char[] charArray = currentWord.toCharArray();
                    charArray[i] = ch;
                    String transformedWord = new String(charArray);

                    if (wordSet.contains(transformedWord)) {
                        currentPath.add(transformedWord);
                        queue.add(new ArrayList<>(currentPath));
                        usedOnLevel.add(transformedWord);
                        currentPath.remove(currentPath.size() - 1);
                    }
                }
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int tc = sc.nextInt();
        while (tc-- > 0) {
            int n = sc.nextInt();
            List<String> wordList = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                wordList.add(sc.next());
            }
            String startWord = sc.next();
            String targetWord = sc.next();
            Solution sol = new Solution();
            List<List<String>> ans = sol.findSequences(startWord, targetWord, wordList);
            if (ans.isEmpty()) {
                System.out.println(-1);
            } else {
                for (List<String> path : ans) {
                    for (String word : path) {
                        System.out.print(word + " ");
                    }
                    System.out.println();
                }
            }
        }
        sc.close();
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **BFS Traversal:** \(O(N \cdot \log(N) \cdot M \cdot 26)\), where \(N\) is the size of the `wordList`, \(M\) is the word length, and 26 is the number of letters in the English alphabet.

### Space Complexity

- **Auxiliary Space:** \(O(N \cdot M)\) for storing intermediate paths and words.

---

## How to Run the Code

### For C++

1. Compile using `g++`.
2. Run the compiled binary and input the test cases.

### For Java

1. Compile using `javac`.
2. Run the program using `java` and input the test cases.

---
