# Queue Implementation Using Linked List

## Problem Overview

This problem involves implementing a **queue** data structure using a **linked list**. The queue supports the following operations:

- **Enqueue**: Adds an element to the rear of the queue.
- **Dequeue**: Removes and returns the front element from the queue.
- **Front**: Retrieves the value of the front element without removing it.
- **IsEmpty**: Checks if the queue is empty.

Unlike an array-based implementation, a linked list provides a dynamic structure that grows and shrinks as needed without any need for resizing. This ensures efficient memory usage, as only the required amount of space is allocated.

---

## Class Structure

### `Node` Class

The `Node` class defines the structure of each element (node) in the queue. Each node contains:

- **data**: The value stored in the node.
- **next**: A pointer to the next node in the queue.

```cpp
class Node {
public:
    int data;        // The value of the node
    Node *next;      // Pointer to the next node

    // Default constructor
    Node() {
        this->data = 0;
        this->next = nullptr;
    }

    // Constructor to initialize node with data
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    // Constructor to initialize node with data and next pointer
    Node(int data, Node *next) {
        this->data = data;
        this->next = next;
    }
};
```

### `Queue` Class

The `Queue` class implements the queue using a linked list with two primary pointers:

1. **Start**: Points to the front (first node) of the queue.
2. **Rear**: Points to the rear (last node) of the queue.

The class also tracks the **size** of the queue, which is the number of elements currently in the queue.

```cpp
class Queue {
public:
    Node *start, *rear; // Pointers to the front and rear of the queue
    int size;           // Size of the queue (number of elements)

    // Constructor to initialize the queue
    Queue() {
        start = rear = nullptr;
        size = 0;
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

This function checks whether the queue is empty by checking if the `size` is equal to 0.

```cpp
bool isEmpty() {
    return size == 0;
}
```

### 2. **Enqueue Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function adds a new node containing the provided data to the rear of the queue. If the queue is empty, both `start` and `rear` pointers are updated to point to the new node. Otherwise, the new node is linked to the current `rear`, and the `rear` pointer is updated to the new node.

```cpp
void enqueue(int data) {
    Node *temp = new Node(data);  // Create a new node with the provided data

    if (start == nullptr) {       // If the queue is empty
        start = rear = temp;      // Set both start and rear to the new node
    } else {
        rear->next = temp;        // Link the new node to the rear of the queue
        rear = temp;              // Update the rear pointer
    }

    size += 1;                    // Increment the size of the queue
}
```

### 3. **Dequeue Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function removes the front element from the queue by moving the `start` pointer to the next node. If the queue is empty, it returns `-1`. The node at the front is deleted, and the queue's size is decremented.

```cpp
int dequeue() {
    if (isEmpty()) return -1;    // If the queue is empty, return -1

    Node *temp = start;          // Store the current front node
    int data = temp->data;       // Store the front node's data
    start = start->next;         // Move the start pointer to the next node
    delete temp;                 // Delete the old front node
    size -= 1;                   // Decrement the size of the queue

    return data;                 // Return the data of the removed element
}
```

### 4. **Front Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function returns the value of the front element in the queue without removing it. If the queue is empty, it returns `-1`.

```cpp
int front() {
    if (size == 0) return -1;    // If the queue is empty, return -1
    return start->data;          // Return the data of the front node
}
```

---

## Edge Cases

1. **Empty Queue**: Both `dequeue()` and `front()` return `-1` when the queue is empty.
2. **Single Element**: When there is only one element in the queue, both `start` and `rear` point to the same node. After removing this element, both pointers are set to `nullptr`, indicating an empty queue.

---

## Time and Space Complexity

### Time Complexity

- **Enqueue**: O(1), as the new element is always added at the rear in constant time.
- **Dequeue**: O(1), as removing the front element involves updating the `start` pointer in constant time.
- **Front**: O(1), as it directly accesses the front element.
- **IsEmpty**: O(1), checking if the queue is empty requires a simple comparison.

### Space Complexity

- **O(n)**, where `n` is the number of elements in the queue. Each element is stored in a node, which consists of the `data` and a pointer to the next node.

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

This implementation of a queue using a linked list provides a flexible and efficient solution. It efficiently handles edge cases like empty queues and dynamic growth by managing memory allocation with linked nodes. The operations are designed to have O(1) time complexity, making this implementation ideal for scenarios where efficient enqueue and dequeue operations are required.
