# 295. Find Median from Data Stream

## Problem Overview

**Problem:**  
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.

- For example, for `arr = [2,3,4]`, the median is `3`.
- For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.

**Objective:**  
Implement the `MedianFinder` class to calculate the median from a stream of numbers:

1. **MedianFinder()** initializes the `MedianFinder` object.
2. **void addNum(int num)** adds the integer `num` to the data structure.
3. **double findMedian()** returns the median of all elements added so far. Answers within `10^-5` of the actual answer are acceptable.

### Example

```cpp
Input:
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]

Output:
[null, null, null, 1.5, null, 2.0]

Explanation:
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr = [1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

### Constraints

- `-10^5 <= num <= 10^5`
- There will be at least one element in the data structure before calling `findMedian()`.
- At most `5 * 10^4` calls will be made to `addNum()` and `findMedian()`.

### Follow-Up

1. **If all integers are in the range [0, 100], how would you optimize your solution?**
   - Use a counting array of size 101 to maintain the frequency of each number.
   - Use prefix sums to calculate the median efficiently.
2. **If 99% of integers are in the range [0, 100], how would you optimize your solution?**
   - Use a counting array for numbers in the range and handle outliers separately with a smaller data structure.

---

### Approach

The problem is solved using two heaps (priority queues):

1. **Max-Heap (`smallerPQ`)**:  
   Stores the smaller half of the elements, allowing access to the largest of the smaller half (left side).
2. **Min-Heap (`greaterPQ`)**:  
   Stores the larger half of the elements, allowing access to the smallest of the larger half (right side).

### Logic for Insertion

- **Adding a Number (`addNum(int num)`):**

  - If `smallerPQ` is empty, add the number directly to it.
  - If `smallerPQ` has more elements than `greaterPQ`:
    - If the new number is smaller than the maximum of `smallerPQ`, transfer the top element from `smallerPQ` to `greaterPQ` and insert the new number into `smallerPQ`.
    - Otherwise, insert the new number into `greaterPQ`.
  - If `smallerPQ` has the same number of elements as `greaterPQ`:
    - If the new number is smaller than the maximum of `smallerPQ`, add it to `smallerPQ`.
    - Otherwise, add it to `greaterPQ` and transfer the top element of `greaterPQ` to `smallerPQ`.

- **Finding the Median (`findMedian()`):**
  - If `smallerPQ` and `greaterPQ` have the same number of elements, the median is the average of the top of both heaps.
  - If `smallerPQ` has more elements, the median is the top element of `smallerPQ`.

### Code with Documentation

```cpp
#include <queue>
using namespace std;

class MedianFinder {
public:
    // Max-Heap to store the smaller half of the numbers.
    priority_queue<int> smallerPQ;

    // Min-Heap to store the larger half of the numbers.
    priority_queue<int, vector<int>, greater<int>> greaterPQ;

    // Constructor: Initializes the MedianFinder object.
    MedianFinder() {}

    /**
     * Adds an integer to the data structure.
     * @param num - The integer to add.
     * Logic:
     * - If `smallerPQ` is empty, directly add the number to `smallerPQ`.
     * - If `smallerPQ` has more elements than `greaterPQ`:
     *   - If `num` is smaller than the max of `smallerPQ`, move the top of `smallerPQ` to `greaterPQ` and insert `num` into `smallerPQ`.
     *   - Otherwise, add `num` directly to `greaterPQ`.
     * - If both heaps have the same number of elements:
     *   - Add `num` to the appropriate heap and balance the sizes.
     */
    void addNum(int num) {
        if (smallerPQ.empty()) {
            smallerPQ.push(num);
            return;
        }

        if (smallerPQ.size() > greaterPQ.size()) {
            if (num < smallerPQ.top()) {
                greaterPQ.push(smallerPQ.top());
                smallerPQ.pop();
                smallerPQ.push(num);
            } else {
                greaterPQ.push(num);
            }
        } else {
            if (num < smallerPQ.top()) {
                smallerPQ.push(num);
            } else {
                greaterPQ.push(num);
                smallerPQ.push(greaterPQ.top());
                greaterPQ.pop();
            }
        }
    }

    /**
     * Returns the median of the current data stream.
     * @return double - The median value.
     * Logic:
     * - If `smallerPQ` and `greaterPQ` have the same size, the median is the average of the tops.
     * - If `smallerPQ` has more elements, the median is the top of `smallerPQ`.
     */
    double findMedian() {
        if (smallerPQ.size() == greaterPQ.size()) {
            return (double)(smallerPQ.top() + greaterPQ.top()) / 2;
        }
        return smallerPQ.top();
    }
};
```

### Analysis

```plaintext
Time Complexity:
- `addNum(int num)`: O(log n) due to insertion into the heaps.
- `findMedian()`: O(1) as accessing the top of heaps is constant time.
- Overall, the time complexity for adding `n` numbers and finding the median is O(n log n).

Space Complexity:
- O(n) for storing numbers in the two heaps.

Constraints and Considerations:
- Handles edge cases like an empty data stream.
- Efficiently balances two heaps to ensure median calculations remain optimal.
```

### How to Use

1. Instantiate the `MedianFinder` object:

   ```cpp
   MedianFinder* obj = new MedianFinder();
   ```

2. Add a number using `addNum`:

   ```cpp
   obj->addNum(1);
   ```

3. Retrieve the median using `findMedian`:

   ```cpp
   double median = obj->findMedian();
   ```

4. Clean up memory if dynamically allocated:

   ```cpp
   delete obj;
   ```

---

### Summary

This `MedianFinder` class efficiently handles dynamic data streams, allowing for quick retrieval of the median using a two-heap approach. It keeps the data balanced by maintaining the properties of max-heap and min-heap, making the solution suitable for a large number of inputs while keeping the time complexity manageable.
