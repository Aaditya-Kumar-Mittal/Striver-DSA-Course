# Jump Game II

## Table of Contents

- [Jump Game II](#jump-game-ii)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Examples](#examples)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Greedy Solution](#greedy-solution)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
    - [For Java](#for-java)
  - [Other Solutions](#other-solutions)
    - [Recursive Solution but produces TLE](#recursive-solution-but-produces-tle)
    - [Memoization of recursive solution but it may give TLE](#memoization-of-recursive-solution-but-it-may-give-tle)

---

## Introduction

The **Jump Game II** problem involves finding the minimum number of jumps needed to reach the last index of an array. Each array element specifies the maximum jump length from that position. It is guaranteed that you can always reach the last index.

---

## Problem Description

### Examples

1. **Input**:  
   `nums = [2,3,1,1,4]`  
   **Output**:  
   `2`  
   **Explanation**: Jump 1 step from index 0 to index 1, then 3 steps to reach the last index.

2. **Input**:  
   `nums = [2,3,0,1,4]`  
   **Output**:  
   `2`

---

### Constraints

- `1 <= nums.length <= 10^4`
- `0 <= nums[i] <= 1000`
- Guaranteed that you can reach `nums[n - 1]`.

---

## Approach

### Greedy Solution

The goal is to minimize jumps while ensuring the traversal of the entire array. The greedy approach works as follows:

1. Keep track of the current range of indices (`left` to `right`) that can be reached with the current number of jumps.
2. For each index in the current range, calculate the farthest position that can be reached.
3. Once the farthest position extends beyond the last index, increment the jump counter.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0; // Number of jumps made
        int left = 0;  // Left boundary of the current range
        int right = 0; // Right boundary of the current range

        while (right < nums.size() - 1) {
            int farthest = 0; // Tracks the farthest point we can reach in the next jump

            for (int i = left; i <= right; i++) {
                if (nums[i] > INT_MAX - i) {
                    // Prevent overflow
                    farthest = INT_MAX;
                } else {
                    farthest = max(farthest, i + nums[i]);
                }
            }

            left = right + 1; // Update the left boundary
            right = farthest; // Update the right boundary
            jumps++;          // Increment the jump counter
        }

        return jumps;
    }
};
```

---

### Java Implementation

```java
class Solution {
    public int jump(int[] nums) {
        int jumps = 0;  // Number of jumps made
        int left = 0;   // Left boundary of the current range
        int right = 0;  // Right boundary of the current range

        while (right < nums.length - 1) {
            int farthest = 0; // Tracks the farthest point we can reach in the next jump

            for (int i = left; i <= right; i++) {
                farthest = Math.max(farthest, i + nums[i]);
            }

            left = right + 1; // Update the left boundary
            right = farthest; // Update the right boundary
            jumps++;          // Increment the jump counter
        }

        return jumps;
    }
}
```

---

## Complexity Analysis

- **Time Complexity**:  
  The array is traversed once, with each element processed in constant time for updating the `farthest` variable.  
  **O(n)**, where `n` is the length of the array.

- **Space Complexity**:  
  No additional space is used other than a few variables.  
  **O(1)**.

---

## How to Run the Code

### For C++

1. Save the code to a file (e.g., `Solution.cpp`).
2. Compile using a C++ compiler:

   ```bash
   g++ Solution.cpp -o Solution
   ```

3. Run the executable:

   ```bash
   ./Solution
   ```

### For Java

1. Save the code to a file (e.g., `Solution.java`).
2. Compile using a Java compiler:

   ```bash
   javac Solution.java
   ```

3. Run the compiled class:

   ```bash
   java Solution
   ```

## Other Solutions

### Recursive Solution but produces TLE

```cpp
class Solution {
public:

   long long int jump(vector<int> nums , int curr, int dest)
    {
            if(curr>=dest) return 0;
            long long int tmp=INT_MAX;

            //Try Every jump 1 to nums[curr] jump
            //and find minimum steps need to reach to end

            for(int i=1;i<=nums[curr];i++)
            {
                tmp=min(tmp,1+jump(nums,curr+i,dest));
            }
         return tmp;
    }

    int jump(vector<int>& nums) {
         return jump(nums,0,nums.size()-1);
    }
};
```

- **Time Complexity**: O(k^n), Where, k is max element of nums and n is size of nums.
- **Space Complexity**: O(1).
- Because every time inside the recursive function it is calling itself nums[i] times and this is happening for every element (i.e n elements).

### Memoization of recursive solution but it may give TLE

```cpp
class Solution {
public:

   long long int jump(vector<int> &nums , int curr, int dest,vector<int> &dp)
    {
            if(curr==dest) return 0;
            if(dp[curr]!=-1) return dp[curr];
            //cout<<curr<<" ";
            long long int tmp=INT_MAX;

            for(int i=1;i<=nums[curr];i++)
            {   if(i+curr>dest) break;
                tmp=min(tmp,1+jump(nums,curr+i,dest,dp));
            }
         dp[curr]=tmp;
         return tmp;
    }

    int jump(vector<int>& nums) {
         vector<int> dp(nums.size(),-1);
         return jump(nums,0,nums.size()-1,dp);
    }
};
```

- Time Complexity: O(k \* n), Where, k is max element of nums and n is size of nums.
- Space Complexity: O(n).
- Because every time inside the recursive function it is calling itself nums[i] times and this is happening for every element (i.e n elements). But here we have stored previous calculated result, so there will be no repeation.
