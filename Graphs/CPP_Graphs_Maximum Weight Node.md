# Maximum Weight Node

## Table of Contents

- [Maximum Weight Node](#maximum-weight-node)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
  - [Code Implementations](#code-implementations)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [C++](#c)
    - [Java](#java)

---

## Introduction

This problem involves a maze with `n` cells connected by unidirectional doors (like valves). Each cell may have multiple entry points but no more than one exit point.

Your task is to find the maximum weight node. The weight of a cell `i` is the sum of all indices of the cells that have `i` as their exit point. If multiple cells have the same maximum weight, the cell with the highest index should be returned.

---

## Problem Description

1. You are given an array `exits[]` of size `n`, where:
   - `exits[i]` represents the exit point of the `i-th` cell.
   - If `exits[i] = -1`, the `i-th` cell does not have an exit.
2. The weight of a cell `i` is the sum of the indices of cells pointing to it.

Objective: Find the index of the cell with the maximum weight. If there is a tie, return the cell with the highest index.

---

## Examples

### Example 1

Input:  
`exits[] = [2, 0, -1, 2]`  
Output:  
`2`

Explanation:

- `0` points to `2`, weight of `2` = `0`.
- `1` points to `0`, weight of `0` = `1`.
- `3` points to `2`, weight of `2` += `3`.

Weights of cells:

- Cell `0`: 1
- Cell `1`: 0
- Cell `2`: 0 + 3 = 3
- Cell `3`: 0

Cell `2` has the maximum weight.

---

### Example 2

Input:  
`exits[] = [-1]`  
Output:  
`0`

Explanation:  
There is only one cell, so its weight is `0`.

---

## Constraints

1. \( 1 \leq n \leq 10^5 \)
2. \( -1 \leq \text{exits}[i] < n \)
3. \( \text{exits}[i] \neq i \) (a cell cannot point to itself).

---

## Approach

The problem can be solved efficiently using the following steps:

1. Initialize a Weight Array: Create a temporary array `weights` of size `n`, initialized to `0`.
2. Iterate Through `exits[]`: For each cell `i`, if `exits[i] != -1`, add `i` to `weights[exits[i]]`.
3. Find Maximum Weight: Traverse the `weights` array from right to left to find the cell with the maximum weight. Right-to-left traversal ensures that ties are resolved in favor of the cell with the highest index.

---

## Code Implementations

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWeightCell(vector<int> &exits) {
        int n = exits.size();
        vector<int> weights(n, 0);

        // Calculate weights for each cell
        for (int i = 0; i < n; i++) {
            if (exits[i] != -1) {
                weights[exits[i]] += i;
            }
        }

        // Find the cell with the maximum weight
        int maxWeight = 0, maxNode = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (weights[i] > maxWeight) {
                maxWeight = weights[i];
                maxNode = i;
            }
        }

        return maxNode;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> exits(n);
        for (int i = 0; i < n; i++) {
            cin >> exits[i];
        }

        Solution solution;
        cout << solution.maxWeightCell(exits) << endl;
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    public int maxWeightCell(int[] exits) {
        int n = exits.length;
        int[] weights = new int[n];

        // Calculate weights for each cell
        for (int i = 0; i < n; i++) {
            if (exits[i] != -1) {
                weights[exits[i]] += i;
            }
        }

        // Find the cell with the maximum weight
        int maxWeight = 0, maxNode = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (weights[i] > maxWeight) {
                maxWeight = weights[i];
                maxNode = i;
            }
        }

        return maxNode;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();
            int[] exits = new int[n];
            for (int i = 0; i < n; i++) {
                exits[i] = sc.nextInt();
            }

            Solution solution = new Solution();
            System.out.println(solution.maxWeightCell(exits));
        }
    }
}
```

---

## Complexity Analysis

- Time Complexity: \( O(n) \)
  - One pass to compute weights.
  - One pass to find the maximum weight.
- Space Complexity: \( O(n) \)
  - For the `weights` array.

---

## How to Run the Code

### C++

1. Save the code in a file named `MaxWeightNode.cpp`.
2. Compile using `g++ MaxWeightNode.cpp -o MaxWeightNode`.
3. Run with `./MaxWeightNode`.

### Java

1. Save the code in a file named `MaxWeightNode.java`.
2. Compile using `javac MaxWeightNode.java`.
3. Run with `java MaxWeightNode`
