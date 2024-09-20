# Stacks - Implementing Stack Using Queues

## Analysis

### Problem Name: Implement Stack using Queues

### Time Complexity

- `push`: O(n) because we rotate the entire queue to maintain stack order.
- `pop`, `top`, `empty`: O(1) as these operations only interact with the front of the queue.

### Space Complexity

- O(1) for each operation, only using constant space aside from the queue itself.

### Notes

- This implementation ensures that the stack's last-in-first-out (LIFO) behavior is preserved using only the standard operations of a queue.

```cpp
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> Q; // Main queue to simulate stack behavior

    /**
     * @brief Constructor for the stack.
     *
     * This initializes an empty stack using a queue.
     */
    MyStack() {
    }

    /**
     * @brief Pushes an element to the top of the stack.
     *
     * This function pushes an element to the "top" of the stack by simulating stack behavior
     * using a queue. After pushing the new element to the back of the queue, we rotate
     * the elements so that the last pushed element appears at the front (as the stack's top).
     *
     * @param x The element to be pushed onto the stack.
     *
     * Time Complexity: O(n) - Rotating all elements in the queue after pushing.
     * Space Complexity: O(1) - No extra space apart from the input queue.
     */
    void push(int x) {
        int s = Q.size(); // Get current size of the queue
        Q.push(x); // Push the new element

        // Rotate the existing elements to make the new element the front (top of stack)
        for (int i = 0; i < s; i++) {
            Q.push(Q.front()); // Push the front element to the back
            Q.pop(); // Remove the front element
        }
    }

    /**
     * @brief Removes the element on the top of the stack and returns it.
     *
     * This function removes the element that was most recently pushed to the stack.
     *
     * @return The element removed from the stack (front of the queue).
     *
     * Time Complexity: O(1) - Removing the front element from the queue.
     * Space Complexity: O(1).
     */
    int pop() {
        int ele = Q.front(); // Get the front element
        Q.pop(); // Remove the front element (which is the top of the stack)
        return ele;
    }

    /**
     * @brief Returns the element on the top of the stack without removing it.
     *
     * @return The element at the top of the stack (front of the queue).
     *
     * Time Complexity: O(1).
     * Space Complexity: O(1).
     */
    int top() {
        return Q.front(); // Return the front element as the stack top
    }

    /**
     * @brief Checks whether the stack is empty.
     *
     * @return True if the stack is empty, false otherwise.
     *
     * Time Complexity: O(1).
     * Space Complexity: O(1).
     */
    bool empty() {
        return Q.empty(); // Return true if the queue (stack) is empty
    }
};
```
