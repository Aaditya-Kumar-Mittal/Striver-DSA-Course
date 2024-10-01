# Stack Problem: Largest Rectangle in Histogram

## Problem Statement

You are given an array of integers `heights` representing the histogram's bar heights where the width of each bar is `1`. Your task is to return the **area of the largest rectangle** that can be formed in the histogram.

Each histogram bar is represented by its height, and the width of each bar is fixed as `1`. You need to find the largest rectangular area that can be formed by one or more consecutive bars.

### Constraints

- `1 <= heights.length <= 10^5`
- `0 <= heights[i] <= 10^4`

---

## Examples

### Example 1

**Input:**

```text
heights = [2, 1, 5, 6, 2, 3]
```

**Output:**

```text
10
```

**Explanation:**

- The histogram looks like:

  ```text
           |
        |  |
        |  |
        |  |     |
  |     |  |  |  |
  |  |  |  |  |  |
  ------------------
  2  1  5  6  2  3
  ```

- The largest rectangle is formed between the bars at indices `2` and `3`, with height `5` and width `2` (total area = `5 * 2 = 10`).

---

### Example 2

**Input:**

```text
heights = [2, 4]
```

**Output:**

```text
4
```

**Explanation:**

- The histogram looks like:

  ```text
     |
     |
  |  |
  |  |
  ------
  2  4
  ```

- The largest rectangle is formed by the single bar with height `4` (area = `4 * 1 = 4`).

---

## Solution - 1 Approach

### Key Idea

To solve this problem efficiently, we need to determine for each bar in the histogram:

- The **Next Smaller Element (NSE)**: The index of the first bar to the right that is smaller than the current bar.
- The **Previous Smaller Element (PSE)**: The index of the first bar to the left that is smaller than the current bar.

Using these two values, we can calculate the maximum possible width for a rectangle that has the current bar as the smallest bar in the rectangle.

### Steps

1. **Calculate the NSE (Next Smaller Element):**
   - For each bar, find the first bar to the right that is shorter. This is done using a stack to track indices and compare heights.
2. **Calculate the PSE (Previous Smaller Element):**
   - Similarly, find the first bar to the left that is shorter using another stack.
3. **Calculate the maximum area:**
   - For each bar, compute the area of the rectangle that can be formed with that bar as the shortest one. The width of the rectangle is determined by the distance between the NSE and PSE, and the height is the height of the bar itself.

### Formula

For each bar `heights[i]`, the width of the rectangle is `(NSE[i] - PSE[i] - 1)`, and the height is `heights[i]`. The area is:

```text
area = heights[i] * (NSE[i] - PSE[i] - 1)
```

Finally, we find the maximum area from all possible rectangles.

## Code Implementation

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;  // Stack to store indices
        vector<int> NSE(n, 0), PSE(n, 0);

        // Step 1: Calculate NSE (Next Smaller Element)
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            NSE[i] = st.empty() ? n : st.top();  // If stack is empty, no smaller element to the right
            st.push(i);
        }

        // Clear the stack for the next calculation
        while (!st.empty())
            st.pop();

        // Step 2: Calculate PSE (Previous Smaller Element)
        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i])
                st.pop();
            PSE[i] = st.empty() ? -1 : st.top();  // If stack is empty, no smaller element to the left
            st.push(i);
        }

        // Step 3: Calculate the maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = heights[i] * (NSE[i] - PSE[i] - 1);  // Area formula
            maxArea = max(maxArea, area);  // Track the maximum area
        }

        return maxArea;
    }
};
```

## Explanation of the Code

### Step 1: Calculating Next Smaller Element (NSE)

- We iterate over the array from right to left.
- For each element, we use a stack to keep track of the indices of bars that haven't yet found their next smaller element.
- If the current bar is smaller than the bar at the top of the stack, we pop the stack (this means we found a smaller bar to the right).
- If the stack is empty, it means there is no smaller element to the right, so we set the value of `NSE[i]` to `n` (i.e., an index out of bounds).

### Step 2: Calculating Previous Smaller Element (PSE)

- We now iterate over the array from left to right, following a similar process to find the previous smaller element for each bar.
- If no smaller element exists to the left, we set `PSE[i]` to `-1`.

### Step 3: Calculating the Maximum Area

- For each bar, we calculate the width of the largest rectangle that can be formed using that bar as the smallest bar.
- The width is the difference between the indices of the next and previous smaller elements, minus 1.
- The area is then calculated by multiplying this width by the height of the bar.
- We keep track of the maximum area during the iteration.

## Time and Space Complexity

### Time Complexity

- **O(n)**: Each element is pushed and popped from the stack at most once during the calculation of both `NSE` and `PSE`. Thus, the overall complexity is linear in terms of the number of bars, i.e., `O(n)`.

### Space Complexity

- **O(n)**: We use two arrays `NSE` and `PSE`, and a stack to store the indices, all of which require `O(n)` space.

## Detailed Example Walkthrough

### Example: `[2, 1, 5, 6, 2, 3]`

1. **Initial array:**
   - Heights: `[2, 1, 5, 6, 2, 3]`
2. **Step 1: NSE Calculation:**

   - NSE: `[1, 6, 4, 4, 6, 6]`

3. **Step 2: PSE Calculation:**

   - PSE: `[-1, -1, 1, 2, 1, 4]`

4. **Step 3: Area Calculation:**
   - For each bar, calculate the area:
     - `heights[0] = 2`, width = `1 - (-1) - 1 = 1`, area = `2 * 1 = 2`
     - `heights[1] = 1`, width = `6 - (-1) - 1 = 6`, area = `1 * 6 = 6`
     - `heights[2] = 5`, width = `4 - 1 - 1 = 2`, area = `5 * 2 = 10`
     - `heights[3] = 6`, width = `4 - 2 - 1 = 1`, area = `6 * 1 = 6`
     - `heights[4] = 2`, width = `6 - 1 - 1 = 4`, area = `2 * 4 = 8`
     - `heights[5] = 3`, width = `6 - 4 - 1 = 1`, area = `3 * 1 = 3`
   - The maximum area is `10`.

## Conclusion

This solution efficiently calculates the largest rectangular area in a histogram using stacks to track the Next and Previous Smaller Elements. The solution has an optimal time complexity of **O(n)**, making it well-suited for large inputs.

## Solution - 2 Implementaion (Most Optimized)

```cpp
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * Function to calculate the largest rectangle area in a histogram.
     *
     * @param heights - vector of integers representing the heights of the histogram bars.
     * @return the area of the largest rectangle that can be formed in the histogram.
     *
     * The algorithm is based on using a stack to efficiently compute the maximum
     * area of the rectangles in O(n) time complexity. It processes each bar and ensures
     * the stack holds indices of the histogram bars in increasing order of their heights.
     * When a lower height bar is encountered, it computes the area for the previous bars.
     */
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();  // Get the size of the heights array
        stack<int> st;           // Stack to store the indices of the histogram bars
        int maxArea = 0;         // Variable to track the maximum area

        // Iterate over each bar in the histogram
        for (int i = 0; i < n; i++) {
            // Process the stack if the current height is smaller than the top of the stack
            while (!st.empty() && heights[st.top()] > heights[i]) {
                // Pop the top element and calculate the area for it
                int myElement = heights[st.top()];  // Height of the popped element
                st.pop();                           // Remove the top of the stack

                int NSE = i;                        // The current element is the Next Smaller Element
                int PSE = st.empty() ? -1 : st.top(); // The element at the new top of the stack is the Previous Smaller Element

                // Calculate the area with 'myElement' as the smallest height
                int area = myElement * (NSE - PSE - 1);

                // Update the maximum area
                maxArea = max(area, maxArea);
            }

            // Push the current index onto the stack
            st.push(i);
        }

        // Process the remaining elements in the stack after the iteration
        while (!st.empty()) {
            int NSE = n;                            // The end of the histogram serves as the Next Smaller Element
            int myElement = heights[st.top()];      // Height of the top element in the stack
            st.pop();                               // Remove the top of the stack

            int PSE = st.empty() ? -1 : st.top();   // The element at the new top of the stack is the Previous Smaller Element

            // Calculate the area with 'myElement' as the smallest height
            int area = myElement * (NSE - PSE - 1);

            // Update the maximum area
            maxArea = max(area, maxArea);
        }

        // Return the largest area found
        return maxArea;
    }
};

// Optimization for faster input/output
auto init = []() {
    ios::sync_with_stdio(false);  // Disable synchronization with C-style I/O
    cin.tie(nullptr);             // Untie cin from cout for faster input
    return '$';                   // Return a placeholder value (not used in logic)
}();

/**
 * Analysis:
 *
 * Problem: Largest Rectangle in Histogram
 *
 * Time Complexity: O(n)
 * - Each element is pushed and popped from the stack at most once, leading to an overall time complexity of O(n),
 *   where 'n' is the number of bars in the histogram.
 *
 * Space Complexity: O(n)
 * - The stack can hold up to 'n' indices in the worst case, leading to O(n) auxiliary space complexity.
 *
 * Approach:
 * - Use a stack to keep track of indices of the histogram bars in increasing order of their heights.
 * - For each bar, if the current bar is smaller than the bar at the stack's top, calculate the area of the rectangle
 *   formed by the bar at the top of the stack.
 * - Continue this until the stack is empty, ensuring that for each bar, the largest rectangle area is computed.
 * - Finally, process any remaining bars in the stack to calculate the area for the bars that extend to the end of the histogram.
 */
```

## Solution - 3 Implementation

```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        vector<int> index;

        int n = a.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            while (!index.empty() && a[i] <= a[index.back()]) {
                int val = a[index.back()];
                index.pop_back();
                if (index.empty())
                    ans = max(ans, val * (i));
                else
                    ans = max(ans, val * (i - index.back() - 1));

            }
            index.push_back(i);
        }
        while(!index.empty()){
                            int val = a[index.back()];
                index.pop_back();
                if (index.empty())
                    ans = max(ans, val * (n));
                else
                    ans = max(ans, val * (n - index.back() - 1));
        }
        return ans;
    }
};
auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return '$';
}();
```

## Solution - 4 Implementation

```cpp
class Solution
{
public:
  int largestRectangleArea(vector<int> &hs)
  {
    if (hs.size() == 0)
      return 0;
    hs.push_back(0);
    vector<int> st{-1};
    int n = hs.size();
    int result = 0;
    for (int i = 0; i < n; ++i)
    {
      while (st.size() > 1 && hs[st.back()] >= hs[i])
      {
        int k = st.back();
        st.pop_back();
        int w = i - st.back() - 1;
        int s = hs[k] * w;
        result = max(result, s);
      }
      st.push_back(i);
    }
    return result;
  }
};

auto init = []()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return '$';
}();
```
