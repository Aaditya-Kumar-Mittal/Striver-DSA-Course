# Does Array Represent Max Heap

## Problem Description

**Problem**: Given an array `arr` of size `n`, the task is to check if the given array can be a level-order representation of a Max Heap.

### Max Heap Definition

A **Max Heap** is a complete binary tree in which:

- The value of each node is greater than or equal to the values of its children.
- In a level-order traversal, each node's value should be greater than or equal to the values of its children.

### Example 1

**Input**:

```plaintext
n = 6
arr[] = {90, 15, 10, 7, 12, 2}
```

**Output**: `1` (or `True`)

**Explanation**:
The given array represents the following tree:

```plaintext
       90
     /    \
   15     10
  /  \    /
 7   12  2
```

This tree follows the max-heap property because every parent node is greater than or equal to its children.

### Example 2

**Input**:

```plaintext
n = 6
arr[] = {9, 15, 10, 7, 12, 11}
```

**Output**: `0` (or `False`)

**Explanation**:
The given array represents the following tree:

```plaintext
       9
     /    \
   15     10
  /  \    /
 7   12  11
```

This tree does not follow the max-heap property because:

- Node `9` is smaller than its children `15` and `10`.
- Node `10` is smaller than its child `11`.

---

## Function Signature

The function that needs to be implemented is:

```cpp
bool isMaxHeap(int arr[], int n);
```

### Parameters

- `arr[]`: An integer array of size `n` representing the heap.
- `n`: Integer denoting the size of the array.

### Returns

- `True` if the given array represents a valid level-order representation of a max-heap.
- `False` otherwise.

---

## Approach

### Understanding the Problem

1. For an array to represent a max-heap:

   - The parent node should be greater than or equal to both its left and right child nodes.
   - In array representation, for a node at index `i`:
     - The left child is at index `2 * i + 1`.
     - The right child is at index `2 * i + 2`.

2. Iterate through each node that has children and check the max-heap condition:
   - For every `i` from `0` to `(n-2)/2`:
     - Check if `arr[i]` is greater than or equal to `arr[2 * i + 1]` (left child).
     - If `2 * i + 2 < n` (right child exists), also ensure `arr[i]` is greater than or equal to `arr[2 * i + 2]` (right child).
   - If any of these conditions are violated, return `False`.
   - Otherwise, return `True`.

### Time Complexity

- **O(n)**: We iterate through all elements up to `(n-2)/2`, performing constant-time checks for each.

### Space Complexity

- **O(1)**: No additional data structures are used, making the space requirement constant.

---

## Solution Code

```cpp
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool isMaxHeap(int arr[], int n) {
        // Special case: If there's only one or zero elements, it's always a heap.
        if (n <= 1) {
            return true;
        }

        // Iterate through all internal nodes (nodes that have at least one child)
        for (int i = 0; i <= (n - 2) / 2; i++) {
            // Check if the left child exists and is greater than the parent
            if (arr[i] < arr[2 * i + 1]) {
                return false;
            }

            // Check if the right child exists and is greater than the parent
            if (2 * i + 2 < n && arr[i] < arr[2 * i + 2]) {
                return false;
            }
        }

        // If all conditions are satisfied, it's a max-heap
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[4 * n] = {0};
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        cout << ob.isMaxHeap(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
```

---

## Explanation of the Code

1. **Driver Code Section**: Reads input values, creates an instance of the `Solution` class, and calls the `isMaxHeap` method for each test case.
2. **`isMaxHeap` Function**:
   - It first checks if the array is empty or has only one element, in which case it trivially represents a heap.
   - For other cases, it iterates over all parent nodes (those with at least one child) and checks the max-heap property with their children.
   - If a violation of the max-heap condition is found, it returns `False`.
   - Otherwise, after checking all elements, it returns `True`.

---

## Edge Cases to Consider

1. **Single Element (`n = 1`)**: A single element always satisfies the max-heap condition.
2. **Empty Array (`n = 0`)**: Considered trivially as a max-heap since no elements exist.
3. **All Elements Equal**: An array where all elements have the same value will still satisfy the max-heap condition.
4. **Array with Increasing or Decreasing Values**:
   - Strictly decreasing arrays (e.g., `[10, 9, 8, 7]`) will fail the max-heap condition.
   - Strictly increasing arrays (e.g., `[1, 2, 3, 4]`) will also fail the max-heap condition.

---

## Complexity Analysis

- **Time Complexity**: `O(n)` because we iterate through all parent nodes (up to `(n - 2) / 2`) and perform a constant number of comparisons for each.
- **Space Complexity**: `O(1)` since no additional space is used beyond a few variables.

---

## Sample Input and Output

**Input**:

```plaintext
2
6
90 15 10 7 12 2
6
9 15 10 7 12 11
```

**Output**:

```plaintext
1
0
```

### Explanation

- For the first input, the array represents a valid max-heap.
- For the second input, the array does not satisfy the max-heap property because `9` is smaller than its children.

---

## Conclusion

The solution effectively determines if a given array represents a valid max-heap based on the level-order property. It runs in linear time with constant space, making it suitable for large input sizes up to \(10^5\).
