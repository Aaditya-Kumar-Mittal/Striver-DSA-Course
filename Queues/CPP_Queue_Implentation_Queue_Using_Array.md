# Queue Implementation Using Dynamic Array

## Problem Overview

This problem involves implementing a **queue** data structure using a **dynamic array**. The queue supports the following operations:

- **Enqueue**: Adds an element to the rear of the queue.
- **Dequeue**: Removes and returns the front element from the queue.
- **Front**: Retrieves the value of the front element without removing it.
- **IsEmpty**: Checks if the queue is empty.

The dynamic array ensures that the queue can grow as needed, handling more elements than its initial capacity allows by resizing the array dynamically.

---

## Class Structure

### `Queue` Class

The `Queue` class implements the queue using a dynamic array (`vector<int>`), with two main pointers:

1. **Start**: Points to the front element of the queue.
2. **Rear**: Points to the position where the next element will be inserted.

```cpp
class Queue {
public:
    int start, rear;      // Pointers to the front and rear of the queue
    vector<int> arr;      // Dynamic array to hold the queue elements

    // Constructor to initialize the queue
    Queue() {
        start = 0;        // Initialize the start pointer
        rear = 0;         // Initialize the rear pointer
        arr.resize(1000); // Initial size of the array is 1000
    }

    // Function to check if the queue is empty
    bool isEmpty();

    // Function to add an element to the rear of the queue
    void enqueue(int data);

    // Function to remove and return the front element from the queue
    int dequeue();

    // Function to return the front element without removing it
    int front();
};
```

---

## Queue Operations

### 1. **Is Empty Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function checks whether the queue is empty by comparing the `start` and `rear` pointers.

```cpp
bool isEmpty() {
    return start == rear;  // Queue is empty if start and rear pointers are the same
}
```

### 2. **Enqueue Operation**

- **Time Complexity**: O(1) **amortized**
- **Space Complexity**: O(n), where `n` is the number of elements in the queue.

This function adds an element to the rear of the queue. If the rear pointer exceeds the size of the array, the array's size is doubled to accommodate more elements.

```cpp
void enqueue(int data) {
    if (rear >= arr.size()) {
        arr.resize(arr.size() * 2);  // Double the size of the array
    }
    arr[rear] = data;  // Add the data to the rear of the queue
    rear += 1;         // Move the rear pointer
}
```

### 3. **Dequeue Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function removes and returns the front element from the queue by moving the `start` pointer. If the queue is empty, it returns `-1`.

```cpp
int dequeue() {
    if (isEmpty()) return -1;  // Return -1 if the queue is empty
    int pop = arr[start];      // Store the front element
    start += 1;                // Move the start pointer to the next element
    return pop;                // Return the removed element
}
```

### 4. **Front Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function returns the front element of the queue without removing it. If the queue is empty, it returns `-1`.

```cpp
int front() {
    if (start == rear) return -1;  // Return -1 if the queue is empty
    return arr[start];             // Return the front element
}
```

---

## Edge Cases

1. **Empty Queue**: Both `dequeue()` and `front()` return `-1` when the queue is empty.
2. **Dynamic Resizing**: If the rear pointer exceeds the size of the array during the `enqueue()` operation, the array is dynamically resized to double its current size. This ensures there is always space available for new elements.

---

## Time and Space Complexity

### Time Complexity

- **Enqueue**: O(1) amortized. In normal cases, adding an element to the rear of the queue takes constant time. However, when the array is full and needs to be resized, the operation takes O(n) time, where `n` is the current size of the array. This resizing happens infrequently, so the amortized time complexity remains O(1).
- **Dequeue**: O(1), as removing the front element only involves updating the `start` pointer.
- **Front**: O(1), as it directly accesses the element at the `start` pointer.
- **IsEmpty**: O(1), checking if the queue is empty requires a simple comparison.

### Space Complexity

- **O(n)**, where `n` is the number of elements in the queue. The dynamic array resizes as needed, so the space used grows with the number of elements.

---

## Example Use Case

Here’s how the `Queue` class might be used in practice:

```cpp
Queue myQueue;

myQueue.enqueue(10);   // Queue: [10]
myQueue.enqueue(20);   // Queue: [10, 20]
myQueue.enqueue(30);   // Queue: [10, 20, 30]

cout << myQueue.front();  // Output: 10
cout << myQueue.dequeue();  // Output: 10, Queue: [20, 30]
cout << myQueue.dequeue();  // Output: 20, Queue: [30]
cout << myQueue.isEmpty();  // Output: 0 (false)
cout << myQueue.dequeue();  // Output: 30, Queue: []
cout << myQueue.isEmpty();  // Output: 1 (true)
cout << myQueue.dequeue();  // Output: -1 (empty queue)
```

---

## Conclusion

This implementation of a queue using a dynamic array is efficient and handles a variety of edge cases gracefully. The `enqueue` operation dynamically resizes the array when necessary, ensuring that there is always space to add new elements. The operations are designed to have O(1) time complexity, making this implementation suitable for use cases where queue operations need to be performed quickly and efficiently.
