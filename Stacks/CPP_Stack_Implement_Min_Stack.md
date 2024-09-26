# MinStack - Stack with Constant Time Minimum Retrieval

This markdown contains the implementation of a `MinStack` class that supports the following stack operations in constant time:

- `push(val)`: Pushes an element onto the stack.
- `pop()`: Removes the top element from the stack.
- `top()`: Retrieves the top element from the stack.
- `getMin()`: Retrieves the minimum element from the stack at any given time.

The `MinStack` class uses a single stack to store elements while maintaining the minimum value efficiently. This implementation ensures that all operations are done in constant time (`O(1)`).

## Features

- **Push** operation that handles normal values and updates the minimum efficiently.
- **Pop** operation that recovers the previous minimum when the current minimum is popped.
- **Top** operation that retrieves the top element or decodes the minimum if needed.
- **GetMin** operation that retrieves the current minimum element in constant time.

## Time Complexity

- **Push**: `O(1)`
- **Pop**: `O(1)`
- **Top**: `O(1)`
- **GetMin**: `O(1)`

## Space Complexity

- **O(n)**, where `n` is the number of elements in the stack.

## How It Works

The `MinStack` class leverages a special encoding technique to track the minimum element. When an element smaller than the current minimum is pushed, a specially encoded value is stored in the stack instead of the actual element. This encoded value helps us track the previous minimum when the current minimum is popped from the stack.

### Encoding Technique

- If a new element is less than the current minimum, the encoded value `2 * val - mini` is pushed onto the stack, and `mini` is updated to the new element.
- When the encoded value is popped, the previous minimum is restored using the formula `2 * mini - encoded_value`.

This technique allows us to maintain the minimum value efficiently without using additional space for storing minimums in another stack.

## Example

```cpp
int main() {
    MinStack* obj = new MinStack();
    obj->push(10);         // Stack: [10], min: 10
    obj->push(5);          // Stack: [10, 5], min: 5
    obj->push(20);         // Stack: [10, 5, 20], min: 5
    cout << obj->getMin() << endl;  // Output: 5
    obj->pop();            // Stack: [10, 5], min: 5
    cout << obj->top() << endl;     // Output: 5
    cout << obj->getMin() << endl;  // Output: 5
    obj->pop();            // Stack: [10], min: 10
    cout << obj->getMin() << endl;  // Output: 10
    return 0;
}
```

## Code Explanation

The `MinStack` class is implemented in C++ with the following functions:

1. **Constructor:**

   - Initializes the stack and sets the initial minimum to `INT_MAX`.

2. **Push Function:**

   - Takes an integer value as input.
   - If the stack is empty, it pushes the value and sets it as the minimum.
   - If the value is smaller than the current minimum, it stores an encoded value and updates the minimum.

3. **Pop Function:**

   - Pops the top element from the stack.
   - If the popped element is an encoded value, it decodes the previous minimum.

4. **Top Function:**

   - Returns the top element of the stack.
   - If the top element is an encoded value, it returns the current minimum.

5. **GetMin Function:**
   - Returns the current minimum element.

---

### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 *  Class MinStack:
 *  This class implements a stack that supports push, pop, top, and retrieving
 *  the minimum element in constant time.
 *  It uses a single stack to store values, with a special technique to handle minimum values efficiently.
 */
class MinStack {
public:
    stack<long long> st;    // Stack to store elements, possibly with encoded values
    long long mini;         // Variable to keep track of the current minimum value in the stack

    /**
     *  Constructor:
     *  Initializes the stack and sets the initial minimum value to INT_MAX.
     *  Ensures the stack is empty before starting.
     */
    MinStack() {
        while (!st.empty()) st.pop();  // Clear the stack if not empty
        mini = INT_MAX;                // Initialize mini with the maximum possible value
    }

    /**
     *  Function to push an element onto the stack.
     *  @param val - The value to be pushed onto the stack.
     *  If the element is smaller than the current minimum, we store a special encoded value
     *  and update the minimum. If the stack is empty, the element itself is the minimum.
     */
    void push(int val) {
        long long ins = (long long) val;  // Convert the value to long long for handling overflow
        if (st.empty()) {
            mini = ins;  // Set mini to the first value pushed
            st.push(ins);  // Push the value normally
        }
        else {
            if (ins >= mini) {
                st.push(ins);  // Push the value if greater than or equal to the current minimum
            }
            else {
                st.push(2 * ins - mini);  // Push encoded value to keep track of previous minimum
                mini = ins;  // Update the minimum to the new smaller value
            }
        }
    }

    /**
     *  Function to pop the top element from the stack.
     *  If the popped element is an encoded value, it decodes the previous minimum.
     */
    void pop() {
        if (st.empty()) return;  // Do nothing if the stack is empty
        long long x = st.top();  // Get the top element
        st.pop();  // Remove the top element
        if (x < mini) {  // If it's encoded, decode the previous minimum
            mini = 2 * mini - x;
        }
    }

    /**
     *  Function to get the top element of the stack.
     *  @return The top element, or the current minimum if the top element is encoded.
     */
    int top() {
        if (st.empty()) return -1;  // Return -1 if the stack is empty
        long long x = st.top();  // Get the top element
        if (x >= mini) return x;  // If it's a normal value, return it
        return mini;  // If it's encoded, return the current minimum
    }

    /**
     *  Function to get the current minimum element in the stack.
     *  @return The current minimum value in the stack.
     */
    int getMin() {
        return mini;  // Return the current minimum
    }
};

```

```cpp
class MinStack {
public:
    stack<long long> st;
    long long min;
    MinStack() {}

    void push(int val) {

        if (!st.size()) {
            min = val;
            st.push(val);
        } else {
            if (min > val) {
                st.push(val + (val - min));
                min = val;
            } else
                st.push(val);
        }
    }

    void pop() {
        long long val = st.top();
        st.pop();
        if (min > val) {
            min = min + (min - val);
        }
    }

    int top() {
        if (min > st.top())
            return min;
        return st.top();
    }

    int getMin() { return min; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```

### Brute Force Solution

```cpp
class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty())
            st.push({val, val});
        else
            st.push({val, min(val, st.top().second)});
    }
    
    void pop() {
        st.pop();
        return;
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```
