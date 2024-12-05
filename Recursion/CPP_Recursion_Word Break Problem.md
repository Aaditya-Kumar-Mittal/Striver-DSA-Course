# Word Break Problem

## Table of Contents

- [Word Break Problem](#word-break-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Observations](#key-observations)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2 (CPP and Dynamic Programming)](#solution---2-cpp-and-dynamic-programming)
    - [Solution - 3](#solution---3)
    - [Solution - 4](#solution---4)
    - [Solution - 5 (Using Tries)](#solution---5-using-tries)
    - [Solution - 6,7,8,9](#solution---6789)

---

## Introduction

The task is to determine if a given string `s` can be segmented into a sequence of one or more dictionary words from a given word dictionary `wordDict`. Words can be reused multiple times.

---

## Problem Description

### Input

- `s`: A string to segment.
- `wordDict`: A list of unique strings representing the word dictionary.

### Output

- `true`: If the string can be segmented using the dictionary words.
- `false`: Otherwise.

---

### Examples

#### Example 1

**Input:**

```plaintext
s = "leetcode", wordDict = ["leet", "code"]
```

**Output:**

```plaintext
true
```

**Explanation:**  
`leetcode` can be split as `leet code`.

---

#### Example 2

**Input:**

```plaintext
s = "applepenapple", wordDict = ["apple", "pen"]
```

**Output:**

```plaintext
true
```

**Explanation:**  
`applepenapple` can be split as `apple pen apple`. Words in the dictionary can be reused.

---

#### Example 3

**Input:**

```plaintext
s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
```

**Output:**

```plaintext
false
```

---

### Constraints

- `1 ≤ s.length ≤ 300`
- `1 ≤ wordDict.length ≤ 1000`
- `1 ≤ wordDict[i].length ≤ 20`
- `s` and `wordDict[i]` consist only of lowercase English letters.
- All strings in `wordDict` are unique.

---

## Approach

### Key Observations

1. **Dynamic Programming (DP):**

   - Use a DP table (`dp[i]`) where `dp[i] = true` if the substring `s[0:i]` can be segmented using the dictionary.

2. **Recursive Backtracking with Memoization:**

   - Recursively check if substrings can form valid segments while storing results to avoid recomputation.

3. **Hash Set for Fast Lookup:**
   - Store the dictionary words in a hash set to enable constant-time lookups.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    unordered_set<string> st; // Stores dictionary words
    int n;                    // Length of string s
    int t[301];               // Memoization table

    // Recursive function to check segmentation
    bool solve(int idx, string& s) {
        if (idx >= n) // Base case: all characters processed
            return true;

        if (t[idx] != -1) // If result is already computed
            return t[idx];

        for (int l = 1; l <= n - idx; l++) {
            string temp = s.substr(idx, l); // Extract substring of length l

            if (st.find(temp) != st.end() && solve(idx + l, s)) // Check if valid
                return t[idx] = true;
        }

        return t[idx] = false; // No valid segmentation found
    }

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t)); // Initialize memoization table

        // Insert all dictionary words into the set
        for (string& word : wordDict) {
            st.insert(word);
        }

        return solve(0, s);
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private Set<String> wordSet;
    private int[] memo;

    private boolean solve(String s, int idx) {
        if (idx == s.length()) // Base case: all characters processed
            return true;

        if (memo[idx] != -1) // If result is already computed
            return memo[idx] == 1;

        for (int l = 1; l <= s.length() - idx; l++) {
            String temp = s.substring(idx, idx + l); // Extract substring

            if (wordSet.contains(temp) && solve(s, idx + l)) // Check validity
                return memo[idx] = 1;
        }

        return memo[idx] = 0; // No valid segmentation found
    }

    public boolean wordBreak(String s, List<String> wordDict) {
        wordSet = new HashSet<>(wordDict);
        memo = new int[s.length()];
        Arrays.fill(memo, -1);

        return solve(s, 0);
    }
}
```

---

## Complexity Analysis

### Time Complexity

1. **Recursive Approach with Memoization:**

   - At most `n` starting indices with `n` substrings for each = `O(n^2)`.
   - Hash lookup for each substring = `O(1)`.

   **Overall Time Complexity:** `O(n^2)`.

2. **DP Approach:** Same as above.

### Space Complexity

1. **Recursive Call Stack:** `O(n)` (max depth of recursion).
2. **Memoization Table:** `O(n)`.

   **Overall Space Complexity:** `O(n)`.

This implementation uses recursion with memoization or DP to efficiently solve the problem within given constraints.

## Other Solutions

### Solution - 1

```cpp
class Solution
{
public:
  bool wordBreak(string s, vector<string> &wordDict)
  {
    vector<bool> isSubWord(s.length() + 1);
    isSubWord[s.length()] = true;
    for (int i = s.length() - 1; i >= 0; i--)
    {
      for (string word : wordDict)
      {
        if ((i + word.length() <= s.length()) &&
            (s.substr(i, word.length()) == word))
        {
          isSubWord[i] = isSubWord[i + word.length()];
        }
        if (isSubWord[i])
          break;
      }
    }
    return isSubWord[0];
  }
};
```

### Solution - 2 (CPP and Dynamic Programming)

```cpp
class Solution {
public:
    bool solve(string &s, int start, unordered_set<string> &dictSet, vector<int> &dp){
        // Step 1: If at end of string, return true
        if(start == s.size()) return true;

        // Step 2: Return saved result if already calculated
        if(dp[start] != -1) return dp[start];

        // Step 3: Check all words starting from 'start'
        string word;
        for(int i = start; i < s.size(); i++){
            word += s[i];
            // Step 4: If word is in dictionary and rest can be solved, return true
            if(dictSet.find(word) != dictSet.end() && solve(s, i+1, dictSet, dp)){
                return dp[start] = true;
            }
        }

        // Step 5: Save and return false if no match found
        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // Step 6: Save wordDict in a set for fast lookup
        unordered_set<string> dictSet;
        dictSet.insert(wordDict.begin(), wordDict.end());
        // Step 7: Create DP array for caching results
        vector<int> dp(s.size(), -1);
        // Step 8: Start solving from index 0
        return solve(s, 0, dictSet, dp);
    }
};
```

### Solution - 3

```cpp
class Solution {
public:
    bool wordBreak(string source, vector<string>& wordDict) {
        set<string> s;
        for(auto i : wordDict) {
            reverse(i.begin(), i.end());
            s.insert(i);
        }

        int n = source.size();
        vector<int> dp(n, 0);
        string cur = "";
        for(int i = 0 ; i < n; i++) {
            cur.push_back(source[i]);
            string copy = cur;
            reverse(copy.begin(), copy.end());
            if(s.count(copy)) {
                dp[i]++; continue;
            }

            for(int j = 0; j < i; j++) {
                copy.pop_back();
                if(dp[j]) {
                    if(s.count(copy)) {dp[i]++; break;}
                }
            }
        }
        return dp[n-1] == 1;
    }
};
```

### Solution - 4

```cpp
class Solution
{
    unordered_set<string> dict;

    bool wordBreakImpl( string const & input )
    {
      if( dict.contains( input ) )
        return true;

      int n = input.length();
      vector<bool> dp( n, false );
      dp[0] = dict.contains( input.substr( 0, 1 ) );

      for( int index = 1; index < n; ++index )
      {
        int offset = 0;
        while( offset < index )
        {
          if( dp[index - offset - 1] && dict.contains( input.substr( index - offset, offset + 1 ) ) )
          {
            dp[index] = true;
            break;
          }
          ++offset;
        }

        if( !dp[index] && dict.contains( input.substr( 0, index + 1 ) ) )
        {
          dp[index] = true;
        }
      }

      return dp.back();
    }

public:
    bool wordBreak( string s, vector<string>& wordDict )
    {
      dict.insert( wordDict.begin(), wordDict.end() );
      return wordBreakImpl( s );
    }
};
```

### Solution - 5 (Using Tries)

```cpp
class Trie
{
public:
  bool leaf;
  unordered_map<char, Trie *> child;
  Trie()
  {
    leaf = false;
  }
};
class Solution
{
  Trie *root;

public:
  Solution()
  {
    root = new Trie();
  }
  void insert(string word)
  {
    Trie *temp = root;

    for (int i = 0; i < word.length(); i++)
    {
      if (temp->child.find(word[i]) == temp->child.end())
      {
        temp->child[word[i]] = new Trie();
      }
      temp = temp->child[word[i]];
    }
    temp->leaf = true;
  }

  int ways(int start, string &s, vector<int> &dp)
  {
    if (start >= s.length())
    {
      return true;
    }

    if (dp[start] != -1)
      return dp[start];

    int ans = 0;
    Trie *temp = root;

    for (int i = start; i < s.length(); i++)
    {
      char ch = s[i];
      if (temp->child.find(ch) == temp->child.end())
      {
        break;
      }

      if (temp->child.find(ch) != temp->child.end())
      {
        temp = temp->child[ch];
        if (temp->leaf && ways(i + 1, s, dp))
        {
          ans = 1;
          dp[start] = 1;
          return dp[start];
        }
      }
    }

    return dp[start] = ans;
  }
  bool wordBreak(string s, vector<string> &wordDict)
  {
    int n = wordDict.size();
    for (int i = 0; i < n; i++)
    {
      insert(wordDict[i]);
    }

    vector<int> dp(s.length() + 5, -1);
    int ans = ways(0, s, dp);
    return ans;
  }
};
```

### Solution - 6,7,8,9

```java



/*
 SOLUTION 1: bfs
    Idea is to try to chop off prefix of s that is in the dict
    enqueue the left-over of each chop off
    if there is a time the left over happens to be in the dict as well
        we know word is breakable, b/c all the previous chops are all in the dict
    otherwise the original world is not breakable.

    we can use a set to store all the leftovers that we have tried, to avoid enqueue the
    same leftover multiple times.

*/
public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        int index = 0;
        Queue<String> queue = new LinkedList<String>();
        queue.offer(s);
        Set<String> visited = new HashSet<String>();
        while(!queue.isEmpty()){
            String candidate = queue.poll();
            if(wordDict.contains(candidate)) return true;
            for(int i = 0; i < candidate.length(); i++){
                String chop = candidate.substring(0,i);
                String next = candidate.substring(i, candidate.length());
                if(!visited.contains(next) && wordDict.contains(chop)){
                    next = candidate.substring(i, candidate.length());
                    queue.offer(next);
                    visited.add(next);
                }
            }
        }
        return false;
    }
}

/* SOLUTION 2: dfs
    use a set to record the substring (i, s.length) that is not breakable
    start from the front, try to see if the substring (0,i) is in the dict,
    if so, recursively check if there is a way to break (i, s.length)


public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        if(s.length() == 0) return false;
        Set<Integer> set = new HashSet<Integer>();
        return helper(s, 0, set, wordDict);
    }

    private boolean helper(String s, int index, Set<Integer> set, Set<String> dict){
        if(index == s.length()) return true;
        for(int i = index + 1; i <= s.length(); i++){
            if(set.contains(i)) continue;
            if(dict.contains(s.substring(index, i))){
                 if (helper(s, i, set, dict)) return true;
                 set.add(i);
            }
        }
        return false;
    }
}


/* SOLUTION 3: dp
    dp[i] represents if substring (0,i) is breakable.
    for each longer substring, we just need to check

public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        if(s.length() == 0) return false;
        boolean[] breakable = new boolean[s.length() + 1];
        breakable[0] = true;
        for(int i = 1; i <= s.length(); i++){
            for(int j = 0; j < i; j++){
                if(breakable[j] && wordDict.contains(s.substring(j, i))){
                    breakable[i] = true;
                    break;
                }
            }
        }
        //for(boolean b : breakable) System.out.print(b + ", ");
        return breakable[s.length()];
    }
}
*/

/* SOLUTION 4: TRIE + MAP


public class Solution {
    public boolean wordBreak(String s, Set<String> wordDict) {
        Trie trie = new Trie();
        for(String d : wordDict){
            trie.insert(d);
        }
        List<String> prefix = findPrefix(trie, s);
        Map<String, Boolean> map = new HashMap<String, Boolean>();
        for(String split : prefix){
            if(canBeSplitted(trie, s.replaceFirst(split, ""), map)){
                map.put(split, true);
                return true;
            }
        }
        return false;
    }

    private boolean canBeSplitted(Trie root, String input, Map<String, Boolean> map){
        if(map.containsKey(input)) return map.get(input);
        if(root.search(input) || input.length() == 0) return true;
        List<String> prefix = findPrefix(root, input);
        for(String s : prefix){
            String copy = new String(input);
            if(canBeSplitted(root, copy.replaceFirst(s, ""), map)){
                map.put(input, true);
                return true;
            }
        }
        map.put(input, false);
        return false;
    }

    private List<String> findPrefix(Trie root, String input){
        char[] split = input.toCharArray();
        List<String> result = new ArrayList<String>();
        TrieNode pointer = root.root;
        for(int i = 0; i < split.length; i++){
            pointer = pointer.next[split[i] - 'a'];
            if(pointer == null) break;
            if(pointer.word != null) result.add(pointer.word);
        }
        return result;
    }

    class TrieNode {

        public String word;
        public TrieNode[] next;
        public TrieNode() {
            word = null;
            next = new TrieNode[26];
        }
    }

    public class Trie {
        private TrieNode root;

        public Trie() {
            root = new TrieNode();
        }

        public void insert(String word) {
            TrieNode pointer = root;
            for(int i = 0; i < word.length(); i++){
                if(pointer.next[word.charAt(i) - 'a'] == null){
                    pointer.next[word.charAt(i) - 'a'] = new TrieNode();
                }
                pointer = pointer.next[word.charAt(i) - 'a'];
            }
            pointer.word = word;
        }

        public boolean search(String word) {
            TrieNode pointer = root;
            if(root.word != null && root.word.equals(word)) return true;
            for(int i = 0; i < word.length(); i++){
                if(pointer.next[word.charAt(i) - 'a'] == null) return false;
                pointer = pointer.next[word.charAt(i) - 'a'];
            }
            if(pointer.word == null) return false;
            return pointer.word.equals(word);
        }

    }

}*/
```
