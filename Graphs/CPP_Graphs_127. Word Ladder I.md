# Word Ladder Problem

## Table of Contents

- [Word Ladder Problem](#word-ladder-problem)
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
    - [Steps](#steps)
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

The **Word Ladder Problem** involves finding the shortest sequence of transformations from a `beginWord` to an `endWord` where each word differs by exactly one letter, and every intermediate word must be in a given dictionary, `wordList`. The goal is to determine how many words are in the shortest transformation sequence or return 0 if no such sequence exists.

---

## Problem Description

Given:

- `beginWord`: A starting word.
- `endWord`: The target word.
- `wordList`: A dictionary of words to help transform the `beginWord` to the `endWord`.

### Objective

Return the length of the shortest transformation sequence from `beginWord` to `endWord`. If no such sequence exists, return 0.

### Conditions

- Every adjacent word differs by exactly one character.
- Each intermediate word must exist in `wordList`.
- `beginWord` does not necessarily need to be in the wordList.
- `endWord` must be in `wordList` for a valid transformation sequence to exist.

---

### Examples

#### Example 1

**Input:**

```text
beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
```

**Output:**

```text
5
```

**Explanation:**

- The shortest transformation sequence is `hit -> hot -> dot -> dog -> cog`, which is 5 words long.

#### Example 2

**Input:**

```text
beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
```

**Output:**

```text
0
```

**Explanation:**

- The end word "cog" is not in the `wordList`, so no valid transformation sequence exists.

---

### Constraints

- \( 1 \leq \text{beginWord.length} \leq 10 \)
- \( \text{endWord.length} = \text{beginWord.length} \)
- \( 1 \leq \text{wordList.length} \leq 5000 \)
- Each word in the `wordList` has the same length as `beginWord`.
- `beginWord != endWord`
- All words in `wordList` are unique.
- The problem uses lowercase English letters.

---

## Approach

We can solve this problem using **Breadth-First Search (BFS)**. BFS is ideal because it explores all possible transformations level by level, ensuring that the first time we encounter the `endWord`, it is through the shortest path.

### Steps

1. **Initialize the BFS Queue**:
   - Start by pushing the `beginWord` into a queue along with its initial distance (1, as it’s the first word in the transformation).

2. **Set for Dictionary Lookup**:
   - Use a `unordered_set` for fast lookups of the dictionary words.

3. **BFS Loop**:
   - At each step, take the front word from the queue, and try all possible one-letter transformations.
   - If a transformed word exists in the `wordList`, mark it as visited by removing it from the set and enqueue it with the updated step count.

4. **End Condition**:
   - If we reach the `endWord`, return the current step count.
   - If the queue is exhausted and no path to `endWord` is found, return 0.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Queue to store the word and its corresponding step count
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        // Unordered set for quick lookup of words in wordList
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);  // We don't need to process the beginWord again
        
        // BFS loop
        while (!q.empty()) {
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            
            // If we reached the endWord, return the number of steps
            if (word == endWord) {
                return steps;
            }
            
            // Try all possible transformations by changing one character at a time
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];  // Save the original character
                
                // Try replacing the current character with every letter from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    // If the transformed word exists in the dictionary
                    if (st.find(word) != st.end()) {
                        st.erase(word);  // Mark the word as visited
                        q.push({word, steps + 1});  // Enqueue the new word and its step count
                    }
                }
                
                word[i] = original;  // Restore the original character
            }
        }
        
        // If no transformation sequence exists, return 0
        return 0;
    }
};
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        // Queue to store the word and its corresponding step count
        Queue<Pair<String, Integer>> q = new LinkedList<>();
        q.offer(new Pair<>(beginWord, 1));
        
        // Set for quick lookup of words in wordList
        Set<String> st = new HashSet<>(wordList);
        st.remove(beginWord);  // We don't need to process the beginWord again
        
        // BFS loop
        while (!q.isEmpty()) {
            Pair<String, Integer> pair = q.poll();
            String word = pair.getKey();
            int steps = pair.getValue();
            
            // If we reached the endWord, return the number of steps
            if (word.equals(endWord)) {
                return steps;
            }
            
            // Try all possible transformations by changing one character at a time
            for (int i = 0; i < word.length(); i++) {
                char original = word.charAt(i);  // Save the original character
                
                // Try replacing the current character with every letter from 'a' to 'z'
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    String transformed = word.substring(0, i) + ch + word.substring(i + 1);
                    
                    // If the transformed word exists in the dictionary
                    if (st.contains(transformed)) {
                        st.remove(transformed);  // Mark the word as visited
                        q.offer(new Pair<>(transformed, steps + 1));  // Enqueue the new word and its step count
                    }
                }
            }
        }
        
        // If no transformation sequence exists, return 0
        return 0;
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **BFS Traversal**: Each word is processed at most once, and for each word, we examine all 26 possible transformations for each of the word's characters.
  - For a word of length \( L \), there are \( 26 \times L \) possible transformations.
  - For \( N \) words in the word list, the time complexity is \( O(N \times L \times 26) = O(N \times L) \).

### Space Complexity

- **Queue**: The queue stores words, and the maximum number of words stored in the queue is \( O(N) \).
- **Set for WordList**: The set used for fast lookups also takes \( O(N) \) space.
- **Overall**: \( O(N \times L) \)

---

## How to Run the Code

### For C++

1. Save the code in a `.cpp` file.
2. Compile using:

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
