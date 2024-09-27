# Stack - Previous Smaller Element (PSE)

This program finds the **previous smaller element** for each element in an array. The **previous smaller element** of an element is defined as the closest smaller element that appears **before** the current element in the array. If no such element exists, the function returns `-1` for that element.

## Problem Description

- Given an array `A`, for each element in `A`, find the **previous smaller element** (PSE).
- The previous smaller element for a number `x` is the first number smaller than `x` to its left.
- If no such element exists, return `-1`.

## Approach

### Stack-Based Approach

- A **stack** is used to maintain elements in a **monotonically increasing order**.
- The stack helps to efficiently find the closest smaller element by comparing the current element with the stack's top.

---

## Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/*
    Function to find the previous smaller element for each element in the array.
    The approach is to use a stack to store elements in such a way that the
    top of the stack contains the closest smaller element seen so far.

    Parameters:
    - vector<int> &A: Reference to the input array.

    Returns:
    - vector<int>: A new array where each element is the previous smaller element
      for the corresponding element in the input array. If no such element exists,
      return -1.
*/
vector<int> prevSmaller(vector<int> &A) {
    int n = A.size();            // Get the size of the input array
    stack<int> st;               // Stack to store the previous smaller elements
    vector<int> PSE(n);          // Resultant array to store the previous smaller elements

    // Loop through each element in the array
    for (int i = 0; i < n; i++) {
        // Pop elements from the stack while they are greater than or equal to the current element
        while (!st.empty() && st.top() >= A[i])
            st.pop();

        // If the stack is empty, there is no smaller element on the left, so store -1
        if (st.empty())
            PSE[i] = -1;
        else
            PSE[i] = st.top();   // Else, the top of the stack is the previous smaller element

        // Push the current element to the stack for future comparisons
        st.push(A[i]);
    }

    return PSE;                  // Return the array of previous smaller elements
}
```

## Explanation

1. **Previous Smaller Element Concept**:

   - For each element in the input array, the function finds the closest smaller element **to the left**.
   - If no such element exists, the function returns `-1` for that element.

2. **Stack-Based Algorithm**:

   - The stack is used to maintain elements in **increasing order**.
   - While traversing the array, if the current element is smaller than the top of the stack, we **pop** elements until a smaller element is found or the stack is empty.
   - If the stack becomes empty, this means there is no smaller element to the left, so we assign `-1`.
   - The current element is then **pushed** to the stack for future comparisons.

3. **Key Points**:
   - Each element is **processed once**, ensuring a linear time complexity.
   - The stack helps to efficiently track the previous smaller elements.

## Edge Cases

1. **Empty Array**:

   - If the input array is empty, the function returns an empty result.

2. **All Elements in Increasing Order**:

   - If the array elements are sorted in increasing order, there will be no smaller element to the left for any element. The result will be an array filled with `-1`.

3. **Single Element Array**:
   - If the input array contains only one element, there is no element to its left, so the result is `-1`.

## Time Complexity

- **O(n)**: Each element is pushed and popped from the stack at most once, resulting in an overall time complexity of linear order.

## Space Complexity

- **O(n)**: The space complexity is determined by the stack and the resultant array, both of which can hold up to `n` elements.

## Driver Code

```cpp
// Driver function to test the solution
int main() {
    int t; // Number of test cases
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

        // Call the function and store the result
        vector<int> result = prevSmaller(arr);

        // Output the result
        for (int i : result) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
```

## Additional Notes

1. The function efficiently computes the previous smaller element using a **stack** in **linear time**.
2. The stack helps in keeping track of smaller elements in a **monotonic order**.
3. For each element in the array, we pop from the stack until a **smaller element is found** or the stack becomes empty.
4. This approach is especially useful in problems related to **nearest smaller/greater elements**.

## Example

For input array `A = [4, 5, 2, 10, 8]`:

- The output will be `[-1, 4, -1, 2, 2]`.

Explanation:

- For `4`, there is no smaller element to the left, so `-1`.
- For `5`, the previous smaller element is `4`.
- For `2`, there is no smaller element to the left, so `-1`.
- For `10`, the previous smaller element is `2`.
- For `8`, the previous smaller element is `2`.

## Summary

- The algorithm efficiently computes the previous smaller element for each element in an array using a **stack-based approach**.
- The solution has a time complexity of **O(n)**, making it suitable for large input arrays.
