# Trapping Rain Water

This program calculates how much water can be trapped between the heights of walls after it rains. The walls are represented as an array of non-negative integers, where the width of each bar is 1 unit. The amount of water trapped above each bar is determined by the heights of the tallest bars to the left and right of the current.

## Problem Description

- Given an array `height[]` where each element represents the height of walls, calculate the total units of water that can be trapped between the walls.
- Water is trapped between two higher walls, with the current bar acting as the base for calculating trapped water.

## Approach

### Two-Pointer Technique

- A **two-pointer approach** is used to traverse the array from both ends towards the center.
- For each element, the algorithm calculates how much water can be trapped above it based on the **minimum of the maximum heights** to its left and right.
- We maintain two pointers `l` and `r`, representing the left and right indices, and two variables `lMax` and `rMax` to track the maximum heights on the left and right.

## Code

```cpp
class Solution {
public:
    /*
        Function to calculate how much water can be trapped between the heights.
        This approach uses two pointers to scan from both ends of the array towards the center.
        For each element, the algorithm calculates how much water can be trapped above it
        based on the minimum of the maximum heights to its left and right.

        Parameters:
        - vector<int>& height: Reference to the input array representing heights of walls.

        Returns:
        - int: Total units of water that can be trapped between the walls.
    */
    int trap(vector<int>& height) {
        // Initialize variables
        int lMax = 0, rMax = 0;              // Track the left and right maximum heights
        int total = 0;                       // Total water trapped
        int l = 0, r = height.size() - 1;    // Left and right pointers

        // Use a two-pointer approach to traverse the array from both ends
        while (l <= r) {
            // If the left height is less than or equal to the right height
            if (height[l] <= height[r]) {
                // If the current left height is greater than or equal to the left maximum, update it
                if (height[l] >= lMax) {
                    lMax = height[l];
                }
                // Otherwise, calculate water trapped and add to the total
                else {
                    total += lMax - height[l];
                }
                l++; // Move the left pointer to the right
            }
            // If the right height is less than the left height
            else {
                // If the current right height is greater than or equal to the right maximum, update it
                if (height[r] >= rMax) {
                    rMax = height[r];
                }
                // Otherwise, calculate water trapped and add to the total
                else {
                    total += rMax - height[r];
                }
                r--; // Move the right pointer to the left
            }
        }

        return total; // Return the total trapped water
    }
};
```

## Explanation

1. **Two-Pointer Approach**:

   - Two pointers (`l` for the left end and `r` for the right end) are used to scan the array from both sides.
   - The approach ensures that water is only trapped if there are **higher walls** on both sides of the current position.
   - Depending on whether `height[l] <= height[r]`, the algorithm calculates the trapped water for the smaller of the two, ensuring the calculation is accurate for each bar.

2. **Water Calculation**:

   - For every index, the amount of water trapped above it is determined by the difference between the **maximum height** seen so far (either on the left or right) and the current height at that index.
   - The total amount of water trapped is accumulated by summing the differences for each index.

3. **Key Points**:
   - We update `lMax` when processing the left pointer (`l`) and `rMax` when processing the right pointer (`r`).
   - If the current height is greater than or equal to the maximum height so far, no water is trapped at that position.
   - Water is only trapped if the current height is smaller than the **local maximum**.

## Edge Cases

1. **Arrays with Less than 3 Elements**:

   - Arrays of size less than 3 cannot trap any water. This is because water needs at least two walls to form a container.

2. **Flat or Monotonically Increasing/Decreasing Arrays**:

   - If all elements are the same height or in strictly increasing/decreasing order, no water will be trapped.

3. **Single Peak or Trough**:
   - If the array has a single high point or low point (e.g., `[1, 0, 1]`), water is trapped only in the valleys, and this is accurately handled by the algorithm.

## Time Complexity

- **O(n)**: The algorithm processes each element in the array exactly once, ensuring a linear time complexity. Both pointers (`l` and `r`) move towards the center, making one pass through the array.

## Space Complexity

- **O(1)**: The algorithm uses only a constant amount of extra space for the two pointers (`l`, `r`), two variables (`lMax`, `rMax`), and an accumulator for the total trapped water.

## Driver Code

```cpp
// Driver function to test the solution
int main() {
    int t; // Number of test cases
    cin >> t;

    // Loop over each test case
    while (t--) {
        int n;
        cin >> n;
        vector<int> height(n);

        // Input the array of heights
        for (int i = 0; i < n; i++) {
            cin >> height[i];
        }

        // Create an instance of the Solution class
        Solution obj;
        int result = obj.trap(height);

        // Output the result
        cout << result << endl;
    }

    return 0;
}
```

## Additional Notes

1. The **two-pointer approach** is efficient for solving the "Trapping Rain Water" problem due to its **O(n)** time complexity and **O(1)** space complexity.
2. It avoids the need to explicitly calculate left and right maximums for each element by using two pointers and dynamically updating `lMax` and `rMax`.
3. The algorithm handles arrays of various forms, including flat regions, peaks, and troughs.

## Example

For input array `height = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]`:

- The total amount of water trapped is **6** units.

Explanation:

- Water is trapped between the heights at indices 2, 4, 6, and so on, where walls of greater height on both sides form a container for the trapped rainwater.

## Summary

- This solution efficiently computes the amount of water trapped between walls after a rain using the **two-pointer approach**.
- With **O(n)** time complexity and **O(1)** space complexity, it is highly efficient and suitable for large inputs.

## Better Solution

```cpp
class Solution
{
public:
  int trap(vector<int> &height)
  {
    int n = height.size();

    vector<int> prefix(n);

    prefix[0] = height[0];

    vector<int> suffix((n));

    suffix[n - 1] = height[n - 1];

    int count = 0;

    for (int i = 1; i < n - 1; i++)
    {
      if (prefix[i - 1] < height[i])
      {
        prefix[i] = height[i];
      }
      else
      {
        prefix[i] = prefix[i - 1];
      }
    }
    for (int i = n - 2; i >= 0; i--)
    {
      if (suffix[i + 1] < height[i])
      {
        suffix[i] = height[i];
      }
      else
      {
        suffix[i] = suffix[i + 1];
      }
    }
    for (int i = 0; i < n - 1; i++)
    {
      count += min(prefix[i], suffix[i]) - height[i];
    }
    return count;
  }
};
```
