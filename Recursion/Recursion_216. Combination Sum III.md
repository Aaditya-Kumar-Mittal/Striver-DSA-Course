# Combination Sum III

## Table of Contents

- [Combination Sum III](#combination-sum-iii)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)

## Introduction

The problem requires finding all valid combinations of `k` numbers that sum up to `n` using numbers from `1` to `9`, ensuring that each number is used at most once. The result should not contain duplicate combinations.

## Problem Description

Given two integers `k` and `n`, find all possible sets of `k` numbers that sum to `n`, with the following conditions:

- Only numbers from `1` to `9` can be used.
- Each number can be used at most once.
- The order of elements in the output does not matter.

### Examples

#### Example 1

**Input:**

```cpp
k = 3, n = 7
```

**Output:**

```cpp
[[1,2,4]]
```

**Explanation:**

- The only valid combination is `[1, 2, 4]` since `1 + 2 + 4 = 7`.

#### Example 2

**Input:**

```cpp
k = 3, n = 9
```

**Output:**

```cpp
[[1,2,6],[1,3,5],[2,3,4]]
```

**Explanation:**

- `[1, 2, 6]`, `[1, 3, 5]`, and `[2, 3, 4]` all sum to `9`.

#### Example 3

**Input:**

```cpp
k = 4, n = 1
```

**Output:**

```cpp
[]
```

**Explanation:**

- The smallest sum using `4` different numbers from `1-9` is `1+2+3+4 = 10`, which is greater than `1`, so no valid combination exists.

### Constraints

- `2 <= k <= 9`
- `1 <= n <= 60`

## Approach

The solution employs **backtracking** to explore all possible combinations:

1. Start with the first number `1` and attempt to build a subset.
2. Either **include** or **exclude** each number, updating the sum and remaining count `k` accordingly.
3. If `k == 0`, check if the sum matches `n`. If yes, add the subset to results.
4. If `k < 0` or sum exceeds `n`, return immediately (pruning unnecessary computation).
5. Use **backtracking** to explore all possible subsets efficiently.

## Detailed Explanation of Code

### C++ Implementation

```cpp
class Solution {
public:
    void solve(int index, int k, int sum, int target, vector<int>& subset,
               vector<vector<int>>& ans) {
        // If k is 0, check if sum equals target
        if (k == 0) {
            if (sum == target) {
                ans.push_back(subset);
            }
            return;
        }

        // Base case: if index exceeds 9, return
        if (index > 9)
            return;

        // If k is less than 0, return
        if (k < 0)
            return;

        // If sum exceeds the target, return
        if (sum > target)
            return;

        // Pick the current element
        sum += index;
        subset.push_back(index);
        solve(index + 1, k - 1, sum, target, subset, ans);

        // Backtracking step
        sum -= index;
        subset.pop_back();

        // Do not pick the current element
        solve(index + 1, k, sum, target, subset, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> subset;
        solve(1, k, 0, n, subset, ans);
        return ans;
    }
};
```

## Complexity Analysis

- **Time Complexity:** `O(2^9)`, since each number has two choices (include/exclude), but pruning reduces actual operations.
- **Space Complexity:** `O(k)`, where `k` is the number of elements in a subset, due to recursion stack.

## How to Run the Code

1. Copy and paste the C++ code into a local IDE or online compiler.
2. Create a `main` function to instantiate the `Solution` class and call `combinationSum3(k, n)` with desired values.
3. Print the returned result to verify correctness.

Example:

```cpp
int main() {
    Solution sol;
    vector<vector<int>> result = sol.combinationSum3(3, 9);
    for (auto& comb : result) {
        for (int num : comb) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
```

This implementation efficiently finds all unique valid subsets using backtracking.
