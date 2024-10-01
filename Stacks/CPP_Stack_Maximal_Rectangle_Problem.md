# Maximal Rectangle Problem

## Problem Description

Given a `rows x cols` binary matrix filled with `0's` and `1's`, find the largest rectangle containing only `1's` and return its area.

### Problem Constraints

- `rows == matrix.length`
- `cols == matrix[i].length`
- `1 <= row, cols <= 200`
- `matrix[i][j]` is either `'0'` or `'1'`.

---

## Example 1

**Input:**

```plaintext
matrix = [
  ["1", "0", "1", "0", "0"],
  ["1", "0", "1", "1", "1"],
  ["1", "1", "1", "1", "1"],
  ["1", "0", "0", "1", "0"]
]
```

**Output:**

```plaintext
6
```

**Explanation:**  
The maximal rectangle is highlighted as below:

```plaintext
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
```

---

## Example 2

**Input:**

```plaintext
matrix = [["0"]]
```

**Output:**

```plaintext
0
```

---

## Example 3

**Input:**

```plaintext
matrix = [["1"]]
```

**Output:**

```plaintext
1
```

---

## Approach

This problem can be reduced to multiple histogram area problems. For each row in the matrix, think of it as a row in a histogram, where heights increase with each consecutive `'1'`. The key idea is:

1. Convert each row of the binary matrix into a histogram, where the height of each column is the count of consecutive `1's`.
2. Use the largest rectangle in a histogram approach to calculate the maximal rectangle area for each histogram formed.
3. Keep track of the maximum area.

---

## C++ Solution with Multiline Comments

```cpp
class Solution {
public:
    /**
     * Function to calculate the largest rectangle area in a histogram.
     * This uses a stack-based approach to calculate the largest area for each bar,
     * considering the heights of the bars.
     *
     * @param heights: a vector of integers representing heights of histogram bars.
     * @return: the maximum rectangle area in the histogram.
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
                st.pop();  // Remove the top of the stack

                int NSE = i;  // The current element is the Next Smaller Element
                int PSE = st.empty() ? -1 : st.top();  // The element at the new top of the stack is the Previous Smaller Element

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
            int NSE = n;  // The end of the histogram serves as the Next Smaller Element
            int myElement = heights[st.top()];  // Height of the top element in the stack
            st.pop();  // Remove the top of the stack

            int PSE = st.empty() ? -1 : st.top();  // The element at the new top of the stack is the Previous Smaller Element

            // Calculate the area with 'myElement' as the smallest height
            int area = myElement * (NSE - PSE - 1);

            // Update the maximum area
            maxArea = max(area, maxArea);
        }

        // Return the largest area found
        return maxArea;
    }

    /**
     * Function to calculate the maximal rectangle in a 2D binary matrix.
     * This converts each row of the binary matrix into a histogram and then uses the largest rectangle in a histogram approach.
     *
     * @param matrix: a 2D vector of characters representing the binary matrix.
     * @return: the maximum rectangle area containing only 1's.
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Get the dimensions of the matrix
        int n = matrix.size();
        int m = matrix[0].size();

        // Vector to store the heights of the histogram for each row
        vector<vector<int>> prefixSum(n, vector<int>(m, 0));

        // Convert the binary matrix into a histogram
        for (int j = 0; j < m; j++) {
            int sum = 0;  // Reset the sum for each column

            for (int i = 0; i < n; i++) {
                // Convert '1' to integer 1 and '0' to integer 0 and accumulate heights
                sum += (matrix[i][j] - '0');

                // If the current element is '0', reset the sum to 0
                if (matrix[i][j] == '0') {
                    sum = 0;
                }

                // Store the sum in the prefix sum array (heights of the histogram)
                prefixSum[i][j] = sum;
            }
        }

        int maxArea = 0;  // Variable to track the maximum rectangle area

        // Calculate the largest rectangle area for each row (histogram)
        for (int i = 0; i < n; i++) {
            maxArea = max(maxArea, largestRectangleArea(prefixSum[i]));
        }

        // Return the largest area found
        return maxArea;
    }
};

// Optimization: Disable synchronization with C-style I/O for faster input/output
auto init = []() {
    ios::sync_with_stdio(false);  // Disable synchronization with C-style I/O
    cin.tie(nullptr);  // Untie cin from cout for faster input
    return '$';  // Return a placeholder value (not used in logic)
}();
```

## Key Concepts

1. **Histogram Conversion**:  
   Each row of the binary matrix is treated as a histogram, where the heights of the columns are calculated based on the number of consecutive `1's`.

2. **Largest Rectangle in Histogram**:  
   The `largestRectangleArea` function calculates the maximum area of a rectangle in a histogram using a stack-based approach, where we find the Next Smaller Element (NSE) and Previous Smaller Element (PSE) for each bar.

3. **Optimization**:  
   The `init` function disables synchronization with C-style I/O and unties `cin` from `cout` for faster input and output operations.

---

## Time Complexity

- **Time Complexity**:  
  The overall time complexity is `O(n * m)` because we process each element of the matrix once and calculate the largest rectangle for each row using a stack, which takes linear time for each row.

- **Space Complexity**:  
  The space complexity is `O(n * m)` due to the additional space used for the `prefixSum` matrix and the stack used in the `largestRectangleArea` function.

## Other Solutions

### Solution - 2 Implementation

Here’s your C++ code with detailed multiline documentation comments:

```cpp
class Solution {
public:
    /**
     * @brief Function to find the maximal rectangle in a 2D binary matrix filled with '0's and '1's.
     *
     * This function implements a dynamic programming approach that scans through the matrix row by row.
     * It calculates the height of consecutive '1's up to the current row, and for each row, it finds
     * the maximum rectangle area using the heights, the left and right boundaries for that row.
     *
     * @param matrix A 2D vector of characters representing the binary matrix.
     *               '1' represents a filled cell, '0' represents an empty cell.
     * @return int The area of the largest rectangle containing only '1's in the matrix.
     */
    int maximalRectangle(vector<vector<char>>& matrix) {
        // Fast I/O optimizations
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        // If the matrix is empty, return 0 (no area).
        if (matrix.empty()) return 0;

        int m = matrix.size();       // Number of rows in the matrix
        int n = matrix[0].size();    // Number of columns in the matrix

        // These vectors store the left boundary, right boundary, and heights of '1's for each column.
        vector<int> left(n), right(n), height(n);

        // Initialize the right boundaries to 'n' (right edge of the matrix).
        fill(right.begin(), right.end(), n);

        int maxarea = 0;  // Variable to store the maximum rectangle area

        // Iterate through each row of the matrix
        for (int i = 0; i < m; i++) {
            int cur_left = 0, cur_right = n;  // Current left and right boundaries

            // Step 1: Update the height array. It stores the count of consecutive '1's up to the current row.
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    height[j]++;    // If current cell is '1', increment the height
                else
                    height[j] = 0;  // If it's '0', reset the height to 0
            }

            // Step 2: Update the left array. It stores the leftmost boundary for each column where '1's are continuous.
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    left[j] = max(left[j], cur_left);  // Take the maximum of the current left boundary and the previous one
                else {
                    left[j] = 0;      // Reset left boundary if current cell is '0'
                    cur_left = j + 1; // Move the current left pointer to the next column
                }
            }

            // Step 3: Update the right array. It stores the rightmost boundary for each column where '1's are continuous.
            for (int j = n - 1; j >= 0; j--) {
                if (matrix[i][j] == '1')
                    right[j] = min(right[j], cur_right);  // Take the minimum of the current right boundary and the previous one
                else {
                    right[j] = n;   // Reset right boundary if current cell is '0'
                    cur_right = j;  // Move the current right pointer to the previous column
                }
            }

            // Step 4: Calculate the maximal area for the current row using the height, left, and right arrays.
            for (int j = 0; j < n; j++) {
                // Calculate the area of the rectangle formed with height[j] and between left[j] and right[j]
                maxarea = max(maxarea, (right[j] - left[j]) * height[j]);
            }
        }

        // Return the maximum area found in the matrix
        return maxarea;
    }
};
```

### Detailed Explanation of Each Section

- **Input and I/O Optimizations**:  
  The `ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);` commands are used to speed up input/output operations by unsynchronizing C++ streams with C-style I/O functions.

- **Edge Case**:  
  If the input matrix is empty, we immediately return `0` since no rectangle can exist.

- **Variables**:

  - `m`: The number of rows in the matrix.
  - `n`: The number of columns in the matrix.
  - `left[]`: An array that keeps track of the left boundary (the furthest left position where `1's` can form a rectangle for each column).
  - `right[]`: An array that keeps track of the right boundary (the furthest right position where `1's` can form a rectangle for each column).
  - `height[]`: An array that keeps track of the height of consecutive `1's` up to the current row for each column.
  - `maxarea`: The maximum rectangle area found during the entire computation.

- **Steps**:
  1. **Updating Heights**: For every cell in the current row, if the value is `'1'`, increment the height; otherwise, reset it to `0`.
  2. **Updating Left Boundaries**: For every column, calculate how far the left boundary of the rectangle can extend, ensuring that it's consistent with previous rows.
  3. **Updating Right Boundaries**: Similarly, calculate how far the right boundary of the rectangle can extend, ensuring it doesn't exceed earlier restrictions.
  4. **Calculating Area**: For each column, compute the area using the height, left, and right arrays and update the maximum area if the current one is larger.

This solution ensures that the time complexity remains linear, i.e., `O(m * n)`, where `m` is the number of rows and `n` is the number of columns. The space complexity is `O(n)` for the three auxiliary arrays (`left`, `right`, `height`).
