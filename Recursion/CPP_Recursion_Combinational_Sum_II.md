# Recursion Problem - Combination Sum II

## Approach

1. Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
2. Each number in candidates may only be used once in the combination.
3. The solution set must not contain duplicate combinations.
4. The problem asks to find all unique combinations of numbers that sum to a given target.
5. The candidates array might contain duplicates, so we must ensure that the result set does not have duplicate combinations.
6. To handle duplicates, the input array is sorted, and we skip over repeated elements within the recursion by checking `arr[i] == arr[i-1]`.
7. We use backtracking to explore all possible combinations by choosing or skipping each element.
8. If an element exceeds the remaining target, we break the loop early to save unnecessary calculations.

```cpp
class Solution {
public:

    // Helper function to find combinations that sum to the target
    void findCombinations(int index, vector<int> &arr, int target, vector<int> &comb, vector<vector<int>> &ans){

        // Base condition: if target becomes 0, we found a valid combination
        if(target == 0){
            ans.push_back(comb);  // Add the current combination to the answer list
            return;
        }

        // Loop through the array starting from the current index
        for(int i = index; i < arr.size(); i++){

            // Skip duplicates: to avoid selecting the same element multiple times in different recursive calls
            if( i > index && arr[i] == arr[i-1]) continue;

            // If the current element exceeds the target, no point in continuing further
            if(arr[i] > target) break;

            // Include the current element in the combination
            comb.push_back(arr[i]);

            // Recur for the next elements with updated target (target - arr[i])
            findCombinations(i+1, arr, target - arr[i], comb, ans);

            // Backtrack by removing the current element from the combination
            comb.pop_back();
        }
    }

    // Main function to return all unique combinations that sum to the target
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        // Sort the candidates to facilitate skipping duplicates
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;  // Result vector to store all unique combinations

        vector<int> comb;  // Temporary vector to store each valid combination

        // Call the helper function to find combinations starting from index 0
        findCombinations(0, candidates, target, comb, ans);

        return ans;
    }
};
```

## Time Complexity

- Sorting the input array takes O(N log N), where N is the number of elements in `candidates`.
- The recursive function explores all subsets, so the time complexity is O(2^N) in the worst case.
- Overall time complexity: O(N log N + 2^N).

## Space Complexity

- The recursion stack can go as deep as O(N) (if all elements are included in the combination).
- Additional space is used to store the combinations and candidates, so the space complexity is O(N).
