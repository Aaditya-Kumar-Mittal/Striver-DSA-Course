# Convert Min Heap to Max Heap

## Table of Contents

- [Convert Min Heap to Max Heap](#convert-min-heap-to-max-heap)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Input](#input)
    - [Output](#output)
    - [Constraints](#constraints)
  - [Solution Overview](#solution-overview)
    - [Approach](#approach)
  - [Code Explanation](#code-explanation)
  - [Example](#example)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Usage](#usage)
  - [Time and Space Complexity](#time-and-space-complexity)

---

## Problem Description

Given an array that represents a Min Heap, the task is to convert it into a Max Heap. A **Min Heap** is a binary tree where the parent node is always less than or equal to its child nodes. In contrast, a **Max Heap** is a binary tree where the parent node is always greater than or equal to its child nodes.

### Input

- `t` (Number of test cases)
- `n` (Number of elements in the array)
- `arr[]` (Array elements representing a Min Heap)

### Output

- Converted array representing a Max Heap.

### Constraints

- `1 ≤ t ≤ 100` (Number of test cases)
- `1 ≤ n ≤ 10^5` (Size of the array)
- `1 ≤ arr[i] ≤ 10^5` (Element values)

---

## Solution Overview

The conversion process involves ensuring that the **Max Heap property** is maintained: every parent node should be greater than or equal to its child nodes. We achieve this by iterating through the internal nodes of the Min Heap and applying the **Max-Heapify** operation.

### Approach

1. **Max-Heapify Operation**: Adjusts a given node to maintain the Max Heap property.
2. **Convert Function**: Converts the Min Heap to a Max Heap by applying `maxHeapify` starting from the last non-leaf node and moving upwards.

---

## Code Explanation

Here's the code with inline comments for better understanding:

```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * @brief Performs the Max-Heapify operation on the heap.
     * @param arr The array representing the heap.
     * @param N The size of the heap.
     * @param index The index of the element to heapify.
     *
     * Max-Heapify ensures that the subtree rooted at `index` maintains
     * the max-heap property.
     */
    void maxHeapify(vector<int> &arr, int N, int index) {
        int leftChild = (2 * index) + 1;
        int rightChild = (2 * index) + 2;
        int largest = index;

        // Compare with left child
        if (leftChild < N && arr[leftChild] > arr[largest]) {
            largest = leftChild;
        }

        // Compare with right child
        if (rightChild < N && arr[rightChild] > arr[largest]) {
            largest = rightChild;
        }

        // If the largest is not the current index, swap and recursively heapify
        if (largest != index) {
            swap(arr[largest], arr[index]);
            maxHeapify(arr, N, largest);
        }
    }

    /**
     * @brief Converts a Min Heap into a Max Heap.
     * @param arr The array representing the Min Heap.
     * @param N The size of the array.
     *
     * This function iteratively calls `maxHeapify` on all non-leaf nodes
     * to transform the given Min Heap array into a Max Heap array.
     */
    void convertMinToMaxHeap(vector<int> &arr, int N) {
        // Start from the last non-leaf node and apply `maxHeapify` upwards.
        for (int i = (N - 2) / 2; i >= 0; i--) {
            maxHeapify(arr, N, i);
        }
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<int> vec(n);

        // Input array elements
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
        }

        // Creating an object of Solution class
        Solution obj;

        // Convert Min Heap to Max Heap
        obj.convertMinToMaxHeap(vec, n);

        // Output the Max Heap array
        for (int i = 0; i < n; i++) {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
```

---

## Example

### Example 1

**Input**:

```plaintext
t = 1
n = 6
arr[] = {3, 5, 9, 6, 8, 20}
```

**Output**:

```plaintext
20 8 9 6 5 3
```

**Explanation**:
The initial array represents a Min Heap:

```plaintext
       3
     /   \
    5     9
   / \   /
  6   8 20
```

After converting it into a Max Heap:

```plaintext
       20
      /  \
     8    9
    / \  /
   6  5  3
```

### Example 2

**Input**:

```plaintext
t = 1
n = 4
arr[] = {1, 2, 3, 4}
```

**Output**:

```plaintext
4 2 3 1
```

---

## Usage

To run this program, follow these steps:

1. **Compile** the program using:

   ```bash
   g++ -o convertHeap convert_heap.cpp
   ```

2. **Run** the compiled program:

   ```bash
   ./convertHeap
   ```

3. **Input** the number of test cases and arrays as prompted.

---

## Time and Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the number of elements in the heap.
  - Building a heap with `maxHeapify` from the bottom up takes linear time.
- **Space Complexity**: `O(1)` (ignoring the space required for input) since heap conversion is done in-place.

---
