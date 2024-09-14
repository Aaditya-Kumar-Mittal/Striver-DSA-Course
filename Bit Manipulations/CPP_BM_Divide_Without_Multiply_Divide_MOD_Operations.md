# Divide Two Integers without using Multiplication, Division, and Mod Operator

## Problem Statement

Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, or modulus operators.

The integer division should truncate toward zero, meaning that the result should lose its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.

Return the quotient after dividing the dividend by the divisor.

**Note**: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. If the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, return -2^31.

### Example

```plaintext
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10 / 3 = 3.33333.. which is truncated to 3.

Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7 / -3 = -2.33333.. which is truncated to -2.
```

## Approach

To divide two integers without using multiplication, division, or modulus operators, we use **bit manipulation** and **subtraction**.

### Steps

1. **Handle the sign**:

   - Determine whether the result should be positive or negative based on the signs of `dividend` and `divisor`.

2. **Bit manipulation**:

   - Left-shift the divisor to find the largest multiple that can be subtracted from the dividend.
   - Subtract this multiple from the dividend and accumulate the result in the quotient.

3. **Edge cases**:
   - If the quotient exceeds the 32-bit signed integer limit, return `INT_MAX` or `INT_MIN`.

## Code

```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        // Special case when dividend equals divisor
        if (dividend == divisor) return 1;

        // Special case when dividend is zero
        if (dividend == 0) return 0;

        // Determine the sign of the result
        bool sign = true; // Positive result by default
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            sign = false;  // Negative result if one of them is negative
        }

        // Work with absolute values to avoid overflow
        long num = abs(dividend);
        long d = abs(divisor);

        long quotient = 0;

        // Perform bit manipulation and subtraction
        while (num >= d) {
            int cnt = 0;

            // Find the largest multiple of the divisor
            while (num >= (d << (cnt + 1))) {
                cnt += 1;
            }

            // Add the multiple to the quotient
            quotient += 1 << cnt;

            // Subtract the found multiple from the dividend
            num -= d << cnt;
        }

        // Handle 32-bit overflow cases
        if (quotient == (1 << 31) && sign) return INT_MAX;
        if (quotient == (1 << 31) && !sign) return INT_MIN;

        // Return the quotient with the correct sign
        return sign ? quotient : -quotient;
    }
};
```

## Complexity Analysis

- **Time Complexity**: O(log N), where `N` is the dividend. The loop runs logarithmically as we shift the divisor to find the largest multiple.
- **Space Complexity**: O(1), as we are using a constant amount of extra space for the variables.
