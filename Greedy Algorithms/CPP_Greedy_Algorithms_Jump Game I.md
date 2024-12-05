# Jump Game Problem

## Table of Contents

- [Jump Game Problem](#jump-game-problem)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Examples](#examples)
      - [Example 1](#example-1)
      - [Example 2](#example-2)
    - [Constraints](#constraints)
  - [Approach](#approach)
    - [Key Observations](#key-observations)
  - [Detailed Explanation of Code](#detailed-explanation-of-code)
    - [C++ Implementation](#c-implementation)
    - [Java Implementation](#java-implementation)
  - [Complexity Analysis](#complexity-analysis)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [Interview Walkthrough and Thought Process](#interview-walkthrough-and-thought-process)
    - [Clarifying Questions](#clarifying-questions)
      - [Thinking Aloud: Recursion-Based Approach](#thinking-aloud-recursion-based-approach)
      - [Optimizing: Memoization](#optimizing-memoization)
      - [Tabulation (Dynamic Programming)](#tabulation-dynamic-programming)
      - [Optimal Greedy Approach](#optimal-greedy-approach)
    - [Summary of Approaches](#summary-of-approaches)

---

## Introduction

The task is to determine if it is possible to jump from the first index of the given integer array to the last index. Each array element represents the maximum jump length at that position.

---

## Problem Description

### Input

- `nums`: An integer array representing maximum jump lengths.

### Output

- `true`: If you can reach the last index.
- `false`: Otherwise.

---

### Examples

#### Example 1

**Input:**

```plaintext
nums = [2, 3, 1, 1, 4]
```

**Output:**

```plaintext
true
```

**Explanation:**  
Jump 1 step from index `0` to `1`, then 3 steps to the last index.

---

#### Example 2

**Input:**

```plaintext
nums = [3, 2, 1, 0, 4]
```

**Output:**

```plaintext
false
```

**Explanation:**  
You will always arrive at index `3`, but its maximum jump length is `0`, making it impossible to proceed.

---

### Constraints

- `1 ≤ nums.length ≤ 10^4`
- `0 ≤ nums[i] ≤ 10^5`

---

## Approach

### Key Observations

1. **Greedy Approach:**

   - Track the farthest index reachable (`maxIndex`) as you iterate through the array.
   - If the current index exceeds `maxIndex`, it means you cannot proceed further.

2. **Conditions for Success:**
   - At every step, check if `maxIndex` is at least equal to the current index.

---

## Detailed Explanation of Code

### C++ Implementation

```cpp
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0; // Farthest index reachable so far

        for (int i = 0; i < nums.size(); i++) {
            if (i > maxIndex) // If current index is beyond max reachable
                return false;

            // Update the farthest reachable index
            maxIndex = max(maxIndex, i + nums[i]);
        }

        return true; // Reached the end of the loop, can reach the last index
    }
};
```

---

### Java Implementation

```java
class Solution {
    public boolean canJump(int[] nums) {
        int maxIndex = 0; // Farthest index reachable so far

        for (int i = 0; i < nums.length; i++) {
            if (i > maxIndex) // If current index is beyond max reachable
                return false;

            // Update the farthest reachable index
            maxIndex = Math.max(maxIndex, i + nums[i]);
        }

        return true; // Reached the end of the loop, can reach the last index
    }
}
```

---

## Complexity Analysis

### Time Complexity

- **Iteration:** `O(n)`, where `n` is the length of the array.
- At each index, we perform a constant amount of work (update `maxIndex`).

**Overall Time Complexity:** `O(n)`.

### Space Complexity

- The solution uses a constant amount of extra space for variables.

**Overall Space Complexity:** `O(1)`.

---

This implementation efficiently solves the problem using a greedy approach, ensuring a time complexity of `O(n)` and a space complexity of `O(1)`.

## Interview Walkthrough and Thought Process

When faced with the **Jump Game** problem during an interview, a clear and structured approach can make a strong impression. Here's how you can demonstrate your thought process step by step:

---

### Clarifying Questions

1. **Input/Output**:

   - Is the array guaranteed to be non-empty? _(Yes, as per constraints.)_
   - Can the array contain only non-negative integers? _(Yes, per constraints.)_

2. **Behavior**:

   - What should we return if the array has only one element? _(Always `true`, as we're already at the last index.)_
   - Can we reuse jumps? _(No, we can only jump forward based on the current index value._)

3. **Edge Cases**:
   - What if all elements are `0`? _(If the first element is `0` and the size is more than 1, return `false`.)_
   - What if the array is like `[0,0,0,...]`? _(Impossible to reach the last index if not already there.)_

---

#### Thinking Aloud: Recursion-Based Approach

1. Start with **brute-force recursion**:

   - The problem can be visualized as a **decision tree**. At each index, there are multiple jump options, and we need to explore all possible paths to the last index.
   - Base Cases:
     - If `idx == nums.size() - 1`: Reached the last index, return `true`.
     - If `nums[idx] == 0`: Cannot move forward, return `false`.

2. Iteratively explore:

   - From the current index, explore all possible jumps (`idx + 1` to `idx + nums[idx]`).
   - If any path leads to the last index, return `true`.

3. Recursive Code:

   ```cpp
   class Solution {
   public:
       bool canJump(vector<int>& nums) {
           return canReach(nums, 0);
       }

   private:
       bool canReach(vector<int>& nums, int idx) {
           if (idx == nums.size() - 1) return true; // Reached last index
           if (nums[idx] == 0) return false;        // Stuck at index

           int maxJump = idx + nums[idx];
           for (int jump = idx + 1; jump <= maxJump; jump++) {
               if (jump < nums.size() && canReach(nums, jump))
                   return true;
           }

           return false;
       }
   };
   ```

4. Complexity:
   - **Time:** Exponential, as it explores all possible jump combinations: `O(N^N)`.
   - **Space:** `O(N)` for recursion stack.

---

#### Optimizing: Memoization

1. Identify **overlapping subproblems**:

   - Many indices are revisited during recursion, causing redundant computations.
   - Use a **`dp` array** to store results for already-visited indices.

2. Modified Approach:

   - Introduce a `dp` array initialized with `-1` (unvisited).
   - Return stored results for previously calculated indices.

3. Code:

   ```cpp
   class Solution {
   public:
       bool canJump(vector<int>& nums) {
           vector<int> dp(nums.size(), -1);
           return canReach(nums, 0, dp);
       }

   private:
       bool canReach(vector<int>& nums, int idx, vector<int>& dp) {
           if (idx == nums.size() - 1) return true;
           if (nums[idx] == 0) return false;
           if (dp[idx] != -1) return dp[idx];

           int maxJump = idx + nums[idx];
           for (int jump = idx + 1; jump <= maxJump; jump++) {
               if (jump < nums.size() && canReach(nums, jump, dp))
                   return dp[idx] = true;
           }

           return dp[idx] = false;
       }
   };
   ```

4. Complexity:
   - **Time:** `O(N * N)`, as each index can involve up to `N` jumps.
   - **Space:** `O(N)` for `dp` array and recursion stack.

---

#### Tabulation (Dynamic Programming)

1. **Iterative Optimization**:

   - Avoid recursion stack by filling the `dp` array iteratively.
   - Traverse from the last index backward, storing whether each index can lead to the last index.

2. Code:

   ```cpp
   class Solution {
   public:
       bool canJump(vector<int>& nums) {
           int n = nums.size();
           vector<int> dp(n, 0);  // `0` means cannot reach, `1` means can reach
           dp[n - 1] = 1;        // Base case: last index is always reachable

           for (int idx = n - 2; idx >= 0; idx--) {
               int maxJump = min(idx + nums[idx], n - 1);
               for (int jump = idx + 1; jump <= maxJump; jump++) {
                   if (dp[jump]) {
                       dp[idx] = 1;
                       break;
                   }
               }
           }

           return dp[0] == 1;
       }
   };
   ```

3. Complexity:
   - **Time:** `O(N * N)`.
   - **Space:** `O(N)` for `dp` array.

---

#### Optimal Greedy Approach

1. **Key Observation**:

   - Keep track of the **farthest reachable index** (`reach`) while traversing the array.
   - If the current index exceeds `reach`, return `false`.

2. Algorithm:

   - Start with `reach = 0`.
   - For each index, check if it's within the reachable range.
   - Update `reach` with the maximum of its current value and `idx + nums[idx]`.

3. Code:

   ```cpp
   class Solution {
   public:
       bool canJump(vector<int>& nums) {
           int reach = 0;

           for (int idx = 0; idx < nums.size(); idx++) {
               if (idx > reach) return false;
               reach = max(reach, idx + nums[idx]);
           }

           return true;
       }
   };
   ```

4. Complexity:
   - **Time:** `O(N)`.
   - **Space:** `O(1)`.

---

### Summary of Approaches

| Approach        | Time Complexity | Space Complexity | Notes                       |
| --------------- | --------------- | ---------------- | --------------------------- |
| Recursion       | `O(N^N)`        | `O(N)`           | Naive, exponential time.    |
| Memoization     | `O(N * N)`      | `O(N)`           | Optimized with overlapping. |
| Tabulation (DP) | `O(N * N)`      | `O(N)`           | Iterative DP approach.      |
| Greedy          | `O(N)`          | `O(1)`           | Best solution, linear time. |

In an interview, explaining this thought process demonstrates problem-solving skills, understanding of trade-offs, and clear communication.
