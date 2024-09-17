#include <iostream>
#include <vector>
using namespace std;

/*
    Stack class that follows LIFO (Last In First Out) principle.

    Public Methods:
    - `push(int num)`: Pushes the given number to the stack if the stack is not full.
    - `pop()`: Removes and returns the top element from the stack if present, else returns -1.
    - `top()`: Returns the top element of the stack if present, else returns -1.
    - `isEmpty()`: Returns 1 if the stack is empty, else returns 0.
    - `isFull()`: Returns 1 if the stack is full, else returns 0.
*/

class Stack
{
public:
  int Top, capacity; // Tracks the top index and capacity of the stack
  vector<int> st;    // Vector to hold the stack elements

  // Constructor: Initializes stack with a given capacity
  Stack(int capacity)
  {
    Top = -1;                  // Initialize the top index to -1 (indicating empty)
    this->capacity = capacity; // Set the stack's capacity
    st.reserve(capacity);      // Reserve space in the vector for 'capacity' elements
  }

  // Method to push an element onto the stack
  void push(int num)
  {
    if (Top < capacity - 1)
    {                    // Ensure stack is not full
      Top++;             // Move the top pointer up
      st.push_back(num); // Add the element to the stack
    }
  }

  // Method to pop the top element from the stack
  int pop()
  {
    if (Top == -1)
      return -1;          // If stack is empty, return -1
    int popEle = st[Top]; // Get the top element
    Top--;                // Move the top pointer down
    st.pop_back();        // Remove the element from the stack
    return popEle;        // Return the popped element
  }

  // Method to get the top element of the stack
  int top()
  {
    if (Top < 0)
      return -1;    // If stack is empty, return -1
    return st[Top]; // Return the top element
  }

  // Method to check if the stack is empty
  int isEmpty()
  {
    return (Top == -1) ? 1 : 0; // Return 1 if empty, else 0
  }

  // Method to check if the stack is full
  int isFull()
  {
    return (Top == capacity - 1) ? 1 : 0; // Return 1 if full, else 0
  }
};

int main()
{
  int capacity;
  cout << "Enter the stack capacity: ";
  cin >> capacity;

  Stack stack(capacity); // Create a stack with user-specified capacity

  int choice;
  while (true)
  {
    cout << "\n1. Push\n2. Pop\n3. Top\n4. isEmpty\n5. isFull\n6. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
      int num;
      cout << "Enter number to push: ";
      cin >> num;
      stack.push(num);
    }
    else if (choice == 2)
    {
      cout << "Popped element: " << stack.pop() << endl;
    }
    else if (choice == 3)
    {
      cout << "Top element: " << stack.top() << endl;
    }
    else if (choice == 4)
    {
      cout << "Stack is empty: " << stack.isEmpty() << endl;
    }
    else if (choice == 5)
    {
      cout << "Stack is full: " << stack.isFull() << endl;
    }
    else if (choice == 6)
    {
      break;
    }
    else
    {
      cout << "Invalid choice. Try again." << endl;
    }
  }

  return 0;
}

/*
    Analysis:

    1. **Problem**:
       - Implement a stack using an array (or vector) with the operations:
         - Push: Add an element to the top of the stack.
         - Pop: Remove the top element from the stack.
         - Top: View the top element.
         - isEmpty: Check if the stack is empty.
         - isFull: Check if the stack is full.

    2. **Approach**:
       - Use a vector to simulate the stack.
       - Track the current top index using a variable `Top`.
       - Use simple conditions to ensure that elements are only pushed when there’s space and popped when the stack is not empty.

    3. **Time Complexity**:
       - `push()`: O(1) – Pushing an element involves incrementing `Top` and adding to the vector.
       - `pop()`: O(1) – Popping an element involves decrementing `Top` and removing from the vector.
       - `top()`: O(1) – Accessing the top element is a constant-time operation.
       - `isEmpty()`: O(1) – Checking if the stack is empty is a simple comparison.
       - `isFull()`: O(1) – Checking if the stack is full is a simple comparison.

    4. **Space Complexity**:
       - `O(n)` where `n` is the capacity of the stack. The vector `st` stores up to `n` elements.

    5. **Example**:
       - Input:
         - Capacity: 5
         - Push: 1, 2, 3
         - Pop: once
         - Top: check
         - Push: 4
       - Output:
         - After push(1), push(2), push(3): Top is 3
         - After pop(): Top is 2
         - After push(4): Top is 4
*/
