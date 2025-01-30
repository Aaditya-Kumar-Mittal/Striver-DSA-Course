# Partitions with Given Difference

## Table of Contents

- [Partitions with Given Difference](#partitions-with-given-difference)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursion + Memoization](#recursion--memoization)
    - [Tabulation](#tabulation)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)

## Introduction

The problem asks to partition an array `arr[]` into two subsets such that each element belongs to only one subset. We need to find the number of partitions where the difference between the sum of the two subsets equals a given value `d`, and one subset has a sum greater than or equal to the other.

## Problem Description

Given an array `arr[]`, partition it into two subsets such that:

- The sum of elements in one subset is `sum1`.
- The sum of elements in the other subset is `sum2`.
- The absolute difference between `sum1` and `sum2` is equal to a given difference `d`.

We need to return the count of such partitions where the difference between `sum1` and `sum2` equals `d`.

### Examples

**Example 1:**

- Input: `arr[] = [5, 2, 6, 4], d = 3`
- Output: `1`
- Explanation: There is only one possible partition: `{6, 4}` and `{5, 2}`. The difference between the subset sums is: `(6 + 4) - (5 + 2) = 3`.

**Example 2:**

- Input: `arr[] = [1, 1, 1, 1], d = 0`
- Output: `6`
- Explanation: We can choose two 1's from indices {0, 1}, {0, 2}, {0, 3}, {1, 2}, {1, 3}, {2, 3} and put them in `sum1` while the remaining two 1's go into `sum2`. There are 6 ways to partition the array.

**Example 3:**

- Input: `arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11`
- Output: `2`

### Constraints

- `1 <= arr.size() <= 500`
- `0 <= d <= 500`
- `0 <= arr[i] <= 6`

## Approach

The problem can be broken down into two main approaches for finding the number of ways to partition the array:

### Recursion + Memoization

We solve the problem recursively by checking whether the element is included in the subset with sum `sum1` or the subset with sum `sum2`. Using memoization, we avoid recalculating the result for already computed subproblems.

### Tabulation

We can use dynamic programming to tabulate all possible ways to partition the array such that the sum of the elements of one subset equals `(totalSum - d) / 2`. This approach builds the solution iteratively.

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int mod = 1e9;

        int tabulation_optimized(vector<int> &arr, int target) {
            int n = arr.size();
            vector<int> dp(target + 1, 0), current(target + 1, 0);
            dp[0] = 1;

            if (arr[0] == 0) dp[0] = 2;  // Special case for 0
            if (arr[0] != 0 && arr[0] <= target) dp[arr[0]] = 1;

            for (int i = 1; i < n; i++) {
                for (int sum = 0; sum <= target; sum++) {
                    int notpick = dp[sum];
                    int pick = (arr[i] <= sum) ? dp[sum - arr[i]] : 0;
                    current[sum] = (notpick + pick) % mod;
                }
                dp = current;  // Update dp for the next iteration
            }
            return dp[target];
        }

        int countPartitions(vector<int>& arr, int d) {
            int n = arr.size();
            int totalSum = accumulate(arr.begin(), arr.end(), 0);

            if (totalSum - d < 0 || (totalSum - d) % 2) return 0;

            return tabulation_optimized(arr, (totalSum - d) / 2);
        }
};

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {
        int d;
        vector<int> arr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;
        cout << "~\n";
    }
    return 0;
}
```

### Java Implementation

```java
import java.util.*;

class Solution {
    public int mod = (int) 1e9;

    public int tabulationOptimized(int[] arr, int target) {
        int n = arr.length;
        int[] dp = new int[target + 1];
        int[] current = new int[target + 1];
        dp[0] = 1;

        if (arr[0] == 0) dp[0] = 2;  // Special case for 0
        if (arr[0] != 0 && arr[0] <= target) dp[arr[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int notpick = dp[sum];
                int pick = (arr[i] <= sum) ? dp[sum - arr[i]] : 0;
                current[sum] = (notpick + pick) % mod;
            }
            dp = current.clone();  // Update dp for the next iteration
        }
        return dp[target];
    }

    public int countPartitions(int[] arr, int d) {
        int n = arr.length;
        int totalSum = 0;
        for (int num : arr) totalSum += num;

        if (totalSum - d < 0 || (totalSum - d) % 2 != 0) return 0;

        return tabulationOptimized(arr, (totalSum - d) / 2);
    }
}
```

## Complexity Analysis

### Time Complexity

- **Tabulation Approach:** The time complexity of the tabulation approach is \(O(n \times \text{target})\), where `n` is the size of the array and `target` is the value `(totalSum - d) / 2`.

### Space Complexity

- **Tabulation Approach:** The space complexity is \(O(\text{target})\) as we only store one array of size `target+1` to store the results.

## How to Run the Code

### For C++

1. Ensure you have a C++ compiler such as `g++`.
2. Compile the code: `g++ -o partitions partitions.cpp`
3. Run the compiled program: `./partitions`

### For Java

1. Ensure you have the Java Development Kit (JDK) installed.
2. Compile the code: `javac Solution.java`
3. Run the compiled program: `java Solution`
