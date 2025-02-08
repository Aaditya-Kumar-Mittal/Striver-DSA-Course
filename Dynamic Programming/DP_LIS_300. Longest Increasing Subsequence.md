# Longest Increasing Subsequence

## Table of Contents

- [Longest Increasing Subsequence](#longest-increasing-subsequence)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Given](#given)
    - [Task](#task)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
      - [Example 3](#example-3)
    - [Constraints](#constraints)
  - [Approach](#approach)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [Recursive Approach](#recursive-approach)
    - [Memoization Approach](#memoization-approach)
    - [Tabulation Approach](#tabulation-approach)
    - [Space-Optimized Tabulation Approach](#space-optimized-tabulation-approach)
    - [Efficient Tabulation Approach](#efficient-tabulation-approach)
    - [Binary Search Approach](#binary-search-approach)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
  - [Other Solutions](#other-solutions)
    - [My Leetcode Submission](#my-leetcode-submission)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)

---

## Introduction

The problem requires finding the length of the **longest strictly increasing subsequence** in a given integer array `nums`.

A **subsequence** is a sequence derived from another sequence by deleting some elements without changing the order of the remaining elements.

---

## Problem Description

### Given

- An integer array `nums`.

### Task

- Return the **length** of the longest **strictly increasing subsequence**.

### Examples

#### Example 1

**Input:**

```cpp
nums = [10,9,2,5,3,7,101,18]
```

**Output:**

```cpp
4
```

**Explanation:**
The longest increasing subsequence is `[2,3,7,101]`, so the length is `4`.

#### Example 2

**Input:**

```cpp
nums = [0,1,0,3,2,3]
```

**Output:**

```cpp
4
```

#### Example 3

**Input:**

```cpp
nums = [7,7,7,7,7,7,7]
```

**Output:**

```cpp
1
```

### Constraints

- `1 <= nums.length <= 2500`
- `-10^4 <= nums[i] <= 10^4`

---

## Approach

Several approaches can be used to solve this problem:

1. **Recursive Approach:** Try all subsequences.
2. **Memoization Approach:** Store results to avoid redundant computations.
3. **Tabulation Approach:** Bottom-up dynamic programming.
4. **Space-Optimized Tabulation Approach:** Reducing space complexity.
5. **Efficient Approach:** Using **Binary Search** and **Dynamic Programming** together.

---

## Detailed Explanation of Code

### Recursive Approach

```cpp
int recursive_solution(int index, int prevInd, int n, vector<int>& arr) {
    if (index == n)
        return 0;
    int not_pick = recursive_solution(index + 1, prevInd, n, arr);
    int pick = 0;
    if (prevInd == -1 || arr[index] > arr[prevInd])
        pick = 1 + recursive_solution(index + 1, index, n, arr);
    return max(not_pick, pick);
}
```

**Explanation:**

- If we reach the end, return 0.
- Recursively decide whether to include `arr[index]` in the subsequence.

### Memoization Approach

```cpp
int memoization(int index, int prevInd, int n, vector<int>& arr, vector<vector<int>>& dp) {
    if (index == n)
        return 0;
    if (dp[index][prevInd + 1] != -1)
        return dp[index][prevInd + 1];
    int not_pick = memoization(index + 1, prevInd, n, arr, dp);
    int pick = 0;
    if (prevInd == -1 || arr[index] > arr[prevInd])
        pick = 1 + memoization(index + 1, index, n, arr, dp);
    return dp[index][prevInd + 1] = max(not_pick, pick);
}
```

**Explanation:**

- Uses **top-down DP** to store results, avoiding redundant calculations.
- Uses a `dp` table indexed by `index` and `prevInd + 1`.

### Tabulation Approach

```cpp
int tabulation(int n, vector<int>& arr) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int index = n - 1; index >= 0; index--) {
        for (int prevInd = index - 1; prevInd >= -1; prevInd--) {
            int not_pick = dp[index + 1][prevInd + 1];
            int pick = 0;
            if (prevInd == -1 || arr[index] > arr[prevInd])
                pick = 1 + dp[index + 1][index + 1];
            dp[index][prevInd + 1] = max(not_pick, pick);
        }
    }
    return dp[0][0];
}
```

**Explanation:**

- Uses **bottom-up DP**.
- Stores the result for every state in a **2D DP table**.

### Space-Optimized Tabulation Approach

```cpp
int tabulation_optimized(int n, vector<int>& arr) {
    vector<int> dp(n + 1, 0), current(n + 1, 0);
    for (int index = n - 1; index >= 0; index--) {
        for (int prevInd = index - 1; prevInd >= -1; prevInd--) {
            int not_pick = dp[prevInd + 1];
            int pick = 0;
            if (prevInd == -1 || arr[index] > arr[prevInd])
                pick = 1 + dp[index + 1];
            current[prevInd + 1] = max(not_pick, pick);
        }
        dp = current;
    }
    return current[0];
}
```

**Explanation:**

- Optimized **space complexity** from `O(n^2)` to `O(n)`.

### Efficient Tabulation Approach

```cpp
int tabulation_2(int n, vector<int>& arr) {
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++) {
        for (int p = 0; p < i; p++) {
            if (arr[p] < arr[i]) {
                dp[i] = max(1 + dp[p], dp[i]);
            }
        }
        maxi = max(maxi, dp[i]);
    }
    return maxi;
}
```

**Explanation:**

- Uses **O(n^2) dynamic programming**.
- Maintains a `dp` array where `dp[i]` stores the length of the LIS ending at `i`.

---

### Binary Search Approach

```cpp


class Solution {
  public:
    // Function to find length of longest increasing subsequence.
    // Function to find the length of the longest increasing subsequence.
    int lis(vector<int>& arr) {
        if (arr.empty()) return 0; // Edge case: empty array

        vector<int> temp;
        temp.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > temp.back()) {
                temp.push_back(arr[i]);
            } else {
                // Find the position where arr[i] can replace an element in temp
                auto it = lower_bound(temp.begin(), temp.end(), arr[i]);
                int ind = distance(temp.begin(), it); // Convert iterator to index
                temp[ind] = arr[i];
            }
        }

        return temp.size();
    }
};
```

**Explanation:**

- Uses **binary search** to find the longest increasing subsequence.
- `lower_bound` function is used to find the position where `arr[i]` can replace an element in `temp`.
- Returns the size of the longest increasing subsequence.
- Time complexity: `O(n log n)`, where `n` is the size of the input array.
- Space complexity: `O(n)`, where `n` is the size of the input array.

## Complexity Analysis

| Approach             | Time Complexity | Space Complexity |
| -------------------- | --------------- | ---------------- |
| Recursive            | `O(2^n)`        | `O(n)`           |
| Memoization          | `O(n^2)`        | `O(n^2)`         |
| Tabulation           | `O(n^2)`        | `O(n^2)`         |
| Space Optimized      | `O(n^2)`        | `O(n)`           |
| Efficient Tabulation | `O(n^2)`        | `O(n)`           |
| Binary Search        | `O(n log n)`    | `O(n)`           |

---

## How to Run the Code

1. Compile the code using a C++ compiler:

   ```sh
   g++ solution.cpp -o solution
   ```

2. Run the executable:

   ```sh
   ./solution
   ```

## Other Solutions

### My Leetcode Submission

```cpp
class Solution {
public:
    int recursive_solution(int index, int prevInd, int n, vector<int>& arr) {
        if (index == n)
            return 0;

        int not_pick = recursive_solution(index + 1, prevInd, n, arr);

        int pick = 0;

        if (prevInd == -1 || arr[index] > arr[prevInd])
            pick = 1 + recursive_solution(index + 1, index, n, arr);

        return max(not_pick, pick);
    }

    int memoization(int index, int prevInd, int n, vector<int>& arr,
                    vector<vector<int>>& dp) {
        if (index == n)
            return 0;

        if (dp[index][prevInd + 1] !=
            -1) // Using prevInd + 1 for 0-based indexing
            return dp[index][prevInd + 1];

        int not_pick = memoization(index + 1, prevInd, n, arr, dp);

        int pick = 0;
        if (prevInd == -1 || arr[index] > arr[prevInd])
            pick = 1 + memoization(index + 1, index, n, arr, dp);

        return dp[index][prevInd + 1] = max(not_pick, pick);
    }

    int tabulation(int n, vector<int>& arr) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int prevInd = index - 1; prevInd >= -1; prevInd--) {
                int not_pick = dp[index + 1][prevInd + 1];
                int pick = 0;
                if (prevInd == -1 || arr[index] > arr[prevInd])
                    pick = 1 + dp[index + 1][index + 1];
                dp[index][prevInd + 1] = max(not_pick, pick);
            }
        }

        return dp[0][0]; // Corrected return statement
    }

    int tabulation_optimized(int n, vector<int>& arr) {
        vector<int> dp(n + 1, 0), current(n + 1, 0);

        for (int index = n - 1; index >= 0; index--) {
            for (int prevInd = index - 1; prevInd >= -1; prevInd--) {
                int not_pick = dp[prevInd + 1];
                int pick = 0;
                if (prevInd == -1 || arr[index] > arr[prevInd])
                    pick = 1 + dp[index + 1];
                current[prevInd + 1] = max(not_pick, pick);
            }
            dp = current;
        }

        return current[0]; // Corrected return statement
    }

    int tabulation_2(int n, vector<int>& arr) {
        vector<int> dp(n, 1);

        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int p = 0; p < i; p++) {
                if (arr[p] < arr[i]) {
                    dp[i] = max(1 + dp[p], dp[i]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        return tabulation_2(n, nums);
    }
};
```

### Solution - 2

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        auto binarySearch = [&](int start, int end, int key) {
            if(res.empty()) return -1;
            int ind = -1;
            while(start <= end) {
                int mid = start + (end-start)/2;
                if(res[mid] < key) {
                    start = mid+1;
                    ind = mid;
                } else if(res[mid] >= key)
                    end = mid-1;
            }
            return ind;
        };
        for(auto num : nums) {
            int ind = binarySearch(0, res.size()-1, num);
            if((ind == -1 && res.empty()) || ind == res.size()-1) res.emplace_back(num);
            else res[ind+1] = num;
        }
        return res.size();
    }
};
```

### Solution - 3

```cpp
class Solution {
  public:
  #define rep(i,a,b) for(int i=a;i<b;i++)
  #define pb(x) push_back(x)
  #define all(x) x.begin(), x.end()
  #define fl(x,y) for(auto x: y)
  #define nln cout<<endl
  #define ff first
  #define ss second
  #define MIN(v) *min_element(all(v))
  #define MAX(v) *max_element(all(v))
  #define shar(a) {rep(var,0,n)cout<<a[var]<<" ";nln;}
  #define show(s) {fl(val,s)cout<<val<<" ";nln;}
  #define showmap(m) {fl(val,m)cout<<val.ff<<" "<<val.ss<<endl;nln;}
  #define lb(c, x) lower_bound(all(x),c)-x.begin()
  #define ub(c, x) upper_bound(all(x),c)-x.begin()
  #define acc(x) accumulate(all(x),0)
  #define hi 100000000

  int n;
  int a[2505];


      int lengthOfLIS(vector<int>& v) { n=v.size();
      rep(i,0,n+1) a[i] = 0;;
      a[0] = 1;

      rep(i,1,n){ a[i] = 1;
          rep(j,0,i) if(v[i]>v[j]) a[i] = max(a[i],a[j]+1);
      }

      // rep(i,0,n) cout<<a[i]<<" "; nln;

      int ans=0;
      rep(i,0,n) ans = max(ans,a[i]);
      return ans;

      }
  };
```
