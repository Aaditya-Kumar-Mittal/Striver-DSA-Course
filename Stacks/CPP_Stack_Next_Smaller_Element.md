# Stack - Next Smaller Element (Help Classmate Problem)

This C++ program solves the **Next Smaller Element** problem using a stack-based approach. For each element in the array, it finds the next element on the right that is smaller than the current element and returns this information in a new array. If no such smaller element exists, `-1` is placed at the corresponding position.

## Problem Statement

Given an array of integers, for each element in the array, find the **next smaller element** to the right. If there is no smaller element to the right, return `-1`.

### Input Format

- The first line contains an integer `t` denoting the number of test cases.
- For each test case:
  - The first line contains an integer `n` denoting the size of the array.
  - The second line contains `n` space-separated integers representing the elements of the array.

### Output Format

For each test case, output `n` space-separated integers representing the next smaller element for each array element. If no smaller element exists, output `-1`.

## Approach

This solution uses a **stack** to keep track of elements and efficiently find the next smaller element for each item in the array in a **reverse traversal** (from right to left). The algorithm runs in linear time `O(n)` for each test case.

### Key Steps

1. **Traverse the array from right to left**:

   - For each element, pop elements from the stack as long as the stack's top is greater than or equal to the current element.
   - After removing larger or equal elements, if the stack is empty, no smaller element exists for the current element; thus, set the result as `-1`.
   - Otherwise, the top of the stack represents the next smaller element.
   - Push the current element onto the stack for future comparisons.

2. **Return the result vector**:
   - The result vector contains the next smaller element for each element of the array.

## Code

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function Template for C++
class Solution {
public:
    vector<int> help_classmate(vector<int> arr, int n) {
        vector<int> NSE(n);  // Result vector to store next smaller elements
        stack<int> st;  // Stack to store elements for comparison

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from stack while top of stack is >= current element
            while (!st.empty() && st.top() >= arr[i])
                st.pop();

            // If stack is empty, there is no smaller element
            if (st.empty())
                NSE[i] = -1;
            else
                NSE[i] = st.top();  // Top of the stack is the next smaller element

            // Push the current element onto the stack
            st.push(arr[i]);
        }

        return NSE;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> array(n);
        for (int i = 0; i < n; ++i) {
            cin >> array[i];
        }
        Solution obj;
        vector<int> result = obj.help_classmate(array, n);
        for (int i = 0; i < n; ++i) {
            cout << result[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
```

## Example

### Input

```plaintext
2
4
3 8 4 1
5
5 2 6 1 9
```

### Output

```plaintext
1 4 1 -1
2 1 1 -1 -1
```

### Explanation

#### Test Case 1

- For element `3`, the next smaller element is `1`.
- For element `8`, the next smaller element is `4`.
- For element `4`, the next smaller element is `1`.
- For element `1`, there is no smaller element to the right, so it returns `-1`.

#### Test Case 2

- For element `5`, the next smaller element is `2`.
- For element `2`, the next smaller element is `1`.
- For element `6`, the next smaller element is `1`.
- For element `1`, there is no smaller element to the right, so it returns `-1`.
- For element `9`, there is no smaller element to the right, so it returns `-1`.

## Time Complexity

- **Time Complexity**: `O(n)` for each test case, where `n` is the number of elements in the array. This is because each element is pushed and popped from the stack at most once.
- **Space Complexity**: `O(n)` for the result vector and the stack.

## Conclusion

The stack-based approach efficiently solves the problem by maintaining a comparison stack and processing each element in linear time. It ensures that the program can handle larger inputs within the time limits, making it an optimal solution for the **Next Smaller Element** problem.
