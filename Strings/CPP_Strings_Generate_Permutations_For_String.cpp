//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  
    /*
        Function to generate all permutations of the string `S` starting from the given index.
        
        Parameters:
        - index: The starting index for the current permutation.
        - S: The input string whose permutations are being generated.
        - ans: A vector to store all generated permutations.
        
        The function uses backtracking with in-place swapping to generate permutations.
    */
    void genPermutes(int index, string &S, vector<string> &ans) {
        // Base case: if the current index reaches the end of the string, add the permutation to the result
        if (index == S.size()) {
            ans.push_back(S);
            return;
        }

        // Recursive case: generate permutations by swapping the current character
        // with each character in the remaining substring
        for (int i = index; i < S.size(); i++) {
            swap(S[index], S[i]);  // Swap the current index with i
            genPermutes(index + 1, S, ans);  // Recur for the next index
            swap(S[index], S[i]);  // Backtrack to the original state (undo the swap)
        }
    }

    /*
        Function to find all permutations of the string `S`.
        
        Parameters:
        - S: The input string for which we are generating all permutations.
        
        Returns:
        - A vector of strings containing all permutations of `S`.
    */
    vector<string> find_permutation(string S) {
        vector<string> ans;  // To store all permutations
        genPermutes(0, S, ans);  // Generate permutations using backtracking
        sort(ans.begin(), ans.end());  // Sort the permutations lexicographically
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;  // Number of test cases
    while (t--) {
        string S;
        cin >> S;  // Input string

        Solution ob;
        vector<string> ans = ob.find_permutation(S);  // Get permutations of the string

        // Print all permutations
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends

/*
Analysis:

Problem: Permutations of a String
Approach: Backtracking and Recursion

1. **Base Case**:
   - If the index reaches the size of the string `S`, the current permutation is pushed into the answer vector `ans`.

2. **Recursive Case**:
   - For each index, recursively swap the current character with each of the remaining characters and generate permutations by fixing one character at a time.
   - The swapping helps in generating new permutations by altering the positions of characters.

3. **Backtracking**:
   - After exploring a permutation, the function swaps back to its original state to explore new possibilities, ensuring all permutations are covered.

**Time Complexity**:
- There are `n!` (factorial of the length of the string) permutations, and each permutation takes `O(n)` time to process (due to swaps and backtracking).
- Therefore, the overall time complexity is `O(n * n!)`.

**Space Complexity**:
- The space complexity is `O(n)`, where `n` is the length of the string, due to the recursion stack used during the backtracking process.

**Example**:
For input `S = "ABC"`, the output will be:
ABC ACB BAC BCA CAB CBA
*/
