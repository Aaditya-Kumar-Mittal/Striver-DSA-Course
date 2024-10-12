# Fruit Into Baskets (Problem 904) ~ Longest Subarray With at most 2 Elements

## Problem Statement

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array `fruits` where `fruits[i]` is the type of fruit the `ith` tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have **two baskets**, and each basket can only hold a **single type** of fruit.
- There is **no limit** on the number of fruits each basket can hold.
- Starting from any tree of your choice, you must pick **exactly one fruit** from **every** tree (including the start tree) while moving to the right.
- The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.

**Given the integer array `fruits`, return the `maximum` number of fruits you can pick.**

### Constraints

- `1 <= fruits.length <= 10^5`
- `0 <= fruits[i] < fruits.length`

---

## Brute Force Solution

### Approach

1. Use a nested loop to explore all possible subarrays starting from each index.
2. Use a set to track the types of fruits in the current subarray.
3. If the set size is `<= 2`, calculate the length of the current subarray and update the maximum length.
4. If the set size exceeds `2`, break out of the inner loop and move to the next starting index.

#### Brute Force Code

```cpp
class Solution {
public:
    /**
     * @brief Finds the maximum number of fruits that can be collected in two baskets using a brute force approach.
     *
     * @param fruits A vector representing different types of fruits in a row.
     * @return int The length of the longest subarray containing at most two types of fruits.
     */
    int totalFruit(vector<int>& fruits) {
        int maxLen = 0;        // Store the maximum length of valid subarrays.
        int n = fruits.size(); // Length of the fruits array.

        // Iterate through each starting point.
        for (int i = 0; i < n; i++) {
            set<int> st; // Set to store unique types of fruits in the current window.

            // Expand the window from i to j.
            for (int j = i; j < n; j++) {
                st.insert(fruits[j]); // Add the fruit type to the set.

                // Check if the window contains at most two types of fruits.
                if (st.size() <= 2) {
                    maxLen = max(maxLen, j - i + 1); // Update the maximum length.
                } else {
                    break; // Stop expanding the window if more than 2 types.
                }
            }
        }

        return maxLen; // Return the maximum length found.
    }
};
```

#### Complexity Analysis

- **Time Complexity**: `O(n^2)` due to the nested loop structure.
- **Space Complexity**: `O(1)` for storing at most 3 unique types in the set.
- **Drawback**: This approach is inefficient for larger input sizes due to its quadratic time complexity.

---

### Optimized Solution: Sliding Window

#### Sliding Window Approach

1. Use a sliding window technique with two pointers (`left` and `right`) to maintain a valid window.
2. Use a `unordered_map` to track the frequency of each fruit type in the current window.
3. Expand the window by moving `right` and add the current fruit type to the map.
4. If the size of the map exceeds `2`, shrink the window from the `left` until the map size is `≤ 2`.
5. Update the `maxLen` with the length of the current valid window.
6. Continue until `right` reaches the end of the array.

#### Code

```cpp
class Solution {
public:
    /**
     * @brief Finds the maximum number of fruits that can be collected in two baskets using a sliding window approach.
     *
     * @param fruits A vector representing different types of fruits in a row.
     * @return int The length of the longest subarray containing at most two types of fruits.
     */
    int totalFruit(vector<int>& fruits) {
        ios::sync_with_stdio(0); // Optimize input/output.
        cin.tie(0);
        cout.tie(0);

        int maxLen = 0;                      // Store the maximum length of valid subarrays.
        int left = 0;                        // Left pointer for the sliding window.
        unordered_map<int, int> freqMap;     // Stores the frequency of each fruit type in the current window.

        // Traverse the array with the right pointer.
        for (int right = 0; right < fruits.size(); ++right) {
            freqMap[fruits[right]]++;        // Add the current fruit to the map.

            // If more than 2 types of fruits are in the window, shrink it from the left.
            while (freqMap.size() > 2) {
                freqMap[fruits[left]]--;     // Decrease the count of the fruit at the left pointer.
                if (freqMap[fruits[left]] == 0) {
                    freqMap.erase(fruits[left]); // Remove the fruit type from the map if its count is zero.
                }
                left++;                      // Move the left pointer to shrink the window.
            }

            // Calculate the maximum length of the valid window.
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen; // Return the maximum length found.
    }
};
```

#### Time Complexity Analysis

- **Time Complexity**: `O(n)` since both `left` and `right` pointers traverse the array at most once.
- **Space Complexity**: `O(1)` because the `unordered_map` can contain at most `2` fruit types.
- **Efficiency**: This approach is much more efficient and suitable for large input sizes.

---

### Summary

- **Brute Force Approach**: Involves checking all possible subarrays, which is inefficient for large inputs.
- **Optimized Approach**: Uses a sliding window and a hashmap to maintain a window with at most `2` fruit types, providing a linear time solution.
- **Key Concept**: Sliding Window with a variable-size window and frequency map to keep track of elements.

This optimized solution provides the best performance for the problem, making it suitable for the given constraints.

---

## Other Approaches

### Approach - 3

```cpp
    int totalFruit(vector<int> tree) {
        int res = 0, cur = 0, count_b = 0, a = 0, b = 0;
        for (int c :  tree) {
            cur = c == a || c == b ? cur + 1 : count_b + 1;
            count_b = c == b ? count_b + 1 : 1;
            if (b != c) a = b, b = c;
            res = max(res, cur);
        }
        return res;
    }
```

### Approach - 4

```cpp
    int totalFruit(vector<int> &tree) {
        unordered_map<int, int> count;
        int i, j;
        for (i = 0, j = 0; j < tree.size(); ++j) {
            count[tree[j]]++;
            if (count.size() > 2) {
                if (--count[tree[i]] == 0)count.erase(tree[i]);
                i++;
            }
        }
        return j - i;
    }
```

### Approach - 5

```cpp

```
