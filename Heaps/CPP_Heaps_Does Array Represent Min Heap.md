# Does Array Represent Min-Heap

<!-- markdownlint-disable MD024 -->

## Problem Description

**Problem**: Given an array `A` of size `n`, the task is to check if the given array can be a level-order representation of a **Min Heap**.

### Min Heap Definition

A **Min Heap** is a complete binary tree in which:

- The value of each node is less than or equal to the values of its children.
- In a level-order traversal, each node's value should be less than or equal to the values of its children.

### Example 1

**Input**:

```plaintext
A = {2, 3, 5, 8, 10}
```

**Output**: `The given array is a min-heap`

**Explanation**:
The given array represents the following tree:

```plaintext
       2
     /   \
    3     5
   / \
  8   10
```

This tree follows the min-heap property because every parent node is less than or equal to its children.

### Example 2

**Input**:

```plaintext
A = {10, 3, 5, 8, 2}
```

**Output**: `The given array is not a min-heap`

**Explanation**:
The given array represents the following tree:

```plaintext
       10
     /   \
    3     5
   / \
  8   2
```

This tree does not follow the min-heap property because:

- Node `10` is greater than its children `3` and `5`.

---

## Function Signature

The function that needs to be implemented is:

```cpp
bool checkMinHeap(vector<int> const &A);
```

### Parameters

- `A`: A constant reference to a vector of integers representing the heap.

### Returns

- `True` if the given array represents a valid level-order representation of a min-heap.
- `False` otherwise.

---

## Approach

### Understanding the Problem

1. For an array to represent a min-heap:

   - The parent node should be less than or equal to both its left and right child nodes.
   - In array representation, for a node at index `i`:
     - The left child is at index `2 * i + 1`.
     - The right child is at index `2 * i + 2`.

2. Iterate through each node that has children and check the min-heap condition:
   - For every `i` from `0` to `(n-2)/2`:
     - Check if `A[i]` is less than or equal to `A[2 * i + 1]` (left child).
     - If `2 * i + 2 < n` (right child exists), also ensure `A[i]` is less than or equal to `A[2 * i + 2]` (right child).
   - If any of these conditions are violated, return `False`.
   - Otherwise, return `True`.

### Time Complexity

- **O(n)**: We iterate through all elements up to `(n-2)/2`, performing constant-time checks for each.

### Space Complexity

- **O(1)**: No additional data structures are used, making the space requirement constant.

---

## Solution Code

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Iterative function to check if a given array represents min-heap or not
bool checkMinHeap(vector<int> const &A)
{
    int n = A.size();

    // Base case: A single element or empty array is always a min-heap.
    if (n <= 1) {
        return true;
    }

    // Check for all internal nodes if their left and right children satisfy the min-heap property.
    for (int i = 0; i <= (n - 2) / 2; i++)
    {
        // If the left child is greater than the parent, return false.
        if (A[i] > A[2*i + 1]) {
            return false;
        }

        // If the right child exists and is greater than the parent, return false.
        if (2*i + 2 < n && A[i] > A[2*i + 2]) {
            return false;
        }
    }

    // If all conditions are satisfied, it's a min-heap.
    return true;
}

int main()
{
    vector<int> A = {2, 3, 5, 8, 10};

    if (checkMinHeap(A)) {
        cout << "The given array is a min-heap";
    }
    else {
        cout << "The given array is not a min-heap";
    }

    return 0;
}
```

---

## Explanation of the Code

1. **Function `checkMinHeap`**:

   - Takes a constant reference to a vector `A` as input, ensuring no copies of the array are made.
   - Handles the base case where arrays of size `0` or `1` are automatically considered min-heaps.
   - Iterates over all parent nodes (up to `(n - 2) / 2`) to check:
     - If the left child exists and is greater than the parent, return `false`.
     - If the right child exists and is greater than the parent, return `false`.
   - Returns `true` if all parent-child relationships satisfy the min-heap condition.

2. **`main` Function**:
   - Initializes a vector `A` with a test case.
   - Calls `checkMinHeap` to determine if `A` represents a valid min-heap.
   - Outputs the result.

---

## Edge Cases to Consider

1. **Single Element (`n = 1`)**: A single element always satisfies the min-heap condition.
2. **Empty Array (`n = 0`)**: Considered trivially as a min-heap since no elements exist.
3. **All Elements Equal**: An array where all elements have the same value will still satisfy the min-heap condition.
4. **Array with Increasing or Decreasing Values**:
   - Strictly increasing arrays (e.g., `[1, 2, 3, 4]`) will be a valid min-heap.
   - Strictly decreasing arrays (e.g., `[10, 9, 8, 7]`) will fail the min-heap condition.

---

## Complexity Analysis

- **Time Complexity**: `O(n)` because we iterate through all parent nodes (up to `(n - 2) / 2`) and perform a constant number of comparisons for each.
- **Space Complexity**: `O(1)` since no additional space is used beyond a few variables.

---

## Sample Input and Output

**Input**:

```plaintext
A = {2, 3, 5, 8, 10}
```

**Output**:

```plaintext
The given array is a min-heap
```

### Explanation

- For the given input, the array represents a valid min-heap where every parent node is less than or equal to its children.

**Input**:

```plaintext
A = {10, 3, 5, 8, 2}
```

**Output**:

```plaintext
The given array is not a min-heap
```

### Explanation

- In this case, the array does not represent a valid min-heap because `10` is greater than its child `3`.

---

## Conclusion

The solution effectively checks if a given array represents a valid min-heap based on the level-order property. It runs in linear time with constant space, making it suitable for large input sizes up to \(10^5\).

---

## Recursive Solution

```cpp
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a given array represents min-heap or not
bool checkMinHeap(vector<int> const A, int i)
{
    // if `i` is a leaf node, return true as every leaf node is a heap
    if (2*i + 2 > A.size()) {
        return true;
    }

    // if `i` is an internal node

    // recursively check if the left child is a heap
    bool left = (A[i] <= A[2*i + 1]) && checkMinHeap(A, 2*i + 1);

    // recursively check if the right child is a heap (to avoid the array index out
    // of bounds, first check if the right child exists or not)
    bool right = (2*i + 2 == A.size()) ||
            (A[i] <= A[2*i + 2] && checkMinHeap(A, 2*i + 2));

    // return true if both left and right child are heaps
    return left && right;
}

int main()
{
    vector<int> A = {1, 2, 3, 4, 5, 6};

    // start with index 0 (the root of the heap)
    int index = 0;

    if (checkMinHeap(A, index)) {
        cout << "The given array is a min-heap";
    }
    else {
        cout << "The given array is not a min-heap";
    }

    return 0;
}
```
