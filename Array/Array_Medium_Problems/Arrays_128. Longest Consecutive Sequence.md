# Longest Consecutive Sequence

<!-- markdownlint-disable MD024 -->

## Table of Contents

- [Longest Consecutive Sequence](#longest-consecutive-sequence)
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
    - [Brute-force (Sorting Based) Solution](#brute-force-sorting-based-solution)
      - [✅ Pros](#-pros)
      - [❌ Cons](#-cons)
    - [Optimized (HashSet Based) Solution](#optimized-hashset-based-solution)
      - [✅ Pros](#-pros-1)
      - [❌ Cons](#-cons-1)
  - [Complexity Analysis](#complexity-analysis)
  - [How to Run the Code](#how-to-run-the-code)
    - [For C++](#for-c)
  - [Other Solutions](#other-solutions)
    - [Solution - 1](#solution---1)
    - [Solution - 2](#solution---2)
    - [Solution - 3](#solution---3)
      - [✅ **Approach 1: Brute Force using Three Nested Loops**](#-approach-1-brute-force-using-three-nested-loops)
      - [✅ **Approach 2: Brute Better using Sorting**](#-approach-2-brute-better-using-sorting)
      - [✅ **Approach 3: Optimized using Unordered Map**](#-approach-3-optimized-using-unordered-map)
      - [✅ **Approach 4: Optimized using Unordered Set**](#-approach-4-optimized-using-unordered-set)
    - [Solution - 4](#solution---4)

---

## Introduction

This document provides solutions to the problem **Longest Consecutive Sequence** from LeetCode. The goal is to determine the length of the longest sequence of consecutive integers in an unsorted array, using efficient techniques to optimize performance.

---

## Problem Description

Given an unsorted array of integers `nums`, return the **length of the longest consecutive elements sequence**.

You must write an algorithm that runs in **O(n)** time.

### Examples

#### Example 1

**Input:**  
`nums = [100, 4, 200, 1, 3, 2]`  
**Output:**  
`4`  
**Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`.

#### Example 2

**Input:**  
`nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]`  
**Output:**  
`9`

#### Example 3

**Input:**  
`nums = [1, 0, 1, 2]`  
**Output:**  
`3`  
**Explanation:** The sequence `[0, 1, 2]` is the longest.

---

### Constraints

- `0 <= nums.length <= 10⁵`
- `-10⁹ <= nums[i] <= 10⁹`

---

## Approach

We provide two solutions:

1. **Brute-force Sorting Approach**: Sort the array and count consecutive sequences while skipping duplicates.
2. **Optimized HashSet Approach**: Use a hash set to identify the start of sequences and count their lengths without sorting.

---

## Detailed Explanation of Code

### Brute-force (Sorting Based) Solution

```cpp
int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;

    sort(nums.begin(), nums.end());

    int longest = 1, countCurrent = 1, lastSmaller = nums[0];
    int n = nums.size();

    for(int i = 1; i < n; i++) {
        if(nums[i] == lastSmaller) continue; // skip duplicates

        if(nums[i] - 1 == lastSmaller) {
            countCurrent++;
        } else {
            countCurrent = 1; // reset count
        }

        lastSmaller = nums[i];
        longest = max(longest, countCurrent);
    }

    return longest;
}
```

#### ✅ Pros

- Easy to implement
- Handles duplicates

#### ❌ Cons

- Time complexity is `O(n log n)` due to sorting

---

### Optimized (HashSet Based) Solution

```cpp
int longestConsecutive(vector<int>& nums) {
    if(nums.empty()) return 0;

    unordered_set<int> mySet(nums.begin(), nums.end());
    int longest = 0;

    for(auto it : mySet) {
        // Only try to build sequence from start of sequence
        if(mySet.find(it - 1) == mySet.end()) {
            int current = it;
            int count = 1;

            while(mySet.find(current + 1) != mySet.end()) {
                current++;
                count++;
            }

            longest = max(longest, count);
        }
    }

    return longest;
}
```

#### ✅ Pros

- **O(n)** time complexity
- Efficient lookup using hash set

#### ❌ Cons

- Slightly more complex logic

---

## Complexity Analysis

| Approach              | Time Complexity | Space Complexity |
| --------------------- | --------------- | ---------------- |
| Brute-force (Sorting) | O(n log n)      | O(1) or O(n)     |
| Optimized (HashSet)   | O(n)            | O(n)             |

---

## How to Run the Code

### For C++

1. Include necessary headers:

   ```cpp
   #include <bits/stdc++.h>
   using namespace std;
   ```

2. Create a main function to test:

   ```cpp
   int main() {
       vector<int> nums = {100, 4, 200, 1, 3, 2};
       Solution sol;
       cout << sol.longestConsecutive(nums) << endl;
       return 0;
   }
   ```

3. Compile and run:

   ```bash
   g++ -o main main.cpp
   ./main
   ```

---

## Other Solutions

### Solution - 1

```cpp
int longestConsecutive(vector<int>& nums) {
    unordered_map<int, int> m;
    int r = 0;
    for (int i : nums)
        if (!m[i]) {
            m[i] = m[i - 1] + m[i + 1] + 1;
            m[i - m[i - 1]] = m[i];
            m[i + m[i + 1]] = m[i];
            r = max(r, m[i]);
        }
    return r;
}
```

### Solution - 2

```java
public int longestConsecutive(int[] num) {
    int res = 0;
    HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
    for (int n : num) {
        if (!map.containsKey(n)) {
            int left = (map.containsKey(n - 1)) ? map.get(n - 1) : 0;
            int right = (map.containsKey(n + 1)) ? map.get(n + 1) : 0;
            // sum: length of the sequence n is in
            int sum = left + right + 1;
            map.put(n, sum);

            // keep track of the max length
            res = Math.max(res, sum);

            // extend the length to the boundary(s)
            // of the sequence
            // will do nothing if n has no neighbors
            map.put(n - left, sum);
            map.put(n + right, sum);
        }
        else {
            // duplicates
            continue;
        }
    }
    return res;
}
```

Here's your markdown documentation section for the given code under:

---

### Solution - 3

This section describes four different approaches for solving the **Longest Consecutive Sequence** problem in C++. Each approach improves on the previous one in terms of time and/or space complexity.

---

#### ✅ **Approach 1: Brute Force using Three Nested Loops**

```cpp
class Solution {
private:
    bool longestConsecutive(vector<int>& nums, int target){
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] == target){
                return true;
            }
        }
        return false;
    }
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int longestConsecutiveSequence = 0;
        for(auto num : nums){
            int currentNumber = num;
            int currentConsecutiveSequence = 1;
            while(longestConsecutive(nums, currentNumber+1)){
                currentNumber += 1;
                currentConsecutiveSequence += 1;
            }
            longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
        }
        return longestConsecutiveSequence;
    }
};
```

**Time Complexity:** `O(N^3)`  
**Space Complexity:** `O(1)`  
**Note:** This brute-force solution checks each element repeatedly and will result in **TLE** for large inputs.

---

#### ✅ **Approach 2: Brute Better using Sorting**

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        sort(nums.begin(), nums.end());
        int currentConsecutiveSequence = 1;
        int longestConsecutiveSequence = 0;
        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == nums[i-1] + 1){
                    currentConsecutiveSequence++;
                }
                else{
                    longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
                    currentConsecutiveSequence = 1;
                }
            }
        }
        return max(longestConsecutiveSequence, currentConsecutiveSequence);
    }
};
```

**Time Complexity:** `O(N log N)`  
**Space Complexity:** `O(1)`  
**Note:** Uses sorting to simplify the problem, making it more efficient than the brute-force version.

---

#### ✅ **Approach 3: Optimized using Unordered Map**

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, bool> map;
        for(int i = 0; i<nums.size(); i++){
            map[nums[i]] = true;
        }
        for(int i=0; i<nums.size(); i++){
            if(map.count(nums[i]-1) > 0){
                map[nums[i]] = false;
            }
        }
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(map[nums[i]] == true){
                int j=0; int count=0;
                while(map.count(nums[i]+j) > 0){
                    j++;
                    count++;
                }
                if(count > maxlen){
                    maxlen = count;
                }
            }
        }
        return maxlen;
    }
};
```

**Time Complexity:** `O(N)`  
**Space Complexity:** `O(N)`  
**Note:** This approach uses a hash table (unordered map) to mark potential starting points of sequences and count their lengths.

---

#### ✅ **Approach 4: Optimized using Unordered Set**

```cpp
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int longestConsecutiveSequence = 0;
        for(int num : nums){
            if(set.find(num-1) == set.end()){
                int currentNumber = num;
                int currentConsecutiveSequence = 1;
                while(set.find(currentNumber+1) != set.end()){
                    currentNumber++;
                    currentConsecutiveSequence++;
                }
                longestConsecutiveSequence = max(longestConsecutiveSequence, currentConsecutiveSequence);
            }
        }
        return longestConsecutiveSequence;
    }
};
```

**Time Complexity:** `O(N)`  
**Space Complexity:** `O(N)`  
**Note:** This is the most optimized approach using an unordered set to detect the start of sequences efficiently.

---

### Solution - 4

```java
class Solution {
    public int longestConsecutive(int[] nums) {
        UF uf = new UF(nums.length);
        // Map val to index in nums
        Map<Integer, Integer> valToIndex = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (valToIndex.containsKey(nums[i])) {
                continue;
            }

            if (valToIndex.containsKey(nums[i] - 1)) {
                uf.union(i, valToIndex.get(nums[i] - 1));
            }

            if (valToIndex.containsKey(nums[i] + 1)) {
                uf.union(i, valToIndex.get(nums[i] + 1));
            }

            valToIndex.put(nums[i], i);
        }

        return uf.getLargetComponentSize();
    }

    class UF {
        private int[] parent;
        private int[] size;

        public UF(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        public void union(int x, int y) { // connected if consecutive
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            }
        };

        private int find(int x) {
            if (parent[x] == x) {
                return x;
            }

            return parent[x] = find(parent[x]);
        };

        public int getLargetComponentSize() {
            int maxSize = 0;
            for (int i = 0; i < parent.length; i++) {
                if (parent[i] == i && size[i] > maxSize) {
                    maxSize = size[i];
                }
            }

            return maxSize;
        }
    }
}
```

- **Time Complexity:** `O(N)`
- **Space Complexity:** `O(N)`

---
