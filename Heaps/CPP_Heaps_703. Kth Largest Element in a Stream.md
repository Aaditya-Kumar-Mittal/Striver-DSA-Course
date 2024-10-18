# Kth Largest Element in a Stream

## Table of Contents

- [Kth Largest Element in a Stream](#kth-largest-element-in-a-stream)
  - [Table of Contents](#table-of-contents)
  - [Problem Description](#problem-description)
    - [Class Requirements](#class-requirements)
    - [Input/Output](#inputoutput)
    - [Constraints](#constraints)
  - [Solution Overview](#solution-overview)
    - [Approach](#approach)
  - [Code Explanation](#code-explanation)
    - [Explanation](#explanation)
  - [Example](#example)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
  - [Time and Space Complexity](#time-and-space-complexity)
    - [Time Complexity](#time-complexity)
    - [Space Complexity](#space-complexity)
  - [Other Solutions](#other-solutions)
    - [Using Binary Search](#using-binary-search)

---

## Problem Description

**Problem**: You are tasked to implement a class that maintains the `k`th largest element in a stream of scores in real-time. This class will be used to determine the dynamic cut-off for admission based on incoming test scores.

### Class Requirements

- **`KthLargest(int k, vector<int>& nums)`**: Initializes the object with an integer `k` and an initial list of scores `nums`.
- **`int add(int val)`**: Adds a new score `val` to the stream and returns the `k`th largest score among all the scores seen so far.

### Input/Output

- Input:
  - `k`: An integer representing the desired `k`th largest score.
  - `nums`: A vector of integers representing the initial list of scores.
  - `val`: An integer score to be added to the stream.
- Output:
  - After calling the `add` function, it should return the `k`th largest score.

### Constraints

- `0 <= nums.length <= 10^4`
- `1 <= k <= nums.length + 1`
- `-10^4 <= nums[i] <= 10^4`
- `-10^4 <= val <= 10^4`
- At most `10^4` calls will be made to `add`.

---

## Solution Overview

### Approach

1. **Using a Min-Heap (Priority Queue)**:
   - Use a min-heap (priority queue) of size `k` to keep track of the `k` largest elements in the stream.
   - The root of the min-heap will hold the `k`th largest element.
   - As new elements are added:
     - If the size of the heap is less than `k`, simply push the element.
     - If the size equals `k` and the new element is larger than the root of the heap, replace the root (pop and push).
   - This ensures that the heap always contains the largest `k` elements.

---

## Code Explanation

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @class KthLargest
 * @brief A class to find the kth largest element in a stream of integers.
 */
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap to store the k largest elements.
    int globalK;  // Stores the value of k to find the kth largest element.

    /**
     * @brief Constructor that initializes the class with the integer k and initial list of numbers.
     * @param k The position (1-indexed) of the largest element to maintain.
     * @param nums The initial list of numbers in the stream.
     */
    KthLargest(int k, vector<int>& nums) {
        globalK = k;
        // Initialize the min-heap with the k largest elements from nums.
        for (auto x : nums) {
            if (pq.size() < k) {
                pq.push(x);
            } else if (pq.size() == k && x >= pq.top()) {
                pq.push(x);
            }
            if (pq.size() > k) {
                pq.pop();  // Keep the heap size exactly equal to k.
            }
        }
    }

    /**
     * @brief Adds a new number to the stream and returns the kth largest element.
     * @param val The new number to be added.
     * @return The kth largest element after adding the new number.
     */
    int add(int val) {
        // If the heap size is less than k, directly add the value.
        if (pq.size() < globalK) {
            pq.push(val);
        }
        // If the value is greater than or equal to the smallest in the heap, replace it.
        else if (pq.size() == globalK && val >= pq.top()) {
            pq.push(val);
        }
        // Maintain the size of the heap to be k by removing the smallest element.
        if (pq.size() > globalK) {
            pq.pop();
        }
        // The top of the min-heap is the kth largest element.
        return pq.top();
    }
};

/**
 * Usage Example:
 * KthLargest* obj = new KthLargest(k, nums);
 * int result = obj->add(val);
 */
```

### Explanation

1. **Min-Heap**: A min-heap is used to efficiently keep track of the `k` largest elements:
   - It stores the smallest of the `k` largest elements at its root.
2. **Heap Initialization**:
   - For each element in `nums`, it is pushed into the heap if the heap size is less than `k`.
   - If the heap size is `k` and the new element is greater than or equal to the root, it replaces the root.
   - This ensures that only the largest `k` elements are kept.
3. **Adding New Elements**:
   - When a new score is added via `add(val)`, it follows the same logic to maintain the `k` largest elements in the heap.
   - The root of the heap (`pq.top()`) is the `k`th largest element after each addition.

---

## Example

### Example 1

**Input**:

- `k = 3`
- `nums = [4, 5, 8, 2]`
- `add(3) -> returns 4`
- `add(5) -> returns 5`
- `add(10) -> returns 5`
- `add(9) -> returns 8`
- `add(4) -> returns 8`

**Output**: `[null, 4, 5, 5, 8, 8]`

**Explanation**:

- After initializing with `k = 3` and `nums = [4, 5, 8, 2]`, the heap contains `[4, 5, 8]`.
- Adding `3` keeps `4` as the 3rd largest element.
- Adding `5` updates the 3rd largest to `5`.
- Adding `10` keeps `5` as the 3rd largest.
- Adding `9` updates the 3rd largest to `8`.
- Adding `4` keeps `8` as the 3rd largest.

### Example 2

**Input**:

- `k = 4`
- `nums = [7, 7, 7, 7, 8, 3]`
- `add(2) -> returns 7`
- `add(10) -> returns 7`
- `add(9) -> returns 7`
- `add(9) -> returns 8`

**Output**: `[null, 7, 7, 7, 8]`

**Explanation**:

- After initializing with `k = 4` and `nums = [7, 7, 7, 7, 8, 3]`, the heap contains `[7, 7, 7, 8]`.
- Adding values adjusts the `k`th largest as per the conditions.

---

## Time and Space Complexity

### Time Complexity

- **Initialization**: `O(n log k)` where `n` is the number of initial elements in `nums` since each insertion into the heap of size `k` takes `O(log k)`.
- **Adding Elements**: `O(log k)` for each `add` operation due to heap insertion.

### Space Complexity

- **Space**: `O(k)` as we maintain a heap of size `k`.

## Other Solutions

### Using Binary Search

```cpp
class KthLargest {
public:
    vector<int> stream;
    int k;

    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (int num : nums) {
            stream.push_back(num);
        }
        sort(stream.begin(), stream.end());
    }

    int add(int val) {
        int index = getIndex(val);
        // Add val to correct position
        stream.insert(stream.begin() + index, val);
        return stream[stream.size() - k];
    }

private:
    int getIndex(int val) {
        int left = 0;
        int right = stream.size() - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            int midValue = stream[mid];
            if (midValue == val) return mid;
            if (midValue > val) {
                // Go to left half
                right = mid - 1;
            } else {
                // Go to right half
                left = mid + 1;
            }
        }
        return left;
    }
};
```
