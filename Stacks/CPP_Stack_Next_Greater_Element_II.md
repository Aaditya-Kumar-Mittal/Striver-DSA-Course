# Stack - Next Greater Element in a Circular Array

This program finds the **next greater element** for each element in a circular array. A **circular array** means that after the last element, the first element is considered again (i.e., it "wraps around"). The approach utilizes a stack to efficiently compute the next greater element (NGE) for each element.

---

## Problem Description

- Given a circular array `nums`, for each element in `nums`, we need to find the **next greater element** (NGE).
- The next greater element for a number `x` is the first number greater than `x` traversing in a circular manner.
- If no such element exists, we return `-1` for that number.

---

## Approach

### Stack-Based Approach

- A **stack** is used to store elements that we haven't yet found the next greater element for.
- The array is processed **twice** (circular nature), using the stack to maintain candidates for the NGE.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    // Function to find the next greater element in a circular array.
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();             // Size of the array
        vector<int> NGE(n);              // Vector to store the next greater elements
        stack<int> st;                   // Stack to store indices of elements

        // First pass: Push elements (except the last one) onto the stack
        // to process them later in circular fashion
        for (int i = n - 2; i >= 0; i--) {
            st.push(nums[i]);
        }

        // Second pass: Process the array as a circular array
        for (int i = n - 1; i >= 0; i--) {
            // Pop elements from the stack that are smaller or equal to the current element
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no greater element exists, set NGE[i] to -1
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
```

---

## Explanation

1. **Circular Array**:

   - A **circular array** allows the traversal to wrap around.
   - After the last element, we consider the first element to follow.

2. **First Pass**:

   - In the first pass, we push elements from the second last to the first into the stack, **excluding** the last element. This sets up the stack for circular comparison.

3. **Second Pass**:
   - In the second pass, we process the array and the stack. For each element, we pop from the stack all smaller or equal elements since they cannot be the **next greater element** for any subsequent element.
   - If the stack is empty, it means no greater element exists for that element, so we assign `-1`. Otherwise, the top of the stack is the next greater element.
   - The current element is then pushed to the stack for future comparison.

---

## Edge Cases

1. **Single Element Array**:

   - If the array contains a single element, it has no next greater element, so the result is `-1`.

2. **All Elements are Equal**:

   - If all elements in the array are equal, none will have a greater element, so the result will be an array filled with `-1`.

3. **Descending Order Array**:
   - For an array in descending order, each element will have the first element (or no element) as the next greater element.

---

## Time Complexity

- **O(n)**: Each element is pushed and popped from the stack at most once, making the overall time complexity linear.

## Space Complexity

- **O(n)**: The result vector and stack can each store up to `n` elements, where `n` is the number of elements in the input array.

---

## Driver Code

```cpp
// Driver function to test the solution
int main() {
    // Number of test cases
    int t;
    cin >> t;

    // Loop over each test case
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);

        // Input the array elements
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Create an instance of the Solution class
        Solution obj;
        vector<int> res = obj.nextGreaterElements(arr);

        // Output the next greater elements
        for (int i : res) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
```

## Additional Notes

1. The circular nature of the array is **handled by traversing the array twice**.
2. **Stack-based algorithms** like this are efficient for solving problems where we need to find the next greater or smaller element in an array, as the stack helps in maintaining the **monotonic property** for comparisons.
3. Each element is **processed once**, ensuring that the solution is **linear in complexity**.

## Example

For input array `nums = [5, 3, 6, 2, 1]`:

- The output will be `[6, 6, -1, 5, 5]`.

Explanation:

- For `5`, the next greater element is `6`.
- For `3`, the next greater element is `6`.
- For `6`, there is no greater element, so `-1`.
- For `2`, the next greater element is `5`.
- For `1`, the next greater element is `5`.
