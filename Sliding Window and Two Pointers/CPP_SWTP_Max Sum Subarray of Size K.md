# Sliding Window and Two Pointers - Max Sum Subarray of Size K

## Problem Description

This code solves the problem of finding the maximum sum of a subarray of size `K` in a given array `Arr` of size `N`. It uses the sliding window technique to efficiently calculate the sum of subarrays, making it faster than a brute-force approach.

### Approach

The solution uses a sliding window approach combined with two pointers to maintain the sum of the current window of size `K` and update it as the window slides through the array.

### Key Concepts

- **Sliding Window**: Instead of recalculating the sum of elements for every new subarray, the sliding window technique allows us to adjust the sum by removing the leftmost element of the window and adding the new rightmost element.
- **Two Pointers**: The `left` pointer represents the start of the window, and the `right` pointer represents the end of the window. As the window slides, both pointers move to maintain the window size.

### Code Implementation

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    /**
     * @brief Calculates the maximum sum of a subarray of size K.
     *
     * This function takes an integer K, a vector Arr of integers, and an integer N, which is the size of Arr.
     * It uses a sliding window technique to find the maximum sum of a subarray with length K.
     *
     * @param K The size of the subarray.
     * @param Arr The vector containing the array elements.
     * @param N The size of the array.
     * @return long The maximum sum of a subarray of size K.
     */
    long maximumSumSubarray(int K, vector<int> &Arr, int N) {
        // Initialize the sum of the first window of size K
        long sum = 0;
        for(int i = 0; i < K; i++) {
            sum += Arr[i];
        }

        // Initialize maxSum with the sum of the first window
        long maxSum = sum;

        // Initialize pointers for sliding window
        int left = 0, right = K - 1;

        // Slide the window over the array until the end
        while (right < N - 1) {
            // Move the window to the right by removing the leftmost element and adding the next element
            sum -= Arr[left];
            left++;
            right++;
            sum += Arr[right];

            // Update the maxSum if the current window sum is greater
            maxSum = max(sum, maxSum);
        }

        return maxSum;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> Arr;
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K, Arr, N) << endl;
    }
    return 0;
}
// } Driver Code Ends
```

### Explanation

1. **Initialization**:

   - Calculate the sum of the first `K` elements as the initial window sum.
   - Set `maxSum` to this initial sum, as this is the first subarray of size `K`.

2. **Sliding Window Update**:

   - Initialize `left` to `0` (start of the window) and `right` to `K - 1` (end of the window).
   - Slide the window by incrementing `left` and `right` pointers while updating the sum:
     - Subtract `Arr[left]` from `sum` (element that goes out of the window).
     - Add `Arr[right]` to `sum` (new element that enters the window).
     - Update `maxSum` with the maximum value between the current window sum and the previous `maxSum`.

3. **Return Result**:
   - After sliding through the entire array, `maxSum` will hold the maximum sum of any subarray of size `K`.

### Complexity Analysis

- **Time Complexity**: `O(N)`, where `N` is the size of the array. The sum is adjusted in constant time for each window as it slides.
- **Space Complexity**: `O(1)`, since the solution only uses a few variables for storing sums and pointers, and does not require additional data structures.

### Example

**Input**:

```plaintext
N = 5, K = 3
Arr = [1, 2, 3, 4, 5]
```

**Output**:

```plaintext
12
```

**Explanation**:

- The subarrays of size `K=3` are `[1,2,3]`, `[2,3,4]`, and `[3,4,5]`.
- Their sums are `6`, `9`, and `12`, respectively.
- The maximum sum is `12`.

### Edge Cases

1. **K equals N**: If `K` is equal to `N`, the function should return the sum of the entire array.
2. **All elements are negative**: The function should correctly handle cases where all elements are negative, returning the subarray with the least negative sum.
3. **K is 1**: When `K` is `1`, the function should return the maximum single element in the array.

### How to Run the Code

1. Input the number of test cases `t`.
2. For each test case, input `N` (number of elements in `Arr`) and `K` (size of the subarray).
3. Input `N` space-separated integers representing the elements of `Arr`.
4. The output will be the maximum sum of any subarray of size `K`.

### Conclusion

This implementation of the maximum sum subarray problem using the sliding window technique is efficient and easy to understand. It minimizes the number of operations needed by avoiding recalculating sums for overlapping elements of subarrays.
