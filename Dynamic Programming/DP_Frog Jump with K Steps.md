# Minimal Cost

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Minimal Cost](#minimal-cost)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
  - [Code](#code)
    - [C++ Implementations](#c-implementations)
      - [Recursive Solution](#recursive-solution)
      - [Memoization Solution](#memoization-solution)
      - [Tabulation Solution](#tabulation-solution)
    - [Java Implementations](#java-implementations)
      - [Recursive Solution](#recursive-solution-1)
      - [Memoization Solution](#memoization-solution-1)
      - [Tabulation Solution](#tabulation-solution-1)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [Space Optimization](#space-optimization)
      - [Updated Code](#updated-code)
      - [Explanation](#explanation)
      - [Complexity Analysis](#complexity-analysis-1)
      - [Example Walkthrough](#example-walkthrough)
        - [Input](#input)
        - [Execution](#execution)
        - [Output](#output)

---

## Introduction

The **Minimal Cost** problem involves finding the minimum cost for Geek to reach the last stone. From any stone \( i \), Geek can jump to stones \( i+1, i+2, \dots, i+k \). The cost of jumping from stone \( i \) to stone \( j \) is the absolute difference between their heights, \( |arr[i] - arr[j]| \).

---

## Problem Description

**Input:**

- An integer \( k \), the maximum number of stones Geek can jump over.
- An array `arr[]` of size \( n \), where `arr[i]` represents the height of the \( i \)-th stone.

**Output:**

- An integer representing the minimum cost to reach the last stone.

---

## Examples

### Example 1

**Input:**

```bash
k = 3, arr[] = [10, 30, 40, 50, 20]
```

**Output:**

```bash
30
```

**Explanation:**

- Geek follows the path: 1 → 2 → 5.
- Cost:
  - \( |10 - 30| = 20 \)
  - \( |30 - 20| = 10 \)
- Total cost = \( 20 + 10 = 30 \).

---

### Example 2

**Input:**

```bash
k = 1, arr[] = [10, 20, 10]
```

**Output:**

```bash
20
```

**Explanation:**

- Geek follows the path: 1 → 2 → 3.
- Cost:
  - \( |10 - 20| = 10 \)
  - \( |20 - 10| = 10 \)
- Total cost = \( 10 + 10 = 20 \).

---

## Constraints

- \( 1 \leq arr.size() \leq 10^4 \)
- \( 1 \leq k \leq 100 \)
- \( 1 \leq arr[i] \leq 10^4 \)

---

## Approach

### Recursive Approach

- **Idea:** Use recursion to compute the minimum cost to reach each stone, considering all possible jumps up to \( k \).
- **Base Case:**
  - If \( i = 0 \), cost is \( 0 \).
- **Recursive Relation:**
  - \( \text{cost}(i) = \min_{j=1}^{k} (\text{cost}(i-j) + |arr[i] - arr[i-j]|) \), where \( i-j \geq 0 \).

---

### Memoization Approach

- **Idea:** Use an array `dp[]` to store the minimum cost for each stone and avoid redundant calculations.
- **Transition:**
  - Same as the recursive approach, but store results in `dp[]` to reuse in subsequent calls.

---

### Tabulation Approach

- **Idea:** Use a `dp[]` array to iteratively compute the minimum cost for each stone.
- **Steps:**
  1. Initialize `dp[0] = 0` (no cost to start).
  2. For each stone \( i \) from 1 to \( n-1 \), calculate:
     - \( dp[i] = \min_{j=1}^{k} (dp[i-j] + |arr[i] - arr[i-j]|) \), where \( i-j \geq 0 \).

---

## Code

### C++ Implementations

#### Recursive Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursive_solution(int index, int k, vector<int>& arr) {
        if (index == 0) return 0;

        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int cost = recursive_solution(index - j, k, arr) + abs(arr[index] - arr[index - j]);
                minCost = min(minCost, cost);
            }
        }
        return minCost;
    }
};
```

---

#### Memoization Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoization(int index, int k, vector<int>& arr, vector<int>& dp) {
        if (index == 0) return 0;
        if (dp[index] != -1) return dp[index];

        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int cost = memoization(index - j, k, arr, dp) + abs(arr[index] - arr[index - j]);
                minCost = min(minCost, cost);
            }
        }
        return dp[index] = minCost;
    }
};
```

---

#### Tabulation Solution

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tabulation(int n, int k, vector<int>& arr) {
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = min(dp[i], dp[i - j] + abs(arr[i] - arr[i - j]));
                }
            }
        }
        return dp[n - 1];
    }
};
```

---

### Java Implementations

#### Recursive Solution

```java
import java.util.*;

class Solution {
    public int recursiveSolution(int index, int k, int[] arr) {
        if (index == 0) return 0;

        int minCost = Integer.MAX_VALUE;
        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int cost = recursiveSolution(index - j, k, arr) + Math.abs(arr[index] - arr[index - j]);
                minCost = Math.min(minCost, cost);
            }
        }
        return minCost;
    }
}
```

---

#### Memoization Solution

```java
import java.util.*;

class Solution {
    public int memoization(int index, int k, int[] arr, int[] dp) {
        if (index == 0) return 0;
        if (dp[index] != -1) return dp[index];

        int minCost = Integer.MAX_VALUE;
        for (int j = 1; j <= k; j++) {
            if (index - j >= 0) {
                int cost = memoization(index - j, k, arr, dp) + Math.abs(arr[index] - arr[index - j]);
                minCost = Math.min(minCost, cost);
            }
        }
        return dp[index] = minCost;
    }
}
```

---

#### Tabulation Solution

```java
import java.util.*;

class Solution {
    public int tabulation(int n, int k, int[] arr) {
        int[] dp = new int[n];
        Arrays.fill(dp, Integer.MAX_VALUE);
        dp[0] = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    dp[i] = Math.min(dp[i], dp[i - j] + Math.abs(arr[i] - arr[i - j]));
                }
            }
        }
        return dp[n - 1];
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Recursive Approach:** \( O(k^n) \) (exponential due to overlapping subproblems).
- **Memoization Approach:** \( O(k \cdot n) \) (each state is computed once).
- **Tabulation Approach:** \( O(k \cdot n) \) (each state is computed iteratively).

### Space Complexity

- **Recursive Approach:** \( O(n) \) (call stack).
- **Memoization Approach:** \( O(n) \) (call stack + `dp[]`).
- **Tabulation Approach:** \( O(n) \) (`dp[]` array).

---

## How to Run the Code

1. Save the respective C++ or Java implementation.
2. Compile and run with the respective command:
   - **C++:**

     ```bash
     g++ -std=c++17 solution.cpp -o solution
     ./solution
     ```

   - **Java:**

     ```bash
     javac Solution.java
     java Solution
      ```

## Other Solutions

### Space Optimization

To optimize space complexity, we can maintain a **list of the last `k` elements** instead of the entire `dp` array. This allows us to compute the result using only \( O(k) \) space, as only the last `k` entries are relevant for any computation at index `i`.

Here's how the space-optimized solution looks:

#### Updated Code

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// } Driver Code Ends

class Solution {
public:
    // Space Optimized Tabulation Solution
    int minimizeCost(int k, vector<int>& arr) {
        int n = arr.size();
        deque<int> dp(k, INT_MAX); // Maintain a deque for the last `k` entries
        dp[0] = 0;                // Cost to reach the first index is 0

        for (int i = 1; i < n; i++) {
            int currentMin = INT_MAX;

            // Compute minimum cost for the current index
            for (int j = 1; j <= k; j++) {
                if (i - j >= 0) {
                    currentMin = min(currentMin, dp[(i - j) % k] + abs(arr[i] - arr[i - j]));
                }
            }

            // Update the deque with the current result
            dp[i % k] = currentMin;
        }

        return dp[(n - 1) % k];
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
```

---

#### Explanation

1. **Key Idea**:
   - Instead of maintaining a full `dp` array of size \( n \), only the last `k` values are kept in a deque (cyclic array).
   - Each `dp[i % k]` corresponds to the cost of reaching index \( i \).

2. **How It Works**:
   - At each index `i`, compute the minimum cost using only the last `k` values from `dp`.
   - Update `dp[i % k]` with the computed cost.

3. **Space Optimization**:
   - Instead of \( O(n) \), this reduces the space complexity to \( O(k) \).

---

#### Complexity Analysis

1. **Time Complexity**:
   - Outer loop runs \( O(n) \) for \( n \) elements.
   - Inner loop runs \( O(k) \) for each index.
   - Total: \( O(n \cdot k) \).

2. **Space Complexity**:
   - Only a deque of size \( k \) is maintained.
   - Total: \( O(k) \).

---

#### Example Walkthrough

##### Input

- \( k = 2 \)
- \( arr = [10, 30, 40, 50] \)

##### Execution

- Initialize `dp = [0, INT_MAX]`.
- Iterate through each index \( i \), updating the deque to store only the last `k` results.
- Compute the minimum cost dynamically.

##### Output

- The result is the minimum cost to reach the last index.

This approach maintains the same time complexity as the full `dp` array but significantly reduces the space usage, making it suitable for memory-constrained environments.

---
