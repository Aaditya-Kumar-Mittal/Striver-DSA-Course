# 215. Kth Largest Element in an Array

## Table of Contents

- [215. Kth Largest Element in an Array](#215-kth-largest-element-in-an-array)
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
  - [My Solution](#my-solution)

---

## Problem Description

**Problem**: Given an integer array `nums` and an integer `k`, return the `k`th largest element in the array.

- The `k`th largest element is determined by its position in the sorted array, but the goal is to find it without fully sorting the array.
- You can assume that `k` is always valid, meaning `1 ≤ k ≤ nums.length`.

### Input

- `nums` (`vector<int>`): The array of integers.
- `k` (int): The position of the desired largest element.

### Output

- An integer representing the `k`th largest element in the array.

### Constraints

- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---

## Solution Overview

### Approach

1. **Using Sorting (Brute Force)**:

   - Sort the array in ascending order and return the `k`th element from the end.
   - **Time Complexity**: `O(n log n)` due to sorting.
   - This approach is straightforward but not optimal for large arrays.

2. **Using a Max Heap (Priority Queue)**:

   - Construct a max-heap from the array using a priority queue.
   - Extract the maximum element `k` times to get the `k`th largest element.
   - **Time Complexity**: `O(k log n)` for extracting `k` elements.
   - **Space Complexity**: `O(n)` for storing elements in the heap.

3. **Using a Min-Heap**:
   - Use a min-heap of size `k` to keep track of the `k` largest elements seen so far.
   - Iterate through the array and maintain a heap of size `k` such that the root contains the `k`th largest element.
   - **Time Complexity**: `O(n log k)` as each insertion into the heap of size `k` takes `O(log k)` time.
   - **Space Complexity**: `O(k)` since the heap stores `k` elements.

---

## Code Explanation

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/**
 * @class Solution
 * @brief A class to find the kth largest element in an array.
 */
class Solution {
public:
    /**
     * @brief Finds the kth largest element in the given array.
     *
     * This function implements a min-heap solution to find the kth largest element.
     *
     * @param nums The input vector of integers.
     * @param k The position (1-indexed) of the largest element to find.
     * @return The kth largest element.
     */
    int findKthLargest(vector<int>& nums, int k) {
        // Optimizing input-output operations.
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // Using a Min-Heap with size `k` to store the k largest elements.
        priority_queue<int, vector<int>, greater<int>> pq;

        // Iterate over each element in the array.
        for (int x : nums) {
            pq.push(x);  // Insert the element into the min-heap.

            // If the size of the heap exceeds `k`, remove the smallest element.
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // The root of the heap is the kth largest element.
        return pq.top();
    }
};
```

### Explanation

1. **Optimized Input/Output**: Using `ios::sync_with_stdio(0)` and `cin.tie(0)` improves the speed of I/O operations.
2. **Min-Heap**: A min-heap is maintained using `priority_queue<int, vector<int>, greater<int>>`:
   - This keeps the smallest element at the top.
   - Only the `k` largest elements are maintained in the heap.
3. **Heap Adjustment**:
   - For each element, if the heap size exceeds `k`, the smallest element is removed.
   - This ensures that the heap only contains the `k` largest elements.
4. **Return kth Largest**: The top of the min-heap will contain the `k`th largest element when all elements have been processed.

---

## Example

### Example 1

**Input**:

- `nums = [3, 2, 1, 5, 6, 4]`
- `k = 2`

**Output**:

- `5`

**Explanation**: After sorting the array, `[1, 2, 3, 4, 5, 6]`, the 2nd largest element is `5`.

### Example 2

**Input**:

- `nums = [3, 2, 3, 1, 2, 4, 5, 5, 6]`
- `k = 4`

**Output**:

- `4`

**Explanation**: After sorting the array, `[1, 2, 2, 3, 3, 4, 5, 5, 6]`, the 4th largest element is `4`.

---

## Usage

To use the solution:

1. Create an instance of the `Solution` class.
2. Call the `findKthLargest` method with the input array and the desired `k`.

```cpp
int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 2;
    Solution solution;
    cout << solution.findKthLargest(nums, k) << endl;  // Output: 5
    return 0;
}
```

---

## Time and Space Complexity

### Time Complexity

- **Using Min-Heap**: `O(n log k)`
  - For each of the `n` elements, inserting into a heap of size `k` takes `O(log k)` time.
- **Brute Force (Sorting)**: `O(n log n)`
  - Sorting the entire array takes `O(n log n)` time.

### Space Complexity

- **Using Min-Heap**: `O(k)`
  - The min-heap stores at most `k` elements at any time.
- **Brute Force (Sorting)**: `O(1)` if sorting in-place, but it can be `O(n)` if the sort function uses extra space.

## My Solution

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        ios::sync_with_stdio(0);

        cin.tie(0);

        cout.tie(0);

        // Brute Force Solution
        /*
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
        */

        // Using priority queue for Max Heap
        /*
        priority_queue<int> pq(nums.begin(), nums.end()); //default constructs
        max-heap

        int ans = -1;

        while(k--)
        {
            ans = pq.top();

            pq.pop();
        }

        return ans;
        */

        // Using Min - Heap

        priority_queue<int, vector<int>, greater<int>> pq;

        for (int x : nums) {
            pq.push(x);

            if (pq.size() > k)
                pq.pop();
        }

        return pq.top();
    }
};
```
