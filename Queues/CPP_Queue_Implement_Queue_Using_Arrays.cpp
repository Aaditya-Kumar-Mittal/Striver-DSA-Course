#include <bits/stdc++.h>

using namespace std;

/*
    Queue class that follows FIFO (First In First Out) principle.

    Public Methods:
    - `push(int x)`: Adds the element `x` to the queue if it's not full.
    - `pop()`: Removes and returns the front element from the queue if present, else returns -1.
    - `top()`: Returns the front element of the queue if present, else returns -1.
    - `Size()`: Returns the current size of the queue.
    - `isFull()`: Returns true if the queue is full, else false.
    - `isEmpty()`: Returns true if the queue is empty, else false.
*/

class Queue
{
public:
  vector<int> arr;                       // Vector to store queue elements
  int start, end, capacity, currentSize; // Variables to track start, end, capacity, and size

  // Constructor to initialize the queue with given capacity
  Queue(int capacity)
  {
    start = -1;                // Start index of the queue (-1 indicates empty)
    end = -1;                  // End index of the queue
    this->capacity = capacity; // Set the capacity of the queue
    arr.resize(capacity);      // Allocate space in the vector
    currentSize = 0;           // Initialize the current size to 0
  }

  // Method to push an element to the queue
  void push(int x)
  {
    if (currentSize == capacity)
    { // Check if the queue is full
      std::cout << "Queue is full. Cannot add more elements!" << std::endl;
      return;
    }

    if (end == -1)
    { // If queue is empty, initialize start and end
      start = 0;
      end = 0;
    }
    else
    {
      end = (end + 1) % capacity; // Circular increment of end index
    }

    arr[end] = x; // Add the element at the end
    std::cout << "Element Pushed To Queue is: " << x << std::endl;
    currentSize++; // Increment the size
  }

  // Method to pop the front element from the queue
  int pop()
  {
    if (start == -1)
    { // Check if the queue is empty
      std::cout << "Queue is empty. Cannot pop an empty queue." << std::endl;
      return -1;
    }

    int popStart = arr[start]; // Store the element to be popped

    if (currentSize == 1)
    { // If only one element left, reset queue
      start = -1;
      end = -1;
    }
    else
    {
      start = (start + 1) % capacity; // Circular increment of start index
    }

    currentSize--;   // Decrement the size
    return popStart; // Return the popped element
  }

  // Method to get the front element of the queue
  int top()
  {
    if (start == -1)
    { // Check if the queue is empty
      std::cout << "Queue is empty. No element present." << std::endl;
      return -1;
    }
    return arr[start]; // Return the front element
  }

  // Method to get the current size of the queue
  int Size()
  {
    return currentSize;
  }

  // Method to check if the queue is full
  bool isFull()
  {
    return currentSize == capacity;
  }

  // Method to check if the queue is empty
  bool isEmpty()
  {
    return start == -1;
  }
};

int main()
{
  Queue q(6); // Create a queue of capacity 6
  q.push(4);
  q.push(14);
  q.push(24);
  q.push(34);

  cout << "The peek of the queue before deleting any element: " << q.top() << endl;
  cout << "The size of the queue before deletion: " << q.Size() << endl;
  cout << "The first element to be deleted: " << q.pop() << endl;
  cout << "The peek of the queue after deleting an element: " << q.top() << endl;
  cout << "The size of the queue after deleting an element: " << q.Size() << endl;

  return 0;
}

/*
    Analysis:

    1. **Problem**:
       - Implement a queue using a circular array with the operations:
         - Push: Add an element to the rear of the queue.
         - Pop: Remove the front element from the queue.
         - Top: View the front element.
         - Size: Check the current size of the queue.
         - isEmpty: Check if the queue is empty.
         - isFull: Check if the queue is full.

    2. **Approach**:
       - Use a vector to simulate the circular array.
       - Track the front (`start`) and rear (`end`) of the queue using indices.
       - Handle the wrap-around behavior of the queue using modulo arithmetic (`% capacity`).

    3. **Time Complexity**:
       - `push()`: O(1) – Adding an element involves updating `end` and adding to the vector.
       - `pop()`: O(1) – Removing an element involves updating `start` and removing from the vector.
       - `top()`: O(1) – Accessing the front element is a constant-time operation.
       - `Size()`: O(1) – Simply returns the current size.
       - `isEmpty()`: O(1) – Simple check on `start`.
       - `isFull()`: O(1) – Simple check on `currentSize`.

    4. **Space Complexity**:
       - `O(n)` where `n` is the capacity of the queue. The vector `arr` stores up to `n` elements.

    5. **Example**:
       - Input:
         - Capacity: 6
         - Push: 4, 14, 24, 34
         - Pop: once
         - Top: check
         - Push: 44
       - Output:
         - After push(4), push(14), push(24), push(34): Front is 4
         - After pop(): Front is 14
         - After push(44): Front is 14, size is 4
*/
