# MyCircularDeque

This C++ class, `MyCircularDeque`, implements a circular deque (double-ended queue) using a fixed-size array (vector). The circular deque allows for insertion, deletion, and access to both the front and back of the deque with constant time complexity `O(1)` for all operations. It supports operations like inserting elements at the front or back, deleting elements from the front or back, checking if the deque is empty or full, and accessing elements from the front or back.

## Class Members

- **myQ**: A vector of integers to represent the deque, initialized with a capacity and filled with `-1`.
- **front**: An integer pointer to track the front of the deque.
- **back**: An integer pointer to track the back of the deque.
- **size**: The current number of elements in the deque.
- **capacity**: The maximum number of elements that the deque can hold.

## Code Implementation

```cpp
class MyCircularDeque {
public:
    vector<int> myQ;

    int front, back, size, capacity;

    MyCircularDeque(int k) {

        myQ = vector<int>(k, -1);

        front = back = size = 0;

        capacity = k;
    }

    bool insertFront(int value) {

        if (isFull())
            return false;

        front--;

        front = front + capacity;

        front %= capacity;

        myQ[front] = value;

        size++;

        return true;
    }

    bool insertLast(int value) {

        if (isFull())
            return false;

        myQ[back] = value;

        back++;

        back %= capacity;

        size++;

        return true;
    }

    bool deleteFront() {

        if (isEmpty())
            return false;

        myQ[front] = -1;

        front++;

            front %= capacity;

        size--;

        return true;
    }

    bool deleteLast() {

        if (isEmpty())
            return false;

        back--;

        back = back + capacity;

        back %= capacity;

        myQ[back] = -1;

        size--;

        return true;
    }

    int getFront() {

        if (isEmpty())
            return -1;

        return myQ[front];
    }

    int getRear() {

        if (isEmpty())
            return -1;

        if (back == 0)
            return myQ[capacity - 1];
        else
            return myQ[back - 1];
    }

    bool isEmpty() { return size == 0; }

    bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

## Public Methods

### Constructor

- **Description**: Initializes a deque of size `k`, with all elements initially set to `-1`. The `front` and `back` pointers are initialized to `0`, and the `size` is set to `0`. The `capacity` of the deque is set to `k`.

### Insert Operations

#### `bool insertFront(int value)`

- **Description**: Inserts an element at the front of the deque.
- **Parameters**: `value` - the value to be inserted.
- **Returns**: `true` if the operation is successful, `false` if the deque is full.
- **Time Complexity**: `O(1)`

#### `bool insertLast(int value)`

- **Description**: Inserts an element at the back (rear) of the deque.
- **Parameters**: `value` - the value to be inserted.
- **Returns**: `true` if the operation is successful, `false` if the deque is full.
- **Time Complexity**: `O(1)`

### Delete Operations

#### `bool deleteFront()`

- **Description**: Deletes an element from the front of the deque.
- **Returns**: `true` if the operation is successful, `false` if the deque is empty.
- **Time Complexity**: `O(1)`

#### `bool deleteLast()`

- **Description**: Deletes an element from the back (rear) of the deque.
- **Returns**: `true` if the operation is successful, `false` if the deque is empty.
- **Time Complexity**: `O(1)`

### Get Operations

#### `int getFront()`

- **Description**: Retrieves the front element from the deque.
- **Returns**: The front element if the deque is not empty, `-1` if the deque is empty.
- **Time Complexity**: `O(1)`

#### `int getRear()`

- **Description**: Retrieves the rear (back) element from the deque.
- **Returns**: The rear element if the deque is not empty, `-1` if the deque is empty.
- **Time Complexity**: `O(1)`

### Status Check Operations

#### `bool isEmpty()`

- **Description**: Checks if the deque is empty.
- **Returns**: `true` if the deque is empty, `false` otherwise.
- **Time Complexity**: `O(1)`

#### `bool isFull()`

- **Description**: Checks if the deque is full.
- **Returns**: `true` if the deque is full, `false` otherwise.
- **Time Complexity**: `O(1)`

## Example Usage

```cpp
MyCircularDeque* obj = new MyCircularDeque(k);
bool param_1 = obj->insertFront(value);
bool param_2 = obj->insertLast(value);
bool param_3 = obj->deleteFront();
bool param_4 = obj->deleteLast();
int param_5 = obj->getFront();
int param_6 = obj->getRear();
bool param_7 = obj->isEmpty();
bool param_8 = obj->isFull();
```

## Detailed Explanation of Circular Deque Operations

### Insertion

- The `insertFront()` method decrements the `front` pointer circularly and places the new element at the new `front` position.
- The `insertLast()` method places the new element at the current `back` position, then increments the `back` pointer circularly.
- Both operations check if the deque is full before proceeding, and return `false` if the deque is full.

### Deletion

- The `deleteFront()` method removes the element from the current `front` position, moves the `front` pointer forward circularly, and decreases the size of the deque.
- The `deleteLast()` method decrements the `back` pointer circularly and removes the element from the back position.
- Both operations check if the deque is empty before proceeding, and return `false` if the deque is empty.

### Retrieval

- The `getFront()` method returns the element at the `front` position. If the deque is empty, it returns `-1`.
- The `getRear()` method returns the element at the position right before the `back` pointer, adjusted circularly. If the deque is empty, it returns `-1`.

### Status Check

- The `isEmpty()` method checks if the size of the deque is `0`.
- The `isFull()` method checks if the size of the deque is equal to the `capacity`.

## Time Complexity

All operations in this implementation (`insertFront`, `insertLast`, `deleteFront`, `deleteLast`, `getFront`, `getRear`, `isEmpty`, and `isFull`) have constant time complexity: `O(1)`.

## Conclusion

This implementation of `MyCircularDeque` provides efficient support for typical deque operations with `O(1)` time complexity, thanks to the use of circular indexing in a fixed-size array.

## Other Methods

### Method - 2

```cpp
class MyCircularDeque {
public:
    vector<int> myQ;  // Vector to hold the elements of the deque
    int front, back, size, capacity;  // Pointers for front, back, size, and capacity

    // Constructor to initialize the deque with a size of k
    MyCircularDeque(int k) {
        myQ = vector<int>(k, -1);  // Initialize the deque with size k, filled with -1
        front = 0;  // Points to the first element of the deque
        back = 0;   // Points to the position where the next element will be added
        size = 0;   // Current size of the deque
        capacity = k;  // Maximum size of the deque
    }

    // Function to insert an element at the front of the deque
    bool insertFront(int value) {
        if (isFull())
            return false;  // Cannot insert if deque is full

        front = (front - 1 + capacity) % capacity;  // Update front circularly
        myQ[front] = value;  // Insert the value at the front
        size++;  // Increment size
        return true;
    }

    // Function to insert an element at the rear of the deque
    bool insertLast(int value) {
        if (isFull())
            return false;  // Cannot insert if deque is full

        myQ[back] = value;  // Insert the value at the back
        back = (back + 1) % capacity;  // Update back circularly
        size++;  // Increment size
        return true;
    }

    // Function to delete an element from the front of the deque
    bool deleteFront() {
        if (isEmpty())
            return false;  // Cannot delete if deque is empty

        myQ[front] = -1;  // Reset the front value to -1
        front = (front + 1) % capacity;  // Move front forward circularly
        size--;  // Decrement size
        return true;
    }

    // Function to delete an element from the rear of the deque
    bool deleteLast() {
        if (isEmpty())
            return false;  // Cannot delete if deque is empty

        back = (back - 1 + capacity) % capacity;  // Move back backward circularly
        myQ[back] = -1;  // Reset the back value to -1
        size--;  // Decrement size
        return true;
    }

    // Function to get the front element
    int getFront() {
        if (isEmpty())
            return -1;  // Return -1 if deque is empty

        return myQ[front];  // Return the front element
    }

    // Function to get the rear element
    int getRear() {
        if (isEmpty())
            return -1;  // Return -1 if deque is empty

        // Adjust the back pointer circularly for proper retrieval
        return myQ[(back - 1 + capacity) % capacity];
    }

    // Function to check if the deque is empty
    bool isEmpty() {
        return size == 0;  // Deque is empty if size is 0
    }

    // Function to check if the deque is full
    bool isFull() {
        return size == capacity;  // Deque is full if size equals capacity
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
```

### Using Circular Doubly Linked List

```cpp
// Node structure for the doubly linked list
struct Node {
    int data;
    Node* next, * last;
    // Constructor initializes
    Node(int x, Node* next = NULL, Node* last = NULL)
        : data(x), next(next), last(last) {}
};

class MyCircularDeque {
    Node* dummy; // Dummy node
    int k;
    int len;

public:
    // Constructor to initialize deque with given capacity
    MyCircularDeque(int k) : k(k), len(0) {
        dummy = new Node(-1); // Create a dummy node
        dummy->next = dummy->last = dummy;
    }

    bool insertFront(int value) {
        if (len == k)
            return 0; // full

        Node* newNode = new Node(value, dummy->next, dummy);
        dummy->next->last = newNode; // Link old front's last to newNode
        dummy->next = newNode;       // Link dummy to new front (newNode)

        if (len == 0) {
            dummy->last = newNode; // inserting the first element
        }

        len++;
        return 1;
    }

    bool insertLast(int value) {
        if (len == k)
            return 0; // full

        Node* newNode = new Node(value, dummy, dummy->last);
        dummy->last->next = newNode; // Link old back's next to newNode
        dummy->last = newNode;       // Link dummy's last to newNode

        if (len == 0) {
            dummy->next = newNode; // inserting the first element
        }

        len++;
        return 1;
    }

    bool deleteFront() {
        if (len == 0)
            return 0; // empty

        Node* curr = dummy->next;
        dummy->next = curr->next;
        curr->next->last = dummy;

        delete curr;
        len--;

        return 1;
    }

    bool deleteLast() {
        if (len == 0)
            return 0; // empty

        Node* curr = dummy->last;
        dummy->last = curr->last;
        curr->last->next = dummy;

        delete curr;
        len--;

        return 1;
    }

    int getFront() { return (len == 0) ? -1 : dummy->next->data; }

    int getRear() { return (len == 0) ? -1 : dummy->last->data; }

    bool isEmpty() { return len == 0; }

    bool isFull() { return len == k; }
};
```
