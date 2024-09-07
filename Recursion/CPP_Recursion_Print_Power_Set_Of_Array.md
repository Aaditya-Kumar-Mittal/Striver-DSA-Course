# Recursion Problem - Printing Power Set of a Given Array

---

## Code of the problem

```cpp
class Solution {
public:
    // Function to generate all subsets of the given array 'nums'.
    // Returns a vector of vectors, where each inner vector is a subset of 'nums'.
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans; // To store all subsets
        vector<int> subset;      // To store each individual subset

        // Call the helper function to create subsets starting from index 0
        createSubsets(nums, 0, subset, ans);

        return ans; // Return the final result
    }

    // Recursive helper function to create subsets
    // 'nums' is the input array, 'index' is the current index being processed
    // 'subset' stores the current subset being built, and 'ans' stores all subsets
    void createSubsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& ans){

        // Base case: If the current index equals the size of the array, store the subset
        if(index == nums.size()) {
            ans.push_back(subset); // Store the current subset
            return;                // Backtrack to explore other subsets
        }

        // Include the current element (nums[index]) in the subset
        subset.push_back(nums[index]);

        // Recursively create subsets including the current element
        createSubsets(nums, index + 1, subset, ans);

        // Backtrack: Remove the current element (nums[index]) from the subset
        subset.pop_back();

        // Recursively create subsets excluding the current element
        createSubsets(nums, index + 1, subset, ans);
    }
};
```

## Analysis of the Problem

### Problem

The problem requires generating all possible subsets (the power set) of a given array of distinct integers.

### Approach

1. **Backtracking/Recursion**:
   - For each element in the array, we have two choices: either include it in the current subset or exclude it.
   - Using recursion, we explore both possibilities at every step.
   - When the index reaches the size of the array, the current subset is complete, and we store it in the answer.

2. **Subset Construction**:
   - Subsets are created in two phases: one where the element is included and one where it is excluded.
   - This ensures all combinations of elements are explored, resulting in all subsets.

### Time Complexity

- **O(2^n)** where `n` is the number of elements in the input array `nums`.
  - For each element, there are two choices (include or exclude), so the total number of subsets is 2^n.
  - Each subset is created in O(n), but since we are dealing with power sets, the dominant factor is 2^n.

### Space Complexity

- **O(2^n)** to store all the subsets in the answer vector.
- **O(n)** space used by the recursive call stack and temporary vectors to store each subset during recursion.

### Edge Cases

1. **Empty Set**: If the input array is empty, the only subset is the empty set itself.
2. **Small Arrays**: The function efficiently handles small arrays by exploring all possible subsets using recursion.
