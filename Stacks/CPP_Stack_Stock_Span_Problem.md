# Stack Problem - Stock Span

## Problem Description

The `StockSpanner` class is designed to collect daily stock price quotes and compute the stock's **span** for each day's price. The **span** of the stock's price for a given day is defined as the maximum number of consecutive days (including the given day and going backward) for which the stock price was less than or equal to the price of that day.

For example:

- If the prices of the stock in the last four days are `[7, 2, 1, 2]` and the price of the stock today is `2`, then the span of today is `4` because starting from today, the price of the stock was `<= 2` for `4` consecutive days.
- If the prices of the stock in the last four days are `[7, 34, 1, 2]` and the price of the stock today is `8`, then the span of today is `3` because starting from today, the price of the stock was `<= 8` for `3` consecutive days.

## Class Design

### `StockSpanner`

- **Constructor:**

  - `StockSpanner()`: Initializes the `StockSpanner` object and sets up an empty stack and index.
  - The stack is used to store pairs of `(price, index)`, where `price` is the stock price and `index` is its respective day index.
  - `ind`: Tracks the current index (day).

- **Method:**
  - `int next(int price)`: Takes the stock price of the current day as input and returns the span of the stock's price.
    - Increments `ind` to keep track of the current day.
    - Uses a stack to store prices in a way that helps find the span efficiently.
    - Pops elements from the stack while the top of the stack represents a price that is less than or equal to the current `price` (since the span would extend past those days).
    - If the stack is empty after popping, it means there is no greater price before this day, and the span extends back to the start.
    - Pushes the current `price` along with `ind` onto the stack.
    - Returns the span as `ind - (st.empty() ? -1 : st.top().second)`.

### Helper Method

- `void clear()`: Clears the stack, resetting the state of the `StockSpanner`.

### Example

```cpp
StockSpanner stockSpanner = StockSpanner();
stockSpanner.next(100); // Returns 1
stockSpanner.next(80);  // Returns 1
stockSpanner.next(60);  // Returns 1
stockSpanner.next(70);  // Returns 2
stockSpanner.next(60);  // Returns 1
stockSpanner.next(75);  // Returns 4
stockSpanner.next(85);  // Returns 6
```

- The `next` function uses a stack to track prices and their indices efficiently.
- When processing a new price, it pops prices from the stack that are less than or equal to the new price, which helps determine how far back the span goes.

## Approach

- **Stack Usage:** The stack stores pairs of `(price, index)`.
- **Span Calculation:** For each new price, the stack is used to find how many consecutive days, including the current day, the price was greater or equal to previous days' prices.
- **Efficiency:** The approach ensures that each price is pushed and popped at most once, leading to an average time complexity of O(1) per `next` call.

## Complexity Analysis

- **Time Complexity:** `O(1)` amortized for each `next()` call.
  - Each element is pushed and popped from the stack at most once.
- **Space Complexity:** `O(n)` where `n` is the number of prices processed, since each price may be stored in the stack.

## Constraints

- `1 <= price <= 10^5`
- At most `10^4` calls will be made to `next()`.

## Code

```cpp
class StockSpanner {
    stack<pair<int, int>> st;
    int ind;

public:
    StockSpanner() {
        ind = -1;
        clear();
    }

    int next(int price) {
        std::ios::sync_with_stdio(0);
        std::cin.tie(0);
        std::cout.tie(0);

        ind = ind + 1;

        while (!st.empty() && st.top().first <= price) {
            st.pop();
        }

        int ans = ind - (st.empty() ? -1 : st.top().second);

        st.push({price, ind});

        return ans;
    }

    void clear() {
        while (!st.empty()) {
            st.pop();
        }
    }
};
```

## How It Works

1. **Stack Maintenance:**
   - For each price, remove all prices from the stack that are less than or equal to the current price because the current price will dominate those days.
   - The top of the stack (if it exists) then represents the nearest greater price before the current day.
2. **Span Calculation:**
   - If the stack is empty, it means all previous prices are smaller than or equal to the current price, so the span extends from the start.
   - Otherwise, the difference between the current index and the index at the top of the stack gives the span.

## Example Walkthrough

1. **`stockSpanner.next(100)`**

   - Stack: `[]` (initially empty)
   - After processing `100`: `st = [(100, 0)]`
   - Span: `1` (no previous elements)

2. **`stockSpanner.next(80)`**

   - Stack: `[(100, 0)]`
   - After processing `80`: `st = [(100, 0), (80, 1)]`
   - Span: `1` (80 is less than 100)

3. **`stockSpanner.next(60)`**

   - Stack: `[(100, 0), (80, 1)]`
   - After processing `60`: `st = [(100, 0), (80, 1), (60, 2)]`
   - Span: `1` (60 is less than 80)

4. **`stockSpanner.next(70)`**

   - Stack: `[(100, 0), (80, 1), (60, 2)]`
   - Pop `60` (it is less than `70`)
   - After processing `70`: `st = [(100, 0), (80, 1), (70, 3)]`
   - Span: `2` (includes `60` and `70`)

5. **`stockSpanner.next(75)`**
   - Stack: `[(100, 0), (80, 1), (70, 3)]`
   - Pop `70` (it is less than `75`)
   - After processing `75`: `st = [(100, 0), (80, 1), (75, 4)]`
   - Span: `4` (includes `60`, `70`, `60`, `75`)

## Conclusion

The `StockSpanner` class efficiently calculates the span of stock prices using a stack-based approach. This solution ensures that the computation is both time and space efficient, suitable for large inputs as specified by the problem constraints.

## Vector Based Solution

```cpp
class Solution {
public:
    // Function to calculate the span of stock's price for all n days.
    vector<int> calculateSpan(int price[], int n) {
        // Stack to store indices of prices.
        stack<int> st;
        // Vector to store the span for each day.
        vector<int> stockSpan(n);

        // Traverse through each day's price.
        for (int i = 0; i < n; i++) {
            // Pop elements from the stack while the current price is greater than or equal to the price at stack top index.
            while (!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }

            // If stack becomes empty, all previous prices are smaller.
            // Span is the entire length from day 0 to the current day.
            stockSpan[i] = st.empty() ? (i + 1) : (i - st.top());

            // Push the current day's index onto the stack.
            st.push(i);
        }

        return stockSpan;
    }
};
```

### GeeksForGeeks Solution

```cpp
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    // Function to calculate the span of stock’s price for all n days.
    vector<int> calculateSpan(int price[], int n) {

        stack<long long> st;

        vector<int> stockSpan(n, 1);

        // Traverse through each day's price
        for(int i = 0; i < n; i++) {
            // Pop elements from the stack while the current price is greater than the price at stack top index.
            while(!st.empty() && price[st.top()] <= price[i]) {
                st.pop();
            }

            // If stack becomes empty, all previous prices are smaller.
            // Span is the entire length from day 0 to the current day.
            if(st.empty()) {
                stockSpan[i] = i + 1;
            } else {
                // Otherwise, span is the difference between the current day and the index of the last greater element.
                stockSpan[i] = i - st.top();
            }

            // Push the current day's index onto the stack.
            st.push(i);
        }

        return stockSpan;
    }
};
```
