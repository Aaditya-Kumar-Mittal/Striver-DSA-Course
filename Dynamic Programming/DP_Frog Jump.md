# Frog Jump

## Table of Contents

- [Frog Jump](#frog-jump)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
  - [Examples](#examples)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Constraints](#constraints)
  - [Approach](#approach)
    - [Recursive Approach with Memoization](#recursive-approach-with-memoization)
    - [Dynamic Programming Approach](#dynamic-programming-approach)
    - [Optimized Space Approach](#optimized-space-approach)
  - [Code](#code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [How to Run the Code](#how-to-run-the-code)
    - [C++](#c)
    - [Java](#java)
  - [Other Solutions](#other-solutions)
    - [Using Tabulation](#using-tabulation)
    - [Space Optimization](#space-optimization)

---

## Introduction

The **Frog Jump** problem involves finding the minimum cost for a frog to reach the top of a staircase, where the frog can jump either 1 step or 2 steps at a time. The cost of a jump is the absolute difference in height between the two stairs.

---

## Problem Description

**Input:**

- An array `heights[]` where `heights[i]` represents the height of the \(i\)-th stair.

**Output:**

- An integer representing the minimum total cost for the frog to reach the top of the stairs.

---

## Examples

### Example 1

**Input:**

```bash
heights[] = [20, 30, 40, 20]
```

**Output:**

```bash
20
```

**Explanation:**

- The frog jumps:
  1. From stair 0 to stair 1: Cost = \( |30 - 20| = 10 \)
  2. From stair 1 to stair 3: Cost = \( |20 - 30| = 10 \)
- Total cost = \( 10 + 10 = 20 \).

---

### Example 2

**Input:**

```bash
heights[] = [30, 20, 50, 10, 40]
```

**Output:**

```bash
30
```

**Explanation:**

- The frog jumps:
  1. From stair 0 to stair 2: Cost = \( |50 - 30| = 20 \)
  2. From stair 2 to stair 4: Cost = \( |40 - 50| = 10 \)
- Total cost = \( 20 + 10 = 30 \).

---

## Constraints

- \( 1 \leq \text{height.size()} \leq 10^5 \)
- \( 0 \leq \text{height}[i] \leq 10^4 \)

---

## Approach

### Recursive Approach with Memoization

- Define a recursive function `dp_function(index)` that calculates the minimum cost to reach the \( \text{index} \)-th stair.
- Base case:
  - \( dp[0] = 0 \) (Cost to stay on the first stair is 0).
- Recurrence relation:
  - \( dp[i] = \min(dp[i-1] + |heights[i] - heights[i-1]|, dp[i-2] + |heights[i] - heights[i-2]|) \).

### Dynamic Programming Approach

- Use a `dp` array to store the minimum cost to reach each stair.
- Transition:
  - \( dp[i] = \min(dp[i-1] + |heights[i] - heights[i-1]|, dp[i-2] + |heights[i] - heights[i-2]|) \).

### Optimized Space Approach

- Instead of using an array, store only the last two results:
  - Use two variables `prev1` and `prev2` to represent the last two results.

---

## Code

### C++ Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function with memoization
    int dp_function(int index, vector<int>& dp, vector<int>& height) {
        if (index == 0) return 0;

        if (dp[index] != -1) return dp[index];

        int left = dp_function(index - 1, dp, height) + abs(height[index] - height[index - 1]);

        int right = INT_MAX;
        if (index > 1) {
            right = dp_function(index - 2, dp, height) + abs(height[index] - height[index - 2]);
        }

        return dp[index] = min(left, right);
    }

    // Function to calculate minimum cost
    int minCost(vector<int>& height) {
        int n = height.size();
        vector<int> dp(n + 1, -1);
        return dp_function(n - 1, dp, height);
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }
        Solution obj;
        cout << obj.minCost(heights) << endl;
    }
    return 0;
}
```

---

### Java Implementation

```java
import java.util.*;

class Solution {
    // Recursive function with memoization
    private int dp_function(int index, int[] dp, int[] height) {
        if (index == 0) return 0;

        if (dp[index] != -1) return dp[index];

        int left = dp_function(index - 1, dp, height) + Math.abs(height[index] - height[index - 1]);

        int right = Integer.MAX_VALUE;
        if (index > 1) {
            right = dp_function(index - 2, dp, height) + Math.abs(height[index] - height[index - 2]);
        }

        return dp[index] = Math.min(left, right);
    }

    // Function to calculate minimum cost
    public int minCost(int[] height) {
        int n = height.length;
        int[] dp = new int[n];
        Arrays.fill(dp, -1);
        return dp_function(n - 1, dp, height);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int n = sc.nextInt();
            int[] heights = new int[n];
            for (int i = 0; i < n; i++) {
                heights[i] = sc.nextInt();
            }
            Solution obj = new Solution();
            System.out.println(obj.minCost(heights));
        }
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Recursive with Memoization:** \( O(n) \)
- **Dynamic Programming:** \( O(n) \)
- **Optimized Space:** \( O(n) \)

### Space Complexity

- **Recursive with Memoization:** \( O(n) \) (Call stack + DP array)
- **Dynamic Programming:** \( O(n) \) (DP array)
- **Optimized Space:** \( O(1) \) (Two variables)

---

## How to Run the Code

### C++

1. Save the code to `solution.cpp`.
2. Compile using:

   ```bash
   g++ -std=c++17 -o solution solution.cpp
   ```

3. Run the executable:

   ```bash
   ./solution
   ```

### Java

1. Save the code to `Solution.java`.
2. Compile using:

   ```bash
   javac Solution.java
   ```

3. Run the class:

   ```bash
   java Solution
   ```

## Other Solutions

### Using Tabulation

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int dp_function(int index, vector<int>& dp, vector<int>& height)
    {
        if(index == 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int left = dp_function(index-1, dp, height) + abs(height[index] - height[index-1]);
        
        int right = INT_MAX;
        
        if(index > 1) right = dp_function(index-2, dp, height) + abs(height[index] - height[index-2]);
        
        return dp[index] = min(left, right);
    }
    
    int minCost(vector<int>& height) {
        // Code here
        
        int n = height.size();
        
        vector<int> dp(n, -1);
        
        // int ans = dp_function(n-1, dp, height);
        
        dp[0] = 0;
        
        for(int i = 1 ; i < n ; i++)
        {
            int fStep = dp[i-1] + abs(height[i] - height[i-1]);
            
            int sStep = INT_MAX;
            
            if(i > 1) sStep = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(fStep, sStep);
        }
        
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
```

- **Time Complexity:** \( O(n) \)
- **Space Complexity:** \( O(n) \)

---

### Space Optimization

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int dp_function(int index, vector<int>& dp, vector<int>& height)
    {
        if(index == 0) return 0;
        
        if(dp[index] != -1) return dp[index];
        
        int left = dp_function(index-1, dp, height) + abs(height[index] - height[index-1]);
        
        int right = INT_MAX;
        
        if(index > 1) right = dp_function(index-2, dp, height) + abs(height[index] - height[index-2]);
        
        return dp[index] = min(left, right);
    }
    
    int minCost(vector<int>& height) {
        // Code here
        
        int n = height.size();
        
        // vector<int> dp(n, -1);
        
        // int ans = dp_function(n-1, dp, height);
        
        // dp[0] = 0;
        
        int prev1 = 0, prev2 = 0;
        
        for(int i = 1 ; i < n ; i++)
        {
            int fStep = prev1 + abs(height[i] - height[i-1]);
            
            int sStep = INT_MAX;
            
            if(i > 1) sStep = prev2 + abs(height[i] - height[i-2]);
            
            int curri = min(fStep, sStep);
            
            prev2 = prev1;
            
            prev1 = curri;
        }
        
        return prev1;
    }
};

//{ Driver Code Starts.

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        vector<int> arr;
        int num;
        while (ss >> num) {
            arr.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(arr) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
```

- **Time Complexity:** \( O(n) \)
- **Space Complexity:** \( O(1) \)

---
