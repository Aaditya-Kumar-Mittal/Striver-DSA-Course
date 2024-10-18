# Kth Smallest Element in an Array

## Table of Contents

- [Kth Smallest Element in an Array](#kth-smallest-element-in-an-array)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Constraints](#constraints)
  - [Solution Overview](#solution-overview)
    - [Approach](#approach)
  - [Code Explanation](#code-explanation)
    - [Explanation](#explanation)
  - [Example](#example)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Usage](#usage)
  - [Time and Space Complexity](#time-and-space-complexity)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)

---

## Problem Description

**Problem**: Given an integer array `A` and an integer `B`, return the `B`th smallest element in the array.

- The `B`th smallest element is determined by its position in the sorted order, but the goal is to find it without fully sorting the array.
- You can assume that `B` is always valid, meaning `1 ≤ B ≤ A.size()`.

### Input

- `A` (`vector<int>`): The input vector of integers.
- `B` (int): The position of the desired smallest element.

### Output

- An integer representing the `B`th smallest element in the array.

### Constraints

- `1 <= B <= A.size() <= 10^5`
- `-10^4 <= A[i] <= 10^4`

---

## Solution Overview

### Approach

1. **Using Sorting (Brute Force)**:

   - Sort the array in ascending order and return the `B`th element from the beginning.
   - **Time Complexity**: `O(n log n)` due to sorting.
   - This approach is straightforward but not optimal for large arrays.

2. **Using a Max Heap (Priority Queue)**:
   - Use a max-heap of size `B` to keep track of the `B` smallest elements seen so far.
   - Iterate through the array and maintain a heap of size `B` such that the root contains the largest element among the `B` smallest elements.
   - **Time Complexity**: `O(n log B)` as each insertion into the heap of size `B` takes `O(log B)` time.
   - **Space Complexity**: `O(B)` since the heap stores `B` elements.

---

## Code Explanation

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @class Solution
 * @brief A class to find the kth smallest element in an array.
 */
class Solution {
public:
    /**
     * @brief Finds the kth smallest element in the given array.
     *
     * This function implements a max-heap solution to find the kth smallest element.
     *
     * @param A The input vector of integers.
     * @param B The position (1-indexed) of the smallest element to find.
     * @return The Bth smallest element.
     */
    int kthsmallest(const vector<int>& A, int B) {
        // Using a Max-Heap with size `B` to store the B smallest elements.
        priority_queue<int> pq;

        // Iterate over each element in the array.
        for (int a : A) {
            pq.push(a);  // Insert the element into the max-heap.

            // If the size of the heap exceeds `B`, remove the largest element.
            if (pq.size() > B) {
                pq.pop();
            }
        }

        // The root of the max-heap is the Bth smallest element.
        return pq.top();
    }
};
```

### Explanation

1. **Max-Heap**: A max-heap is maintained using `priority_queue<int>`:
   - This keeps the largest element at the top.
   - Only the `B` smallest elements are maintained in the heap.
2. **Heap Adjustment**:
   - For each element, if the heap size exceeds `B`, the largest element is removed.
   - This ensures that the heap only contains the `B` smallest elements.
3. **Return Bth Smallest**: The top of the max-heap will contain the `B`th smallest element when all elements have been processed.

---

## Example

### Example 1

**Input**:

- `A = [7, 10, 4, 3, 20, 15]`
- `B = 3`

**Output**:

- `7`

**Explanation**: After sorting the array, `[3, 4, 7, 10, 15, 20]`, the 3rd smallest element is `7`.

### Example 2

**Input**:

- `A = [7, 10, 4, 20, 15]`
- `B = 4`

**Output**:

- `15`

**Explanation**: After sorting the array, `[4, 7, 10, 15, 20]`, the 4th smallest element is `15`.

---

## Usage

To use the solution:

1. Create an instance of the `Solution` class.
2. Call the `kthsmallest` method with the input array and the desired `B`.

```cpp
int main() {
    vector<int> A = {7, 10, 4, 3, 20, 15};
    int B = 3;
    Solution solution;
    cout << solution.kthsmallest(A, B) << endl;  // Output: 7
    return 0;
}
```

---

## Time and Space Complexity

### Time Complexity

- **Using Max-Heap**: `O(n log B)`
  - For each of the `n` elements, inserting into a heap of size `B` takes `O(log B)` time.
- **Brute Force (Sorting)**: `O(n log n)`
  - Sorting the entire array takes `O(n log n)` time.

### Space Complexity

- **Using Max-Heap**: `O(B)`
  - The max-heap stores at most `B` elements at any time.
- **Brute Force (Sorting)**: `O(1)` if sorting in-place, but it can be `O(n)` if the sort function uses extra space.
