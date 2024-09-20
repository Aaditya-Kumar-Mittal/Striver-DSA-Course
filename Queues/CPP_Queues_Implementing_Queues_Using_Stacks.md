# Implementing Queue Using Stacks

## Analysis

### Problem Name: Implement Queue using Stacks

### Time Complexity

- `push`: O(1) because we push directly to the stack.
- `pop`: O(n) due to moving elements between the two stacks.
- `peek`: O(n) for the same reason as `pop`.
- `empty`: O(1).

### Space Complexity

- O(1) for each operation as we use two stacks, but no additional memory is used besides the stacks themselves.

## Key Adjustments

1. **Time Complexity**:

   - `push` is O(1), while `pop` and `peek` are O(n) due to the need to transfer elements between the two stacks.

2. **Restoration of Stack Order**:
   - After performing a `pop()` or `peek()`, elements are moved back from the `helperStack` to `myStack` to maintain the correct order.

### Code

```cpp
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> myStack, helperStack; // Two stacks: one for main queue operations and one for helper operations

    // Constructor for MyQueue
    MyQueue() { }

    /**
     * @brief Push an element to the back of the queue.
     * @param x The element to push.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    void push(int x) {
        myStack.push(x); // Push directly to the main stack
    }

    /**
     * @brief Remove the element from the front of the queue and return it.
     * @return The front element of the queue.
     *
     * Time Complexity: O(n), where n is the number of elements in the queue.
     * Time Complexity: Amortized O(1). In the worst case, when s2 is empty, elements from s1 are
     * moved to s2, but this happens only once for each element.
     * Space Complexity: O(1), no extra space apart from stacks.
     */
    int pop() {
        // Move all elements from myStack to helperStack to access the first inserted element
        while (!myStack.empty()) {
            helperStack.push(myStack.top());
            myStack.pop();
        }

        // The top element of helperStack is the front of the queue
        int x = helperStack.top();
        helperStack.pop(); // Remove the front element

        // Move elements back to myStack to restore the order
        while (!helperStack.empty()) {
            myStack.push(helperStack.top());
            helperStack.pop();
        }

        return x; // Return the popped front element
    }

    /**
     * @brief Get the front element of the queue without removing it.
     * @return The front element of the queue.
     *
     * Time Complexity: O(n), where n is the number of elements in the queue.
     *  Time Complexity: Amortized O(1).
     * Space Complexity: O(1)
     */
    int peek() {
        // Move all elements from myStack to helperStack to access the first inserted element
        while (!myStack.empty()) {
            helperStack.push(myStack.top());
            myStack.pop();
        }

        // The top element of helperStack is the front of the queue
        int ele = helperStack.top();

        // Move elements back to myStack to restore the order
        while (!helperStack.empty()) {
            myStack.push(helperStack.top());
            helperStack.pop();
        }

        return ele; // Return the front element without removing it
    }

    /**
     * @brief Check if the queue is empty.
     * @return True if the queue is empty, false otherwise.
     *
     * Time Complexity: O(1)
     * Space Complexity: O(1)
     */
    bool empty() {
        return myStack.empty(); // Queue is empty if myStack is empty
    }
};
```
