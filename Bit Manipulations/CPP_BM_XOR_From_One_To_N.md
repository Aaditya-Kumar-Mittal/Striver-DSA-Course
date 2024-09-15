# Bit Manipulation Problem: Calculate XOR of all numbers from 1 to n

## **Concept**

- XOR from 1 to n follows a repeating pattern every 4 numbers. The values of XOR(1 to n) can be determined by the remainder of n when divided by 4 (`n % 4`).
- We can avoid calculating XOR step-by-step and use this repeating pattern for constant-time computation.

### **Pattern**

- XOR(1 to n) based on n % 4:
  - `n % 4 == 0` -> XOR(1 to n) = n
  - `n % 4 == 1` -> XOR(1 to n) = 1
  - `n % 4 == 2` -> XOR(1 to n) = n + 1
  - `n % 4 == 3` -> XOR(1 to n) = 0
- This pattern emerges because XOR cancels out pairs of the same number, and XOR's properties allow for this predictable cycle.

### **Time Complexity**

- `O(1)` because the XOR is determined using a mathematical pattern, and no loops or recursion are required.

### **Space Complexity**

- `O(1)` as no extra space is used other than a few variables.

### **Example**

- Input: n = 5
  - Output: 1
  - Explanation: XOR(1 to 5) = 1 ^ 2 ^ 3 ^ 4 ^ 5 = 1.

  - Input: n = 8
  - Output: 8
  - Explanation: XOR(1 to 8) = 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 = 8.

## Code

```cpp
/*
    Function to calculate the XOR of all numbers from 1 to n.

    Parameters:
    - n: The upper bound number (1 to n) for which we need to calculate XOR.
    
    Returns:
    - The result of XOR of all numbers from 1 to n.
    
    Approach:
    - There is a pattern in the XOR of numbers from 1 to n based on n % 4:
      - If n % 4 == 0, XOR(1 to n) = n
      - If n % 4 == 1, XOR(1 to n) = 1
      - If n % 4 == 2, XOR(1 to n) = n + 1
      - If n % 4 == 3, XOR(1 to n) = 0
    - This pattern repeats every 4 numbers, allowing us to calculate the XOR in constant time.

    Why this works:
    - XOR is a binary operation with several properties, such as:
      - XOR of a number with itself is 0: `x ^ x = 0`
      - XOR of a number with 0 is the number itself: `x ^ 0 = x`
    - The pattern in XOR results is derived from how binary numbers increment.
*/

int calculateXOR(int n) {
    // Check remainder of n when divided by 4 and return the corresponding XOR value.
    if (n % 4 == 1) return 1;       // If n % 4 == 1, XOR(1 to n) = 1
    if (n % 4 == 2) return n + 1;   // If n % 4 == 2, XOR(1 to n) = n + 1
    if (n % 4 == 3) return 0;       // If n % 4 == 3, XOR(1 to n) = 0
    return n;                       // If n % 4 == 0, XOR(1 to n) = n
}
```

### Key Points

- **Pattern-based Calculation**: The XOR of numbers from 1 to `n` follows a repeating pattern based on `n % 4`.
- **Time Complexity**: Constant time `O(1)` due to the direct use of modulo and conditional checks.
- **Space Complexity**: Constant space `O(1)` since no extra data structures are needed.
