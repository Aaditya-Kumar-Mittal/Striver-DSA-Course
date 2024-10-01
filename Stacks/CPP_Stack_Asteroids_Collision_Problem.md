# Stack Problem: 735. Asteroid Collision

## Problem Statement

We are given an array `asteroids` of integers representing asteroids in a row. Each asteroid moves at the same speed:

- The **absolute value** of each integer represents the asteroid's size.
- The **sign** of each integer represents the asteroid's direction:
  - Positive integers represent asteroids moving to the right.
  - Negative integers represent asteroids moving to the left.

### Rules

- Two asteroids moving in the **same direction** will never collide.
- When two asteroids moving in **opposite directions** collide, the smaller asteroid explodes. If both asteroids are of the same size, **both explode**.

### Task

Find out the state of the asteroids after all collisions and return the remaining asteroids in the array.

### Constraints

- `2 <= asteroids.length <= 10^4`
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`

## Examples

### Example 1

**Input:**

```text
asteroids = [5, 10, -5]
```

**Output:**

```text
[5, 10]
```

**Explanation:**

- The asteroid `10` and `-5` collide, resulting in the larger asteroid `10` surviving.
- The asteroid `5` and `10` are both moving in the same direction, so they never collide.

### Example 2

**Input:**

```text
asteroids = [8, -8]
```

**Output:**

```text
[]
```

**Explanation:**

- The asteroid `8` and `-8` collide and both explode since they have equal sizes.

### Example 3

**Input:**

```text
asteroids = [10, 2, -5]
```

**Output:**

```text
[10]
```

**Explanation:**

- The asteroid `2` and `-5` collide, and `-5` survives as it is larger.
- The asteroid `10` collides with `-5` and survives as it is larger.

## Solution Approach

### Key Idea

We will use a **stack** to simulate the collisions:

- Positive asteroids are always pushed into the stack as they are moving to the right.
- When we encounter a negative asteroid, we check for collisions with the top of the stack (if the top of the stack is a positive asteroid).
- If the negative asteroid is smaller than the top of the stack, the negative asteroid is destroyed.
- If the negative asteroid is larger, it will destroy the top of the stack and continue checking for further collisions.
- If both asteroids are of equal size, both are destroyed.

### Step-by-Step Explanation

1. **Initialize an empty stack** to store the asteroids that survive collisions.

2. **Iterate through the asteroids**:

   - If the asteroid is positive, push it to the stack (because it moves to the right and will not collide with other right-moving asteroids).
   - If the asteroid is negative, we need to check the top of the stack (the last asteroid added). If the top is positive, a collision occurs:
     - If the absolute value of the negative asteroid is **greater** than the positive one, pop the top of the stack (destroy the positive asteroid) and continue the comparison with the next asteroid in the stack.
     - If the absolute values are **equal**, pop the top of the stack (both asteroids are destroyed).
     - If the negative asteroid is **smaller**, it is destroyed, and we stop further comparisons.

3. **Return the stack** after processing all the asteroids. The remaining asteroids in the stack are those that survived.

## Code Implementation

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;  // Stack to store the asteroids that survive
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            bool destroyed = false;

            // If current asteroid is negative, check for collisions with the top of the stack
            while (!st.empty() && asteroids[i] < 0 && st.back() > 0) {
                if (abs(asteroids[i]) > st.back()) {
                    // Current negative asteroid is larger, so pop the top positive asteroid
                    st.pop_back();
                } else if (abs(asteroids[i]) == st.back()) {
                    // Both asteroids are of the same size, both get destroyed
                    st.pop_back();
                    destroyed = true;
                    break;
                } else {
                    // The current negative asteroid is destroyed by the positive one
                    destroyed = true;
                    break;
                }
            }

            // If the current asteroid is not destroyed, push it to the stack
            if (!destroyed) {
                st.push_back(asteroids[i]);
            }
        }

        return st;  // Return the stack as the final result
    }
};
```

## Time and Space Complexity

### Time Complexity

- **O(n)**: We iterate through the list of asteroids once, and each asteroid is pushed and popped from the stack at most once.

### Space Complexity

- **O(n)**: The stack can hold all the asteroids if no collisions happen.

## Detailed Example Walkthrough

### Example 1: `[5, 10, -5]`

- Initial stack: `[]`
- **Process `5`**: No collision. Stack: `[5]`
- **Process `10`**: No collision. Stack: `[5, 10]`
- **Process `-5`**: Collision with `10`. `10` survives as it is larger. Stack: `[5, 10]`
- Final output: `[5, 10]`

### Example 2: `[8, -8]`

- Initial stack: `[]`
- **Process `8`**: No collision. Stack: `[8]`
- **Process `-8`**: Collision with `8`. Both are destroyed. Stack: `[]`
- Final output: `[]`

### Example 3: `[10, 2, -5]`

- Initial stack: `[]`
- **Process `10`**: No collision. Stack: `[10]`
- **Process `2`**: No collision. Stack: `[10, 2]`
- **Process `-5`**: Collision with `2`. `-5` survives as it is larger. Stack: `[10]`
- Final output: `[10]`

## Solution Using Stack

```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> st;

        for(auto it: ast){
            bool alive = true;

            while(!st.empty() && it <0 && st.top()>0) {

                if(st.top() < -it){ st.pop(); continue; }

                else if(st.top() == -it) st.pop();
                 alive = false; // noo need to push this when equal both gone
                 break;
            }
            if(alive) st.push(it);
        }

        vector<int> result(st.size());
          for (int i = st.size() - 1; i >= 0; --i) {
            result[i] = st.top();
            st.pop();
        }
       return result;
    }
};
```
