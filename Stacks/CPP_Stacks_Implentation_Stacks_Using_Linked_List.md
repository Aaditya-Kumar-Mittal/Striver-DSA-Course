# Stack Implementation Using Linked List

## Problem Overview

This problem involves implementing a **stack** data structure using a **singly linked list**. The stack supports the following operations:

- **Push**: Adds an element to the top of the stack.
- **Pop**: Removes the top element from the stack.
- **Get Top**: Retrieves the value of the top element without removing it.
- **Get Size**: Returns the current size of the stack.
- **Is Empty**: Checks if the stack is empty.

The linked list allows for dynamic memory allocation, meaning the stack can grow as needed without the limitations of a fixed size.

---

## Class Structure

### Complete Code

```cpp
class Stack
{
    //Write your code here

public:

    Node *top;

    int size;

    Stack()
    {
        top = nullptr;

        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int data)
    {
        Node *temp = new Node(data);

        temp->next = top;

        top = temp;

        size = size +1;
    }

    void pop()
    {
        if(size == 0) return;

        Node *temp = top;

        top = top->next;

        delete temp;

        size = size - 1;
    }

    int getTop()
    {
        if(size == 0) return -1;

        return top->data;
    }
};
```

### `Node` Class

The `Node` class represents the building block of the stack. Each node contains two parts:

1. **Data**: The value held by the node.
2. **Next Pointer**: A pointer to the next node in the stack.

```cpp
class Node {
public:
    int data;        // Value stored in the node
    Node *next;      // Pointer to the next node

    // Default constructor initializes data to 0 and next to NULL
    Node() {
        this->data = 0;
        next = NULL;
    }

    // Constructor initializes node with given data
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Constructor initializes node with given data and next pointer
    Node(int data, Node* next) {
        this->data = data;
        this->next = next;
    }
};
```

### `Stack` Class

The `Stack` class contains the stack operations and uses the `Node` class for managing elements.

```cpp
class Stack {
public:
    Node *top;  // Pointer to the top element of the stack
    int size;   // Current size of the stack

    // Constructor to initialize an empty stack
    Stack() {
        top = nullptr;
        size = 0;
    }

    // Function to return the size of the stack
    int getSize();

    // Function to check if the stack is empty
    bool isEmpty();

    // Function to push a new element onto the stack
    void push(int data);

    // Function to pop the top element from the stack
    void pop();

    // Function to get the top element of the stack
    int getTop();
};
```

---

## Stack Operations

### 1. **Push Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function adds a new element to the top of the stack.

```cpp
void push(int data) {
    Node *temp = new Node(data);  // Create a new node with the given data
    temp->next = top;             // Link the new node to the current top
    top = temp;                   // Update top to the new node
    size = size + 1;              // Increment the size of the stack
}
```

### 2. **Pop Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function removes the top element from the stack. If the stack is empty, it does nothing.

```cpp
void pop() {
    if (size == 0) return;        // If the stack is empty, do nothing

    Node *temp = top;             // Store the current top node
    top = top->next;              // Move the top to the next element
    delete temp;                  // Delete the old top node
    size = size - 1;              // Decrement the size of the stack
}
```

### 3. **Get Top Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function retrieves the top element of the stack without removing it. If the stack is empty, it returns `-1`.

```cpp
int getTop() {
    if (size == 0) return -1;     // If the stack is empty, return -1
    return top->data;             // Return the data of the top node
}
```

### 4. **Get Size Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function returns the number of elements currently in the stack.

```cpp
int getSize() {
    return size;  // Return the size of the stack
}
```

### 5. **Is Empty Operation**

- **Time Complexity**: O(1)
- **Space Complexity**: O(1)

This function checks whether the stack is empty by comparing the size to `0`.

```cpp
bool isEmpty() {
    return size == 0;  // Return true if the stack is empty
}
```

---

## Edge Cases

1. **Popping from an empty stack**: The `pop()` function is designed to handle an empty stack by doing nothing if there are no elements to remove.
2. **Getting the top element of an empty stack**: The `getTop()` function returns `-1` when called on an empty stack to indicate that there are no elements.

---

## Time and Space Complexity

### Time Complexity

- **Push**: O(1), because inserting a new element at the top of the stack is a constant-time operation.
- **Pop**: O(1), because removing the top element also takes constant time.
- **Get Top**: O(1), as accessing the top element is a simple operation.
- **Is Empty**: O(1), checking if the stack is empty requires a simple comparison.
- **Get Size**: O(1), the size is maintained as a variable and can be accessed in constant time.

### Space Complexity

- **O(N)**, where `N` is the number of elements in the stack. Each element is stored in a node of the linked list, and each node requires additional space for the `data` and `next` pointer.

---

## Example Use Case

Here’s how the `Stack` class might be used in practice:

```cpp
Stack myStack;
myStack.push(10);     // Stack: [10]
myStack.push(20);     // Stack: [20, 10]
myStack.push(30);     // Stack: [30, 20, 10]

cout << myStack.getTop();  // Output: 30
myStack.pop();             // Stack: [20, 10]
cout << myStack.getTop();  // Output: 20

cout << myStack.getSize(); // Output: 2
myStack.pop();             // Stack: [10]
cout << myStack.isEmpty(); // Output: 0 (false)
myStack.pop();             // Stack: []
cout << myStack.isEmpty(); // Output: 1 (true)
```

## Conclusion

This implementation of a stack using a linked list is efficient in terms of both time and space. The operations are all O(1), making it ideal for use cases that require dynamic memory allocation without worrying about fixed sizes, unlike array-based implementations. Edge cases such as handling an empty stack are also accounted for, ensuring robustness in different scenarios.
