# Recursion Problem - Combinational Sum - 1

---

## Problem Statement

- Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

- The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

## Code

```cpp
class Solution {
public:
    void findCombinations(int index, vector<int>& arr, int target,
                          vector<vector<int>>& ans, vector<int>& ds) {

        // Base case: When index is out of bounds of the array
        if (index == arr.size()) {
            // If the target is zero, add the current combination to the result
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
        }

        // If the current element is less than or equal to the target
        if (arr[index] <= target) {
            // Include the element in the current combination
            ds.push_back(arr[index]);
            // Explore further with the same element (allowing unlimited use)
            findCombinations(index, arr, target - arr[index], ans, ds);
            // Exclude the element and backtrack
            ds.pop_back();
        }

        // Explore the next element without including the current one
        findCombinations(index + 1, arr, target, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans; // To store all unique combinations
        vector<int> comb; // To store the current combination
        findCombinations(0, candidates, target, ans, comb); // Start finding combinations
        return ans;
    }
};
```

<img src="./Recursion Codes/Recursion_Combinational_Sum_1.png" alt="Combinational Sum - 1" style="border: 5px solid blue">

## Time Complexity: O(2^n \* k)

- Where n is the number of candidates and k is the maximum depth of recursion or the length of a combination.
- The time complexity is primarily due to the exploration of all possible combinations of elements (2^n).
- Each recursive call explores two choices: including the current element or excluding it. This results in a total of 2^n possible subsets.
- Additionally, storing each valid combination takes O(k) time, where k is the length of each combination.

## Space Complexity: O(k \* x + n)

- O(k \* x) for storing all valid combinations, where x is the number of valid combinations and k is the maximum length of each combination.
- O(n) for the recursion stack depth, where n is the depth of recursion. The maximum depth of the recursion stack is proportional to the number of elements in the input.
- The space required for the result storage and recursion stack are the main contributors to the space complexity.
