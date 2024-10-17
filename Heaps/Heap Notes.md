# Understanding Heaps as a Data Structures

## Types of Heaps

1. **Max-Heap**
   - Value of the root is greatest among child nodes
   - Same applies to the left and the right subtrees.
   - The total number of comparisons required in the max heap is according to the height of the tree. The height of the complete binary tree is always logn; therefore, the time complexity would also be O(logn).
2. **Min-Heap**
   - In this heap, the value of the root node must be the smallest among all its child nodes and the same thing must be done for its left and right sub-tree also.
   - The total number of comparisons required in the min heap is according to the height of the tree. The height of the complete binary tree is always logn; therefore, the time complexity would also be O(logn).

| **Heap Data Structure**                  |
| ---------------------------------------- |
| ![Heaps](./images/MinHeapAndMaxHeap.png) |

### Properties of Heap

1. **Complete Binary Tree**
   - All levels of the tree are fully filled except possibly the last level
   - All Levels are filled rorm **Left to Right**
   - Minimum (or maximum) element is **always at the root of the tree** according to the heap type.
   - Left child at index **`2i+1`** and right child at index **`2i+2`** for 0-based indexing of node numbers.
2. **Heapify**
   - Process to rearrange the elements to maintain the property of heap data structure
   - Single Violation imbalances the complete tree.
   - process to rearrange the elements to maintain the property of heap data structure. - **`O(log N)`**

## Various Operations in Heap Data Structure

| S. No. | Operation                                          | Description                                                                                                                                                                                                 | Time Complexity (Worst Case) | Time Complexity (Best Case) |
| ------ | -------------------------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------------- | --------------------------- |
| 1.     | **Heapify**                                        | Process to rearrange the elements to maintain the property of heap data structure                                                                                                                           | **`O(log N)`**               |                             |
| 2.     | **Insertion**                                      | Inserting new element into the heap, heapify to maintain the order                                                                                                                                          | **`O(log N)`**               |                             |
| 3.     | **Deleteion**                                      | Delete the element from the heap, deletes the root element of the tree and replaces it with the last element of the tree. Heapify to maintaint the order                                                    | **`O(log N)`**               |                             |
| 4.     | **getMax (For max-heap) or getMin (For min-heap)** | Finds the maximum element or minimum element for max-heap and min-heap respectively and as we know minimum and maximum elements will always be the root node itself for min-heap and max-heap respectively. | **`O(1)`**                   | **`O(1)`**                  |
| 5.     | **decreaseKey()**                                  | Decreases the value of the key                                                                                                                                                                              | **`O(log N)`**               |                             |
