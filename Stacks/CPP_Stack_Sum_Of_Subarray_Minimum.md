# Stack - Sum of Subarray Minimums

This C++ program efficiently calculates the sum of the minimum elements of all possible contiguous subarrays from a given array. The result is computed modulo `1e9 + 7` to handle large sums.

## Problem Statement

Given an array of integers `arr`, find the sum of `min(b)` where `b` ranges over every (contiguous) subarray of `arr`. Since the result may be large, return the result modulo `10^9 + 7`.

### Example 1

**Input**:  
`arr = [3,1,2,4]`  
**Output**:  
`17`

**Explanation**:  
The subarrays are: `[3]`, `[1]`, `[2]`, `[4]`, `[3,1]`, `[1,2]`, `[2,4]`, `[3,1,2]`, `[1,2,4]`, `[3,1,2,4]`.  
Minimums for each subarray: `3, 1, 2, 4, 1, 1, 2, 1, 1, 1`.  
Sum of minimums = `17`.

### Example 2

**Input**:  
`arr = [11,81,94,43,3]`  
**Output**:  
`444`

### Constraints

- `1 <= arr.length <= 3 * 10^4`
- `1 <= arr[i] <= 3 * 10^4`

## Approach

The solution uses two key auxiliary arrays:

1. **Next Smaller Element (`nse`)**: Stores the index of the next smaller element for each element of the array.
2. **Previous Smaller or Equal Element (`psee`)**: Stores the index of the previous smaller or equal element for each element of the array.

These two arrays help determine how many subarrays each element is the minimum in, allowing efficient computation of the sum of subarray minimums.

### Key Functions

- **`nextSmallerElement()`**: Finds the next smaller element for each element in the array.
- **`previousSmallerEqualElement()`**: Finds the previous smaller or equal element for each element in the array.
- **`sumSubarrayMins()`**: Uses the above two functions to compute the contribution of each element as the minimum in various subarrays, and calculates the total sum modulo `1e9 + 7`.

## Code with Detailed Comments

```cpp
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * Function to compute the next smaller element indices for each element in the array.
     * @param arr - input array of integers
     * @return vector of indices where each index corresponds to the next smaller element for arr[i]
     */
    vector<int> nextSmallerElement(vector<int>& arr) {
        vector<int> NSE(arr.size());  // Result array to store next smaller element indices
        stack<int> st;  // Stack to track elements' indices

        // Traverse the array from right to left
        for (int i = arr.size() - 1; i >= 0; i--) {
            // Pop elements from the stack until we find a smaller element
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();

            // If stack is empty, no smaller element to the right; otherwise, the stack's top has the next smaller element's index
            NSE[i] = st.empty() ? arr.size() : st.top();

            // Push the current index to the stack for further comparisons
            st.push(i);
        }
        return NSE;
    }

    /**
     * Function to compute the previous smaller or equal element indices for each element in the array.
     * @param arr - input array of integers
     * @return vector of indices where each index corresponds to the previous smaller or equal element for arr[i]
     */
    vector<int> previousSmallerEqualElement(vector<int>& arr) {
        vector<int> PSEE(arr.size());  // Result array to store previous smaller or equal element indices
        stack<int> st;  // Stack to track elements' indices

        // Traverse the array from left to right
        for (int i = 0; i < arr.size(); i++) {
            // Pop elements from the stack until we find a smaller or equal element
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();

            // If stack is empty, no smaller or equal element to the left; otherwise, the stack's top has the previous smaller/equal element's index
            PSEE[i] = st.empty() ? -1 : st.top();

            // Push the current index to the stack for further comparisons
            st.push(i);
        }
        return PSEE;
    }

    /**
     * Main function to compute the sum of subarray minimums.
     * @param arr - input array of integers
     * @return total sum of subarray minimums, modulo 1e9+7
     */
    int sumSubarrayMins(vector<int>& arr) {
        // Optimize input/output operations
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);

        // Get the next smaller element and previous smaller or equal element arrays
        vector<int> nse = nextSmallerElement(arr);
        vector<int> psee = previousSmallerEqualElement(arr);

        long long total = 0;  // Variable to store the total sum
        int mod = 1e9 + 7;    // Modulo constant

        // Traverse the array and calculate the contribution of each element
        for (int i = 0; i < arr.size(); i++) {
            // Number of subarrays where arr[i] is the minimum from the left
            int left = i - psee[i];
            // Number of subarrays where arr[i] is the minimum from the right
            int right = nse[i] - i;

            // Contribution of arr[i] to the sum of subarray minimums
            total = (total + (1LL * right * left % mod) * arr[i] % mod) % mod;
        }

        return total;  // Return the total sum modulo 1e9 + 7
    }
};
```

## Explanation of the Key Functions

1. **`nextSmallerElement()`**:  
   This function returns the index of the next smaller element for each array element. It uses a stack to maintain the indices of elements, and for each element, pops from the stack until a smaller element is found. If no such element is found, it returns the size of the array.

2. **`previousSmallerEqualElement()`**:  
   Similar to the above function, but this one works from left to right and finds the previous smaller or equal element for each element in the array.

3. **`sumSubarrayMins()`**:  
   This is the main function that calculates the total sum of subarray minimums. For each element, it calculates the number of subarrays in which the element is the minimum by multiplying the number of subarrays on the left and the right where the element is the smallest. The contribution of each element is calculated and added to the total sum modulo `1e9 + 7`.

## Time and Space Complexity

- **Time Complexity**: `O(n)` where `n` is the size of the input array. This is because each element is processed only once in both `nextSmallerElement` and `previousSmallerEqualElement`.
- **Space Complexity**: `O(n)` for storing the `nse`, `psee`, and the stack used in both the element-finding functions.

## Conclusion

This solution optimally computes the sum of subarray minimums using stacks and two auxiliary arrays. It efficiently processes the array in linear time and handles large inputs by taking results modulo `1e9 + 7`.

## Other Methods

### Method - 2

```cpp
inline const auto optimize = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return 0;
}();

class Solution {
    using ST = std::int64_t;
public:
    static constexpr int sumSubarrayMins(const std::vector<int>& arr) {
        // ok, let's think boys an girls.
        // so, this is an interesting question.
        // We could use a segment tree, but I don't want to do that.
        // Now let's think about this a bit. our hint is that it is most likley using a stack.


        // A minimum number essentially acts as a firewall. If we had "next smaller" and "previous" smaller
        // for each, then we know the answer, don't we?


        const int N = arr.size();

        std::vector<int> prevSmaller(N, -1);
        std::vector<int> nextSmaller(N, N);

        // We do next smaller here.
        std::vector<int> st;
        for (int i = 0; i < N; i++) {
            const int x = arr[i];
            while (!st.empty() && x < arr[st.back()]) {
                nextSmaller[st.back()] = i;
                st.pop_back();
            }

            if (!st.empty()) {
                prevSmaller[i] = st.back();
            }
            st.push_back(i);
        }


        ST ans = 0;
        constexpr ST MODN = 1000000007;


        for (int i = 0; i < N; i++) {
            // ok, now let's see how many subsets I am the smallest element
            const int leftSpace = i - prevSmaller[i];
            const int rightSpace = nextSmaller[i] - i;
            const ST numArrays = (leftSpace*rightSpace);
            ans += numArrays * arr[i];
            ans %= MODN;
        }





        return ans;
    }
};
```
