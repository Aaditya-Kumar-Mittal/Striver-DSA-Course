# Bit Manipulation Problem Name: `Check if a Number is a Power of Two`

## Problem Description

 Given an integer `n`, write a function to determine if it is a power of two.

### Solution - 1

```cpp
class Solution {
public:
    // Function to check if a number is a power of two
    bool isPowerOfTwo(int n) {
        // Check if n is positive and (n & (n - 1)) is zero
        return n > 0 && ((n & (n - 1)) == 0);
    }
};
```

### My Approach

1. **Objective:** Determine if the given integer `n` is a power of two.
2. **Mathematical Insight:**
   - A number `n` is a power of two if it has exactly one bit set in its binary representation.
   - For example, the binary representation of powers of two are:
     - 1: 0001
     - 2: 0010
     - 4: 0100
     - 8: 1000
   - For these numbers, the expression `n & (n - 1)` will be zero because:
     - `n - 1` flips all bits after the rightmost set bit (including the bit itself).
     - Performing `n & (n - 1)` will turn off the rightmost set bit, leaving zero.
3. **Algorithm Explanation:**
   - **Check if `n` is positive:** Powers of two must be positive.
   - **Check if `n & (n - 1)` equals zero:** This confirms that `n` has exactly one bit set.

### Time Complexity

- **Bitwise Operations:** The AND operation and subtraction are performed in constant time.
- **Overall Time Complexity:** O(1)

### Space Complexity

- **Auxiliary Space:** No extra space is used apart from the input and output.
- **Overall Space Complexity:** O(1)

### Example

- **Input:** n = 16
  - **Binary Representation:** 00010000
  - **n - 1:** 15 → 00001111
  - **Result of (16 & 15):** 00000000 → Output: true

- **Input:** n = 18
  - **Binary Representation:** 00010010
  - **n - 1:** 17 → 00010001
  - **Result of (18 & 17):** 00010000 → Output: false

Here's the complete Markdown file for the different approaches to solving the "Power of Two" problem. You can save this content into a `.md` file.

## Other Approaches

### 1. **Bit Manipulation**

**Approach:**

Use bit manipulation to check if a number is a power of two. For a number `n` to be a power of two, it must have exactly one bit set in its binary representation.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    return n > 0 && ((n & (n - 1)) == 0);
}
```

**Explanation:**

- The expression `n & (n - 1)` will be zero if `n` is a power of two.
- Example: For `n = 16` (binary: `00010000`), `n - 1 = 15` (binary: `00001111`), thus `16 & 15 = 00000000`.

**Time Complexity:** O(1)

**Space Complexity:** O(1)

---

### 2. **Mathematical Logarithm**

**Approach:**

Use logarithms to determine if a number is a power of two.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    double logResult = log2(n);
    return logResult == floor(logResult);
}
```

**Explanation:**

- Compute `log2(n)` and check if it's an integer.
- Example: For `n = 16`, `log2(16) = 4` which is an integer.

**Time Complexity:** O(1)

**Space Complexity:** O(1)

---

### 3. **Iterative Division**

**Approach:**

Divide the number `n` by 2 repeatedly until it becomes 1 or an odd number.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
```

**Explanation:**

- If `n` becomes 1, it was a power of two.
- Example: For `n = 8`, dividing by 2 gives 4, then 2, then 1.

**Time Complexity:** O(log n)

**Space Complexity:** O(1)

---

### 4. **Recursive Approach**

**Approach:**

Use recursion to check if `n` is a power of two.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    if (n == 1) return true;
    if (n <= 0 || n % 2 != 0) return false;
    return isPowerOfTwo(n / 2);
}
```

**Explanation:**

- Recursively divide `n` by 2 until it becomes 1 or less than 1.
- Example: For `n = 32`, divide recursively: 16 → 8 → 4 → 2 → 1.

**Time Complexity:** O(log n)

**Space Complexity:** O(log n) due to recursive stack space.

---

### 5. **Bit Count**

**Approach:**

Count the number of set bits in `n`.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    return __builtin_popcount(n) == 1;
}
```

**Explanation:**

- Use the built-in function `__builtin_popcount` to count the number of set bits.
- Example: For `n = 8` (binary: `00001000`), the count is 1, indicating it is a power of two.

**Time Complexity:** O(1)

**Space Complexity:** O(1)

---

### 6. **Using Powers of Two Array**

**Approach:**

Precompute all powers of two up to the maximum possible value and check if `n` is in this list.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    static unordered_set<int> powersOfTwo = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824};
    return powersOfTwo.count(n) > 0;
}
```

**Explanation:**

- Use a precomputed set of powers of two.
- Example: For `n = 64`, check if it is in the precomputed set.

**Time Complexity:** O(1)

**Space Complexity:** O(1) for set storage.

---

### 7. **Mathematical Approach with Modulo**

**Approach:**

Use modulo operation to check if the number `n` can be expressed as \(2^k\).

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    if (n <= 0) return false;
    while (n % 2 == 0) {
        n /= 2;
    }
    return n == 1;
}
```

**Explanation:**

- Reduce `n` by dividing by 2 while it is even.
- Check if the result is 1.
- Example: For `n = 32`, dividing by 2 repeatedly yields 1.

**Time Complexity:** O(log n)

**Space Complexity:** O(1)

---

### 8. **Using Bitwise Operations**

**Approach:**

Use bitwise operations to check if exactly one bit is set.

**Code:**

```cpp
bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}
```

**Explanation:**

- The expression `n & (n - 1)` will be zero if `n` is a power of two.
- Example: For `n = 64`, `n - 1 = 63` (binary: `00111111`), thus `64 & 63 = 00000000`.

**Time Complexity:** O(1)

**Space Complexity:** O(1)
