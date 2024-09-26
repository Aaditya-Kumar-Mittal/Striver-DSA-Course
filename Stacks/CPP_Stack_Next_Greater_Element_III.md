# Stack - Next Greater Element III

This markdown contains an implementation of the **Next Greater Element** problem. The solution is optimized using a stack-based approach to efficiently find the next greater element for each element in an array.

## Problem Statement

For every element in the given array, find the next greater element (NGE), i.e., the first element to the right which is greater than the current element. If no such element exists, return `-1` for that element.

### Example

Given an array `[4, 5, 2, 25]`, the **Next Greater Element** array would be:  
`[5, 25, 25, -1]`.

## Key Operations

- **Next Greater Element (NGE)**: For each element in the array, the NGE is the first larger element to its right.
- If no such greater element exists, return `-1`.

## Approach

### Stack-Based Approach

- **Stack for Comparisons**:  
  The stack is used to store elements from right to left as we traverse the array.
- **Pushing and Popping**:

  - For each element, remove all smaller or equal elements from the stack.
  - Push the current element into the stack for future comparisons.

- **Assigning NGE**:
  - If the stack is empty after popping smaller elements, the NGE for the current element is `-1`.
  - If not empty, the top element of the stack is the next greater element for the current element.

---

## Detailed Steps

1. **Initialize NGE Array**:

   - Create a vector `NGE` to store the results.
   - Use the same size as the input array.

2. **Traverse from Right to Left**:
   - Start iterating the array from the last element to the first.
3. **Stack Operations**:

   - **Pop Elements**:  
     Pop elements from the stack that are smaller or equal to the current element since they cannot be NGE for future elements.
   - **Assign NGE**:
     - If the stack is empty, set the NGE of the current element as `-1`.
     - Otherwise, set it as the top element of the stack.
   - **Push Current Element**:  
     Push the current element into the stack for future comparisons.

4. **Return the NGE Vector**:
   - After the loop completes, return the vector containing the next greater elements.

---

## Time and Space Complexity

### Time Complexity

- **O(n)**:  
  Each element is pushed and popped from the stack at most once.  
  Hence, the overall time complexity is linear.

### Space Complexity

- **O(n)**:  
  Due to the stack and the result vector storing up to `n` elements.

---

## Edge Cases

- **Last Element**:  
  The last element of the array will always have a next greater element of `-1` since no elements exist to its right.

- **All Elements Decreasing**:  
  In the case where all elements are in decreasing order (e.g., `[5, 4, 3, 2, 1]`), the result will be `[-1, -1, -1, -1, -1]`.

---

## Code with Documentation Comments

```cpp
#include<bits/stdc++.h>
using namespace std;

/**
 * Function to find the next greater element for each element in the array.
 * The approach uses a stack to maintain elements for which we haven't yet found the next greater element.
 * We traverse the array from right to left, ensuring that at each element, we know the next greater element if it exists.
 */
class Solution {
    public:

    /**
     * Function to find the next greater element for each element of the array.
     * @param nums - The input array of elements.
     * @param n - The size of the array.
     * @return A vector containing the next greater elements.
     */
    vector<long long> nextLargerElement(vector<long long> nums, int n) {
        vector<long long> NGE(n); // Vector to store the next greater elements
        stack<long long> st;      // Stack to store elements for which we are finding the NGE

        // Traverse the array from right to left
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller or equal to the current element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If the stack is empty, no greater element exists, set NGE[i] to -1
            if (st.empty()) {
                NGE[i] = -1;
            } else {
                // The top element of the stack is the next greater element
                NGE[i] = st.top();
            }

            // Push the current element to the stack for future comparisons
            st.push(nums[i]);
        }

        return NGE; // Return the vector containing the next greater elements
    }
};

/****************************************************************
 Problem Name: Next Greater Element

 Time Complexity:
 - O(n), where n is the number of elements in the input array.
   Each element is pushed and popped from the stack at most once,
   so the overall time complexity is linear.

 Space Complexity:
 - O(n), where n is the number of elements in the input array.
   This is due to the use of the stack and the result vector,
   both of which may store up to n elements.

 Approach:
 1. **Stack-Based Approach**:
    - As we traverse the array from right to left, the stack helps us efficiently find the next greater element for each item.
    - For each element, we remove all smaller elements from the stack because they can't be the next greater element for any subsequent elements.
    - The first element left in the stack that is greater than the current element becomes its next greater element.
 2. **Edge Cases**:
    - The last element in the array will always have a next greater element of `-1`, as there are no elements to its right.
 ****************************************************************/

/**
 * Driver function to test the solution.
 */
int main() {
    // Number of test cases
    int t;
    cin >> t;

    // Loop over each test case
    while (t--) {
        int n;
        cin >> n;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Creating an instance of the Solution class
        Solution obj;
        vector<long long> res = obj.nextLargerElement(arr, n);

        // Output the next greater elements
        for (long long i : res) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}

```

## Example Input and Output

### Input

```plaintext
1
4
1 3 2 4
```

### Output

```plaintext
3 4 4 -1
```

## Conclusion

This implementation of the **Next Greater Element** problem efficiently finds the next greater element for each element in the array using a stack-based approach. The time complexity is optimal for large inputs due to its linear behavior.
