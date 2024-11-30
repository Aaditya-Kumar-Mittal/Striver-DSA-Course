# Word Search Problem

## Table of Contents

- [Word Search Problem](#word-search-problem)
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
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2](#solution---2)

---

## Introduction

The problem involves determining if a given word can be found in a 2D grid of characters. The word must be formed using sequentially adjacent cells, where adjacency includes horizontal and vertical neighbors. A cell may not be reused in a single word path.

---

## Problem Description

### Input

- `board`: An `m x n` 2D grid of characters.
- `word`: A string to search in the grid.

### Output

- `true`: If the word exists in the grid.
- `false`: Otherwise.

---

### Examples

#### Example 1

**Input:**

```plaintext
board = [["A","B","C","E"],
         ["S","F","C","S"],
         ["A","D","E","E"]],
word = "ABCCED"
```

**Output:**

```plaintext
true
```

---

#### Example 2

**Input:**

```plaintext
board = [["A","B","C","E"],
         ["S","F","C","S"],
         ["A","D","E","E"]],
word = "SEE"
```

**Output:**

```plaintext
true
```

---

#### Example 3

**Input:**

```plaintext
board = [["A","B","C","E"],
         ["S","F","C","S"],
         ["A","D","E","E"]],
word = "ABCB"
```

**Output:**

```plaintext
false
```

---

### Constraints

- `1 ≤ m, n ≤ 6`
- `1 ≤ word.length ≤ 15`
- `board` and `word` consist of only lowercase and uppercase English letters.

---

## Approach

### Key Observations

1. **Depth-First Search (DFS):**

   - For each cell, start a DFS to check if the word can be constructed.
   - Mark visited cells temporarily to avoid revisiting.

2. **Pruning:**

   - Stop exploring a path if it doesn't match the current character in `word`.

3. **Directions:**
   - Define movement in four possible directions: up, down, left, and right.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    // Helper function to perform DFS
    bool find(vector<vector<char>>& board, int i, int j, int m, int n, int idx, string& word) {
        if (idx == word.length())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word[idx])
            return false;

        char temp = board[i][j];
        board[i][j] = '$'; // Mark cell as visited

        for (auto& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, m, n, idx + 1, word))
                return true;
        }

        board[i][j] = temp; // Backtrack
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, m, n, 0, word))
                    return true;
            }
        }
        return false;
    }
};
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    private final int[][] directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    private boolean find(char[][] board, int i, int j, int m, int n, int idx, String word) {
        if (idx == word.length())
            return true;

        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] == '$' || board[i][j] != word.charAt(idx))
            return false;

        char temp = board[i][j];
        board[i][j] = '$'; // Mark cell as visited

        for (int[] dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (find(board, new_i, new_j, m, n, idx + 1, word))
                return true;
        }

        board[i][j] = temp; // Backtrack
        return false;
    }

    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0) && find(board, i, j, m, n, 0, word))
                    return true;
            }
        }
        return false;
    }
}
```

---

## Complexity Analysis

1. **Time Complexity**:

   - For each cell `(i, j)`:
     - Perform DFS for up to `O(word.length)` steps.
   - Total: `O(m * n * 4^word.length)` (pruned by constraints).

2. **Space Complexity**:
   - `O(word.length)` for recursive call stack during DFS.

This solution uses DFS with backtracking to efficiently search for the word in the grid while adhering to the constraints.

## Other Solutions

### Solution - 1

```cpp
class Solution {
public:
    /*
        time comple
    */
    bool tryPath(vector<vector<char>>& board, int i, int j, int wi, string& word) {
        if (wi == word.size()) {
            return true;
        }
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
            || board[i][j] != word[wi])
            {
                return false;
        }
        char c = board[i][j];
        board[i][j] = '#'; // make the char at i, j = # indicating its visited
        bool res = (tryPath(board, i-1, j, wi+1, word) ||
                    tryPath(board, i+1, j, wi+1, word) ||
                    tryPath(board, i, j-1, wi+1, word) ||
                    tryPath(board, i, j+1, wi+1, word));
        board[i][j] = c; // set the char at i, j make to original char.
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if (word.size() > m * n) return false;

        unordered_map<char, int> boardCount;
        for(const auto& row : board) {
            for(char c : row) {
                boardCount[c]++;
            }
        }

        /*
            if occurances of a char in board is less than occurances of that char in
            the given word then we can't form the given word.
        */
        unordered_map<char, int> wordCount;
        for(char c : word) {
            wordCount[c]++;
            if(boardCount[c] < wordCount[c]){
                return false;
            }
        }
        /*
            sometime reverse can help if board has many occurances of starting char
            of given word but fewer for last char. So having less starting points means
            less paths to explore.
        */
        if(boardCount[word[0]] > boardCount[word.back()])
            reverse(word.begin(), word.end());

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (tryPath(board, i, j, 0, word) == true) return true;
            }
        }
        return false;
    }
};
```

### Solution - 2

```cpp
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        // Space Complexity: O(1) because we only have unique lower and upper English letters so bounded!
        std::unordered_map<char, int> board_freq_cnt;

        // Time Complexity: O(mn)
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                board_freq_cnt[board[row][col]]++;
            }
        }

        // Space Complexity: O(1) because we only have unique lower and upper English letters so bounded!
        std::unordered_map<char, int> word_freq_cnt;

        // Time Complexity: O(L)
        for (const auto& letter : word)
        {
            word_freq_cnt[letter]++;
        }
        // TimeCompelxity for constructing the freq cnts: O(mn + L) < O(mn*4^L) so we are good
        // Now for each letter of the word check if there are enough letters in the board
        // Time complexity of this for loop is also O(1)
        for (const auto& [letter, letter_cnt] : word_freq_cnt)
        {
            if (board_freq_cnt[letter] < letter_cnt) return false;
        }

        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // this b
                if (existDFS(board, row, col, m, n, 0, word)) return true;
            }
        }

        return false;
    }

private:
    bool existDFS(std::vector<std::vector<char>>& board, int row, int col, int m, int n, int idx, const std::string& word)
    {
        if ((row < 0 || row >= m) || (col < 0 || col >= n) || (board[row][col] != word[idx])) return false;
        if (idx == word.size() - 1) return true;
        // Mark cell with a non letter character to avoid having a vector visited
        char temp = board[row][col];
        board[row][col] = '#';

        bool is_found = existDFS(board, row - 1, col, m, n, idx + 1, word) ||
        existDFS(board, row + 1, col, m, n, idx + 1, word) ||
        existDFS(board, row, col - 1, m, n, idx + 1, word) ||
        existDFS(board, row, col + 1, m, n, idx + 1, word);

        // backtrack
        board[row][col] = temp;
        return is_found;
    }
};
```
