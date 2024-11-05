# Greedy Problem: Lemonade Change (Leetcode 860)

## Problem Statement

You are running a lemonade stand where each cup of lemonade costs $5. Customers pay with either a $5, $10, or $20 bill. Each customer pays exactly once, and each payment must have the correct change provided if it requires any.

Given an integer array `bills` where `bills[i]` is the bill given by the ith customer, return `true` if you can provide the correct change to every customer. Otherwise, return `false`.

### Examples

**Example 1:**

- **Input:** `bills = [5,5,5,10,20]`
- **Output:** `true`
- **Explanation:** The first three customers pay with $5 bills, which gives enough change for the subsequent customers who pay with larger bills.

**Example 2:**

- **Input:** `bills = [5,5,10,10,20]`
- **Output:** `false`
- **Explanation:** For the last customer with a $20 bill, we cannot provide $15 in change, since we only have two $10 bills.

### Constraints

- \(1 \leq \text{bills.length} \leq 10^5\)
- Each `bills[i]` is either 5, 10, or 20.

### Approach

1. **Track Change Available**:
   - Use two variables, `fives` and `tens`, to keep count of $5 and $10 bills on hand.
2. **Iterate Through Bills**:
   - For a $5 bill, simply increase `fives`.
   - For a $10 bill, provide one $5 bill as change if available; otherwise, return `false`.
   - For a $20 bill, prioritize giving one $10 and one $5 as change if both are available. If not, attempt to give three $5 bills. If neither option is possible, return `false`.
3. **Result**:
   - If the loop completes without returning `false`, return `true`.

### Code with Detailed Comments

```cpp
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief Determines if change can be provided for every customer.
     *
     * @param bills Vector of integers representing each customer's bill.
     * @return bool True if change can be provided to every customer, otherwise false.
     */
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;

        // Iterate through each bill in the bills array
        for (int i = 0; i < bills.size(); i++) {
            // Case when customer pays with a $5 bill
            if (bills[i] == 5) {
                fives += 1; // Collect $5 bill as no change is needed

            // Case when customer pays with a $10 bill
            } else if (bills[i] == 10) {
                if (fives) { // Check if we have a $5 bill for change
                    fives -= 1; // Use one $5 bill as change
                    tens += 1;  // Add the $10 bill to our cash
                } else {
                    return false; // Cannot provide change, return false
                }

            // Case when customer pays with a $20 bill
            } else {
                if (tens && fives) { // Prefer using one $10 and one $5 for $15 change
                    tens -= 1; // Use one $10 bill
                    fives -= 1; // Use one $5 bill
                } else if (fives >= 3) { // Alternatively, use three $5 bills for change
                    fives -= 3;
                } else {
                    return false; // Cannot provide change, return false
                }
            }
        }

        return true; // Successfully provided change for all customers
    }
};

/**
 * Problem: Lemonade Change (Leetcode 860)
 *
 * Analysis:
 * - The goal is to ensure correct change can be provided for every customer.
 * - Maintain counts of $5 and $10 bills for change, and prioritize using higher denominations when possible to preserve smaller bills for future transactions.
 *
 * Time Complexity: O(n)
 * - We iterate through the `bills` array once, performing constant-time operations per customer.
 *
 * Space Complexity: O(1)
 * - Only a fixed number of integer variables are used to track available bills, regardless of the input size.
 *
 * Edge Cases:
 * - All customers pay with $5 bills: Change can always be provided, and the function should return `true`.
 * - Insufficient smaller denominations to provide change for a large bill, e.g., only having $10 bills for a $20 bill's change.
 * - Multiple customers with $20 bills without sufficient smaller bills for change.
 */
```

---

### Explanation of Code

- **Tracking Bills**: Counts of $5 and $10 bills are maintained to simplify providing change efficiently.
- **Decision Making**: For each bill type, the code chooses the smallest possible denominations first, especially for $20 bills, ensuring more options for future customers.
- **Return**: The code returns `true` if all customers are served with correct change; otherwise, `false`.

### Complexity Analysis

- **Time Complexity**: \(O(n)\)
  - Each customer’s payment is processed in constant time, resulting in a linear complexity.
- **Space Complexity**: \(O(1)\)
  - The space used is constant, as only two variables track counts of available bills.

### Edge Cases

1. **All $5 Bills**: Should always return `true`, as no change is required.
2. **Insufficient Bills for $20 Change**: The function will return `false` if there aren’t enough smaller bills.
3. **Multiple Large Bills Consecutively**: Proper handling is required to ensure smaller bills are preserved for upcoming transactions.
