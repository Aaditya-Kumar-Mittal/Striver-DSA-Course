# Subset Sum Problem

## Table of Contents

- [Subset Sum Problem](#subset-sum-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Solution](#recursive-solution)
    - [Memoization](#memoization)
    - [Tabulation](#tabulation)
    - [Space-Optimized Tabulation](#space-optimized-tabulation)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Submission](#my-submission)

---

## Introduction

The Subset Sum Problem is a classical dynamic programming problem that asks whether there exists a subset of a given array of positive integers such that the sum of its elements equals a given target value.

---

## Problem Description

Given an array of positive integers `arr[]` and a value `target`, determine if there is a subset of the array with a sum equal to `target`.

### Examples

#### Example 1

**Input:**

```bash
arr[] = [3, 34, 4, 12, 5, 2], target = 9
```

**Output:**

```bash
true
```

**Explanation:**
The subset `{4, 3, 2}` has a sum equal to `9`.

#### Example 2

**Input:**

```bash
arr[] = [3, 34, 4, 12, 5, 2], target = 30
```

**Output:**

```bash
false
```

**Explanation:**
No subset in the array sums up to `30`.

#### Example 3

**Input:**

```bash
arr[] = [1, 2, 3], target = 6
```

**Output:**

```bash
true
```

**Explanation:**
The entire array `{1, 2, 3}` forms a subset with sum `6`.

### Constraints

- `1 <= arr.size() <= 200`
- `1 <= arr[i] <= 200`
- `1 <= target <= 40,000`

---

## Approach

### Recursive Solution

The recursive approach explores all subsets of the array. At each step, we have two choices:

- Include the current element in the subset and reduce the target.
- Exclude the current element and move to the next.

**Base Cases:**

1. If the target is `0`, return `true`.
2. If the array is exhausted (index = 0), check if the last element equals the target.

### Memoization

To optimize the recursive solution, we use memoization. We store results of subproblems in a 2D `dp` table where `dp[i][j]` indicates whether a subset of the first `i` elements has a sum equal to `j`.

### Tabulation

In the tabulation approach, we build the `dp` table iteratively:

1. Initialize `dp[i][0]` to `true` because a sum of `0` can always be achieved with an empty subset.
2. For each element and each possible sum, calculate `dp[i][j]` using the results of the previous row.

### Space-Optimized Tabulation

Instead of using a 2D `dp` table, we use two 1D arrays to save space. We maintain the current and previous rows and update them iteratively.

---

## Code

### C++ Implementation

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    // Recursive Solution
    bool recursive_solution(int index, int target, vector<int>& arr) {
        if (target == 0) return true;
        if (index == 0) return arr[0] == target;

        bool not_take = recursive_solution(index - 1, target, arr);
        bool take = false;
        if (target >= arr[index]) {
            take = recursive_solution(index - 1, target - arr[index], arr);
        }

        return take || not_take;
    }

    // Memoization Solution
    bool memoization(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (index == 0) return arr[0] == target;

        if (dp[index][target] != -1) return dp[index][target];

        bool not_take = memoization(index - 1, target, arr, dp);
        bool take = false;
        if (target >= arr[index]) {
            take = memoization(index - 1, target - arr[index], arr, dp);
        }

        return dp[index][target] = take || not_take;
    }

    // Tabulation Solution
    bool tabulation(int n, int target, vector<int>& arr) {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (arr[0] <= target) dp[0][arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool not_take = dp[i - 1][j];
                bool take = false;
                if (j >= arr[i]) take = dp[i - 1][j - arr[i]];
                dp[i][j] = take || not_take;
            }
        }

        return dp[n - 1][target];
    }

    // Space-Optimized Tabulation
    bool tabulation_optimized(int n, int target, vector<int>& arr) {
        vector<bool> dp(target + 1, false), current(target + 1, false);

        dp[0] = true;
        current[0] = true;
        if (arr[0] <= target) dp[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool not_take = dp[j];
                bool take = false;
                if (j >= arr[i]) take = dp[j - arr[i]];
                current[j] = take || not_take;
            }
            dp = current;
        }

        return dp[target];
    }

public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        return tabulation_optimized(n, target, arr);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
```

---

## Complexity Analysis

- **Recursive Solution:**

  - Time Complexity: \(O(2^n)\)
  - Space Complexity: \(O(n)\) (recursion stack)

- **Memoization:**

  - Time Complexity: \(O(n \times target)\)
  - Space Complexity: \(O(n \times target) + O(n)\) (DP array + recursion stack)

- **Tabulation:**

  - Time Complexity: \(O(n \times target)\)
  - Space Complexity: \(O(n \times target)\)

- **Space-Optimized Tabulation:**
  - Time Complexity: \(O(n \times target)\)
  - Space Complexity: \(O(target)\)

---

## How to Run the Code

1. **Compile:**

   ```bash
   g++ -o subset_sum subset_sum.cpp
   ```

2. **Run:**

   ```bash
   ./subset_sum
   ```

3. **Input Format:**

   - First line: Number of test cases `t`
   - For each test case:
     - Array elements (space-separated)
     - Target sum

4. **Example Input:**

   ```bash
   2
   3 34 4 12 5 2
   9
   3 34 4 12 5 2
   30
   ```

5. **Example Output:**

   ```bash
   true
   ~
   false
   ```

## Other Solutions

### My Submission

```cpp
//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
    // Recursive Solution
    bool recursive_solution(int index, int target, vector<int>& arr) {
        // Base Cases
        // 1 -> If target is achieved
        if (target == 0) return true;

        // 2 -> If index is exhausted
        if (index == 0) return arr[0] == target;

        // Explore Possibilities
        bool not_take = recursive_solution(index - 1, target, arr);

        bool take = false;

        if (target >= arr[index]) {
            take = recursive_solution(index - 1, target - arr[index], arr);
        }

        return take || not_take;
    }

    // Memoization Solution
    bool memoization(int index, int target, vector<int>& arr, vector<vector<int>>& dp) {
        // Base Cases
        if (target == 0) return true;
        if (index == 0) return arr[0] == target;

        // Check if already computed
        if (dp[index][target] != -1) return dp[index][target];

        // Explore Possibilities
        bool not_take = memoization(index - 1, target, arr, dp);

        bool take = false;
        if (target >= arr[index]) {
            take = memoization(index - 1, target - arr[index], arr, dp);
        }

        return dp[index][target] = take || not_take;
    }

    // Tabulation Solution
    bool tabulation(int n, int target, vector<int>& arr) {
        vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

        // Base Cases
        for (int i = 0; i < n; i++) dp[i][0] = true; // Target 0 is achievable with any index
        if (arr[0] <= target) dp[0][arr[0]] = true; // Handle arr[0] for index 0

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool not_take = dp[i - 1][j];
                bool take = false;

                if (j >= arr[i]) take = dp[i - 1][j - arr[i]];

                dp[i][j] = take || not_take;
            }
        }

        return dp[n - 1][target];
    }

    // Tabulation Solution Space Optimized
    bool tabulation_optimized(int n, int target, vector<int>& arr) {

        vector<bool> dp(target+1, false), current(target+1, false);

        dp[0] = true;
        current[0] = true;
        dp[arr[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= target; j++) {
                bool not_take = dp[j];
                bool take = false;

                if (j >= arr[i]) take = dp[j - arr[i]];

               current[j] = take || not_take;
            }
            dp = current;
        }

        return dp[target];
    }

public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();

        // Uncomment this line to use the recursive solution
        // return recursive_solution(n - 1, target, arr);

        // Memoization
        // vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        // return memoization(n - 1, target, arr, dp);

        return tabulation_optimized(n, target, arr);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
```
